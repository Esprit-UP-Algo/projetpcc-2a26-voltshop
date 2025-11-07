#ifndef ARTICLE_DAO_H
#define ARTICLE_DAO_H

#include <QString>
#include <QVector>

struct Article {
    int     SKU{};
    QString NAME;
    QString CATEGORY;
    QString BRAND;
    double  PURCHASEPRICE{};
    double  SELLINGPRICE{};
    int     STOCK{};
    QString LOCATION;
    QString COMPATIBILITY;
};

class ArticleDAO {
public:
    // Validations (déjà utilisées dans ton .cpp)
    static bool isNumeric(const QString& value);
    static bool validate(const Article& a, QString& errorMsg);

    // CRUD
    static bool create(const Article& a);
    static bool update(const Article& a);
    static bool remove(int sku);
    static bool exists(int sku);
    static QVector<Article> fetchAll();

    // ✅ NOUVEAU : sélection des articles sous un seuil
    static QVector<Article> fetchBelowStock(int threshold);
};

#endif // ARTICLE_DAO_H
