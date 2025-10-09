#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientwindow.h"
#include "loginwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , clientWindow(nullptr)
    , paymentIdCounter(1) // Initialize counter to 1
    , isDarkMode(false)
{
    ui->setupUi(this);
    
    // Load VoltShop logo in main window
    QPixmap pix_logo(":/images/ressource/logo.jpeg");
    if (!pix_logo.isNull()) {
        ui->logo_main->setPixmap(pix_logo.scaled(100,80,Qt::KeepAspectRatio));
    }
    
    // Connect the person icon button (pushButton_2) to open client module
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::openClientModule);
    // Connect the credit card (fourth) button to show payment module
    connect(ui->Paymen_button, &QPushButton::clicked, this, &MainWindow::showPaymentModule);
    // Connect the logout button to logout function
    connect(ui->logout_b, &QPushButton::clicked, this, &MainWindow::logout);
    
    // Connect the add payment button to add payment data to table
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::addPaymentToTable);
    
    // Connect dark mode button
    connect(ui->darkmode_button, &QPushButton::clicked, this, &MainWindow::toggleDarkMode);
    
    // Make sure the table has the correct number of columns
    if (ui->tableWidget_2->columnCount() < 5) {
        ui->tableWidget_2->setColumnCount(5);
        ui->tableWidget_2->setHorizontalHeaderLabels({"Payment_ID", "Amount", "Pay_Method", "Date", "Status"});
    }
}

void MainWindow::showPaymentModule()
{
    // Hide client view if present and restore payment tab widget
    if (clientWindow) {
        clientWindow->hide();
    }
    ui->tabWidget->show();
    ui->tabWidget->raise();
    ui->tabWidget->activateWindow();
}
         
void MainWindow::toggleDarkMode()
{
    isDarkMode = !isDarkMode;
    
    if (isDarkMode) {
        // Dark mode styles
        ui->tabWidget->setStyleSheet(
            "QTabWidget::pane {"
            "    border: 1px solid #444444;"
            "    background: #2D2D2D;"
            "    border-radius: 6px;"
            "    padding: 6px;"
            "}");
           /*"QTabBar::tab {"
            "    background: #1A1A1A;"
            "    color: #CCCCCC;"
            "    padding: 8px 16px;"
            "    border-top-left-radius: 6px;"
            "    border-top-right-radius: 6px;"
            "    margin-right: 2px;"
            "    font-weight: bold;"
            "}"
            "QTabBar::tab:selected {"
            "    background: #444444;"
            "    color: #FFFFFF;"
            "}"
            "QTabBar::tab:hover {"
            "    background: #555555;"
            "    color: #FFFFFF;"
            "}"
        );*/
        
        // Update group boxes in dark mode
        /*QList<QGroupBox*> groupBoxes = ui->tabWidget->findChildren<QGroupBox*>();
        for (QGroupBox* groupBox : groupBoxes) {
            groupBox->setStyleSheet(
                "QGroupBox {"
                "    background-color: #444444;"
                "    border: 2px solid #555555;"
                "    border-radius: 6px;"
                "    margin-top: 20px;"
                "    padding: 10px;"
                "    font-family: Segoe UI, Arial;"
                "    font-size: 14px;"
                "    font-weight: bold;"
                "    color: #CCCCCC;"
                "}"
                "QGroupBox::title {"
                "    subcontrol-origin: margin;"
                "    subcontrol-position: top left;"
                "    padding: 2px 8px;"
                "    background-color: #555555;"
                "    color: white;"
                "    border-radius: 4px;"
                "}"
            );
        }*/
        
        // Update table widgets in dark mode
       /* QList<QTableWidget*> tableWidgets = ui->tabWidget->findChildren<QTableWidget*>();
        for (QTableWidget* tableWidget : tableWidgets) {
            tableWidget->setStyleSheet(
                "QTableWidget {"
                "    background-color: #2D2D2D;"
                "    alternate-background-color: #3A3A3A;"
                "    gridline-color: #555555;"
                "    border: 1px solid #555555;"
                "    selection-background-color: #0066CC;"
                "    selection-color: white;"
                "    font-family: Segoe UI, Arial;"
                "    font-size: 13px;"
                "    color: #CCCCCC;"
                "}"
                "QHeaderView::section {"
                "    background-color: #444444;"
                "    color: #CCCCCC;"
                "    padding: 6px;"
                "    border: none;"
                "    font-weight: bold;"
                "}"
                "QTableCornerButton::section {"
                "    background-color: #444444;"
                "    border: none;"
                "}"
            );
        }*/
        
        // Update labels in dark mode
        /*QList<QLabel*> labels = ui->tabWidget->findChildren<QLabel*>();
        for (QLabel* label : labels) {
            label->setStyleSheet("color: #CCCCCC;");
        }
        
        // Update line edits in dark mode
        QList<QLineEdit*> lineEdits = ui->tabWidget->findChildren<QLineEdit*>();
        for (QLineEdit* lineEdit : lineEdits) {
            lineEdit->setStyleSheet(
                "QLineEdit {"
                "    background-color: #3A3A3A;"
                "    border: 2px solid #555555;"
                "    border-radius: 6px;"
                "    padding: 6px 10px;"
                "    font-size: 14px;"
                "    color: #CCCCCC;"
                "}"
                "QLineEdit:focus {"
                "    border: 2px solid #0066CC;"
                "    background-color: #444444;"
                "}"
            );
        }
        
        // Update buttons in dark mode
        QList<QPushButton*> buttons = ui->tabWidget->findChildren<QPushButton*>();
        for (QPushButton* button : buttons) {
            if (button != ui->darkmode_button) {
                button->setStyleSheet(
                    "QPushButton {"
                    "    background-color: #444444;"
                    "    color: #CCCCCC;"
                    "    border-radius: 6px;"
                    "    padding: 6px 12px;"
                    "    font-weight: bold;"
                    "    border: 2px solid #555555;"
                    "}"
                    "QPushButton:hover { background-color: #555555; }"
                    "QPushButton:pressed { background-color: #333333; }"
                );
            }
        }*/
    } else {
        // Light mode (default) styles
        ui->tabWidget->setStyleSheet(
            "QTabWidget::pane {"
            "    border: 1px solid #00A3E0;"
            "    background: #E6F2FA;"
            "    border-radius: 6px;"
            "    padding: 6px;"
            "}"
            "QTabBar::tab {"
            "    background: #003271;"
            "    color: white;"
            "    padding: 8px 16px;"
            "    border-top-left-radius: 6px;"
            "    border-top-right-radius: 6px;"
            "    margin-right: 2px;"
            "    font-weight: bold;"
            "}"
            "QTabBar::tab:selected {"
            "    background: #ADD8E6;"
            "    color: white;"
            "}"
            "QTabBar::tab:hover {"
            "    background: #004599;"
            "    color: white;"
            "}"
        );
        
        // Reset group boxes to light mode
        QList<QGroupBox*> groupBoxes = ui->tabWidget->findChildren<QGroupBox*>();
        for (QGroupBox* groupBox : groupBoxes) {
            groupBox->setStyleSheet(
                "QGroupBox {"
                "     background-color: rgb(173, 216, 230);"
                "     border: 2px solid #00A3E0;"
                "     border-radius: 6px;"
                "     margin-top: 20px;"
                "     padding: 10px;"
                "     font-family: Segoe UI, Arial;"
                "     font-size: 14px;"
                "     font-weight: bold;"
                "     color: #003271;"
                " }"
                " QGroupBox::title {"
                "     subcontrol-origin: margin;"
                "     subcontrol-position: top left;"
                "     padding: 2px 8px;"
                "     background-color: #00A3E0;"
                "     color: white;"
                "     border-radius: 4px;"
                " }"
            );
        }
        
        // Reset table widgets to light mode
        QList<QTableWidget*> tableWidgets = ui->tabWidget->findChildren<QTableWidget*>();
        for (QTableWidget* tableWidget : tableWidgets) {
            tableWidget->setStyleSheet(
                "QTableWidget {"
                "     background-color: white;"
                "     alternate-background-color: #E6F2FA;"
                "     gridline-color: #ADD8E6;"
                "     border: 1px solid #ADD8E6;"
                "     selection-background-color: #003271;"
                "     selection-color: white;"
                "     font-family: Segoe UI, Arial;"
                "     font-size: 13px;"
                " }"
                " QHeaderView::section {"
                "     background-color: #ADD8E6;"
                "     color: black;"
                "     padding: 6px;"
                "     border: none;"
                "     font-weight: bold;"
                " }"
                " QTableCornerButton::section {"
                "     background-color: #ADD8E6;"
                "     border: none;"
                " }"
            );
        }
        
        // Reset labels to light mode
        QList<QLabel*> labels = ui->tabWidget->findChildren<QLabel*>();
        for (QLabel* label : labels) {
            label->setStyleSheet("font: 900 9pt \"Swis721 Blk BT\"; color: rgb(0, 0, 0);");
        }
        
        // Reset line edits to light mode
        QList<QLineEdit*> lineEdits = ui->tabWidget->findChildren<QLineEdit*>();
        for (QLineEdit* lineEdit : lineEdits) {
            lineEdit->setStyleSheet(
                "QLineEdit {"
                "     background-color: #f4faff;"
                "     border: 2px solid #003271;"
                "     border-radius: 6px;"
                "     padding: 6px 10px;"
                "     font-size: 14px;"
                "     color: #000000;"
                " }"
                " QLineEdit:focus {"
                "     border: 2px solid #1e6fd9;"
                "     background-color: #ffffff;"
                " }"
            );
        }
        
        // Reset buttons to light mode
        QList<QPushButton*> buttons = ui->tabWidget->findChildren<QPushButton*>();
        for (QPushButton* button : buttons) {
            if (button != ui->darkmode_button) {
                button->setStyleSheet(
                    "QPushButton {"
                    " 	font: 900 9pt \"Swis721 Blk BT\";"
                    "     background-color: #003271;"
                    "     color: white;"
                    "     border-radius: 6px;"
                    "     padding: 6px 12px;"
                    " }"
                    " QPushButton:hover { background-color: #004599; }"
                    " QPushButton:pressed { background-color: #002050; }"
                );
            }
        }
    }
}

void MainWindow::logout()
{
    // Close the main window and show login dialog again
    this->close();
    
    // Show login dialog
    LoginWindow login;
    if (login.exec() == QDialog::Accepted) {
        // Login successful, show main window again
        MainWindow *newMainWindow = new MainWindow();
        newMainWindow->show();
    } else {
        // Login cancelled or failed, exit application
        QApplication::quit();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    if (clientWindow) {
        delete clientWindow;
    }
}

void MainWindow::openClientModule()
{
    if (!clientWindow) {
        // Create the client module as a child of the central area
        clientWindow = new ClientWindow(ui->centralwidget);
        // Place it exactly where the payment tab widget currently is
        clientWindow->setGeometry(ui->tabWidget->geometry());
    }

    // Hide the payment tab widget and show the client UI in its place
    ui->tabWidget->hide();
    clientWindow->show();
    clientWindow->raise();
    clientWindow->activateWindow();
}

void MainWindow::addPaymentToTable()
{
    // Get values from input fields
    QString amount = ui->lineEdit->text();
    QString paymentMethod = ui->comboBox_2->currentText();
    QString date = ui->dateEdit->date().toString("dd/MM/yyyy");
    QString status = ui->comboBox_3->currentText();
    
    // Validate amount
    if (amount.isEmpty()) {
        return; // Don't add if amount is empty
    }
    
    // Get reference to the table
    QTableWidget* table = ui->tableWidget_2;
    
    // Add a new row at the top (position 0)
    table->insertRow(0);
    
    // Create and set items for each column
    QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(paymentIdCounter++));
    QTableWidgetItem* amountItem = new QTableWidgetItem(amount);
    QTableWidgetItem* methodItem = new QTableWidgetItem(paymentMethod);
    QTableWidgetItem* dateItem = new QTableWidgetItem(date);
    QTableWidgetItem* statusItem = new QTableWidgetItem(status);
    
    table->setItem(0, 0, idItem);
    table->setItem(0, 1, amountItem);
    table->setItem(0, 2, methodItem);
    table->setItem(0, 3, dateItem);
    table->setItem(0, 4, statusItem);
    
    // Clear input fields after adding
    ui->lineEdit->clear();
    
    // Make sure the row is visible (should be visible by default since it's at the top)
    table->scrollToTop();
    
    // Debug message to confirm data was added
    qDebug() << "Added payment: ID=" << paymentIdCounter-1 << ", Amount=" << amount;
}
