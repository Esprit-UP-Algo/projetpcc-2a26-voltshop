#include "mainwindow.h"
#include "loginwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Show login dialog first
    LoginWindow login;
    if (login.exec() == QDialog::Accepted) {
        // Login successful, show main window
        MainWindow w;
        w.show();
        return a.exec();
    }
    
    // Login cancelled or failed, exit application
    return 0;
}
