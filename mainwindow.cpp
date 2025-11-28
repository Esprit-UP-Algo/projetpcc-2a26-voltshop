#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QRegularExpressionValidator>
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
#include <QPageLayout>
#include <QFont>
#include <QPageSize>
#include <QPainter>
#include <QPrinter>
<<<<<<< HEAD
#include <QTextTable>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QLabel>
#include <QGridLayout>
#include <QPieSeries>
#include <QPieSlice>
#include <QChartView>
#include <QChart>
#include <QDialog>
#include <QPushButton>
#include "CameraCaptureDialog.h"
#include <opencv2/opencv.hpp>
#include "face_recognition.h"
#include "chatbotdialog.h"

=======
#include"client_dao.h"
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94
#include <QDesktopServices>
#include <QUrl>
#include <QImage>

// ✅ AJOUTS pour validations/combos
#include <QIntValidator>
#include <QDoubleValidator>
#include <QRegularExpression>
#include <QComboBox>
#include <QLineEdit>
#include <climits>

static inline bool isPlaceholderSelected(QComboBox* box, const QString& placeholder)
{
    if (!box) return true;
    const int idx = box->currentIndex();
    const QString t = box->currentText().trimmed();
    return (idx <= 0) || t.isEmpty() || t.compare(placeholder, Qt::CaseInsensitive) == 0;
}

bool editing = false;
int editingCode = -1;
#include <random>
// ✅ Generates a random 8-digit eloyee ID (IDE)
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
    connect(ui->comboBox_Emp_Sort, &QComboBox::currentTextChanged,
            this, &MainWindow::on_comboBox_Emp_Sort_currentTextChanged);

    // -------------- ADD THIS LINE FOR STATISTICS ------------------
    connect(ui->pushButton_Emp_Stats, &QPushButton::clicked,
            this, &MainWindow::on_pushButton_Emp_Stats_clicked);
    // --------------------------------------------------------------
    FaceRecognition::instance().loadTrainingData("C:/Users/IMDS/Downloads/integration2026 (3) (1)/integration2026 (3)/integration2026/integrationtest/employees_photos/employees_photos");
    refreshEmployeeTable();

    //commandes
    ui->tableauCommande->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableauCommande->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableauCommande->setMouseTracking(true);
    rafraichirTableau();
    chargerClientsFichier();
    chargerClientsComboBox();
    afficherCommandes();
    mettreAJourComboBoxClients();
<<<<<<< HEAD

    connect(ui->comboBox_trie, &QComboBox::currentTextChanged, this, &MainWindow::trierCommandes);
    connect(ui->pushButton_exportpdf, &QPushButton::clicked, this, &MainWindow::exporterPDFCommandes);
=======
    connect(ui->pushButton_exportpdf, &QPushButton::clicked, this, &MainWindow::on_pushButton_exportpdf_clicked);
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94

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

    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->tableWidget_4, &QTableWidget::cellClicked, this, [this](int row, int col){
        if (row < 0) return;
        populateTransactionFormFromRow(row);
        editing = true;
        if (ui->tableWidget_4->item(row, 0))
            editingCode = ui->tableWidget_4->item(row, 0)->text().toInt();
    });

    afficherTransactions();

    if (ui->comboBoxsort) {
        connect(ui->comboBoxsort, &QComboBox::currentTextChanged, this, &MainWindow::afficherTransactionsSorted);
    }
    // If a sort-order control exists, re-run the sort when it changes
    if (ui->comboBoxSortOrder) {
        connect(ui->comboBoxSortOrder, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int) {
            // reapply current sort selection
            if (ui->comboBoxsort) afficherTransactionsSorted(ui->comboBoxsort->currentText());
        });
    }

    // =========================================================
    // 🔒 VALIDATEURS & PLACEHOLDERS (bloque clavier)
    // =========================================================
    // SKU (formulaire CRUD) : entier strictement positif
    if (ui->sku) {
        auto *vsku = new QIntValidator(1, INT_MAX, this);
        ui->sku->setValidator(vsku);

        connect(ui->sku, &QLineEdit::editingFinished, this, [this]() {
            bool ok = false;
            const int val = ui->sku->text().trimmed().toInt(&ok);
            if (!ok || val <= 0) {
                QMessageBox::warning(this, "Validation", "SKU must be a strictly positive integer.");
                ui->sku->setFocus();
                ui->sku->selectAll();
            }
        });
    }

    // SKU_2 (RECHERCHE seulement) : entier strictement positif
    if (ui->sku_2) {
        auto *v = new QIntValidator(1, INT_MAX, this);   // ← bloque lettres/signes, interdit <= 0
        ui->sku_2->setValidator(v);

        connect(ui->sku_2, &QLineEdit::editingFinished, this, [this]() {
            const QString txt = ui->sku_2->text().trimmed();
            if (txt.isEmpty()) {
                // vide = pas de recherche, pas d'erreur
                return;
            }
            bool ok = false;
            const int val = txt.toInt(&ok);
            if (!ok || val <= 0) {
                QMessageBox::warning(this, "Validation", "SKU must be a strictly positive integer.");
                ui->sku_2->setFocus();
                ui->sku_2->selectAll();
            }
        });
    }

    // STOCK : entier strictement positif
    {
        auto *v = new QIntValidator(1, INT_MAX, this);
        ui->stock->setValidator(v);
    }
    // PURCHASE PRICE : réel strictement positif
    {
        auto *v = new QDoubleValidator(0.000001, 1e12, 6, this);
        v->setNotation(QDoubleValidator::StandardNotation);
        ui->price1->setValidator(v);
    }
    // SELLING PRICE : réel strictement positif
    {
        auto *v = new QDoubleValidator(0.000001, 1e12, 6, this);
        v->setNotation(QDoubleValidator::StandardNotation);
        ui->price2->setValidator(v);
    }

    // BRAND : s'assurer d'un placeholder unique
    {
        if (ui->brand) {
            if (ui->brand->findText("Select the brand", Qt::MatchFixedString) == -1)
                ui->brand->insertItem(0, "Select the brand");
            ui->brand->setCurrentIndex(0);
        }
    }

    // CATEGORY : supporter QComboBox (recommandé) ou fallback QLineEdit existant
    {
        QComboBox *catCombo = nullptr;

        if (auto *asCombo = qobject_cast<QComboBox*>(ui->cat)) {
            catCombo = asCombo;
        } else {
            catCombo = this->findChild<QComboBox*>("cat");
            if (!catCombo) catCombo = this->findChild<QComboBox*>("catBox");
        }

        if (catCombo) {
            if (catCombo->findText("Select the category", Qt::MatchFixedString) == -1)
                catCombo->insertItem(0, "Select the category");
            catCombo->setCurrentIndex(0);
        }
    }

    // =========================================================
    // ✅ RECHERCHE COMBINÉE ARTICLES : SKU_2 + Brand rech_Bra
    // =========================================================
    auto tryArticleSearch = [this]()
    {
        if (!ui || !ui->tab_Art || !ui->sku_2 || !ui->rech_Bra) return;

        // SKU_2 : entier strictement positif
        const QString skuText = ui->sku_2->text().trimmed();
        bool okSku = false;
        const int skuVal = skuText.toInt(&okSku);
        if (!okSku || skuVal <= 0) {
            // pas valide → on affiche tout
            refreshArticlesGrid();
            return;
        }

        // Brand de recherche
        const int brandIdx = ui->rech_Bra->currentIndex();
        const QString brandTxt = ui->rech_Bra->currentText().trimmed();
        if (brandIdx < 0 || brandTxt.isEmpty() ||
            brandTxt.compare("Select the brand", Qt::CaseInsensitive) == 0) {
            refreshArticlesGrid();
            return;
        }

        // Filtrer les articles
        const auto rows = article_dao::fetchAll();
        QVector<Article> filtered;
        filtered.reserve(rows.size());
        for (const auto& a : rows) {
            if (a.SKU == skuVal && a.BRAND.compare(brandTxt, Qt::CaseInsensitive) == 0) {
                filtered.push_back(a);
            }
        }

        // Afficher résultats filtrés
        ui->tab_Art->setRowCount(0);
        for (int i = 0; i < filtered.size(); ++i) {
            const auto &a = filtered[i];
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
            addActionButtonsForRow(i); // ✎
        }
    };

    if (ui->sku_2) {
        connect(ui->sku_2, &QLineEdit::textChanged, this, [tryArticleSearch](const QString&){ tryArticleSearch(); });
    }
    if (ui->rech_Bra) {
        connect(ui->rech_Bra, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, [tryArticleSearch](int){ tryArticleSearch(); });
    }
    // ================================================
    // 🔒 CLIENTS — VALIDATORS (block keyboard inputs)
    // ================================================
    if (ui->c_cin) {
        auto *v = new QIntValidator(0, 99999999, this);   // block letters
        ui->c_cin->setValidator(v);
    }
    if (ui->c_phone) {
        auto *v = new QIntValidator(0, 99999999, this);   // block letters
        ui->c_phone->setValidator(v);
    }

    // Email strict: email@example.com
    // Email strict: email@example.com
    if (ui->c_email) {
        QRegularExpression rx(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
        auto *emailVal = new QRegularExpressionValidator(rx, this);
        ui->c_email->setValidator(emailVal);
    }


    // ------------------------------------------------
    // 🔍 Recherche dynamique dans clients
    // ------------------------------------------------
    connect(ui->rech, &QLineEdit::textChanged, this, [this](const QString &text){
        QString key = text.trimmed();

        if (key.isEmpty()) {
            refreshClientsGrid();
            return;
        }

        const auto rows = client_dao::fetchAll();
        ui->tab_Client->setRowCount(0);

        for (const auto &c : rows) {
            if (c.CIN.startsWith(key, Qt::CaseInsensitive) ||
                c.FIRST_NAME.startsWith(key, Qt::CaseInsensitive) ||
                c.EMAIL.startsWith(key, Qt::CaseInsensitive)) {

                int row = ui->tab_Client->rowCount();
                ui->tab_Client->insertRow(row);

                ui->tab_Client->setItem(row,1, new QTableWidgetItem(c.CIN));
                ui->tab_Client->setItem(row,2, new QTableWidgetItem(c.FIRST_NAME));
                ui->tab_Client->setItem(row,3, new QTableWidgetItem(c.LAST_NAME));
                ui->tab_Client->setItem(row,4, new QTableWidgetItem(c.EMAIL));
                ui->tab_Client->setItem(row,5, new QTableWidgetItem(c.PHONE_NBR));
                ui->tab_Client->setItem(row,6, new QTableWidgetItem(c.ADRESS));
                addClientEditPenForRow(row);
            }
        }
    });

    // ------------------------------------------------
    // 🔡 TRI Clients (QComboBox sort: First name / Adress)
    // ------------------------------------------------
    connect(ui->sort, &QComboBox::currentTextChanged, this, [this](const QString &crit){
        if (crit.compare("name", Qt::CaseInsensitive) == 0)
            ui->tab_Client->sortItems(2, Qt::AscendingOrder);
        else if (crit.compare("Adress", Qt::CaseInsensitive) == 0)
            ui->tab_Client->sortItems(6, Qt::AscendingOrder);
    });


    // =========================================================
    // ✅ TRI ARTICLES : rech_tri (PurchasePrice / SellingPrice / Sort by)
    // =========================================================
    if (ui->rech_tri) {
        connect(ui->rech_tri, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, [this](int){
                    if (!ui || !ui->tab_Art || !ui->rech_tri) return;

                    const QString crit = ui->rech_tri->currentText().trimmed();

                    // "Sort by" → revenir à l'état initial
                    if (crit.isEmpty() ||
                        crit.compare("Sort by", Qt::CaseInsensitive) == 0)
                    {
                        refreshArticlesGrid();
                        return;
                    }

                    int col = -1;

                    // Purchase price
                    if (crit.compare("Purchase price", Qt::CaseInsensitive) == 0 ||
                        crit.compare("purchaseprice", Qt::CaseInsensitive) == 0 ||
                        crit.compare("PURCHASEPRICE", Qt::CaseInsensitive) == 0)
                    {
                        col = 5; // colonne Purchase Price
                    }
                    // Selling price
                    else if (crit.compare("Selling price", Qt::CaseInsensitive) == 0 ||
                             crit.compare("sellingprice", Qt::CaseInsensitive) == 0 ||
                             crit.compare("SELLINGPRICE", Qt::CaseInsensitive) == 0)
                    {
                        col = 6; // colonne Selling Price
                    }

                    // Si critère non reconnu → reset
                    if (col < 0) {
                        refreshArticlesGrid();
                        return;
                    }

                    // Tri ascendant sur la colonne choisie
                    ui->tab_Art->sortItems(col, Qt::AscendingOrder);
                });
    }
}
<<<<<<< HEAD
=======


>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94
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
    QString sql = "SELECT IDT, ID, AMOUNT, PAY_METHOD, DATE_TRANS, STATUS FROM TAB_TRANS";

    // Determine order direction (default ascending)
    QString orderDir = " ASC";
    if (ui->comboBoxSortOrder) {
        QString ord = ui->comboBoxSortOrder->currentText();
        if (ord.contains("desc", Qt::CaseInsensitive) || ord.contains("Descending", Qt::CaseInsensitive)) orderDir = " DESC";
        else orderDir = " ASC";
    }

    if (sortBy.compare("Amount", Qt::CaseInsensitive) == 0) {
        // AMOUNT is stored as VARCHAR2, so convert to number for correct ordering
        sql += " ORDER BY TO_NUMBER(AMOUNT)" + orderDir;
    } else if (sortBy.compare("Date", Qt::CaseInsensitive) == 0) {
        sql += " ORDER BY DATE_TRANS" + orderDir;
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

void MainWindow::on_lineEdit_17_textChanged(const QString &text)
{
    QString t = text.trimmed();
    if (t.isEmpty()) {
        afficherTransactions();
        return;
    }

    bool ok = false;
    int idFilter = t.toInt(&ok);

    QSqlQueryModel *model = new QSqlQueryModel();
    if (ok) {
        QSqlQuery q;
        q.prepare("SELECT IDT, ID, AMOUNT, PAY_METHOD, DATE_TRANS, STATUS FROM TAB_TRANS WHERE ID = :ID");
        q.bindValue(":ID", idFilter);
        q.exec();
        model->setQuery(q);
    } else {
        // If not a number, return an empty model
        model->setQuery("SELECT IDT, ID, AMOUNT, PAY_METHOD, DATE_TRANS, STATUS FROM TAB_TRANS WHERE 1=0");
    }

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

// Helpers pour CATEGORY (support QComboBox OU QLineEdit)
static QString readCategoryFromUi(const Ui::MainWindow* ui)
{
    if (!ui) return {};
    if (auto *asCombo = qobject_cast<QComboBox*>(ui->cat))
        return asCombo->currentText().trimmed();
    if (auto *catCombo = ui->centralwidget->findChild<QComboBox*>("cat"))
        return catCombo->currentText().trimmed();
    if (auto *catCombo2 = ui->centralwidget->findChild<QComboBox*>("catBox"))
        return catCombo2->currentText().trimmed();
    if (auto *asLine = qobject_cast<QLineEdit*>(ui->cat))
        return asLine->text().trimmed();
    return {};
}

static void setCategoryIntoUi(Ui::MainWindow* ui, const QString& value)
{
    if (!ui) return;
    if (auto *asCombo = qobject_cast<QComboBox*>(ui->cat)) {
        asCombo->setCurrentText(value);
        return;
    }
    if (auto *catCombo = ui->centralwidget->findChild<QComboBox*>("cat"))
    {
        catCombo->setCurrentText(value);
        return;
    }
    if (auto *catCombo2 = ui->centralwidget->findChild<QComboBox*>("catBox"))
    {
        catCombo2->setCurrentText(value);
        return;
    }
    // Fallback LineEdit
    if (auto *asLine = qobject_cast<QLineEdit*>(ui->cat)) {
        asLine->setText(value);
    }
}

static bool isCategoryPlaceholderSelected(Ui::MainWindow* ui)
{
    if (!ui) return true;
    if (auto *asCombo = qobject_cast<QComboBox*>(ui->cat))
        return isPlaceholderSelected(asCombo, "Select the category");
    if (auto *catCombo = ui->centralwidget->findChild<QComboBox*>("cat"))
        return isPlaceholderSelected(catCombo, "Select the category");
    if (auto *catCombo2 = ui->centralwidget->findChild<QComboBox*>("catBox"))
        return isPlaceholderSelected(catCombo2, "Select the category");
    // Si c'est un QLineEdit, on considère placeholder non sélectionné (l’utilisateur doit écrire qqch)
    return false;
}

Article MainWindow::readFormArticle() const
{
    Article a;
    a.SKU           = ui->sku->text().trimmed().toInt();          // ✅ CRUD → sku
    a.NAME          = ui->name->text().trimmed();
    a.CATEGORY      = readCategoryFromUi(ui);
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
    // ==============================
    // ✅ VALIDATION AVANT INSERT/UPDATE
    // ==============================
    // 1) SKU obligatoire et entier (via champ sku)
    bool okSku = false;
    const QString skuStr = ui->sku->text().trimmed();
    const int skuVal = skuStr.toInt(&okSku);
    if (!okSku || skuStr.isEmpty()) {
        QMessageBox::warning(this, "Validation", "SKU must be an integer number.");
        ui->sku->setFocus();
        ui->sku->selectAll();
        return;
    }
    if (skuVal <= 0) {
        QMessageBox::warning(this, "Validation", "SKU must be a positive integer.");
        ui->sku->setFocus();
        ui->sku->selectAll();
        return;
    }

    // 2) Tous les champs obligatoires (rapides)
    auto requiredNotEmpty = [&](const QString& s){ return !s.trimmed().isEmpty(); };
    if (!requiredNotEmpty(ui->name->text())
        || !requiredNotEmpty(ui->price1->text())
        || !requiredNotEmpty(ui->price2->text())
        || !requiredNotEmpty(ui->stock->text())
        || !requiredNotEmpty(ui->loca->text())
        || !requiredNotEmpty(ui->com->text()))
    {
        QMessageBox::warning(this, "Validation", "All fields are required.");
        return;
    }

    // 3) CATEGORY / BRAND ne doivent pas rester sur placeholder
    if (ui->brand && isPlaceholderSelected(ui->brand, "Select the brand")) {
        QMessageBox::warning(this, "Validation", "All fields are required.");
        ui->brand->setFocus();
        return;
    }
    if (isCategoryPlaceholderSelected(ui)) {
        QMessageBox::warning(this, "Validation", "All fields are required.");
        return;
    }

    // 4) PURCHASE PRICE, SELLING PRICE : > 0
    bool okP1=false, okP2=false;
    const double p1 = ui->price1->text().toDouble(&okP1);
    const double p2 = ui->price2->text().toDouble(&okP2);
    if (!okP1 || p1 <= 0.0) {
        QMessageBox::warning(this, "Validation", "Purchase price must be a strictly positive number.");
        ui->price1->setFocus(); return;
    }
    if (!okP2 || p2 <= 0.0) {
        QMessageBox::warning(this, "Validation", "Selling price must be a strictly positive number.");
        ui->price2->setFocus(); return;
    }

    // 5) STOCK : entier > 0
    bool okStock=false; const int s = ui->stock->text().toInt(&okStock);
    if (!okStock || s <= 0) {
        QMessageBox::warning(this, "Validation", "Stock must be a strictly positive integer.");
        ui->stock->setFocus(); return;
    }

    // ====== OK, créer l’objet et poursuivre ======
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

// Supprimer l'article sélectionné via le bouton "DEL"
void MainWindow::on_DEL_clicked()
{
    if (!ui->tab_Art) {
        QMessageBox::warning(this, "Delete", "Articles table not found.");
        return;
    }

    // 1) Trouver la ligne sélectionnée (supporte sélection ou simple clic courant)
    int row = -1;
    if (ui->tab_Art->selectionModel()) {
        const auto sel = ui->tab_Art->selectionModel()->selectedRows();
        if (!sel.isEmpty()) row = sel.first().row();
    }
    if (row < 0) row = ui->tab_Art->currentRow();

    if (row < 0) {
        QMessageBox::warning(this, "Delete", "Please select a row to delete.");
        return;
    }

    // 2) Récupérer le SKU (colonne 1 du tableau des articles)
    QTableWidgetItem* skuItem = ui->tab_Art->item(row, 1);
    if (!skuItem) {
        QMessageBox::warning(this, "Delete", "Cannot read SKU from the selected row.");
        return;
    }
    bool ok = false;
    const int sku = skuItem->text().toInt(&ok);
    if (!ok || sku <= 0) {
        QMessageBox::warning(this, "Delete", "Invalid SKU value.");
        return;
    }

    // 3) Demander confirmation
    if (QMessageBox::question(this, "Confirm",
                              QString("Delete article with SKU %1 ?").arg(sku),
                              QMessageBox::Yes | QMessageBox::No)
        != QMessageBox::Yes) {
        return;
    }

    // 4) Supprimer dans la base
    if (!article_dao::remove(sku)) {
        QMessageBox::critical(this, "Error", "Delete failed.");
        return;
    }

    // 5) Rafraîchir l’UI et réinitialiser le formulaire (retour au mode ajout)
    refreshArticlesGrid();
    setFormMode(false);
    QMessageBox::information(this, "Success", "Article deleted.");
}


void MainWindow::setFormMode(bool edit)
{
    m_isEditMode = edit;
    if (edit) {
        ui->confirm->setText("Update");
        ui->sku->setEnabled(false);      // ✅ on bloque sku (CRUD), pas sku_2
    } else {
        ui->confirm->setText("Confirm");
        ui->sku->setEnabled(true);
        ui->sku->clear();
        ui->name->clear();

        // CATEGORY reset (combo si dispo, sinon line edit)
        if (!isCategoryPlaceholderSelected(ui)) setCategoryIntoUi(ui, "");
        if (auto *asCombo = qobject_cast<QComboBox*>(ui->cat)) {
            int idx = asCombo->findText("Select the category", Qt::MatchFixedString);
            asCombo->setCurrentIndex(idx >= 0 ? idx : 0);
        } else {
            setCategoryIntoUi(ui, "");
        }

        if (ui->brand) {
            int idx = ui->brand->findText("Select the brand", Qt::MatchFixedString);
            ui->brand->setCurrentIndex(idx >= 0 ? idx : 0);
        }

        ui->price1->clear(); ui->price2->clear(); ui->stock->clear();
        ui->loca->clear(); ui->com->clear();
    }
}

void MainWindow::populateFormFromRow(int row)
{
    if (row < 0) return;
    ui->sku->setText(ui->tab_Art->item(row,1)->text());         // ✅ CRUD → sku
    ui->name->setText(ui->tab_Art->item(row,2)->text());

    // CATEGORY
    setCategoryIntoUi(ui, ui->tab_Art->item(row,3)->text());

    // BRAND
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
    // Model columns: IDT, ID (refId), AMOUNT, PAY_METHOD, DATE_TRANS, STATUS
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
    ui->e_status->setCurrentText(ui->tab_Employee->item(row, 5)->text());
        // Status
}

Employee MainWindow::readEmployeeForm() const
{
    Employee e;
    e.cin = ui->e_cin->text().trimmed().toStdString();
    e.fullName = ui->e_fullname->text().trimmed().toStdString();
    e.position = ui->e_position->currentText().trimmed().toStdString();
    e.address = ui->e_address->text().trimmed().toStdString();
    e.salary = ui->e_salary->text().trimmed().toStdString(); // ✅ keep as string
    e.status = ui->e_status->currentText().trimmed().toStdString();

    return e;
}

void MainWindow::clearEmployeeForm()
{
    ui->e_cin->clear();
    ui->e_fullname->clear();
    ui->e_address->clear();
    ui->e_salary->clear();
    ui->e_position->setCurrentIndex(-1); // ✅ This one is a QComboBox
    ui->e_status->setCurrentIndex(-1);  // ✅ QLineEdit, so use clear()

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

    // Build query (sorting included)
    QString queryStr =
        "SELECT cin, fullname, position, adress, salary, status FROM employees";

    if (!currentEmployeeSort.isEmpty())
        queryStr += " ORDER BY " + currentEmployeeSort;

    QSqlQuery query(db);
    if (!query.exec(queryStr)) {
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

void MainWindow::on_comboBox_Emp_Sort_currentTextChanged(const QString &sortBy)
{
    // 1. Load employees from the DATABASE instead of using g_emp (which is empty)
    std::vector<Employee> sortedList;
    QSqlQuery q("SELECT cin, fullname, position, adress, salary, status FROM employees");

    while (q.next()) {
        Employee e;
        e.cin      = q.value(0).toString().toStdString();
        e.fullName = q.value(1).toString().toStdString();
        e.position = q.value(2).toString().toStdString();
        e.address  = q.value(3).toString().toStdString();
        e.salary   = q.value(4).toString().toStdString();
        e.status   = q.value(5).toString().toStdString();
        sortedList.push_back(e);
    }

    // 2. Apply sorting
    if (sortBy == "Name") {
        std::sort(sortedList.begin(), sortedList.end(),
                  [](const Employee &a, const Employee &b) {
                      return QString::fromStdString(a.fullName)
                      < QString::fromStdString(b.fullName);
                  });
    }
    else if (sortBy == "CIN") {
        std::sort(sortedList.begin(), sortedList.end(),
                  [](const Employee &a, const Employee &b) {
                      return QString::fromStdString(a.cin)
                      < QString::fromStdString(b.cin);
                  });
    }
    else if (sortBy == "Salary") {
        std::sort(sortedList.begin(), sortedList.end(),
                  [](const Employee &a, const Employee &b) {
                      return QString::fromStdString(a.salary).toDouble()
                      < QString::fromStdString(b.salary).toDouble();
                  });
    }
    else {
        refreshEmployeeTable(); // Default view
        return;
    }

    // 3. Draw the sorted table
    ui->tab_Employee->clearContents();
    ui->tab_Employee->setRowCount(0);
    ui->tab_Employee->setHorizontalHeaderLabels(
        {"CIN", "Full Name", "Position", "Address", "Salary", "Status"}
        );

    for (const auto &e : sortedList) {
        int row = ui->tab_Employee->rowCount();
        ui->tab_Employee->insertRow(row);

        ui->tab_Employee->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(e.cin)));
        ui->tab_Employee->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(e.fullName)));
        ui->tab_Employee->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(e.position)));
        ui->tab_Employee->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(e.address)));
        ui->tab_Employee->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(e.salary)));
        ui->tab_Employee->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(e.status)));
    }

    ui->tab_Employee->resizeColumnsToContents();
}
void MainWindow::on_btnPointage_clicked()
{
    // Absolute path
    QString trainingFolder =
        "C:/Users/IMDS/Downloads/integration2026 (3) (1)/integration2026 (3)/integration2026/integrationtest/employees_photos/employees_photos";

    if (!QDir(trainingFolder).exists())
        trainingFolder = QCoreApplication::applicationDirPath() + "/employees_photos";

    if (!QDir(trainingFolder).exists()) {
        QMessageBox::warning(this, "Erreur",
                             "Dossier d'entraînement introuvable !\n" + trainingFolder);
        return;
    }

    qDebug() << "📂 Loading training data from:" << trainingFolder;

    if (!FaceRecognition::instance().loadTrainingData(trainingFolder)) {
        QMessageBox::warning(this, "Erreur",
                             "Impossible de charger les données d'entraînement!\n\n"
                             "Vérifiez que :\n"
                             "- Le dossier employees_photos existe\n"
                             "- Il contient des photos nommées CIN.jpg\n"
                             "- Le fichier haarcascade_frontalface_default.xml est présent");
        return;
    }

    // --- CAMERA ---
    camera.open(0);
    if (!camera.isOpened()) {
        QMessageBox::warning(this, "Erreur", "Caméra introuvable!");
        return;
    }

    // --- RECOGNITION LOOP ---
    bool employeeFound = false;
    int detectionAttempts = 0;
    const int maxAttempts = 300;

    while (detectionAttempts < maxAttempts && !employeeFound) {
        cv::Mat frame;
        camera >> frame;

        if (frame.empty()) break;

        int cinDetected = FaceRecognition::instance().recognize(frame);

        if (cinDetected != -1) {
            camera.release();
            cv::destroyAllWindows();

            QString cin = QString::number(cinDetected);

            //=========================
            //   ATTENDANCE LOGIC
            //=========================
            QDateTime timeIn;
            int attendanceId;

            if (getOpenSession(cin, timeIn, attendanceId)) {
                // Employee clocking OUT
                clockOutEmployee(attendanceId, timeIn, cin);
            } else {
                // Employee clocking IN
                clockInEmployee(cin);
            }

            employeeFound = true;
            return;
        }

        cv::putText(frame, "Reconnaissance en cours...",
                    cv::Point(10, 30),
                    cv::FONT_HERSHEY_SIMPLEX,
                    0.7, cv::Scalar(0, 255, 0), 2);

        cv::imshow("Pointage - Appuyez sur ESC pour annuler", frame);

        if (cv::waitKey(30) == 27) break;

        detectionAttempts++;
    }

    camera.release();
    cv::destroyAllWindows();

    if (!employeeFound) {
        QMessageBox::warning(this, "Échec",
                             "Aucun employé reconnu.\n"
                             "Vérifiez visibilité, éclairage et base de données.");
    }
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
    if (ui->c_fname->text().trimmed().isEmpty()) {
        QMessageBox::warning(this,"Validation","First name est obligatoire.");
        return;
    }
    if (ui->c_lname->text().trimmed().isEmpty()) {
        QMessageBox::warning(this,"Validation","Last name est obligatoire.");
        return;
    }
    if (ui->c_email->text().trimmed().isEmpty()) {
        QMessageBox::warning(this,"Validation","email est obligatoire.");
        return;
    }
    if (ui->c_phone->text().trimmed().isEmpty()) {
        QMessageBox::warning(this,"Validation","Phone nbr est obligatoire.");
        return;
    }
    if (ui->c_adress->text().trimmed().isEmpty()) {
        QMessageBox::warning(this,"Validation","adress est obligatoire.");
        return;
    }
    QString em  = ui->c_email->text().trimmed();
    QRegularExpression rx(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!rx.match(em).hasMatch()) {
        QMessageBox::warning(this, "Invalid Email",
                             "Invalid email format. Expected: email@example.com");
        ui->c_email->setFocus();
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
    // 1) Lire le CIN depuis le line edit
    QString cin = ui->c_Line_rech->text().trimmed();

    // Champ vide ?
    if (cin.isEmpty()) {
        QMessageBox::warning(this, "Delete", "Please enter a CIN to delete.");
        return;
    }

    // (Optionnel) Vérifier format: exactement 8 chiffres
    QRegularExpression cinRx(R"(^\d{8}$)");
    if (!cinRx.match(cin).hasMatch()) {
        QMessageBox::warning(this, "Delete", "CIN must contain exactly 8 digits.");
        ui->c_Line_rech->setFocus();
        ui->c_Line_rech->selectAll();
        return;
    }

    // 2) Vérifier que le client existe réellement en base
    if (!client_dao::exists(cin)) {
        QMessageBox::information(this, "Delete",
                                 "No client found with this CIN.");
        ui->c_Line_rech->selectAll();
        return;
    }

    // 3) Demander confirmation
    if (QMessageBox::question(this, "Confirm",
                              QString("Delete client %1 ?").arg(cin),
                              QMessageBox::Yes | QMessageBox::No)
        != QMessageBox::Yes)
    {
        return;
    }

    // 4) Suppression effective
    if (client_dao::remove(cin)) {
        QMessageBox::information(this, "Success",
                                 "Client deleted successfully.");
        refreshClientsGrid();          // Rafraîchir le tableau
        mettreAJourComboBoxClients();  // Mettre à jour la combo des commandes
        ui->c_Line_rech->clear();      // Vider le line edit
    } else {
        QMessageBox::critical(this, "Error",
                              "Delete failed. Please try again.");
    }
}
void MainWindow::on_tab_Art_cellChanged(int, int) { }



void MainWindow::on_pushButton_25_clicked()
{
    // Add Payment
    QString idStr = ui->P_id->text().trimmed();
    bool ok = false;
    int id = idStr.toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Validation", "ID invalide. Entrez un entier positif.");
        ui->P_id->setFocus();
        return;
    }

    QString amount = ui->lineEdit_16->text().trimmed();
    QRegularExpression amountRx("^[0-9]+(\\.[0-9]{1,2})?$");
    if (amount.isEmpty() || !amountRx.match(amount).hasMatch() || amount.toDouble() <= 0.0) {
        QMessageBox::warning(this, "Validation", "Montant invalide. Entrez un montant numérique positif (ex: 1234.56).");
        ui->lineEdit_16->setFocus();
        return;
    }

    // Ensure a pay method is chosen (assumes index 0 is the placeholder "Select the Method")
    if (ui->comboBox_3->currentIndex() <= 0) {
        QMessageBox::warning(this, "Validation", "Veuillez sélectionner une méthode de paiement.");
        ui->comboBox_3->setFocus();
        return;
    }
    QString pay_method = ui->comboBox_3->currentText();

    QDate date = ui->dateEdit->date();
    if (!date.isValid()) {
        QMessageBox::warning(this, "Validation", "Date invalide. Veuillez sélectionner une date.");
        ui->dateEdit->setFocus();
        return;
    }

    // Ensure a status is chosen (assumes index 0 is placeholder)
    if (ui->comboBox_4->currentIndex() <= 0) {
        QMessageBox::warning(this, "Validation", "Veuillez sélectionner un statut.");
        ui->comboBox_4->setFocus();
        return;
    }
    QString status = ui->comboBox_4->currentText();

    // refId is taken from the P_id field and maps to TAB_TRANS.ID (required non-null column)
    int refId = id;
    // If we are editing an existing transaction, call modifier(); otherwise ajouter()
    int idToUse = editing ? editingCode : 0;
    Transaction t(idToUse, amount, pay_method, date, status, refId);
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
    QString salary   = ui->e_salary->text().trimmed();
    QString status   = ui->e_status->currentText().trimmed();

    // ==========================
    // VALIDATION
    // ==========================
    QRegularExpression cinRegex("^[0-9]{8}$");
    if (!cinRegex.match(cin).hasMatch()) {
        QMessageBox::warning(this, "Invalid CIN", "❌ CIN must have exactly 8 digits.");
        return;
    }

    QRegularExpression nameRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    if (!nameRegex.match(fullName).hasMatch() || fullName.length() < 3) {
        QMessageBox::warning(this, "Invalid Name", "❌ Full name must contain only letters and spaces (min 3 chars).");
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
        QMessageBox::warning(this, "Invalid Salary", "❌ Salary must be positive.");
        return;
    }

    QStringList validStatuses = {"Active", "Inactive", "On Probation", "Resigned", "Terminated"};
    if (!validStatuses.contains(status)) {
        QMessageBox::warning(this, "Invalid Status",
                             "❌ Status must be one of:\nActive, Inactive, On Probation, Resigned, Terminated.");
        return;
    }

    // Duplicate CIN check (only when adding)
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
    if (m_employeeEditMode)
    {
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
            QMessageBox::information(this, "Success", "✏️ Employee updated successfully!");
        } else {
            QMessageBox::critical(this, "Database Error",
                                  "❌ Failed to update employee:\n" + query.lastError().text());
            return;
        }

        m_employeeEditMode = false;
        m_editingCin.clear();
        ui->e_cin->setEnabled(true);
    }
    else
    {
        // ==============================
        // ADD MODE (PHOTO REQUIRED)
        // ==============================

        CameraCaptureDialog cam(this);

        if (cam.exec() != QDialog::Accepted) {
            QMessageBox::warning(this, "Photo Required",
                                 "❌ You must take a photo to register the employee.");
            return;
        }

        QString tempPhotoPath = cam.getSavedImagePath();

        // Save photo permanently
        QString folder = QDir::currentPath() + "/employees_photos";
        QDir().mkpath(folder);

        QString finalPhotoPath = folder + "/" + cin + ".jpg";

        QFile::remove(finalPhotoPath);  // if exists
        QFile::rename(tempPhotoPath, finalPhotoPath);

        // Insert employee
        QString ide = generateRandomIDE();

        query.prepare(R"(
            INSERT INTO employees (ide, cin, fullname, position, adress, salary, status, photo)
            VALUES (:ide, :cin, :fullname, :position, :address, :salary, :status, :photo)
        )");

        query.bindValue(":ide", ide);
        query.bindValue(":cin", cin);
        query.bindValue(":fullname", fullName);
        query.bindValue(":position", position);
        query.bindValue(":address", address);
        query.bindValue(":salary", salary);
        query.bindValue(":status", status);
        query.bindValue(":photo", finalPhotoPath);

        if (query.exec()) {
            QMessageBox::information(this, "Success",
                                     "✅ Employee added successfully!\n📸 Photo saved.\nID: " + ide);
        } else {
            QMessageBox::critical(this, "Database Error",
                                  "❌ Failed to add employee:\n" + query.lastError().text());
            return;
        }
    }

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
void MainWindow::on_pushButton_Emp_Stats_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database connection is not open!");
        return;
    }

    // Count employees by position and salary ranges
    QMap<QString, int> positionStats;
    QMap<QString, int> salaryStats;
    int totalEmployees = 0;
    double totalSalary = 0;

    // Define salary ranges
    QMap<QString, QPair<double, double>> salaryRanges = {
        {"0-1000 DT", {0, 1000}},
        {"1001-2000 DT", {1001, 2000}},
        {"2001-3000 DT", {2001, 3000}},
        {"3001-4000 DT", {3001, 4000}},
        {"4001-5000 DT", {4001, 5000}},
        {"5000+ DT", {5001, 999999}}
    };

    // Initialize salary range counters
    for (const QString &range : salaryRanges.keys()) {
        salaryStats[range] = 0;
    }

    // Read employee data from DATABASE instead of g_emp
    QSqlQuery query(db);
    QString queryStr = "SELECT position, salary FROM employees";
    if (!query.exec(queryStr)) {
        QMessageBox::critical(this, "Database Error",
                              "Failed to fetch employees for statistics:\n" + query.lastError().text());
        return;
    }

    // Process employee data from database
    while (query.next()) {
        QString position = query.value("position").toString().trimmed();
        QString salaryStr = query.value("salary").toString().trimmed();

        // Statistics by position
        if (!position.isEmpty()) {
            positionStats[position]++;
        }

        // Statistics by salary
        bool ok;
        double salary = salaryStr.toDouble(&ok);
        if (ok && salary > 0) {
            totalEmployees++;
            totalSalary += salary;

            // Find the salary range
            for (const QString &range : salaryRanges.keys()) {
                QPair<double, double> limits = salaryRanges[range];
                if (salary >= limits.first && salary <= limits.second) {
                    salaryStats[range]++;
                    break;
                }
            }
        }
    }

    // Get total count from database (in case some salaries were invalid)
    QSqlQuery countQuery("SELECT COUNT(*) as total FROM employees", db);
    if (countQuery.exec() && countQuery.next()) {
        totalEmployees = countQuery.value("total").toInt();
    }

    if (positionStats.isEmpty() || totalEmployees == 0) {
        QMessageBox::information(this, "Information", "No employee data to display.");
        return;
    }

    // Create a dialog for statistics
    QDialog *statsDialog = new QDialog(this);
    statsDialog->setWindowTitle("Employee Statistics");
    statsDialog->setMinimumSize(1000, 700);

    QVBoxLayout *dialogLayout = new QVBoxLayout(statsDialog);

    // Create main widget with grid layout
    QWidget *mainWidget = new QWidget();
    QGridLayout *mainLayout = new QGridLayout(mainWidget);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(15);

    // === MAIN TITLE ===
    QLabel *titleLabel = new QLabel("Employee Statistics");
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #2c3e50; margin-bottom: 15px;");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel, 0, 0, 1, 2);

    // Colors for charts
    QVector<QColor> colors = {
        QColor("#3498db"),  // Blue
        QColor("#e74c3c"),  // Red
        QColor("#2ecc71"),  // Green
        QColor("#f39c12"),  // Orange
        QColor("#9b59b6"),  // Purple
        QColor("#1abc9c"),  // Turquoise
        QColor("#d35400"),  // Dark orange
        QColor("#c0392b")   // Dark red
    };

    // === CHART 1: DISTRIBUTION BY POSITION ===
    QWidget *positionWidget = new QWidget();
    QVBoxLayout *positionLayout = new QVBoxLayout(positionWidget);
    positionLayout->setContentsMargins(5, 5, 5, 5);

    // Title
    QLabel *positionTitle = new QLabel("Distribution by Position");
    positionTitle->setStyleSheet("font-size: 14px; font-weight: bold; color: #2c3e50; margin-bottom: 10px;");
    positionTitle->setAlignment(Qt::AlignCenter);
    positionLayout->addWidget(positionTitle);

    // Create pie chart for positions
    QPieSeries *seriesPositions = new QPieSeries();

    int colorIndex = 0;
    for (auto it = positionStats.begin(); it != positionStats.end(); ++it) {
        double percentage = (it.value() * 100.0) / totalEmployees;

        // Use short and clear names
        QString positionDisplay = it.key();
        if (positionDisplay.length() > 12)
            positionDisplay = positionDisplay.left(10) + "..";

        // Format with line break: percentage on top, name below
        QString label = QString("%1%\n%2").arg(percentage, 0, 'f', 1).arg(positionDisplay);

        QPieSlice *slice = seriesPositions->append(label, it.value());
        slice->setColor(colors[colorIndex % colors.size()]);
        slice->setLabelVisible(true);
        slice->setLabelColor(Qt::black);
        slice->setLabelPosition(QPieSlice::LabelOutside);
        slice->setLabelArmLengthFactor(0.1); // Short arm
        slice->setExplodeDistanceFactor(0.01); // Very slight separation
        slice->setBorderColor(Qt::white);
        slice->setBorderWidth(1);

        // Adaptive font
        QFont labelFont = slice->labelFont();
        labelFont.setPointSize(8);
        labelFont.setBold(true);
        slice->setLabelFont(labelFont);

        colorIndex++;
    }

    QChart *chartPositions = new QChart();
    chartPositions->addSeries(seriesPositions);
    chartPositions->setTitle("");
    chartPositions->legend()->setVisible(false);
    chartPositions->setAnimationOptions(QChart::AllAnimations);
    chartPositions->setBackgroundBrush(QBrush(QColor("#f8f9fa")));
    chartPositions->setMargins(QMargins(0, 0, 0, 0));

    QChartView *chartViewPositions = new QChartView(chartPositions);
    chartViewPositions->setRenderHint(QPainter::Antialiasing);
    chartViewPositions->setMinimumSize(400, 350);

    positionLayout->addWidget(chartViewPositions);
    mainLayout->addWidget(positionWidget, 1, 0);

    // === CHART 2: DISTRIBUTION BY SALARY ===
    QWidget *salaryWidget = new QWidget();
    QVBoxLayout *salaryLayout = new QVBoxLayout(salaryWidget);
    salaryLayout->setContentsMargins(5, 5, 5, 5);

    // Title
    QLabel *salaryTitle = new QLabel("Distribution by Salary Range");
    salaryTitle->setStyleSheet("font-size: 14px; font-weight: bold; color: #2c3e50; margin-bottom: 10px;");
    salaryTitle->setAlignment(Qt::AlignCenter);
    salaryLayout->addWidget(salaryTitle);

    // Create pie chart for salaries
    QPieSeries *seriesSalary = new QPieSeries();

    // Colors for salary ranges
    QVector<QColor> colorsSalary = {
        QColor("#2ecc71"),  // Light green
        QColor("#3498db"),  // Blue
        QColor("#f39c12"),  // Orange
        QColor("#e67e22"),  // Dark orange
        QColor("#e74c3c"),  // Red
        QColor("#c0392b")   // Dark red
    };

    int colorSalaryIndex = 0;
    for (auto it = salaryStats.begin(); it != salaryStats.end(); ++it) {
        if (it.value() > 0) {
            double percentage = (it.value() * 100.0) / totalEmployees;

            // Short names for salary ranges
            QString rangeDisplay = it.key();
            if (rangeDisplay == "0-1000 DT") rangeDisplay = "0-1k DT";
            else if (rangeDisplay == "1001-2000 DT") rangeDisplay = "1k-2k DT";
            else if (rangeDisplay == "2001-3000 DT") rangeDisplay = "2k-3k DT";
            else if (rangeDisplay == "3001-4000 DT") rangeDisplay = "3k-4k DT";
            else if (rangeDisplay == "4001-5000 DT") rangeDisplay = "4k-5k DT";
            else if (rangeDisplay == "5000+ DT") rangeDisplay = "5k+ DT";

            // Format with line break: percentage on top, range below
            QString label = QString("%1%\n%2").arg(percentage, 0, 'f', 1).arg(rangeDisplay);

            QPieSlice *slice = seriesSalary->append(label, it.value());
            slice->setColor(colorsSalary[colorSalaryIndex % colorsSalary.size()]);
            slice->setLabelVisible(true);
            slice->setLabelColor(Qt::black);
            slice->setLabelPosition(QPieSlice::LabelOutside);
            slice->setLabelArmLengthFactor(0.1); // Short arm
            slice->setExplodeDistanceFactor(0.01); // Very slight separation
            slice->setBorderColor(Qt::white);
            slice->setBorderWidth(1);

            // Adaptive font
            QFont labelFont = slice->labelFont();
            labelFont.setPointSize(8);
            labelFont.setBold(true);
            slice->setLabelFont(labelFont);

            colorSalaryIndex++;
        }
    }

    QChart *chartSalary = new QChart();
    chartSalary->addSeries(seriesSalary);
    chartSalary->setTitle("");
    chartSalary->legend()->setVisible(false);
    chartSalary->setAnimationOptions(QChart::AllAnimations);
    chartSalary->setBackgroundBrush(QBrush(QColor("#f8f9fa")));
    chartSalary->setMargins(QMargins(0, 0, 0, 0));

    QChartView *chartViewSalary = new QChartView(chartSalary);
    chartViewSalary->setRenderHint(QPainter::Antialiasing);
    chartViewSalary->setMinimumSize(400, 350);

    salaryLayout->addWidget(chartViewSalary);
    mainLayout->addWidget(salaryWidget, 1, 1);

    // === SUMMARY STATISTICS ===
    QWidget *summaryWidget = new QWidget();
    QVBoxLayout *summaryLayout = new QVBoxLayout(summaryWidget);

    QLabel *summaryTitle = new QLabel("Summary Statistics");
    summaryTitle->setStyleSheet("font-size: 14px; font-weight: bold; color: #2c3e50; margin-bottom: 10px;");
    summaryTitle->setAlignment(Qt::AlignCenter);
    summaryLayout->addWidget(summaryTitle);

    double avgSalary = totalEmployees > 0 ? totalSalary / totalEmployees : 0;

    QLabel *totalLabel = new QLabel(QString("Total Employees: %1").arg(totalEmployees));
    QLabel *avgSalaryLabel = new QLabel(QString("Average Salary: %1 DT").arg(avgSalary, 0, 'f', 2));
    QLabel *positionsLabel = new QLabel(QString("Different Positions: %1").arg(positionStats.size()));

    QStringList summaryStyles = {
        "font-size: 12px; padding: 5px; background-color: #ecf0f1; border-radius: 3px;"
    };

    totalLabel->setStyleSheet(summaryStyles[0]);
    avgSalaryLabel->setStyleSheet(summaryStyles[0]);
    positionsLabel->setStyleSheet(summaryStyles[0]);

    summaryLayout->addWidget(totalLabel);
    summaryLayout->addWidget(avgSalaryLabel);
    summaryLayout->addWidget(positionsLabel);

    mainLayout->addWidget(summaryWidget, 2, 0, 1, 2);

    // Add close button
    QPushButton *closeButton = new QPushButton("Close");
    closeButton->setStyleSheet("QPushButton { background-color: #e74c3c; color: white; padding: 8px; border-radius: 4px; }");
    connect(closeButton, &QPushButton::clicked, statsDialog, &QDialog::accept);
    mainLayout->addWidget(closeButton, 3, 0, 1, 2);

    // Add everything to dialog
    dialogLayout->addWidget(mainWidget);

    // Show the dialog
    statsDialog->exec();

    // Clean up
    statsDialog->deleteLater();
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

        QString produits = model->data(model->index(i, 2)).toString();
        QString total = model->data(model->index(i, 3)).toString();
        QString statut = model->data(model->index(i, 4)).toString();
        QString client = clientsMap.value(code, "—");  // récup client depuis JSON

        QDateTime dateTime = model->data(model->index(i, 1)).toDateTime();
        QString dateStr = dateTime.date().toString("yyyy-MM-dd");
        ui->tableauCommande->setItem(i, 1, new QTableWidgetItem(dateStr));


        ui->tableauCommande->setItem(i, 0, new QTableWidgetItem(code));

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
            QString data;

            if (j == 1) { // colonne date
                QDateTime dateTime = model->data(model->index(i, j)).toDateTime();
                data = dateTime.date().toString("yyyy-MM-dd");
            } else {
                data = model->data(model->index(i, j)).toString();
            }

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

<<<<<<< HEAD



void MainWindow::trierCommandes(const QString &critere)
{
    int colonneStatus = 4; // adapte selon ta table
    int colonneDate = 1;

    QList<QList<QString>> lignes;

    // Récupère toutes les lignes
    for (int i = 0; i < ui->tableauCommande->rowCount(); ++i) {
        QList<QString> rowData;
        for (int j = 0; j < ui->tableauCommande->columnCount(); ++j)
            rowData.append(ui->tableauCommande->item(i, j)->text());
        lignes.append(rowData);
    }

    if (critere == "status") {
        QStringList ordre = {"pending", "in progress", "delivered", "cancelled"};
        std::sort(lignes.begin(), lignes.end(), [&](const QList<QString> &a, const QList<QString> &b) {
            int i1 = ordre.indexOf(a[colonneStatus].toLower());
            int i2 = ordre.indexOf(b[colonneStatus].toLower());
            if (i1 == -1) i1 = ordre.size();
            if (i2 == -1) i2 = ordre.size();
            return i1 < i2;
        });
    }
    else if (critere == "date") {
        std::sort(lignes.begin(), lignes.end(), [&](const QList<QString> &a, const QList<QString> &b) {
            QDate d1 = QDate::fromString(a[colonneDate], "yyyy-MM-dd");
            QDate d2 = QDate::fromString(b[colonneDate], "yyyy-MM-dd");
            return d1 > d2; // tri décroissant
        });
    }

    // Réécrire le tableau trié
    ui->tableauCommande->setRowCount(0);
    for (const auto &row : lignes) {
        int r = ui->tableauCommande->rowCount();
        ui->tableauCommande->insertRow(r);
        for (int j = 0; j < row.size(); ++j)
            ui->tableauCommande->setItem(r, j, new QTableWidgetItem(row[j]));
    }
}

// 🟢 Quand on clique sur le bouton Search
void MainWindow::on_pushButton_search_clicked()
{
    QString searchText = ui->lineEdit_search->text().trimmed().toLower();
    bool found = false;

    if (searchText.isEmpty()) {
        QMessageBox::information(this, "Search", "Please enter a code or client to search.");
        return;
    }

    for (int i = 0; i < ui->tableauCommande->rowCount(); ++i) {
        QString code = ui->tableauCommande->item(i, 0)->text().toLower();
        QString client = ui->tableauCommande->item(i, 5)->text().toLower();

        bool match = code.contains(searchText) || client.contains(searchText);
        ui->tableauCommande->setRowHidden(i, !match);

        if (match)
            found = true;
    }

    if (!found) {
        QMessageBox::warning(this, "Search", "⚠️ Order not found!");
    }
}

// 🔄 Quand on efface le texte → tout réafficher automatiquement
void MainWindow::on_lineEdit_search_textChanged(const QString &text)
{
    if (text.trimmed().isEmpty()) {
        for (int i = 0; i < ui->tableauCommande->rowCount(); ++i)
            ui->tableauCommande->setRowHidden(i, false);
    }
}


void MainWindow::exporterPDFCommandes()
{
    QWidget* parent = this;

    QString fileName = QFileDialog::getSaveFileName(parent,
                                                    "Export order list as PDF",
                                                    QDir::homePath() + "/order_list.pdf",
                                                    "PDF Files (*.pdf)");

    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";

    QTextDocument document;
    QTextCursor cursor(&document);

    // --- Main title ---
    QTextCharFormat titleFormat;
    titleFormat.setFontPointSize(18);
    titleFormat.setFontWeight(QFont::Bold);
    titleFormat.setForeground(Qt::darkBlue);
    cursor.insertText("Order List – VOTSHOP\n", titleFormat);

    // --- Export date ---
    cursor.insertText("\nDate: " + QDate::currentDate().toString("dd/MM/yyyy") + "\n\n");

    // --- Table format ---
    QTextTableFormat tableFormat;
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorder(0.8);
    tableFormat.setCellPadding(6);
    tableFormat.setCellSpacing(0);
    tableFormat.setAlignment(Qt::AlignCenter);
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));

    int rowCount = ui->tableauCommande->rowCount();
    int colCount = ui->tableauCommande->columnCount();

    QTextTable* table = cursor.insertTable(rowCount + 1, colCount, tableFormat);

    // --- Header row ---
    QTextCharFormat headerFormat;
    headerFormat.setFontWeight(QFont::Bold);
    headerFormat.setBackground(QBrush(QColor("#E0E0E0"))); // light gray
    headerFormat.setFontPointSize(11);

    for (int c = 0; c < colCount; ++c)
    {
        QString headerText = ui->tableauCommande->horizontalHeaderItem(c)->text();
        QTextCursor cellCursor = table->cellAt(0, c).firstCursorPosition();
        cellCursor.setCharFormat(headerFormat);
        cellCursor.insertText(headerText);
    }

    // --- Table content ---
    for (int r = 0; r < rowCount; ++r)
    {
        for (int c = 0; c < colCount; ++c)
        {
            QTableWidgetItem* item = ui->tableauCommande->item(r, c);
            if (!item) continue;

            QString text = item->text();

            // 🔹 If the column is "Date", remove the time part
            if (ui->tableauCommande->horizontalHeaderItem(c)->text().contains("Date", Qt::CaseInsensitive))
            {
                QDateTime dateTime = QDateTime::fromString(text, Qt::ISODate);
                if (dateTime.isValid())
                    text = dateTime.date().toString("dd/MM/yyyy");
                else if (text.contains(" "))
                    text = text.split(" ").first();
            }

            table->cellAt(r + 1, c).firstCursorPosition().insertText(text);
        }
    }

    // --- Footer ---
    cursor.movePosition(QTextCursor::End);
    cursor.insertText("\n\nDocument automatically generated by VOLTSHOP", QTextCharFormat());

    // --- Print / Save as PDF ---
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    document.print(&printer);

    QMessageBox::information(parent, "Export Successful 🎉",
                             "The PDF file has been successfully saved at:\n" + fileName);
}
bool MainWindow::getOpenSession(const QString &cin,
                                QDateTime &timeIn,
                                int &attendanceId)
{
    QSqlQuery query;
    query.prepare("SELECT id, time_in FROM attendance WHERE cin = :cin AND time_out IS NULL");
    query.bindValue(":cin", cin);

    if (!query.exec()) {
        qDebug() << "❌ ERROR getOpenSession:" << query.lastError();
        return false;
    }

    if (query.next()) {
        attendanceId = query.value("id").toInt();
        timeIn = query.value("time_in").toDateTime();
        return true;
    }

    return false;
}

void MainWindow::clockInEmployee(const QString &cin)
{
    QSqlQuery query;
    query.prepare("INSERT INTO attendance (id, cin, time_in) "
                  "VALUES (ATTENDANCE_SEQ.NEXTVAL, :cin, CURRENT_TIMESTAMP)");
    query.bindValue(":cin", cin);

    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur", "Échec du pointage d'entrée !");
        qDebug() << "❌ ERROR clockInEmployee:" << query.lastError();
        return;
    }

    QMessageBox::information(this, "Pointage Entrée",
                             "Entrée enregistrée pour CIN: " + cin);
}



void MainWindow::clockOutEmployee(int attendanceId,
                                  const QDateTime &timeIn,
                                  const QString &cin)
{
    QDateTime now = QDateTime::currentDateTime();

    // Update attendance record
    QSqlQuery query;
    query.prepare("UPDATE attendance SET time_out = CURRENT_TIMESTAMP WHERE id = :id");
    query.bindValue(":id", attendanceId);

    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur", "Échec du pointage de sortie !");
        qDebug() << "❌ ERROR clockOutEmployee:" << query.lastError();
        return;
    }

    // Calculate worked duration
    qint64 seconds = timeIn.secsTo(now);
    QTime workedTime = QTime(0, 0).addSecs(seconds);
    double hoursWorked = getWorkedHours(timeIn, now);

    // Update employee salary based on hours worked
    updateEmployeeSalary(cin, hoursWorked);

    // Get employee position for display
    QSqlQuery posQuery;
    posQuery.prepare("SELECT position, salary FROM EMPLOYEE WHERE cin = :cin");
    posQuery.bindValue(":cin", cin);

    QString position = "Unknown";
    QString newSalary = "N/A";
    if (posQuery.exec() && posQuery.next()) {
        position = posQuery.value("position").toString();
        newSalary = QString::number(posQuery.value("salary").toDouble(), 'f', 2);
    }

    double hourlyRate = calculateHourlyRate(position);
    double earnedAmount = hoursWorked * hourlyRate;

    // Show detailed message with salary information
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Pointage Sortie");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText(QString(
                       "✅ Sortie enregistrée pour CIN: %1\n\n"
                       "📋 Poste: %2\n"
                       "⏱️ Temps travaillé: %3\n"
                       "💰 Taux horaire: %4 TND/h\n"
                       "💵 Montant gagné: %5 TND\n"
                       "💳 Salaire total: %6 TND"
                       ).arg(cin)
                       .arg(position)
                       .arg(workedTime.toString("hh:mm:ss"))
                       .arg(QString::number(hourlyRate, 'f', 2))
                       .arg(QString::number(earnedAmount, 'f', 2))
                       .arg(newSalary));

    msgBox.exec();

    // Refresh the employee table to show updated salary
    refreshEmployeeTable();
}
double MainWindow::calculateHourlyRate(const QString &position)
{
    QString pos = position.toLower().trimmed();

    // Hourly rates based on position hierarchy
    if (pos.contains("manager") || pos.contains("directeur")) {
        return 25.0;  // 25 TND/hour for managers
    }
    else if (pos.contains("technicien") || pos.contains("technician")) {
        return 15.0;  // 15 TND/hour for technicians
    }
    else if (pos.contains("security") || pos.contains("securite") || pos.contains("guard")) {
        return 8.0;   // 8 TND/hour for security
    }
    else {
        return 12.0;  // 12 TND/hour for other positions (default)
    }
}

// =====================================================
//           CALCULATE WORKED HOURS
// =====================================================
double MainWindow::getWorkedHours(const QDateTime &timeIn, const QDateTime &timeOut)
{
    qint64 seconds = timeIn.secsTo(timeOut);
    return seconds / 3600.0; // Convert seconds to hours
}
// =====================================================
//           UPDATE EMPLOYEE SALARY
// =====================================================
void MainWindow::updateEmployeeSalary(const QString &cin, double hoursWorked)
{
    // Get employee position from database
    QSqlQuery query;
    query.prepare("SELECT position, salary FROM EMPLOYEE WHERE cin = :cin");
    query.bindValue(":cin", cin);

    if (!query.exec() || !query.next()) {
        qDebug() << "❌ ERROR: Could not retrieve employee data:" << query.lastError();
        return;
    }

    QString position = query.value("position").toString();
    double currentSalary = query.value("salary").toDouble();

    // Calculate hourly rate based on position
    double hourlyRate = calculateHourlyRate(position);

    // Calculate earned amount for this session
    double earnedAmount = hoursWorked * hourlyRate;

    // Update total salary
    double newSalary = currentSalary + earnedAmount;

    // Update in database
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE EMPLOYEE SET salary = :salary WHERE cin = :cin");
    updateQuery.bindValue(":salary", QString::number(newSalary, 'f', 2));
    updateQuery.bindValue(":cin", cin);

    if (!updateQuery.exec()) {
        qDebug() << "❌ ERROR: Failed to update salary:" << updateQuery.lastError();
        QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du salaire !");
        return;
    }

    qDebug() << "✅ Salary updated for CIN:" << cin
             << "| Position:" << position
             << "| Hours:" << hoursWorked
             << "| Rate:" << hourlyRate << "TND/h"
             << "| Earned:" << earnedAmount << "TND"
             << "| New Total:" << newSalary << "TND";
}
void MainWindow::on_chat_bot_clicked()
{
    ChatBotDialog dlg(this);
    dlg.setWindowTitle("ChatBot Mistral");
    dlg.exec();
=======
void MainWindow::on_pushButton_exportpdf_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty())
        return;

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMarginsF(30, 30, 30, 30));

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        QMessageBox::warning(this, "Erreur", "Impossible de créer le fichier PDF.");
        return;
    }

    int pageWidth = pdfWriter.width();
    int pageHeight = pdfWriter.height();
    int margin = 50;
    int y = margin;

    // === LOGO ===
    QPixmap logo(":/images/ressource/logo.jpeg");
    if (!logo.isNull()) {
        QRect logoRect(margin, y, 100, 100);
        painter.drawPixmap(logoRect, logo.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    // === TITRE ===
    painter.setFont(QFont("Helvetica", 18, QFont::Bold));
    painter.drawText(margin + 130, y + 50, "Liste des Commandes");

    // === DATE ===
    painter.setFont(QFont("Helvetica", 10));
    painter.drawText(pageWidth - 200, y + 50, "Date : " + QDate::currentDate().toString("dd/MM/yyyy"));

    y += 150; // plus d’espace avant le tableau

    // === TABLEAU ===
    int totalCols = ui->tableauCommande->columnCount();
    int totalRows = ui->tableauCommande->rowCount();
    if (totalCols == 0 || totalRows == 0) {
        painter.drawText(margin, y, "⚠️ Aucun enregistrement à afficher.");
        painter.end();
        QMessageBox::information(this, "PDF généré", "Aucune donnée à exporter.");
        return;
    }

    QVector<int> colWidths(totalCols, 0);
    QFontMetrics metrics(painter.font());

    // Calcul automatique de la largeur de colonnes
    for (int col = 0; col < totalCols; ++col) {
        int maxWidth = metrics.horizontalAdvance(ui->tableauCommande->horizontalHeaderItem(col)->text());
        for (int row = 0; row < totalRows; ++row) {
            QTableWidgetItem *item = ui->tableauCommande->item(row, col);
            if (item)
                maxWidth = qMax(maxWidth, metrics.horizontalAdvance(item->text()));
        }
        colWidths[col] = maxWidth + 40;
    }

    // Ajustement à la largeur de page
    int availableWidth = pageWidth - 2 * margin;
    int totalWidth = std::accumulate(colWidths.begin(), colWidths.end(), 0);
    if (totalWidth > availableWidth) {
        double ratio = (double)availableWidth / totalWidth;
        for (int &w : colWidths) w = int(w * ratio);
    }

    int rowHeight = 30;
    QPen borderPen(Qt::black);
    painter.setPen(borderPen);

    // === En-têtes ===
    painter.setFont(QFont("Helvetica", 11, QFont::Bold));
    painter.setBrush(QColor(66, 133, 244));

    int x = margin;
    for (int col = 0; col < totalCols; ++col) {
        QRect cellRect(x, y, colWidths[col], rowHeight);
        painter.fillRect(cellRect, QColor(66, 133, 244));
        painter.drawRect(cellRect);
        painter.setPen(Qt::white);
        painter.drawText(cellRect, Qt::AlignCenter, ui->tableauCommande->horizontalHeaderItem(col)->text());
        painter.setPen(borderPen);
        x += colWidths[col];
    }
    y += rowHeight;

    // === Données ===
    painter.setFont(QFont("Helvetica", 10));
    for (int row = 0; row < totalRows; ++row) {
        if (y > pageHeight - 100) { // Nouvelle page
            pdfWriter.newPage();
            y = margin + 20;

            // Réimpression de l’en-tête
            x = margin;
            painter.setFont(QFont("Helvetica", 11, QFont::Bold));
            painter.setBrush(QColor(66, 133, 244));
            for (int col = 0; col < totalCols; ++col) {
                QRect cellRect(x, y, colWidths[col], rowHeight);
                painter.fillRect(cellRect, QColor(66, 133, 244));
                painter.drawRect(cellRect);
                painter.setPen(Qt::white);
                painter.drawText(cellRect, Qt::AlignCenter, ui->tableauCommande->horizontalHeaderItem(col)->text());
                painter.setPen(borderPen);
                x += colWidths[col];
            }
            y += rowHeight;
            painter.setFont(QFont("Helvetica", 10));
        }

        if (row % 2 == 0)
            painter.fillRect(QRect(margin, y, availableWidth, rowHeight), QColor(245, 245, 245));

        x = margin;
        for (int col = 0; col < totalCols; ++col) {
            QString text = ui->tableauCommande->item(row, col)
            ? ui->tableauCommande->item(row, col)->text()
            : "";
            QRect cellRect(x, y, colWidths[col], rowHeight);
            painter.drawRect(cellRect);
            painter.drawText(cellRect, Qt::AlignCenter, text);
            x += colWidths[col];
        }
        y += rowHeight;
    }

    // === Pied de page ===
    painter.setFont(QFont("Helvetica", 9, QFont::StyleItalic));
    painter.drawText(margin, pageHeight - 40, "Document généré automatiquement par ESPRIT_SR");

    painter.end();
    QMessageBox::information(this, "Succès", "PDF exporté avec succès !");
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94
}
