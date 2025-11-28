#ifndef VOLTSHOPFEEDBACKPANEL_H
#define VOLTSHOPFEEDBACKPANEL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QGroupBox>
#include <QProgressBar>
#include <QTimer>
#include <QProcess>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include <QSplitter>
#include <QTextEdit>
#include <QComboBox>
#include <QLineEdit>
#include <QDateTime>

struct VoltFeedback {
    QString responseId;
    QString createTime;
    QString rating;
    QString comment;
    int sequence = 0;
};

class VoltShopFeedbackPanel : public QWidget
{
    Q_OBJECT

public:
    explicit VoltShopFeedbackPanel(QWidget *parent = nullptr);

private slots:
    void onSyncData();
    void onNodeFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void onNodeError(QProcess::ProcessError error);

private:
    // Layouts
    QVBoxLayout *mainLayout;
    QSplitter *mainSplitter;

    // Dashboard
    QGroupBox *cardAvgRating;
    QGroupBox *cardLatestComment;
    QGroupBox *cardTotalResponses;
    QGroupBox *cardLastSync;
    QLabel *labelAvgRating;
    QLabel *labelLatestComment;
    QLabel *labelTotalResponses;
    QLabel *labelLastSync;
    QPushButton *btnSync;
    QProgressBar *syncProgress;

    // Table section
    QGroupBox *tableGroup;
    QVBoxLayout *tableLayout;
    QTableWidget *table;

    // Insights section
    QGroupBox *insightGroup;
    QTextEdit *insightText;

    // Data
    QList<VoltFeedback> feedbackList;
    QTimer refreshTimer;
    QProcess nodeProcess;

    // Internal methods
    void setupUI();
    void setupDashboard();
    void setupTable();
    void setupInsights();

    void loadDataFromJSON();
    void updateDashboard();
    void updateTable();
    void updateInsights();
    void generateInsights();

    QString formatDate(const QString &isoTime);
    QString starEmoji(const QString &rating);

    QString getJSONPath();
};

#endif // VOLTSHOPFEEDBACKPANEL_H
