/********************************************************************************
** Form generated from reading UI file 'chatbotdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOTDIALOG_H
#define UI_CHATBOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_chatbotdialog
{
public:
    QPushButton *sendBtn;
    QTextEdit *chatView;
    QLineEdit *inputBox;

    void setupUi(QDialog *chatbotdialog)
    {
        if (chatbotdialog->objectName().isEmpty())
            chatbotdialog->setObjectName("chatbotdialog");
        chatbotdialog->resize(710, 428);
        sendBtn = new QPushButton(chatbotdialog);
        sendBtn->setObjectName("sendBtn");
        sendBtn->setGeometry(QRect(560, 350, 93, 29));
        sendBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        chatView = new QTextEdit(chatbotdialog);
        chatView->setObjectName("chatView");
        chatView->setGeometry(QRect(0, 20, 671, 291));
        inputBox = new QLineEdit(chatbotdialog);
        inputBox->setObjectName("inputBox");
        inputBox->setGeometry(QRect(20, 350, 521, 31));
        inputBox->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f4faff;\n"
"    border: 2px solid #003271;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #1e6fd9;\n"
"    background-color: #ffffff;\n"
"}"));

        retranslateUi(chatbotdialog);

        QMetaObject::connectSlotsByName(chatbotdialog);
    } // setupUi

    void retranslateUi(QDialog *chatbotdialog)
    {
        chatbotdialog->setWindowTitle(QCoreApplication::translate("chatbotdialog", "Dialog", nullptr));
        sendBtn->setText(QCoreApplication::translate("chatbotdialog", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatbotdialog: public Ui_chatbotdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOTDIALOG_H
