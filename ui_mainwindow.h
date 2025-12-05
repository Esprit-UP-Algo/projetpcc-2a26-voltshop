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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "barchartwidget.h"
#include "piechartwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QPushButton *btn_Client;
    QPushButton *quit;
    QLabel *logo;
    QPushButton *btn_Stock;
    QPushButton *btn_Employee;
    QPushButton *btn_Commande;
    QPushButton *btn_Transaction;
    QLabel *label_58;
    QPushButton *chat_bot;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTabWidget *page_FeedbackClient;
    QWidget *tab;
    QPushButton *c_confirm;
    QPushButton *c_delete;
    QWidget *widget_7;
    QPushButton *pushButton_8;
    QLineEdit *c_Line_rech;
    QComboBox *sort;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QLabel *label_7;
    QLineEdit *rech;
    QPushButton *c_DEL;
    QTableWidget *tab_Client;
    QPushButton *pushButton_6;
    QLabel *label_67;
    QLabel *label_68;
    QWidget *widget_8;
    QLabel *label_31;
    QLineEdit *c_phone;
    QLineEdit *c_lname;
    QLabel *label;
    QLineEdit *c_adress;
    QLabel *label_4;
    QLineEdit *c_cin;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *c_fname;
    QLabel *label_2;
    QLineEdit *c_email;
    QLineEdit *c_age;
    QLabel *label_69;
    QLabel *label_70;
    QLabel *label_71;
    QLabel *label_72;
    QLabel *label_73;
    QLabel *label_74;
    QLabel *label_75;
    QPushButton *pushButton;
    QWidget *tab_2;
    QWidget *chart_client_age;
    QWidget *widget;
    QWidget *widget_4;
    QWidget *widget_5;
    QWidget *widget_6;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QWidget *clientStatsContainer;
    QWidget *tab_10;
    QListWidget *listWidget_journal;
    QWidget *tab_11;
    QWidget *containerFeedback;
    QWidget *page_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QTableWidget *tableauCommande;
    QPushButton *pushButton_supprimer;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_products;
    QLineEdit *lineEdit_total;
    QDateEdit *dateEdit_date;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_code;
    QComboBox *comboBox_client;
    QComboBox *comboBox_status;
    QLineEdit *ID;
    QLabel *label_87;
    QLabel *label_88;
    QLabel *label_92;
    QLabel *label_93;
    QLabel *label_94;
    QLabel *label_96;
    QLabel *label_85;
    QLabel *label_86;
    QLabel *label_97;
    QComboBox *comboBox_trie;
    QLabel *label_15;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_deliveryTracking;
    QPushButton *btnExportCatalogue;
    QPushButton *pushButton_22;
    QLabel *label_82;
    QLabel *label_83;
    QLabel *label_16;
    QLabel *label_84;
    QLabel *label_90;
    QLabel *label_91;
    QLabel *label_95;
    QLabel *label_89;
    QLabel *label_98;
    QWidget *tab_4;
    QLabel *label_total;
    QLabel *label_revenu;
    PieChartWidget *pieStatut;
    BarChartWidget *barMois;
    QLabel *label_47;
    QLabel *label_81;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *btn_home;
    QWidget *tab_5;
    QPushButton *confirm;
    QPushButton *delete_2;
    QWidget *widget_3;
    QTableWidget *tab_Art;
    QPushButton *DEL;
    QPushButton *btn_pdf;
    QLabel *label_26;
    QLineEdit *sku_2;
    QLabel *label_27;
    QLabel *label_28;
    QComboBox *rech_tri;
    QComboBox *rech_Bra;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_41;
    QLabel *label_46;
    QWidget *widget_2;
    QLabel *label_56;
    QLabel *label_59;
    QLabel *label_60;
    QLabel *label_61;
    QLabel *label_62;
    QLabel *label_63;
    QLabel *label_64;
    QLabel *label_65;
    QLabel *label_66;
    QLabel *label_19;
    QLabel *label_18;
    QLabel *label_22;
    QLabel *label_21;
    QLabel *label_23;
    QLabel *label_17;
    QLabel *label_20;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *com;
    QLineEdit *loca;
    QLineEdit *stock;
    QComboBox *cat;
    QLineEdit *sku;
    QLineEdit *name;
    QComboBox *brand;
    QLineEdit *price2;
    QLineEdit *price1;
    QPushButton *btn_add;
    QWidget *tab_6;
    QPushButton *btn_stats;
    QWidget *stockStatsContainer;
    QPushButton *btn_ai_stock;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget_3;
    QWidget *tab_7;
    QGroupBox *groupBox_4;
    QLineEdit *P_id;
    QLabel *label_32;
    QLineEdit *lineEdit_16;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QDateEdit *dateEdit;
    QPushButton *pushButton_25;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QLabel *label_76;
    QLabel *label_77;
    QLabel *label_78;
    QLabel *label_79;
    QLabel *label_80;
    QWidget *transaction_container;
    QComboBox *comboBoxsort;
    QComboBox *comboBoxSortOrder;
    QLineEdit *lineEdit_17;
    QLabel *label_37;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QLineEdit *lineEdit_18;
    QTableWidget *tableWidget_4;
    QPushButton *darkmode_button;
    QWidget *fa;
    QLabel *label_38;
    QLabel *label_39;
    QWidget *page_5;
    QTabWidget *tabWidget_4;
    QWidget *tab_8;
    QPushButton *btnPointage;
    QPushButton *export_pp;
    QTableWidget *tab_Employee;
    QPushButton *pushButton_32;
    QPushButton *pushButton_39;
    QGroupBox *groupBox_5;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *label_54;
    QLabel *label_55;
    QLineEdit *e_cin;
    QLineEdit *e_address;
    QLineEdit *e_salary;
    QLineEdit *e_fullname;
    QComboBox *e_position;
    QComboBox *e_status;
    QLabel *label_49;
    QPushButton *confirmb;
    QPushButton *pushButton_29;
    QLineEdit *lineEdit_19;
    QPushButton *pushButton_31;
    QLabel *label_48;
    QPushButton *pushButton_41;
    QLineEdit *lineEdit_20;
    QComboBox *comboBox_Emp_Sort;
    QWidget *tab_9;
    QWidget *widget_Emp_Chart_2;
    QPushButton *pushButton_Emp_Stats;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1543, 845);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-image: url(:/images/ressource/image_back.jpg);"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(11, 11, 190, 731));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(190, 0));
        groupBox_2->setMaximumSize(QSize(190, 16777215));
        groupBox_2->setStyleSheet(QString::fromUtf8("/* ===========================\n"
"   SIDEBAR (groupBox_2)\n"
"   =========================== */\n"
"\n"
"QGroupBox#groupBox_2 {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 rgba(34, 0, 68, 0.95),\n"
"        stop:1 rgba(13, 0, 26, 0.98)\n"
"    );\n"
"    border: none;\n"
"    border-radius: 28px;\n"
"    color: white;\n"
"    padding-top: 20px;\n"
"}\n"
"\n"
"/* Tous les boutons dans la sidebar */\n"
"QGroupBox#groupBox_2 QPushButton {\n"
"    background: transparent;\n"
"    color: white;\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding: 10px 26px;\n"
"    font-size: 15px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"/* Effet hover l\303\251ger */\n"
"QGroupBox#groupBox_2 QPushButton:hover {\n"
"    background: rgba(255, 255, 255, 0.10);\n"
"    border-radius: 20px;\n"
"}\n"
"\n"
"/* === BOUTON SELECTIONN\303\211 (capsule violette) === */\n"
"QGroupBox#groupBox_2 QPushButton[selected=\"true\"] {\n"
"    background: qlineargradient(\n"
"        x1:0, "
                        "y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(180, 0, 255, 0.90),\n"
"        stop:1 rgba(0, 180, 255, 0.90)\n"
"    );\n"
"    border-radius: 22px;\n"
"    color: white;\n"
"    font-weight: 700;\n"
"    padding: 10px 28px;\n"
"}\n"
"\n"
"/* Tu peux personnaliser LOG OUT si tu veux */\n"
"QGroupBox#groupBox_2 QPushButton#btn_Logout {\n"
"    background: rgba(0, 120, 255, 0.9);\n"
"    border-radius: 8px;\n"
"    padding: 8px 26px;\n"
"}\n"
"\n"
"QGroupBox#groupBox_2 QPushButton#btn_Logout:hover {\n"
"    background: rgba(50, 150, 255, 1.0);\n"
"}\n"
""));
        btn_Client = new QPushButton(groupBox_2);
        btn_Client->setObjectName("btn_Client");
        btn_Client->setGeometry(QRect(10, 110, 171, 61));
        btn_Client->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"/* Survol */\n"
"QPushButton:hover {\n"
"    background-color: #5AB4F0;\n"
"}\n"
"\n"
"/* Quand un bouton est cliqu\303\251 et reste actif */\n"
"QPushButton:checked {\n"
"    background-color: #004C8C; /* Couleur plus fonc\303\251e */\n"
"    border: 2px solid white;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("ressource/7.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_Client->setIcon(icon);
        btn_Client->setIconSize(QSize(50, 50));
        btn_Client->setCheckable(true);
        quit = new QPushButton(groupBox_2);
        quit->setObjectName("quit");
        quit->setGeometry(QRect(50, 620, 81, 71));
        quit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 900 9pt \"Swis721 Blk BT\";\n"
"    background:tansparent;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"/* Survol */\n"
"QPushButton:hover {\n"
"    background-color:transparent;\n"
"}\n"
"\n"
"/* S\303\251lectionn\303\251 (le bouton cliqu\303\251 reste dans cette couleur) */\n"
"QPushButton:checked {\n"
"    background:transparent; /* Couleur plus fonc\303\251e */\n"
"    border: 2px solid white;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("ressource/8.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        quit->setIcon(icon1);
        quit->setIconSize(QSize(60, 60));
        quit->setCheckable(true);
        logo = new QLabel(groupBox_2);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(30, 10, 131, 81));
        logo->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/Downloads/WhatsApp Image 2025-09-16 at 13.04.56 (1).jpeg")));
        logo->setScaledContents(true);
        btn_Stock = new QPushButton(groupBox_2);
        btn_Stock->setObjectName("btn_Stock");
        btn_Stock->setGeometry(QRect(10, 270, 171, 61));
        btn_Stock->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"/* Survol */\n"
"QPushButton:hover {\n"
"    background-color: #5AB4F0;\n"
"}\n"
"\n"
"/* Quand un bouton est cliqu\303\251 et reste actif */\n"
"QPushButton:checked {\n"
"    background-color: #004C8C; /* Couleur plus fonc\303\251e */\n"
"    border: 2px solid white;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("ressource/9.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_Stock->setIcon(icon2);
        btn_Stock->setIconSize(QSize(50, 50));
        btn_Stock->setCheckable(true);
        btn_Employee = new QPushButton(groupBox_2);
        btn_Employee->setObjectName("btn_Employee");
        btn_Employee->setGeometry(QRect(10, 450, 171, 61));
        btn_Employee->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"/* Survol */\n"
"QPushButton:hover {\n"
"    background-color: #5AB4F0;\n"
"}\n"
"\n"
"/* Quand un bouton est cliqu\303\251 et reste actif */\n"
"QPushButton:checked {\n"
"    background-color: #004C8C; /* Couleur plus fonc\303\251e */\n"
"    border: 2px solid white;\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("ressource/5.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_Employee->setIcon(icon3);
        btn_Employee->setIconSize(QSize(50, 50));
        btn_Employee->setCheckable(true);
        btn_Commande = new QPushButton(groupBox_2);
        btn_Commande->setObjectName("btn_Commande");
        btn_Commande->setGeometry(QRect(10, 190, 171, 61));
        btn_Commande->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"/* Survol */\n"
"QPushButton:hover {\n"
"    background-color: #5AB4F0;\n"
"}\n"
"\n"
"/* Quand un bouton est cliqu\303\251 et reste actif */\n"
"QPushButton:checked {\n"
"    background-color: #004C8C; /* Couleur plus fonc\303\251e */\n"
"    border: 2px solid white;\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("ressource/2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_Commande->setIcon(icon4);
        btn_Commande->setIconSize(QSize(60, 60));
        btn_Commande->setCheckable(true);
        btn_Transaction = new QPushButton(groupBox_2);
        btn_Transaction->setObjectName("btn_Transaction");
        btn_Transaction->setGeometry(QRect(10, 360, 171, 61));
        btn_Transaction->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"/* Survol */\n"
"QPushButton:hover {\n"
"    background-color: #5AB4F0;\n"
"}\n"
"\n"
"/* Quand un bouton est cliqu\303\251 et reste actif */\n"
"QPushButton:checked {\n"
"    background-color: #004C8C; /* Couleur plus fonc\303\251e */\n"
"    border: 2px solid white;\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("ressource/4.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_Transaction->setIcon(icon5);
        btn_Transaction->setIconSize(QSize(50, 50));
        btn_Transaction->setCheckable(true);
        label_58 = new QLabel(groupBox_2);
        label_58->setObjectName("label_58");
        label_58->setGeometry(QRect(32, 10, 121, 81));
        label_58->setPixmap(QPixmap(QString::fromUtf8("ressource/logo12.png")));
        label_58->setScaledContents(true);
        chat_bot = new QPushButton(groupBox_2);
        chat_bot->setObjectName("chat_bot");
        chat_bot->setGeometry(QRect(10, 560, 171, 31));
        chat_bot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #2C82C9;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"/* Survol */\n"
"QPushButton:hover {\n"
"    background-color: #5AB4F0;\n"
"}\n"
"\n"
"/* S\303\251lectionn\303\251 (le bouton cliqu\303\251 reste dans cette couleur) */\n"
"QPushButton:checked {\n"
"    background-color: #004C8C; /* Couleur plus fonc\303\251e */\n"
"    border: 2px solid white;\n"
"}\n"
""));
        chat_bot->setCheckable(true);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(208, 31, 1351, 741));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("QStackedWidget {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QStackedWidget > QWidget {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
""));
        page = new QWidget();
        page->setObjectName("page");
        page->setStyleSheet(QString::fromUtf8("background: transparent;"));
        page_FeedbackClient = new QTabWidget(page);
        page_FeedbackClient->setObjectName("page_FeedbackClient");
        page_FeedbackClient->setGeometry(QRect(0, 30, 1371, 701));
        page_FeedbackClient->setStyleSheet(QString::fromUtf8("/* ========= PANE TRANSPARENT (fond du QTabWidget) ========= */\n"
"QTabWidget::pane {\n"
"    border: none;\n"
"    background: transparent;   /* on voit ton background global */\n"
"}\n"
"\n"
"/* Position de la barre d'onglets */\n"
"QTabWidget::tab-bar {\n"
"    alignment: left;\n"
"}\n"
"\n"
"/* ========= ONGLET NORMAL (non s\303\251lectionn\303\251) ========= */\n"
"QTabWidget QTabBar::tab {\n"
"    background: transparent;\n"
"    color: #ffffff;\n"
"    padding: 6px 22px;\n"
"    border: none;\n"
"    margin-right: 8px;\n"
"    margin-bottom: 8px;        /* \360\237\224\245 d\303\251tache l\342\200\231onglet du pane \342\206\222 on voit bien l\342\200\231arrondi */\n"
"    font-weight: 600;\n"
"    border-radius: 50px;       /* forme capsule, pas carr\303\251 */\n"
"}\n"
"\n"
"/* ========= ONGLET S\303\211LECTIONN\303\211 (capsule violette) ========= */\n"
"QTabWidget QTabBar::tab:selected {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #c72cff,\n"
"        "
                        "stop:1 #4a7dff\n"
"    );\n"
"    color: #ffffff;\n"
"    border-radius: 50px;\n"
"}\n"
"\n"
"/* ========= HOVER (survol l\303\251ger) ========= */\n"
"QTabWidget::tab:hover {\n"
"    background: rgba(255, 255, 255, 0.12);\n"
"    border-radius: 18px;\n"
"}\n"
""));
        page_FeedbackClient->setIconSize(QSize(30, 30));
        tab = new QWidget();
        tab->setObjectName("tab");
        c_confirm = new QPushButton(tab);
        c_confirm->setObjectName("c_confirm");
        c_confirm->setGeometry(QRect(40, 590, 161, 51));
        c_confirm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("ressource/12.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        c_confirm->setIcon(icon6);
        c_confirm->setIconSize(QSize(30, 30));
        c_delete = new QPushButton(tab);
        c_delete->setObjectName("c_delete");
        c_delete->setGeometry(QRect(210, 590, 161, 51));
        c_delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("ressource/13.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        c_delete->setIcon(icon7);
        c_delete->setIconSize(QSize(45, 45));
        widget_7 = new QWidget(tab);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(390, 60, 931, 491));
        widget_7->setStyleSheet(QString::fromUtf8("#widget_7 {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"\n"
"        /* Bleu tr\303\250s clair en entr\303\251e */\n"
"        stop:0 rgba(90, 150, 255, 70),\n"
"\n"
"        /* Bleu encore plus clair au centre */\n"
"        stop:0.5 rgba(140, 190, 255, 60),\n"
"\n"
"        /* Bleu l\303\251ger et doux en sortie */\n"
"        stop:1 rgba(100, 160, 255, 70)\n"
"    );\n"
"\n"
"    border-radius: 26px;\n"
"\n"
"    /* contour tr\303\250s discret */\n"
"    border: 1px solid rgba(255, 255, 255, 50);\n"
"\n"
"    /* Reflet int\303\251rieur tr\303\250s soft (effet verre) */\n"
"    box-shadow:\n"
"        inset 0 0 35px rgba(255, 255, 255, 30),\n"
"        0 0 20px rgba(100, 160, 255, 25);\n"
"}\n"
""));
        pushButton_8 = new QPushButton(widget_7);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(40, 410, 191, 51));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("ressource/19.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_8->setIcon(icon8);
        pushButton_8->setIconSize(QSize(37, 37));
        c_Line_rech = new QLineEdit(widget_7);
        c_Line_rech->setObjectName("c_Line_rech");
        c_Line_rech->setGeometry(QRect(550, 420, 171, 51));
        sizePolicy1.setHeightForWidth(c_Line_rech->sizePolicy().hasHeightForWidth());
        c_Line_rech->setSizePolicy(sizePolicy1);
        c_Line_rech->setMinimumSize(QSize(30, 0));
        c_Line_rech->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        sort = new QComboBox(widget_7);
        sort->addItem(QString());
        sort->addItem(QString());
        sort->addItem(QString());
        sort->setObjectName("sort");
        sort->setGeometry(QRect(680, 30, 141, 41));
        sort->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_8 = new QLabel(widget_7);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 20, 191, 51));
        label_8->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(widget_7);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(390, 20, 161, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        pushButton_4->setIcon(icon6);
        pushButton_4->setIconSize(QSize(30, 30));
        label_7 = new QLabel(widget_7);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(600, 20, 111, 61));
        label_7->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";"));
        rech = new QLineEdit(widget_7);
        rech->setObjectName("rech");
        rech->setGeometry(QRect(200, 20, 171, 51));
        rech->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        c_DEL = new QPushButton(widget_7);
        c_DEL->setObjectName("c_DEL");
        c_DEL->setGeometry(QRect(740, 420, 171, 51));
        c_DEL->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("ressource/20.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        c_DEL->setIcon(icon9);
        c_DEL->setIconSize(QSize(37, 37));
        tab_Client = new QTableWidget(widget_7);
        if (tab_Client->columnCount() < 7)
            tab_Client->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tab_Client->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tab_Client->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tab_Client->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tab_Client->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tab_Client->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tab_Client->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tab_Client->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tab_Client->rowCount() < 12)
            tab_Client->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tab_Client->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tab_Client->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tab_Client->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tab_Client->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tab_Client->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tab_Client->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tab_Client->setItem(0, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tab_Client->setItem(0, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tab_Client->setItem(0, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tab_Client->setItem(0, 3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tab_Client->setItem(0, 4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tab_Client->setItem(0, 5, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tab_Client->setItem(1, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tab_Client->setItem(1, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tab_Client->setItem(1, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tab_Client->setItem(1, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tab_Client->setItem(1, 4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tab_Client->setItem(1, 5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tab_Client->setItem(2, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tab_Client->setItem(2, 1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tab_Client->setItem(2, 2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tab_Client->setItem(2, 3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tab_Client->setItem(2, 4, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tab_Client->setItem(2, 5, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tab_Client->setItem(3, 0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tab_Client->setItem(3, 1, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tab_Client->setItem(3, 2, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tab_Client->setItem(3, 3, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tab_Client->setItem(3, 4, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tab_Client->setItem(3, 5, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tab_Client->setItem(4, 0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tab_Client->setItem(4, 1, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tab_Client->setItem(4, 2, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tab_Client->setItem(4, 3, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tab_Client->setItem(4, 4, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tab_Client->setItem(4, 5, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tab_Client->setItem(5, 0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tab_Client->setItem(5, 1, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tab_Client->setItem(5, 2, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tab_Client->setItem(5, 3, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tab_Client->setItem(5, 4, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tab_Client->setItem(5, 5, __qtablewidgetitem48);
        tab_Client->setObjectName("tab_Client");
        tab_Client->setGeometry(QRect(20, 90, 891, 301));
        tab_Client->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        pushButton_6 = new QPushButton(widget_7);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(1090, 270, 141, 31));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_67 = new QLabel(widget_7);
        label_67->setObjectName("label_67");
        label_67->setGeometry(QRect(10, 30, 31, 31));
        label_67->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_67->setPixmap(QPixmap(QString::fromUtf8("ressource/15.png")));
        label_67->setScaledContents(true);
        label_68 = new QLabel(widget_7);
        label_68->setObjectName("label_68");
        label_68->setGeometry(QRect(570, 30, 21, 41));
        label_68->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_68->setPixmap(QPixmap(QString::fromUtf8("ressource/34.png")));
        label_68->setScaledContents(true);
        widget_8 = new QWidget(tab);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(20, 60, 361, 491));
        widget_8->setStyleSheet(QString::fromUtf8("#widget_8 {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"\n"
"        /* Bleu tr\303\250s clair en entr\303\251e */\n"
"        stop:0 rgba(90, 150, 255, 70),\n"
"\n"
"        /* Bleu encore plus clair au centre */\n"
"        stop:0.5 rgba(140, 190, 255, 60),\n"
"\n"
"        /* Bleu l\303\251ger et doux en sortie */\n"
"        stop:1 rgba(100, 160, 255, 70)\n"
"    );\n"
"\n"
"    border-radius: 26px;\n"
"\n"
"    /* contour tr\303\250s discret */\n"
"    border: 1px solid rgba(255, 255, 255, 50);\n"
"\n"
"    /* Reflet int\303\251rieur tr\303\250s soft (effet verre) */\n"
"    box-shadow:\n"
"        inset 0 0 35px rgba(255, 255, 255, 30),\n"
"        0 0 20px rgba(100, 160, 255, 25);\n"
"}\n"
""));
        label_31 = new QLabel(widget_8);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(50, 430, 81, 21));
        label_31->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        c_phone = new QLineEdit(widget_8);
        c_phone->setObjectName("c_phone");
        c_phone->setGeometry(QRect(160, 300, 161, 41));
        c_phone->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        c_lname = new QLineEdit(widget_8);
        c_lname->setObjectName("c_lname");
        c_lname->setGeometry(QRect(160, 180, 161, 41));
        c_lname->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label = new QLabel(widget_8);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 60, 51, 21));
        label->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        c_adress = new QLineEdit(widget_8);
        c_adress->setObjectName("c_adress");
        c_adress->setGeometry(QRect(160, 360, 161, 41));
        c_adress->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_4 = new QLabel(widget_8);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 180, 111, 41));
        label_4->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        c_cin = new QLineEdit(widget_8);
        c_cin->setObjectName("c_cin");
        c_cin->setGeometry(QRect(160, 50, 161, 41));
        c_cin->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_5 = new QLabel(widget_8);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 310, 101, 20));
        label_5->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_3 = new QLabel(widget_8);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 250, 71, 20));
        label_3->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_6 = new QLabel(widget_8);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 370, 81, 21));
        label_6->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        c_fname = new QLineEdit(widget_8);
        c_fname->setObjectName("c_fname");
        c_fname->setGeometry(QRect(160, 120, 161, 41));
        c_fname->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_2 = new QLabel(widget_8);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 120, 111, 31));
        label_2->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        c_email = new QLineEdit(widget_8);
        c_email->setObjectName("c_email");
        c_email->setGeometry(QRect(160, 240, 161, 41));
        c_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        c_age = new QLineEdit(widget_8);
        c_age->setObjectName("c_age");
        c_age->setGeometry(QRect(160, 420, 161, 41));
        c_age->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_69 = new QLabel(widget_8);
        label_69->setObjectName("label_69");
        label_69->setGeometry(QRect(20, 60, 31, 31));
        label_69->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_69->setPixmap(QPixmap(QString::fromUtf8("ressource/36.png")));
        label_69->setScaledContents(true);
        label_70 = new QLabel(widget_8);
        label_70->setObjectName("label_70");
        label_70->setGeometry(QRect(10, 110, 31, 41));
        label_70->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_70->setPixmap(QPixmap(QString::fromUtf8("ressource/39.png")));
        label_70->setScaledContents(true);
        label_71 = new QLabel(widget_8);
        label_71->setObjectName("label_71");
        label_71->setGeometry(QRect(10, 180, 31, 41));
        label_71->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_71->setPixmap(QPixmap(QString::fromUtf8("ressource/39.png")));
        label_71->setScaledContents(true);
        label_72 = new QLabel(widget_8);
        label_72->setObjectName("label_72");
        label_72->setGeometry(QRect(10, 240, 31, 31));
        label_72->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_72->setPixmap(QPixmap(QString::fromUtf8("ressource/40.png")));
        label_72->setScaledContents(true);
        label_73 = new QLabel(widget_8);
        label_73->setObjectName("label_73");
        label_73->setGeometry(QRect(10, 300, 31, 41));
        label_73->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_73->setPixmap(QPixmap(QString::fromUtf8("ressource/41.png")));
        label_73->setScaledContents(true);
        label_74 = new QLabel(widget_8);
        label_74->setObjectName("label_74");
        label_74->setGeometry(QRect(10, 370, 31, 31));
        label_74->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_74->setPixmap(QPixmap(QString::fromUtf8("ressource/42.png")));
        label_74->setScaledContents(true);
        label_75 = new QLabel(widget_8);
        label_75->setObjectName("label_75");
        label_75->setGeometry(QRect(10, 430, 31, 31));
        label_75->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_75->setPixmap(QPixmap(QString::fromUtf8("ressource/43.png")));
        label_75->setScaledContents(true);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 30, 181, 51));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("ressource/44.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon10);
        pushButton->setIconSize(QSize(40, 40));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("ressource/10.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        page_FeedbackClient->addTab(tab, icon11, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        chart_client_age = new QWidget(tab_2);
        chart_client_age->setObjectName("chart_client_age");
        chart_client_age->setGeometry(QRect(710, 30, 391, 371));
        widget = new QWidget(tab_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(690, 390, 21, 21));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(46,204,113);"));
        widget_4 = new QWidget(tab_2);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(690, 420, 21, 21));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(102,179,231);"));
        widget_5 = new QWidget(tab_2);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(690, 480, 21, 21));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(87, 75, 144);"));
        widget_6 = new QWidget(tab_2);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(690, 450, 21, 21));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 62, 138);"));
        label_42 = new QLabel(tab_2);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(730, 390, 111, 20));
        label_42->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:black;"));
        label_43 = new QLabel(tab_2);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(730, 420, 101, 20));
        label_43->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:black;"));
        label_44 = new QLabel(tab_2);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(730, 450, 101, 20));
        label_44->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:black;"));
        label_45 = new QLabel(tab_2);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(730, 480, 101, 20));
        label_45->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:black;"));
        clientStatsContainer = new QWidget(tab_2);
        clientStatsContainer->setObjectName("clientStatsContainer");
        clientStatsContainer->setGeometry(QRect(20, 50, 641, 491));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("ressource/11.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        page_FeedbackClient->addTab(tab_2, icon12, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        listWidget_journal = new QListWidget(tab_10);
        listWidget_journal->setObjectName("listWidget_journal");
        listWidget_journal->setGeometry(QRect(40, 20, 1111, 531));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("ressource/37.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        page_FeedbackClient->addTab(tab_10, icon13, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName("tab_11");
        containerFeedback = new QWidget(tab_11);
        containerFeedback->setObjectName("containerFeedback");
        containerFeedback->setGeometry(QRect(20, 30, 1141, 521));
        containerFeedback->setStyleSheet(QString::fromUtf8("table->setStyleSheet(R\"(\n"
"    QTableWidget { \n"
"        background:white; \n"
"        color:black;          /* TEXTE TABLE EN NOIR */\n"
"    }\n"
"    QHeaderView::section { \n"
"        background:#f2f2f2;\n"
"        color:black;          /* TEXTE HEADERS EN NOIR */\n"
"        font-weight:bold;\n"
"    }\n"
")\");\n"
""));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8("ressource/38.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        page_FeedbackClient->addTab(tab_11, icon14, QString());
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setStyleSheet(QString::fromUtf8("background:transparent;"));
        tabWidget_2 = new QTabWidget(page_2);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 0, 1361, 761));
        tabWidget_2->setStyleSheet(QString::fromUtf8("/* ========= PANE TRANSPARENT (fond du QTabWidget) ========= */\n"
"QTabWidget::pane {\n"
"    border: none;\n"
"    background: transparent;   /* on voit ton background global */\n"
"}\n"
"\n"
"/* Position de la barre d'onglets */\n"
"QTabWidget::tab-bar {\n"
"    alignment: left;\n"
"}\n"
"\n"
"/* ========= ONGLET NORMAL (non s\303\251lectionn\303\251) ========= */\n"
"QTabWidget QTabBar::tab {\n"
"    background: transparent;\n"
"    color: #ffffff;\n"
"    padding: 6px 22px;\n"
"    border: none;\n"
"    margin-right: 8px;\n"
"    margin-bottom: 8px;        /* \360\237\224\245 d\303\251tache l\342\200\231onglet du pane \342\206\222 on voit bien l\342\200\231arrondi */\n"
"    font-weight: 600;\n"
"    border-radius: 50px;       /* forme capsule, pas carr\303\251 */\n"
"}\n"
"\n"
"/* ========= ONGLET S\303\211LECTIONN\303\211 (capsule violette) ========= */\n"
"QTabWidget QTabBar::tab:selected {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #c72cff,\n"
"        "
                        "stop:1 #4a7dff\n"
"    );\n"
"    color: #ffffff;\n"
"    border-radius: 50px;\n"
"}\n"
"\n"
"/* ========= HOVER (survol l\303\251ger) ========= */\n"
"QTabWidget::tab:hover {\n"
"    background: rgba(255, 255, 255, 0.12);\n"
"    border-radius: 18px;\n"
"}\n"
""));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tableauCommande = new QTableWidget(tab_3);
        if (tableauCommande->columnCount() < 6)
            tableauCommande->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableauCommande->setHorizontalHeaderItem(0, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableauCommande->setHorizontalHeaderItem(1, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableauCommande->setHorizontalHeaderItem(2, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableauCommande->setHorizontalHeaderItem(3, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableauCommande->setHorizontalHeaderItem(4, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableauCommande->setHorizontalHeaderItem(5, __qtablewidgetitem54);
        if (tableauCommande->rowCount() < 4)
            tableauCommande->setRowCount(4);
        tableauCommande->setObjectName("tableauCommande");
        tableauCommande->setGeometry(QRect(490, 210, 671, 191));
        tableauCommande->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 rgba(26, 26, 46, 0.95),\n"
"        stop:1 rgba(20, 20, 35, 0.98)\n"
"    );\n"
"    color: white;\n"
"    gridline-color: rgba(100, 200, 255, 0.2);\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"    border-radius: 8px;\n"
"    selection-background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(0, 234, 255, 0.3),\n"
"        stop:1 rgba(106, 124, 255, 0.3)\n"
"    );\n"
"    selection-color: white;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"    font-size: 11pt;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 8px;\n"
"    border: none;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background: rgba(0, 234, 255, 0.15);\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        sto"
                        "p:0 rgba(0, 234, 255, 0.4),\n"
"        stop:1 rgba(106, 124, 255, 0.4)\n"
"    );\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #4472C4,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"    color: white;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    font-size: 11pt;\n"
"    border-right: 1px solid rgba(255, 255, 255, 0.1);\n"
"}\n"
"\n"
"QHeaderView::section:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #5588dd,\n"
"        stop:1 #7a8cff\n"
"    );\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background: rgba(26, 26, 46, 0.5);\n"
"    width: 12px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"    border-radius: 6px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QS"
                        "crollBar::handle:vertical:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00ffff,\n"
"        stop:1 #7a8cff\n"
"    );\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: rgba(26, 26, 46, 0.5);\n"
"    height: 12px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"    border-radius: 6px;\n"
"    min-width: 20px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00ffff,\n"
"        stop:1 #7a8cff\n"
"    );\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background: #4472C4;\n"
"    border"
                        ": none;\n"
"}\n"
""));
        tableauCommande->setRowCount(4);
        pushButton_supprimer = new QPushButton(tab_3);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(710, 470, 181, 61));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        lineEdit_search = new QLineEdit(tab_3);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setGeometry(QRect(660, 60, 261, 51));
        lineEdit_search->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        pushButton_search = new QPushButton(tab_3);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setGeometry(QRect(510, 60, 141, 51));
        pushButton_search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(0, 70, 421, 551));
        groupBox_3->setStyleSheet(QString::fromUtf8("#widget_2 {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"\n"
"        /* Bleu tr\303\250s clair en entr\303\251e */\n"
"        stop:0 rgba(90, 150, 255, 70),\n"
"\n"
"        /* Bleu encore plus clair au centre */\n"
"        stop:0.5 rgba(140, 190, 255, 60),\n"
"\n"
"        /* Bleu l\303\251ger et doux en sortie */\n"
"        stop:1 rgba(100, 160, 255, 70)\n"
"    );\n"
"\n"
"    border-radius: 26px;\n"
"\n"
"    /* contour tr\303\250s discret */\n"
"    border: 1px solid rgba(255, 255, 255, 50);\n"
"\n"
"    /* Reflet int\303\251rieur tr\303\250s soft (effet verre) */\n"
"    box-shadow:\n"
"        inset 0 0 35px rgba(255, 255, 255, 30),\n"
"        0 0 20px rgba(100, 160, 255, 25);\n"
"}\n"
""));
        lineEdit_products = new QLineEdit(groupBox_3);
        lineEdit_products->setObjectName("lineEdit_products");
        lineEdit_products->setGeometry(QRect(160, 210, 111, 41));
        lineEdit_products->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        lineEdit_total = new QLineEdit(groupBox_3);
        lineEdit_total->setObjectName("lineEdit_total");
        lineEdit_total->setGeometry(QRect(170, 300, 121, 41));
        lineEdit_total->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        dateEdit_date = new QDateEdit(groupBox_3);
        dateEdit_date->setObjectName("dateEdit_date");
        dateEdit_date->setGeometry(QRect(160, 120, 121, 41));
        dateEdit_date->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/images/ressource/icons8-calendar-50.png);\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}\n"
""));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(60, 50, 91, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Swis721 Blk BT")});
        font.setBold(true);
        font.setItalic(false);
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(70, 130, 91, 31));
        label_10->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(60, 210, 91, 31));
        label_11->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(80, 310, 63, 20));
        label_12->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(70, 390, 63, 20));
        label_13->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(80, 480, 63, 20));
        label_14->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        lineEdit_code = new QLineEdit(groupBox_3);
        lineEdit_code->setObjectName("lineEdit_code");
        lineEdit_code->setGeometry(QRect(150, 40, 131, 41));
        lineEdit_code->setTabletTracking(false);
        lineEdit_code->setAutoFillBackground(false);
        lineEdit_code->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        comboBox_client = new QComboBox(groupBox_3);
        comboBox_client->setObjectName("comboBox_client");
        comboBox_client->setGeometry(QRect(170, 470, 111, 41));
        comboBox_client->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        comboBox_status = new QComboBox(groupBox_3);
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->setObjectName("comboBox_status");
        comboBox_status->setGeometry(QRect(170, 390, 111, 41));
        comboBox_status->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        ID = new QLineEdit(groupBox_3);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(270, 210, 81, 41));
        ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_87 = new QLabel(groupBox_3);
        label_87->setObjectName("label_87");
        label_87->setGeometry(QRect(10, 120, 51, 41));
        label_87->setPixmap(QPixmap(QString::fromUtf8("ressource/93.png")));
        label_87->setScaledContents(true);
        label_88 = new QLabel(groupBox_3);
        label_88->setObjectName("label_88");
        label_88->setGeometry(QRect(20, 470, 41, 31));
        label_88->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_88->setPixmap(QPixmap(QString::fromUtf8("ressource/36.png")));
        label_88->setScaledContents(true);
        label_92 = new QLabel(groupBox_3);
        label_92->setObjectName("label_92");
        label_92->setGeometry(QRect(10, 30, 41, 51));
        label_92->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/WhatsApp_Image_2025-12-03_\303\240_01.36.51_30b495e9-removebg-preview.png")));
        label_92->setScaledContents(true);
        label_93 = new QLabel(groupBox_3);
        label_93->setObjectName("label_93");
        label_93->setGeometry(QRect(10, 200, 41, 51));
        label_93->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/WhatsApp_Image_2025-12-03_\303\240_01.38.02_86f7d76d-removebg-preview.png")));
        label_93->setScaledContents(true);
        label_94 = new QLabel(groupBox_3);
        label_94->setObjectName("label_94");
        label_94->setGeometry(QRect(10, 300, 41, 41));
        label_94->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/WhatsApp_Image_2025-12-03_\303\240_01.38.34_327004ed-removebg-preview.png")));
        label_94->setScaledContents(true);
        label_96 = new QLabel(groupBox_3);
        label_96->setObjectName("label_96");
        label_96->setGeometry(QRect(10, 380, 31, 31));
        label_96->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_96->setPixmap(QPixmap(QString::fromUtf8("ressource/24.png")));
        label_96->setScaledContents(true);
        label_85 = new QLabel(groupBox_3);
        label_85->setObjectName("label_85");
        label_85->setGeometry(QRect(10, 40, 31, 41));
        label_85->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/555.png")));
        label_85->setScaledContents(true);
        label_86 = new QLabel(groupBox_3);
        label_86->setObjectName("label_86");
        label_86->setGeometry(QRect(10, 200, 41, 41));
        label_86->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/666.png")));
        label_86->setScaledContents(true);
        label_97 = new QLabel(groupBox_3);
        label_97->setObjectName("label_97");
        label_97->setGeometry(QRect(10, 290, 41, 41));
        label_97->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/777.png")));
        label_97->setScaledContents(true);
        comboBox_trie = new QComboBox(tab_3);
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->setObjectName("comboBox_trie");
        comboBox_trie->setGeometry(QRect(1120, 120, 121, 41));
        comboBox_trie->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(1030, 120, 81, 41));
        label_15->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        pushButton_ajouter = new QPushButton(tab_3);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(40, 620, 141, 51));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        pushButton_cancel = new QPushButton(tab_3);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(240, 620, 141, 51));
        pushButton_cancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        pushButton_deliveryTracking = new QPushButton(tab_3);
        pushButton_deliveryTracking->setObjectName("pushButton_deliveryTracking");
        pushButton_deliveryTracking->setGeometry(QRect(450, 470, 201, 61));
        pushButton_deliveryTracking->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        btnExportCatalogue = new QPushButton(tab_3);
        btnExportCatalogue->setObjectName("btnExportCatalogue");
        btnExportCatalogue->setGeometry(QRect(1050, 560, 171, 61));
        btnExportCatalogue->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        pushButton_22 = new QPushButton(tab_3);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(10, 20, 171, 61));
        pushButton_22->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        label_82 = new QLabel(tab_3);
        label_82->setObjectName("label_82");
        label_82->setGeometry(QRect(1000, 120, 21, 41));
        label_82->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_82->setPixmap(QPixmap(QString::fromUtf8("ressource/34.png")));
        label_82->setScaledContents(true);
        label_83 = new QLabel(tab_3);
        label_83->setObjectName("label_83");
        label_83->setGeometry(QRect(520, 70, 31, 31));
        label_83->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_83->setPixmap(QPixmap(QString::fromUtf8("ressource/15.png")));
        label_83->setScaledContents(true);
        label_16 = new QLabel(tab_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(50, 630, 31, 31));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/12.png")));
        label_16->setScaledContents(true);
        label_84 = new QLabel(tab_3);
        label_84->setObjectName("label_84");
        label_84->setGeometry(QRect(250, 630, 41, 31));
        label_84->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/13.png")));
        label_84->setScaledContents(true);
        label_90 = new QLabel(tab_3);
        label_90->setObjectName("label_90");
        label_90->setGeometry(QRect(720, 480, 31, 31));
        label_90->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/20.png")));
        label_90->setScaledContents(true);
        label_91 = new QLabel(tab_3);
        label_91->setObjectName("label_91");
        label_91->setGeometry(QRect(1050, 560, 61, 61));
        label_91->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/2.png")));
        label_91->setScaledContents(true);
        label_95 = new QLabel(tab_3);
        label_95->setObjectName("label_95");
        label_95->setGeometry(QRect(20, 30, 41, 41));
        label_95->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/WhatsApp_Image_2025-12-03_\303\240_01.39.45_481e9f6d-removebg-preview.png")));
        label_95->setScaledContents(true);
        label_89 = new QLabel(tab_3);
        label_89->setObjectName("label_89");
        label_89->setGeometry(QRect(460, 480, 31, 31));
        label_89->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_89->setPixmap(QPixmap(QString::fromUtf8("ressource/24.png")));
        label_89->setScaledContents(true);
        label_98 = new QLabel(tab_3);
        label_98->setObjectName("label_98");
        label_98->setGeometry(QRect(20, 30, 41, 41));
        label_98->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/888.png")));
        label_98->setScaledContents(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/ressource/10.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        tabWidget_2->addTab(tab_3, icon15, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        label_total = new QLabel(tab_4);
        label_total->setObjectName("label_total");
        label_total->setGeometry(QRect(20, 50, 231, 61));
        label_total->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"font: 11pt \"Segoe UI\";"));
        label_revenu = new QLabel(tab_4);
        label_revenu->setObjectName("label_revenu");
        label_revenu->setGeometry(QRect(20, 170, 221, 51));
        label_revenu->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"font: 11pt \"Segoe UI\";"));
        pieStatut = new PieChartWidget(tab_4);
        pieStatut->setObjectName("pieStatut");
        pieStatut->setGeometry(QRect(439, 0, 681, 331));
        pieStatut->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);"));
        barMois = new BarChartWidget(tab_4);
        barMois->setObjectName("barMois");
        barMois->setGeometry(QRect(80, 260, 661, 371));
        barMois->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);"));
        label_47 = new QLabel(tab_4);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(10, 10, 191, 31));
        label_47->setFont(font);
        label_47->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_81 = new QLabel(tab_4);
        label_81->setObjectName("label_81");
        label_81->setGeometry(QRect(10, 120, 191, 31));
        label_81->setFont(font);
        label_81->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/ressource/11.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        tabWidget_2->addTab(tab_4, icon16, QString());
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setStyleSheet(QString::fromUtf8("background:transparent;"));
        verticalLayout_3 = new QVBoxLayout(page_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        btn_home = new QTabWidget(page_3);
        btn_home->setObjectName("btn_home");
        btn_home->setAutoFillBackground(false);
        btn_home->setStyleSheet(QString::fromUtf8("/* ========= PANE TRANSPARENT (fond du QTabWidget) ========= */\n"
"QTabWidget#btn_home::pane {\n"
"    border: none;\n"
"    background: transparent;   /* on voit ton background global */\n"
"}\n"
"\n"
"/* Position de la barre d'onglets */\n"
"QTabWidget#btn_home::tab-bar {\n"
"    alignment: left;\n"
"}\n"
"\n"
"/* ========= ONGLET NORMAL (non s\303\251lectionn\303\251) ========= */\n"
"QTabWidget#btn_home QTabBar::tab {\n"
"    background: transparent;\n"
"    color: #ffffff;\n"
"    padding: 6px 22px;\n"
"    border: none;\n"
"    margin-right: 8px;\n"
"    margin-bottom: 8px;        /* \360\237\224\245 d\303\251tache l\342\200\231onglet du pane \342\206\222 on voit bien l\342\200\231arrondi */\n"
"    font-weight: 600;\n"
"    border-radius: 50px;       /* forme capsule, pas carr\303\251 */\n"
"}\n"
"\n"
"/* ========= ONGLET S\303\211LECTIONN\303\211 (capsule violette) ========= */\n"
"QTabWidget#btn_home QTabBar::tab:selected {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
""
                        "        stop:0 #c72cff,\n"
"        stop:1 #4a7dff\n"
"    );\n"
"    color: #ffffff;\n"
"    border-radius: 50px;\n"
"}\n"
"\n"
"/* ========= HOVER (survol l\303\251ger) ========= */\n"
"QTabWidget#btn_home QTabBar::tab:hover {\n"
"    background: rgba(255, 255, 255, 0.12);\n"
"    border-radius: 18px;\n"
"}\n"
""));
        btn_home->setIconSize(QSize(30, 30));
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        confirm = new QPushButton(tab_5);
        confirm->setObjectName("confirm");
        confirm->setGeometry(QRect(30, 610, 141, 51));
        confirm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        confirm->setIcon(icon6);
        confirm->setIconSize(QSize(30, 30));
        delete_2 = new QPushButton(tab_5);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(190, 610, 151, 51));
        delete_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        delete_2->setIcon(icon7);
        delete_2->setIconSize(QSize(45, 40));
        widget_3 = new QWidget(tab_5);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(450, 50, 811, 541));
        widget_3->setStyleSheet(QString::fromUtf8("#widget_3 {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"\n"
"        /* Bleu tr\303\250s clair en entr\303\251e */\n"
"        stop:0 rgba(90, 150, 255, 70),\n"
"\n"
"        /* Bleu encore plus clair au centre */\n"
"        stop:0.5 rgba(140, 190, 255, 60),\n"
"\n"
"        /* Bleu l\303\251ger et doux en sortie */\n"
"        stop:1 rgba(100, 160, 255, 70)\n"
"    );\n"
"\n"
"    border-radius: 26px;\n"
"\n"
"    /* contour tr\303\250s discret */\n"
"    border: 1px solid rgba(255, 255, 255, 50);\n"
"\n"
"    /* Reflet int\303\251rieur tr\303\250s soft (effet verre) */\n"
"    box-shadow:\n"
"        inset 0 0 35px rgba(255, 255, 255, 30),\n"
"        0 0 20px rgba(100, 160, 255, 25);\n"
"}\n"
""));
        tab_Art = new QTableWidget(widget_3);
        if (tab_Art->columnCount() < 6)
            tab_Art->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tab_Art->setHorizontalHeaderItem(0, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tab_Art->setHorizontalHeaderItem(1, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tab_Art->setHorizontalHeaderItem(2, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tab_Art->setHorizontalHeaderItem(3, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tab_Art->setHorizontalHeaderItem(4, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tab_Art->setHorizontalHeaderItem(5, __qtablewidgetitem60);
        if (tab_Art->rowCount() < 5)
            tab_Art->setRowCount(5);
        tab_Art->setObjectName("tab_Art");
        tab_Art->setGeometry(QRect(20, 180, 761, 231));
        tab_Art->setStyleSheet(QString::fromUtf8("\n"
"QHeaderView::section {\n"
"    background-color: rgb(173, 216, 230);\n"
"    color: black;\n"
"    font-weight: bold;\n"
"}\n"
"QTableWidget::item {\n"
"    background-color: white; \n"
"    color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        DEL = new QPushButton(widget_3);
        DEL->setObjectName("DEL");
        DEL->setGeometry(QRect(620, 470, 181, 51));
        DEL->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        DEL->setIcon(icon9);
        DEL->setIconSize(QSize(30, 30));
        btn_pdf = new QPushButton(widget_3);
        btn_pdf->setObjectName("btn_pdf");
        btn_pdf->setGeometry(QRect(430, 470, 181, 51));
        btn_pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        btn_pdf->setIcon(icon8);
        btn_pdf->setIconSize(QSize(30, 30));
        label_26 = new QLabel(widget_3);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(50, 120, 35, 26));
        label_26->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        sku_2 = new QLineEdit(widget_3);
        sku_2->setObjectName("sku_2");
        sku_2->setGeometry(QRect(100, 110, 141, 41));
        sku_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_27 = new QLabel(widget_3);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(300, 120, 95, 26));
        label_27->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_28 = new QLabel(widget_3);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(540, 120, 196, 26));
        label_28->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        rech_tri = new QComboBox(widget_3);
        rech_tri->addItem(QString());
        rech_tri->addItem(QString());
        rech_tri->setObjectName("rech_tri");
        rech_tri->setGeometry(QRect(620, 110, 151, 41));
        rech_tri->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        rech_Bra = new QComboBox(widget_3);
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->addItem(QString());
        rech_Bra->setObjectName("rech_Bra");
        rech_Bra->setGeometry(QRect(360, 110, 161, 41));
        rech_Bra->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_29 = new QLabel(widget_3);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(40, 50, 41, 41));
        label_29->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_29->setPixmap(QPixmap(QString::fromUtf8("ressource/15.png")));
        label_29->setScaledContents(true);
        label_30 = new QLabel(widget_3);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(80, 50, 361, 41));
        label_30->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_41 = new QLabel(widget_3);
        label_41->setObjectName("label_41");
        label_41->setGeometry(QRect(10, 120, 35, 26));
        label_41->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_41->setPixmap(QPixmap(QString::fromUtf8("ressource/16.png")));
        label_41->setScaledContents(true);
        label_46 = new QLabel(widget_3);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(260, 105, 31, 41));
        label_46->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_46->setPixmap(QPixmap(QString::fromUtf8("ressource/17.png")));
        label_46->setScaledContents(true);
        widget_2 = new QWidget(tab_5);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 40, 401, 551));
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2 {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"\n"
"        /* Bleu tr\303\250s clair en entr\303\251e */\n"
"        stop:0 rgba(90, 150, 255, 70),\n"
"\n"
"        /* Bleu encore plus clair au centre */\n"
"        stop:0.5 rgba(140, 190, 255, 60),\n"
"\n"
"        /* Bleu l\303\251ger et doux en sortie */\n"
"        stop:1 rgba(100, 160, 255, 70)\n"
"    );\n"
"\n"
"    border-radius: 26px;\n"
"\n"
"    /* contour tr\303\250s discret */\n"
"    border: 1px solid rgba(255, 255, 255, 50);\n"
"\n"
"    /* Reflet int\303\251rieur tr\303\250s soft (effet verre) */\n"
"    box-shadow:\n"
"        inset 0 0 35px rgba(255, 255, 255, 30),\n"
"        0 0 20px rgba(100, 160, 255, 25);\n"
"}\n"
""));
        label_56 = new QLabel(widget_2);
        label_56->setObjectName("label_56");
        label_56->setGeometry(QRect(10, 40, 35, 26));
        label_56->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_56->setPixmap(QPixmap(QString::fromUtf8("ressource/16.png")));
        label_56->setScaledContents(true);
        label_59 = new QLabel(widget_2);
        label_59->setObjectName("label_59");
        label_59->setGeometry(QRect(10, 210, 31, 41));
        label_59->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_59->setPixmap(QPixmap(QString::fromUtf8("ressource/17.png")));
        label_59->setScaledContents(true);
        label_60 = new QLabel(widget_2);
        label_60->setObjectName("label_60");
        label_60->setGeometry(QRect(10, 100, 35, 26));
        label_60->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_60->setPixmap(QPixmap(QString::fromUtf8("ressource/22.png")));
        label_60->setScaledContents(true);
        label_61 = new QLabel(widget_2);
        label_61->setObjectName("label_61");
        label_61->setGeometry(QRect(10, 160, 35, 26));
        label_61->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_61->setPixmap(QPixmap(QString::fromUtf8("ressource/28.png")));
        label_61->setScaledContents(true);
        label_62 = new QLabel(widget_2);
        label_62->setObjectName("label_62");
        label_62->setGeometry(QRect(10, 270, 35, 26));
        label_62->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_62->setPixmap(QPixmap(QString::fromUtf8("ressource/29.png")));
        label_62->setScaledContents(true);
        label_63 = new QLabel(widget_2);
        label_63->setObjectName("label_63");
        label_63->setGeometry(QRect(10, 330, 31, 26));
        label_63->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_63->setPixmap(QPixmap(QString::fromUtf8("ressource/30.png")));
        label_63->setScaledContents(true);
        label_64 = new QLabel(widget_2);
        label_64->setObjectName("label_64");
        label_64->setGeometry(QRect(10, 380, 35, 26));
        label_64->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_64->setPixmap(QPixmap(QString::fromUtf8("ressource/9.png")));
        label_64->setScaledContents(true);
        label_65 = new QLabel(widget_2);
        label_65->setObjectName("label_65");
        label_65->setGeometry(QRect(10, 440, 35, 26));
        label_65->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_65->setPixmap(QPixmap(QString::fromUtf8("ressource/24.png")));
        label_65->setScaledContents(true);
        label_66 = new QLabel(widget_2);
        label_66->setObjectName("label_66");
        label_66->setGeometry(QRect(10, 500, 35, 26));
        label_66->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_66->setPixmap(QPixmap(QString::fromUtf8("ressource/31.png")));
        label_66->setScaledContents(true);
        label_19 = new QLabel(widget_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(50, 160, 111, 31));
        label_19->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_18 = new QLabel(widget_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(50, 100, 81, 31));
        label_18->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_22 = new QLabel(widget_2);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(50, 330, 131, 24));
        label_22->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_21 = new QLabel(widget_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(50, 270, 141, 24));
        label_21->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_23 = new QLabel(widget_2);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(50, 380, 91, 24));
        label_23->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_17 = new QLabel(widget_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(60, 40, 45, 24));
        label_17->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_20 = new QLabel(widget_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(50, 220, 81, 24));
        label_20->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_24 = new QLabel(widget_2);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(50, 440, 101, 24));
        label_24->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        label_25 = new QLabel(widget_2);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(50, 500, 141, 24));
        label_25->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        com = new QLineEdit(widget_2);
        com->setObjectName("com");
        com->setGeometry(QRect(200, 490, 151, 41));
        com->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        loca = new QLineEdit(widget_2);
        loca->setObjectName("loca");
        loca->setGeometry(QRect(200, 430, 151, 41));
        loca->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        stock = new QLineEdit(widget_2);
        stock->setObjectName("stock");
        stock->setGeometry(QRect(200, 370, 151, 41));
        stock->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        cat = new QComboBox(widget_2);
        cat->addItem(QString());
        cat->addItem(QString());
        cat->addItem(QString());
        cat->addItem(QString());
        cat->addItem(QString());
        cat->addItem(QString());
        cat->addItem(QString());
        cat->addItem(QString());
        cat->setObjectName("cat");
        cat->setGeometry(QRect(200, 140, 151, 41));
        cat->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        sku = new QLineEdit(widget_2);
        sku->setObjectName("sku");
        sku->setGeometry(QRect(200, 30, 151, 41));
        sku->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        name = new QLineEdit(widget_2);
        name->setObjectName("name");
        name->setGeometry(QRect(200, 90, 151, 41));
        name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        brand = new QComboBox(widget_2);
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->setObjectName("brand");
        brand->setGeometry(QRect(200, 200, 151, 41));
        brand->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        price2 = new QLineEdit(widget_2);
        price2->setObjectName("price2");
        price2->setGeometry(QRect(200, 320, 151, 41));
        price2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        price1 = new QLineEdit(widget_2);
        price1->setObjectName("price1");
        price1->setGeometry(QRect(200, 260, 151, 41));
        price1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        btn_add = new QPushButton(tab_5);
        btn_add->setObjectName("btn_add");
        btn_add->setGeometry(QRect(30, 10, 191, 51));
        btn_add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        btn_home->addTab(tab_5, icon11, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        btn_stats = new QPushButton(tab_6);
        btn_stats->setObjectName("btn_stats");
        btn_stats->setGeometry(QRect(930, 540, 221, 51));
        btn_stats->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8("ressource/26.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_stats->setIcon(icon17);
        btn_stats->setIconSize(QSize(40, 40));
        stockStatsContainer = new QWidget(tab_6);
        stockStatsContainer->setObjectName("stockStatsContainer");
        stockStatsContainer->setGeometry(QRect(30, 30, 1121, 401));
        btn_ai_stock = new QPushButton(tab_6);
        btn_ai_stock->setObjectName("btn_ai_stock");
        btn_ai_stock->setGeometry(QRect(700, 540, 211, 51));
        btn_ai_stock->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8("ressource/27.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_ai_stock->setIcon(icon18);
        btn_ai_stock->setIconSize(QSize(40, 40));
        btn_home->addTab(tab_6, icon12, QString());

        verticalLayout_3->addWidget(btn_home);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        verticalLayout_4 = new QVBoxLayout(page_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        tabWidget_3 = new QTabWidget(page_4);
        tabWidget_3->setObjectName("tabWidget_3");
        tabWidget_3->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: transparent;\n"
"    border: none;\n"
"    color: white;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: rgba(255,255,255,0);\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: rgba(255,255,255,0.05);\n"
"}\n"
"\n"
"/* Rendre la PAGE interne transparente */\n"
"QTabWidget > QWidget {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
""));
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        groupBox_4 = new QGroupBox(tab_7);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(20, 60, 461, 571));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        P_id = new QLineEdit(groupBox_4);
        P_id->setObjectName("P_id");
        P_id->setGeometry(QRect(200, 80, 171, 41));
        P_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_32 = new QLabel(groupBox_4);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(90, 90, 41, 20));
        label_32->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#ffffff;\n"
"font-weight: bold;"));
        lineEdit_16 = new QLineEdit(groupBox_4);
        lineEdit_16->setObjectName("lineEdit_16");
        lineEdit_16->setGeometry(QRect(200, 170, 181, 41));
        lineEdit_16->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_33 = new QLabel(groupBox_4);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(100, 180, 81, 20));
        label_33->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 11pt;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        label_34 = new QLabel(groupBox_4);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(80, 270, 121, 20));
        label_34->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 11pt;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        label_35 = new QLabel(groupBox_4);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(100, 370, 61, 20));
        label_35->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 11pt;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        label_36 = new QLabel(groupBox_4);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(90, 450, 63, 20));
        label_36->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 11pt;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        dateEdit = new QDateEdit(groupBox_4);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(200, 360, 181, 41));
        dateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/images/ressource/icons8-calendar-50.png);\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}\n"
""));
        pushButton_25 = new QPushButton(groupBox_4);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(20, 0, 161, 51));
        pushButton_25->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8("ressource/95.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_25->setIcon(icon19);
        pushButton_25->setIconSize(QSize(25, 25));
        comboBox_3 = new QComboBox(groupBox_4);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(210, 260, 181, 41));
        comboBox_3->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/ressource/arrow-down.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background: #1a1a2e;\n"
"    color: white;\n"
"    selection-background-color: #6a7cff;\n"
"    border: 1px solid #00eaff;\n"
"}\n"
""));
        comboBox_3->setIconSize(QSize(50, 50));
        comboBox_4 = new QComboBox(groupBox_4);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(190, 440, 191, 41));
        comboBox_4->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/ressource/arrow-down.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background: #1a1a2e;\n"
"    color: white;\n"
"    selection-background-color: #6a7cff;\n"
"    border: 1px solid #00eaff;\n"
"}\n"
""));
        label_76 = new QLabel(groupBox_4);
        label_76->setObjectName("label_76");
        label_76->setGeometry(QRect(10, 80, 71, 41));
        label_76->setPixmap(QPixmap(QString::fromUtf8("ressource/90.png")));
        label_76->setScaledContents(true);
        label_77 = new QLabel(groupBox_4);
        label_77->setObjectName("label_77");
        label_77->setGeometry(QRect(10, 170, 81, 41));
        label_77->setPixmap(QPixmap(QString::fromUtf8("ressource/91.png")));
        label_77->setScaledContents(true);
        label_78 = new QLabel(groupBox_4);
        label_78->setObjectName("label_78");
        label_78->setGeometry(QRect(10, 260, 61, 41));
        label_78->setPixmap(QPixmap(QString::fromUtf8("ressource/92.png")));
        label_78->setScaledContents(true);
        label_79 = new QLabel(groupBox_4);
        label_79->setObjectName("label_79");
        label_79->setGeometry(QRect(10, 350, 61, 51));
        label_79->setPixmap(QPixmap(QString::fromUtf8("ressource/93.png")));
        label_79->setScaledContents(true);
        label_80 = new QLabel(groupBox_4);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(10, 440, 61, 51));
        label_80->setPixmap(QPixmap(QString::fromUtf8("ressource/94.png")));
        label_80->setScaledContents(true);
        label_32->raise();
        lineEdit_16->raise();
        label_33->raise();
        label_34->raise();
        label_35->raise();
        label_36->raise();
        pushButton_25->raise();
        comboBox_4->raise();
        P_id->raise();
        dateEdit->raise();
        comboBox_3->raise();
        label_76->raise();
        label_77->raise();
        label_78->raise();
        label_79->raise();
        label_80->raise();
        transaction_container = new QWidget(tab_7);
        transaction_container->setObjectName("transaction_container");
        transaction_container->setGeometry(QRect(570, 80, 721, 491));
        transaction_container->setStyleSheet(QString::fromUtf8("#transaction_container {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"\n"
"        /* Bleu tr\303\250s clair en entr\303\251e */\n"
"        stop:0 rgba(90, 150, 255, 70),\n"
"\n"
"        /* Bleu encore plus clair au centre */\n"
"        stop:0.5 rgba(140, 190, 255, 60),\n"
"\n"
"        /* Bleu l\303\251ger et doux en sortie */\n"
"        stop:1 rgba(100, 160, 255, 70)\n"
"    );\n"
"\n"
"    border-radius: 26px;\n"
"\n"
"    /* contour tr\303\250s discret */\n"
"    border: 1px solid rgba(255, 255, 255, 50);\n"
"\n"
"    /* Reflet int\303\251rieur tr\303\250s soft (effet verre) */\n"
"    box-shadow:\n"
"        inset 0 0 35px rgba(255, 255, 255, 30),\n"
"        0 0 20px rgba(100, 160, 255, 25);\n"
"}\n"
""));
        comboBoxsort = new QComboBox(transaction_container);
        comboBoxsort->addItem(QString());
        comboBoxsort->addItem(QString());
        comboBoxsort->addItem(QString());
        comboBoxsort->setObjectName("comboBoxsort");
        comboBoxsort->setGeometry(QRect(370, 40, 121, 41));
        comboBoxsort->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/ressource/arrow-down.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background: #1a1a2e;\n"
"    color: white;\n"
"    selection-background-color: #6a7cff;\n"
"    border: 1px solid #00eaff;\n"
"}\n"
""));
        comboBoxSortOrder = new QComboBox(transaction_container);
        comboBoxSortOrder->addItem(QString());
        comboBoxSortOrder->addItem(QString());
        comboBoxSortOrder->addItem(QString());
        comboBoxSortOrder->setObjectName("comboBoxSortOrder");
        comboBoxSortOrder->setGeometry(QRect(540, 40, 101, 41));
        comboBoxSortOrder->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/ressource/arrow-down.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background: #1a1a2e;\n"
"    color: white;\n"
"    selection-background-color: #6a7cff;\n"
"    border: 1px solid #00eaff;\n"
"}\n"
""));
        lineEdit_17 = new QLineEdit(transaction_container);
        lineEdit_17->setObjectName("lineEdit_17");
        lineEdit_17->setGeometry(QRect(180, 40, 131, 41));
        lineEdit_17->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        label_37 = new QLabel(transaction_container);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(20, 50, 141, 20));
        label_37->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 11pt;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        pushButton_27 = new QPushButton(transaction_container);
        pushButton_27->setObjectName("pushButton_27");
        pushButton_27->setGeometry(QRect(20, 390, 191, 51));
        pushButton_27->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8("ressource/96.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_27->setIcon(icon20);
        pushButton_27->setIconSize(QSize(30, 30));
        pushButton_28 = new QPushButton(transaction_container);
        pushButton_28->setObjectName("pushButton_28");
        pushButton_28->setGeometry(QRect(390, 390, 131, 51));
        pushButton_28->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"\n"
"    /* forme capsule parfaite */\n"
"    padding: 10px 28px;\n"
"    border-radius: 22px;\n"
"\n"
"    /* d\303\251grad\303\251 violet \342\206\222 bleu (identique \303\240 la maquette) */\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d147ff,     /* violet clair */\n"
"        stop:1 #4a7dff      /* bleu clair */\n"
"    );\n"
"\n"
"    border: none;\n"
"\n"
"    /* Glow l\303\251ger autour du bouton (comme la maquette) */\n"
"    box-shadow: 0px 0px 12px rgba(120, 140, 255, 0.45);\n"
"}\n"
"\n"
"/* Effet hover : un peu plus lumineux */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e66bff,\n"
"        stop:1 #6a92ff\n"
"    );\n"
"}\n"
"\n"
"/* Effet clic : bouton \303\251cras\303\251 l\303\251g\303\250rement */\n"
"QPushButton:pressed {\n"
"    transform: scale(0.96);\n"
"    box-shadow: 0px 0px 6px rgba(120, 140, 255, 0.3"
                        ");\n"
"}\n"
""));
        pushButton_28->setIcon(icon9);
        pushButton_28->setIconSize(QSize(25, 25));
        lineEdit_18 = new QLineEdit(transaction_container);
        lineEdit_18->setObjectName("lineEdit_18");
        lineEdit_18->setGeometry(QRect(550, 390, 161, 51));
        lineEdit_18->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: white;\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 18px;\n"
"\n"
"    /* Bordure lumineuse bleu/cyan comme la photo */\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"}\n"
"\n"
"/* Effet glow au focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00eaff;\n"
"    box-shadow: 0 0 12px #00eaff;\n"
"}\n"
""));
        tableWidget_4 = new QTableWidget(transaction_container);
        if (tableWidget_4->columnCount() < 5)
            tableWidget_4->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(4, __qtablewidgetitem65);
        if (tableWidget_4->rowCount() < 8)
            tableWidget_4->setRowCount(8);
        tableWidget_4->setObjectName("tableWidget_4");
        tableWidget_4->setGeometry(QRect(30, 90, 671, 271));
        tableWidget_4->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 rgba(26, 26, 46, 0.95),\n"
"        stop:1 rgba(20, 20, 35, 0.98)\n"
"    );\n"
"    color: white;\n"
"    gridline-color: rgba(100, 200, 255, 0.2);\n"
"    border: 2px solid qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"    border-radius: 8px;\n"
"    selection-background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(0, 234, 255, 0.3),\n"
"        stop:1 rgba(106, 124, 255, 0.3)\n"
"    );\n"
"    selection-color: white;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"    font-size: 11pt;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 8px;\n"
"    border: none;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background: rgba(0, 234, 255, 0.15);\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        sto"
                        "p:0 rgba(0, 234, 255, 0.4),\n"
"        stop:1 rgba(106, 124, 255, 0.4)\n"
"    );\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #4472C4,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"    color: white;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    font-size: 11pt;\n"
"    border-right: 1px solid rgba(255, 255, 255, 0.1);\n"
"}\n"
"\n"
"QHeaderView::section:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #5588dd,\n"
"        stop:1 #7a8cff\n"
"    );\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background: rgba(26, 26, 46, 0.5);\n"
"    width: 12px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"    border-radius: 6px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QS"
                        "crollBar::handle:vertical:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00ffff,\n"
"        stop:1 #7a8cff\n"
"    );\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: rgba(26, 26, 46, 0.5);\n"
"    height: 12px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00eaff,\n"
"        stop:1 #6a7cff\n"
"    );\n"
"    border-radius: 6px;\n"
"    min-width: 20px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00ffff,\n"
"        stop:1 #7a8cff\n"
"    );\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background: #4472C4;\n"
"    border"
                        ": none;\n"
"}\n"
""));
        darkmode_button = new QPushButton(tab_7);
        darkmode_button->setObjectName("darkmode_button");
        darkmode_button->setGeometry(QRect(20, 10, 51, 31));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/images/ressource/night-mode.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        darkmode_button->setIcon(icon21);
        tabWidget_3->addTab(tab_7, icon11, QString());
        fa = new QWidget();
        fa->setObjectName("fa");
        label_38 = new QLabel(fa);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(600, 10, 701, 551));
        label_38->setStyleSheet(QString::fromUtf8(" background-image: url(:/images/ressource/chart2.png);"));
        label_38->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/chart2.png")));
        label_38->setScaledContents(true);
        label_39 = new QLabel(fa);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(0, 10, 561, 551));
        label_39->setStyleSheet(QString::fromUtf8(" background-image: url(:/images/ressource/testchart.png);"));
        label_39->setPixmap(QPixmap(QString::fromUtf8(":/images/ressource/testchart.png")));
        label_39->setScaledContents(true);
        tabWidget_3->addTab(fa, icon12, QString());

        verticalLayout_4->addWidget(tabWidget_3);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        tabWidget_4 = new QTabWidget(page_5);
        tabWidget_4->setObjectName("tabWidget_4");
        tabWidget_4->setGeometry(QRect(0, 0, 1191, 601));
        tabWidget_4->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: transparent;\n"
"    border: none;\n"
"    color: white;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: rgba(255,255,255,0);\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: rgba(255,255,255,0.05);\n"
"}\n"
"\n"
"/* Rendre la PAGE interne transparente */\n"
"QTabWidget > QWidget {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
""));
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        btnPointage = new QPushButton(tab_8);
        btnPointage->setObjectName("btnPointage");
        btnPointage->setGeometry(QRect(510, 450, 141, 31));
        btnPointage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        export_pp = new QPushButton(tab_8);
        export_pp->setObjectName("export_pp");
        export_pp->setGeometry(QRect(250, 460, 141, 31));
        export_pp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        tab_Employee = new QTableWidget(tab_8);
        if (tab_Employee->columnCount() < 6)
            tab_Employee->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tab_Employee->setHorizontalHeaderItem(0, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tab_Employee->setHorizontalHeaderItem(1, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tab_Employee->setHorizontalHeaderItem(2, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tab_Employee->setHorizontalHeaderItem(3, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tab_Employee->setHorizontalHeaderItem(4, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tab_Employee->setHorizontalHeaderItem(5, __qtablewidgetitem71);
        if (tab_Employee->rowCount() < 12)
            tab_Employee->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tab_Employee->setVerticalHeaderItem(0, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tab_Employee->setVerticalHeaderItem(1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tab_Employee->setVerticalHeaderItem(2, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tab_Employee->setVerticalHeaderItem(3, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tab_Employee->setVerticalHeaderItem(4, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        tab_Employee->setVerticalHeaderItem(5, __qtablewidgetitem77);
        tab_Employee->setObjectName("tab_Employee");
        tab_Employee->setGeometry(QRect(40, 120, 491, 291));
        tab_Employee->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        pushButton_32 = new QPushButton(tab_8);
        pushButton_32->setObjectName("pushButton_32");
        pushButton_32->setGeometry(QRect(560, 120, 93, 29));
        pushButton_32->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_39 = new QPushButton(tab_8);
        pushButton_39->setObjectName("pushButton_39");
        pushButton_39->setGeometry(QRect(690, -10, 131, 29));
        pushButton_39->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        groupBox_5 = new QGroupBox(tab_8);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(690, 20, 291, 411));
        groupBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        label_50 = new QLabel(groupBox_5);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(30, 40, 41, 20));
        label_50->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_51 = new QLabel(groupBox_5);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(30, 100, 101, 20));
        label_51->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_52 = new QLabel(groupBox_5);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(30, 240, 71, 20));
        label_52->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_53 = new QLabel(groupBox_5);
        label_53->setObjectName("label_53");
        label_53->setGeometry(QRect(30, 170, 101, 20));
        label_53->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_54 = new QLabel(groupBox_5);
        label_54->setObjectName("label_54");
        label_54->setGeometry(QRect(30, 300, 101, 20));
        label_54->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        label_55 = new QLabel(groupBox_5);
        label_55->setObjectName("label_55");
        label_55->setGeometry(QRect(30, 360, 81, 21));
        label_55->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";\n"
""));
        e_cin = new QLineEdit(groupBox_5);
        e_cin->setObjectName("e_cin");
        e_cin->setGeometry(QRect(150, 40, 113, 31));
        e_cin->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        e_address = new QLineEdit(groupBox_5);
        e_address->setObjectName("e_address");
        e_address->setGeometry(QRect(150, 240, 113, 31));
        e_address->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        e_salary = new QLineEdit(groupBox_5);
        e_salary->setObjectName("e_salary");
        e_salary->setGeometry(QRect(150, 300, 113, 31));
        e_salary->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        e_fullname = new QLineEdit(groupBox_5);
        e_fullname->setObjectName("e_fullname");
        e_fullname->setGeometry(QRect(150, 100, 113, 31));
        e_fullname->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        e_position = new QComboBox(groupBox_5);
        e_position->addItem(QString());
        e_position->addItem(QString());
        e_position->addItem(QString());
        e_position->addItem(QString());
        e_position->addItem(QString());
        e_position->addItem(QString());
        e_position->addItem(QString());
        e_position->addItem(QString());
        e_position->setObjectName("e_position");
        e_position->setGeometry(QRect(145, 170, 121, 26));
        e_status = new QComboBox(groupBox_5);
        e_status->addItem(QString());
        e_status->addItem(QString());
        e_status->addItem(QString());
        e_status->addItem(QString());
        e_status->addItem(QString());
        e_status->setObjectName("e_status");
        e_status->setGeometry(QRect(150, 350, 111, 26));
        label_49 = new QLabel(tab_8);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(60, 60, 181, 20));
        label_49->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";"));
        confirmb = new QPushButton(tab_8);
        confirmb->setObjectName("confirmb");
        confirmb->setGeometry(QRect(1040, 130, 93, 29));
        confirmb->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_29 = new QPushButton(tab_8);
        pushButton_29->setObjectName("pushButton_29");
        pushButton_29->setGeometry(QRect(460, 60, 93, 29));
        pushButton_29->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        lineEdit_19 = new QLineEdit(tab_8);
        lineEdit_19->setObjectName("lineEdit_19");
        lineEdit_19->setGeometry(QRect(260, 50, 131, 41));
        lineEdit_19->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        pushButton_31 = new QPushButton(tab_8);
        pushButton_31->setObjectName("pushButton_31");
        pushButton_31->setGeometry(QRect(890, 460, 93, 29));
        pushButton_31->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        label_48 = new QLabel(tab_8);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(50, 420, 63, 20));
        label_48->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Swis721 Blk BT\";"));
        pushButton_41 = new QPushButton(tab_8);
        pushButton_41->setObjectName("pushButton_41");
        pushButton_41->setGeometry(QRect(1040, 300, 93, 29));
        pushButton_41->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        lineEdit_20 = new QLineEdit(tab_8);
        lineEdit_20->setObjectName("lineEdit_20");
        lineEdit_20->setGeometry(QRect(990, 460, 113, 26));
        lineEdit_20->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        comboBox_Emp_Sort = new QComboBox(tab_8);
        comboBox_Emp_Sort->addItem(QString());
        comboBox_Emp_Sort->addItem(QString());
        comboBox_Emp_Sort->addItem(QString());
        comboBox_Emp_Sort->addItem(QString());
        comboBox_Emp_Sort->setObjectName("comboBox_Emp_Sort");
        comboBox_Emp_Sort->setGeometry(QRect(150, 420, 111, 26));
        tabWidget_4->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        widget_Emp_Chart_2 = new QWidget(tab_9);
        widget_Emp_Chart_2->setObjectName("widget_Emp_Chart_2");
        widget_Emp_Chart_2->setGeometry(QRect(210, 140, 661, 321));
        pushButton_Emp_Stats = new QPushButton(tab_9);
        pushButton_Emp_Stats->setObjectName("pushButton_Emp_Stats");
        pushButton_Emp_Stats->setGeometry(QRect(420, 60, 211, 29));
        pushButton_Emp_Stats->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 900 9pt \"Swis721 Blk BT\";\n"
"    background-color: #003271;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"QPushButton:hover { background-color: #004599; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        tabWidget_4->addTab(tab_9, QString());
        stackedWidget->addWidget(page_5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1543, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);
        page_FeedbackClient->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);
        btn_home->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);
        tabWidget_4->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QString());
        btn_Client->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        quit->setText(QString());
        logo->setText(QString());
        btn_Stock->setText(QCoreApplication::translate("MainWindow", "STOCKS", nullptr));
        btn_Employee->setText(QCoreApplication::translate("MainWindow", "Employees", nullptr));
        btn_Commande->setText(QCoreApplication::translate("MainWindow", "Order", nullptr));
        btn_Transaction->setText(QCoreApplication::translate("MainWindow", "Transaction", nullptr));
        label_58->setText(QString());
        chat_bot->setText(QCoreApplication::translate("MainWindow", "CHAT BOT", nullptr));
        c_confirm->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        c_delete->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", " Export to PDF", nullptr));
        c_Line_rech->setPlaceholderText(QCoreApplication::translate("MainWindow", "          CIN", nullptr));
        sort->setItemText(0, QCoreApplication::translate("MainWindow", "Name", nullptr));
        sort->setItemText(1, QCoreApplication::translate("MainWindow", "Adress", nullptr));
        sort->setItemText(2, QString());

        label_8->setText(QCoreApplication::translate("MainWindow", "Search for a client:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Sort By:", nullptr));
        rech->setPlaceholderText(QCoreApplication::translate("MainWindow", "CIN,Name,Email", nullptr));
        c_DEL->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab_Client->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "CIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab_Client->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab_Client->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab_Client->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab_Client->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Adress", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab_Client->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Phone Nbr", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tab_Client->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));

        const bool __sortingEnabled = tab_Client->isSortingEnabled();
        tab_Client->setSortingEnabled(false);
        tab_Client->setSortingEnabled(__sortingEnabled);

        pushButton_6->setText(QString());
        label_67->setText(QString());
        label_68->setText(QString());
        label_31->setText(QCoreApplication::translate("MainWindow", "Age:", nullptr));
        c_phone->setPlaceholderText(QCoreApplication::translate("MainWindow", " ** *** ***", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CIN:", nullptr));
        c_adress->setPlaceholderText(QCoreApplication::translate("MainWindow", "Complete Adress", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Last Name:", nullptr));
        c_cin->setPlaceholderText(QCoreApplication::translate("MainWindow", "CIN(********)", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Phone nbr:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Adress:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "First Name:", nullptr));
        c_email->setPlaceholderText(QCoreApplication::translate("MainWindow", "email@exemple.com", nullptr));
        label_69->setText(QString());
        label_70->setText(QString());
        label_71->setText(QString());
        label_72->setText(QString());
        label_73->setText(QString());
        label_74->setText(QString());
        label_75->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add Client", nullptr));
        page_FeedbackClient->setTabText(page_FeedbackClient->indexOf(tab), QCoreApplication::translate("MainWindow", "Home", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "Age: 18-25", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "Age: 25-40", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "Age: 40-60", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "Age:   +60", nullptr));
        page_FeedbackClient->setTabText(page_FeedbackClient->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        page_FeedbackClient->setTabText(page_FeedbackClient->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Logs", nullptr));
        page_FeedbackClient->setTabText(page_FeedbackClient->indexOf(tab_11), QCoreApplication::translate("MainWindow", "page_FeedbackClient ", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableauCommande->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableauCommande->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableauCommande->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Products", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableauCommande->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableauCommande->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableauCommande->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "client", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", " Delete Order ", nullptr));
        lineEdit_search->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search by code or client", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainWindow", " Search :", nullptr));
        groupBox_3->setTitle(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "code :", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Date :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Products :", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Total :", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Status :", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "client :", nullptr));
        lineEdit_code->setPlaceholderText(QCoreApplication::translate("MainWindow", "x-xxxx", nullptr));
        comboBox_status->setItemText(0, QCoreApplication::translate("MainWindow", "pending", nullptr));
        comboBox_status->setItemText(1, QCoreApplication::translate("MainWindow", "in progress", nullptr));
        comboBox_status->setItemText(2, QCoreApplication::translate("MainWindow", "delivered", nullptr));
        comboBox_status->setItemText(3, QCoreApplication::translate("MainWindow", "cancelled", nullptr));

        label_87->setText(QString());
        label_88->setText(QString());
        label_92->setText(QString());
        label_93->setText(QString());
        label_94->setText(QString());
        label_96->setText(QString());
        label_85->setText(QString());
        label_86->setText(QString());
        label_97->setText(QString());
        comboBox_trie->setItemText(0, QString());
        comboBox_trie->setItemText(1, QCoreApplication::translate("MainWindow", "status", nullptr));
        comboBox_trie->setItemText(2, QCoreApplication::translate("MainWindow", "date", nullptr));

        label_15->setText(QCoreApplication::translate("MainWindow", "sort by :", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "Confirm ", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "cancel ", nullptr));
        pushButton_deliveryTracking->setText(QCoreApplication::translate("MainWindow", "Delivery Tracking", nullptr));
        btnExportCatalogue->setText(QCoreApplication::translate("MainWindow", "Catalogue", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", " Add Order ", nullptr));
        label_82->setText(QString());
        label_83->setText(QString());
        label_16->setText(QString());
        label_84->setText(QString());
        label_90->setText(QString());
        label_91->setText(QString());
        label_95->setText(QString());
        label_89->setText(QString());
        label_98->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("MainWindow", " Home", nullptr));
        label_total->setText(QString());
        label_revenu->setText(QString());
        label_47->setText(QCoreApplication::translate("MainWindow", "number of orders :", nullptr));
        label_81->setText(QCoreApplication::translate("MainWindow", "income :", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        confirm->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        delete_2->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tab_Art->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "SKU", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tab_Art->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tab_Art->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tab_Art->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Brand", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tab_Art->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Purchase Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tab_Art->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Selling Price", nullptr));
        DEL->setText(QCoreApplication::translate("MainWindow", "  Delete", nullptr));
        btn_pdf->setText(QCoreApplication::translate("MainWindow", "   Export PDF", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "SKU", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Brand ", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Sort By", nullptr));
        rech_tri->setItemText(0, QCoreApplication::translate("MainWindow", "Sort by", nullptr));
        rech_tri->setItemText(1, QCoreApplication::translate("MainWindow", "stock", nullptr));

        rech_Bra->setItemText(0, QCoreApplication::translate("MainWindow", "Select the brand", nullptr));
        rech_Bra->setItemText(1, QCoreApplication::translate("MainWindow", "apple", nullptr));
        rech_Bra->setItemText(2, QCoreApplication::translate("MainWindow", "Samsung", nullptr));
        rech_Bra->setItemText(3, QCoreApplication::translate("MainWindow", "LG", nullptr));
        rech_Bra->setItemText(4, QCoreApplication::translate("MainWindow", "Sony", nullptr));
        rech_Bra->setItemText(5, QCoreApplication::translate("MainWindow", "Hisence", nullptr));
        rech_Bra->setItemText(6, QCoreApplication::translate("MainWindow", "TCL", nullptr));
        rech_Bra->setItemText(7, QCoreApplication::translate("MainWindow", "Beko", nullptr));
        rech_Bra->setItemText(8, QCoreApplication::translate("MainWindow", "Bosch", nullptr));
        rech_Bra->setItemText(9, QCoreApplication::translate("MainWindow", "Intel", nullptr));
        rech_Bra->setItemText(10, QCoreApplication::translate("MainWindow", "AMD", nullptr));
        rech_Bra->setItemText(11, QCoreApplication::translate("MainWindow", "NVIDIA", nullptr));
        rech_Bra->setItemText(12, QCoreApplication::translate("MainWindow", "Gigabyte", nullptr));
        rech_Bra->setItemText(13, QCoreApplication::translate("MainWindow", "ASUS ROG", nullptr));
        rech_Bra->setItemText(14, QCoreApplication::translate("MainWindow", "Xiamo smat home", nullptr));
        rech_Bra->setItemText(15, QCoreApplication::translate("MainWindow", "JBL", nullptr));
        rech_Bra->setItemText(16, QCoreApplication::translate("MainWindow", "Beats", nullptr));
        rech_Bra->setItemText(17, QString());

        rech_Bra->setPlaceholderText(QCoreApplication::translate("MainWindow", "select the brand", nullptr));
        label_29->setText(QString());
        label_30->setText(QCoreApplication::translate("MainWindow", "Search for an artical.....", nullptr));
        label_41->setText(QString());
        label_46->setText(QString());
        label_56->setText(QString());
        label_59->setText(QString());
        label_60->setText(QString());
        label_61->setText(QString());
        label_62->setText(QString());
        label_63->setText(QString());
        label_64->setText(QString());
        label_65->setText(QString());
        label_66->setText(QString());
        label_19->setText(QCoreApplication::translate("MainWindow", "category :", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Name :", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Selling Price :", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "purchase price :", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Stock :", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "SKU :", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Brand :", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Location :", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "compatibilty :", nullptr));
        cat->setItemText(0, QCoreApplication::translate("MainWindow", "Select the category", nullptr));
        cat->setItemText(1, QCoreApplication::translate("MainWindow", "Accessory", nullptr));
        cat->setItemText(2, QCoreApplication::translate("MainWindow", "computers&peripherals", nullptr));
        cat->setItemText(3, QCoreApplication::translate("MainWindow", "gaming", nullptr));
        cat->setItemText(4, QCoreApplication::translate("MainWindow", "Tv&Home Entertaiment", nullptr));
        cat->setItemText(5, QCoreApplication::translate("MainWindow", "Home Appliances ", nullptr));
        cat->setItemText(6, QCoreApplication::translate("MainWindow", "Pc Components ", nullptr));
        cat->setItemText(7, QCoreApplication::translate("MainWindow", "smart Home", nullptr));

        cat->setPlaceholderText(QCoreApplication::translate("MainWindow", "select the category", nullptr));
        brand->setItemText(0, QCoreApplication::translate("MainWindow", "Select the brand", nullptr));
        brand->setItemText(1, QCoreApplication::translate("MainWindow", "apple", nullptr));
        brand->setItemText(2, QCoreApplication::translate("MainWindow", "Samsung", nullptr));
        brand->setItemText(3, QCoreApplication::translate("MainWindow", "LG", nullptr));
        brand->setItemText(4, QCoreApplication::translate("MainWindow", "Sony", nullptr));
        brand->setItemText(5, QCoreApplication::translate("MainWindow", "Hisence", nullptr));
        brand->setItemText(6, QCoreApplication::translate("MainWindow", "TCL", nullptr));
        brand->setItemText(7, QCoreApplication::translate("MainWindow", "Beko", nullptr));
        brand->setItemText(8, QCoreApplication::translate("MainWindow", "Bosch", nullptr));
        brand->setItemText(9, QCoreApplication::translate("MainWindow", "Intel", nullptr));
        brand->setItemText(10, QCoreApplication::translate("MainWindow", "AMD", nullptr));
        brand->setItemText(11, QCoreApplication::translate("MainWindow", "NVIDIA", nullptr));
        brand->setItemText(12, QCoreApplication::translate("MainWindow", "Gigabyte", nullptr));
        brand->setItemText(13, QCoreApplication::translate("MainWindow", "ASUS ROG", nullptr));
        brand->setItemText(14, QCoreApplication::translate("MainWindow", "Xiamo smat home", nullptr));
        brand->setItemText(15, QCoreApplication::translate("MainWindow", "JBL", nullptr));
        brand->setItemText(16, QCoreApplication::translate("MainWindow", "Beats", nullptr));
        brand->setItemText(17, QString());

        brand->setPlaceholderText(QCoreApplication::translate("MainWindow", "select the brand", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "Add an Artical", nullptr));
        btn_home->setTabText(btn_home->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Home", nullptr));
        btn_stats->setText(QCoreApplication::translate("MainWindow", "Stock Alerts", nullptr));
        btn_ai_stock->setText(QCoreApplication::translate("MainWindow", "AI Stock Insights", nullptr));
        btn_home->setTabText(btn_home->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        groupBox_4->setTitle(QString());
        label_32->setText(QCoreApplication::translate("MainWindow", "  ID :", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Amount :", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Pay_Method :", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", " Date :", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Status :", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "Add Payment", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "Select the Method", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "Credit Card", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "Cash", nullptr));

        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "Select status", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "Payed ", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("MainWindow", "in progress", nullptr));
        comboBox_4->setItemText(3, QCoreApplication::translate("MainWindow", "Canceled ", nullptr));

        label_76->setText(QString());
        label_77->setText(QString());
        label_78->setText(QString());
        label_79->setText(QString());
        label_80->setText(QString());
        comboBoxsort->setItemText(0, QCoreApplication::translate("MainWindow", "Sort By", nullptr));
        comboBoxsort->setItemText(1, QCoreApplication::translate("MainWindow", "Amount", nullptr));
        comboBoxsort->setItemText(2, QCoreApplication::translate("MainWindow", "Date", nullptr));

        comboBoxSortOrder->setItemText(0, QCoreApplication::translate("MainWindow", "Order", nullptr));
        comboBoxSortOrder->setItemText(1, QCoreApplication::translate("MainWindow", "Ascending", nullptr));
        comboBoxSortOrder->setItemText(2, QCoreApplication::translate("MainWindow", "Descending", nullptr));

        lineEdit_17->setPlaceholderText(QCoreApplication::translate("MainWindow", "         ID", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Search Payment By:", nullptr));
        pushButton_27->setText(QCoreApplication::translate("MainWindow", "Export to Excel", nullptr));
        pushButton_28->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        lineEdit_18->setPlaceholderText(QCoreApplication::translate("MainWindow", "Payment_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Pay_Method", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        darkmode_button->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Home", nullptr));
        label_38->setText(QString());
        label_39->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(fa), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        btnPointage->setText(QCoreApplication::translate("MainWindow", "pointage", nullptr));
        export_pp->setText(QCoreApplication::translate("MainWindow", "Export to PDF", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tab_Employee->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "CIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tab_Employee->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Fullname", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tab_Employee->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tab_Employee->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Adress", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tab_Employee->horizontalHeaderItem(4);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "Salary", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tab_Employee->horizontalHeaderItem(5);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        pushButton_32->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_39->setText(QCoreApplication::translate("MainWindow", "Add employee", nullptr));
        groupBox_5->setTitle(QString());
        label_50->setText(QCoreApplication::translate("MainWindow", "CIN:", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "full name", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "adress", nullptr));
        label_53->setText(QCoreApplication::translate("MainWindow", "position", nullptr));
        label_54->setText(QCoreApplication::translate("MainWindow", "salary", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "status", nullptr));
        e_position->setItemText(0, QCoreApplication::translate("MainWindow", "Manager", nullptr));
        e_position->setItemText(1, QCoreApplication::translate("MainWindow", "Assistant", nullptr));
        e_position->setItemText(2, QCoreApplication::translate("MainWindow", "Technician", nullptr));
        e_position->setItemText(3, QCoreApplication::translate("MainWindow", "Sales Representative", nullptr));
        e_position->setItemText(4, QCoreApplication::translate("MainWindow", "HR Specialist", nullptr));
        e_position->setItemText(5, QCoreApplication::translate("MainWindow", "Accountant", nullptr));
        e_position->setItemText(6, QCoreApplication::translate("MainWindow", "Security", nullptr));
        e_position->setItemText(7, QCoreApplication::translate("MainWindow", "Intern", nullptr));

        e_status->setItemText(0, QCoreApplication::translate("MainWindow", "Active", nullptr));
        e_status->setItemText(1, QCoreApplication::translate("MainWindow", "Inactive", nullptr));
        e_status->setItemText(2, QCoreApplication::translate("MainWindow", "On Probation", nullptr));
        e_status->setItemText(3, QCoreApplication::translate("MainWindow", "Resigned", nullptr));
        e_status->setItemText(4, QCoreApplication::translate("MainWindow", "Terminated", nullptr));

        label_49->setText(QCoreApplication::translate("MainWindow", "Search for a employee:", nullptr));
        confirmb->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        lineEdit_19->setPlaceholderText(QCoreApplication::translate("MainWindow", " CIN,Name", nullptr));
        pushButton_31->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "Sort By:", nullptr));
        pushButton_41->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        comboBox_Emp_Sort->setItemText(0, QCoreApplication::translate("MainWindow", "Default", nullptr));
        comboBox_Emp_Sort->setItemText(1, QCoreApplication::translate("MainWindow", "Name", nullptr));
        comboBox_Emp_Sort->setItemText(2, QCoreApplication::translate("MainWindow", "CIN", nullptr));
        comboBox_Emp_Sort->setItemText(3, QCoreApplication::translate("MainWindow", "Salary", nullptr));

        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_8), QCoreApplication::translate("MainWindow", "Home", nullptr));
        pushButton_Emp_Stats->setText(QCoreApplication::translate("MainWindow", "statistics", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Functionality", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
