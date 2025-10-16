#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

bool createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A"); // ton DSN ODBC 64-bit
    db.setUserName("nada");
    db.setPassword("esprit25");

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Connexion Oracle", "Échec : " + db.lastError().text());
        return false;
    }
    QMessageBox::information(nullptr, "Connexion Oracle", "Connexion réussie !");
    return true;
}
