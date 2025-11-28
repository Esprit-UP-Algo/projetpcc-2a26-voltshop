#include "connection.h"
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A26");
    db.setUserName("houssem");
    db.setPassword("esprit25");
}

Connection::~Connection() {
    if (db.isOpen())
        db.close();
}

Connection& Connection::getInstance() {
    static Connection instance; // création unique
    return instance;
}

bool Connection::openConnection() {
    if (!db.isOpen() && !db.open()) {
        QMessageBox::critical(nullptr, "Erreur de connexion",
                              db.lastError().text());
        return false;
    }
    qDebug() << "Connexion Oracle réussie.";
    return true;
}

void Connection::closeConnection() {
    if (db.isOpen())
        db.close();
}


QSqlDatabase Connection::getDatabase() {
    return db;
}
