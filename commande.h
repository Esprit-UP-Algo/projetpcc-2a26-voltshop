#ifndef COMMANDE_H
#define COMMANDE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include "ui_mainwindow.h"

struct Location {
    QString name;
    double latitude;
    double longitude;
};

class Commande
{
public:
    Commande();
    Commande(QString code, QDate date_commande, QString produits, double total, QString statut);

    bool ajouter();
    bool supprimer(QString code);
    bool modifier();
    void exporterPDFCommandes(Ui::MainWindow* ui);

    QSqlQueryModel* afficher();

    int stat_total_commandes();
    double stat_revenu_total();
    QMap<QString, int> stat_statuts();
    QMap<QString, int> stat_par_mois();

    static Location getCoordinate(QString name);
    static double calculateDistance(Location a, Location b);



private:
    QString code;
    QString client, produits, statut;
    QDate date_commande;
    double total;


};

#endif // COMMANDE_H
