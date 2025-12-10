#include "excelexporter.h"
#include "connection.h"
#include "logger.h"
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>

ExcelExporter::ExcelExporter(QObject *parent)
    : QObject(parent), m_process(nullptr)
{
    // Set Python script path relative to source directory
    // The script is in the source folder, not the build folder
    QString sourceDir = QDir::currentPath();
    
    // If we're in the build directory, go up to find the source
    if (sourceDir.contains("/build") || sourceDir.contains("\\build")) {
        QDir dir(sourceDir);
        dir.cdUp(); // Go up from build directory
        sourceDir = dir.absolutePath();
    }
    
    m_pythonScriptPath = sourceDir + "/python_scripts/financial_export.py";
    
    // Normalize path
    QFileInfo scriptInfo(m_pythonScriptPath);
    m_pythonScriptPath = scriptInfo.absoluteFilePath();
    
    LOG_INFO(QString("ExcelExporter initialized, script path: %1").arg(m_pythonScriptPath));
}

ExcelExporter::~ExcelExporter()
{
    if (m_process) {
        if (m_process->state() == QProcess::Running) {
            m_process->terminate();
            m_process->waitForFinished(3000);
        }
        delete m_process;
    }
}

QString ExcelExporter::findPythonExecutable()
{
    // Try common Python executable names
    QStringList pythonCandidates = {"python", "python3", "py"};
    
    for (const QString &candidate : pythonCandidates) {
        QProcess testProcess;
        testProcess.start(candidate, QStringList() << "--version");
        if (testProcess.waitForFinished(3000)) {
            if (testProcess.exitCode() == 0) {
                LOG_INFO(QString("Found Python executable: %1").arg(candidate));
                return candidate;
            }
        }
    }
    
    LOG_WARNING("Python executable not found in PATH");
    return "python"; // Default fallback
}

QJsonArray ExcelExporter::fetchTransactionsFromDB()
{
    QJsonArray transactions;
    
    Connection& conn = Connection::getInstance();
    if (!conn.openConnection()) {
        LOG_ERROR("Failed to open database connection for export");
        return transactions;
    }
    
    QSqlQuery query(conn.getDatabase());
    QString sql = "SELECT IDT, ID, AMOUNT, PAY_METHOD, TO_CHAR(DATE_TRANS, 'DD/MM/YYYY') AS DATE_TRANS, STATUS FROM TAB_TRANS ORDER BY DATE_TRANS DESC";
    
    if (!query.exec(sql)) {
        LOG_ERROR(QString("Failed to fetch transactions: %1").arg(query.lastError().text()));
        return transactions;
    }
    
    int count = 0;
    while (query.next()) {
        QJsonObject trans;
        trans["IDT"] = query.value("IDT").toInt();
        trans["ID"] = query.value("ID").toInt();
        trans["AMOUNT"] = query.value("AMOUNT").toString();
        trans["PAY_METHOD"] = query.value("PAY_METHOD").toString();
        trans["DATE_TRANS"] = query.value("DATE_TRANS").toString();
        trans["STATUS"] = query.value("STATUS").toString();
        
        transactions.append(trans);
        count++;
    }
    
    LOG_INFO(QString("Fetched %1 transactions from database").arg(count));
    return transactions;
}

bool ExcelExporter::exportTransactionsToBilan(const QString &outputPath)
{
    emit exportStarted();
    emit exportProgress("Récupération des données de la base de données...");
    
    // Check if Python script exists
    QFileInfo scriptInfo(m_pythonScriptPath);
    if (!scriptInfo.exists()) {
        QString error = QString("Script Python introuvable: %1").arg(m_pythonScriptPath);
        LOG_ERROR(error);
        emit exportFinished(false, error);
        return false;
    }
    
    // Fetch transaction data
    QJsonArray transactions = fetchTransactionsFromDB();
    if (transactions.isEmpty()) {
        QString error = "Aucune transaction à exporter";
        LOG_WARNING(error);
        emit exportFinished(false, error);
        return false;
    }
    
    emit exportProgress(QString("Exportation de %1 transactions...").arg(transactions.size()));
    
    // Convert to JSON string
    QJsonDocument doc(transactions);
    QString jsonData = doc.toJson(QJsonDocument::Compact);
    
    // Find Python executable
    QString pythonExe = findPythonExecutable();
    
    // Create process
    if (m_process) {
        delete m_process;
    }
    m_process = new QProcess(this);
    
    // Set up process arguments
    QStringList arguments;
    arguments << m_pythonScriptPath << outputPath;
    
    LOG_INFO(QString("Launching Python: %1 %2 %3").arg(pythonExe, m_pythonScriptPath, outputPath));
    
    // Start Python process
    m_process->start(pythonExe, arguments);
    
    if (!m_process->waitForStarted(5000)) {
        QString error = "Impossible de démarrer Python. Vérifiez que Python est installé.";
        LOG_ERROR(error);
        emit exportFinished(false, error);
        return false;
    }
    
    // Write JSON data to stdin
    m_process->write(jsonData.toUtf8());
    m_process->closeWriteChannel();
    
    emit exportProgress("Génération du fichier Excel...");
    
    // Wait for process to finish
    if (!m_process->waitForFinished(30000)) { // 30 second timeout
        QString error = "Le script Python a dépassé le délai d'attente";
        LOG_ERROR(error);
        m_process->kill();
        emit exportFinished(false, error);
        return false;
    }
    
    // Check exit code
    int exitCode = m_process->exitCode();
    QString stdOutput = m_process->readAllStandardOutput();
    QString stdError = m_process->readAllStandardError();
    
    LOG_INFO(QString("Python process exited with code: %1").arg(exitCode));
    if (!stdOutput.isEmpty()) {
        LOG_INFO(QString("Python stdout: %1").arg(stdOutput));
    }
    if (!stdError.isEmpty()) {
        LOG_ERROR(QString("Python stderr: %1").arg(stdError));
    }
    
    if (exitCode == 0 && stdOutput.contains("SUCCESS")) {
        QString success = QString("Bilan Financier exporté avec succès:\n%1").arg(outputPath);
        LOG_INFO(success);
        emit exportFinished(true, success);
        return true;
    } else {
        QString error = QString("Erreur lors de l'export:\n%1").arg(stdError.isEmpty() ? stdOutput : stdError);
        LOG_ERROR(error);
        emit exportFinished(false, error);
        return false;
    }
}
