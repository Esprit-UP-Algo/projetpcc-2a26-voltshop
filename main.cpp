#include "mainwindow.h"
#include "connection.h"       // ✅ pour la fonction createConnection()
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Tentative de connexion à la base Oracle
    if (!createConnection()) {
        QMessageBox::critical(nullptr, "Erreur de connexion",
                              "Impossible de se connecter à la base de données Oracle.\n"
                              "Vérifie ton ODBC (Source_Projet2A) et tes identifiants.");
        return 1; // on arrête le programme si la connexion échoue
    }

    // Si tout est bon, on ouvre la fenêtre principale
    MainWindow w;
    w.show();

    return a.exec();
}
