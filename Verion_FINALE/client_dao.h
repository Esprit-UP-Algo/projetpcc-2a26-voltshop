#pragma once
#include <QString>
#include <QVector>
#include <QListWidget>

struct Client {
    QString CIN;
    QString FIRST_NAME;
    QString LAST_NAME;
    QString EMAIL;
    QString PHONE_NBR;
    QString ADRESS;
    int AGE; // CHAMP AJOUTÉ (Age du client)
};

class client_dao
{
public:
    static bool create(const Client& c);
    static bool update(const Client& c);
    static bool remove(const QString& cin);
    static bool exists(const QString& cin);
    static QVector<Client> fetchAll();
    static bool validateClient(const Client& c, QString& errorMessage);

    // 🔹 récupération d'un client par CIN
    static bool getByCin(const QString &cin, Client &out);

    // 🔹 journal (historique)
    static void journalAdd(const QString &action, const Client &c);
    static void journalLoad(QListWidget *listWidget);
    static void journalClear();      // 🔴 A JOUTER
};
