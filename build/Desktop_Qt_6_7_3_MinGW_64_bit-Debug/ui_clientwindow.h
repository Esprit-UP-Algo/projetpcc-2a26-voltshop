/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGroupBox *groupBox_3;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_21;
    QLineEdit *lineEdit_22;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QTableWidget *tableWidget_3;
    QComboBox *comboBox_3;
    QLabel *label_23;
    QLabel *label_24;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QLineEdit *lineEdit_23;
    QLabel *PDF_3;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QPushButton *pushButton_33;
    QPushButton *pushButton_34;
    QPushButton *pushButton_35;
    QPushButton *pushButton_36;
    QLineEdit *lineEdit_24;
    QPushButton *darkmode_button;
    QWidget *tab_6;
    QLabel *stat_3;

    void setupUi(QWidget *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName("ClientWindow");
        ClientWindow->resize(1398, 658);
        tabWidget = new QTabWidget(ClientWindow);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 20, 1261, 581));
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
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        groupBox_3 = new QGroupBox(tab_5);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 50, 301, 401));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(30, 40, 41, 20));
        label_17->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(30, 100, 101, 20));
        label_18->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(30, 240, 71, 20));
        label_19->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(30, 170, 101, 20));
        label_20->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(30, 300, 101, 20));
        label_21->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(30, 360, 81, 21));
        label_22->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        lineEdit_17 = new QLineEdit(groupBox_3);
        lineEdit_17->setObjectName("lineEdit_17");
        lineEdit_17->setGeometry(QRect(150, 40, 113, 26));
        lineEdit_17->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_18 = new QLineEdit(groupBox_3);
        lineEdit_18->setObjectName("lineEdit_18");
        lineEdit_18->setGeometry(QRect(150, 170, 113, 26));
        lineEdit_18->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_19 = new QLineEdit(groupBox_3);
        lineEdit_19->setObjectName("lineEdit_19");
        lineEdit_19->setGeometry(QRect(150, 240, 113, 26));
        lineEdit_19->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_20 = new QLineEdit(groupBox_3);
        lineEdit_20->setObjectName("lineEdit_20");
        lineEdit_20->setGeometry(QRect(150, 300, 113, 26));
        lineEdit_20->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_21 = new QLineEdit(groupBox_3);
        lineEdit_21->setObjectName("lineEdit_21");
        lineEdit_21->setGeometry(QRect(150, 360, 113, 26));
        lineEdit_21->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_22 = new QLineEdit(groupBox_3);
        lineEdit_22->setObjectName("lineEdit_22");
        lineEdit_22->setGeometry(QRect(150, 100, 113, 26));
        lineEdit_22->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        pushButton_25 = new QPushButton(tab_5);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(30, 460, 93, 29));
        pushButton_25->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_26 = new QPushButton(tab_5);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(160, 460, 93, 29));
        pushButton_26->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        tableWidget_3 = new QTableWidget(tab_5);
        if (tableWidget_3->columnCount() < 6)
            tableWidget_3->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget_3->rowCount() < 12)
            tableWidget_3->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 5, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_3->setItem(2, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_3->setItem(2, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_3->setItem(2, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_3->setItem(2, 3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_3->setItem(2, 4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_3->setItem(2, 5, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_3->setItem(3, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_3->setItem(3, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_3->setItem(3, 2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_3->setItem(3, 3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_3->setItem(3, 4, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_3->setItem(3, 5, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_3->setItem(4, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_3->setItem(4, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_3->setItem(4, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_3->setItem(4, 3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_3->setItem(4, 4, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_3->setItem(4, 5, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_3->setItem(5, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_3->setItem(5, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_3->setItem(5, 2, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_3->setItem(5, 3, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_3->setItem(5, 4, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_3->setItem(5, 5, __qtablewidgetitem47);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(350, 100, 681, 281));
        tableWidget_3->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        comboBox_3 = new QComboBox(tab_5);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(920, 60, 76, 26));
        label_23 = new QLabel(tab_5);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(840, 60, 63, 20));
        label_23->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";"));
        label_24 = new QLabel(tab_5);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(340, 70, 161, 20));
        label_24->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";"));
        pushButton_27 = new QPushButton(tab_5);
        pushButton_27->setObjectName("pushButton_27");
        pushButton_27->setGeometry(QRect(660, 60, 93, 29));
        pushButton_27->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_28 = new QPushButton(tab_5);
        pushButton_28->setObjectName("pushButton_28");
        pushButton_28->setGeometry(QRect(520, 440, 141, 31));
        pushButton_28->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_29 = new QPushButton(tab_5);
        pushButton_29->setObjectName("pushButton_29");
        pushButton_29->setGeometry(QRect(30, 40, 121, 29));
        pushButton_29->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_30 = new QPushButton(tab_5);
        pushButton_30->setObjectName("pushButton_30");
        pushButton_30->setGeometry(QRect(940, 410, 93, 29));
        pushButton_30->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        lineEdit_23 = new QLineEdit(tab_5);
        lineEdit_23->setObjectName("lineEdit_23");
        lineEdit_23->setGeometry(QRect(500, 60, 131, 31));
        lineEdit_23->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        PDF_3 = new QLabel(tab_5);
        PDF_3->setObjectName("PDF_3");
        PDF_3->setGeometry(QRect(470, 430, 41, 41));
        PDF_3->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/projetpcc-2a26-voltshop-gestion_client/PDF.png")));
        PDF_3->setScaledContents(true);
        pushButton_31 = new QPushButton(tab_5);
        pushButton_31->setObjectName("pushButton_31");
        pushButton_31->setGeometry(QRect(350, 140, 31, 31));
        pushButton_31->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_31->setIcon(icon);
        pushButton_32 = new QPushButton(tab_5);
        pushButton_32->setObjectName("pushButton_32");
        pushButton_32->setGeometry(QRect(350, 180, 31, 31));
        pushButton_32->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_32->setIcon(icon);
        pushButton_33 = new QPushButton(tab_5);
        pushButton_33->setObjectName("pushButton_33");
        pushButton_33->setGeometry(QRect(350, 300, 31, 31));
        pushButton_33->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_33->setIcon(icon);
        pushButton_34 = new QPushButton(tab_5);
        pushButton_34->setObjectName("pushButton_34");
        pushButton_34->setGeometry(QRect(350, 260, 31, 31));
        pushButton_34->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_34->setIcon(icon);
        pushButton_35 = new QPushButton(tab_5);
        pushButton_35->setObjectName("pushButton_35");
        pushButton_35->setGeometry(QRect(350, 220, 31, 31));
        pushButton_35->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_35->setIcon(icon);
        pushButton_36 = new QPushButton(tab_5);
        pushButton_36->setObjectName("pushButton_36");
        pushButton_36->setGeometry(QRect(350, 330, 31, 31));
        pushButton_36->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_36->setIcon(icon);
        lineEdit_24 = new QLineEdit(tab_5);
        lineEdit_24->setObjectName("lineEdit_24");
        lineEdit_24->setGeometry(QRect(790, 410, 131, 31));
        lineEdit_24->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        darkmode_button = new QPushButton(tab_5);
        darkmode_button->setObjectName("darkmode_button");
        darkmode_button->setGeometry(QRect(20, 0, 51, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/ressource/night-mode.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        darkmode_button->setIcon(icon1);
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        stat_3 = new QLabel(tab_6);
        stat_3->setObjectName("stat_3");
        stat_3->setGeometry(QRect(30, 90, 451, 381));
        stat_3->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/ChatGPT Image 25 sept. 2025, 18_40_45.png")));
        stat_3->setScaledContents(true);
        tabWidget->addTab(tab_6, QString());

        retranslateUi(ClientWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QWidget *ClientWindow)
    {
        ClientWindow->setWindowTitle(QCoreApplication::translate("ClientWindow", "Client Management", nullptr));
        groupBox_3->setTitle(QString());
        label_17->setText(QCoreApplication::translate("ClientWindow", "CIN:", nullptr));
        label_18->setText(QCoreApplication::translate("ClientWindow", "First Name:", nullptr));
        label_19->setText(QCoreApplication::translate("ClientWindow", "Email:", nullptr));
        label_20->setText(QCoreApplication::translate("ClientWindow", "Last Name:", nullptr));
        label_21->setText(QCoreApplication::translate("ClientWindow", "Phone nbr:", nullptr));
        label_22->setText(QCoreApplication::translate("ClientWindow", "Adress:", nullptr));
        pushButton_25->setText(QCoreApplication::translate("ClientWindow", "Confirm", nullptr));
        pushButton_26->setText(QCoreApplication::translate("ClientWindow", "Cancel", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ClientWindow", "CIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ClientWindow", "First Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ClientWindow", "Last Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ClientWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ClientWindow", "Adress", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ClientWindow", "Phone Nbr", nullptr));

        const bool __sortingEnabled = tableWidget_3->isSortingEnabled();
        tableWidget_3->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_3->item(0, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ClientWindow", "12345678", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_3->item(0, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ClientWindow", "Ahmed", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_3->item(0, 2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ClientWindow", "Ben Ali", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_3->item(0, 3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ClientWindow", "ahmed.benali@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_3->item(0, 4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("ClientWindow", "Tunis, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_3->item(0, 5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("ClientWindow", "+216 71 123 456", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_3->item(1, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("ClientWindow", "87654321", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_3->item(1, 1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("ClientWindow", "Fatma", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_3->item(1, 2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("ClientWindow", "Sassi", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_3->item(1, 3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("ClientWindow", "fatma.sassi@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->item(1, 4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("ClientWindow", "Sfax, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->item(1, 5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("ClientWindow", "+216 74 987 654", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->item(2, 0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("ClientWindow", "11223344", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_3->item(2, 1);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("ClientWindow", "Mohamed", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_3->item(2, 2);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("ClientWindow", "Triki", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_3->item(2, 3);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("ClientWindow", "mohamed.triki@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_3->item(2, 4);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("ClientWindow", "Sousse, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_3->item(2, 5);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("ClientWindow", "+216 73 112 233", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_3->item(3, 0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("ClientWindow", "55667788", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_3->item(3, 1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("ClientWindow", "Leila", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_3->item(3, 2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("ClientWindow", "Mejri", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_3->item(3, 3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("ClientWindow", "leila.mejri@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_3->item(3, 4);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("ClientWindow", "Ariana, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_3->item(3, 5);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("ClientWindow", "+216 70 556 677", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_3->item(4, 0);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("ClientWindow", "99887766", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_3->item(4, 1);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("ClientWindow", "Karim", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_3->item(4, 2);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("ClientWindow", "Hamdi", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_3->item(4, 3);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("ClientWindow", "karim.hamdi@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_3->item(4, 4);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("ClientWindow", "Bizerte, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_3->item(4, 5);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("ClientWindow", "+216 72 998 877", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_3->item(5, 0);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("ClientWindow", "33445566", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_3->item(5, 1);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("ClientWindow", "Sarra", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_3->item(5, 2);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("ClientWindow", "Bouaziz", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_3->item(5, 3);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("ClientWindow", "sarra.bouaziz@email.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_3->item(5, 4);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("ClientWindow", "Gabes, Tunisia", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_3->item(5, 5);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("ClientWindow", "+216 75 334 455", nullptr));
        tableWidget_3->setSortingEnabled(__sortingEnabled);

        comboBox_3->setItemText(0, QCoreApplication::translate("ClientWindow", "Name", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("ClientWindow", "Adress", nullptr));
        comboBox_3->setItemText(2, QString());

        label_23->setText(QCoreApplication::translate("ClientWindow", "Sort By:", nullptr));
        label_24->setText(QCoreApplication::translate("ClientWindow", "Search for a client:", nullptr));
        pushButton_27->setText(QCoreApplication::translate("ClientWindow", "Confirm", nullptr));
        pushButton_28->setText(QCoreApplication::translate("ClientWindow", "Export to PDF", nullptr));
        pushButton_29->setText(QCoreApplication::translate("ClientWindow", "Add Client", nullptr));
        pushButton_30->setText(QCoreApplication::translate("ClientWindow", "Delete", nullptr));
        lineEdit_23->setPlaceholderText(QCoreApplication::translate("ClientWindow", "CIN,Name,Email", nullptr));
        PDF_3->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_31->setToolTip(QCoreApplication::translate("ClientWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_31->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_32->setToolTip(QCoreApplication::translate("ClientWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_32->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_33->setToolTip(QCoreApplication::translate("ClientWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_33->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_34->setToolTip(QCoreApplication::translate("ClientWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_34->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_35->setToolTip(QCoreApplication::translate("ClientWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_35->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_36->setToolTip(QCoreApplication::translate("ClientWindow", "Edit this client", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_36->setText(QString());
        lineEdit_24->setPlaceholderText(QCoreApplication::translate("ClientWindow", "          CIN", nullptr));
        darkmode_button->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("ClientWindow", "Home", nullptr));
        stat_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("ClientWindow", "Functionality", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
