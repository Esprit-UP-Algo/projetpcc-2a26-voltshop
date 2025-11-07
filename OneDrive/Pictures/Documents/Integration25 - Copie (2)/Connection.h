#pragma once
#include <QSqlDatabase>
#include <QString>

class Connection {
public:
    // Accès global à l’unique instance
    static Connection& instance();

    // Ouvre la connexion si nécessaire (idempotent)
    bool open(const QString& dsn, const QString& user, const QString& pass);

    // Accès à la base unique
    QSqlDatabase& db();

    // Interdire copie/assignation
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;

private:
    Connection();              // privé
    ~Connection();             // ferme si ouvert

    QSqlDatabase m_db;
    bool m_opened = false;
};
