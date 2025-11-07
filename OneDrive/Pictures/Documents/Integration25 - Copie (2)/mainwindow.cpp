#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHeaderView>
#include <QAbstractItemView>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QIcon>
#include <QTableWidgetItem>
#include <QFile>
#include <QDebug>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QRegularExpression>
#include <QSignalBlocker>

// ✅ EXPORT PDF
#include <QFileDialog>
#include <QDateTime>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QMarginsF>
// ✅ Qt6: tailles/marges de page
#include <QPageSize>
#include <QPageLayout>

// =====================
//      CONSTRUCTEUR
// =====================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ----- MENU -----
    connect(ui->btn_Client,      &QPushButton::clicked, this, &MainWindow::showSClient);
    connect(ui->btn_Commande,    &QPushButton::clicked, this, &MainWindow::showCommande);
    connect(ui->btn_Stock,       &QPushButton::clicked, this, &MainWindow::showStock);
    connect(ui->btn_Transaction, &QPushButton::clicked, this, &MainWindow::showTransaction);
    connect(ui->btn_Employee,    &QPushButton::clicked, this, &MainWindow::showEmployee);

    // ----- ARTICLES -----
    setupTabArt();
    refreshArticlesGrid();

    // Bouton Export PDF sous seuil (si pas d’auto-connexion par nom)
    if (ui->exportUnderThreshold) {
        connect(ui->exportUnderThreshold, &QPushButton::clicked,
                this, &MainWindow::on_exportUnderThreshold_clicked);
    }

    // ----- CLIENTS -----
    connect(ui->btn_Client, &QPushButton::clicked, this, [this]() {
        if (!m_clientTableInit) { setupTabClient(); m_clientTableInit = true; }
        refreshClientsGrid();
    });

    // Page d’accueil
    ui->stackedWidget->setCurrentIndex(0);

    // =============== CONTRÔLE DE SAISIE NUMÉRIQUE (UI live) ===============
    auto setupLiveNumericGuard = [this](QLineEdit* le, bool isInteger) {
        le->setProperty("lastValid", le->text());

        QObject::connect(le, &QLineEdit::textChanged, this, [le, isInteger](const QString& txt){
            static QRegularExpression reInt(R"(^\d*$)");
            static QRegularExpression reDec(R"(^\d*([.]\d{0,2})?$)");

            const bool ok = isInteger ? reInt.match(txt).hasMatch()
                                      : reDec.match(txt).hasMatch();

            if (ok) {
                le->setProperty("lastValid", txt);
            } else {
                const QString last = le->property("lastValid").toString();
                QMessageBox::warning(le, "Erreur de saisie",
                                     isInteger
                                         ? "Ce champ accepte uniquement des chiffres (entiers)."
                                         : "Ce champ accepte uniquement des nombres (ex : 12 ou 12.34).");
                const QSignalBlocker guard(le);
                le->setText(last);
                le->setCursorPosition(le->text().size());
            }
        });
    };

    setupLiveNumericGuard(ui->price1, /*isInteger=*/false);
    setupLiveNumericGuard(ui->price2, /*isInteger=*/false);
    setupLiveNumericGuard(ui->stock , /*isInteger=*/true);
    // ======================================================================
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

    const auto rows = ArticleDAO::fetchAll();
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

// ===============================
//  CONFIRM : ADD / UPDATE
// ===============================
void MainWindow::on_confirm_clicked()
{
    // --- Contrôles de saisie stricts AVANT conversions ---
    const QString skuT   = ui->sku->text().trimmed();
    const QString nameT  = ui->name->text().trimmed();
    const QString catT   = ui->cat->text().trimmed();
    const QString brandT = ui->brand->currentText().trimmed();
    const QString p1T    = ui->price1->text().trimmed();
    const QString p2T    = ui->price2->text().trimmed();
    const QString stockT = ui->stock->text().trimmed();
    const QString locT   = ui->loca->text().trimmed();
    const QString compT  = ui->com->text().trimmed();

    static const QRegularExpression reInt(R"(^\d+$)");
    static const QRegularExpression reDec(R"(^\d+(\.\d+)?$)");

    if (skuT.isEmpty() || nameT.isEmpty() || catT.isEmpty() || brandT.isEmpty()
        || p1T.isEmpty() || p2T.isEmpty() || stockT.isEmpty()
        || locT.isEmpty() || compT.isEmpty()) {
        QMessageBox::warning(this, "Validation","Tous les champs sont obligatoires.");
        return;
    }
    if (!reInt.match(skuT).hasMatch())  { QMessageBox::warning(this,"Validation","SKU doit être un entier positif."); ui->sku->setFocus(); return; }
    if (!reDec.match(p1T).hasMatch())   { QMessageBox::warning(this,"Validation","Purchase Price doit être un nombre (ex : 12 ou 12.50)."); return; }
    if (!reDec.match(p2T).hasMatch())   { QMessageBox::warning(this,"Validation","Selling Price doit être un nombre (ex : 12 ou 12.50).");  return; }
    if (!reInt.match(stockT).hasMatch()){ QMessageBox::warning(this,"Validation","Stock doit être un entier positif."); ui->stock->setFocus(); return; }

    // Conversions sûres
    Article a;
    a.SKU           = skuT.toInt();
    a.NAME          = nameT;
    a.CATEGORY      = catT;
    a.BRAND         = brandT;
    a.PURCHASEPRICE = p1T.toDouble();
    a.SELLINGPRICE  = p2T.toDouble();
    a.STOCK         = stockT.toInt();
    a.LOCATION      = locT;
    a.COMPATIBILITY = compT;

    // Exécution
    if (!m_isEditMode) {
        if (ArticleDAO::exists(a.SKU)) {
            QMessageBox::warning(this,"Doublon","Ce SKU existe déjà.");
            return;
        }
        if (!ArticleDAO::create(a)) {
            QMessageBox::critical(this,"Erreur","Insertion échouée.");
            return;
        }
        QMessageBox::information(this,"Succès","Article ajouté.");
    } else {
        if (!ArticleDAO::update(a)) {
            QMessageBox::critical(this,"Erreur","Mise à jour échouée.");
            return;
        }
        QMessageBox::information(this,"Succès","Article mis à jour.");
    }

    refreshArticlesGrid();
    setFormMode(false);
}

void MainWindow::on_delete_clicked()
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

    if (ArticleDAO::remove(sku))
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

    if (ArticleDAO::remove(sku)) refreshArticlesGrid();
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
        ui->brand->clear(); ui->price2->clear(); ui->stock->clear();
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

void MainWindow::addActionButtonsForRow(int row)
{
    auto *editBtn = new QPushButton;
    editBtn->setToolTip("Edit");
    editBtn->setFlat(true);
    editBtn->setCursor(Qt::PointingHandCursor);
    const char* kPenPath = ":/images/ressource/edit.png";
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

// =================== EXPORT PDF SOUS SEUIL ===================
void MainWindow::on_exportUnderThreshold_clicked()
{
    const int threshold = 5; // STOCK < 5

    // 1) Charger les articles sous seuil
    const auto rows = ArticleDAO::fetchBelowStock(threshold);
    if (rows.isEmpty()) {
        QMessageBox::information(this, "Export PDF",
                                 "Aucun article avec STOCK < 5.");
        return;
    }

    // 2) Choisir le fichier de sortie
    const QString defaultName = QString("Articles_sous_seuil_%1.pdf")
                                    .arg(QDate::currentDate().toString("yyyyMMdd"));
    const QString fileName = QFileDialog::getSaveFileName(
        this, "Enregistrer le PDF", defaultName, "PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    // 3) Construire le HTML (uniquement les sous-seuil)
    QString html;
    html += "<html><head><meta charset='utf-8'>"
            "<style>"
            "body { font-family: DejaVu Sans, Arial, sans-serif; font-size:10pt; }"
            "h1 { font-size:14pt; }"
            "table { border-collapse: collapse; width:100%; }"
            "th, td { border:1px solid #333; padding:6px 8px; }"
            "th { background:#f0f0f0; }"
            "td.num { text-align:right; }"
            "</style>"
            "</head><body>";

    html += QString("<h1>Articles avec STOCK &lt; %1 — %2</h1>")
                .arg(threshold)
                .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm"));

    html += "<table><thead><tr>"
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
        html += QString("<tr>"
                        "<td class='num'>%1</td>"
                        "<td>%2</td>"
                        "<td>%3</td>"
                        "<td>%4</td>"
                        "<td class='num'>%5</td>"
                        "<td class='num'>%6</td>"
                        "<td class='num' style='font-weight:bold;color:#c0392b;'>%7</td>"
                        "<td>%8</td>"
                        "<td>%9</td>"
                        "</tr>")
                    .arg(a.SKU)
                    .arg(a.NAME.toHtmlEscaped())
                    .arg(a.CATEGORY.toHtmlEscaped())
                    .arg(a.BRAND.toHtmlEscaped())
                    .arg(QString::number(a.PURCHASEPRICE, 'f', 2))
                    .arg(QString::number(a.SELLINGPRICE, 'f', 2))
                    .arg(a.STOCK)
                    .arg(a.LOCATION.toHtmlEscaped())
                    .arg(a.COMPATIBILITY.toHtmlEscaped());
    }

    html += "</tbody></table></body></html>";

    // 4) Impression PDF (Qt6 OK)
    QTextDocument doc;
    doc.setHtml(html);

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setFullPage(false);
    printer.setOutputFileName(fileName);

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(12, 12, 12, 12), QPageLayout::Millimeter);
#else
    printer.setPaperSize(QPrinter::A4);
    printer.setPageMargins(12, 12, 12, 12, QPrinter::Millimeter);
#endif

    doc.print(&printer);

    QMessageBox::information(this, "Export PDF", "PDF généré avec succès !");
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
    const auto rows = ClientDAO::fetchAll();
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
        if (ClientDAO::exists(c.CIN)) {
            QMessageBox::warning(this,"Doublon","CIN existe déjà.");
            return;
        }
        if (!ClientDAO::create(c)) {
            QMessageBox::critical(this,"Erreur","Ajout échoué.");
            return;
        }
        QMessageBox::information(this,"Succès","Client ajouté.");
    } else {
        if (!ClientDAO::update(c)) {
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
    if (ClientDAO::remove(cin)) refreshClientsGrid();
}

void MainWindow::on_c_DEL_clicked()
{
    QString cin = ui->c_Line_rech->text().trimmed();
    if (cin.isEmpty()) return;
    if (QMessageBox::question(this,"Confirmer",
                              QString("Supprimer le client %1 ?").arg(cin)) != QMessageBox::Yes) return;
    if (ClientDAO::remove(cin)) refreshClientsGrid();
    ui->c_Line_rech->clear();
}

void MainWindow::on_tab_Art_cellChanged(int, int) { }
