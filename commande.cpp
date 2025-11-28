#include "commande.h"
#include "connection.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QTextDocument>
#include <QTextTable>
#include <QPrinter>
#include <QMessageBox>
#include <QDate>
#include <QDateTime>
#include <QTextCursor>

Commande::Commande() {}

Commande::Commande(QString code, QDate date_commande, QString produits, double total, QString statut)
{
    this->code = code;
    this->date_commande = date_commande;
    this->produits = produits;
    this->total = total;
    this->statut = statut;
}

bool Commande::ajouter()
{
    // Vérifier que la connexion est ouverte
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return false;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO TAB_COMMANDE (CODE, DATE_COMMANDE, PRODUCTS, TOTAL, STATUS) "
                  "VALUES (:CODE, :DATE_COMMANDE, :PRODUCTS, :TOTAL, :STATUS)");

    query.bindValue(":CODE", code);
    query.bindValue(":DATE_COMMANDE", date_commande);
    query.bindValue(":PRODUCTS", produits);
    query.bindValue(":TOTAL", total);
    query.bindValue(":STATUS", statut);


    if (!query.exec()) {
        qDebug() << "❌ Erreur ajout commande :" << query.lastError().text();
        qDebug() << "Requête:" << query.lastQuery();
        return false;
    }

    qDebug() << "✅ Commande ajoutée avec succès, code:" << code;
    return true;
}
bool Commande::supprimer(QString code)
{
    Connection& conn = Connection::getInstance();
    QSqlDatabase db = conn.getDatabase();

    if (!db.isOpen()) {
        qDebug() << "Base de données non connectée";
        return false;
    }

    // On utilise une transaction : soit tout passe, soit rien
    if (!db.transaction()) {
        qDebug() << "❌ Impossible de démarrer une transaction:" << db.lastError().text();
        return false;
    }

    QSqlQuery query(db);

    // 1) Supprimer les lignes liées dans CONCERNER
    query.prepare("DELETE FROM CONCERNER WHERE CODE = :CODE");
    query.bindValue(":CODE", code);

    if (!query.exec()) {
        qDebug() << "❌ Erreur suppression CONCERNER :" << query.lastError().text();
        db.rollback();
        return false;
    }

    // 2) Supprimer la commande dans TAB_COMMANDE
    query.clear();
    query.prepare("DELETE FROM TAB_COMMANDE WHERE CODE = :CODE");
    query.bindValue(":CODE", code);

    if (!query.exec()) {
        qDebug() << "❌ Erreur suppression commande :" << query.lastError().text();
        db.rollback();
        return false;
    }

    // 3) Valider la transaction
    if (!db.commit()) {
        qDebug() << "❌ Erreur commit transaction :" << db.lastError().text();
        db.rollback();
        return false;
    }

    qDebug() << "✅ Commande et lignes CONCERNER supprimées avec succès, code:" << code;
    return true;
}



QSqlQueryModel* Commande::afficher()
{
    // Vérifier que la connexion est ouverte
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return new QSqlQueryModel(); // Retourne un modèle vide
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT CODE, DATE_COMMANDE, PRODUCTS, TOTAL, STATUS FROM TAB_COMMANDE");


    if (model->lastError().isValid()) {
        qDebug() << "❌ Erreur lors de l'affichage:" << model->lastError().text();
    } else {
        qDebug() << "✅ Données chargées, nombre de lignes:" << model->rowCount();
    }

    return model;
}

bool Commande::modifier()
{
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return false;
    }

    QSqlQuery query;
    QString queryStr = "UPDATE TAB_COMMANDE "
                       "SET DATE_COMMANDE = :DATE_COMMANDE, PRODUCTS = :PRODUCTS, "
                       "TOTAL = :TOTAL, STATUS = :STATUS "
                       "WHERE CODE = :CODE";

    // ✅ Préparation de la requête
    if (!query.prepare(queryStr)) {
        qDebug() << "❌ Erreur préparation requête :" << query.lastError().text();
        return false;
    }

    // ✅ Liaison des valeurs
    query.bindValue(":CODE", code);
    query.bindValue(":DATE_COMMANDE", date_commande);
    query.bindValue(":PRODUCTS", produits);
    query.bindValue(":TOTAL", total);
    query.bindValue(":STATUS", statut);

    // ✅ Exécution
    if (!query.exec()) {
        qDebug() << "❌ Erreur modification commande :" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Commande mise à jour avec succès, code:" << code;
    return true;
}

int Commande::stat_total_commandes() {
    QSqlQuery query("SELECT COUNT(*) FROM commandes");
    if (query.next())
        return query.value(0).toInt();
    return 0;
}


double Commande::stat_revenu_total() {
    QSqlQuery query("SELECT SUM(total) FROM commandes");
    if (query.next())
        return query.value(0).toDouble();
    return 0;
}


QMap<QString,int> Commande::stat_statuts() {
    QMap<QString,int> map;
    QSqlQuery query("SELECT statut, COUNT(*) FROM commandes GROUP BY statut");
    while (query.next()) {
        QString st = query.value(0).toString();
        int c = query.value(1).toInt();
        map[st] = c;
    }
    return map;
}


QMap<QString,int> Commande::stat_par_mois() {
    QMap<QString,int> map;
    QSqlQuery query("SELECT TO_CHAR(date_commande, 'MM'), COUNT(*) FROM commandes GROUP BY TO_CHAR(date_commande,'MM')");
    while (query.next()) {
        QString mois = query.value(0).toString();
        int count = query.value(1).toInt();
        map[mois] = count;
    }
    return map;
}









