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
    QLabel *PDF;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QLineEdit *lineEdit_8;
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
"    padding: 3px 3px;\n"
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
"    padding: 3px 3px;\n"
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
"    padding: 3px 3px;\n"
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
"    padding: 3px 3px;\n"
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
"    padding: 3px 3px;\n"
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
"    padding: 3px 3px;\n"
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
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget->rowCount() < 12)
            tableWidget->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(2, 5, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(3, 3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(3, 4, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(3, 5, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(4, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setItem(4, 3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(4, 4, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setItem(4, 5, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setItem(5, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setItem(5, 2, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setItem(5, 3, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setItem(5, 4, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setItem(5, 5, __qtablewidgetitem47);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(350, 100, 681, 281));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: white;\n"
"	color : black;  \n"
" 	alternate-background-color: #E6F2FA;\n"
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
"    font-size: 12px;\n"
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
"    font-size: 12px;\n"
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
"    font-size: 12px;\n"
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
"    font-size: 12px;\n"
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
"    font-size: 12px;\n"
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
"    font-size: 12px;\n"
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
        lineEdit_8 = new QLineEdit(tab);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(820, 410, 113, 26));
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
        menubar->setGeometry(QRect(0, 0, 1354, 21));
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
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Adress", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Phone Nbr", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "12345678", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Ahmed", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Ben Ali", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "ahmed.benali@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Tunis, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "+216 71 123 456", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(1, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "87654321", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(1, 1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Fatma", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Sassi", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(1, 3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "fatma.sassi@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Sfax, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "+216 74 987 654", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(2, 0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "11223344", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(2, 1);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Mohamed", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(2, 2);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Triki", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(2, 3);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "mohamed.triki@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(2, 4);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Sousse, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(2, 5);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "+216 73 112 233", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(3, 0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "55667788", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(3, 1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Leila", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(3, 2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Mejri", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(3, 3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "leila.mejri@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(3, 4);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "Ariana, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(3, 5);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "+216 70 556 677", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(4, 0);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "99887766", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(4, 1);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Karim", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(4, 2);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "Hamdi", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(4, 3);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "karim.hamdi@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(4, 4);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "Bizerte, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(4, 5);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "+216 72 998 877", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(5, 0);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "33445566", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(5, 1);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "Sarra", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->item(5, 2);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "Bouaziz", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->item(5, 3);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "sarra.bouaziz@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->item(5, 4);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "Gabes, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->item(5, 5);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "+216 75 334 455", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

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
#if QT_CONFIG(tooltip)
        pushButton_10->setToolTip(QCoreApplication::translate("MainWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_10->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_11->setToolTip(QCoreApplication::translate("MainWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_11->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_12->setToolTip(QCoreApplication::translate("MainWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_12->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_13->setToolTip(QCoreApplication::translate("MainWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_13->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_14->setToolTip(QCoreApplication::translate("MainWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_14->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_15->setToolTip(QCoreApplication::translate("MainWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_15->setText(QString());
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "CIN", nullptr));
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
