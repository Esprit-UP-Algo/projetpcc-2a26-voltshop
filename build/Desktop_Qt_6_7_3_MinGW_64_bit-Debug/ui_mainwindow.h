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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
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
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;
    QComboBox *comboBox;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLabel *PDF;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QWidget *tab_2;
    QLabel *stat;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_8;
    QPushButton *quit;
    QLabel *logo;
    QLabel *logo2;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1354, 593);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(200, 0, 1051, 541));
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
        groupBox->setGeometry(QRect(10, 50, 301, 401));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 41, 20));
        label->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 100, 101, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 240, 71, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 170, 101, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 300, 101, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 360, 81, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(150, 40, 113, 26));
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
"}"));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(150, 170, 113, 26));
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
"}"));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(150, 240, 113, 26));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(150, 300, 113, 26));
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
"}"));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(150, 360, 113, 26));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(150, 100, 113, 26));
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
"}"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 460, 93, 29));
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
        pushButton_3->setGeometry(QRect(160, 460, 93, 29));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 12)
            tableWidget->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem10);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(350, 100, 681, 281));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(920, 60, 76, 26));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(840, 60, 63, 20));
        label_7->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";"));
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(340, 70, 161, 20));
        label_8->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";"));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(660, 60, 93, 29));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_6->setGeometry(QRect(520, 440, 141, 31));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 40, 121, 29));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_7->setGeometry(QRect(940, 410, 93, 29));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        lineEdit_7 = new QLineEdit(tab);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(500, 60, 131, 31));
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_8 = new QLineEdit(tab);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(810, 410, 113, 26));
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        PDF = new QLabel(tab);
        PDF->setObjectName("PDF");
        PDF->setGeometry(QRect(470, 430, 41, 41));
        PDF->setPixmap(QPixmap(QString::fromUtf8("PDF.png")));
        PDF->setScaledContents(true);
        pushButton_10 = new QPushButton(tab);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(350, 140, 31, 31));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(173, 216, 230);\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(135, 206, 250); /* un bleu un peu plus clair */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 149, 237); /* un bleu un peu plus fonc\303\251 */\n"
"}\n"
""));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        pushButton_10->setIcon(icon);
        pushButton_11 = new QPushButton(tab);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(350, 180, 31, 31));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(173, 216, 230);\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(135, 206, 250); /* un bleu un peu plus clair */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 149, 237); /* un bleu un peu plus fonc\303\251 */\n"
"}\n"
""));
        pushButton_11->setIcon(icon);
        pushButton_12 = new QPushButton(tab);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(350, 300, 31, 31));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(173, 216, 230);\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(135, 206, 250); /* un bleu un peu plus clair */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 149, 237); /* un bleu un peu plus fonc\303\251 */\n"
"}\n"
""));
        pushButton_12->setIcon(icon);
        pushButton_13 = new QPushButton(tab);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(350, 260, 31, 31));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(173, 216, 230);\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(135, 206, 250); /* un bleu un peu plus clair */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 149, 237); /* un bleu un peu plus fonc\303\251 */\n"
"}\n"
""));
        pushButton_13->setIcon(icon);
        pushButton_14 = new QPushButton(tab);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(350, 220, 31, 31));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(173, 216, 230);\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(135, 206, 250); /* un bleu un peu plus clair */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 149, 237); /* un bleu un peu plus fonc\303\251 */\n"
"}\n"
""));
        pushButton_14->setIcon(icon);
        pushButton_15 = new QPushButton(tab);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(350, 330, 31, 31));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(173, 216, 230);\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(135, 206, 250); /* un bleu un peu plus clair */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 149, 237); /* un bleu un peu plus fonc\303\251 */\n"
"}\n"
""));
        pushButton_15->setIcon(icon);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        stat = new QLabel(tab_2);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(30, 90, 451, 381));
        stat->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/ChatGPT Image 25 sept. 2025, 18_40_45.png")));
        stat->setScaledContents(true);
        tabWidget->addTab(tab_2, QString());
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, -10, 191, 541));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 69, 153);"));
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(10, 100, 171, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #5AB4F0;; }\n"
"QPushButton:pressed { background-color: #5AB4F0; }"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        pushButton_8->setIcon(icon1);
        pushButton_8->setIconSize(QSize(50, 50));
        quit = new QPushButton(groupBox_2);
        quit->setObjectName("quit");
        quit->setGeometry(QRect(10, 490, 171, 31));
        quit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #5AB4F0; }\n"
"QPushButton:pressed { background-color: rgb(0, 69, 153);; }"));
        logo = new QLabel(groupBox_2);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(30, 10, 131, 81));
        logo->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/WhatsApp Image 2025-09-16 at 13.04.56 (1).jpeg")));
        logo->setScaledContents(true);
        logo2 = new QLabel(groupBox_2);
        logo2->setObjectName("logo2");
        logo2->setGeometry(QRect(30, 10, 131, 81));
        logo2->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/WhatsApp Image 2025-09-16 at 13.04.56 (1).jpeg")));
        logo2->setScaledContents(true);
        pushButton_16 = new QPushButton(groupBox_2);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(10, 240, 171, 61));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #5AB4F0;; }\n"
"QPushButton:pressed { background-color: #5AB4F0;; }"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste));
        pushButton_16->setIcon(icon2);
        pushButton_16->setIconSize(QSize(50, 50));
        pushButton_17 = new QPushButton(groupBox_2);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(10, 380, 171, 61));
        pushButton_17->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #5AB4F0; }\n"
"QPushButton:pressed { background-color: #5AB4F0;; }"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::Phone));
        pushButton_17->setIcon(icon3);
        pushButton_17->setIconSize(QSize(50, 50));
        pushButton_18 = new QPushButton(groupBox_2);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(10, 170, 171, 61));
        pushButton_18->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #5AB4F0; }\n"
"QPushButton:pressed { background-color:#5AB4F0; }"));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::NetworkWired));
        pushButton_18->setIcon(icon4);
        pushButton_18->setIconSize(QSize(50, 50));
        pushButton_19 = new QPushButton(groupBox_2);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(10, 310, 171, 61));
        pushButton_19->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #5AB4F0; }\n"
"QPushButton:pressed { background-color:#5AB4F0; }\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/assests/creditcard.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_19->setIcon(icon5);
        pushButton_19->setIconSize(QSize(50, 50));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1354, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "CIN:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "First Name:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Last Name:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Phone nbr:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Adress:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "CIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Name", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Adress", nullptr));
        comboBox->setItemText(2, QString());

        label_7->setText(QCoreApplication::translate("MainWindow", "Sort By:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Search for a client:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Export to PDF", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add Client", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("MainWindow", " CIN,Name,Email", nullptr));
        PDF->setText(QString());
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        pushButton_15->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Home", nullptr));
        stat->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Functionality", nullptr));
        groupBox_2->setTitle(QString());
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "CLIENTS", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "LOG OUT", nullptr));
        logo->setText(QString());
        logo2->setText(QString());
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "STOCKS", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "LOCAL", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "COMMANDS", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Transaction", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
