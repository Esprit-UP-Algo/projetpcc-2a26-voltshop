#include "transaction.h"
#include "connection.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

Transaction::Transaction() {}

<<<<<<< HEAD
Transaction::Transaction(int id, QString amount, QString pay_method, QDate date_trans, QString status, int idcom, int refId)
    : id(id), amount(amount), pay_method(pay_method), date_trans(date_trans), status(status), idcom(idcom), refId(refId)
=======
Transaction::Transaction(int id, QString amount, QString pay_method, QDate date_trans, QString status, int refId)
    : id(id), amount(amount), pay_method(pay_method), date_trans(date_trans), status(status), refId(refId)
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94
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

<<<<<<< HEAD
    // Build INSERT: include required ID column (refId -> TAB_TRANS.ID) and optional IDCOM
=======
    // Build INSERT: include required ID column (refId -> TAB_TRANS.ID)
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94
    QString cols = "IDT, ID, AMOUNT, PAY_METHOD, DATE_TRANS, STATUS";
    // Use TO_DATE on the placeholder so Oracle converts the provided string to a DATE
    // Use DD/MM/YYYY HH24:MI:SS and always send a time part to avoid format mismatches
    QString vals = ":IDT, :ID, :AMOUNT, :PAY_METHOD, TO_DATE(:DATE_TRANS,'DD/MM/YYYY HH24:MI:SS'), :STATUS";
<<<<<<< HEAD
    if (idcom > 0) {
        cols += ", IDCOM";
        vals += ", :IDCOM";
    }
=======
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94
    QString sql = QString("INSERT INTO TAB_TRANS (%1) VALUES (%2)").arg(cols, vals);
    query.prepare(sql);
    query.bindValue(":IDT", id);
    query.bindValue(":ID", refId);
    query.bindValue(":AMOUNT", amount);
    query.bindValue(":PAY_METHOD", pay_method);
    query.bindValue(":DATE_TRANS", date_trans.toString("dd/MM/yyyy") + " 00:00:00");
    query.bindValue(":STATUS", status);
<<<<<<< HEAD
    if (idcom > 0) query.bindValue(":IDCOM", idcom);
=======
    Q_UNUSED(id);
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94

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

    QSqlQuery query;
    query.prepare("DELETE FROM TAB_TRANS WHERE IDT = :ID");
    query.bindValue(":ID", id);

    if (!query.exec()) {
        qDebug() << "❌ Erreur suppression transaction :" << query.lastError().text();
        return false;
    }
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
<<<<<<< HEAD
    model->setQuery("SELECT IDT, ID, AMOUNT, PAY_METHOD, DATE_TRANS, STATUS, IDCOM FROM TAB_TRANS");
=======
    model->setQuery("SELECT IDT, ID, AMOUNT, PAY_METHOD, DATE_TRANS, STATUS FROM TAB_TRANS");
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94

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
    
<<<<<<< HEAD
    QString queryStr = "UPDATE TAB_TRANS SET AMOUNT = :AMOUNT, PAY_METHOD = :PAY_METHOD, DATE_TRANS = TO_DATE(:DATE_TRANS,'DD/MM/YYYY HH24:MI:SS'), STATUS = :STATUS, ID = :ID";
    if (idcom > 0) queryStr += ", IDCOM = :IDCOM";
    else queryStr += ", IDCOM = NULL";
    queryStr += " WHERE IDT = :IDT";
=======
    QString queryStr = "UPDATE TAB_TRANS SET AMOUNT = :AMOUNT, PAY_METHOD = :PAY_METHOD, DATE_TRANS = TO_DATE(:DATE_TRANS,'DD/MM/YYYY HH24:MI:SS'), STATUS = :STATUS, ID = :ID WHERE IDT = :IDT";
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94

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
<<<<<<< HEAD
    if (idcom > 0) query.bindValue(":IDCOM", idcom);
=======
    
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94

    qDebug() << "Modifier requête:" << queryStr;
    qDebug() << ":DATE_TRANS bind:" << date_trans.toString("dd/MM/yyyy") + " 00:00:00" << " :IDT=" << id << " :ID=" << refId;
    if (!query.exec()) {
        qDebug() << "❌ Erreur modification transaction :" << query.lastError().text();
        return false;
    }
    qDebug() << "✅ Transaction mise à jour avec succès, id:" << id;
    return true;
}
