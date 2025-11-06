#pragma once
#include <QString>
#include <QVector>

struct Client {
    QString CIN;
    QString FIRST_NAME;
    QString LAST_NAME;
    QString EMAIL;
    QString PHONE_NBR;
    QString ADRESS;     // (orthographe demandée)
};

class client_dao {
public:
    static bool create(const Client& c);           // INSERT
    static bool update(const Client& c);           // UPDATE WHERE CIN
    static bool remove(const QString& cin);        // DELETE
    static bool exists(const QString& cin);        // SELECT 1
    static QVector<Client> fetchAll();             // SELECT *
};
