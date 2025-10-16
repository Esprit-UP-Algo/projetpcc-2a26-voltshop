#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isEditMode(false)
    , currentEditRow(-1)
{
    ui->setupUi(this);

    // ====== TON CODE D’IMAGES CONSERVÉ TEL QUEL ======
    QPixmap pix_logo("C:/Users/msi/Documents/gestionclient/assests/logo.jpeg");
    ui->logo->setPixmap(pix_logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->logo2->setPixmap(pix_logo.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap pix_stat("C:/Users/msi/Documents/gestionclient/assests/stat.png");
    ui->stat->setPixmap(pix_stat.scaled(700,700,Qt::KeepAspectRatio));
    QPixmap pix_PDF("C:/Users/msi/Documents/gestionclient/assests/PDF.png");
    ui->PDF->setPixmap(pix_PDF.scaled(90,90,Qt::KeepAspectRatio));
    // ==================================================

    // ✅ AJOUTS : préparer le tableau et charger depuis Oracle
    setupClientsTableWidget();
    loadClientsFromDatabase();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quit_clicked()
{
    close();
}

// Helper function to populate form fields with table data
void MainWindow::populateFormFromTableRow(int row)
{
    // Get data from the table widget for the specified row
    QTableWidgetItem* cinItem       = ui->tableWidget->item(row, 0); // CIN column
    QTableWidgetItem* firstNameItem = ui->tableWidget->item(row, 1); // First Name column
    QTableWidgetItem* lastNameItem  = ui->tableWidget->item(row, 2); // Last Name column
    QTableWidgetItem* emailItem     = ui->tableWidget->item(row, 3); // Email column
    QTableWidgetItem* addressItem   = ui->tableWidget->item(row, 4); // Address column
    QTableWidgetItem* phoneItem     = ui->tableWidget->item(row, 5); // Phone column

    // Populate the form fields with the table data (handle null items safely)
    ui->lineEdit->setText(  cinItem       ? cinItem->text()       : "" ); // CIN field
    ui->lineEdit_6->setText(firstNameItem ? firstNameItem->text() : "" ); // First Name field
    ui->lineEdit_2->setText(lastNameItem  ? lastNameItem->text()  : "" ); // Last Name field
    ui->lineEdit_3->setText(emailItem     ? emailItem->text()     : "" ); // Email field
    ui->lineEdit_5->setText(addressItem   ? addressItem->text()   : "" ); // Address field
    ui->lineEdit_4->setText(phoneItem     ? phoneItem->text()     : "" ); // Phone number field

    // Set edit mode
    isEditMode = true;
    currentEditRow = row;

    // Change button text to indicate edit mode
    ui->pushButton->setText("Update Client");

    // Change the styling to indicate edit mode
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "font: 900 9pt \"Swis721 Blk BT\";"
        "background-color: #FF6B35;" // Orange color for edit mode
        "color: white;"
        "border-radius: 6px;"
        "padding: 6px 12px;"
        "}"
        "QPushButton:hover { background-color: #E55A2B; }"
        "QPushButton:pressed { background-color: #CC4125; }"
        );
}

// Edit button handlers for each row
void MainWindow::on_pushButton_10_clicked() { populateFormFromTableRow(0); } // Row 0 edit button
void MainWindow::on_pushButton_14_clicked() { populateFormFromTableRow(1); } // Row 1 edit button
void MainWindow::on_pushButton_11_clicked() { populateFormFromTableRow(2); } // Row 2 edit button
void MainWindow::on_pushButton_13_clicked() { populateFormFromTableRow(3); } // Row 3 edit button
void MainWindow::on_pushButton_12_clicked() { populateFormFromTableRow(4); } // Row 4 edit button
void MainWindow::on_pushButton_15_clicked() { populateFormFromTableRow(5); } // Row 5 edit button

// Helper function to reset form back to add mode
void MainWindow::resetFormToAddMode()
{
    // Clear all form fields
    ui->lineEdit->clear();      // CIN field
    ui->lineEdit_6->clear();    // First Name field
    ui->lineEdit_2->clear();    // Last Name field
    ui->lineEdit_3->clear();    // Email field
    ui->lineEdit_4->clear();    // Phone field
    ui->lineEdit_5->clear();    // Address field

    // Reset edit mode flags
    isEditMode = false;
    currentEditRow = -1;

    // Reset button text and styling back to normal
    ui->pushButton->setText("Add Client");
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "font: 900 9pt \"Swis721 Blk BT\";"
        "background-color: #003271;"
        "color: white;"
        "border-radius: 6px;"
        "padding: 6px 12px;"
        "}"
        "QPushButton:hover { background-color: #004599; }"
        "QPushButton:pressed { background-color: #002050; }"
        );
}

// Cancel button handler
void MainWindow::on_pushButton_3_clicked()
{
    resetFormToAddMode(); // Reset form when cancel is pressed
}

/* ============================
 *    AJOUTS : Oracle + Table
 * ============================ */

void MainWindow::setupClientsTableWidget()
{
    // 6 colonnes (ordre aligné avec populateFormFromTableRow)
    ui->tableWidget->setColumnCount(6);
    QStringList headers { "CIN", "First Name", "Last Name", "Email", "Address", "Phone" };
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // lecture seule
}

void MainWindow::loadClientsFromDatabase()
{
    ui->tableWidget->setRowCount(0);

    // ⚠️ La connexion Oracle QODBC doit être ouverte (createConnection() dans main.cpp)
    QSqlQuery q;
    const char* sql =
        "SELECT CIN, FIRSTNAME, LASTNAME, EMAIL, ADDRESS, PHONE "
        "FROM CLIENTS "
        "ORDER BY CIN";
    if (!q.exec(sql)) {
        QMessageBox::critical(this, "Erreur SELECT", q.lastError().text());
        return;
    }

    int r = 0;
    while (q.next()) {
        ui->tableWidget->insertRow(r);
        for (int c = 0; c < 6; ++c) {
            ui->tableWidget->setItem(r, c, new QTableWidgetItem(q.value(c).toString()));
        }
        ++r;
    }
}

bool MainWindow::insertClientToDatabase(const QString& cinVal,
                                        const QString& firstName,
                                        const QString& lastName,
                                        const QString& email,
                                        const QString& address,
                                        const QString& phone)
{
    QSqlQuery q;
    q.prepare(R"(
        INSERT INTO CLIENTS (CIN, FIRSTNAME, LASTNAME, EMAIL, ADDRESS, PHONE)
        VALUES (:cin, :fn, :ln, :em, :ad, :ph)
    )");
    q.bindValue(":cin", cinVal);
    q.bindValue(":fn",  firstName);
    q.bindValue(":ln",  lastName);
    q.bindValue(":em",  email);
    q.bindValue(":ad",  address);
    q.bindValue(":ph",  phone);

    auto db = QSqlDatabase::database();
    db.transaction();
    if (!q.exec()) {
        db.rollback();
        QMessageBox::critical(this, "Erreur INSERT", q.lastError().text());
        return false;
    }
    db.commit();
    return true;
}

bool MainWindow::updateClientInDatabase(const QString& cinVal,
                                        const QString& firstName,
                                        const QString& lastName,
                                        const QString& email,
                                        const QString& address,
                                        const QString& phone)
{
    QSqlQuery q;
    q.prepare(R"(
        UPDATE CLIENTS
           SET FIRSTNAME = :fn,
               LASTNAME  = :ln,
               EMAIL     = :em,
               ADDRESS   = :ad,
               PHONE     = :ph
         WHERE CIN       = :cin
    )");
    q.bindValue(":fn",  firstName);
    q.bindValue(":ln",  lastName);
    q.bindValue(":em",  email);
    q.bindValue(":ad",  address);
    q.bindValue(":ph",  phone);
    q.bindValue(":cin", cinVal);

    auto db = QSqlDatabase::database();
    db.transaction();
    if (!q.exec()) {
        db.rollback();
        QMessageBox::critical(this, "Erreur UPDATE", q.lastError().text());
        return false;
    }
    db.commit();
    return true;
}

/* =========================================
 *  Bouton principal (Add / Update) — AJOUT
 *  (Nom du slot conservé : on_pushButton_clicked)
 * ========================================= */
void MainWindow::on_pushButton_clicked()
{
    // Utilise tes objectName d’origine
    const QString cinVal    = ui->lineEdit->text().trimmed();   // CIN
    const QString firstName = ui->lineEdit_6->text().trimmed(); // First Name
    const QString lastName  = ui->lineEdit_2->text().trimmed(); // Last Name
    const QString email     = ui->lineEdit_3->text().trimmed(); // Email
    const QString address   = ui->lineEdit_5->text().trimmed(); // Address
    const QString phone     = ui->lineEdit_4->text().trimmed(); // Phone

    if (cinVal.isEmpty()) {
        QMessageBox::warning(this, "Validation", "CIN est obligatoire (clé primaire).");
        ui->lineEdit->setFocus();
        return;
    }

    if (!isEditMode) {
        // === MODE AJOUT ===
        if (!insertClientToDatabase(cinVal, firstName, lastName, email, address, phone))
            return;

        // Ajout visuel immédiat
        const int r = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(r);
        ui->tableWidget->setItem(r, 0, new QTableWidgetItem(cinVal));
        ui->tableWidget->setItem(r, 1, new QTableWidgetItem(firstName));
        ui->tableWidget->setItem(r, 2, new QTableWidgetItem(lastName));
        ui->tableWidget->setItem(r, 3, new QTableWidgetItem(email));
        ui->tableWidget->setItem(r, 4, new QTableWidgetItem(address));
        ui->tableWidget->setItem(r, 5, new QTableWidgetItem(phone));

        QMessageBox::information(this, "Succès", "Client ajouté.");
        resetFormToAddMode();
    } else {
        // === MODE ÉDITION ===
        if (!updateClientInDatabase(cinVal, firstName, lastName, email, address, phone))
            return;

        // Mise à jour visuelle de la ligne en cours
        const int r = currentEditRow;
        if (r >= 0 && r < ui->tableWidget->rowCount()) {
            ui->tableWidget->item(r, 0)->setText(cinVal);
            ui->tableWidget->item(r, 1)->setText(firstName);
            ui->tableWidget->item(r, 2)->setText(lastName);
            ui->tableWidget->item(r, 3)->setText(email);
            ui->tableWidget->item(r, 4)->setText(address);
            ui->tableWidget->item(r, 5)->setText(phone);
        }

        QMessageBox::information(this, "Succès", "Client mis à jour.");
        resetFormToAddMode();
    }
}
