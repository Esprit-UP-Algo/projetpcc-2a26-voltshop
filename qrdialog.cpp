#include "qrdialog.h"
#include "ui_qrdialog.h"
#include <QDesktopServices>
#include <QUrl>
#include <QClipboard>
#include <QApplication>

QRDialog::QRDialog(const QString &otpAuthUrl, 
                   const QString &secret, 
                   const QString &username,
                   QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QRDialog)
{
    ui->setupUi(this);
    
    setWindowTitle("Setup Two-Factor Authentication");
    setModal(true);
    
    // Set username label
    ui->usernameLabel->setText(QString("Setting up 2FA for: <b>%1</b>").arg(username));
    
    // Set the secret in the text box
    ui->secretTextEdit->setPlainText(secret);
    ui->secretTextEdit->setReadOnly(true);
    
    // Make the otpauth URL clickable
    ui->otpauthLabel->setText(QString("<a href=\"%1\">%1</a>").arg(otpAuthUrl));
    ui->otpauthLabel->setOpenExternalLinks(true);
    ui->otpauthLabel->setWordWrap(true);
    ui->otpauthLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    
    // Connect copy button
    connect(ui->copySecretButton, &QPushButton::clicked, [secret]() {
        QApplication::clipboard()->setText(secret);
    });
    
    // Connect done button
    connect(ui->doneButton, &QPushButton::clicked, this, &QDialog::accept);
}

QRDialog::~QRDialog()
{
    delete ui;
}
