#include "commande.h"
#include "connection.h"

Commande::Commande() {}

Commande::Commande(int code, QString client, QDate date_commande, QString produits, double total, QString statut)
{
    this->code = code;
    this->client = client;
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
    query.prepare("INSERT INTO TAB_COMMANDE (CODE, CLIENT, DATE_COMMANDE, PRODUCTS, TOTAL, STATUS) "
                  "VALUES (:CODE, :CLIENT, :DATE_COMMANDE, :PRODUCTS, :TOTAL, :STATUS)");

    query.bindValue(":CODE", code);
    query.bindValue(":CLIENT", client);
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
bool Commande::supprimer(int code)
{
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM TAB_COMMANDE WHERE CODE = :CODE");  // ✅ corriger ici
    query.bindValue(":CODE", code);

    if (!query.exec()) {
        qDebug() << "❌ Erreur suppression commande :" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Commande supprimée avec succès, code:" << code;
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
    model->setQuery("SELECT CODE, CLIENT, DATE_COMMANDE, PRODUCTS, TOTAL, STATUS FROM TAB_COMMANDE");


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
                       "SET CLIENT = :CLIENT, DATE_COMMANDE = :DATE_COMMANDE, PRODUCTS = :PRODUCTS, "
                       "TOTAL = :TOTAL, STATUS = :STATUS "
                       "WHERE CODE = :CODE";

    // ✅ Préparation de la requête
    if (!query.prepare(queryStr)) {
        qDebug() << "❌ Erreur préparation requête :" << query.lastError().text();
        return false;
    }

    // ✅ Liaison des valeurs
    query.bindValue(":CODE", code);
    query.bindValue(":CLIENT", client);
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
