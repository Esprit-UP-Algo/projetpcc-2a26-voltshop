#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientwindow.h"
#include "loginwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , clientWindow(nullptr)
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
