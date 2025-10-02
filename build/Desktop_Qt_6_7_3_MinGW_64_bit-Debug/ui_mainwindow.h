/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *logo_main;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox;
    QTableWidget *table_payment;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_6;
    QWidget *fa;
    QLabel *label_15;
    QTableWidget *tableWidget;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_6;
    QLabel *label_16;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_2;
    QPushButton *pushButton_11;
    QPushButton *Paymen_button;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QLabel *label_17;
    QMenuBar *menubar;
    QMenu *menuVoltShop;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1302, 648);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        logo_main = new QLabel(centralwidget);
        logo_main->setObjectName("logo_main");
        logo_main->setGeometry(QRect(5, 5, 100, 80));
        logo_main->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/logo.jpeg")));
        logo_main->setScaledContents(true);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(110, 0, 1181, 601));
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
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 40, 301, 461));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: rgb(173, 216, 230);\n"
"    border: 2px solid #00A3E0;\n"
"    border-radius: 6px;\n"
"    margin-top: 20px; /* space for the title */\n"
"    padding: 10px;\n"
"    font-family: Segoe UI, Arial;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #003271;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 2px 8px;\n"
"    background-color: #00A3E0;\n"
"    color: white;\n"
"    border-radius: 4px;\n"
"}\n"
""));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 100, 121, 28));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}\n"
""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 70, 101, 20));
        label->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(10, 180, 121, 28));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 150, 63, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 240, 101, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 310, 41, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 380, 63, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(10, 340, 141, 29));
        dateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    background-color: #f4faff;\n"
"    border: 2px solid #003271;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid #1e6fd9;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border-left: 1px solid #003271;\n"
"    background-color: #003271;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/images/ressource/icons8-calendar-50.png);\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}\n"
""));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 0, 131, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(10, 270, 161, 31));
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #f4faff;\n"
"    border: 2px solid #003271;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #1e6fd9;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border-left: 1px solid #003271;\n"
"    background-color: #003271;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/ressource/arrow-down.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
""));
        comboBox_2->setIconSize(QSize(50, 50));
        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(10, 410, 131, 28));
        comboBox_3->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #f4faff;\n"
"    border: 2px solid #003271;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #1e6fd9;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border-left: 1px solid #003271;\n"
"    background-color: #003271;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/ressource/arrow-down.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
""));
        lineEdit->raise();
        label->raise();
        lineEdit_2->raise();
        label_2->raise();
        label_4->raise();
        label_5->raise();
        label_3->raise();
        dateEdit->raise();
        pushButton->raise();
        comboBox_2->raise();
        comboBox_3->raise();
        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(960, 127, 121, 31));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #f4faff;\n"
"    border: 2px solid #003271;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #1e6fd9;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border-left: 1px solid #003271;\n"
"    background-color: #003271;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/ressource/arrow-down.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
""));
        table_payment = new QTableWidget(tab);
        if (table_payment->columnCount() < 5)
            table_payment->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_payment->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_payment->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_payment->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_payment->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_payment->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (table_payment->rowCount() < 4)
            table_payment->setRowCount(4);
        table_payment->setObjectName("table_payment");
        table_payment->setGeometry(QRect(570, 170, 521, 221));
        table_payment->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(740, 130, 121, 31));
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
        pushButton_4->setGeometry(QRect(470, 470, 151, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(610, 130, 113, 28));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}\n"
""));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(460, 130, 141, 20));
        label_7->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(0, 0, 0);"));
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(30, 510, 101, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(170, 510, 101, 31));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(650, 470, 151, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_8->setGeometry(QRect(910, 480, 101, 31));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        lineEdit_6 = new QLineEdit(tab);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(1030, 480, 113, 28));
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}\n"
""));
        tabWidget->addTab(tab, QString());
        fa = new QWidget();
        fa->setObjectName("fa");
        label_15 = new QLabel(fa);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(580, 10, 571, 341));
        label_15->setStyleSheet(QString::fromUtf8(" background-image: url(:/images/ressource/chart2.png);"));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/chart2.png")));
        label_15->setScaledContents(true);
        tableWidget = new QTableWidget(fa);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem12);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(920, 380, 231, 121));
        label_8 = new QLabel(fa);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 10, 501, 411));
        label_8->setStyleSheet(QString::fromUtf8(" background-image: url(:/images/ressource/testchart.png);"));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/testchart.png")));
        label_8->setScaledContents(true);
        label_10 = new QLabel(fa);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(380, 190, 91, 21));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 180, 255);\n"
"font: 12pt \"Segoe UI\";"));
        label_9 = new QLabel(fa);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 200, 61, 21));
        label_9->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 107, 53);"));
        label_13 = new QLabel(fa);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(130, 220, 49, 16));
        label_13->setStyleSheet(QString::fromUtf8("color:black;\n"
"font: 11pt \"Segoe UI\";"));
        label_11 = new QLabel(fa);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(210, 370, 51, 21));
        label_11->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);"));
        label_12 = new QLabel(fa);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(280, 220, 49, 16));
        label_12->setStyleSheet(QString::fromUtf8("color:black;\n"
"font: 11pt \"Segoe UI\";"));
        label_14 = new QLabel(fa);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(220, 300, 31, 16));
        label_14->setStyleSheet(QString::fromUtf8("color:black;\n"
"font: 11pt \"Segoe UI\";"));
        label_6 = new QLabel(fa);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 20, 481, 51));
        label_6->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"font: 28pt \"Segoe UI\";\n"
""));
        label_16 = new QLabel(fa);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(560, 410, 341, 51));
        label_16->setStyleSheet(QString::fromUtf8("\n"
"font: 24pt \"Segoe UI\";"));
        tabWidget->addTab(fa, QString());
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, -30, 111, 631));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);"));
        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(-10, 570, 121, 51));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: rgb(0, 0, 127);\n"
"    color: red;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"    qproperty-icon: url(:/images/ressource/log-out.png);\n"
"    qproperty-iconSize: 25px 25px;\n"
"}\n"
"QPushButton:hover { background-color: Red; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_9->setIconSize(QSize(25, 25));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 150, 91, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: blue;   /* base color */\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 8px 14px;\n"
"    font-weight: bold;\n"
"    transition: all 0.3s ease;   /* smooth hover effect */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background-color: #004a9f;   /* lighter blue */\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #00204d;   /* darker blue */\n"
"    padding-left: 16px;          /* slight \"press\" animation */\n"
"    padding-top: 9px;\n"
"}\n"
"\n"
"/* Disabled state */\n"
"QPushButton:disabled {\n"
"    background-color: #7f8c8d;\n"
"    color: #dfe6e9;\n"
"}\n"
""));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(45, 40));
        pushButton_11 = new QPushButton(groupBox_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(10, 220, 91, 61));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: blue;   /* base color */\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 8px 14px;\n"
"    font-weight: bold;\n"
"    transition: all 0.3s ease;   /* smooth hover effect */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background-color: #004a9f;   /* lighter blue */\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #00204d;   /* darker blue */\n"
"    padding-left: 16px;          /* slight \"press\" animation */\n"
"    padding-top: 9px;\n"
"}\n"
"\n"
"/* Disabled state */\n"
"QPushButton:disabled {\n"
"    background-color: #7f8c8d;\n"
"    color: #dfe6e9;\n"
"}\n"
""));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::NetworkWired));
        pushButton_11->setIcon(icon1);
        pushButton_11->setIconSize(QSize(45, 45));
        Paymen_button = new QPushButton(groupBox_2);
        Paymen_button->setObjectName("Paymen_button");
        Paymen_button->setGeometry(QRect(10, 360, 91, 61));
        Paymen_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: blue;   /* base color */\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 8px 14px;\n"
"    font-weight: bold;\n"
"    qproperty-icon: url(:/images/ressource/credit-card.png);\n"
"    qproperty-iconSize: 100px 100px;\n"
"    transition: all 0.3s ease;   /* smooth hover effect */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background-color: #004a9f;   /* lighter blue */\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #00204d;   /* darker blue */\n"
"    padding-left: 16px;          /* slight \"press\" animation */\n"
"    padding-top: 9px;\n"
"}\n"
"\n"
"/* Disabled state */\n"
"QPushButton:disabled {\n"
"    background-color: #7f8c8d;\n"
"    color: #dfe6e9;\n"
"}\n"
""));
        pushButton_14 = new QPushButton(groupBox_2);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(10, 290, 91, 61));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: blue;   /* base color */\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 8px 14px;\n"
"    font-weight: bold;\n"
"    transition: all 0.3s ease;   /* smooth hover effect */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background-color: #004a9f;   /* lighter blue */\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #00204d;   /* darker blue */\n"
"    padding-left: 16px;          /* slight \"press\" animation */\n"
"    padding-top: 9px;\n"
"}\n"
"\n"
"/* Disabled state */\n"
"QPushButton:disabled {\n"
"    background-color: #7f8c8d;\n"
"    color: #dfe6e9;\n"
"}\n"
""));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste));
        pushButton_14->setIcon(icon2);
        pushButton_14->setIconSize(QSize(45, 45));
        pushButton_15 = new QPushButton(groupBox_2);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(10, 430, 91, 61));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: blue;   /* base color */\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 8px 14px;\n"
"    font-weight: bold;\n"
"    transition: all 0.3s ease;   /* smooth hover effect */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background-color: #004a9f;   /* lighter blue */\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #00204d;   /* darker blue */\n"
"    padding-left: 16px;          /* slight \"press\" animation */\n"
"    padding-top: 9px;\n"
"}\n"
"\n"
"/* Disabled state */\n"
"QPushButton:disabled {\n"
"    background-color: #7f8c8d;\n"
"    color: #dfe6e9;\n"
"}\n"
""));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::Phone));
        pushButton_15->setIcon(icon3);
        pushButton_15->setIconSize(QSize(45, 45));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(-10, 30, 131, 101));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/logo.jpeg")));
        label_17->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1302, 21));
        menuVoltShop = new QMenu(menubar);
        menuVoltShop->setObjectName("menuVoltShop");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuVoltShop->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logo_main->setText(QString());
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Payment_ID", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Pay_Method", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add Payment", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Select the Method", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Credit Card", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Cash", nullptr));

        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "Select status", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "Payed ", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "in progress", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "Canceled ", nullptr));

        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Sort By", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Amount", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Date", nullptr));

        QTableWidgetItem *___qtablewidgetitem = table_payment->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Payment_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_payment->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_payment->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Pay_Method", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_payment->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_payment->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Exprot to PDF", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", " ID_Payment", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Search Payment By:", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Export to Excel", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Home", nullptr));
        label_15->setText(QString());
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "ID_Payment", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "750", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(1, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(1, 1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(2, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(2, 1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "375", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_8->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Completed", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Pending", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "40 %", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Failed", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "40 %", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "20 %", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Payment Status Distribution", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Top 3 highest Pyments :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(fa), QCoreApplication::translate("MainWindow", "Fonctionality", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        pushButton_9->setText(QString());
        pushButton_2->setText(QString());
        pushButton_11->setText(QString());
        Paymen_button->setText(QString());
        pushButton_14->setText(QString());
        pushButton_15->setText(QString());
        label_17->setText(QString());
        menuVoltShop->setTitle(QCoreApplication::translate("MainWindow", "VoltShop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
