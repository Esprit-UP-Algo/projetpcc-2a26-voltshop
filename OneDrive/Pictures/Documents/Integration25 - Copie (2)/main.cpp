#include <QApplication>
#include <QMessageBox>
#include "login.h"
#include "Connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ⚠️ Mets tes identifiants exacts (DSN/USER/PASS)
    if (!Connection::instance().open("Source_Projet2A26", "houssem", "esprit25")) {
        return 1; // message déjà affiché dans open()
    }

    Login login;
    login.show();
    return a.exec();
}
