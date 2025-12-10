#include "article_dao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

bool article_dao::create(const Article& a) {
    QSqlQuery q;
    q.prepare(R"(
        INSERT INTO TAB_ART
        (SKU, NAME, CATEGORY, BRAND, PURCHASEPRICE, SELLINGPRICE, STOCK, LOCATION, COMPATIBILITY)
        VALUES (:sku,:n,:c,:b,:p1,:p2,:s,:l,:cp)
    )");
    q.bindValue(":sku", a.SKU);
    q.bindValue(":n",   a.NAME);
    q.bindValue(":c",   a.CATEGORY);
    q.bindValue(":b",   a.BRAND);
    q.bindValue(":p1",  a.PURCHASEPRICE);
    q.bindValue(":p2",  a.SELLINGPRICE);
    q.bindValue(":s",   a.STOCK);
    q.bindValue(":l",   a.LOCATION);
    q.bindValue(":cp",  a.COMPATIBILITY);

    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();
    ok ? db.commit() : db.rollback();
    return ok;
}

bool article_dao::update(const Article& a) {
    QSqlQuery q;
    q.prepare(R"(
        UPDATE TAB_ART
           SET NAME=:n, CATEGORY=:c, BRAND=:b,
               PURCHASEPRICE=:p1, SELLINGPRICE=:p2,
               STOCK=:s, LOCATION=:l, COMPATIBILITY=:cp
         WHERE SKU=:sku
    )");
    q.bindValue(":n",   a.NAME);
    q.bindValue(":c",   a.CATEGORY);
    q.bindValue(":b",   a.BRAND);
    q.bindValue(":p1",  a.PURCHASEPRICE);
    q.bindValue(":p2",  a.SELLINGPRICE);
    q.bindValue(":s",   a.STOCK);
    q.bindValue(":l",   a.LOCATION);
    q.bindValue(":cp",  a.COMPATIBILITY);
    q.bindValue(":sku", a.SKU);

    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();
    ok ? db.commit() : db.rollback();
    return ok;
}

bool article_dao::remove(int sku)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "DB not open in article_dao::remove";
        return false;
    }

    db.transaction();

    // 1) Supprimer d'abord dans CONCERNER (toutes les commandes qui utilisent cet article)
    {
        QSqlQuery qCon(db);
        if (!qCon.prepare("DELETE FROM CONCERNER WHERE SKU = :sku")) {
            qDebug() << "Error prepare DELETE CONCERNER:" << qCon.lastError().text();
            db.rollback();
            return false;
        }
        qCon.bindValue(":sku", sku);

        if (!qCon.exec()) {
            qDebug() << "Error exec DELETE CONCERNER:" << qCon.lastError().text();
            db.rollback();
            return false;
        }
    }

    // 2) Supprimer l'article dans TAB_ART
    {
        QSqlQuery qArt(db);
        if (!qArt.prepare("DELETE FROM TAB_ART WHERE SKU = :sku")) {
            qDebug() << "Error prepare DELETE TAB_ART:" << qArt.lastError().text();
            db.rollback();
            return false;
        }
        qArt.bindValue(":sku", sku);

        if (!qArt.exec()) {
            qDebug() << "Error exec DELETE TAB_ART:" << qArt.lastError().text();
            db.rollback();
            return false;
        }
    }

    db.commit();
    return true;
}

bool article_dao::exists(int sku) {
    QSqlQuery q;
    q.prepare("SELECT 1 FROM TAB_ART WHERE SKU=:sku");
    q.bindValue(":sku", sku);
    return q.exec() && q.next();
}

QVector<Article> article_dao::fetchAll() {
    QVector<Article> out;
    QSqlQuery q(R"(
        SELECT SKU, NAME, CATEGORY, BRAND,
               PURCHASEPRICE, SELLINGPRICE, STOCK, LOCATION, COMPATIBILITY
          FROM TAB_ART
         ORDER BY SKU
    )");
    while (q.next()) {
        Article a;
        a.SKU            = q.value(0).toInt();
        a.NAME           = q.value(1).toString();
        a.CATEGORY       = q.value(2).toString();
        a.BRAND          = q.value(3).toString();
        a.PURCHASEPRICE  = q.value(4).toDouble();
        a.SELLINGPRICE   = q.value(5).toDouble();
        a.STOCK          = q.value(6).toInt();
        a.LOCATION       = q.value(7).toString();
        a.COMPATIBILITY  = q.value(8).toString();
        out.push_back(a);
    }
    return out;
}
QVector<Article> article_dao::fetchBelowStock(int threshold)
{
    QVector<Article> result;
    QSqlQuery q;

    q.prepare(R"(
        SELECT SKU, NAME, CATEGORY, BRAND, PURCHASEPRICE,
               SELLINGPRICE, STOCK, LOCATION, COMPATIBILITY
        FROM TAB_ART
        WHERE STOCK < :th
        ORDER BY STOCK ASC
    )");

    q.bindValue(":th", threshold);

    if (!q.exec())
        return result;

    while (q.next()) {
        Article a;
        a.SKU           = q.value(0).toInt();
        a.NAME          = q.value(1).toString();
        a.CATEGORY      = q.value(2).toString();
        a.BRAND         = q.value(3).toString();
        a.PURCHASEPRICE = q.value(4).toFloat();
        a.SELLINGPRICE  = q.value(5).toFloat();
        a.STOCK         = q.value(6).toInt();
        a.LOCATION      = q.value(7).toString();
        a.COMPATIBILITY = q.value(8).toString();

        result.append(a);
    }

    return result;
}
QVector<Article> article_dao::fetchStockBetween(int minStock, int maxStock)
{
    QVector<Article> result;
    QSqlQuery q;

    q.prepare(R"(
        SELECT SKU, NAME, CATEGORY, BRAND, PURCHASEPRICE,
               SELLINGPRICE, STOCK, LOCATION, COMPATIBILITY
        FROM TAB_ART
        WHERE STOCK BETWEEN :minVal AND :maxVal
        ORDER BY STOCK ASC
    )");

    q.bindValue(":minVal", minStock);
    q.bindValue(":maxVal", maxStock);

    if (!q.exec())
        return result;

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

        result.append(a);
    }

    return result;
}


QVector<Article> article_dao::fetchAllOrderByStock(bool ascending)
{
    QVector<Article> result;

    QSqlQuery q;
    QString order = ascending ? "ASC" : "DESC";

    q.prepare(QStringLiteral(R"(
        SELECT SKU,
               NAME,
               CATEGORY,
               BRAND,
               PURCHASEPRICE,
               SELLINGPRICE,
               STOCK,
               LOCATION,
               COMPATIBILITY
        FROM TAB_ART
        ORDER BY STOCK %1
    )").arg(order));

    if (!q.exec()) {
        qWarning() << "fetchAllOrderByStock failed:" << q.lastError().text();
        return result;
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

        result.push_back(a);
    }

    return result;
}
// article_dao.cpp
QVector<Article> article_dao::fetchAllSortedByStock()
{
    QVector<Article> list;

    QSqlQuery q;
    q.prepare(R"(
        SELECT SKU, NAME, CATEGORY, BRAND, PURCHASEPRICE,
               SELLINGPRICE, STOCK, LOCATION, COMPATIBILITY
        FROM TAB_ART
        ORDER BY STOCK ASC
    )");

    if (!q.exec()) {
        qDebug() << "Error fetchAllSortedByStock:" << q.lastError().text();
        return list;
    }

    while (q.next()) {
        Article a;

        a.SKU           = q.value("SKU").toInt();
        a.NAME          = q.value("NAME").toString();
        a.CATEGORY      = q.value("CATEGORY").toString();
        a.BRAND         = q.value("BRAND").toString();
        a.PURCHASEPRICE = q.value("PURCHASEPRICE").toDouble();
        a.SELLINGPRICE  = q.value("SELLINGPRICE").toDouble();
        a.STOCK         = q.value("STOCK").toInt();
        a.LOCATION      = q.value("LOCATION").toString();
        a.COMPATIBILITY = q.value("COMPATIBILITY").toString();

        list.append(a);
    }

    return list;
}


