 #include "login.h"
#include "ui_Login.h"
#include "mainwindow.h"
#include "connection.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QCryptographicHash>
#include <QInputDialog>
#include "totphelper.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QPalette>
#include <QColor>
#include <QDebug>
#include <QApplication>
#include "qrdialog.h"
#include <QDesktopServices>
#include <QUrl>
#include <QStatusBar>
#include <QTimer>

Login::Login(QWidget *parent)
    : QDialog(parent), ui(new Ui::Login)
{
    ui->setupUi(this);

    // Champs (dans login.ui) : QLineEdit id, QLineEdit mdp, QPushButton connect
    ui->mdp->setEchoMode(QLineEdit::Password);

    // Connect text change signals to update connect button state
    connect(ui->id, &QLineEdit::textChanged, this, &Login::updateConnectButton);
    connect(ui->mdp, &QLineEdit::textChanged, this, &Login::updateConnectButton);
    updateConnectButton();

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
}

Login::~Login()
{
    delete ui;
}

void Login::on_connect_clicked()
{
    const QString user = ui->id->text().trimmed();
    const QString pass = ui->mdp->text();

    // Basic input validation
    if (user.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un identifiant.");
        ui->id->setFocus();
        return;
    }
    if (pass.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un mot de passe.");
        ui->mdp->setFocus();
        return;
    }

    // Attempt DB-based authentication using a parameterized query
    Connection &c = Connection::getInstance();
    if (!c.openConnection()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données.");
        return;
    }

    // NOTE: Update these table/column names to match your DB schema if different.
    const QString userTable = "TAB_USER"; // change to your users table
    const QString userColumn = "USERNAME"; // change to your username column
    const QString passColumn = "PASSWORD"; // change to your password column
    const QString totpColumn = "TOTP_SECRET"; // change or add this column in your DB

    QSqlQuery q(c.getDatabase());
    // Select password, totp secret and role
    q.prepare(QString("SELECT %1, %2, ROLE FROM %3 WHERE %4 = :username").arg(passColumn, totpColumn, userTable, userColumn));
    q.bindValue(":username", user);

    if (!q.exec()) {
        QMessageBox::critical(this, "Erreur", QString("Erreur SQL: %1").arg(q.lastError().text()));
        return;
    }

    if (q.next()) {
        const QString stored = q.value(0).toString();
        const QString storedTotp = q.value(1).toString();
        const QString role = q.value(2).toString();

        // Compute SHA-256 hash of supplied password
        const QByteArray passHash = QCryptographicHash::hash(pass.toUtf8(), QCryptographicHash::Sha256).toHex();

        // Accept if stored equals hex-hash OR stored equals plaintext (fallback for legacy DBs)
        if (stored == passHash || stored == pass) {
            // If user has TOTP enabled, prompt for code
            if (!storedTotp.isEmpty()) {
                bool ok;
                QString code = QInputDialog::getText(this, "2FA", "Enter the 6-digit code from your authenticator:", QLineEdit::Normal, QString(), &ok);
                if (!ok) return; // user cancelled
                if (!TotpHelper::verifyCode(storedTotp, code, 1)) {
                    QMessageBox::warning(this, "Erreur", "Code 2FA invalide.");
                    ui->mdp->clear();
                    ui->mdp->setFocus();
                    return;
                }
            } else {
                // Offer to enable 2FA
                auto resp = QMessageBox::question(this, "Activer 2FA", "Voulez-vous activer l'authentification à deux facteurs (Google Authenticator)?", QMessageBox::Yes | QMessageBox::No);
                if (resp == QMessageBox::Yes) {
                    QString secret = TotpHelper::generateBase32Secret(16);
                    QString issuer = "VoltShop"; // change to your app name
                    QString otpUrl = TotpHelper::makeOtpAuthUrl(issuer, user, secret);

                    // Show secret and otpauth URL. The user can scan the QR generated from this URL or enter the secret
                    // Show a simple dialog with a tappable otpauth link and the secret
                    QrDialog dlg(QString(), secret, otpUrl, this);
                    if (dlg.exec() != QDialog::Accepted) {
                        // user cancelled enrollment - proceed without enabling 2FA
                    }

                    // After scanning, ask for confirmation code
                    bool ok;
                    QString code = QInputDialog::getText(this, "Confirm 2FA", "Enter the 6-digit code shown in your authenticator app:", QLineEdit::Normal, QString(), &ok);
                    if (!ok) return; // cancelled
                    if (!TotpHelper::verifyCode(secret, code, 1)) {
                        qDebug() << "[Login] TOTP verification failed during enrollment for user:" << user << "code:" << code;
                        QMessageBox::warning(this, "Erreur", "Code 2FA invalide - configuration annulée.");
                        return;
                    } else {
                        qDebug() << "[Login] TOTP verification succeeded during enrollment for user:" << user;
                    }

                    // Save secret to DB
                    QSqlQuery u(c.getDatabase());
                    u.prepare(QString("UPDATE %1 SET %2 = :secret WHERE %3 = :username").arg(userTable, totpColumn, userColumn));
                    u.bindValue(":secret", secret);
                    u.bindValue(":username", user);
                    if (!u.exec()) {
                        qDebug() << "[Login] Failed to save TOTP secret:" << u.lastError().text();
                        QMessageBox::warning(this, "Erreur", QString("Impossible d'enregistrer le secret 2FA: %1").arg(u.lastError().text()));
                        // proceed without 2FA
                    } else {
                        qDebug() << "[Login] TOTP secret saved for user:" << user;
                    }
                }
            }

            QString normRole = role.trimmed().toLower();
            if (normRole.isEmpty()) normRole = "client"; // safe default
            qDebug() << "[Login] Scheduling MainWindow creation for role:" << role << "(normalized:" << normRole << ")";

            // Prevent double-scheduling (e.g., double-click). If already scheduled, ignore.
            if (m_mainWindowScheduled) {
                qDebug() << "[Login] MainWindow creation already scheduled; ignoring duplicate.";
                return;
            }
            m_mainWindowScheduled = true;

            // Capture needed values by value. Defer actual creation to the next
            // event loop iteration to avoid reentrancy/race issues between showing
            // the main window and deleting the login dialog.
            const QString captureUser = user;
            const QString captureRole = normRole;
            
            // Prevent the application from quitting if the login dialog is closed
            // before the main window is fully shown.
            qApp->setQuitOnLastWindowClosed(false);

            // Schedule creation using the application object as context so the
            // creation lambda runs even if the Login dialog is deleted immediately.
            // disable connect button to avoid duplicate attempts
            if (ui && ui->connect) {
                ui->connect->setEnabled(false);
                ui->connect->blockSignals(true);
            }

            QTimer::singleShot(0, qApp, [captureUser, captureRole]() {
                qDebug() << "[Login] Creating MainWindow (deferred) for" << captureUser << "role:" << captureRole;
                MainWindow *w = nullptr;
                try {
                    // Enable debug-skip to create a minimal MainWindow for isolation
                    MainWindow::s_skipHeavyInit = true;
                    w = new MainWindow();
                } catch (...) {
                    qDebug() << "[Login] Exception while new MainWindow()";
                    MainWindow::s_skipHeavyInit = false;
                    return;
                }
                w->setInitialRole(captureRole);
                w->setWindowTitle(QString("VoltShop - %1 (%2)").arg(captureUser, captureRole));
                if (w->statusBar()) w->statusBar()->showMessage(QString("Logged in as %1 (%2)").arg(captureUser, captureRole));
                // Do NOT set WA_DeleteOnClose - we manage deletion explicitly via deleteLater in logout
                qDebug() << "[Login] About to show MainWindow (deferred)";
                w->show();
                // restore default so subsequent MainWindow creations behave normally
                MainWindow::s_skipHeavyInit = false;
                qDebug() << "[Login] MainWindow shown (deferred)";
                // Restore default quit behavior after the main window is visible
                QTimer::singleShot(0, qApp, [](){ qApp->setQuitOnLastWindowClosed(true); });
                connect(w, &QObject::destroyed, qApp, [](){ qDebug() << "[Login] MainWindow destroyed"; });
            });

            // Hide the login dialog and delete it after a short delay to ensure
            // the MainWindow creation callback has a chance to execute
            this->hide();
            QTimer::singleShot(100, this, [this]() {
                qDebug() << "[Login] Deleting Login dialog (deferred)";
                this->deleteLater();
            });
            return;
        }
    }

    QMessageBox::warning(this, "Erreur", "ID ou mot de passe incorrect !");
    ui->mdp->clear();
    ui->mdp->setFocus();
}

void Login::updateConnectButton()
{
    const bool enable = !ui->id->text().trimmed().isEmpty() && !ui->mdp->text().isEmpty();
    ui->connect->setEnabled(enable);
}
