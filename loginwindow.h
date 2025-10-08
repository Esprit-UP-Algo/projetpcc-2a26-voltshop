#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    
    // User type: 1 = admin (fathi), 2 = client manager (nada)
    int getUserType() const { return userType; }

private slots:
    void onLoginClicked();
    void onCancelClicked();

private:
    Ui::LoginWindow *ui;
    bool validateLogin(const QString &username, const QString &password);
    int userType; // Store the user type after successful login
};

#endif // LOGINWINDOW_H
