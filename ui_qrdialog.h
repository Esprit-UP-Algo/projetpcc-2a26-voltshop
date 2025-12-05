/********************************************************************************
** Form generated from reading UI file 'qrdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRDIALOG_H
#define UI_QRDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QRDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *usernameLabel;
    QGroupBox *instructionsGroup;
    QVBoxLayout *verticalLayout_2;
    QLabel *step1Label;
    QLabel *step2Label;
    QLabel *otpauthLabel;
    QGroupBox *manualGroup;
    QVBoxLayout *verticalLayout_3;
    QLabel *manualLabel;
    QTextEdit *secretTextEdit;
    QPushButton *copySecretButton;
    QSpacerItem *verticalSpacer;
    QPushButton *doneButton;

    void setupUi(QDialog *QRDialog)
    {
        if (QRDialog->objectName().isEmpty())
            QRDialog->setObjectName("QRDialog");
        QRDialog->resize(550, 600);
        QRDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #1e3c72, stop:1 #2a5298);\n"
"}\n"
"\n"
"QLabel {\n"
"    color: white;\n"
"    font-size: 12pt;\n"
"}\n"
"\n"
"QTextEdit {\n"
"    background-color: #2d2d2d;\n"
"    color: #00ff00;\n"
"    font-family: 'Courier New', monospace;\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"    border: 2px solid #00ff00;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    font-size: 11pt;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 10px 20px;\n"
"    min-height: 40px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3d8b40;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    color: white;\n"
"    font-size: 11pt;\n"
"    font-weight: bold;\n"
"    border: 2px solid rgba(255, 255, 255, 0.3);\n"
"    border-radius: 8px;\n"
""
                        "    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 10px;\n"
"    background-color: rgba(255, 255, 255, 0.1);\n"
"    border-radius: 4px;\n"
"}"));
        verticalLayout = new QVBoxLayout(QRDialog);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, 30, 30, 30);
        titleLabel = new QLabel(QRDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setWordWrap(true);

        verticalLayout->addWidget(titleLabel);

        usernameLabel = new QLabel(QRDialog);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(usernameLabel);

        instructionsGroup = new QGroupBox(QRDialog);
        instructionsGroup->setObjectName("instructionsGroup");
        verticalLayout_2 = new QVBoxLayout(instructionsGroup);
        verticalLayout_2->setObjectName("verticalLayout_2");
        step1Label = new QLabel(instructionsGroup);
        step1Label->setObjectName("step1Label");
        step1Label->setWordWrap(true);

        verticalLayout_2->addWidget(step1Label);

        step2Label = new QLabel(instructionsGroup);
        step2Label->setObjectName("step2Label");
        step2Label->setWordWrap(true);

        verticalLayout_2->addWidget(step2Label);

        otpauthLabel = new QLabel(instructionsGroup);
        otpauthLabel->setObjectName("otpauthLabel");
        otpauthLabel->setTextFormat(Qt::RichText);
        otpauthLabel->setWordWrap(true);
        otpauthLabel->setOpenExternalLinks(true);
        otpauthLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);

        verticalLayout_2->addWidget(otpauthLabel);


        verticalLayout->addWidget(instructionsGroup);

        manualGroup = new QGroupBox(QRDialog);
        manualGroup->setObjectName("manualGroup");
        verticalLayout_3 = new QVBoxLayout(manualGroup);
        verticalLayout_3->setObjectName("verticalLayout_3");
        manualLabel = new QLabel(manualGroup);
        manualLabel->setObjectName("manualLabel");
        manualLabel->setWordWrap(true);

        verticalLayout_3->addWidget(manualLabel);

        secretTextEdit = new QTextEdit(manualGroup);
        secretTextEdit->setObjectName("secretTextEdit");
        secretTextEdit->setMaximumSize(QSize(16777215, 80));
        secretTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(secretTextEdit);

        copySecretButton = new QPushButton(manualGroup);
        copySecretButton->setObjectName("copySecretButton");

        verticalLayout_3->addWidget(copySecretButton);


        verticalLayout->addWidget(manualGroup);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        doneButton = new QPushButton(QRDialog);
        doneButton->setObjectName("doneButton");

        verticalLayout->addWidget(doneButton);


        retranslateUi(QRDialog);

        QMetaObject::connectSlotsByName(QRDialog);
    } // setupUi

    void retranslateUi(QDialog *QRDialog)
    {
        QRDialog->setWindowTitle(QCoreApplication::translate("QRDialog", "Two-Factor Authentication Setup", nullptr));
        titleLabel->setText(QCoreApplication::translate("QRDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700;\">\360\237\224\222 Two-Factor Authentication Setup</span></p></body></html>", nullptr));
        usernameLabel->setText(QCoreApplication::translate("QRDialog", "<html><head/><body><p align=\"center\">Setting up 2FA for: <span style=\" font-weight:700;\">username</span></p></body></html>", nullptr));
        instructionsGroup->setTitle(QCoreApplication::translate("QRDialog", "Setup Instructions", nullptr));
        step1Label->setText(QCoreApplication::translate("QRDialog", "<html><head/><body><p><span style=\" font-weight:700;\">Step 1:</span> Install Google Authenticator or any TOTP app on your phone</p></body></html>", nullptr));
        step2Label->setText(QCoreApplication::translate("QRDialog", "<html><head/><body><p><span style=\" font-weight:700;\">Step 2:</span> Tap the link below to open in your authenticator app:</p></body></html>", nullptr));
        otpauthLabel->setText(QCoreApplication::translate("QRDialog", "otpauth://", nullptr));
        manualGroup->setTitle(QCoreApplication::translate("QRDialog", "Manual Entry", nullptr));
        manualLabel->setText(QCoreApplication::translate("QRDialog", "<html><head/><body><p><span style=\" font-weight:700;\">Alternative:</span> Enter this secret key manually in your app:</p></body></html>", nullptr));
        copySecretButton->setText(QCoreApplication::translate("QRDialog", "\360\237\223\213 Copy Secret to Clipboard", nullptr));
        doneButton->setText(QCoreApplication::translate("QRDialog", "\342\234\223 Done - Continue to Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QRDialog: public Ui_QRDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRDIALOG_H
