#include <QApplication>
#include "login.h"
#include "connection.h"
#include "logger.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Install crash handlers early
    Logger::installSignalHandlers();
    LOG_INFO("=== VoltShop Application Started ===");

    // Récupération de l'instance unique de connexion
    Connection& c = Connection::getInstance();

    // Tentative d'ouverture
    if (!c.openConnection()) {
        LOG_ERROR("Failed to connect to Oracle database");
        QMessageBox::critical(nullptr, "Erreur de connexion",
                              "Impossible de se connecter à Oracle.\n"
                              "Vérifie ODBC (DSN), identifiants et services Oracle.");
        return 1;
    }

    LOG_INFO("Database connection established successfully");

    // Lancer ton interface de login
    Login login;
    login.show();

    int result = a.exec();
    
    LOG_INFO(QString("=== VoltShop Application Exited with code %1 ===").arg(result));
    return result;
}
