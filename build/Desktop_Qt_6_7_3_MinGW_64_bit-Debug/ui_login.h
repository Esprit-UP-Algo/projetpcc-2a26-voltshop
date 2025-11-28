/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *logoLabel;
    QGroupBox *loginGroupBox;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *cancelButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *titleLabel;
    QLabel *statusLabel;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(450, 600);
        LoginWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"  background-color: rgb(0, 0, 127);\n"
"    background-image: radial-gradient(circle, #3f51b5 1px, transparent 1px);\n"
"    background-size: 20px 20px;\n"
"}\n"
"\n"
"QPushButton {\n"
"    font: 900 12pt \"Segoe UI\";\n"
"    background-color: #1a237e;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 12px 20px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #283593;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #0d1a5c;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #90caf9;\n"
"    border-radius: 8px;\n"
"    padding: 12px 16px;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"    font-family: \"Segoe UI\", Arial;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #9e9e9e;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #1a237e;\n"
"    font-family: \"Segoe UI"
                        "\", Arial;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    background-color: #90caf9;\n"
"    border: 2px solid #64b5f6;\n"
"    border-radius: 15px;\n"
"    margin-top: 20px;\n"
"    padding: 25px;\n"
"    font-family: \"Segoe UI\", Arial;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 10px 20px;\n"
"    background-color: #1a237e;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"}"));
        logoLabel = new QLabel(LoginWindow);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setGeometry(QRect(125, 30, 200, 120));
        logoLabel->setStyleSheet(QString::fromUtf8("background-color: white; border-radius: 10px; padding: 10px;"));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/logo.jpeg")));
        logoLabel->setScaledContents(true);
        loginGroupBox = new QGroupBox(LoginWindow);
        loginGroupBox->setObjectName("loginGroupBox");
        loginGroupBox->setGeometry(QRect(50, 200, 350, 291));
        usernameLineEdit = new QLineEdit(loginGroupBox);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(30, 80, 290, 51));
        passwordLineEdit = new QLineEdit(loginGroupBox);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(30, 160, 290, 51));
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        loginButton = new QPushButton(loginGroupBox);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(30, 230, 140, 41));
        loginButton->setIconSize(QSize(16, 16));
        cancelButton = new QPushButton(loginGroupBox);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(180, 230, 140, 40));
        label_2 = new QLabel(loginGroupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 60, 321, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color:white;\n"
""));
        label_3 = new QLabel(loginGroupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 140, 331, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color:white;\n"
""));
        titleLabel = new QLabel(loginGroupBox);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(0, 0, 231, 30));
        titleLabel->setStyleSheet(QString::fromUtf8("background-color: blue; color: white; font: bold 16pt \"Segoe UI\"; border-radius: 8px; padding: 5px;"));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        statusLabel = new QLabel(LoginWindow);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(50, 500, 350, 25));
        statusLabel->setStyleSheet(QString::fromUtf8("color: #d32f2f; font-weight: bold; font-size: 12pt;"));
        statusLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "VoltShop - Login", nullptr));
        logoLabel->setText(QString());
        loginGroupBox->setTitle(QString());
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Enter your username", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Enter your password", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        cancelButton->setText(QCoreApplication::translate("LoginWindow", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        titleLabel->setText(QCoreApplication::translate("LoginWindow", "Login to VoltShop", nullptr));
        statusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
