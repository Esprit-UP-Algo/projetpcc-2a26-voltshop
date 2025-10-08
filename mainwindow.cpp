#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientwindow.h"
#include "loginwindow.h"
#include "stockwindow.h"
#include "commandewindow.h"
#include "employeewindow.h"          // ✅ include nouveau

#include <QPixmap>
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , clientWindow(nullptr)
    , stockWindow(nullptr)
    , commandeWindow(nullptr)
    , employeeWindow(nullptr)        // ✅
    , paymentIdCounter(1)
    , isDarkMode(false)
{
    ui->setupUi(this);

    // Logo
    QPixmap pix_logo(":/images/ressource/logo.jpeg");
    if (!pix_logo.isNull()) {
        ui->logo_main->setPixmap(pix_logo.scaled(100, 80, Qt::KeepAspectRatio));
    }

    // Connexions existantes
    connect(ui->pushButton_2,   &QPushButton::clicked, this, &MainWindow::openClientModule);
    connect(ui->Paymen_button,  &QPushButton::clicked, this, &MainWindow::showPaymentModule);
    connect(ui->logout_b,       &QPushButton::clicked, this, &MainWindow::logout);
    connect(ui->pushButton,     &QPushButton::clicked, this, &MainWindow::addPaymentToTable);
    connect(ui->darkmode_button,&QPushButton::clicked, this, &MainWindow::toggleDarkMode);
    connect(ui->stock,          &QPushButton::clicked, this, &MainWindow::openStockModule);
    connect(ui->comwin,         &QPushButton::clicked, this, &MainWindow::openCommandeModule);
    connect(ui->btn_emp,        &QPushButton::clicked, this, &MainWindow::openEmployeeModule);   // ✅ bouton Employee

    // Table paiement
    if (ui->tableWidget_2->columnCount() < 5) {
        ui->tableWidget_2->setColumnCount(5);
        ui->tableWidget_2->setHorizontalHeaderLabels({"Payment_ID", "Amount", "Pay_Method", "Date", "Status"});
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    if (clientWindow)   delete clientWindow;
    if (stockWindow)    delete stockWindow;
    if (commandeWindow) delete commandeWindow;
    if (employeeWindow) delete employeeWindow;     // ✅
}

// --------- CLIENT ---------
void MainWindow::openClientModule()
{
    if (!clientWindow) {
        clientWindow = new ClientWindow(ui->centralwidget);
        clientWindow->setGeometry(ui->tabWidget->geometry());
    }
    if (stockWindow)    stockWindow->hide();
    if (commandeWindow) commandeWindow->hide();
    if (employeeWindow) employeeWindow->hide();

    ui->tabWidget->hide();
    clientWindow->show();
    clientWindow->raise();
    clientWindow->activateWindow();
}

// --------- STOCK ---------
void MainWindow::openStockModule()
{
    if (!stockWindow) {
        stockWindow = new StockWindow(ui->centralwidget);
        stockWindow->setGeometry(ui->tabWidget->geometry());
        connect(stockWindow, &StockWindow::backRequested, this, &MainWindow::onStockBack);
    }
    if (clientWindow)   clientWindow->hide();
    if (commandeWindow) commandeWindow->hide();
    if (employeeWindow) employeeWindow->hide();

    ui->tabWidget->hide();
    stockWindow->show();
    stockWindow->raise();
    stockWindow->activateWindow();
}

void MainWindow::onStockBack()
{
    showPaymentModule();
}

// --------- COMMANDE ---------
void MainWindow::openCommandeModule()
{
    if (!commandeWindow) {
        commandeWindow = new CommandeWindow(ui->centralwidget);
        commandeWindow->setGeometry(ui->tabWidget->geometry());
        connect(commandeWindow, &CommandeWindow::backRequested, this, &MainWindow::onCommandeBack);
    }
    if (clientWindow)   clientWindow->hide();
    if (stockWindow)    stockWindow->hide();
    if (employeeWindow) employeeWindow->hide();

    ui->tabWidget->hide();
    commandeWindow->show();
    commandeWindow->raise();
    commandeWindow->activateWindow();
}

void MainWindow::onCommandeBack()
{
    showPaymentModule();
}

// --------- EMPLOYEE (nouveau) ---------
void MainWindow::openEmployeeModule()
{
    if (!employeeWindow) {
        employeeWindow = new EmployeeWindow(ui->centralwidget);
        employeeWindow->setGeometry(ui->tabWidget->geometry());
        connect(employeeWindow, &EmployeeWindow::backRequested, this, &MainWindow::onEmployeeBack);
    }
    if (clientWindow)   clientWindow->hide();
    if (stockWindow)    stockWindow->hide();
    if (commandeWindow) commandeWindow->hide();

    ui->tabWidget->hide();
    employeeWindow->show();
    employeeWindow->raise();
    employeeWindow->activateWindow();
}

void MainWindow::onEmployeeBack()
{
    showPaymentModule();
}

// --------- PAIEMENT ---------
void MainWindow::showPaymentModule()
{
    if (clientWindow)   clientWindow->hide();
    if (stockWindow)    stockWindow->hide();
    if (commandeWindow) commandeWindow->hide();
    if (employeeWindow) employeeWindow->hide();

    ui->tabWidget->show();
    ui->tabWidget->raise();
    ui->tabWidget->activateWindow();
}

// --------- DARK MODE / LOGOUT / TABLE ---------
void MainWindow::toggleDarkMode()
{
    isDarkMode = !isDarkMode;
    if (isDarkMode) {
        ui->tabWidget->setStyleSheet(
            "QTabWidget::pane { border: 1px solid #444; background: #2D2D2D; border-radius: 6px; padding: 6px; }"
            );
    } else {
        ui->tabWidget->setStyleSheet(
            "QTabWidget::pane { border: 1px solid #00A3E0; background: #E6F2FA; border-radius: 6px; padding: 6px; }"
            "QTabBar::tab { background: #003271; color: white; padding: 8px 16px; border-top-left-radius: 6px; border-top-right-radius: 6px; margin-right: 2px; font-weight: bold; }"
            "QTabBar::tab:selected { background: #ADD8E6; color: white; }"
            "QTabBar::tab:hover { background: #004599; color: white; }"
            );
    }
}

void MainWindow::logout()
{
    this->close();
    LoginWindow login;
    if (login.exec() == QDialog::Accepted) {
        MainWindow *nw = new MainWindow();
        nw->show();
    } else {
        QApplication::quit();
    }
}

void MainWindow::addPaymentToTable()
{
    QString amount = ui->lineEdit->text();
    QString paymentMethod = ui->comboBox_2->currentText();
    QString date = ui->dateEdit->date().toString("dd/MM/yyyy");
    QString status = ui->comboBox_3->currentText();
    if (amount.isEmpty()) return;

    QTableWidget* table = ui->tableWidget_2;
    table->insertRow(0);

    QTableWidgetItem* idItem     = new QTableWidgetItem(QString::number(paymentIdCounter++));
    QTableWidgetItem* amountItem = new QTableWidgetItem(amount);
    QTableWidgetItem* methodItem = new QTableWidgetItem(paymentMethod);
    QTableWidgetItem* dateItem   = new QTableWidgetItem(date);
    QTableWidgetItem* statusItem = new QTableWidgetItem(status);

    table->setItem(0,0,idItem);
    table->setItem(0,1,amountItem);
    table->setItem(0,2,methodItem);
    table->setItem(0,3,dateItem);
    table->setItem(0,4,statusItem);

    ui->lineEdit->clear();
    table->scrollToTop();
    qDebug() << "✅ Added payment:" << (paymentIdCounter-1) << amount;
}
