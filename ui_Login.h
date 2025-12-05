/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QGroupBox *loginGroupBox;
    QLineEdit *id;
    QLineEdit *mdp;
    QPushButton *connect;
    QPushButton *cancelButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *titleLabel;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(539, 622);
        Login->setStyleSheet(QString::fromUtf8("QDialog#Login {\n"
"    background-image: url(:/images/ressource/LoginBack.jpg);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-color: #02051a;\n"
"}"));
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 80, 221, 171));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/logo12.png")));
        label->setScaledContents(true);
        loginGroupBox = new QGroupBox(Login);
        loginGroupBox->setObjectName("loginGroupBox");
        loginGroupBox->setGeometry(QRect(70, 270, 400, 310));
        loginGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox#loginGroupBox {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(30, 60, 120, 0.25), stop:0.5 rgba(20, 45, 100, 0.22), stop:1 rgba(15, 35, 85, 0.28));\n"
"    border-radius: 25px;\n"
"    border: 2px solid rgba(80, 180, 255, 0.5);\n"
"}"));
        id = new QLineEdit(loginGroupBox);
        id->setObjectName("id");
        id->setGeometry(QRect(30, 85, 340, 48));
        id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: white;\n"
"    border-radius: 15px;\n"
"    border: 2px solid rgba(100, 180, 255, 0.4);\n"
"    padding: 12px 16px;\n"
"    font-size: 13px;\n"
"    color: #1a1a1a;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00BFFF;\n"
"    background: #ffffff;\n"
"}"));
        mdp = new QLineEdit(loginGroupBox);
        mdp->setObjectName("mdp");
        mdp->setGeometry(QRect(30, 170, 340, 48));
        mdp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: white;\n"
"    border-radius: 15px;\n"
"    border: 2px solid rgba(100, 180, 255, 0.4);\n"
"    padding: 12px 16px;\n"
"    font-size: 13px;\n"
"    color: #1a1a1a;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00BFFF;\n"
"    background: #ffffff;\n"
"}"));
        mdp->setEchoMode(QLineEdit::EchoMode::Password);
        connect = new QPushButton(loginGroupBox);
        connect->setObjectName("connect");
        connect->setGeometry(QRect(30, 245, 160, 48));
        connect->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #00BFFF, stop:1 #0066FF);\n"
"    border-radius: 15px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #33D6FF, stop:1 #3380FF);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: #0066CC;\n"
"}"));
        cancelButton = new QPushButton(loginGroupBox);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(210, 245, 160, 48));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: rgba(255, 255, 255, 0.1);\n"
"    color: #E0F0FF;\n"
"    border-radius: 15px;\n"
"    border: 2px solid rgba(255, 255, 255, 0.3);\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background: rgba(255, 255, 255, 0.2);\n"
"    border: 2px solid rgba(255, 255, 255, 0.5);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: rgba(255, 255, 255, 0.3);\n"
"}"));
        label_2 = new QLabel(loginGroupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 63, 340, 22));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #B3D9FF;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    background: transparent;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 1px;\n"
"}"));
        label_3 = new QLabel(loginGroupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 148, 340, 22));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #B3D9FF;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    background: transparent;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 1px;\n"
"}"));
        titleLabel = new QLabel(loginGroupBox);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(10, 8, 380, 50));
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 22px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 150, 255, 0.4), stop:1 rgba(0, 100, 200, 0.4));\n"
"    border-radius: 12px;\n"
"    border: 2px solid rgba(100, 200, 255, 0.5);\n"
"    padding: 8px;\n"
"}"));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "VoltShop Login", nullptr));
        label->setText(QString());
        loginGroupBox->setTitle(QString());
        id->setPlaceholderText(QCoreApplication::translate("Login", "Enter your username", nullptr));
        mdp->setPlaceholderText(QCoreApplication::translate("Login", "Enter your password", nullptr));
        connect->setText(QCoreApplication::translate("Login", "LOGIN", nullptr));
        cancelButton->setText(QCoreApplication::translate("Login", "CANCEL", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "USERNAME", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "PASSWORD", nullptr));
        titleLabel->setText(QCoreApplication::translate("Login", "\360\237\224\220 Login to VoltShop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
