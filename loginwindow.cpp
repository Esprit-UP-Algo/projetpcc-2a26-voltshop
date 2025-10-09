#include "loginwindow.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QKeyEvent>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    
    // Connect button signals
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &LoginWindow::onCancelClicked);
    
    // Connect Enter key press on password field to login
    connect(ui->passwordLineEdit, &QLineEdit::returnPressed, this, &LoginWindow::onLoginClicked);
    
    // Set focus to username field
    ui->usernameLineEdit->setFocus();
    
    // Clear status label initially
    ui->statusLabel->clear();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::onLoginClicked()
{
    QString username = ui->usernameLineEdit->text().trimmed();
    QString password = ui->passwordLineEdit->text();
    
    // Clear previous status
    ui->statusLabel->clear();
    
    // Basic validation
    if (username.isEmpty()) {
        ui->statusLabel->setText("Please enter username");
        ui->usernameLineEdit->setFocus();
        return;
    }
    
    if (password.isEmpty()) {
        ui->statusLabel->setText("Please enter password");
        ui->passwordLineEdit->setFocus();
        return;
    }
    
    // Validate credentials (simple hardcoded for demo - replace with real authentication)
    if (validateLogin(username, password)) {
        ui->statusLabel->setText("Login successful!");
        ui->statusLabel->setStyleSheet("color: #2e7d32; font-weight: bold;");
        accept(); // Close dialog with success
    } else {
        ui->statusLabel->setText("Invalid username or password");
        ui->statusLabel->setStyleSheet("color: #d32f2f; font-weight: bold;");
        ui->passwordLineEdit->clear();
        ui->passwordLineEdit->setFocus();
    }
}

void LoginWindow::onCancelClicked()
{
    reject(); // Close dialog with cancel
}

bool LoginWindow::validateLogin(const QString &username, const QString &password)
{
    // Simple hardcoded validation with single admin user
    if (username == "admin" && password == "admin123") {
        userType = 1; // Admin user
        return true;
    }
    return false;
}
