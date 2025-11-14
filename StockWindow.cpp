#include "StockWindow.h"
#include "ui_StockWindow.h"
#include <QPushButton>
#include <QDebug>

StockWindow::StockWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StockWindow)
{
    ui->setupUi(this);

    // ✅ Si tu mets un bouton "Retour" nommé "btnBack" dans stockwindow.ui
    if (auto back = findChild<QPushButton*>("btnBack")) {
        connect(back, &QPushButton::clicked, this, &StockWindow::backRequested);
    }
    
    // Load and display the statstock image
    QPixmap stockPix(":/images/ressource/statstock.png");
    if (!stockPix.isNull()) {
        qDebug() << "Successfully loaded statstock.png";
        ui->stocklabel->setPixmap(stockPix);
        ui->stocklabel->setScaledContents(true);
    } else {
        qDebug() << "Failed to load statstock.png";
    }
}

StockWindow::~StockWindow()
{
    delete ui;
}
