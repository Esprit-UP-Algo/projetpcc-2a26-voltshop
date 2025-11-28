#pragma once
#include <QString>
#include <QVector>

struct Article {
    int     SKU = 0;
    QString NAME, CATEGORY, BRAND;
    double  PURCHASEPRICE = 0.0, SELLINGPRICE = 0.0;
    int     STOCK = 0;
    QString LOCATION, COMPATIBILITY;
};

class article_dao {
public:
    static bool create(const Article& a);   // INSERT
    static bool update(const Article& a);   // UPDATE WHERE SKU
    static bool remove(int sku);            // DELETE
    static bool exists(int sku);            // SELECT 1
    static QVector<Article> fetchAll();     // SELECT *
    static QVector<Article> fetchBelowStock(int threshold);
    static QVector<Article> fetchAllOrderByStock(bool ascending = true);
    static QVector<Article> fetchAllSortedByStock();
};
