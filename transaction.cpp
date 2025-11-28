#include "transaction.h"
#include "connection.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

Transaction::Transaction() {}

Transaction::Transaction(int id, QString amount, QString pay_method, QDate date_trans, QString status, int refId)
    : id(id), amount(amount), pay_method(pay_method), date_trans(date_trans), status(status), refId(refId)
{}

bool Transaction::ajouter()
{
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return false;
    }
    QSqlQuery query;
    QSqlQuery qid;
    if (!qid.exec("SELECT NVL(MAX(IDT),0)+1 FROM TAB_TRANS")) {
        qDebug() << "❌ Erreur obtention next IDT:" << qid.lastError().text();
        return false;
    }
    int nextId = 1;
    if (qid.next()) nextId = qid.value(0).toInt();
    id = nextId;

    // Build INSERT: include required ID column (refId -> TAB_TRANS.ID)
    QString cols = "IDT, ID, AMOUNT, PAY_METHOD, DATE_TRANS, STATUS";
    // Use TO_DATE on the placeholder so Oracle converts the provided string to a DATE
    // Use DD/MM/YYYY HH24:MI:SS and always send a time part to avoid format mismatches
    QString vals = ":IDT, :ID, :AMOUNT, :PAY_METHOD, TO_DATE(:DATE_TRANS,'DD/MM/YYYY HH24:MI:SS'), :STATUS";
    QString sql = QString("INSERT INTO TAB_TRANS (%1) VALUES (%2)").arg(cols, vals);
    query.prepare(sql);
    query.bindValue(":IDT", id);
    query.bindValue(":ID", refId);
    query.bindValue(":AMOUNT", amount);
    query.bindValue(":PAY_METHOD", pay_method);
    query.bindValue(":DATE_TRANS", date_trans.toString("dd/MM/yyyy") + " 00:00:00");
    query.bindValue(":STATUS", status);
    Q_UNUSED(id);

    if (!query.exec()) {
        qDebug() << "❌ Erreur ajout transaction :" << query.lastError().text();
        qDebug() << "Requête:" << query.lastQuery();
        return false;
    }
    qDebug() << "✅ Transaction ajoutée avec succès, id:" << id;
    return true;
}

bool Transaction::supprimer(int id)
{
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return false;
    }

    // Use the singleton's database handle explicitly and run the DELETE inside a transaction
    QSqlDatabase db = conn.getDatabase();
    QSqlQuery query(db);
    // Delete by the transaction primary key IDT
    if (!query.prepare("DELETE FROM TAB_TRANS WHERE ID = :ID")) {
        qDebug() << "❌ Erreur préparation suppression transaction :" << query.lastError().text();
        return false;
    }
    query.bindValue(":ID", id);

    db.transaction();
    const bool ok = query.exec();
    if (!ok) {
        qDebug() << "❌ Erreur suppression transaction :" << query.lastError().text();
        db.rollback();
        return false;
    }

    // Ensure a row was actually deleted
    const int affected = query.numRowsAffected();
    if (affected <= 0) {
        qDebug() << "⚠️ No transaction deleted (IDT not found):" << id;
        db.rollback();
        return false;
    }

    db.commit();
    qDebug() << "✅ Transaction supprimée avec succès, id:" << id;
    return true;
}

QSqlQueryModel* Transaction::afficher()
{
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return new QSqlQueryModel();
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT IDT, ID, AMOUNT, PAY_METHOD, DATE_TRANS, STATUS FROM TAB_TRANS");

    if (model->lastError().isValid()) {
        qDebug() << "❌ Erreur lors de l'affichage:" << model->lastError().text();
    } else {
        qDebug() << "✅ Données chargées, nombre de lignes:" << model->rowCount();
    }
    return model;
}

bool Transaction::modifier()
{
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return false;
    }

    QSqlQuery query;
    
    QString queryStr = "UPDATE TAB_TRANS SET AMOUNT = :AMOUNT, PAY_METHOD = :PAY_METHOD, DATE_TRANS = TO_DATE(:DATE_TRANS,'DD/MM/YYYY HH24:MI:SS'), STATUS = :STATUS, ID = :ID WHERE IDT = :IDT";

    if (!query.prepare(queryStr)) {
        qDebug() << "❌ Erreur préparation requête :" << query.lastError().text();
        return false;
    }
    query.bindValue(":IDT", id);
    query.bindValue(":ID", refId);
    query.bindValue(":AMOUNT", amount);
    query.bindValue(":PAY_METHOD", pay_method);
    // bind date as dd/MM/yyyy plus a time component so TO_DATE format matches
    query.bindValue(":DATE_TRANS", date_trans.toString("dd/MM/yyyy") + " 00:00:00");
    query.bindValue(":STATUS", status);
    

    qDebug() << "Modifier requête:" << queryStr;
    qDebug() << ":DATE_TRANS bind:" << date_trans.toString("dd/MM/yyyy") + " 00:00:00" << " :IDT=" << id << " :ID=" << refId;
    if (!query.exec()) {
        qDebug() << "❌ Erreur modification transaction :" << query.lastError().text();
        return false;
    }
    qDebug() << "✅ Transaction mise à jour avec succès, id:" << id;
    return true;
}
