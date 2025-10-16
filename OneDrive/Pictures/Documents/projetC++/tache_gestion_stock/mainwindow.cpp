#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QHeaderView>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupTabArt();
    loadTabArt();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTabArt()
{
    ui->tab_Art->setColumnCount(9);
    QStringList headers{
        "SKU", "Name", "Category", "Brand",
        "Purchase Price", "Selling Price", "Stock", "Location", "Compatibility"
    };
    ui->tab_Art->setHorizontalHeaderLabels(headers);

    ui->tab_Art->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tab_Art->setSelectionMode(QAbstractItemView::SingleSelection);

    // édition directe dans le tableau
    ui->tab_Art->setEditTriggers(QAbstractItemView::DoubleClicked
                                 |QAbstractItemView::SelectedClicked
                                 |QAbstractItemView::EditKeyPressed);

    ui->tab_Art->horizontalHeader()->setStretchLastSection(true);
    ui->tab_Art->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

QString MainWindow::columnNameFor(int column) const
{
    switch (column) {
    case 0: return "SKU";
    case 1: return "NAME";
    case 2: return "CATEGORY";
    case 3: return "BRAND";
    case 4: return "PURCHASEPRICE";
    case 5: return "SELLINGPRICE";
    case 6: return "STOCK";
    case 7: return "LOCATION";
    case 8: return "COMPATIBILITY";
    }
    return {};
}

void MainWindow::loadTabArt()
{
    m_loading = true;
    ui->tab_Art->setRowCount(0);

    QSqlQuery q;  // <— pas d'exécution implicite
    const char* sql =
        "SELECT "
        "  SKU, NAME, CATEGORY, BRAND, "
        "  PURCHASEPRICE, SELLINGPRICE, STOCK, LOCATION, COMPATIBILITY "
        "FROM TAB_ART "
        "ORDER BY SKU";

    if (!q.exec(sql)) {  // <— exécuter UNE seule fois
        QMessageBox::critical(this, "Erreur SELECT", q.lastError().text());
        m_loading = false;
        return;
    }

    int r = 0;
    while (q.next()) {
        ui->tab_Art->insertRow(r);
        for (int c = 0; c < 9; ++c)
            ui->tab_Art->setItem(r, c, new QTableWidgetItem(q.value(c).toString()));
        ++r;
    }
    m_loading = false;
}

// ============================
//  Bouton "confirm" -> INSERT
// ============================
void MainWindow::on_confirm_clicked()
{
    const QString skuStr = ui->Sku->text().trimmed();
    if (skuStr.isEmpty()) {
        QMessageBox::warning(this, "Validation", "SKU est obligatoire (clé primaire).");
        ui->Sku->setFocus();
        return;
    }

    const int     sku   = skuStr.toInt();
    const QString name  = ui->name->text();
    const QString cat   = ui->cat->text();
    const QString brand = ui->brand->currentText();
    const double  buy   = ui->price1->text().toDouble();
    const double  sell  = ui->price2->text().toDouble();
    const int     stock = ui->stock->text().toInt();
    const QString loc   = ui->loca->text();
    const QString comp  = ui->com->text();

    QSqlQuery q;
    q.prepare(R"(
        INSERT INTO TAB_ART
        (SKU, NAME, CATEGORY, BRAND, PURCHASEPRICE, SELLINGPRICE, STOCK, LOCATION, COMPATIBILITY)
        VALUES (:sku, :name, :cat, :brand, :buy, :sell, :stock, :loc, :comp)
    )");
    q.bindValue(":sku",   sku);
    q.bindValue(":name",  name);
    q.bindValue(":cat",   cat);
    q.bindValue(":brand", brand);
    q.bindValue(":buy",   buy);
    q.bindValue(":sell",  sell);
    q.bindValue(":stock", stock);
    q.bindValue(":loc",   loc);
    q.bindValue(":comp",  comp);

    auto db = QSqlDatabase::database();
    db.transaction();
    if (!q.exec()) {
        db.rollback();
        QMessageBox::critical(this, "Erreur INSERT", q.lastError().text());
        return;
    }
    db.commit();

    loadTabArt();
    QMessageBox::information(this, "Succès", "Article ajouté.");
}

// ========================================
//  Édition d'une cellule -> UPDATE Oracle
// ========================================
void MainWindow::on_tab_Art_cellChanged(int row, int column)
{
    if (m_loading) return;
    if (column == 0) return; // ne pas éditer la PK ici

    bool ok = false;
    const int sku = ui->tab_Art->item(row, 0)->text().toInt(&ok);
    if (!ok) return;

    const QString colName = columnNameFor(column);
    if (colName.isEmpty()) return;

    const QString newVal = ui->tab_Art->item(row, column)
                               ? ui->tab_Art->item(row, column)->text()
                               : QString();

    QSqlQuery q;
    const QString sql = QString("UPDATE TAB_ART SET %1 = :val WHERE SKU = :sku").arg(colName);
    q.prepare(sql);

    if (colName == "PURCHASEPRICE" || colName == "SELLINGPRICE")
        q.bindValue(":val", newVal.toDouble());
    else if (colName == "STOCK")
        q.bindValue(":val", newVal.toInt());
    else
        q.bindValue(":val", newVal);

    q.bindValue(":sku", sku);

    auto db = QSqlDatabase::database();
    db.transaction();
    if (!q.exec()) {
        db.rollback();
        QMessageBox::critical(this, "Erreur UPDATE", q.lastError().text());
        loadTabArt(); // annule l'édition côté UI
        return;
    }
    db.commit();
}

// ===============================
//  Bouton "delete" -> DELETE SQL
// ===============================
void MainWindow::on_delete_clicked()
{
    const auto sel = ui->tab_Art->selectionModel()->selectedRows();
    if (sel.isEmpty()) {
        QMessageBox::information(this, "Suppression", "Sélectionne une ligne.");
        return;
    }

    const int row = sel.first().row();
    bool ok = false;
    const int sku = ui->tab_Art->item(row, 0)->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Suppression", "SKU invalide pour la ligne sélectionnée.");
        return;
    }

    if (QMessageBox::question(this, "Confirmer",
                              QString("Supprimer l'article avec SKU %1 ?").arg(sku)) != QMessageBox::Yes) {
        return;
    }

    QSqlQuery q;
    q.prepare("DELETE FROM TAB_ART WHERE SKU = :sku");
    q.bindValue(":sku", sku);

    auto db = QSqlDatabase::database();
    db.transaction();
    if (!q.exec()) {
        db.rollback();
        QMessageBox::critical(this, "Erreur DELETE", q.lastError().text());
        return;
    }
    db.commit();

    loadTabArt();
}
