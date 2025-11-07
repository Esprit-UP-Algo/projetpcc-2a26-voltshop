#include "article_dao.h"
#include "Connection.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QVariant>
#include <QMessageBox>
#include <QRegularExpression>

// =========================================================
// Vérifie si une chaîne est un nombre entier ou décimal
// =========================================================
bool ArticleDAO::isNumeric(const QString& value)
{
    QRegularExpression re(R"(^\d+(\.\d+)?$)");  // accepte 123 ou 123.45
    return re.match(value.trimmed()).hasMatch();
}

// =========================================================
bool ArticleDAO::validate(const Article& a, QString& errorMsg)
{
    // Convertir les valeurs d’entrée en chaînes pour test
    QString skuStr      = QString::number(a.SKU);
    QString purchaseStr = QString::number(a.PURCHASEPRICE);
    QString sellingStr  = QString::number(a.SELLINGPRICE);
    QString stockStr    = QString::number(a.STOCK);

    // ✅ Vérifie les champs numériques
    if (!isNumeric(skuStr) || a.SKU <= 0) {
        errorMsg = "Erreur : Le SKU doit être un nombre entier positif.";
        return false;
    }
    if (!isNumeric(purchaseStr) || a.PURCHASEPRICE < 0) {
        errorMsg = "Erreur : Le prix d'achat doit être un nombre valide.";
        return false;
    }
    if (!isNumeric(sellingStr) || a.SELLINGPRICE < 0) {
        errorMsg = "Erreur : Le prix de vente doit être un nombre valide.";
        return false;
    }
    if (!isNumeric(stockStr) || a.STOCK < 0) {
        errorMsg = "Erreur : Le stock doit être un nombre entier valide.";
        return false;
    }

    // ✅ Vérifie les champs texte
    if (a.NAME.trimmed().isEmpty() ||
        a.CATEGORY.trimmed().isEmpty() ||
        a.BRAND.trimmed().isEmpty() ||
        a.LOCATION.trimmed().isEmpty() ||
        a.COMPATIBILITY.trimmed().isEmpty()) {
        errorMsg = "Erreur : Tous les champs texte doivent être remplis.";
        return false;
    }

    return true;
}

// =========================================================
// CREATE
// =========================================================
bool ArticleDAO::create(const Article& a)
{
    QString err;
    if (!validate(a, err)) {
        QMessageBox::warning(nullptr, "Erreur de saisie", err);
        return false;
    }

    // Garde-fou numérique
    if (!isNumeric(QString::number(a.SKU)) ||
        !isNumeric(QString::number(a.PURCHASEPRICE)) ||
        !isNumeric(QString::number(a.SELLINGPRICE)) ||
        !isNumeric(QString::number(a.STOCK))) {
        QMessageBox::warning(nullptr, "Erreur de saisie",
                             "Les champs SKU, prix et stock doivent contenir uniquement des chiffres.");
        return false;
    }

    QSqlQuery q(Connection::instance().db());
    q.prepare(R"(
        INSERT INTO TAB_ART
            (SKU, NAME, CATEGORY, BRAND,
             PURCHASEPRICE, SELLINGPRICE, STOCK, LOCATION, COMPATIBILITY)
        VALUES
            (:sku, :name, :cat, :brand,
             :buy, :sell, :stock, :loc, :comp)
    )");

    q.bindValue(":sku",   a.SKU);
    q.bindValue(":name",  a.NAME);
    q.bindValue(":cat",   a.CATEGORY);
    q.bindValue(":brand", a.BRAND);
    q.bindValue(":buy",   a.PURCHASEPRICE);
    q.bindValue(":sell",  a.SELLINGPRICE);
    q.bindValue(":stock", a.STOCK);
    q.bindValue(":loc",   a.LOCATION);
    q.bindValue(":comp",  a.COMPATIBILITY);

    auto& db = Connection::instance().db();
    db.transaction();
    bool ok = q.exec();
    ok ? db.commit() : db.rollback();

    if (!ok)
        QMessageBox::critical(nullptr, "Erreur INSERT", q.lastError().text());
    return ok;
}

// =========================================================
// UPDATE
// =========================================================
bool ArticleDAO::update(const Article& a)
{
    QString err;
    if (!validate(a, err)) {
        QMessageBox::warning(nullptr, "Erreur de saisie", err);
        return false;
    }

    if (!isNumeric(QString::number(a.SKU)) ||
        !isNumeric(QString::number(a.PURCHASEPRICE)) ||
        !isNumeric(QString::number(a.SELLINGPRICE)) ||
        !isNumeric(QString::number(a.STOCK))) {
        QMessageBox::warning(nullptr, "Erreur de saisie",
                             "Les champs SKU, prix et stock doivent contenir uniquement des chiffres.");
        return false;
    }

    QSqlQuery q(Connection::instance().db());
    q.prepare(R"(
        UPDATE TAB_ART
           SET NAME          = :name,
               CATEGORY      = :cat,
               BRAND         = :brand,
               PURCHASEPRICE = :buy,
               SELLINGPRICE  = :sell,
               STOCK         = :stock,
               LOCATION      = :loc,
               COMPATIBILITY = :comp
         WHERE SKU           = :sku
    )");

    q.bindValue(":name",  a.NAME);
    q.bindValue(":cat",   a.CATEGORY);
    q.bindValue(":brand", a.BRAND);
    q.bindValue(":buy",   a.PURCHASEPRICE);
    q.bindValue(":sell",  a.SELLINGPRICE);
    q.bindValue(":stock", a.STOCK);
    q.bindValue(":loc",   a.LOCATION);
    q.bindValue(":comp",  a.COMPATIBILITY);
    q.bindValue(":sku",   a.SKU);

    auto& db = Connection::instance().db();
    db.transaction();
    bool ok = q.exec();
    ok ? db.commit() : db.rollback();

    if (!ok)
        QMessageBox::critical(nullptr, "Erreur UPDATE", q.lastError().text());
    return ok;
}

// =========================================================
// DELETE
// =========================================================
bool ArticleDAO::remove(int sku)
{
    if (sku <= 0) {
        QMessageBox::warning(nullptr, "Erreur de suppression",
                             "Le SKU doit être un nombre entier valide.");
        return false;
    }

    QSqlQuery q(Connection::instance().db());
    q.prepare("DELETE FROM TAB_ART WHERE SKU = :sku");
    q.bindValue(":sku", sku);

    auto& db = Connection::instance().db();
    db.transaction();
    bool ok = q.exec();
    ok ? db.commit() : db.rollback();

    if (!ok)
        QMessageBox::critical(nullptr, "Erreur DELETE", q.lastError().text());
    return ok;
}

// =========================================================
// EXISTS
// =========================================================
bool ArticleDAO::exists(int sku)
{
    if (sku <= 0) return false;
    QSqlQuery q(Connection::instance().db());
    q.prepare("SELECT 1 FROM TAB_ART WHERE SKU = :sku");
    q.bindValue(":sku", sku);
    return q.exec() && q.next();
}

// =========================================================
QVector<Article> ArticleDAO::fetchAll()
{
    QVector<Article> out;
    QSqlQuery q(Connection::instance().db());
    q.prepare(R"(
        SELECT SKU, NAME, CATEGORY, BRAND,
               PURCHASEPRICE, SELLINGPRICE, STOCK, LOCATION, COMPATIBILITY
          FROM TAB_ART
         ORDER BY SKU
    )");
    if (!q.exec()) return out;

    while (q.next()) {
        Article a;
        a.SKU           = q.value(0).toInt();
        a.NAME          = q.value(1).toString();
        a.CATEGORY      = q.value(2).toString();
        a.BRAND         = q.value(3).toString();
        a.PURCHASEPRICE = q.value(4).toDouble();
        a.SELLINGPRICE  = q.value(5).toDouble();
        a.STOCK         = q.value(6).toInt();
        a.LOCATION      = q.value(7).toString();
        a.COMPATIBILITY = q.value(8).toString();
        out.push_back(a);
    }
    return out;
}

// =========================================================
// ✅ NOUVEAU : FETCH BELOW STOCK (seuil strict)
// =========================================================
QVector<Article> ArticleDAO::fetchBelowStock(int threshold)
{
    QVector<Article> out;

    QSqlQuery q(Connection::instance().db());
    q.prepare(R"(
        SELECT SKU, NAME, CATEGORY, BRAND,
               PURCHASEPRICE, SELLINGPRICE, STOCK, LOCATION, COMPATIBILITY
          FROM TAB_ART
         WHERE STOCK < :thr
         ORDER BY STOCK ASC, SKU ASC
    )");
    q.bindValue(":thr", threshold);

    if (!q.exec()) {
        QMessageBox::critical(nullptr, "Erreur SELECT sous seuil", q.lastError().text());
        return out;
    }

    while (q.next()) {
        Article a;
        a.SKU           = q.value(0).toInt();
        a.NAME          = q.value(1).toString();
        a.CATEGORY      = q.value(2).toString();
        a.BRAND         = q.value(3).toString();
        a.PURCHASEPRICE = q.value(4).toDouble();
        a.SELLINGPRICE  = q.value(5).toDouble();
        a.STOCK         = q.value(6).toInt();
        a.LOCATION      = q.value(7).toString();
        a.COMPATIBILITY = q.value(8).toString();
        out.push_back(a);
    }
    return out;
}
