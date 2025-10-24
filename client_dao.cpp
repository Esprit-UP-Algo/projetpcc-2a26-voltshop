#include "client_dao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

bool ClientDAO::create(const Client& c) {
    QSqlQuery q;
    q.prepare(R"(
        INSERT INTO TAB_CLIENT
            (CIN, FIRST_NAME, LAST_NAME, EMAIL, PHONE_NBR, ADRESS)
        VALUES (:cin, :fn, :ln, :em, :ph, :ad)
    )");
    q.bindValue(":cin", c.CIN);
    q.bindValue(":fn",  c.FIRST_NAME);
    q.bindValue(":ln",  c.LAST_NAME);
    q.bindValue(":em",  c.EMAIL);
    q.bindValue(":ph",  c.PHONE_NBR);
    q.bindValue(":ad",  c.ADRESS);

    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();
    ok ? db.commit() : db.rollback();
    return ok;
}

bool ClientDAO::update(const Client& c) {
    QSqlQuery q;
    q.prepare(R"(
        UPDATE TAB_CLIENT
           SET FIRST_NAME = :fn,
               LAST_NAME  = :ln,
               EMAIL      = :em,
               PHONE_NBR  = :ph,
               ADRESS     = :ad
         WHERE CIN        = :cin
    )");
    q.bindValue(":fn",  c.FIRST_NAME);
    q.bindValue(":ln",  c.LAST_NAME);
    q.bindValue(":em",  c.EMAIL);
    q.bindValue(":ph",  c.PHONE_NBR);
    q.bindValue(":ad",  c.ADRESS);
    q.bindValue(":cin", c.CIN);

    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();
    ok ? db.commit() : db.rollback();
    return ok;
}

bool ClientDAO::remove(const QString& cin) {
    QSqlQuery q;
    q.prepare("DELETE FROM TAB_CLIENT WHERE CIN=:cin");
    q.bindValue(":cin", cin);

    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();
    ok ? db.commit() : db.rollback();
    return ok;
}

bool ClientDAO::exists(const QString& cin) {
    QSqlQuery q;
    q.prepare("SELECT 1 FROM TAB_CLIENT WHERE CIN=:cin");
    q.bindValue(":cin", cin);
    return q.exec() && q.next();
}

QVector<Client> ClientDAO::fetchAll() {
    QVector<Client> out;
    QSqlQuery q(R"(
        SELECT CIN, FIRST_NAME, LAST_NAME, EMAIL, PHONE_NBR, ADRESS
          FROM TAB_CLIENT
         ORDER BY CIN
    )");
    while (q.next()) {
        Client c;
        c.CIN        = q.value(0).toString();
        c.FIRST_NAME = q.value(1).toString();
        c.LAST_NAME  = q.value(2).toString();
        c.EMAIL      = q.value(3).toString();
        c.PHONE_NBR  = q.value(4).toString();
        c.ADRESS     = q.value(5).toString();
        out.push_back(c);
    }
    return out;
}
