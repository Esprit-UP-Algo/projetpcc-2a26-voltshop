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
<<<<<<< HEAD
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
=======
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
>>>>>>> dd6e92d7cf8c97371951fce0b19f93117df0ab54
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
<<<<<<< HEAD
#include <QtWidgets/QVBoxLayout>
=======
#include <QtWidgets/QTableWidget>
>>>>>>> dd6e92d7cf8c97371951fce0b19f93117df0ab54
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
<<<<<<< HEAD
    QWidget *widget;
    QTabWidget *tabWidget;
    QWidget *tab_9;
    QWidget *widget_3;
    QWidget *widget_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QWidget *widget_4;
    QWidget *widget_7;
    QWidget *widget_5;
    QWidget *widget_6;
    QPushButton *pushButton_3;
    QWidget *widget_10;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_9;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QWidget *widget_8;
    QWidget *widget_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *tab_10;
    QWidget *widget_11;
    QLabel *label;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_7;
    QLabel *label_2;
    QComboBox *comboBox_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QMenuBar *menubar;
=======
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
    QTableWidget *tableWidget;
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
    QFrame *frame;
    QCalendarWidget *calendarWidget;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menuVoltShop;
>>>>>>> dd6e92d7cf8c97371951fce0b19f93117df0ab54
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
<<<<<<< HEAD
        MainWindow->resize(1116, 766);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 201, 701));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
""));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(200, 0, 901, 701));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::Tab {\n"
"background: #00007F;\n"
"color: white;\n"
"padding:8px;\n"
"margin-right:1px;\n"
"border-radius:7px;\n"
"font-size:17px;\n"
"}\n"
"QTabWidget:: pane{\n"
"background: white;\n"
"}"));
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        widget_3 = new QWidget(tab_9);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, -20, 921, 691));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 242, 250);\n"
""));
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(40, 150, 311, 461));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        verticalLayoutWidget = new QWidget(widget_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 40, 141, 411));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font-size:17px;\n"
"color:black;"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font-size:17px;\n"
"color:black;"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font-size:17px;\n"
"color:black;"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font-size:17px;\n"
"color:black;"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("font-size:17px;\n"
"color:black;"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("font-size:17px;\n"
"color:black;"));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("font-size:17px;\n"
"color:black;"));

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("font-size:17px;\n"
"color:black;"));

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName("label_11");
        label_11->setStyleSheet(QString::fromUtf8("font-size:17px;\n"
"color:black;"));

        verticalLayout->addWidget(label_11);

        verticalLayoutWidget_2 = new QWidget(widget_2);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(160, 30, 131, 441));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));

        verticalLayout_4->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));

        verticalLayout_4->addWidget(lineEdit_2);

        comboBox = new QComboBox(verticalLayoutWidget_2);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(173, 216, 230, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(0, 0, 0, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        comboBox->setPalette(palette);
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));

        verticalLayout_4->addWidget(comboBox);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));

        verticalLayout_4->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));

        verticalLayout_4->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));

        verticalLayout_4->addWidget(lineEdit_5);

        lineEdit_6 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));

        verticalLayout_4->addWidget(lineEdit_6);

        lineEdit_7 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));

        verticalLayout_4->addWidget(lineEdit_7);

        lineEdit_8 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));

        verticalLayout_4->addWidget(lineEdit_8);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(640, 150, 221, 141));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(540, 40, 151, 91));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(640, 310, 221, 141));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(640, 470, 221, 141));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        pushButton_3 = new QPushButton(widget_3);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(60, 130, 191, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 127);\n"
"font-size:17px;\n"
""));
        widget_10 = new QWidget(widget_3);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(360, 150, 271, 461));
        widget_10->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        pushButton_4 = new QPushButton(widget_10);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 368, 171, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0,127);\n"
"font-size:17px;"));
        lineEdit_9 = new QLineEdit(widget_10);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(20, 20, 211, 31));
        lineEdit_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));
        label_12 = new QLabel(widget_10);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 70, 119, 40));
        label_12->setStyleSheet(QString::fromUtf8("font-size:20px;\n"
"color:black;"));
        label_13 = new QLabel(widget_10);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 160, 119, 39));
        label_13->setStyleSheet(QString::fromUtf8("font-size:20px;\n"
"color:black;"));
        label_14 = new QLabel(widget_10);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 250, 119, 39));
        label_14->setStyleSheet(QString::fromUtf8("font-size:20px;\n"
"color:black;"));
        comboBox_2 = new QComboBox(widget_10);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(20, 120, 211, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        comboBox_2->setPalette(palette1);
        comboBox_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:3px;"));
        comboBox_3 = new QComboBox(widget_10);
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(20, 200, 211, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        comboBox_3->setPalette(palette2);
        comboBox_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:3px;"));
        comboBox_4 = new QComboBox(widget_10);
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(20, 300, 211, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        comboBox_4->setPalette(palette3);
        comboBox_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:3px;"));
        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(710, 40, 151, 91));
        widget_8->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        widget_9 = new QWidget(widget_3);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(370, 40, 151, 91));
        widget_9->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230);"));
        pushButton_5 = new QPushButton(widget_3);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(60, 630, 121, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0,127);\n"
"font-size:17px;"));
        pushButton_6 = new QPushButton(widget_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(220, 630, 121, 31));
        pushButton_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0,127);\n"
"font-size:17px;\n"
""));
        widget_2->raise();
        widget_4->raise();
        widget_5->raise();
        widget_6->raise();
        pushButton_3->raise();
        widget_10->raise();
        widget_7->raise();
        widget_8->raise();
        widget_9->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        tabWidget->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        widget_11 = new QWidget(tab_10);
        widget_11->setObjectName("widget_11");
        widget_11->setGeometry(QRect(0, -10, 921, 691));
        widget_11->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 242, 250);\n"
""));
        label = new QLabel(widget_11);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 90, 191, 81));
        label->setStyleSheet(QString::fromUtf8("font-size:21px;\n"
"color:black;"));
        lineEdit_10 = new QLineEdit(widget_11);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(260, 120, 171, 31));
        lineEdit_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));
        pushButton_7 = new QPushButton(widget_11);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(470, 120, 121, 31));
        pushButton_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0,127);\n"
"font-size:17px;"));
        label_2 = new QLabel(widget_11);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(620, 90, 191, 81));
        label_2->setStyleSheet(QString::fromUtf8("font-size:21px;\n"
"color:black;"));
        comboBox_5 = new QComboBox(widget_11);
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(710, 120, 129, 24));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush3(QColor(230, 242, 250, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        comboBox_5->setPalette(palette4);
        comboBox_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 1px solid;\n"
"border-color:#000000;\n"
"border-radius:6px;"));
        pushButton_8 = new QPushButton(widget_11);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(730, 610, 151, 31));
        pushButton_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0,127);\n"
"font-size:17px;"));
        pushButton_9 = new QPushButton(widget_11);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(570, 610, 151, 31));
        pushButton_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0,127);\n"
"font-size:17px;"));
        pushButton_10 = new QPushButton(widget_11);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(410, 610, 151, 31));
        pushButton_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0,127);\n"
"font-size:17px;"));
        tabWidget->addTab(tab_10, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1116, 25));
=======
        MainWindow->resize(1302, 648);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
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
        label->setGeometry(QRect(10, 70, 91, 20));
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
"    image: url(C:/Users/lastg/Desktop/icons8-calendar-50.png); /* replace with your calendar icon if available */\n"
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
"    image: url(C:/Users/lastg/Desktop/arrow-down.png); /* replace with your arrow icon if you have one */\n"
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
"    image: url(C:/Users/lastg/Desktop/arrow-down.png); /* replace with your arrow icon if you have one */\n"
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
"    image: url(C:/Users/lastg/Desktop/arrow-down.png); /* replace with your arrow icon if you have one */\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
""));
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
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(400, 170, 741, 241));
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
        frame = new QFrame(fa);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 951, 501));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        calendarWidget = new QCalendarWidget(frame);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(10, 10, 341, 301));
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
"    qproperty-icon: url(C:/Users/lastg/Desktop/log-out.png);\n"
"    qproperty-iconSize: 25px 25px;\n"
"}\n"
"QPushButton:hover { background-color: Red; }\n"
"QPushButton:pressed { background-color: #002050; }"));
        pushButton_9->setIconSize(QSize(25, 25));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 120, 91, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #003271;   /* base color */\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 8px 14px;\n"
"    font-weight: bold;\n"
"    qproperty-icon: url(C:/Users/lastg/Desktop/credit-card.png);\n"
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
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1302, 25));
        menuVoltShop = new QMenu(menubar);
        menuVoltShop->setObjectName("menuVoltShop");
>>>>>>> dd6e92d7cf8c97371951fce0b19f93117df0ab54
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

<<<<<<< HEAD
=======
        menubar->addAction(menuVoltShop->menuAction());

>>>>>>> dd6e92d7cf8c97371951fce0b19f93117df0ab54
        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
<<<<<<< HEAD
        label_3->setText(QCoreApplication::translate("MainWindow", "SKU :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Name :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Category :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "brand :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "purchase price :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Selling Price :", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Stock :", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Location :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "compatibilty :", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Select", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Add Item", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("MainWindow", "              Search an item...", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Brand", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Sort by", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Battery", nullptr));

        comboBox_2->setCurrentText(QCoreApplication::translate("MainWindow", "Battery", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "Iphone", nullptr));

        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "Name", nullptr));

        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Home", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Search for an item", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Sort by", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "Name", nullptr));

        comboBox_5->setCurrentText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Export to PDF", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Export to Excel", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Limit Alert", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Functionality", nullptr));
=======
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

        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Payment_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Pay_Method", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Exprot to PDF", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", " ID_Payment", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Search Payment By:", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Export to Excel", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Home", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(fa), QCoreApplication::translate("MainWindow", "Fonctionality", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        pushButton_9->setText(QString());
        pushButton_2->setText(QString());
        menuVoltShop->setTitle(QCoreApplication::translate("MainWindow", "VoltShop", nullptr));
>>>>>>> dd6e92d7cf8c97371951fce0b19f93117df0ab54
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
