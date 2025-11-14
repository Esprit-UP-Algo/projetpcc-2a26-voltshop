/********************************************************************************
** Form generated from reading UI file 'CommandeWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDEWINDOW_H
#define UI_COMMANDEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandeWindow
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_6;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QDateEdit *dateEdit_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_10;
    QComboBox *comboBox_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QWidget *tab_2;
    QLabel *label_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1241, 620);
        tabWidget = new QTabWidget(Form);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 1231, 611));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 1px solid #00A3E0;\n"
"    background: #E6F2FA;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"/* Tabs container */\n"
"QTabBar::tab {\n"
"    background: #003271;\n"
"    color: white;\n"
"    padding: 8px 16px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    margin-right: 2px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Selected tab */\n"
"QTabBar::tab:selected {\n"
"    background: #ADD8E6;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QTabBar::tab:hover {\n"
"    background: #004599;\n"
"    color: white;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        tableWidget_2 = new QTableWidget(tab);
        if (tableWidget_2->columnCount() < 6)
            tableWidget_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget_2->rowCount() < 4)
            tableWidget_2->setRowCount(4);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(350, 140, 751, 191));
        tableWidget_2->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: white;\n"
"    alternate-background-color: #E6F2FA;\n"
"    gridline-color: #ADD8E6;\n"
"    border: 1px solid #ADD8E6;\n"
"    selection-background-color: #003271;\n"
"    selection-color: white;\n"
"    font-family: Segoe UI, Arial;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #ADD8E6;\n"
"    color: black;\n"
"    padding: 6px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #ADD8E6;\n"
"    border: none;\n"
"}"));
        tableWidget_2->setRowCount(4);
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(480, 380, 151, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(810, 380, 141, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(1050, 500, 121, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(500, 90, 241, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(360, 80, 121, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 40, 291, 431));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        lineEdit_6 = new QLineEdit(groupBox_2);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(120, 80, 113, 28));
        lineEdit_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_7 = new QLineEdit(groupBox_2);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(120, 210, 113, 28));
        lineEdit_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_8 = new QLineEdit(groupBox_2);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(120, 280, 113, 28));
        lineEdit_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_9 = new QLineEdit(groupBox_2);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(120, 350, 113, 28));
        lineEdit_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        dateEdit_2 = new QDateEdit(groupBox_2);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(120, 140, 110, 29));
        dateEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 30, 91, 21));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 900 9pt \"Swis721 Blk BT\";"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 150, 63, 20));
        label_8->setStyleSheet(QString::fromUtf8("\n"
"font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 210, 71, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 290, 63, 20));
        label_10->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 350, 63, 20));
        label_11->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 90, 63, 20));
        label_12->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        lineEdit_10 = new QLineEdit(groupBox_2);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(110, 30, 113, 28));
        lineEdit_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_2 = new QComboBox(tab);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(970, 90, 82, 28));
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(890, 90, 91, 31));
        label->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 20, 141, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_8 = new QPushButton(tab);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(30, 500, 90, 29));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_9 = new QPushButton(tab);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(170, 500, 90, 29));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_2 = new QLabel(tab_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 30, 731, 481));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/stat2.png")));
        label_2->setScaledContents(true);
        tabWidget->addTab(tab_2, QString());

        retranslateUi(Form);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("CommandeWindow", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CommandeWindow", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CommandeWindow", "client", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CommandeWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CommandeWindow", "Products", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CommandeWindow", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CommandeWindow", "Status", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CommandeWindow", "Edit Order", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CommandeWindow", "Delete Order", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CommandeWindow", "Export PDF ", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("CommandeWindow", "Search by ID, Date or Status ", nullptr));
        pushButton_6->setText(QCoreApplication::translate("CommandeWindow", "\360\237\224\215 Search :", nullptr));
        groupBox_2->setTitle(QString());
        label_7->setText(QCoreApplication::translate("CommandeWindow", "code", nullptr));
        label_8->setText(QCoreApplication::translate("CommandeWindow", "Date", nullptr));
        label_9->setText(QCoreApplication::translate("CommandeWindow", "Products", nullptr));
        label_10->setText(QCoreApplication::translate("CommandeWindow", "Total", nullptr));
        label_11->setText(QCoreApplication::translate("CommandeWindow", "Status", nullptr));
        label_12->setText(QCoreApplication::translate("CommandeWindow", "client", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("CommandeWindow", "status", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("CommandeWindow", "date", nullptr));

        label->setText(QCoreApplication::translate("CommandeWindow", "sort by :", nullptr));
        pushButton->setText(QCoreApplication::translate("CommandeWindow", "Add Order", nullptr));
        pushButton_8->setText(QCoreApplication::translate("CommandeWindow", "Confirm", nullptr));
        pushButton_9->setText(QCoreApplication::translate("CommandeWindow", "cancel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CommandeWindow", " Home", nullptr));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CommandeWindow", "Fonctionality", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommandeWindow: public Ui_CommandeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDEWINDOW_H
