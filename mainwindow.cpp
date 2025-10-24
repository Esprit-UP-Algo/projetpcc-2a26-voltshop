#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHeaderView>
#include <QAbstractItemView>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QIcon>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Boutons menu (doivent exister dans mainwindow.ui)
    connect(ui->btn_Client,      &QPushButton::clicked, this, &MainWindow::showSClient);
    connect(ui->btn_Commande,    &QPushButton::clicked, this, &MainWindow::showCommande);
    connect(ui->btn_Stock,       &QPushButton::clicked, this, &MainWindow::showStock);
    connect(ui->btn_Transaction, &QPushButton::clicked, this, &MainWindow::showTransaction);
    connect(ui->btn_Employee,    &QPushButton::clicked, this, &MainWindow::showEmployee);

    // Prépare le tableau et charge les données
    setupTabArt();
    refreshArticlesGrid();

    // Page d’accueil
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow(){ delete ui; }

// -------- Navigation --------
void MainWindow::showSClient()     { ui->stackedWidget->setCurrentIndex(0); }
void MainWindow::showCommande()    { ui->stackedWidget->setCurrentIndex(1); }
void MainWindow::showStock()       { ui->stackedWidget->setCurrentIndex(2); }
void MainWindow::showTransaction() { ui->stackedWidget->setCurrentIndex(3); }
void MainWindow::showEmployee()    { ui->stackedWidget->setCurrentIndex(4); }

// ------ Préparation tableau ------
void MainWindow::setupTabArt()
{
    // 1 colonne Actions + 9 colonnes données
    ui->tab_Art->setColumnCount(10);
    QStringList headers{
        "", "SKU", "Name", "Category", "Brand",
        "Purchase Price", "Selling Price", "Stock", "Location", "Compatibility"
    };
    ui->tab_Art->setHorizontalHeaderLabels(headers);

    ui->tab_Art->setEditTriggers(QAbstractItemView::NoEditTriggers); // édition via formulaire
    ui->tab_Art->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tab_Art->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tab_Art->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tab_Art->horizontalHeader()->setStretchLastSection(true);
    ui->tab_Art->setColumnWidth(0, 42); // colonne Actions (stylo seul)

    // Clic sur une ligne (hors actions) => passer en édition
    connect(ui->tab_Art, &QTableWidget::cellClicked, this, [this](int row, int col){
        if (row < 0) return;
        if (col == 0) return; // ignore la colonne actions
        populateFormFromRow(row);
        setFormMode(true);
    });
}

// (Mapping conservé si jamais tu veux réactiver l’édition cellulaire un jour)
QString MainWindow::columnNameFor(int column) const
{
    switch (column) {
    case 1: return "SKU";
    case 2: return "NAME";
    case 3: return "CATEGORY";
    case 4: return "BRAND";
    case 5: return "PURCHASEPRICE";
    case 6: return "SELLINGPRICE";
    case 7: return "STOCK";
    case 8: return "LOCATION";
    case 9: return "COMPATIBILITY";
    }
    return {};
}

// ------ Chargement des lignes ------
void MainWindow::refreshArticlesGrid()
{
    m_loading = true;
    ui->tab_Art->setRowCount(0);

    const auto rows = ArticleDAO::fetchAll();
    for (int i = 0; i < rows.size(); ++i) {
        const auto &a = rows[i];
        ui->tab_Art->insertRow(i);
        // col 0 = Actions
        ui->tab_Art->setItem(i,1, new QTableWidgetItem(QString::number(a.SKU)));
        ui->tab_Art->setItem(i,2, new QTableWidgetItem(a.NAME));
        ui->tab_Art->setItem(i,3, new QTableWidgetItem(a.CATEGORY));
        ui->tab_Art->setItem(i,4, new QTableWidgetItem(a.BRAND));
        ui->tab_Art->setItem(i,5, new QTableWidgetItem(QString::number(a.PURCHASEPRICE)));
        ui->tab_Art->setItem(i,6, new QTableWidgetItem(QString::number(a.SELLINGPRICE)));
        ui->tab_Art->setItem(i,7, new QTableWidgetItem(QString::number(a.STOCK)));
        ui->tab_Art->setItem(i,8, new QTableWidgetItem(a.LOCATION));
        ui->tab_Art->setItem(i,9, new QTableWidgetItem(a.COMPATIBILITY));

        addActionButtonsForRow(i); // stylo (sans DEL)
    }

    m_loading = false;
}

// ------ Formulaire -> Article ------
Article MainWindow::readFormArticle() const
{
    Article a;
    a.SKU           = ui->sku->text().trimmed().toInt();
    a.NAME          = ui->name->text().trimmed();
    a.CATEGORY      = ui->cat->text().trimmed();
    a.BRAND         = ui->brand->currentText().trimmed();
    a.PURCHASEPRICE = ui->price1->text().toDouble();
    a.SELLINGPRICE  = ui->price2->text().toDouble();
    a.STOCK         = ui->stock->text().toInt();
    a.LOCATION      = ui->loca->text().trimmed();
    a.COMPATIBILITY = ui->com->text().trimmed();
    return a;
}

// ------ Confirm : Add / Update ------
void MainWindow::on_confirm_clicked()
{
    if (ui->sku->text().trimmed().isEmpty()) {
        QMessageBox::warning(this,"Validation","SKU est obligatoire (clé primaire).");
        ui->sku->setFocus();
        return;
    }

    Article a = readFormArticle();

    if (!m_isEditMode) {
        // CREATE
        if (ArticleDAO::exists(a.SKU)) {
            QMessageBox::warning(this,"SKU existe déjà","Saisis un autre SKU ou passe en édition.");
            return;
        }
        if (!ArticleDAO::create(a)) {
            QMessageBox::critical(this,"INSERT","Échec d’ajout (voir logs).");
            return;
        }
        refreshArticlesGrid();
        QMessageBox::information(this,"Succès","Article ajouté.");
        setFormMode(false);
    } else {
        // UPDATE
        if (!ArticleDAO::update(a)) {
            QMessageBox::critical(this,"UPDATE","Échec de mise à jour (voir logs).");
            return;
        }
        refreshArticlesGrid();
        QMessageBox::information(this,"Succès","Article mis à jour.");
        setFormMode(false);
    }
}

// ------ Désactivé : on n’édite plus dans la grille ------
void MainWindow::on_tab_Art_cellChanged(int, int) {}

// ------ Delete global via sélection (bouton "delete") ------
void MainWindow::on_delete_clicked()
{
    const auto sel = ui->tab_Art->selectionModel()->selectedRows();
    if (sel.isEmpty()) {
        QMessageBox::information(this, "Suppression", "Sélectionne une ligne.");
        return;
    }
    const int row = sel.first().row();
    bool ok=false; const int sku = ui->tab_Art->item(row,1)->text().toInt(&ok);
    if (!ok) { QMessageBox::warning(this,"Suppression","SKU invalide."); return; }

    if (QMessageBox::question(this,"Confirmer",
                              QString("Supprimer l'article SKU %1 ?").arg(sku)) != QMessageBox::Yes) return;

    if (!ArticleDAO::remove(sku)) {
        QMessageBox::critical(this,"DELETE","Échec de suppression (contrainte FK ?).");
        return;
    }
    refreshArticlesGrid();
}

// ------ DEL global via Line_rech (bouton "DEL") ------
void MainWindow::on_DEL_clicked()
{
    const QString skuText = ui->Line_rech->text().trimmed();
    if (skuText.isEmpty()) {
        QMessageBox::information(this,"Suppression","Saisis le SKU dans Line_rech.");
        ui->Line_rech->setFocus();
        return;
    }
    bool ok=false; const int sku = skuText.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this,"Suppression","SKU invalide (entier attendu).");
        ui->Line_rech->setFocus(); ui->Line_rech->selectAll();
        return;
    }
    if (QMessageBox::question(this,"Confirmer",
                              QString("Supprimer l'article SKU %1 ?").arg(sku)) != QMessageBox::Yes) return;

    if (!ArticleDAO::remove(sku)) {
        QMessageBox::critical(this,"DELETE","Échec de suppression (introuvable/contrainte).");
        return;
    }
    refreshArticlesGrid();
    ui->Line_rech->clear();
}

// ------ Helpers UI ------
void MainWindow::setFormMode(bool edit)
{
    m_isEditMode = edit;
    if (edit) {
        ui->confirm->setText("Update");
        ui->sku->setEnabled(false); // PK non modifiable en édition
    } else {
        ui->confirm->setText("Confirm");
        ui->sku->setEnabled(true);
        m_currentRow = -1;
        // reset simple
        ui->sku->clear(); ui->name->clear(); ui->cat->clear(); ui->brand->setCurrentIndex(0);
        ui->price1->clear(); ui->price2->clear(); ui->stock->clear(); ui->loca->clear(); ui->com->clear();
    }
}

void MainWindow::populateFormFromRow(int row)
{
    if (row < 0 || row >= ui->tab_Art->rowCount()) return;
    m_currentRow = row;

    ui->sku->setText(   ui->tab_Art->item(row,1)->text() );
    ui->name->setText(  ui->tab_Art->item(row,2)->text() );
    ui->cat->setText(   ui->tab_Art->item(row,3)->text() );
    ui->brand->setCurrentText( ui->tab_Art->item(row,4)->text() );
    ui->price1->setText(ui->tab_Art->item(row,5)->text() );
    ui->price2->setText(ui->tab_Art->item(row,6)->text() );
    ui->stock->setText( ui->tab_Art->item(row,7)->text() );
    ui->loca->setText(  ui->tab_Art->item(row,8)->text() );
    ui->com->setText(   ui->tab_Art->item(row,9)->text() );
}

// ------ Colonne Actions : STYLO SEUL (Option B robuste) ------
void MainWindow::addActionButtonsForRow(int row)
{
    auto *editBtn = new QPushButton;
    editBtn->setToolTip("Edit");
    editBtn->setFlat(true);
    editBtn->setCursor(Qt::PointingHandCursor);
    editBtn->setIcon(QIcon(":/images/ressource/edit.png"));   // chemin qrc
    editBtn->setIconSize(QSize(16,16));
    editBtn->setStyleSheet("QPushButton{border:none;}");

    connect(editBtn, &QPushButton::clicked, this, [this, editBtn](){
        QWidget *cell = editBtn->parentWidget();
        QPoint p = cell->mapTo(ui->tab_Art->viewport(), QPoint(2,2));
        int row = ui->tab_Art->indexAt(p).row();
        if (row < 0) return;
        populateFormFromRow(row);
        setFormMode(true);
    });

    auto *cell = new QWidget;
    auto *lay  = new QHBoxLayout(cell);
    lay->setContentsMargins(2,0,2,0);
    lay->setAlignment(Qt::AlignCenter);
    lay->addWidget(editBtn);

    ui->tab_Art->setCellWidget(row, 0, cell); // col 0 = Actions
}
