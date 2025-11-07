#include "Connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

static const char* kConnName = "oracle-odbc-unique";

Connection& Connection::instance() {
    static Connection s; // C++11+, thread-safe
    return s;
}

Connection::Connection() {
    if (!QSqlDatabase::drivers().contains("QODBC")) {
        QMessageBox::critical(nullptr, "Oracle ODBC",
                              "Driver QODBC manquant (plugin qsqlodbc 64-bit).");
        return;
    }
    m_db = QSqlDatabase::addDatabase("QODBC", kConnName);
}

Connection::~Connection() {
    if (m_db.isOpen()) m_db.close();
}

bool Connection::open(const QString& dsn, const QString& user, const QString& pass)
{
    if (!m_db.isValid()) return false;
    if (m_opened && m_db.isOpen()) return true; // déjà ouvert

    m_db.setDatabaseName(dsn);
    m_db.setUserName(user);
    m_db.setPassword(pass);

    m_opened = m_db.open();
    if (!m_opened) {
        QMessageBox::critical(nullptr, "Oracle ODBC",
                              "Connexion échouée : " + m_db.lastError().text());
        return false;
    }
    qDebug() << "[DB] Connexion ouverte via Singleton.";
    return true;
}

QSqlDatabase& Connection::db() {
    return m_db;
}
