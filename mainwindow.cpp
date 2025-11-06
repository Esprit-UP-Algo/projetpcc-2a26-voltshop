#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QSqlQuery>
#include "transaction.h"

#include <QHeaderView>
#include <QAbstractItemView>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QIcon>
#include <QTableWidgetItem>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>
#include <QStandardPaths>
#include <QPainter>

#include "piechartwidget.h"

bool editing = false;
int editingCode = -1;


// =====================
//      CONSTRUCTEUR
// =====================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //commandes
    ui->tableauCommande->setSelectionMode(QAbstractItemView::SingleSelection);  // Une seule sélection à la fois
    ui->tableauCommande->setSelectionBehavior(QAbstractItemView::SelectRows);   // Sélectionne toute la ligne
    ui->tableauCommande->setMouseTracking(true);                                // Active le hover
    rafraichirTableau();

    // ----- MENU -----
    connect(ui->btn_Client,      &QPushButton::clicked, this, &MainWindow::showSClient);
    connect(ui->btn_Commande,    &QPushButton::clicked, this, &MainWindow::showCommande);
    connect(ui->btn_Stock,       &QPushButton::clicked, this, &MainWindow::showStock);
    connect(ui->btn_Transaction, &QPushButton::clicked, this, &MainWindow::showTransaction);
    connect(ui->btn_Employee,    &QPushButton::clicked, this, &MainWindow::showEmployee);

    // ----- ARTICLES -----
    setupTabArt();
    refreshArticlesGrid();

    // ----- CLIENTS -----
    connect(ui->btn_Client, &QPushButton::clicked, this, [this]() {
        if (!m_clientTableInit) { setupTabClient(); m_clientTableInit = true; }
        refreshClientsGrid();
    });

    // Page d’accueil
    ui->stackedWidget->setCurrentIndex(0);

    // Wire up transaction row click to populate the transaction form for editing
    connect(ui->tableWidget_4, &QTableWidget::cellClicked, this, [this](int row, int col){
        if (row < 0) return;
        populateTransactionFormFromRow(row);
        // set editing mode: editingCode is IDT in column 0
        editing = true;
        if (ui->tableWidget_4->item(row, 0))
            editingCode = ui->tableWidget_4->item(row, 0)->text().toInt();
    });

    // Load transactions once at startup so the table reflects current DB state on launch
    afficherTransactions();

    // Connect the sort combobox to refresh the transactions table when selection changes
    if (ui->comboBoxsort) {
        connect(ui->comboBoxsort, &QComboBox::currentTextChanged, this, &MainWindow::afficherTransactionsSorted);
    }
}

MainWindow::~MainWindow(){ delete ui; }

// =====================
//     NAVIGATION
// =====================
void MainWindow::showSClient()     { ui->stackedWidget->setCurrentIndex(0); }
void MainWindow::showCommande()    { ui->stackedWidget->setCurrentIndex(1); }
void MainWindow::showStock()       { ui->stackedWidget->setCurrentIndex(2); }
void MainWindow::showTransaction() { ui->stackedWidget->setCurrentIndex(3); }
void MainWindow::showEmployee()    { ui->stackedWidget->setCurrentIndex(4); }

void MainWindow::afficherTransactions()
{
    Transaction t;
    QSqlQueryModel *model = t.afficher();

    QTableWidget *table = ui->tableWidget_4;
    table->setRowCount(0);
    // Ensure table column count matches the model and set readable headers
    int cols = model->columnCount();
    table->setColumnCount(cols);
    QStringList headers;
    for (int c = 0; c < cols; ++c) {
        QString h = model->headerData(c, Qt::Horizontal).toString();
        if (h.isEmpty()) h = QString("col%1").arg(c);
        headers << h;
    }
    table->setHorizontalHeaderLabels(headers);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Hide the internal primary key column IDT (model column 0) from the user
    if (cols > 0) table->setColumnHidden(0, true);

    for (int i = 0; i < model->rowCount(); ++i) {
        table->insertRow(i);
        for (int j = 0; j < cols; ++j) {
            QString cell = model->data(model->index(i, j)).toString();
            // If this is the DATE_TRANS column (model index 4), format it as dd/MM/yyyy for display
            if (j == 4 && !cell.isEmpty()) {
                QDate d = QDate::fromString(cell, "dd/MM/yyyy");
                if (!d.isValid()) d = QDate::fromString(cell, Qt::ISODate);
                if (!d.isValid()) d = QDate::fromString(cell, "yyyy-MM-dd");
                if (d.isValid()) cell = d.toString("dd/MM/yyyy");
            }
            table->setItem(i, j, new QTableWidgetItem(cell));
        }
    }

    // Update the status pie chart whenever the transactions table is refreshed
    populateStatusChart();
}

void MainWindow::on_pushButton_27_clicked()
{
    QTableWidget *table = ui->tableWidget_4;
    if (!table || table->rowCount() == 0) {
        QMessageBox::information(this, "Export", "No data to export.");
        return;
    }

    QString filter = "CSV files (*.csv);;All files (*.*)";
    QString defaultName = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/transactions.csv";
    QString fileName = QFileDialog::getSaveFileName(this, "Export to CSV", defaultName, filter);
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Export", "Cannot open file for writing.");
        return;
    }

    QTextStream out(&file);

    // Write headers (skip hidden columns)
    QStringList headers;
    for (int c = 0; c < table->columnCount(); ++c) {
        if (table->isColumnHidden(c)) continue;
        QTableWidgetItem *item = table->horizontalHeaderItem(c);
        headers << (item ? item->text() : QString("col%1").arg(c));
    }
    out << headers.join(',') << "\n";

    // Write rows
    for (int r = 0; r < table->rowCount(); ++r) {
        QStringList cols;
        for (int c = 0; c < table->columnCount(); ++c) {
            if (table->isColumnHidden(c)) continue;
            QTableWidgetItem *it = table->item(r, c);
            QString cell = it ? it->text() : QString();
            // Escape double quotes by doubling them (CSV standard)
            cell.replace(QString("\""), QString("\"\""));
            if (cell.contains(',') || cell.contains('"') || cell.contains('\n'))
                cell = '"' + cell + '"';
            cols << cell;
        }
        out << cols.join(',') << "\n";
    }

    file.close();
    QMessageBox::information(this, "Export", QString("Exported %1 rows to %2").arg(table->rowCount()).arg(fileName));
}

void MainWindow::afficherTransactionsSorted(const QString &sortBy)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString sql = "SELECT IDT, ID, AMOUNT, PAY_METHOD, DATE_TRANS, STATUS, IDCOM FROM TAB_TRANS";

    if (sortBy.compare("Amount", Qt::CaseInsensitive) == 0) {
        // AMOUNT is stored as VARCHAR2, so convert to number for correct ordering
        sql += " ORDER BY TO_NUMBER(AMOUNT)";
    } else if (sortBy.compare("Date", Qt::CaseInsensitive) == 0) {
        sql += " ORDER BY DATE_TRANS";
    }

    model->setQuery(sql);

    QTableWidget *table = ui->tableWidget_4;
    table->setRowCount(0);
    int cols = model->columnCount();
    table->setColumnCount(cols);
    QStringList headers;
    for (int c = 0; c < cols; ++c) {
        QString h = model->headerData(c, Qt::Horizontal).toString();
        if (h.isEmpty()) h = QString("col%1").arg(c);
        headers << h;
    }
    table->setHorizontalHeaderLabels(headers);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    if (cols > 0) table->setColumnHidden(0, true);

    for (int i = 0; i < model->rowCount(); ++i) {
        table->insertRow(i);
        for (int j = 0; j < cols; ++j) {
            QString cell = model->data(model->index(i, j)).toString();
            if (j == 4 && !cell.isEmpty()) {
                QDate d = QDate::fromString(cell, "dd/MM/yyyy");
                if (!d.isValid()) d = QDate::fromString(cell, Qt::ISODate);
                if (!d.isValid()) d = QDate::fromString(cell, "yyyy-MM-dd");
                if (d.isValid()) cell = d.toString("dd/MM/yyyy");
            }
            table->setItem(i, j, new QTableWidgetItem(cell));
        }
    }

    // Update the chart after sorting display
    populateStatusChart();
}


void MainWindow::populateStatusChart()
{
    // Ensure UI label placeholder exists
    if (!ui || !ui->label_39) return;

    // Remove old chart view if exists
    if (statusChartViewWidget) {
        statusChartViewWidget->setParent(nullptr);
        statusChartViewWidget->deleteLater();
        statusChartViewWidget = nullptr;
    }

    // Query DB for status counts
    QSqlQuery q;
    if (!q.exec("SELECT NVL(STATUS, '(null)') AS STATUS, COUNT(*) AS CNT FROM TAB_TRANS GROUP BY STATUS")) {
        qDebug() << "populateStatusChart query failed:" << q.lastError().text();
    }
    QMap<QString,int> counts;
    bool hasData = false;
    while (q.next()) {
        QString status = q.value(0).toString();
        int cnt = q.value(1).toInt();
        if (cnt > 0) { counts[status] = cnt; hasData = true; }
    }

    if (!hasData) {
        counts.clear();
        counts.insert("No Data", 1);
    }

    // Create PieChartWidget and set data
    PieChartWidget *chartWidget = new PieChartWidget();
    chartWidget->setTitle("Payment Status Distribution");
    chartWidget->setData(counts);

    QWidget *parent = ui->label_39->parentWidget();
    chartWidget->setParent(parent);
    chartWidget->setGeometry(ui->label_39->geometry());
    chartWidget->show();

    statusChartViewWidget = chartWidget;
    ui->label_39->hide();
}

// ===================================================
//                    ARTICLES
// ===================================================

void MainWindow::setupTabArt()
{
    ui->tab_Art->setColumnCount(10);
    QStringList headers{
        "", "SKU", "Name", "Category", "Brand",
        "Purchase Price", "Selling Price", "Stock", "Location", "Compatibility"
    };
    ui->tab_Art->setHorizontalHeaderLabels(headers);

    ui->tab_Art->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tab_Art->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tab_Art->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tab_Art->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tab_Art->setColumnWidth(0, 56);

    connect(ui->tab_Art, &QTableWidget::cellClicked, this, [this](int row, int col){
        if (row < 0 || col == 0) return;
        populateFormFromRow(row);
        setFormMode(true);
    });
}

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

void MainWindow::refreshArticlesGrid()
{
    m_loading = true;
    ui->tab_Art->setRowCount(0);

    const auto rows = article_dao::fetchAll();
    for (int i = 0; i < rows.size(); ++i) {
        const auto &a = rows[i];
        ui->tab_Art->insertRow(i);
        ui->tab_Art->setItem(i,1, new QTableWidgetItem(QString::number(a.SKU)));
        ui->tab_Art->setItem(i,2, new QTableWidgetItem(a.NAME));
        ui->tab_Art->setItem(i,3, new QTableWidgetItem(a.CATEGORY));
        ui->tab_Art->setItem(i,4, new QTableWidgetItem(a.BRAND));
        ui->tab_Art->setItem(i,5, new QTableWidgetItem(QString::number(a.PURCHASEPRICE)));
        ui->tab_Art->setItem(i,6, new QTableWidgetItem(QString::number(a.SELLINGPRICE)));
        ui->tab_Art->setItem(i,7, new QTableWidgetItem(QString::number(a.STOCK)));
        ui->tab_Art->setItem(i,8, new QTableWidgetItem(a.LOCATION));
        ui->tab_Art->setItem(i,9, new QTableWidgetItem(a.COMPATIBILITY));
        addActionButtonsForRow(i); // Stylo
    }

    m_loading = false;
}

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

void MainWindow::on_confirm_clicked()
{
    if (ui->sku->text().trimmed().isEmpty()) {
        QMessageBox::warning(this,"Validation","SKU est obligatoire.");
        ui->sku->setFocus();
        return;
    }

    Article a = readFormArticle();

    if (!m_isEditMode) {
        if (article_dao::exists(a.SKU)) {
            QMessageBox::warning(this,"Doublon","Ce SKU existe déjà.");
            return;
        }
        if (!article_dao::create(a)) {
            QMessageBox::critical(this,"Erreur","Insertion échouée.");
            return;
        }
        QMessageBox::information(this,"Succès","Article ajouté.");
    } else {
        if (!article_dao::update(a)) {
            QMessageBox::critical(this,"Erreur","Mise à jour échouée.");
            return;
        }
        QMessageBox::information(this,"Succès","Article mis à jour.");
    }
    refreshArticlesGrid();
    setFormMode(false);
}

void MainWindow::on_delete_2_clicked()
{
    const auto sel = ui->tab_Art->selectionModel()->selectedRows();
    if (sel.isEmpty()) {
        QMessageBox::information(this,"Suppression","Sélectionne une ligne.");
        return;
    }
    const int row = sel.first().row();
    bool ok=false; const int sku = ui->tab_Art->item(row,1)->text().toInt(&ok);
    if (!ok) return;

    if (QMessageBox::question(this,"Confirmer",
                              QString("Supprimer l'article SKU %1 ?").arg(sku)) != QMessageBox::Yes) return;

    if (article_dao::remove(sku))
        refreshArticlesGrid();
}

void MainWindow::on_DEL_clicked()
{
    QString skuText = ui->Line_rech->text().trimmed();
    if (skuText.isEmpty()) return;
    bool ok=false; int sku = skuText.toInt(&ok);
    if (!ok) return;

    if (QMessageBox::question(this,"Confirmer",
                              QString("Supprimer l'article SKU %1 ?").arg(sku)) != QMessageBox::Yes) return;

    if (article_dao::remove(sku)) refreshArticlesGrid();
    ui->Line_rech->clear();
}

void MainWindow::setFormMode(bool edit)
{
    m_isEditMode = edit;
    if (edit) {
        ui->confirm->setText("Update");
        ui->sku->setEnabled(false);
    } else {
        ui->confirm->setText("Confirm");
        ui->sku->setEnabled(true);
        ui->sku->clear(); ui->name->clear(); ui->cat->clear(); ui->brand->setCurrentIndex(0);
        ui->price1->clear(); ui->price2->clear(); ui->stock->clear();
        ui->loca->clear(); ui->com->clear();
    }
}

void MainWindow::populateFormFromRow(int row)
{
    if (row < 0) return;
    ui->sku->setText(ui->tab_Art->item(row,1)->text());
    ui->name->setText(ui->tab_Art->item(row,2)->text());
    ui->cat->setText(ui->tab_Art->item(row,3)->text());
    ui->brand->setCurrentText(ui->tab_Art->item(row,4)->text());
    ui->price1->setText(ui->tab_Art->item(row,5)->text());
    ui->price2->setText(ui->tab_Art->item(row,6)->text());
    ui->stock->setText(ui->tab_Art->item(row,7)->text());
    ui->loca->setText(ui->tab_Art->item(row,8)->text());
    ui->com->setText(ui->tab_Art->item(row,9)->text());
}

void MainWindow::populateTransactionFormFromRow(int row)
{
    if (row < 0) return;
    // Model columns: IDT, ID (refId), AMOUNT, PAY_METHOD, DATE_TRANS, STATUS, IDCOM
    QTableWidget *table = ui->tableWidget_4;
    if (table->item(row,1)) ui->P_id->setText(table->item(row,1)->text());
    if (table->item(row,2)) ui->lineEdit_16->setText(table->item(row,2)->text());
    if (table->item(row,3)) ui->comboBox_3->setCurrentText(table->item(row,3)->text());
    if (table->item(row,4)) {
        QString d = table->item(row,4)->text();
        QDate date = QDate::fromString(d, "yyyy-MM-dd");
        if (!date.isValid()) date = QDate::fromString(d, Qt::ISODate);
        if (date.isValid()) ui->dateEdit->setDate(date);
    }
    if (table->item(row,5)) ui->comboBox_4->setCurrentText(table->item(row,5)->text());
}

void MainWindow::clearTransactionFields()
{
    ui->P_id->clear();
    ui->lineEdit_16->clear();
    ui->comboBox_3->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->comboBox_4->setCurrentIndex(0);
}


void MainWindow::addActionButtonsForRow(int row)
{
    auto *editBtn = new QPushButton;
    editBtn->setToolTip("Edit");
    editBtn->setFlat(true);
    editBtn->setCursor(Qt::PointingHandCursor);
    const char* kPenPath = ":/image/ressource/edit.png";
    if (QFile::exists(kPenPath)) editBtn->setIcon(QIcon(kPenPath));
    else editBtn->setText("✎");
    editBtn->setIconSize(QSize(18,18));
    editBtn->setStyleSheet("QPushButton{border:none;}");
    editBtn->setFixedSize(26,26);

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
    ui->tab_Art->setCellWidget(row, 0, cell);
}

// ===================================================
//                     CLIENTS
// ===================================================

void MainWindow::setupTabClient()
{
    ui->tab_Client->setColumnCount(7);
    QStringList headers{ "", "CIN", "First name", "Last name", "Email", "Phone", "Adress" };
    ui->tab_Client->setHorizontalHeaderLabels(headers);

    ui->tab_Client->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tab_Client->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tab_Client->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tab_Client->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tab_Client->setColumnWidth(0, 56);

    connect(ui->tab_Client, &QTableWidget::cellClicked, this, [this](int row, int col){
        if (row < 0 || col == 0) return;
        populateClientFormFromRow(row);
        setClientFormMode(true);
    });
}

void MainWindow::refreshClientsGrid()
{
    ui->tab_Client->setRowCount(0);
    const auto rows = client_dao::fetchAll();
    for (int i = 0; i < rows.size(); ++i) {
        const auto &c = rows[i];
        ui->tab_Client->insertRow(i);
        ui->tab_Client->setItem(i,1, new QTableWidgetItem(c.CIN));
        ui->tab_Client->setItem(i,2, new QTableWidgetItem(c.FIRST_NAME));
        ui->tab_Client->setItem(i,3, new QTableWidgetItem(c.LAST_NAME));
        ui->tab_Client->setItem(i,4, new QTableWidgetItem(c.EMAIL));
        ui->tab_Client->setItem(i,5, new QTableWidgetItem(c.PHONE_NBR));
        ui->tab_Client->setItem(i,6, new QTableWidgetItem(c.ADRESS));
        addClientEditPenForRow(i);
    }
}

Client MainWindow::readClientForm() const
{
    Client c;
    c.CIN        = ui->c_cin->text().trimmed();
    c.FIRST_NAME = ui->c_fname->text().trimmed();
    c.LAST_NAME  = ui->c_lname->text().trimmed();
    c.EMAIL      = ui->c_email->text().trimmed();
    c.PHONE_NBR  = ui->c_phone->text().trimmed();
    c.ADRESS     = ui->c_adress->text().trimmed();
    return c;
}

void MainWindow::setClientFormMode(bool edit)
{
    m_clientEditMode = edit;
    if (edit) {
        ui->c_confirm->setText("Update");
        ui->c_cin->setEnabled(false);
    } else {
        ui->c_confirm->setText("Confirm");
        ui->c_cin->setEnabled(true);
        ui->c_cin->clear(); ui->c_fname->clear(); ui->c_lname->clear();
        ui->c_email->clear(); ui->c_phone->clear(); ui->c_adress->clear();
    }
}

void MainWindow::populateClientFormFromRow(int row)
{
    if (row < 0) return;
    ui->c_cin->setText(ui->tab_Client->item(row,1)->text());
    ui->c_fname->setText(ui->tab_Client->item(row,2)->text());
    ui->c_lname->setText(ui->tab_Client->item(row,3)->text());
    ui->c_email->setText(ui->tab_Client->item(row,4)->text());
    ui->c_phone->setText(ui->tab_Client->item(row,5)->text());
    ui->c_adress->setText(ui->tab_Client->item(row,6)->text());
}

void MainWindow::addClientEditPenForRow(int row)
{
    auto *editBtn = new QPushButton;
    editBtn->setToolTip("Edit");
    editBtn->setFlat(true);
    editBtn->setCursor(Qt::PointingHandCursor);
    const char* kPenPath = ":/image/ressource/edit.png";
    if (QFile::exists(kPenPath)) editBtn->setIcon(QIcon(kPenPath));
    else editBtn->setText("✎");
    editBtn->setIconSize(QSize(18,18));
    editBtn->setStyleSheet("QPushButton{border:none;}");
    editBtn->setFixedSize(26,26);

    connect(editBtn, &QPushButton::clicked, this, [this, editBtn](){
        QWidget *cell = editBtn->parentWidget();
        QPoint p = cell->mapTo(ui->tab_Client->viewport(), QPoint(2,2));
        int row = ui->tab_Client->indexAt(p).row();
        if (row < 0) return;
        populateClientFormFromRow(row);
        setClientFormMode(true);
    });

    auto *cell = new QWidget;
    auto *lay  = new QHBoxLayout(cell);
    lay->setContentsMargins(2,0,2,0);
    lay->setAlignment(Qt::AlignCenter);
    lay->addWidget(editBtn);
    ui->tab_Client->setCellWidget(row, 0, cell);
}

void MainWindow::on_c_confirm_clicked()
{
    if (ui->c_cin->text().trimmed().isEmpty()) {
        QMessageBox::warning(this,"Validation","CIN est obligatoire.");
        return;
    }
    Client c = readClientForm();

    if (!m_clientEditMode) {
        if (client_dao::exists(c.CIN)) {
            QMessageBox::warning(this,"Doublon","CIN existe déjà.");
            return;
        }
        if (!client_dao::create(c)) {
            QMessageBox::critical(this,"Erreur","Ajout échoué.");
            return;
        }
        QMessageBox::information(this,"Succès","Client ajouté.");
    } else {
        if (!client_dao::update(c)) {
            QMessageBox::critical(this,"Erreur","Mise à jour échouée.");
            return;
        }
        QMessageBox::information(this,"Succès","Client mis à jour.");
    }
    refreshClientsGrid();
    setClientFormMode(false);
}

void MainWindow::on_c_delete_clicked()
{
    const auto sel = ui->tab_Client->selectionModel()->selectedRows();
    if (sel.isEmpty()) return;
    const int row = sel.first().row();
    const QString cin = ui->tab_Client->item(row,1)->text();
    if (QMessageBox::question(this,"Confirmer",
                              QString("Supprimer le client %1 ?").arg(cin)) != QMessageBox::Yes) return;
    if (client_dao::remove(cin)) refreshClientsGrid();
}

void MainWindow::on_c_DEL_clicked()
{
    QString cin = ui->c_Line_rech->text().trimmed();
    if (cin.isEmpty()) return;
    if (QMessageBox::question(this,"Confirmer",
                              QString("Supprimer le client %1 ?").arg(cin)) != QMessageBox::Yes) return;
    if (client_dao::remove(cin)) refreshClientsGrid();
    ui->c_Line_rech->clear();
}
void MainWindow::on_tab_Art_cellChanged(int, int) { }

// ===================================================
//                    COMMANDES
// ===================================================
void MainWindow::rafraichirTableau()
{
    ui->tableauCommande->clear();
    ui->tableauCommande->setRowCount(0);
    ui->tableauCommande->setColumnCount(6);
    QStringList headers = {"Code", "Client", "Date", "Produits", "Total", "Statut"};
    ui->tableauCommande->setHorizontalHeaderLabels(headers);

    Commande c;
    QSqlQueryModel *model = c.afficher();

    for (int i = 0; i < model->rowCount(); ++i) {
        ui->tableauCommande->insertRow(i);
        for (int j = 0; j < model->columnCount(); ++j) {
            ui->tableauCommande->setItem(i, j, new QTableWidgetItem(model->data(model->index(i, j)).toString()));
        }
    }
}




void MainWindow::on_pushButton_ajouter_clicked()
{
    QString client = ui->lineEdit_client->text();
    QString produits = ui->lineEdit_products->text();
    QString statut = ui->lineEdit_status->text();
    QDate date = ui->dateEdit_date->date();
    double total = ui->lineEdit_total->text().toDouble();

    // Si on est en mode édition, on garde le code existant
    int code = editing ? editingCode : ui->lineEdit_code->text().toInt();

    Commande c(code, client, date, produits, total, statut);

    if (editing) {
        // 🔁 Mettre à jour la commande existante
        if (c.modifier()) {
            QMessageBox::information(this, "Succès", "Commande mise à jour !");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la mise à jour !");
        }

        editing = false;
        editingCode = -1;
        ui->pushButton_ajouter->setText("Confirm"); // on remet le texte normal

    } else {
        // ➕ Ajouter une nouvelle commande
        if (c.ajouter()) {
            QMessageBox::information(this, "Succès", "Commande ajoutée !");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de l'ajout !");
        }
    }

    // 🧹 Réinitialiser les champs et rafraîchir le tableau
    clearFields();
    afficherCommandes();
}


void MainWindow::on_pushButton_25_clicked()
{
    // Add Payment
    int id = ui->P_id->text().toInt();
    QString amount = ui->lineEdit_16->text().trimmed();
    QString pay_method = ui->comboBox_3->currentText();
    QDate date = ui->dateEdit->date();
    QString status = ui->comboBox_4->currentText();

    // For testing, do not include IDCOM (pass 0 to omit linking to a command)
    // refId is taken from the P_id field and maps to TAB_TRANS.ID (required non-null column)
    int refId = ui->P_id->text().toInt();
    // If we are editing an existing transaction, call modifier(); otherwise ajouter()
    int idToUse = editing ? editingCode : 0;
    Transaction t(idToUse, amount, pay_method, date, status, 0, refId);
    if (editing) {
        if (t.modifier()) {
            QMessageBox::information(this, "Succès", "Transaction mise à jour !");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la mise à jour de la transaction !");
        }
        // exit editing mode
        editing = false;
        editingCode = -1;
    } else {
        if (t.ajouter()) {
            QMessageBox::information(this, "Succès", "Transaction ajoutée !");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de l'ajout de la transaction !");
        }
    }
    // Refresh UI and clear form
    clearTransactionFields();
    afficherTransactions();
}

void MainWindow::on_pushButton_28_clicked()
{
    // Delete Payment by id from lineEdit_18
    bool ok = false;
    int id = ui->lineEdit_18->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide pour la suppression.");
        return;
    }
    Transaction t;
    if (t.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Transaction supprimée !");
        afficherTransactions();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression de la transaction.");
    }
}


void MainWindow::on_pushButton_supprimer_clicked()
{
    // Vérifier si une ligne est sélectionnée dans le tableau
    QList<QTableWidgetItem*> selectedItems = ui->tableauCommande->selectedItems();

    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner une commande dans le tableau !");
        return;
    }

    // Récupérer le code de la ligne sélectionnée (première colonne)
    int row = selectedItems.first()->row();
    int code = ui->tableauCommande->item(row, 0)->text().toInt();
    QString client = ui->tableauCommande->item(row, 1)->text();

    // Demander confirmation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer la commande :\n"
                                  "Code: #" + QString::number(code) + "\n" +
                                      "Client: " + client + " ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Commande c;
        if (c.supprimer(code)) {
            QMessageBox::information(this, "Succès", "Commande #" + QString::number(code) + " supprimée avec succès !");
            rafraichirTableau();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression de la commande #" + QString::number(code));
        }
    }
}




void MainWindow::on_tableauCommande_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;

    selectedRow = index.row();  // On mémorise juste la ligne cliquée
    qDebug() << "Ligne sélectionnée :" << selectedRow;
}



void MainWindow::on_pushButton_edit_clicked()
{
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une commande à éditer.");
        return;
    }

    auto getItemText = [&](int col) -> QString {
        QTableWidgetItem *item = ui->tableauCommande->item(selectedRow, col);
        return item ? item->text() : "";
    };

    // 🔹 Remplir les champs avec les valeurs de la ligne sélectionnée
    ui->lineEdit_code->setText(getItemText(0));
    ui->lineEdit_client->setText(getItemText(1));
    ui->dateEdit_date->setDate(QDate::fromString(getItemText(2), "yyyy-MM-dd"));
    ui->lineEdit_products->setText(getItemText(3));
    ui->lineEdit_total->setText(getItemText(4));
    ui->lineEdit_status->setText(getItemText(5));

    // 🔹 Activer le mode édition
    editing = true;
    editingCode = getItemText(0).toInt();

    // 🔹 (Optionnel) Changer le texte du bouton pour indiquer l’action
    ui->pushButton_ajouter->setText("Save");
}


void MainWindow::clearFields()
{
    ui->lineEdit_code->clear();
    ui->lineEdit_client->clear();
    ui->lineEdit_products->clear();
    ui->lineEdit_total->clear();
    ui->lineEdit_status->clear();
    ui->dateEdit_date->setDate(QDate::currentDate());
}
void MainWindow::afficherCommandes()
{
    Commande c;
    QSqlQueryModel *model = c.afficher();

    ui->tableauCommande->setRowCount(model->rowCount());
    ui->tableauCommande->setColumnCount(model->columnCount());

    for (int i = 0; i < model->rowCount(); ++i) {
        for (int j = 0; j < model->columnCount(); ++j) {
            QString data = model->data(model->index(i, j)).toString();
            ui->tableauCommande->setItem(i, j, new QTableWidgetItem(data));
        }
    }

    // Optionnel : mettre les titres de colonnes
    QStringList headers;
    headers << "Code" << "Produit" << "Quantité" << "Prix";
    ui->tableauCommande->setHorizontalHeaderLabels(headers);
}

void MainWindow::on_pushButton_cancel_clicked()
{
    clearFields();
    editing = false;
    editingCode = -1;
    qDebug() << "Édition annulée et champs réinitialisés.";
}
