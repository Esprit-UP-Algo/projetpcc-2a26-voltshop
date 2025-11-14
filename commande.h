#ifndef COMMANDE_H
#define COMMANDE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include "connection.h"

class Commande
{
public:
    Commande();
    Commande(QString code, QDate date_commande, QString produits, double total, QString statut);

    bool ajouter();
    bool supprimer(QString code);
    bool modifier();

    QSqlQueryModel* afficher();

private:
    QString code;
    QString client, produits, statut;
    QDate date_commande;
    double total;
};

// Inline definitions to ensure the symbols are available to all translation units
inline Commande::Commande(QString code, QDate date_commande, QString produits, double total, QString statut)
{
    this->code = code;
    this->date_commande = date_commande;
    this->produits = produits;
    this->total = total;
    this->statut = statut;
}

inline bool Commande::supprimer(QString code)
{
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM TAB_COMMANDE WHERE CODE = :CODE");
    query.bindValue(":CODE", code);

    if (!query.exec()) {
        qDebug() << "❌ Erreur suppression commande :" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Commande supprimée avec succès, code:" << code;
    return true;
}

#endif // COMMANDE_H
