#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QPointer>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class MainWindow;

class Login : public QDialog
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_connect_clicked();  // objectName du bouton = "connect"

private:
    Ui::Login *ui;
    bool m_mainWindowScheduled = false;
    QPointer<MainWindow> m_mainWindow;
    
    // Helper methods for authentication
    bool authenticateUser(const QString &username, const QString &password, 
                          QString &outRole, QString &outTotpSecret);
    bool handleTotpVerification(const QString &username, const QString &totpSecret);
    bool enrollNewTotp(const QString &username);
    void createMainWindowDeferred(const QString &username, const QString &role);
};

#endif // LOGIN_H
