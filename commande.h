#ifndef COMMANDE_H
#define COMMANDE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include "ui_mainwindow.h"


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


private:
    QString code;
    QString client, produits, statut;
    QDate date_commande;
    double total;
};

#endif // COMMANDE_H
