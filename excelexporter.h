#ifndef EXCELEXPORTER_H
#define EXCELEXPORTER_H

#include <QObject>
#include <QString>
#include <QProcess>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class ExcelExporter : public QObject
{
    Q_OBJECT

public:
    explicit ExcelExporter(QObject *parent = nullptr);
    ~ExcelExporter();

    // Export transactions to Excel Bilan Financier
    bool exportTransactionsToBilan(const QString &outputPath);

signals:
    void exportStarted();
    void exportFinished(bool success, const QString &message);
    void exportProgress(const QString &status);

private:
    QProcess *m_process;
    QString m_pythonScriptPath;

    // Fetch all transactions from database
    QJsonArray fetchTransactionsFromDB();
    
    // Find Python executable
    QString findPythonExecutable();
};

#endif // EXCELEXPORTER_H
