#include "qrdialog.h"
#include <QUrl>
#include <QHBoxLayout>
#include <QDesktopServices>
#include <QFont>
#include <QVBoxLayout>

QrDialog::QrDialog(const QString &chartUrl, const QString &secret, const QString &otpUrl, QWidget *parent)
    : QDialog(parent), imgLabel(new QLabel(this)), secretLabel(new QLabel(this)), okButton(new QPushButton("OK", this)), m_otpUrl(otpUrl)
{
    Q_UNUSED(chartUrl)
    qDebug() << "[QrDialog] ctor - secret(len)=" << secret.length() << " otpUrl:" << (m_otpUrl.isEmpty() ? QString("(empty)") : m_otpUrl.left(200));
    
    setWindowTitle("Enable Two-Factor Authentication");
    setMinimumWidth(450);
    setStyleSheet("QDialog { background-color: #f5f5f5; }");

    // Title label
    QLabel *title = new QLabel("Setup Google Authenticator", this);
    QFont titleFont = title->font();
    titleFont.setPointSize(14);
    titleFont.setBold(true);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("color: #2C3E50; padding: 10px; background-color: transparent;");

    // Instructions
    QLabel *info = new QLabel(this);
    info->setText("To enable two-factor authentication:\n"
                  "1. Open Google Authenticator on your phone\n"
                  "2. Click the link below or manually enter the secret\n"
                  "3. Enter the 6-digit code to confirm");
    info->setWordWrap(true);
    info->setStyleSheet("color: #34495E; padding: 15px; background-color: white; "
                       "border: 1px solid #BDC3C7; border-radius: 5px; line-height: 1.6;");

    // Link section with icon
    QLabel *linkLabel = new QLabel("📱 <b>Quick Setup:</b>", this);
    linkLabel->setStyleSheet("color: #2C3E50; padding: 5px; background-color: transparent;");
    
    QLabel *link = new QLabel(this);
    if (!m_otpUrl.isEmpty()) {
        QString escaped = m_otpUrl.toHtmlEscaped();
        link->setText(QString("<a href=\"%1\" style=\"color: #2C82C9; text-decoration: none; "
                             "font-weight: bold;\">🔗 Open in Authenticator App</a>").arg(escaped));
        link->setTextInteractionFlags(Qt::TextBrowserInteraction);
        link->setOpenExternalLinks(true);
    } else {
        link->setText("No auth URL available; use the secret below.");
        link->setTextInteractionFlags(Qt::TextSelectableByMouse);
    }
    link->setStyleSheet("padding: 10px; background-color: #E8F4F8; border: 1px solid #2C82C9; "
                       "border-radius: 5px; color: #2C82C9;");
    link->setAlignment(Qt::AlignCenter);

    // Secret section
    QLabel *secretTitle = new QLabel("🔑 <b>Manual Entry Secret:</b>", this);
    secretTitle->setStyleSheet("color: #2C3E50; padding: 5px; background-color: transparent; margin-top: 10px;");
    
    secretLabel->setText(secret);
    secretLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    secretLabel->setAlignment(Qt::AlignCenter);
    QFont secretFont("Courier New", 11, QFont::Bold);
    secretLabel->setFont(secretFont);
    secretLabel->setStyleSheet("padding: 12px; background-color: #FFFACD; border: 2px dashed #F39C12; "
                              "border-radius: 5px; color: #8B4513; letter-spacing: 2px;");

    // Hint label
    QLabel *hint = new QLabel("💡 Tip: Copy the secret by selecting it with your mouse", this);
    hint->setStyleSheet("color: #7F8C8D; font-size: 9pt; font-style: italic; "
                       "padding: 5px; background-color: transparent;");
    hint->setAlignment(Qt::AlignCenter);

    // OK button with better styling
    okButton->setText("Continue");
    okButton->setMinimumHeight(35);
    okButton->setCursor(Qt::PointingHandCursor);
    okButton->setStyleSheet("QPushButton {"
                           "  background-color: #27AE60;"
                           "  color: white;"
                           "  border: none;"
                           "  border-radius: 5px;"
                           "  padding: 8px 30px;"
                           "  font-weight: bold;"
                           "  font-size: 10pt;"
                           "}"
                           "QPushButton:hover {"
                           "  background-color: #229954;"
                           "}"
                           "QPushButton:pressed {"
                           "  background-color: #1E8449;"
                           "}");

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(10);
    layout->setContentsMargins(20, 20, 20, 20);
    
    layout->addWidget(title);
    layout->addSpacing(5);
    layout->addWidget(info);
    layout->addSpacing(10);
    layout->addWidget(linkLabel);
    layout->addWidget(link);
    layout->addSpacing(10);
    layout->addWidget(secretTitle);
    layout->addWidget(secretLabel);
    layout->addWidget(hint);
    layout->addSpacing(15);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addStretch();
    layout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, this, &QrDialog::accept);
}



QrDialog::~QrDialog()
{
    qDebug() << "[QrDialog] dtor";
}
