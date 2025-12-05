#include "login.h"
#include "ui_Login.h"
#include "mainwindow.h"
#include "connection.h"
#include "totphelper.h"
#include "qrdialog.h"
#include "logger.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QPalette>
#include <QColor>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QInputDialog>
#include <QTimer>
#include <QApplication>

Login::Login(QWidget *parent)
    : QDialog(parent), ui(new Ui::Login)
{
    ui->setupUi(this);

    LOG_INFO("Login dialog created");

    // on s'assure que l'objet s'appelle bien Login pour le CSS
    this->setObjectName("Login");

    // Champs (dans login.ui) : QLineEdit id, QLineEdit mdp, QPushButton connect
    ui->mdp->setEchoMode(QLineEdit::Password);

    // === Texte noir + placeholder gris ===
    auto tune = [](QLineEdit* le){
        QPalette p = le->palette();
        p.setColor(QPalette::Text, Qt::black);   // texte saisi noir
        p.setColor(QPalette::Base, Qt::white);   // fond blanc
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        p.setColor(QPalette::PlaceholderText, QColor(130,130,130)); // placeholder gris
#endif
        le->setPalette(p);
    };
    tune(ui->id);
    tune(ui->mdp);
    
    // Force the UI file styles to take precedence
    this->setObjectName("Login");
}

Login::~Login()
{
    LOG_INFO("Login dialog destroyed");
    delete ui;
}

void Login::on_connect_clicked()
{
    if (m_mainWindowScheduled) {
        LOG_WARNING("Login already in progress, ignoring duplicate click");
        return;
    }

    const QString username = ui->id->text().trimmed();
    const QString password = ui->mdp->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter both username and password.");
        return;
    }

    LOG_INFO(QString("Login attempt for user: %1").arg(username));

    QString role;
    QString totpSecret;
    
    // Step 1: Authenticate username and password
    if (!authenticateUser(username, password, role, totpSecret)) {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
        LOG_WARNING(QString("Failed login for user: %1").arg(username));
        ui->mdp->clear();
        ui->mdp->setFocus();
        return;
    }

    LOG_INFO(QString("User %1 authenticated successfully, role: %2").arg(username, role));

    // Step 2: Handle TOTP (enrollment or verification)
    if (totpSecret.isEmpty() || totpSecret == "null") {
        // First login - offer to enroll in TOTP
        LOG_INFO(QString("User %1 does not have 2FA enabled").arg(username));
        
        QMessageBox::StandardButton reply = QMessageBox::question(
            this, 
            "Enable Two-Factor Authentication?",
            "Two-Factor Authentication (2FA) adds an extra layer of security to your account.\n\n"
            "Would you like to enable 2FA now?\n\n"
            "• Yes - Set up 2FA with Google Authenticator\n"
            "• No - Continue without 2FA (you can enable it later)",
            QMessageBox::Yes | QMessageBox::No,
            QMessageBox::Yes
        );
        
        if (reply == QMessageBox::Yes) {
            // User wants to enroll in 2FA
            if (!enrollNewTotp(username)) {
                LOG_ERROR(QString("TOTP enrollment failed for user: %1").arg(username));
                QMessageBox::warning(this, "Setup Failed", "Failed to set up two-factor authentication.");
                return;
            }
            
            QMessageBox::information(this, "Setup Complete", 
                "Two-factor authentication has been set up. Please log in again with your 6-digit code.");
            LOG_INFO(QString("TOTP enrollment completed for user: %1").arg(username));
            ui->mdp->clear();
            return;
        } else {
            // User declined 2FA - proceed without it
            LOG_INFO(QString("User %1 declined 2FA enrollment, proceeding without 2FA").arg(username));
        }
    } else {
        // Subsequent login - verify TOTP code
        LOG_INFO(QString("User %1 requires TOTP verification").arg(username));
        if (!handleTotpVerification(username, totpSecret)) {
            LOG_WARNING(QString("TOTP verification failed for user: %1").arg(username));
            QMessageBox::warning(this, "Verification Failed", "Invalid verification code.");
            return;
        }
    }

    LOG_INFO(QString("Full authentication successful for user: %1").arg(username));
    
    // Step 3: Create MainWindow with role
    createMainWindowDeferred(username, role);
}

bool Login::authenticateUser(const QString &username, const QString &password, 
                              QString &outRole, QString &outTotpSecret)
{
    Connection& conn = Connection::getInstance();
    if (!conn.openConnection()) {
        LOG_ERROR("Failed to open database connection");
        return false;
    }

    // First, get the user's password algorithm and stored password
    QSqlQuery query(conn.getDatabase());
    query.prepare("SELECT PASSWORD, PASSWORD_ALGO, ROLE, TOTP_SECRET FROM TAB_USER WHERE USERNAME = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        LOG_ERROR(QString("Database query error: %1").arg(query.lastError().text()));
        return false;
    }

    if (!query.next()) {
        LOG_WARNING(QString("User not found: %1").arg(username));
        return false;
    }

    QString storedPassword = query.value("PASSWORD").toString();
    QString passwordAlgo = query.value("PASSWORD_ALGO").toString().toLower();
    outRole = query.value("ROLE").toString();
    outTotpSecret = query.value("TOTP_SECRET").toString();

    LOG_INFO(QString("Retrieved role from database: '%1' for user: %2").arg(outRole, username));

    // Check password based on algorithm
    bool passwordMatch = false;
    
    if (passwordAlgo == "plain") {
        // Plain text comparison
        passwordMatch = (password == storedPassword);
        LOG_DEBUG(QString("Using plain text password verification for user: %1").arg(username));
    } else if (passwordAlgo == "sha256") {
        // SHA256 hash comparison
        QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), 
                                                            QCryptographicHash::Sha256);
        QString passwordHashHex = QString(passwordHash.toHex()).toUpper();
        passwordMatch = (passwordHashHex == storedPassword.toUpper());
        LOG_DEBUG(QString("Using SHA256 password verification for user: %1").arg(username));
    } else {
        LOG_ERROR(QString("Unsupported password algorithm: %1").arg(passwordAlgo));
        return false;
    }

    if (passwordMatch) {
        LOG_DEBUG(QString("User authenticated - Role: %1, TOTP: %2").arg(outRole, outTotpSecret.isEmpty() ? "not set" : "set"));
        return true;
    }

    LOG_WARNING(QString("Password mismatch for user: %1").arg(username));
    return false;
}

bool Login::handleTotpVerification(const QString &username, const QString &totpSecret)
{
    bool ok;
    QString code = QInputDialog::getText(this, "Two-Factor Authentication",
                                         "Enter 6-digit verification code from your authenticator app:",
                                         QLineEdit::Normal, "", &ok);

    if (!ok || code.isEmpty()) {
        return false;
    }

    code = code.trimmed();
    
    if (code.length() != 6) {
        QMessageBox::warning(this, "Invalid Code", "Please enter a 6-digit code.");
        return false;
    }

    // Verify the code with ±1 time window (60 seconds tolerance)
    if (TotpHelper::verifyCode(totpSecret, code, 1)) {
        LOG_INFO(QString("TOTP verification successful for user: %1").arg(username));
        return true;
    }

    LOG_WARNING(QString("TOTP code mismatch for user: %1").arg(username));
    return false;
}

bool Login::enrollNewTotp(const QString &username)
{
    // Generate new Base32 secret
    QString secret = TotpHelper::generateBase32Secret(32);
    
    LOG_INFO(QString("Generated TOTP secret for user: %1").arg(username));

    // Save to database
    Connection& conn = Connection::getInstance();
    QSqlQuery query(conn.getDatabase());
    query.prepare("UPDATE TAB_USER SET TOTP_SECRET = :secret WHERE USERNAME = :username");
    query.bindValue(":secret", secret);
    query.bindValue(":username", username);

    if (!query.exec()) {
        LOG_ERROR(QString("Failed to save TOTP secret: %1").arg(query.lastError().text()));
        return false;
    }

    // Create otpauth URL
    QString otpAuthUrl = TotpHelper::makeOtpAuthUrl("VoltShop", username, secret);

    // Show enrollment dialog
    QRDialog dialog(otpAuthUrl, secret, username, this);
    dialog.exec();

    return true;
}

void Login::createMainWindowDeferred(const QString &username, const QString &role)
{
    m_mainWindowScheduled = true;
    LOG_INFO(QString("Scheduling MainWindow creation for user: %1 with role: %2").arg(username, role));

    // Use QTimer::singleShot to defer MainWindow creation
    QTimer::singleShot(0, qApp, [this, username, role]() {
        if (m_mainWindow) {
            LOG_WARNING("MainWindow already exists, skipping creation");
            return;
        }

        LOG_INFO("Creating MainWindow instance");
        
        // Create MainWindow without WA_DeleteOnClose
        MainWindow *mainWin = new MainWindow();
        m_mainWindow = mainWin;
        
        // Set initial role and apply restrictions
        mainWin->setInitialRole(username, role);
        
        // Show MainWindow
        mainWin->show();
        
        LOG_INFO("MainWindow created and shown successfully");
        
        // Hide login dialog
        this->hide();
    });
}
