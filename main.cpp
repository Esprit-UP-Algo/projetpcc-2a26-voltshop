#include "mainwindow.h"
#include "loginwindow.h"
#include "clientwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Show login dialog first
    LoginWindow login;
    if (login.exec() == QDialog::Accepted) {
        // Login successful, check user type and show appropriate window
        int userType = login.getUserType();
        
        if (userType == 1) {
            // Admin user (fathi) - show payment module
            MainWindow w;
            w.show();
            return a.exec();
        }
        else if (userType == 2) {
            // Client manager (nada) - show client module
            ClientWindow c;
            c.show();
            return a.exec();
        }
    }
    
    // Login cancelled or failed, exit application
    return 0;
}
