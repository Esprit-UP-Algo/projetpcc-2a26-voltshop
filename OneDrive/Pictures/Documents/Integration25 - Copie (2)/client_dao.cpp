#include "client_dao.h"
#include "Connection.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QVariant>
#include <QMessageBox>
#include <QRegularExpression>

// ==============================
//  Helpers de validation
// ==============================
static bool isDigits(const QString& s)
{
    // Chiffres uniquement (vide refusé ailleurs)
    static const QRegularExpression re(R"(^\d+$)");
    return re.match(s.trimmed()).hasMatch();
}

static bool validateClientFields(const Client& c, QString& err)
{
    // Champs obligatoires
    if (c.CIN.trimmed().isEmpty()
        || c.FIRST_NAME.trimmed().isEmpty()
        || c.LAST_NAME.trimmed().isEmpty()
        || c.EMAIL.trimmed().isEmpty()
        || c.PHONE_NBR.trimmed().isEmpty()
        || c.ADRESS.trimmed().isEmpty())
    {
        err = "Tous les champs client sont obligatoires.";
        return false;
    }

    // CIN : chiffres uniquement
    if (!isDigits(c.CIN)) {
        err = "CIN doit contenir uniquement des chiffres.";
        return false;
    }

    // PHONE_NBR : chiffres uniquement
    if (!isDigits(c.PHONE_NBR)) {
        err = "Phone number doit contenir uniquement des chiffres.";
        return false;
    }

    // (Optionnel) si tu veux forcer une longueur précise :
    // if (c.PHONE_NBR.size() != 8) { err = "Phone number doit contenir 8 chiffres."; return false; }

    return true;
}

// ==============================
//  CREATE
// ==============================
bool ClientDAO::create(const Client& c)
{
    QString err;
    if (!validateClientFields(c, err)) {
        QMessageBox::warning(nullptr, "Validation client", err);
        return false;
    }

    QSqlQuery q(Connection::instance().db());
    q.prepare(R"(
        INSERT INTO TAB_CLIENT (CIN, FIRST_NAME, LAST_NAME, EMAIL, PHONE_NBR, ADRESS)
        VALUES (:cin, :fn, :ln, :em, :ph, :ad)
    )");
    q.bindValue(":cin", c.CIN.trimmed());
    q.bindValue(":fn",  c.FIRST_NAME.trimmed());
    q.bindValue(":ln",  c.LAST_NAME.trimmed());
    q.bindValue(":em",  c.EMAIL.trimmed());
    q.bindValue(":ph",  c.PHONE_NBR.trimmed());
    q.bindValue(":ad",  c.ADRESS.trimmed());

    auto& db = Connection::instance().db();
    db.transaction();
    bool ok = q.exec();
    ok ? db.commit() : db.rollback();

    if (!ok) {
        QMessageBox::critical(nullptr, "Erreur INSERT CLIENT", q.lastError().text());
    }
    return ok;
}

// ==============================
//  UPDATE (clé = CIN)
// ==============================
bool ClientDAO::update(const Client& c)
{
    QString err;
    if (!validateClientFields(c, err)) {
        QMessageBox::warning(nullptr, "Validation client", err);
        return false;
    }

    QSqlQuery q(Connection::instance().db());
    q.prepare(R"(
        UPDATE TAB_CLIENT
           SET FIRST_NAME = :fn,
               LAST_NAME  = :ln,
               EMAIL      = :em,
               PHONE_NBR  = :ph,
               ADRESS     = :ad
         WHERE CIN        = :cin
    )");
    q.bindValue(":fn",  c.FIRST_NAME.trimmed());
    q.bindValue(":ln",  c.LAST_NAME.trimmed());
    q.bindValue(":em",  c.EMAIL.trimmed());
    q.bindValue(":ph",  c.PHONE_NBR.trimmed());
    q.bindValue(":ad",  c.ADRESS.trimmed());
    q.bindValue(":cin", c.CIN.trimmed());

    auto& db = Connection::instance().db();
    db.transaction();
    bool ok = q.exec();
    ok ? db.commit() : db.rollback();

    if (!ok) {
        QMessageBox::critical(nullptr, "Erreur UPDATE CLIENT", q.lastError().text());
    }
    return ok;
}

// ==============================
//  DELETE
// ==============================
bool ClientDAO::remove(const QString& cin)
{
    const QString cinT = cin.trimmed();
    if (cinT.isEmpty() || !isDigits(cinT)) {
        QMessageBox::warning(nullptr, "Suppression client",
                             "CIN invalide : chiffres uniquement.");
        return false;
    }

    QSqlQuery q(Connection::instance().db());
    q.prepare("DELETE FROM TAB_CLIENT WHERE CIN = :cin");
    q.bindValue(":cin", cinT);

    auto& db = Connection::instance().db();
    db.transaction();
    bool ok = q.exec();
    ok ? db.commit() : db.rollback();

    if (!ok) {
        QMessageBox::critical(nullptr, "Erreur DELETE CLIENT", q.lastError().text());
    }
    return ok;
}

// ==============================
//  EXISTS
// ==============================
bool ClientDAO::exists(const QString& cin)
{
    const QString cinT = cin.trimmed();
    if (cinT.isEmpty() || !isDigits(cinT)) return false;

    QSqlQuery q(Connection::instance().db());
    q.prepare("SELECT 1 FROM TAB_CLIENT WHERE CIN = :cin");
    q.bindValue(":cin", cinT);
    return q.exec() && q.next();
}

// ==============================
//  FETCH ALL
// ==============================
QVector<Client> ClientDAO::fetchAll()
{
    QVector<Client> out;

    QSqlQuery q(Connection::instance().db());
    q.prepare(R"(
        SELECT CIN, FIRST_NAME, LAST_NAME, EMAIL, PHONE_NBR, ADRESS
          FROM TAB_CLIENT
         ORDER BY CIN
    )");
    if (!q.exec()) {
        // on peut logguer si besoin
        return out;
    }

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
