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
#include "gestion_employee.h"
#include "piechartwidget.h"
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>

#include <QDesktopServices>
#include <QUrl>
#include <QImage>


bool editing = false;
int editingCode = -1;
#include <random>
// ✅ Generates a random 8-digit employee ID (IDE)
QString generateRandomIDE()
{
    static std::mt19937 rng(std::random_device{}()); // Random engine
    std::uniform_int_distribution<int> dist(10000000, 99999999); // Range 8 digits
    return QString::number(dist(rng));
}


// =====================
//      CONSTRUCTEUR
// =====================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_31, &QPushButton::clicked, this, &MainWindow::on_pushButton_31_clicked);
    connect(ui->lineEdit_19, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_19_textChanged);
    connect(ui->tab_Employee, &QTableWidget::cellClicked,
            this, &MainWindow::on_tab_Employee_cellClicked);
    refreshEmployeeTable();
    //commandes

    ui->tableauCommande->setSelectionMode(QAbstractItemView::SingleSelection);  // Une seule sélection à la fois
    ui->tableauCommande->setSelectionBehavior(QAbstractItemView::SelectRows);   // Sélectionne toute la ligne
    ui->tableauCommande->setMouseTracking(true);                                // Active le hover
    rafraichirTableau();
    chargerClientsFichier();  // 🔹 Charge la map depuis clients.json
    chargerClientsComboBox(); // 🔹 Remplit la comboBox avec les clients existants
    afficherCommandes();      // 🔹 Affiche les commandes avec la colonne client
    mettreAJourComboBoxClients();



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
// ===================================================
//                    EMPLOYEES
// ===================================================

void MainWindow::populateEmployeeFormFromRow(int row)
{
    if (row < 0) return;

    ui->e_cin->setText(ui->tab_Employee->item(row, 0)->text());       // CIN
    ui->e_fullname->setText(ui->tab_Employee->item(row, 1)->text());    // Full Name
    ui->e_cin->setEnabled(false);  // 🔒 Lock CIN field during edit mode
    ui->e_position->setCurrentText(ui->tab_Employee->item(row, 2)->text());// Position
    ui->e_address->setText(ui->tab_Employee->item(row, 3)->text());   // Address
    ui->e_salary->setText(ui->tab_Employee->item(row, 4)->text());    // Salary
    ui->e_status->setText(ui->tab_Employee->item(row, 5)->text());    // Status
}

Employee MainWindow::readEmployeeForm() const
{
    Employee e;
    e.cin = ui->e_cin->text().trimmed().toStdString();
    e.fullName = ui->e_fullname->text().trimmed().toStdString();
    e.position = ui->e_position->currentText().trimmed().toStdString();
    e.address = ui->e_address->text().trimmed().toStdString();
    e.salary = ui->e_salary->text().trimmed().toStdString(); // ✅ keep as string
    e.status = ui->e_status->text().trimmed().toStdString();
    return e;
}

void MainWindow::clearEmployeeForm()
{
    ui->e_cin->clear();
    ui->e_fullname->clear();
    ui->e_address->clear();
    ui->e_salary->clear();
    ui->e_position->setCurrentIndex(-1); // ✅ This one is a QComboBox
    ui->e_status->clear();               // ✅ QLineEdit, so use clear()

    ui->e_cin->setEnabled(true);
    ui->e_fullname->setEnabled(true);
    ui->e_position->setEnabled(true);
    ui->e_address->setEnabled(true);
    ui->e_salary->setEnabled(true);
    ui->e_status->setEnabled(true);

    m_employeeEditMode = false;
    m_editingCin.clear();
}

void MainWindow::refreshEmployeeTable()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database connection is not open!");
        return;
    }

    ui->tab_Employee->setColumnCount(6);
    ui->tab_Employee->setHorizontalHeaderLabels(
        {"CIN", "Full Name", "Position", "Address", "Salary", "Status"}
        );

    ui->tab_Employee->clearContents();
    ui->tab_Employee->setRowCount(0);

    QSqlQuery query(db);
    if (!query.exec("SELECT cin, fullname, position, adress, salary, status FROM employees")) {
        QMessageBox::critical(this, "Database Error",
                              "Failed to fetch employees:\n" + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tab_Employee->insertRow(row);
        ui->tab_Employee->setItem(row, 0, new QTableWidgetItem(query.value("cin").toString()));
        ui->tab_Employee->setItem(row, 1, new QTableWidgetItem(query.value("fullname").toString()));
        ui->tab_Employee->setItem(row, 2, new QTableWidgetItem(query.value("position").toString()));
        ui->tab_Employee->setItem(row, 3, new QTableWidgetItem(query.value("adress").toString()));
        ui->tab_Employee->setItem(row, 4, new QTableWidgetItem(query.value("salary").toString()));
        ui->tab_Employee->setItem(row, 5, new QTableWidgetItem(query.value("status").toString()));
        row++;
    }

    ui->tab_Employee->resizeColumnsToContents();

    if (ui->tab_Employee->rowCount() > 0)
        ui->tab_Employee->selectRow(0);
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
    mettreAJourComboBoxClients(); // ✅ mettre à jour la combo du tab commande
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
    mettreAJourComboBoxClients(); //  mettre à jour la combo du tab client
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
    mettreAJourComboBoxClients(); // ✅ mettre à jour la combo du tab commande
}

void MainWindow::on_c_DEL_clicked()
{
    QString cin = ui->c_Line_rech->text().trimmed();
    if (cin.isEmpty()) return;
    if (QMessageBox::question(this,"Confirmer",
                              QString("Supprimer le client %1 ?").arg(cin)) != QMessageBox::Yes) return;
    if (client_dao::remove(cin)) refreshClientsGrid();
    ui->c_Line_rech->clear();
    mettreAJourComboBoxClients(); // ✅ mettre à jour la combo
}
void MainWindow::on_tab_Art_cellChanged(int, int) { }




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


void MainWindow::on_confirmb_clicked()
{
    QString cin      = ui->e_cin->text().trimmed();
    QString fullName = ui->e_fullname->text().trimmed();
    QString position = ui->e_position->currentText().trimmed();
    QString address  = ui->e_address->text().trimmed();
    QString salary   = ui->e_salary->text().trimmed(); // Keep as string
    QString status   = ui->e_status->text().trimmed();

    // ==========================
    // ✅ VALIDATION SECTION
    // ==========================
    QRegularExpression cinRegex("^[0-9]{8}$");
    if (!cinRegex.match(cin).hasMatch()) {
        QMessageBox::warning(this, "Invalid CIN", "❌ CIN must contain exactly 8 digits.");
        return;
    }

    QRegularExpression nameRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    if (!nameRegex.match(fullName).hasMatch() || fullName.length() < 3) {
        QMessageBox::warning(this, "Invalid Name", "❌ Full name must contain only letters and spaces (min 3 characters).");
        return;
    }

    QRegularExpression positionRegex("^[A-Za-z\\s]+$");
    if (!positionRegex.match(position).hasMatch() || position.isEmpty()) {
        QMessageBox::warning(this, "Invalid Position", "❌ Position must contain only letters.");
        return;
    }

    if (address.length() < 5) {
        QMessageBox::warning(this, "Invalid Address", "❌ Address must contain at least 5 characters.");
        return;
    }

    QRegularExpression salaryRegex("^[0-9]+(\\.[0-9]{1,2})?$");
    if (!salaryRegex.match(salary).hasMatch() || salary.toDouble() <= 0) {
        QMessageBox::warning(this, "Invalid Salary", "❌ Salary must be a positive number.");
        return;
    }

    QStringList validStatuses = {"Active", "Inactive", "On Probation", "Resigned", "Terminated"};
    if (!validStatuses.contains(status)) {
        QMessageBox::warning(this, "Invalid Status",
                             "❌ Status must be one of:\nActive, Inactive, On Probation, Resigned, Terminated.");
        return;
    }

    // ==========================
    // ✅ DUPLICATE CIN CHECK
    // ==========================
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM employees WHERE cin = :cin");
    checkQuery.bindValue(":cin", cin);
    checkQuery.exec();
    checkQuery.next();
    int count = checkQuery.value(0).toInt();

    if (!m_employeeEditMode && count > 0) {
        QMessageBox::warning(this, "Duplicate CIN", "❌ An employee with this CIN already exists.");
        return;
    }

    QSqlQuery query;

    // ==============================
    // EDIT MODE
    // ==============================
    if (m_employeeEditMode) {
        query.prepare(R"(
            UPDATE employees
            SET cin = :newcin,
                fullname = :fullname,
                position = :position,
                adress = :address,
                salary = :salary,
                status = :status
            WHERE cin = :oldcin
        )");

        query.bindValue(":newcin", cin);
        query.bindValue(":fullname", fullName);
        query.bindValue(":position", position);
        query.bindValue(":address", address);
        query.bindValue(":salary", salary);
        query.bindValue(":status", status);
        query.bindValue(":oldcin", m_editingCin);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "✅ Employee updated successfully!");
        } else {
            QMessageBox::critical(this, "Database Error", "❌ Failed to update employee:\n" + query.lastError().text());
            return;
        }

        m_employeeEditMode = false;
        m_editingCin.clear();
        ui->e_cin->setEnabled(true);
    }

    // ==============================
    // ADD MODE
    // ==============================
    else {
        QString ide = generateRandomIDE(); // ✅ NEW random 8-digit ID

        query.prepare(R"(
            INSERT INTO employees (ide, cin, fullname, position, adress, salary, status)
            VALUES (:ide, :cin, :fullname, :position, :address, :salary, :status)
        )");

        query.bindValue(":ide", ide); // ✅ NEW binding
        query.bindValue(":cin", cin);
        query.bindValue(":fullname", fullName);
        query.bindValue(":position", position);
        query.bindValue(":address", address);
        query.bindValue(":salary", salary);
        query.bindValue(":status", status);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "✅ Employee added successfully!\nID: " + ide);
        } else {
            QMessageBox::critical(this, "Database Error", "❌ Failed to add employee:\n" + query.lastError().text());
            return;
        }
    }

    // ✅ Refresh and clear
    refreshEmployeeTable();
    clearEmployeeForm();
}



void MainWindow::on_pushButton_31_clicked()
{
    QString cin = ui->lineEdit_20->text().trimmed();

    // Check if CIN field is empty
    if (cin.isEmpty()) {
        QMessageBox::warning(this, "Missing CIN", "⚠️ Please enter a CIN to delete.");
        return;
    }

    // ✅ Check if employee with that CIN exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM employees WHERE cin = :cin");
    checkQuery.bindValue(":cin", cin);

    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Database Error", "❌ Failed to check employee existence:\n" + checkQuery.lastError().text());
        return;
    }

    checkQuery.next();
    int count = checkQuery.value(0).toInt();

    if (count == 0) {
        QMessageBox::information(this, "Not Found", "⚠️ No employee found with CIN: " + cin);
        return;
    }

    // ✅ Confirm deletion
    if (QMessageBox::question(this, "Confirm",
                              QString("Are you sure you want to delete employee with CIN %1?").arg(cin),
                              QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    // ✅ Perform deletion
    QSqlQuery q;
    q.prepare("DELETE FROM employees WHERE cin = :cin");
    q.bindValue(":cin", cin);

    if (q.exec()) {
        QMessageBox::information(this, "Success", "✅ Employee deleted successfully!");
        refreshEmployeeTable();
        ui->lineEdit_20->clear();
    } else {
        QMessageBox::critical(this, "Error", "❌ Failed to delete employee:\n" + q.lastError().text());
    }
}

void MainWindow::on_lineEdit_19_textChanged(const QString &arg1)
{
    QString cin = arg1.trimmed();
    if (cin.isEmpty()) {
        refreshEmployeeTable(); // Show all if empty
        return;
    }
    QSqlQuery q;
    q.prepare("SELECT cin, fullname, position, adress, salary, status FROM employees WHERE cin LIKE :cin");
    q.bindValue(":cin", cin + "%");
    if (!q.exec()) {
        QMessageBox::critical(this, "Error", q.lastError().text());
        return;
    }
    ui->tab_Employee->clear();
    ui->tab_Employee->setColumnCount(6);
    ui->tab_Employee->setHorizontalHeaderLabels({"CIN", "Full Name", "Position", "Address", "Salary", "Status"});
    ui->tab_Employee->setRowCount(0);
    int row = 0;
    while (q.next()) {
        ui->tab_Employee->insertRow(row);
        ui->tab_Employee->setItem(row, 0, new QTableWidgetItem(q.value("cin").toString()));
        ui->tab_Employee->setItem(row, 1, new QTableWidgetItem(q.value("fullname").toString()));
        ui->tab_Employee->setItem(row, 2, new QTableWidgetItem(q.value("position").toString()));
        ui->tab_Employee->setItem(row, 3, new QTableWidgetItem(q.value("adress").toString()));
        ui->tab_Employee->setItem(row, 4, new QTableWidgetItem(q.value("salary").toString()));
        ui->tab_Employee->setItem(row, 5, new QTableWidgetItem(q.value("status").toString()));
        row++;
    }
    ui->tab_Employee->resizeColumnsToContents();
}
void MainWindow::on_tab_Employee_cellClicked(int row, int column)
{
    if (row < 0) return;

    // ✅ Populate all fields
    populateEmployeeFormFromRow(row);

    // ✅ Enable all fields except CIN (primary key)
    ui->e_cin->setEnabled(false);
    ui->e_fullname->setEnabled(true);
    ui->e_position->setEnabled(true);
    ui->e_address->setEnabled(true);
    ui->e_salary->setEnabled(true);
    ui->e_status->setEnabled(true);

    // ✅ Refresh combo box UI (prevents Qt visual freeze)
    ui->e_position->update();

    // ✅ Set editing mode state
    m_employeeEditMode = true;
    m_editingCin = ui->tab_Employee->item(row, 0)->text();
}


    // ===================================================
    //                    COMMANDES
    // ===================================================
void MainWindow::rafraichirTableau()
{
    ui->tableauCommande->clear();
    ui->tableauCommande->setRowCount(0);
    ui->tableauCommande->setColumnCount(6);

    QStringList headers = {"Code", "Date", "Produits", "Total", "Statut", "Client"};
    ui->tableauCommande->setHorizontalHeaderLabels(headers);

    Commande c;
    QSqlQueryModel *model = c.afficher();
    if (!model) return;

    for (int i = 0; i < model->rowCount(); ++i) {
        ui->tableauCommande->insertRow(i);

        // 🔹 colonnes exactes selon ta table SQL
        QString code = model->data(model->index(i, 0)).toString();
        QString date = model->data(model->index(i, 1)).toString();
        QString produits = model->data(model->index(i, 2)).toString();
        QString total = model->data(model->index(i, 3)).toString();
        QString statut = model->data(model->index(i, 4)).toString();
        QString client = clientsMap.value(code, "—");  // récup client depuis JSON

        ui->tableauCommande->setItem(i, 0, new QTableWidgetItem(code));
        ui->tableauCommande->setItem(i, 1, new QTableWidgetItem(date));
        ui->tableauCommande->setItem(i, 2, new QTableWidgetItem(produits));
        ui->tableauCommande->setItem(i, 3, new QTableWidgetItem(total));
        ui->tableauCommande->setItem(i, 4, new QTableWidgetItem(statut));
        ui->tableauCommande->setItem(i, 5, new QTableWidgetItem(client));
    }

    ui->tableauCommande->resizeColumnsToContents();
}






void MainWindow::on_pushButton_ajouter_clicked()
{
    // Pas besoin de QString::number ici
    QString code = editing ? editingCodeC : ui->lineEdit_code->text().trimmed();
    QDate date = ui->dateEdit_date->date();
    QString produits = ui->lineEdit_products->text().trimmed();
    double total = ui->lineEdit_total->text().toDouble();
    QString statut = ui->comboBox_status->currentText().trimmed();
    QString client = ui->comboBox_client->currentText();  // Le client affiché dans Qt

    // Validation
    if (!validerChamps(code, date, produits, total, statut, client))
        return;

    // Création de la commande (sans client dans la BDD)
    Commande c(code, date, produits, total, statut);

    if (editing) {
        // 🔁 Modifier commande existante
        if (c.modifier()) {
            QMessageBox::information(this, "Succès", "Commande modifiée !");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la modification !");
        }

        editing = false;
        editingCodeC = "";
        ui->pushButton_ajouter->setText("Confirmer");
    } else {
        // ➕ Ajouter nouvelle commande
        if (c.ajouter()) {
            QMessageBox::information(this, "Succès", "Commande ajoutée !");

            // ✅ Ajouter la commande au tableau Qt sans recharger depuis SQL
            int row = ui->tableauCommande->rowCount();
            ui->tableauCommande->insertRow(row);

            ui->tableauCommande->setItem(row, 0, new QTableWidgetItem(code));
            ui->tableauCommande->setItem(row, 1, new QTableWidgetItem(date.toString("yyyy-MM-dd")));
            ui->tableauCommande->setItem(row, 2, new QTableWidgetItem(produits));
            ui->tableauCommande->setItem(row, 3, new QTableWidgetItem(QString::number(total)));
            ui->tableauCommande->setItem(row, 4, new QTableWidgetItem(statut));
            ui->tableauCommande->setItem(row, 5, new QTableWidgetItem(client)); // ✅ visible seulement dans Qt
        }
        else {
            QMessageBox::critical(this, "Erreur", "Échec de l'ajout !");
        }
    }

    ui->lineEdit_code->setReadOnly(false);
    clearFields();



    // ✅ Enregistrer dans la map et sauvegarder dans JSON
    clientsMap[code] = client;
    sauvegarderClients(code, ui->comboBox_client->currentText());


    // Puis rafraîchir le tableau
    afficherCommandes();

}



void MainWindow::on_pushButton_supprimer_clicked()
{
    // Vérifier si une ligne est sélectionnée
    QList<QTableWidgetItem*> selectedItems = ui->tableauCommande->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Please select an order from the table!");
        return;
    }

    int row = selectedItems.first()->row();

    //  Vérifie d'abord combien de colonnes il y a
    int totalCols = ui->tableauCommande->columnCount();
    qDebug() << "Colonnes dans le tableau:" << totalCols;

    // Sécuriser les indices
    QString code = ui->tableauCommande->item(row, 0) ? ui->tableauCommande->item(row, 0)->text() : "";
    QString client = (totalCols > 5 && ui->tableauCommande->item(row, 5))
                         ? ui->tableauCommande->item(row, 5)->text()
                         : "Unknown client";

    if (code.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Impossible de déterminer le code de la commande sélectionnée.");
        return;
    }

    // Demande de confirmation
    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Confirmation",
        "Do you really want to delete the order?\n\n"
        "Code: #" + code + "\nClient: " + client,
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        Commande c;
        bool ok = c.supprimer(code);

        if (ok) {
            //  Supprimer aussi le client associé de la map locale (si tu l'utilises)
            clientsMap.remove(code);
            //  Sauvegarder la map mise à jour dans le JSON
            sauvegarderClients(code, client);


            QMessageBox::information(this, "Success", "Commande #" + code + " deleted successfully!");
            chargerClientsFichier();
            rafraichirTableau();
        } else {
            QMessageBox::critical(this, "Error", "Order deletion failed for #" + code);
        }
    }

}


void MainWindow::on_tableauCommande_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;

    selectedRow = index.row();  //mémorise juste la ligne cliquée
    qDebug() << "Ligne sélectionnée :" << selectedRow;
}



void MainWindow::on_pushButton_edit_clicked()
{
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No selection", "Please select a command to edit.");
        return;
    }

    auto getItemText = [&](int col) -> QString {
        QTableWidgetItem *item = ui->tableauCommande->item(selectedRow, col);
        return item ? item->text() : "";
    };

    //  Remplir les champs avec les valeurs de la ligne sélectionnée
    ui->lineEdit_code->setText(getItemText(0));
    ui->dateEdit_date->setDate(QDate::fromString(getItemText(1), "yyyy-MM-dd"));
    ui->lineEdit_products->setText(getItemText(2));
    ui->lineEdit_total->setText(getItemText(3));
    ui->comboBox_status->setCurrentText(getItemText(4));
    ui->comboBox_client->setCurrentText(getItemText(5));

    //  Rendre le code non modifiable
    ui->lineEdit_code->setReadOnly(true);

    //  Activer le mode édition
    editing = true;
    editingCodeC = getItemText(0);


    // (Optionnel) Changer le texte du bouton pour indiquer l’action
    ui->pushButton_ajouter->setText("Save");
    QString code = ui->lineEdit_code->text();
    sauvegarderClients(code, ui->comboBox_client->currentText());
}


void MainWindow::clearFields()
{
    ui->lineEdit_code->clear();
    ui->comboBox_status->setCurrentIndex(-1);
    ui->lineEdit_products->clear();
    ui->lineEdit_total->clear();
    ui->comboBox_status->setCurrentIndex(-1); // ou 0 si tu veux un statut par défaut
    ui->dateEdit_date->setDate(QDate::currentDate());
}
void MainWindow::afficherCommandes()
{
    Commande c;
    QSqlQueryModel *model = c.afficher();

    if (!model) return;

    int colonnesBD = model->columnCount();
    int colonneClient = colonnesBD; // position de la nouvelle colonne "Client"

    ui->tableauCommande->clear();
    ui->tableauCommande->setRowCount(model->rowCount());
    ui->tableauCommande->setColumnCount(colonnesBD + 1);

    // ✅ Entêtes
    QStringList headers;
    for (int j = 0; j < colonnesBD; ++j)
        headers << model->headerData(j, Qt::Horizontal).toString();
    headers << "Client"; // ajout manuel pour la colonne manquante
    ui->tableauCommande->setHorizontalHeaderLabels(headers);

    // ✅ Remplissage du tableau
    for (int i = 0; i < model->rowCount(); ++i)
    {
        QString code = model->data(model->index(i, 0)).toString(); // code de la commande

        for (int j = 0; j < colonnesBD; ++j)
        {
            QString data = model->data(model->index(i, j)).toString();
            ui->tableauCommande->setItem(i, j, new QTableWidgetItem(data));
        }

        // 🔹 Récupération du nom du client depuis le fichier JSON
        QString client = clientsMap.value(code, "—"); // “—” si non trouvé
        ui->tableauCommande->setItem(i, colonneClient, new QTableWidgetItem(client));
    }

    ui->tableauCommande->resizeColumnsToContents();
}


void MainWindow::on_pushButton_cancel_clicked()
{
    clearFields();
    editing = false;
    editingCodeC ="";
    qDebug() << "Édition annulée et champs réinitialisés.";
}
bool MainWindow::validerChamps(QString code, QDate date, QString produits, double total, QString statut,QString client)
{
    //  Code : non vide + format (lettre)-(lettres)
    if (code.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Error", "The code cannot be empty!");
        return false;
    }

    QRegularExpression codeRegex("^[A-Za-z]-[A-Za-z]+$");
    if (!codeRegex.match(code).hasMatch()) {
        QMessageBox::warning(this, "Error", "The code must be in letter-hyphen-letter format (ex : a-fggh).");
        return false;
    }

    //  Client : non vide + uniquement lettres et espaces
    if (client.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Error", "The customer name cannot be empty !");
        return false;
    }

    QRegularExpression clientRegex("^[A-Za-zÀ-ÿ\\s]+$");
    if (!clientRegex.match(client).hasMatch()) {
        QMessageBox::warning(this, "Error", "The customer's name must contain only letters and spaces.");
        return false;
    }

    // 🔸 3. Date : entre 01/01/2000 et aujourd’hui
    QDate minDate(2000, 1, 1);
    QDate currentDate = QDate::currentDate();
    if (date < minDate || date > currentDate) {
        QMessageBox::warning(this, "Erreur", "La date doit être comprise entre 01/01/2000 et aujourd’hui !");
        return false;
    }

    // 🔸 4. Produits : non vide
    if (produits.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Error", "The products field cannot be empty!");
        return false;
    }

    // 🔸 5. Total : doit être un nombre valide et > 0
    QString totalText = ui->lineEdit_total->text().trimmed();
    bool ok;
    double totalValue = totalText.toDouble(&ok);
    if (!ok || totalText.isEmpty() || totalValue <= 0) {
        QMessageBox::warning(this, "Error", "Please enter a valid positive total amount!");
        return false;
    }


    // 🔸 6. Statut : parmi les valeurs autorisées
    QStringList statutsValides = {"pending", "in progress", "delivered", "cancelled"};
    if (!statutsValides.contains(statut.toLower())) {
        QMessageBox::warning(this, "Error", "The status must be: pending, in progress, delivered, or cancelled.");
        return false;
    }

    return true; // ✅ Tous les contrôles sont valides
}

void MainWindow::chargerClientsComboBox()
{
    ui->comboBox_client->clear();

    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "❌ Base non connectée dans chargerClientsComboBox()";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT FIRST_NAME, LAST_NAME FROM TAB_CLIENT");

    if (!query.exec()) {
        qDebug() << "❌ Erreur SQL chargerClientsComboBox:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString prenom = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString nomComplet = prenom + " " + nom;
        ui->comboBox_client->addItem(nomComplet);
    }

    if (ui->comboBox_client->count() > 0)
        ui->comboBox_client->setCurrentIndex(0);

    qDebug() << "✅ Clients chargés dans ComboBox :" << ui->comboBox_client->count();
}

void MainWindow::chargerClientsFichier()
{
    QFile file("clients.json");
    if (!file.exists()) return;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) return;

    QJsonObject obj = doc.object();
    clientsMap.clear();
    for (auto it = obj.begin(); it != obj.end(); ++it)
        clientsMap[it.key()] = it.value().toString();
}



void MainWindow::sauvegarderClients(const QString &code, const QString &client)
{
    QString jsonPath = "clients.json";
    QFile file(jsonPath);
    QJsonObject json;

    // Charger le fichier s’il existe déjà
    if (file.exists()) {
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray data = file.readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);
            if (!doc.isNull()) json = doc.object();
            file.close();
        }
    }

    // Ajouter ou mettre à jour la commande correspondante
    json[code] = client;

    // Sauvegarder dans le fichier
    if (file.open(QIODevice::WriteOnly)) {
        QJsonDocument doc(json);
        file.write(doc.toJson());
        file.close();
    }

    qDebug() << "✅ Client sauvegardé dans JSON:" << code << "→" << client;
}

void MainWindow::mettreAJourComboBoxClients()
{
    ui->comboBox_client->clear();

    QSqlQuery query("SELECT FIRST_NAME, LAST_NAME FROM TAB_CLIENT");

    while (query.next()) {
        QString nomComplet = query.value(0).toString() + " " + query.value(1).toString();
        ui->comboBox_client->addItem(nomComplet);
    }
}



void MainWindow::on_pushButton_exportPDF_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageOrientation(QPageLayout::Portrait);
    pdfWriter.setPageMargins(QMarginsF(15, 15, 15, 15));

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        QMessageBox::warning(this, "Erreur", "Impossible de créer le fichier PDF !");
        return;
    }

    painter.setFont(QFont("Arial", 12));
    painter.drawText(100, 100, "Test export PDF réussi !");
    painter.end();

    QMessageBox::information(this, "Succès", "PDF créé avec succès !");
}
