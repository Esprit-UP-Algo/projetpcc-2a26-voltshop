#include "VoltShopFeedbackPanel.h"
#include <QApplication>
#include <QFileInfo>
#include <QStandardPaths>
#include <QHeaderView>
VoltShopFeedbackPanel::VoltShopFeedbackPanel(QWidget *parent)
    : QWidget(parent)
{
    setupUI();

    // Timer auto refresh
    refreshTimer.setInterval(300000); // 5 minutes
    connect(&refreshTimer, &QTimer::timeout, this, &VoltShopFeedbackPanel::onSyncData);

    // Node process
    connect(&nodeProcess, &QProcess::finished,
            this, &VoltShopFeedbackPanel::onNodeFinished);
    connect(&nodeProcess, &QProcess::errorOccurred,
            this, &VoltShopFeedbackPanel::onNodeError);
    nodeProcess.setProcessChannelMode(QProcess::MergedChannels);
    this->setStyleSheet("color:black;");



    loadDataFromJSON();
    updateDashboard();
    updateTable();
    updateInsights();
}

void VoltShopFeedbackPanel::setupUI()
{
    mainLayout = new QVBoxLayout(this);
    mainSplitter = new QSplitter(Qt::Vertical, this);
    mainLayout->addWidget(mainSplitter);

    setupDashboard();
    setupTable();
    setupInsights();
}

void VoltShopFeedbackPanel::setupDashboard()
{
    QWidget *dash = new QWidget();
    QGridLayout *grid = new QGridLayout(dash);

    cardAvgRating = new QGroupBox("⭐ Average Rating");
    cardLatestComment = new QGroupBox("💬 Latest Comment");
    cardTotalResponses = new QGroupBox("📊 Total Feedback");
    cardLastSync = new QGroupBox("⏱ Last Sync");

    labelAvgRating = new QLabel("0 ⭐");
    labelAvgRating->setStyleSheet("font-size:24px;font-weight:bold;color:#005bbb;");
    labelAvgRating->setAlignment(Qt::AlignCenter);

    labelLatestComment = new QLabel("No feedback yet");
    labelLatestComment->setWordWrap(true);
    labelLatestComment->setAlignment(Qt::AlignCenter);

    labelTotalResponses = new QLabel("0");
    labelTotalResponses->setStyleSheet("font-size:24px;font-weight:bold;");
    labelTotalResponses->setAlignment(Qt::AlignCenter);

    labelLastSync = new QLabel("Never");

    QVBoxLayout *l1 = new QVBoxLayout(cardAvgRating);
    QVBoxLayout *l2 = new QVBoxLayout(cardLatestComment);
    QVBoxLayout *l3 = new QVBoxLayout(cardTotalResponses);
    QVBoxLayout *l4 = new QVBoxLayout(cardLastSync);

    l1->addWidget(labelAvgRating);
    l2->addWidget(labelLatestComment);
    l3->addWidget(labelTotalResponses);
    l4->addWidget(labelLastSync);

    btnSync = new QPushButton("🔄 Sync Feedback");
    btnSync->setStyleSheet("background:#007bff;color:white;font-weight:bold;padding:10px;");
    connect(btnSync, &QPushButton::clicked, this, &VoltShopFeedbackPanel::onSyncData);

    syncProgress = new QProgressBar();
    syncProgress->setVisible(false);

    grid->addWidget(cardAvgRating, 0, 0);
    grid->addWidget(cardLatestComment, 0, 1);
    grid->addWidget(cardTotalResponses, 0, 2);
    grid->addWidget(cardLastSync, 1, 0);
    grid->addWidget(btnSync, 1, 1);
    grid->addWidget(syncProgress, 1, 2);

    mainSplitter->addWidget(dash);
}

void VoltShopFeedbackPanel::setupTable()
{
    tableGroup = new QGroupBox("📋 Client Feedback");
    tableLayout = new QVBoxLayout(tableGroup);

    table = new QTableWidget();
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Date", "Rating", "Comment"});

    // ✅ ENLEVER LA COLONNE GRIS / NOIR
    table->verticalHeader()->setVisible(false);

    // Enlever les lignes et bordures
    table->setShowGrid(false);

    // Ajustement des colonnes
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    table->setStyleSheet(R"(
        QTableWidget { background:white; border:none; }
        QHeaderView::section {
            background:#f2f2f2;
            font-weight:bold;
            padding: 8px;
            border:none;
        }
    )");

    tableLayout->addWidget(table);
    mainSplitter->addWidget(tableGroup);
}



void VoltShopFeedbackPanel::setupInsights()
{
    insightGroup = new QGroupBox("📈 Insights");
    QVBoxLayout *lay = new QVBoxLayout(insightGroup);

    insightText = new QTextEdit();
    insightText->setReadOnly(true);
    insightText->setStyleSheet("background:#f9f9f9; padding:10px; color:black;");
    lay->addWidget(insightText);
    mainSplitter->addWidget(insightGroup);
}

QString VoltShopFeedbackPanel::getJSONPath()
{
    // JSON généré par ton script Node
    QString root = QCoreApplication::applicationDirPath();
    QDir dir(root);
    dir.cdUp();
    dir.cdUp();

    // ⚠️ Le JSON est dans /output/feedback_data.json
    return dir.absolutePath() + "/nodeJsScripts/output/feedback_data.json";
}
void VoltShopFeedbackPanel::loadDataFromJSON()
{
    QString path = getJSONPath();

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "❌ Impossible d'ouvrir le JSON de feedback:" << path;
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isObject()) {
        qDebug() << "❌ JSON invalide";
        return;
    }

    QJsonArray arr = doc.object()["responses"].toArray();
    feedbackList.clear();

    int seq = 1;
    for (const QJsonValue &val : arr) {
        QJsonObject o = val.toObject();

        VoltFeedback f;
        f.responseId = o["responseId"].toString();
        f.createTime = o["createTime"].toString();

        // 1) Essayer de lire les champs déjà "plats"
        f.rating  = o["rating"].toString();
        f.comment = o["comment"].toString();


        // 2) Si vide, on va chercher dans answers (format brut Google Forms)
        if (o.contains("answers")) {
            QJsonObject answersObj = o["answers"].toObject();

            for (auto it = answersObj.begin(); it != answersObj.end(); ++it) {
                QJsonObject answerObj      = it.value().toObject();
                QJsonObject textAnswersObj = answerObj["textAnswers"].toObject();
                QJsonArray  answersArray   = textAnswersObj["answers"].toArray();
                if (answersArray.isEmpty())
                    continue;

                QString value = answersArray.first().toObject()["value"].toString().trimmed();

                // ➜ rating : nombre entre 1 et 5
                bool ok = false;
                int n   = value.toInt(&ok);
                if (ok && n >= 1 && n <= 5 && f.rating.isEmpty()) {
                    f.rating = value;
                    continue;
                }
                // ➜ sinon on considère que c'est le commentaire
                if (f.comment.isEmpty()) {
                    f.comment = value;
                }
            }
        }

        // Séquence (numéro de ligne)
        f.sequence = seq++;
        feedbackList.append(f);
    }

    qDebug() << "📊 Loaded" << feedbackList.size() << "feedback entries";
}


void VoltShopFeedbackPanel::updateDashboard()
{
    if (feedbackList.isEmpty()) {
        labelAvgRating->setText("0 ⭐");
        labelTotalResponses->setText("0");
        return;
    }

    double avg = 0;
    for (auto &f : feedbackList) avg += f.rating.toDouble();
    avg /= feedbackList.size();

    labelAvgRating->setText(QString::number(avg, 'f', 1) + " ⭐");
    labelTotalResponses->setText(QString::number(feedbackList.size()));

    labelLatestComment->setText(feedbackList.last().comment);
}

void VoltShopFeedbackPanel::updateTable()
{
    table->setRowCount(feedbackList.size());

    for (int i = 0; i < feedbackList.size(); i++) {
        const auto &f = feedbackList[i];

        table->setItem(i, 0, new QTableWidgetItem(formatDate(f.createTime)));
        table->setItem(i, 1, new QTableWidgetItem(starEmoji(f.rating)));
        table->setItem(i, 2, new QTableWidgetItem(f.comment));

    }

    table->resizeColumnsToContents();
}

void VoltShopFeedbackPanel::updateInsights()
{
    generateInsights();
}

QString VoltShopFeedbackPanel::formatDate(const QString &iso)
{
    QDateTime dt = QDateTime::fromString(iso, Qt::ISODate);
    return dt.toString("dd MMM yyyy - hh:mm");
}

QString VoltShopFeedbackPanel::starEmoji(const QString &n)
{
    int v = n.toInt();
    return QString(v, QChar(0x2B50)); // ⭐ repeated
}

void VoltShopFeedbackPanel::generateInsights()
{
    if (feedbackList.isEmpty()) {
        insightText->setText("No feedback yet.");
        return;
    }

    int n = feedbackList.size();
    int good = 0;
    for (auto &f : feedbackList)
        if (f.rating.toInt() >= 4) good++;

    double percent = (good * 100.0) / n;

    QString html;
    html += "<h3>Overview</h3>";
    html += QString("<p>👍 %1% positive reviews</p>").arg(percent, 0, 'f', 1);
    html += "<h3>Recommendations</h3>";

    if (percent < 60)
        html += "<p>• Improve packaging quality</p>";
    if (percent < 80)
        html += "<p>• Faster customer support response</p>";

    html += "<p>• Maintain product quality consistency</p>";

    insightText->setHtml(html);
}

void VoltShopFeedbackPanel::onSyncData()
{
    btnSync->setEnabled(false);
    syncProgress->setVisible(true);
    syncProgress->setRange(0,0);

    QString root = QCoreApplication::applicationDirPath();
    QDir dir(root);
    dir.cdUp();
    dir.cdUp();

    // Dossier où il y a forms_extractor.js + credentials.json
    QString nodeScriptsDir = dir.absolutePath() + "/nodeJsScripts";
    nodeProcess.setWorkingDirectory(nodeScriptsDir);

    // ⚠️ METS ICI LE CHEMIN EXACT DONNÉ PAR "where node"
    QString nodeExe = "C:/Program Files/nodejs/node.exe";

    // Petites vérifications avant de lancer
    if (!QFileInfo::exists(nodeExe)) {
        QMessageBox::critical(this, "Error",
                              "Node executable not found at:\n" + nodeExe);
        btnSync->setEnabled(true);
        syncProgress->setVisible(false);
        return;
    }

    if (!QFileInfo::exists(nodeScriptsDir + "/forms_extractor.js")) {
        QMessageBox::critical(this, "Error",
                              "forms_extractor.js not found in:\n" + nodeScriptsDir);
        btnSync->setEnabled(true);
        syncProgress->setVisible(false);
        return;
    }

    // Lancer Node
    QStringList args;
    args << "forms_extractor.js";
    nodeProcess.start(nodeExe, args);
}



void VoltShopFeedbackPanel::onNodeFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    btnSync->setEnabled(true);
    syncProgress->setVisible(false);

    loadDataFromJSON();
    updateDashboard();
    updateTable();
    updateInsights();

    labelLastSync->setText(QDateTime::currentDateTime().toString("dd MMM hh:mm"));
}

void VoltShopFeedbackPanel::onNodeError(QProcess::ProcessError error)
{
    QString detail = nodeProcess.errorString();
    QString output = nodeProcess.readAllStandardOutput();

    QString msg = "Node.js failed to run.\n\nError: " + detail;
    if (!output.isEmpty()) {
        msg += "\n\nOutput:\n" + output;
    }

    QMessageBox::warning(this, "Node.js Error", msg);

    btnSync->setEnabled(true);
    syncProgress->setVisible(false);
}

