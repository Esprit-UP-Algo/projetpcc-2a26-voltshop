#include "article_dao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

bool ArticleDAO::create(const Article& a) {
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

bool ArticleDAO::update(const Article& a) {
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

bool ArticleDAO::remove(int sku) {
    QSqlQuery q;
    q.prepare("DELETE FROM TAB_ART WHERE SKU=:sku");
    q.bindValue(":sku", sku);

    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();
    ok ? db.commit() : db.rollback();
    return ok;
}

bool ArticleDAO::exists(int sku) {
    QSqlQuery q;
    q.prepare("SELECT 1 FROM TAB_ART WHERE SKU=:sku");
    q.bindValue(":sku", sku);
    return q.exec() && q.next();
}

QVector<Article> ArticleDAO::fetchAll() {
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
