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
    QLineEdit *P_id;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QComboBox *comboBox_3;
    QComboBox *comboBox_2;
    QComboBox *comboBoxsort;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_6;
    QTableWidget *tableWidget_2;
    QPushButton *darkmode_button;
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
    QPushButton *logout_b;
    QPushButton *pushButton_2;
    QPushButton *pushButton_11;
    QPushButton *Paymen_button;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QLabel *label_17;
    QPushButton *home_button;
    QMenuBar *menubar;
    QMenu *menuVoltShop;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1439, 648);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        logo_main = new QLabel(centralwidget);
        logo_main->setObjectName("logo_main");
        logo_main->setGeometry(QRect(5, 5, 100, 80));
        logo_main->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/logo.jpeg")));
        logo_main->setScaledContents(true);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(160, 0, 1271, 601));
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
        groupBox->setGeometry(QRect(20, 60, 301, 461));
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
        P_id = new QLineEdit(groupBox);
        P_id->setObjectName("P_id");
        P_id->setGeometry(QRect(10, 100, 121, 28));
        P_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 180, 121, 28));
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
        dateEdit->setGeometry(QRect(10, 340, 141, 31));
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
        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(10, 270, 161, 31));
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
        comboBox_3->setIconSize(QSize(50, 50));
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(10, 410, 131, 28));
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
        P_id->raise();
        label->raise();
        lineEdit->raise();
        label_2->raise();
        label_4->raise();
        label_5->raise();
        label_3->raise();
        dateEdit->raise();
        pushButton->raise();
        comboBox_3->raise();
        comboBox_2->raise();
        comboBoxsort = new QComboBox(tab);
        comboBoxsort->addItem(QString());
        comboBoxsort->addItem(QString());
        comboBoxsort->addItem(QString());
        comboBoxsort->setObjectName("comboBoxsort");
        comboBoxsort->setGeometry(QRect(960, 127, 121, 31));
        comboBoxsort->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(610, 130, 113, 31));
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
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(530, 470, 151, 41));
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
        lineEdit_6->setGeometry(QRect(1030, 480, 113, 31));
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
        tableWidget_2 = new QTableWidget(tab);
        if (tableWidget_2->columnCount() < 5)
            tableWidget_2->setColumnCount(5);
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
        if (tableWidget_2->rowCount() < 8)
            tableWidget_2->setRowCount(8);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(530, 170, 531, 271));
        tableWidget_2->setStyleSheet(QString::fromUtf8(""));
        darkmode_button = new QPushButton(tab);
        darkmode_button->setObjectName("darkmode_button");
        darkmode_button->setGeometry(QRect(0, 0, 51, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/ressource/night-mode.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        darkmode_button->setIcon(icon);
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
        groupBox_2->setGeometry(QRect(0, -30, 161, 631));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);"));
        logout_b = new QPushButton(groupBox_2);
        logout_b->setObjectName("logout_b");
        logout_b->setGeometry(QRect(10, 570, 141, 51));
        logout_b->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        logout_b->setIconSize(QSize(25, 25));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 220, 141, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #002050;; }\n"
"QPushButton:pressed { background-color: rgb(0, 69, 153);; }"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(45, 40));
        pushButton_11 = new QPushButton(groupBox_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(10, 290, 141, 61));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #002050;; }\n"
"QPushButton:pressed { background-color: rgb(0, 69, 153);; }"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::NetworkWired));
        pushButton_11->setIcon(icon2);
        pushButton_11->setIconSize(QSize(45, 45));
        Paymen_button = new QPushButton(groupBox_2);
        Paymen_button->setObjectName("Paymen_button");
        Paymen_button->setGeometry(QRect(10, 430, 141, 61));
        Paymen_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 8pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #002050;; }\n"
"QPushButton:pressed { background-color: rgb(0, 69, 153);; }"));
        pushButton_14 = new QPushButton(groupBox_2);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(10, 360, 141, 61));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #002050;; }\n"
"QPushButton:pressed { background-color: rgb(0, 69, 153);; }"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste));
        pushButton_14->setIcon(icon3);
        pushButton_14->setIconSize(QSize(45, 45));
        pushButton_15 = new QPushButton(groupBox_2);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(10, 500, 141, 61));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #002050;; }\n"
"QPushButton:pressed { background-color: rgb(0, 69, 153);; }"));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        pushButton_15->setIcon(icon4);
        pushButton_15->setIconSize(QSize(45, 45));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(0, 30, 161, 101));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/logo.jpeg")));
        label_17->setScaledContents(true);
        home_button = new QPushButton(groupBox_2);
        home_button->setObjectName("home_button");
        home_button->setGeometry(QRect(10, 150, 141, 61));
        home_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #002050;; }\n"
"QPushButton:pressed { background-color: rgb(0, 69, 153);; }"));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        home_button->setIcon(icon5);
        home_button->setIconSize(QSize(45, 40));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1439, 21));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "VoltShop Desktop App", nullptr));
        logo_main->setText(QString());
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "  ID :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Amount :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Pay_Method :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", " Date :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Status :", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add Payment", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "Select the Method", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "Credit Card", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "Cash", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Select status", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Payed ", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "in progress", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "Canceled ", nullptr));

        comboBoxsort->setItemText(0, QCoreApplication::translate("MainWindow", "Sort By", nullptr));
        comboBoxsort->setItemText(1, QCoreApplication::translate("MainWindow", "Amount", nullptr));
        comboBoxsort->setItemText(2, QCoreApplication::translate("MainWindow", "Date", nullptr));

        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "         ID", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Search Payment By:", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Export to Excel", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "Payment_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Pay_Method", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        darkmode_button->setText(QString());
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
        logout_b->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Order ", nullptr));
        Paymen_button->setText(QCoreApplication::translate("MainWindow", "Transaction", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Stock", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Employee", nullptr));
        label_17->setText(QString());
        home_button->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        menuVoltShop->setTitle(QCoreApplication::translate("MainWindow", "VoltShop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
