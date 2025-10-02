#include "clientwindow.h"
#include "ui_clientwindow.h"
#include <QPixmap>

ClientWindow::ClientWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    
    // You can add the statistics chart later
    // QPixmap pix_stat("ressource/customer_stats.png");
    // if (!pix_stat.isNull()) {
    //     ui->stat->setPixmap(pix_stat.scaled(700,700,Qt::KeepAspectRatio));
    // }
}

ClientWindow::~ClientWindow()
{
    delete ui;
}
