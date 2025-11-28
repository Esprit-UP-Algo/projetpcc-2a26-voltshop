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
#include "barchartwidget.h"
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
#include"client_dao.h"
#include <QDesktopServices>
#include <QUrl>
#include <QImage>
#include <QTimer>
#include <QPointer>
#include "Login.h"

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
// ✅ Generates a random 8-digit employee ID (IDE)
QString generateRandomIDE()
{
    static std::mt19937 rng(std::random_device{}()); // Random engine
    std::uniform_int_distribution<int> dist(10000000, 99999999); // Range 8 digits
    return QString::number(dist(rng));
}

// Define static flag default
bool MainWindow::s_skipHeavyInit = false;
// When >=0, run only blocks 0..s_initMaxBlock (inclusive). -1 = run all.
int MainWindow::s_initMaxBlock = -1;
// No static for m_initialRole — it's an instance member declared in header

// Instance counter for debugging
static int s_instanceCounter = 0;

// =====================
//      CONSTRUCTEUR
// =====================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    int instanceId = ++s_instanceCounter;
    qDebug() << "[MainWindow] ctor start - INSTANCE #" << instanceId;
    ui->setupUi(this);
    qDebug() << "[MainWindow] after setupUi";
    qDebug() << "[MainWindow] s_skipHeavyInit=" << MainWindow::s_skipHeavyInit;
    connect(ui->pushButton_31, &QPushButton::clicked, this, &MainWindow::on_pushButton_31_clicked);
    connect(ui->lineEdit_19, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_19_textChanged);
    connect(ui->tab_Employee, &QTableWidget::cellClicked,
            this, &MainWindow::on_tab_Employee_cellClicked);
    // Defer heavy initialization to finishInitialization() to avoid show()/setupUi() reentrancy races
    if (!MainWindow::s_skipHeavyInit) {
        qDebug() << "[MainWindow] scheduling finishInitialization";
        QTimer::singleShot(0, this, &MainWindow::finishInitialization);
    } else {
        qDebug() << "[MainWindow] skipped scheduling finishInitialization (debug mode)";
    }
    //commandes

    ui->tableauCommande->setSelectionMode(QAbstractItemView::SingleSelection);  // Une seule sélection à la fois
    ui->tableauCommande->setSelectionBehavior(QAbstractItemView::SelectRows);   // Sélectionne toute la ligne
    ui->tableauCommande->setMouseTracking(true);                                // Active le hover
    // Heavy initialization is deferred to finishInitialization().
    // Ensure clients tab and its widgets are initialized at startup so
    // the city pie chart and total clients label appear without clicking Clients
    if (!MainWindow::s_skipHeavyInit) {
        if (!m_clientTableInit) { setupTabClient(); m_clientTableInit = true; }
        refreshClientsGrid();
    } else {
        qDebug() << "[MainWindow] skipped initial clients table setup (debug mode)";
    }
    connect(ui->pushButton_exportpdf, &QPushButton::clicked, this, &MainWindow::on_pushButton_exportpdf_clicked);
    // Explicitly connect the clients export button to ensure the slot is invoked
    if (ui->pushButton_6) connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_pushButton_6_clicked);

    // ----- MENU -----
    connect(ui->btn_Client,      &QPushButton::clicked, this, &MainWindow::showSClient);
    connect(ui->btn_Commande,    &QPushButton::clicked, this, &MainWindow::showCommande);
    connect(ui->btn_Stock,       &QPushButton::clicked, this, &MainWindow::showStock);
    connect(ui->btn_Transaction, &QPushButton::clicked, this, &MainWindow::showTransaction);
    connect(ui->btn_Employee,    &QPushButton::clicked, this, &MainWindow::showEmployee);

    // ----- ARTICLES -----
    // Article setup deferred to finishInitialization().

    // ----- CLIENTS -----
    connect(ui->btn_Client, &QPushButton::clicked, this, [this]() {
        if (!m_clientTableInit) { setupTabClient(); m_clientTableInit = true; }
        refreshClientsGrid();
    });

    // Page d’accueil
    ui->stackedWidget->setCurrentIndex(0);

    qDebug() << "[MainWindow] ctor end - stacked index" << ui->stackedWidget->currentIndex();

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
    // transactions deferred to finishInitialization().

    qDebug() << "[MainWindow] ctor end - stacked index" << ui->stackedWidget->currentIndex();

    // Connect the sort combobox to refresh the transactions table when selection changes
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

    // Connect quit/logout button if present (object name 'quit' in UI)
    if (ui->quit) {
        connect(ui->quit, &QPushButton::clicked, this, &MainWindow::on_quit_clicked);
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


MainWindow::~MainWindow(){
    qDebug() << "[MainWindow] destructor called - INSTANCE COUNT NOW:" << (s_instanceCounter - 1);
    s_instanceCounter--;
    
    // Explicitly delete chart widgets before deleting ui to prevent double-deletion
    if (statusChartViewWidget) {
        delete statusChartViewWidget;
        statusChartViewWidget = nullptr;
    }
    if (paymentMethodChartWidget) {
        delete paymentMethodChartWidget;
        paymentMethodChartWidget = nullptr;
    }
    if (cityChartViewWidget) {
        delete cityChartViewWidget;
        cityChartViewWidget = nullptr;
    }
    
    delete ui;
    qDebug() << "[MainWindow] destructor finished";
}

void MainWindow::finishInitialization()
{
    qDebug() << "[MainWindow] finishInitialization start";

    // Allow quick override from environment for iterative debugging (set VOLT_INIT_MAX=N)
    if (MainWindow::s_initMaxBlock < 0) {
        QByteArray env = qgetenv("VOLT_INIT_MAX");
        if (!env.isEmpty()) {
            bool ok = false;
            int v = env.toInt(&ok);
            if (ok) {
                MainWindow::s_initMaxBlock = v;
                qDebug() << "[MainWindow] VOLT_INIT_MAX overridden to" << MainWindow::s_initMaxBlock;
            }
        }
    }

    int __block = 0;

    qDebug() << "[MainWindow] before refreshEmployeeTable (block" << __block << ")";
    if (MainWindow::s_initMaxBlock < 0 || __block <= MainWindow::s_initMaxBlock) {
        refreshEmployeeTable();
        qDebug() << "[MainWindow] after refreshEmployeeTable (block" << __block << ")";
    } else {
        qDebug() << "[MainWindow] skipped refreshEmployeeTable (block" << __block << ")";
    }
    __block++;

    qDebug() << "[MainWindow] before rafraichirTableau (block" << __block << ")";
    if (MainWindow::s_initMaxBlock < 0 || __block <= MainWindow::s_initMaxBlock) {
        rafraichirTableau();
        qDebug() << "[MainWindow] after rafraichirTableau (block" << __block << ")";
    } else {
        qDebug() << "[MainWindow] skipped rafraichirTableau (block" << __block << ")";
    }
    __block++;

    qDebug() << "[MainWindow] before chargerClientsFichier (block" << __block << ")";
    if (MainWindow::s_initMaxBlock < 0 || __block <= MainWindow::s_initMaxBlock) {
        chargerClientsFichier();  // 🔹 Charge la map depuis clients.json
        qDebug() << "[MainWindow] after chargerClientsFichier (block" << __block << ")";
    } else {
        qDebug() << "[MainWindow] skipped chargerClientsFichier (block" << __block << ")";
    }
    __block++;

    qDebug() << "[MainWindow] before chargerClientsComboBox (block" << __block << ")";
    if (MainWindow::s_initMaxBlock < 0 || __block <= MainWindow::s_initMaxBlock) {
        chargerClientsComboBox(); // 🔹 Remplit la comboBox avec les clients existants
        qDebug() << "[MainWindow] after chargerClientsComboBox (block" << __block << ")";
    } else {
        qDebug() << "[MainWindow] skipped chargerClientsComboBox (block" << __block << ")";
    }
    __block++;

    qDebug() << "[MainWindow] before afficherCommandes (block" << __block << ")";
    if (MainWindow::s_initMaxBlock < 0 || __block <= MainWindow::s_initMaxBlock) {
        afficherCommandes();      // 🔹 Affiche les commandes avec la colonne client
        qDebug() << "[MainWindow] after afficherCommandes (block" << __block << ")";
    } else {
        qDebug() << "[MainWindow] skipped afficherCommandes (block" << __block << ")";
    }
    __block++;

    qDebug() << "[MainWindow] before mettreAJourComboBoxClients (block" << __block << ")";
    if (MainWindow::s_initMaxBlock < 0 || __block <= MainWindow::s_initMaxBlock) {
        mettreAJourComboBoxClients();
        qDebug() << "[MainWindow] after mettreAJourComboBoxClients (block" << __block << ")";
    } else {
        qDebug() << "[MainWindow] skipped mettreAJourComboBoxClients (block" << __block << ")";
    }
    __block++;

    qDebug() << "[MainWindow] before setupTabArt (block" << __block << ")";
    if (MainWindow::s_initMaxBlock < 0 || __block <= MainWindow::s_initMaxBlock) {
        setupTabArt();
        qDebug() << "[MainWindow] after setupTabArt (block" << __block << ")";
    } else {
        qDebug() << "[MainWindow] skipped setupTabArt (block" << __block << ")";
    }
    __block++;

    qDebug() << "[MainWindow] before refreshArticlesGrid (block" << __block << ")";
    if (MainWindow::s_initMaxBlock < 0 || __block <= MainWindow::s_initMaxBlock) {
        refreshArticlesGrid();
        qDebug() << "[MainWindow] after refreshArticlesGrid (block" << __block << ")";
    } else {
        qDebug() << "[MainWindow] skipped refreshArticlesGrid (block" << __block << ")";
    }
    __block++;

    qDebug() << "[MainWindow] before afficherTransactions (block" << __block << ")";
    if (MainWindow::s_initMaxBlock < 0 || __block <= MainWindow::s_initMaxBlock) {
        afficherTransactions();
        qDebug() << "[MainWindow] after afficherTransactions (block" << __block << ")";
    } else {
        qDebug() << "[MainWindow] skipped afficherTransactions (block" << __block << ")";
    }
    __block++;

    qDebug() << "[MainWindow] finishInitialization end";

    // If an initial role was requested before heavy init (from Login), apply it now.
    if (!m_initialRole.isEmpty()) {
        qDebug() << "[MainWindow] Applying initial role after init:" << m_initialRole;
        openRoleTab(m_initialRole);
        m_initialRole.clear();
    }
}

void MainWindow::setInitialRole(const QString &role)
{
    m_initialRole = role.trimmed();
    if (m_initialRole.isEmpty()) return;
    // If heavy init is skipped (debug mode) we should apply immediately
    if (MainWindow::s_skipHeavyInit) {
        qDebug() << "[MainWindow] s_skipHeavyInit true — applying initial role immediately:" << m_initialRole;
        openRoleTab(m_initialRole);
        m_initialRole.clear();
    }
}

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    qDebug() << "[MainWindow] showEvent - visible?" << this->isVisible();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "[MainWindow] closeEvent";
    QMainWindow::closeEvent(event);
}

void MainWindow::on_quit_clicked()
{
    qDebug() << "[MainWindow] logout requested via quit button";
    
    // Disconnect to prevent re-entry
    if (ui && ui->quit) {
        disconnect(ui->quit, nullptr, this, nullptr);
        ui->quit->setEnabled(false);
    }
    
    // Hide this window immediately to give visual feedback
    this->hide();
    
    // Temporarily prevent app from quitting when windows close
    qApp->setQuitOnLastWindowClosed(false);
    
    qDebug() << "[MainWindow] Creating new Login dialog";
    
    // Create and show new Login dialog
    Login *dlg = new Login(nullptr);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->show();
    dlg->raise();
    dlg->activateWindow();
    
    qDebug() << "[MainWindow] New Login shown, scheduling MainWindow deletion";
    
    // Capture 'this' as a QPointer for safe deletion check
    QPointer<MainWindow> self(this);
    
    // Use longer delay to ensure Login is fully initialized before deleting MainWindow
    QTimer::singleShot(200, qApp, [self](){
        if (self) {
            qDebug() << "[MainWindow] Deferred deletion executing";
            self->deleteLater();
        } else {
            qDebug() << "[MainWindow] Already deleted, skipping";
        }
    });
    
    // Restore quit behavior after deletion should complete
    QTimer::singleShot(500, qApp, [](){
        qApp->setQuitOnLastWindowClosed(true);
        qDebug() << "[MainWindow] Quit behavior restored";
    });
}

// =====================
//     NAVIGATION
// =====================
void MainWindow::showSClient()     { ui->stackedWidget->setCurrentIndex(0); }
void MainWindow::showCommande()    { ui->stackedWidget->setCurrentIndex(1); }
void MainWindow::showStock()       { ui->stackedWidget->setCurrentIndex(2); }
void MainWindow::showTransaction() { ui->stackedWidget->setCurrentIndex(3); }
void MainWindow::showEmployee()    { ui->stackedWidget->setCurrentIndex(4); }

// Public router for role-based UI entry
void MainWindow::openRoleTab(const QString &role)
{
    QString r = role.trimmed().toLower();
    // normalize common synonyms
    if (r.isEmpty()) {
        showSClient();
        return;
    }

    if (r == "client" || r == "customer") {
        showSClient();
        return;
    }

    if (r == "commande" || r == "order" || r == "orders" || r == "commands" || r == "sales") {
        showCommande();
        return;
    }

    if (r == "stock" || r == "inventory") {
        showStock();
        return;
    }

    if (r == "transaction" || r == "accounting" || r == "finance") {
        showTransaction();
        return;
    }

    if (r == "employe" || r == "employee" || r == "employé" || r == "admin" || r == "administrator" || r == "manager") {
        showEmployee();
        return;
    }

    // default to clients if unknown
    showSClient();
}

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
    // Update payments-per-method bar chart
    populatePaymentMethodChart();
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
    populatePaymentMethodChart();
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
    populatePaymentMethodChart();
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

void MainWindow::populatePaymentMethodChart()
{
    if (!ui || !ui->label_38) return;

    // Remove old chart if present
    if (paymentMethodChartWidget) {
        paymentMethodChartWidget->setParent(nullptr);
        paymentMethodChartWidget->deleteLater();
        paymentMethodChartWidget = nullptr;
    }

    // Query DB for payment method counts
    QSqlQuery q;
    if (!q.exec("SELECT NVL(PAY_METHOD, '(null)') AS PM, COUNT(*) AS CNT FROM TAB_TRANS GROUP BY PAY_METHOD")) {
        qDebug() << "populatePaymentMethodChart query failed:" << q.lastError().text();
    }
    QMap<QString,int> counts;
    bool has = false;
    while (q.next()) {
        QString pm = q.value(0).toString();
        int cnt = q.value(1).toInt();
        if (cnt > 0) { counts[pm] = cnt; has = true; }
    }
    if (!has) counts.insert("No Data", 1);

    BarChartWidget *w = new BarChartWidget();
    w->setTitle("Payments per Method");
    w->setData(counts);

    QWidget *parent = ui->label_38->parentWidget();
    w->setParent(parent);
    w->setGeometry(ui->label_38->geometry());
    w->show();

    paymentMethodChartWidget = w;
    ui->label_38->hide();
}

void MainWindow::populateCityChart()
{
    if (!ui || !ui->chart_city) return;

    // Remove old chart view if exists
    if (cityChartViewWidget) {
        cityChartViewWidget->setParent(nullptr);
        cityChartViewWidget->deleteLater();
        cityChartViewWidget = nullptr;
    }

    // Aggregate addresses -> city heuristics
    QMap<QString,int> counts;
    const auto rows = client_dao::fetchAll();
    for (const auto &c : rows) {
        QString a = c.ADRESS.trimmed();
        QString city;
        if (a.isEmpty()) {
            city = "Unknown";
        } else if (a.contains(',')) {
            // take last comma-separated token as city
            QStringList parts = a.split(',');
            city = parts.last().trimmed();
        } else if (a.contains('-')) {
            QStringList parts = a.split('-');
            city = parts.last().trimmed();
        } else if (a.contains(' ')) {
            // fallback: take last word (may be city)
            QStringList parts = a.split(' ', Qt::SkipEmptyParts);
            city = parts.last().trimmed();
        } else {
            city = a;
        }

        if (city.isEmpty()) city = "Unknown";
        counts[city] = counts.value(city, 0) + 1;
    }

    if (counts.isEmpty()) {
        counts.insert("No Data", 1);
    }

    // Create pie chart widget and place it over the UI placeholder label
    PieChartWidget *chartWidget = new PieChartWidget();
    chartWidget->setTitle("Clients by City");
    chartWidget->setData(counts);

    QWidget *parent = ui->chart_city->parentWidget();
    chartWidget->setParent(parent);
    chartWidget->setGeometry(ui->chart_city->geometry());
    chartWidget->show();

    cityChartViewWidget = chartWidget;
    ui->chart_city->hide();
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
            QMessageBox::warning(this,"Duplicate","This SKU already exists.");
            return;
        }
        if (!article_dao::create(a)) {
            QMessageBox::critical(this,"Error","Insertion failed.");
            return;
        }
        QMessageBox::information(this,"Success","Article added.");
    } else {
        if (!article_dao::update(a)) {
            QMessageBox::critical(this,"Error","Update failed.");
            return;
        }
        QMessageBox::information(this,"Success","Article updated.");
    }
    refreshArticlesGrid();
    setFormMode(false);
}

void MainWindow::on_delete_2_clicked()
{
    const auto sel = ui->tab_Art->selectionModel()->selectedRows();
    if (sel.isEmpty()) {
        QMessageBox::information(this,"Deletion","Select a row.");
        return;
    }
    const int row = sel.first().row();
    bool ok=false; const int sku = ui->tab_Art->item(row,1)->text().toInt(&ok);
    if (!ok) return;

    if (QMessageBox::question(this,"Confirm",
                              QString("Delete item SKU %1 ?").arg(sku)) != QMessageBox::Yes) return;

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

void MainWindow::on_btn_pdf_clicked()
{
    const int threshold = 5; // Strictement < 5
    const auto rows = article_dao::fetchBelowStock(threshold);
    if (rows.isEmpty()) {
        QMessageBox::information(this, "Export PDF",
                                 "No items with STOCK < 5.");
        return;
    }

    const QString defaultName = QString("Articles_below_threshold_%1.pdf")
                                    .arg(QDate::currentDate().toString("yyyyMMdd"));
    const QString fileName = QFileDialog::getSaveFileName(
        this, "Save PDF", defaultName, "PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QString html;
    html += "<html><head><meta charset='utf-8'>"
            "<style>"
            "body { margin:0; background:#f5f5f5; "
            "       font-family:'DejaVu Sans', Arial, sans-serif; font-size:10pt; }"
            ".page { padding:30px 40px; }"
            ".header { display:flex; justify-content:space-between; "
            "           align-items:flex-end; margin-bottom:6px; }"
            ".title { font-size:22pt; font-weight:700; color:#111827; }"
            ".date  { font-size:10pt; color:#4b5563; }"
            ".subtitle { font-size:10pt; color:#6b7280; "
            "            margin-bottom:18px; padding-bottom:6px; "
            "            border-bottom:1px solid #e5e7eb; }"
            "table.data { border-collapse:collapse; width:100%; margin-top:6px; }"
            "table.data th { background:#111827; color:#ffffff; "
            "                padding:8px 10px; text-align:left; "
            "                font-size:9pt; border:none; }"
            "table.data td { padding:6px 10px; font-size:9pt; "
            "                border-bottom:1px solid #e5e7eb; }"
            "table.data tr:nth-child(even) { background:#f9fafb; }"
            "table.data tr:nth-child(odd)  { background:#ffffff; }"
            "td.num { text-align:right; }"
            ".badge-critical { background:#dc2626; color:#ffffff; "
            "                  padding:3px 8px; border-radius:999px; "
            "                  font-weight:bold; font-size:8.5pt; }"
            ".badge-warning  { background:#f97316; color:#ffffff; "
            "                  padding:3px 8px; border-radius:999px; "
            "                  font-weight:bold; font-size:8.5pt; }"
            "</style>"
            "</head><body>";

    html += "<div class='page'>";

    // En-tête moderne : titre à gauche, date à droite
    html += QString(
                "<div class='header'>"
                "  <div class='title'>Articles with stock lower than %1</div>"
                "  <div class='date'>Date : %2</div>"
                "</div>")
                .arg(threshold)
                .arg(QDate::currentDate().toString("dd/MM/yyyy"));

    html += "<div class='subtitle'>Auto-generated inventory alert report</div>";

    // Tableau des articles
    html += "<table class='data'><thead><tr>"
            "<th>SKU</th>"
            "<th>Name</th>"
            "<th>Category</th>"
            "<th>Brand</th>"
            "<th>Purchase</th>"
            "<th>Selling</th>"
            "<th>Stock</th>"
            "<th>Location</th>"
            "<th>Compatibility</th>"
            "</tr></thead><tbody>";

    for (const auto& a : rows) {
        QString stockClass = (a.STOCK <= 2) ? "badge-critical" : "badge-warning";

        html += "<tr>";
        html += QString("<td class='num'>%1</td>")
                    .arg(a.SKU);
        html += QString("<td>%1</td>")
                    .arg(a.NAME.toHtmlEscaped());
        html += QString("<td>%1</td>")
                    .arg(a.CATEGORY.toHtmlEscaped());
        html += QString("<td>%1</td>")
                    .arg(a.BRAND.toHtmlEscaped());
        html += QString("<td class='num'>%1</td>")
                    .arg(QString::number(a.PURCHASEPRICE, 'f', 2));
        html += QString("<td class='num'>%1</td>")
                    .arg(QString::number(a.SELLINGPRICE, 'f', 2));

        // Badge coloré pour le stock
        html += QString("<td class='num'><span class='%1'>%2</span></td>")
                    .arg(stockClass)
                    .arg(a.STOCK);

        html += QString("<td>%1</td>")
                    .arg(a.LOCATION.toHtmlEscaped());
        html += QString("<td>%1</td>")
                    .arg(a.COMPATIBILITY.toHtmlEscaped());
        html += "</tr>";
    }

    html += "</tbody></table></div></body></html>";

    QTextDocument doc;
    doc.setHtml(html);

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
#if QT_VERSION >= QT_VERSION_CHECK(5, 3, 0)
    printer.setPageSize(QPageSize(QPageSize::A4));
#else
    printer.setPaperSize(QPrinter::A4);
#endif
    printer.setPageMargins(QMarginsF(12, 12, 12, 12), QPageLayout::Millimeter);

    doc.print(&printer);

    QMessageBox::information(this, "Export PDF ", "PDF generated successfully!");
}
void MainWindow::on_btn_stats_clicked()
{
    buildStockStatsCharts();
}
void MainWindow::buildStockStatsCharts()
{
    const int threshold = 5;
    const int maxStockForRotation = 50;

    QSqlQuery q;
    if (!q.exec("SELECT NAME, STOCK FROM TAB_ART")) {
        QMessageBox::critical(this, "Error",
                              "Failed to load stock data:\n" + q.lastError().text());
        return;
    }

    QStringList articleNames;
    QVector<qreal> rotationRates;
    QVector<qreal> lowStockCounts;

    while (q.next()) {
        QString name = q.value(0).toString();
        int stock = q.value(1).toInt();

        articleNames << name;

        qreal rotation = 100.0 * (maxStockForRotation - stock) / maxStockForRotation;
        rotation = qBound<qreal>(0, rotation, 100);
        rotationRates << rotation;

        qreal deficit = (stock < threshold) ? (threshold - stock) : 0;
        lowStockCounts << deficit;
    }

    if (articleNames.isEmpty()) {
        QMessageBox::information(this, "Stock statistics",
                                 "No article found in TAB_ART.");
        return;
    }

    // DETRUIRE ANCIENS GRAPHES
    if (m_stockStatsViewLeft) { delete m_stockStatsViewLeft; m_stockStatsViewLeft = nullptr; }
    if (m_stockStatsViewRight) { delete m_stockStatsViewRight; m_stockStatsViewRight = nullptr; }

    // 1) GRAPH rotation stock
    QBarSet *setRotation = new QBarSet("Rotation");
    for (qreal v : rotationRates) *setRotation << v;

    QBarSeries *seriesRotation = new QBarSeries();
    seriesRotation->append(setRotation);

    QChart *chartRotation = new QChart();
    chartRotation->addSeries(seriesRotation);
    chartRotation->setTitle("Taux de rotation du stock");
    chartRotation->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX1 = new QBarCategoryAxis();
    axisX1->append(articleNames);
    chartRotation->addAxis(axisX1, Qt::AlignBottom);
    seriesRotation->attachAxis(axisX1);

    QValueAxis *axisY1 = new QValueAxis();
    axisY1->setRange(0, 100);
    chartRotation->addAxis(axisY1, Qt::AlignLeft);
    seriesRotation->attachAxis(axisY1);

    m_stockStatsViewLeft = new QChartView(chartRotation);
    m_stockStatsViewLeft->setRenderHint(QPainter::Antialiasing);

    // 2) GRAPH sous seuil
    QStringList lowNames;
    QVector<qreal> lowValues;
    for (int i = 0; i < articleNames.size(); ++i) {
        if (lowStockCounts[i] > 0) {
            lowNames << articleNames[i];
            lowValues << lowStockCounts[i];
        }
    }

    QChart *chartLow = new QChart();
    chartLow->setTitle(QString("Articles below the threshold (< %1)").arg(threshold));

    if (!lowNames.isEmpty()) {
        QBarSet *setLow = new QBarSet("Below threshold");
        for (qreal v : lowValues) *setLow << v;

        QBarSeries *seriesLow = new QBarSeries();
        seriesLow->append(setLow);
        chartLow->addSeries(seriesLow);

        QBarCategoryAxis *axisX2 = new QBarCategoryAxis();
        axisX2->append(lowNames);
        chartLow->addAxis(axisX2, Qt::AlignBottom);
        seriesLow->attachAxis(axisX2);

        QValueAxis *axisY2 = new QValueAxis();
        axisY2->setRange(0, *std::max_element(lowValues.begin(), lowValues.end()));
        chartLow->addAxis(axisY2, Qt::AlignLeft);
        seriesLow->attachAxis(axisY2);

    } else {
        // Aucun sous seuil
        chartLow->setTitle("No Articles below the threshold");
    }

    m_stockStatsViewRight = new QChartView(chartLow);
    m_stockStatsViewRight->setRenderHint(QPainter::Antialiasing);

    // AJOUT DANS L’UI
    if (auto *old = ui->stockStatsContainer->layout()) {
        QLayoutItem *item;
        while ((item = old->takeAt(0))) {
            delete item->widget();
            delete item;
        }
        delete old;
    }

    QHBoxLayout *layout = new QHBoxLayout(ui->stockStatsContainer);
    layout->addWidget(m_stockStatsViewLeft);
    layout->addWidget(m_stockStatsViewRight);
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

    // Update the total clients label (numC) if it exists
    if (ui->numC) {
        ui->numC->setText(QString::number(rows.size()));
        ui->numC->setAlignment(Qt::AlignCenter);
    }

    // Update city pie chart after refreshing clients grid
    populateCityChart();
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
    ui->e_status->setCurrentIndex(-1);               // ✅ QLineEdit, so use clear()

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
    // Delete Payment by id from lineEdit_18 OR by selected row / current editing selection
    int id = -1;
    bool ok = false;

    const QString typed = ui->lineEdit_18->text().trimmed();
    if (!typed.isEmpty()) {
        id = typed.toInt(&ok);
        if (!ok || id <= 0) {
            QMessageBox::warning(this, "Erreur", "ID invalide pour la suppression. Entrez un entier positif ou sélectionnez une ligne.");
            return;
        }
    } else {
        // Try selection from the transactions table
        QTableWidget *table = ui->tableWidget_4;
        if (table && table->selectionModel()) {
            const auto sel = table->selectionModel()->selectedRows();
            if (!sel.isEmpty()) {
                int row = sel.first().row();
                if (table->item(row, 0)) {
                    id = table->item(row, 0)->text().toInt(&ok);
                }
            }
        }
        // Fallback: if we are in editing mode (from clicking a row), use editingCode
        if ((!ok || id <= 0) && editing && editingCode > 0) {
            id = editingCode;
            ok = true;
        }

        if (!ok || id <= 0) {
            QMessageBox::warning(this, "Erreur", "Veuillez entrer un Payment_ID valide ou sélectionner une transaction.");
            return;
        }
    }

    // Confirm deletion with user
    if (QMessageBox::question(this, "Confirm",
                              QString("Delete transaction with IDT %1 ?").arg(id),
                              QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    Transaction t;
    if (t.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Transaction supprimée !");
        // clear possible inputs and editing state
        ui->lineEdit_18->clear();
        clearTransactionFields();
        editing = false;
        editingCode = -1;
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
    QString status   = ui->e_status->currentText().trimmed();

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
}

void MainWindow::on_pushButton_6_clicked()
{
    qDebug() << "on_pushButton_6_clicked invoked";
    // Export selected rows from clients table (ui->tab_Client) to PDF
    QTableWidget *table = ui->tab_Client;
    if (!table) return;

    QList<int> rowsToExport;
    // Collect unique selected rows
    for (const QTableWidgetSelectionRange &range : table->selectedRanges()) {
        for (int r = range.topRow(); r <= range.bottomRow(); ++r) {
            if (!rowsToExport.contains(r)) rowsToExport.append(r);
        }
    }

    if (rowsToExport.isEmpty()) {
        QMessageBox::information(this, "Export PDF", "No rows selected. Please select at least one row.");
        return;
    }

    QString filePath = QFileDialog::getSaveFileName(this, "Exporter les clients sélectionnés en PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty()) return;

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
    const int margin = 40;
    int y = margin;

    // Modern header: colored band with logo, title and date
    const QColor primary(44,130,201); // app blue
    const int bandHeight = 84;
    int contentWidth = pageWidth - 2 * margin;

    // Draw band inside the page margins to avoid clipping
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing);
    QRect bandRect(margin, y, contentWidth, bandHeight);
    painter.fillRect(bandRect, primary);

    // Logo on the left inside the band
    QPixmap logo(":/images/ressource/logo.jpeg");
    if (!logo.isNull()) {
        QRect logoRect(bandRect.left() + 8, bandRect.top() + 8, 68, 68);
        painter.drawPixmap(logoRect, logo.scaled(68, 68, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    // Title centered inside band
    QFont titleFont("Helvetica", 18, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(Qt::white);
    QRect titleRect(bandRect.left() + 96, bandRect.top() + 18, bandRect.width() - 192, 36);
    painter.drawText(titleRect, Qt::AlignCenter, "Liste des clients sélectionnés");

    // Date on the right inside the band
    painter.setFont(QFont("Helvetica", 9));
    QRect dateRect(bandRect.right() - 160, bandRect.top() + 18, 152, 20);
    painter.drawText(dateRect, Qt::AlignRight | Qt::AlignVCenter, QDate::currentDate().toString("dd/MM/yyyy"));
    painter.restore();

    y += bandHeight + 18;

    // Summary card: total selected
    int totalSelected = rowsToExport.size();
    QRect cardRect(margin, y, 220, 80);
    painter.setBrush(QColor(235,245,252));
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(cardRect, 6, 6);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Helvetica", 22, QFont::Bold));
    painter.drawText(QRect(cardRect.left()+12, cardRect.top()+8, cardRect.width()-24, 36), Qt::AlignLeft | Qt::AlignVCenter, QString::number(totalSelected));
    painter.setFont(QFont("Helvetica", 9));
    painter.drawText(QRect(cardRect.left()+12, cardRect.top()+44, cardRect.width()-24, 20), Qt::AlignLeft | Qt::AlignVCenter, "Total selected clients");

    // Prepare columns to export (skip empty header columns, e.g., action column 0)
    QVector<int> cols;
    int totalCols = table->columnCount();
    for (int c = 0; c < totalCols; ++c) {
        QTableWidgetItem *hi = table->horizontalHeaderItem(c);
        QString h = hi ? hi->text().trimmed() : QString();
        if (h.isEmpty()) continue; // skip action/empty columns
        cols.append(c);
    }

    if (cols.isEmpty()) {
        QMessageBox::warning(this, "Export PDF", "No printable columns found.");
        painter.end();
        return;
    }

    // Column widths: proportional by header length and content
    QFont bodyFont("Helvetica", 10);
    painter.setFont(bodyFont);
    QFontMetrics metrics(bodyFont);
    QVector<int> colWidths;
    colWidths.resize(cols.size());
    int availableWidth = pageWidth - 2 * margin;

    for (int i = 0; i < cols.size(); ++i) {
        int c = cols[i];
        QTableWidgetItem *hi = table->horizontalHeaderItem(c);
        int maxW = metrics.horizontalAdvance(hi ? hi->text() : QString("col%1").arg(c));
        for (int r : rowsToExport) {
            QTableWidgetItem *it = table->item(r, c);
            if (it) maxW = qMax(maxW, metrics.horizontalAdvance(it->text()));
        }
        colWidths[i] = maxW + 24;
    }

    int totalWidth = std::accumulate(colWidths.begin(), colWidths.end(), 0);
    if (totalWidth > availableWidth) {
        double ratio = (double)availableWidth / totalWidth;
        for (int &w : colWidths) w = int(w * ratio);
    }

    // Table header + rows (clean, simple layout)
    int x = margin;
    y += 100; // space below summary card
    int rowHeight = 34;

    painter.setRenderHint(QPainter::Antialiasing);
    // Header background
    painter.setBrush(primary.darker(110));
    painter.setPen(Qt::NoPen);
    painter.drawRect(margin, y, availableWidth, rowHeight);

    // Header texts
    painter.setFont(QFont("Helvetica", 10, QFont::Bold));
    painter.setPen(Qt::white);
    x = margin;
    for (int i = 0; i < cols.size(); ++i) {
        QString header = table->horizontalHeaderItem(cols[i])->text();
        QRect cellRect(x + 8, y, colWidths[i] - 16, rowHeight);
        painter.drawText(cellRect, Qt::AlignLeft | Qt::AlignVCenter, header);
        x += colWidths[i];
    }

    // Separator under header
    painter.setPen(QPen(QColor(200,200,200), 1));
    painter.drawLine(margin, y + rowHeight, margin + availableWidth, y + rowHeight);
    y += rowHeight + 6;

    // Rows
    painter.setFont(bodyFont);
    for (int rowIdx = 0; rowIdx < rowsToExport.size(); ++rowIdx) {
        int row = rowsToExport.at(rowIdx);
        if (y + rowHeight > pageHeight - margin - 40) {
            pdfWriter.newPage();

            // redraw the top band on the new page to keep visual continuity
            painter.save();
            painter.setRenderHint(QPainter::Antialiasing);
            QRect newBand(bandRect.left(), margin, bandRect.width(), bandRect.height());
            painter.fillRect(newBand, primary);
            // logo
            if (!logo.isNull()) {
                QRect logoRect(newBand.left() + 8, newBand.top() + 8, 68, 68);
                painter.drawPixmap(logoRect, logo.scaled(68, 68, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            }
            painter.setFont(titleFont);
            painter.setPen(Qt::white);
            QRect newTitleRect(newBand.left() + 96, newBand.top() + 18, newBand.width() - 192, 36);
            painter.drawText(newTitleRect, Qt::AlignCenter, "Liste des clients sélectionnés");
            painter.setFont(QFont("Helvetica", 9));
            QRect newDateRect(newBand.right() - 160, newBand.top() + 18, 152, 20);
            painter.drawText(newDateRect, Qt::AlignRight | Qt::AlignVCenter, QDate::currentDate().toString("dd/MM/yyyy"));
            painter.restore();

            y = margin + bandHeight + 18; // position after redrawn band

            // redraw table header on new page
            painter.setBrush(primary.darker(110));
            painter.setPen(Qt::NoPen);
            painter.drawRect(margin, y, availableWidth, rowHeight);
            painter.setFont(QFont("Helvetica", 10, QFont::Bold));
            painter.setPen(Qt::white);
            x = margin;
            for (int i = 0; i < cols.size(); ++i) {
                QString header = table->horizontalHeaderItem(cols[i])->text();
                QRect cellRect(x + 8, y, colWidths[i] - 16, rowHeight);
                painter.drawText(cellRect, Qt::AlignLeft | Qt::AlignVCenter, header);
                x += colWidths[i];
            }
            painter.setPen(QPen(QColor(200,200,200), 1));
            painter.drawLine(margin, y + rowHeight, margin + availableWidth, y + rowHeight);
            y += rowHeight + 6;
            painter.setFont(bodyFont);
            painter.setPen(Qt::black);
        }

        // alternating background
        if (rowIdx % 2 == 0) {
            painter.fillRect(QRect(margin, y, availableWidth, rowHeight), QColor(250,250,250));
        }

        x = margin;
        painter.setPen(Qt::black);
        for (int cIdx = 0; cIdx < cols.size(); ++cIdx) {
            int c = cols[cIdx];
            QString text = table->item(row, c) ? table->item(row, c)->text() : QString();
            QRect textRect(x + 8, y + 4, colWidths[cIdx] - 16, rowHeight - 8);
            painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter | Qt::TextWordWrap, text);
            // vertical separator
            painter.setPen(QPen(QColor(230,230,230), 1));
            painter.drawLine(x + colWidths[cIdx], y, x + colWidths[cIdx], y + rowHeight);
            painter.setPen(Qt::black);
            x += colWidths[cIdx];
        }
        y += rowHeight;
        // horizontal separator
        painter.setPen(QPen(QColor(240,240,240), 1));
        painter.drawLine(margin, y, margin + availableWidth, y);
    }

    // Footer centered
    painter.setFont(QFont("Helvetica", 9, QFont::StyleItalic));
    painter.setPen(QColor(120,120,120));
    painter.drawText(0, pageHeight - 40, pageWidth, 20, Qt::AlignCenter, "Document généré automatiquement par ESPRIT_SR");

    painter.end();
    QMessageBox::information(this, "Succès", "PDF exporté avec succès !");
}
void MainWindow::on_pushButton_8_clicked()
{
    // === 1) Get clients table ===
    QTableWidget *table = ui->tab_Client;
    if (!table) {
        QMessageBox::warning(this, "Export PDF", "Clients table not found.");
        return;
    }

    // === 2) Collect selected rows ===
    QList<int> rowsToExport;
    for (const QTableWidgetSelectionRange &range : table->selectedRanges()) {
        for (int r = range.topRow(); r <= range.bottomRow(); ++r) {
            if (!rowsToExport.contains(r))
                rowsToExport.append(r);
        }
    }

    if (rowsToExport.isEmpty()) {
        QMessageBox::information(this, "Export PDF",
                                 "No rows selected. Please select at least one client.");
        return;
    }

    // === 3) Ask output file name ===
    const QString defaultName = QString("Selected_clients_%1.pdf")
                                    .arg(QDate::currentDate().toString("yyyyMMdd"));
    const QString fileName = QFileDialog::getSaveFileName(
        this, "Save PDF", defaultName, "PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    // === 4) Build HTML with SAME STYLESHEET as on_btn_pdf_clicked ===
    QString html;
    html += "<html><head><meta charset='utf-8'>"
            "<style>"
            "body { margin:0; background:#f5f5f5; "
            "       font-family:'DejaVu Sans', Arial, sans-serif; font-size:10pt; }"
            ".page { padding:30px 40px; }"
            ".header { display:flex; justify-content:space-between; "
            "           align-items:flex-end; margin-bottom:6px; }"
            ".title { font-size:22pt; font-weight:700; color:#111827; }"
            ".date  { font-size:10pt; color:#4b5563; }"
            ".subtitle { font-size:10pt; color:#6b7280; "
            "            margin-bottom:18px; padding-bottom:6px; "
            "            border-bottom:1px solid #e5e7eb; }"
            "table.data { border-collapse:collapse; width:100%; margin-top:6px; }"
            "table.data th { background:#111827; color:#ffffff; "
            "                padding:8px 10px; text-align:left; "
            "                font-size:9pt; border:none; }"
            "table.data td { padding:6px 10px; font-size:9pt; "
            "                border-bottom:1px solid #e5e7eb; }"
            "table.data tr:nth-child(even) { background:#f9fafb; }"
            "table.data tr:nth-child(odd)  { background:#ffffff; }"
            "td.num { text-align:right; }"
            "</style>"
            "</head><body>";

    html += "<div class='page'>";

    // Header: title + date
    html += QString(
                "<div class='header'>"
                "  <div class='title'>Selected clients</div>"
                "  <div class='date'>Date : %1</div>"
                "</div>")
                .arg(QDate::currentDate().toString("dd/MM/yyyy"));

    html += "<div class='subtitle'>Auto-generated client export report</div>";

    // Clients table
    html += "<table class='data'><thead><tr>"
            "<th>CIN</th>"
            "<th>First name</th>"
            "<th>Last name</th>"
            "<th>Email</th>"
            "<th>Phone</th>"
            "<th>Adress</th>"
            "</tr></thead><tbody>";

    std::sort(rowsToExport.begin(), rowsToExport.end());
    for (int row : rowsToExport) {
        if (row < 0 || row >= table->rowCount()) continue;

        QTableWidgetItem *cinItem   = table->item(row, 1);
        QTableWidgetItem *fnItem    = table->item(row, 2);
        QTableWidgetItem *lnItem    = table->item(row, 3);
        QTableWidgetItem *emItem    = table->item(row, 4);
        QTableWidgetItem *phItem    = table->item(row, 5);
        QTableWidgetItem *adItem    = table->item(row, 6);

        const QString cin    = cinItem ? cinItem->text().toHtmlEscaped() : "";
        const QString fname  = fnItem  ? fnItem->text().toHtmlEscaped()  : "";
        const QString lname  = lnItem  ? lnItem->text().toHtmlEscaped()  : "";
        const QString email  = emItem  ? emItem->text().toHtmlEscaped()  : "";
        const QString phone  = phItem  ? phItem->text().toHtmlEscaped()  : "";
        const QString adress = adItem  ? adItem->text().toHtmlEscaped()  : "";

        html += "<tr>";
        html += QString("<td>%1</td>").arg(cin);
        html += QString("<td>%1</td>").arg(fname);
        html += QString("<td>%1</td>").arg(lname);
        html += QString("<td>%1</td>").arg(email);
        html += QString("<td class='num'>%1</td>").arg(phone);
        html += QString("<td>%1</td>").arg(adress);
        html += "</tr>";
    }

    html += "</tbody></table>";

    // === MUCH SMALLER QR (25x25), UNDER table, CENTERED ===
    html += "<div style='margin-top:14px; text-align:center;'>"
            "<img src='qr1' style='width:50px; height:50px;'/>"
            "</div>";

    html += "</div></body></html>";

    // === 5) Build document & attach QR image ===
    QTextDocument doc;

    // Load QR image
    QImage qrImg(":/images/ressource/qr1.jpg");  // adjust path if needed
    if (!qrImg.isNull()) {
        doc.addResource(QTextDocument::ImageResource, QUrl("qr1"), qrImg);
    }

    doc.setHtml(html);

    // === 6) Print to PDF ===
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
#if QT_VERSION >= QT_VERSION_CHECK(5, 3, 0)
    printer.setPageSize(QPageSize(QPageSize::A4));
#else
    printer.setPaperSize(QPrinter::A4);
#endif
    printer.setPageMargins(QMarginsF(12, 12, 12, 12), QPageLayout::Millimeter);

    doc.print(&printer);

    QMessageBox::information(this, "Export PDF", "PDF generated successfully!");
}
