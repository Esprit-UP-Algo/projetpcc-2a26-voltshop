#include <QApplication>
#include "login.h"
#include "connection.h"
#include <QMessageBox>
#include "logger.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initLogger();
    qDebug() << "[main] Application started";

    // Récupération de l'instance unique de connexion
    Connection& c = Connection::getInstance();

    // Tentative d'ouverture
    if (!c.openConnection()) {
        QMessageBox::critical(nullptr, "Erreur de connexion",
                              "Impossible de se connecter à Oracle.\n"
                              "Vérifie ODBC (DSN), identifiants et services Oracle.");
        return 1;
    }


    // Lancer ton interface de login (heap-allocated so deleteLater() is safe)
    Login *login = new Login();
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
    QObject::connect(&a, &QCoreApplication::aboutToQuit, [](){ qDebug() << "[main] aboutToQuit"; shutdownLogger(); });

    return a.exec();
}
