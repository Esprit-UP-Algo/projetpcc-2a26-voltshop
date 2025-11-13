#include <QApplication>
#include "login.h"
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Récupération de l'instance unique de connexion
    Connection& c = Connection::getInstance();

    // Tentative d'ouverture
    if (!c.openConnection()) {
        QMessageBox::critical(nullptr, "Erreur de connexion",
                              "Impossible de se connecter à Oracle.\n"
                              "Vérifie ODBC (DSN), identifiants et services Oracle.");
        return 1;
    }


    // Lancer ton interface de login
    Login login;
    login.show();

    return a.exec();
}
