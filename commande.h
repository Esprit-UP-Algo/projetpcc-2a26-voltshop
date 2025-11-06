#ifndef COMMANDE_H
#define COMMANDE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>

class Commande
{
public:
    Commande();
    Commande(int code, QString client, QDate date_commande, QString produits, double total, QString statut);

    bool ajouter();
    bool supprimer(int code);
    bool modifier();

    QSqlQueryModel* afficher();

private:
    int code;
    QString client, produits, statut;
    QDate date_commande;
    double total;
};

#endif // COMMANDE_H
