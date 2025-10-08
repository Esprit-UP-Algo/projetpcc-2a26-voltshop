/********************************************************************************
** Form generated from reading UI file 'StockWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKWINDOW_H
#define UI_STOCKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StockWindow
{
public:
    QTabWidget *btn_home;
    QWidget *tab;
    QWidget *widget_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *SKU;
    QLineEdit *Name;
    QLineEdit *category;
    QComboBox *brand;
    QLineEdit *price1;
    QLineEdit *Price2;
    QLineEdit *Stock;
    QLineEdit *loca;
    QLineEdit *compa;
    QPushButton *btn_add;
    QPushButton *btn_confirm;
    QPushButton *btn_cancel;
    QWidget *widget_3;
    QWidget *verticalLayoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QComboBox *rech_tri;
    QLabel *label_11;
    QComboBox *rech_cat;
    QLabel *label_12;
    QComboBox *rech_Bra;
    QLabel *label_16;
    QTableWidget *tableWidget;
    QPushButton *btn_delete;
    QLineEdit *lineEdit_11;
    QPushButton *btn_pdf;
    QLineEdit *line_Search1_2;
    QLabel *label_17;
    QWidget *tab_2;
    QPushButton *btn_delete_2;
    QLabel *label_13;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1083, 599);
        btn_home = new QTabWidget(Form);
        btn_home->setObjectName("btn_home");
        btn_home->setGeometry(QRect(0, 0, 1061, 571));
        btn_home->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 1px solid #00A3E0;\n"
"    background: #E6F2FA;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
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
        widget_2 = new QWidget(tab);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(20, 30, 291, 421));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:rgb(173,216,230);\n"
"border-radius:6px;\n"
""));
        verticalLayoutWidget = new QWidget(widget_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 30, 151, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(label_7);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(label_6);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(label_9);

        verticalLayoutWidget_2 = new QWidget(widget_2);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(160, 20, 121, 411));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        SKU = new QLineEdit(verticalLayoutWidget_2);
        SKU->setObjectName("SKU");
        SKU->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;"));

        verticalLayout_2->addWidget(SKU);

        Name = new QLineEdit(verticalLayoutWidget_2);
        Name->setObjectName("Name");
        Name->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;"));

        verticalLayout_2->addWidget(Name);

        category = new QLineEdit(verticalLayoutWidget_2);
        category->setObjectName("category");
        category->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;"));

        verticalLayout_2->addWidget(category);

        brand = new QComboBox(verticalLayoutWidget_2);
        brand->addItem(QString());
        brand->setObjectName("brand");
        brand->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;\n"
""));

        verticalLayout_2->addWidget(brand);

        price1 = new QLineEdit(verticalLayoutWidget_2);
        price1->setObjectName("price1");
        price1->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;"));

        verticalLayout_2->addWidget(price1);

        Price2 = new QLineEdit(verticalLayoutWidget_2);
        Price2->setObjectName("Price2");
        Price2->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;"));

        verticalLayout_2->addWidget(Price2);

        Stock = new QLineEdit(verticalLayoutWidget_2);
        Stock->setObjectName("Stock");
        Stock->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;"));

        verticalLayout_2->addWidget(Stock);

        loca = new QLineEdit(verticalLayoutWidget_2);
        loca->setObjectName("loca");
        loca->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;"));

        verticalLayout_2->addWidget(loca);

        compa = new QLineEdit(verticalLayoutWidget_2);
        compa->setObjectName("compa");
        compa->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;"));

        verticalLayout_2->addWidget(compa);

        btn_add = new QPushButton(tab);
        btn_add->setObjectName("btn_add");
        btn_add->setGeometry(QRect(40, 10, 151, 29));
        btn_add->setStyleSheet(QString::fromUtf8("background-color:rgb(0,0,127);\n"
"font-size:17px;\n"
"border-radius:6px;\n"
"font-weight: bold;"));
        btn_confirm = new QPushButton(tab);
        btn_confirm->setObjectName("btn_confirm");
        btn_confirm->setGeometry(QRect(40, 470, 121, 29));
        btn_confirm->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color:rgb(0,0,127);\n"
"    font-size:17px;\n"
"    border-radius:6px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(173, 216, 230); \n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(173, 216, 230); \n"
"    color: white;\n"
"    border: 2px solid rgb(173, 216, 230); \n"
"}\n"
""));
        btn_cancel = new QPushButton(tab);
        btn_cancel->setObjectName("btn_cancel");
        btn_cancel->setGeometry(QRect(180, 470, 121, 29));
        btn_cancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:rgb(0,0,127);\n"
"    font-size:17px;\n"
"    border-radius:6px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(173, 216, 230); \n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(173, 216, 230); \n"
"    color: white;\n"
"    border: 2px solid rgb(173, 216, 230); \n"
"}"));
        widget_3 = new QWidget(tab);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(320, 30, 681, 421));
        widget_3->setStyleSheet(QString::fromUtf8("background-color:rgb(173,216,230);\n"
"border-radius:6px;\n"
"background-repeat: no-repeat;\n"
""));
        verticalLayoutWidget_3 = new QWidget(widget_3);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(20, 70, 621, 28));
        horizontalLayout = new QHBoxLayout(verticalLayoutWidget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(label_10);

        rech_tri = new QComboBox(verticalLayoutWidget_3);
        rech_tri->addItem(QString());
        rech_tri->setObjectName("rech_tri");
        rech_tri->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;\n"
""));

        horizontalLayout->addWidget(rech_tri);

        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName("label_11");
        label_11->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(label_11);

        rech_cat = new QComboBox(verticalLayoutWidget_3);
        rech_cat->addItem(QString());
        rech_cat->setObjectName("rech_cat");
        rech_cat->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;\n"
""));

        horizontalLayout->addWidget(rech_cat);

        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName("label_12");
        label_12->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"color:#000000;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(label_12);

        rech_Bra = new QComboBox(verticalLayoutWidget_3);
        rech_Bra->addItem(QString());
        rech_Bra->setObjectName("rech_Bra");
        rech_Bra->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;\n"
""));

        horizontalLayout->addWidget(rech_Bra);

        label_16 = new QLabel(widget_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(120, 30, 21, 21));
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/icons/cherch.png")));
        label_16->setScaledContents(true);
        tableWidget = new QTableWidget(widget_3);
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
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 120, 631, 181));
        tableWidget->setStyleSheet(QString::fromUtf8("\n"
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
        btn_delete = new QPushButton(widget_3);
        btn_delete->setObjectName("btn_delete");
        btn_delete->setGeometry(QRect(430, 360, 111, 31));
        btn_delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:rgb(0,0,127);\n"
"    font-size:17px;\n"
"    border-radius:6px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(173, 216, 230); \n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(173, 216, 230); \n"
"    color: white;\n"
"    border: 2px solid rgb(173, 216, 230); \n"
"}"));
        lineEdit_11 = new QLineEdit(widget_3);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(550, 360, 121, 31));
        lineEdit_11->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;\n"
"border-radius:6px;\n"
"background-color: rgb(255, 255, 255);"));
        btn_pdf = new QPushButton(widget_3);
        btn_pdf->setObjectName("btn_pdf");
        btn_pdf->setGeometry(QRect(290, 360, 121, 31));
        btn_pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:rgb(0,0,127);\n"
"    font-size:17px;\n"
"    border-radius:6px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(173, 216, 230); \n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(173, 216, 230); \n"
"    color: white;\n"
"    border: 2px solid rgb(173, 216, 230); \n"
"}"));
        line_Search1_2 = new QLineEdit(widget_3);
        line_Search1_2->setObjectName("line_Search1_2");
        line_Search1_2->setGeometry(QRect(20, 20, 231, 41));
        line_Search1_2->setStyleSheet(QString::fromUtf8("border:2px solid #000000;\n"
"color:#000000;\n"
"background-color:#ffffff;\n"
""));
        label_17 = new QLabel(widget_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(30, 30, 21, 21));
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/icons/cherch.png")));
        label_17->setScaledContents(true);
        btn_home->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        btn_delete_2 = new QPushButton(tab_2);
        btn_delete_2->setObjectName("btn_delete_2");
        btn_delete_2->setGeometry(QRect(770, 470, 191, 31));
        btn_delete_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:rgb(0,0,127);\n"
"    font-size:17px;\n"
"    border-radius:6px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(173, 216, 230); \n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(173, 216, 230); \n"
"    color: white;\n"
"    border: 2px solid rgb(173, 216, 230); \n"
"}"));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(70, 20, 861, 431));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/images/stat.jpg")));
        label_13->setScaledContents(true);
        btn_home->addTab(tab_2, QString());

        retranslateUi(Form);

        btn_home->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("StockWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("StockWindow", "SKU :", nullptr));
        label_2->setText(QCoreApplication::translate("StockWindow", "Name :", nullptr));
        label_3->setText(QCoreApplication::translate("StockWindow", "category :", nullptr));
        label_4->setText(QCoreApplication::translate("StockWindow", "Brand :", nullptr));
        label_5->setText(QCoreApplication::translate("StockWindow", "purchase price :", nullptr));
        label_7->setText(QCoreApplication::translate("StockWindow", "Selling Price :", nullptr));
        label_6->setText(QCoreApplication::translate("StockWindow", "Stock :", nullptr));
        label_8->setText(QCoreApplication::translate("StockWindow", "Location :", nullptr));
        label_9->setText(QCoreApplication::translate("StockWindow", "compatibilty :", nullptr));
        brand->setItemText(0, QCoreApplication::translate("StockWindow", "Select", nullptr));

        btn_add->setText(QCoreApplication::translate("StockWindow", "Add an Artical", nullptr));
        btn_confirm->setText(QCoreApplication::translate("StockWindow", "Confirm", nullptr));
        btn_cancel->setText(QCoreApplication::translate("StockWindow", "Cancel", nullptr));
        label_10->setText(QCoreApplication::translate("StockWindow", "category ", nullptr));
        rech_tri->setItemText(0, QCoreApplication::translate("StockWindow", "Select", nullptr));

        label_11->setText(QCoreApplication::translate("StockWindow", "Brand ", nullptr));
        rech_cat->setItemText(0, QCoreApplication::translate("StockWindow", "Select", nullptr));

        label_12->setText(QCoreApplication::translate("StockWindow", "Sort By", nullptr));
        rech_Bra->setItemText(0, QCoreApplication::translate("StockWindow", "Select", nullptr));

        label_16->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("StockWindow", "SKU", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("StockWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("StockWindow", "Category", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("StockWindow", "Brand", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("StockWindow", "Purchase Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("StockWindow", "Selling Price", nullptr));
        btn_delete->setText(QCoreApplication::translate("StockWindow", "Delete", nullptr));
        btn_pdf->setText(QCoreApplication::translate("StockWindow", "Export PDF", nullptr));
        line_Search1_2->setPlaceholderText(QCoreApplication::translate("StockWindow", "         Search for an Artical...", nullptr));
        label_17->setText(QString());
        btn_home->setTabText(btn_home->indexOf(tab), QCoreApplication::translate("StockWindow", "Home", nullptr));
        btn_delete_2->setText(QCoreApplication::translate("StockWindow", "Stock Alerts", nullptr));
        label_13->setText(QString());
        btn_home->setTabText(btn_home->indexOf(tab_2), QCoreApplication::translate("StockWindow", "Fonctionality", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StockWindow: public Ui_StockWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWINDOW_H
