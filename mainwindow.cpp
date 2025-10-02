#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix_logo("C:/Users/msi/Documents/gestionclient/assests/logo.jpeg");
    ui->logo->setPixmap(pix_logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->logo2->setPixmap(pix_logo.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap pix_stat("C:/Users/msi/Documents/gestionclient/assests/stat.png");
    ui->stat->setPixmap(pix_stat.scaled(700,700,Qt::KeepAspectRatio));
    QPixmap pix_PDF("C:/Users/msi/Documents/gestionclient/assests/PDF.png");
    ui->PDF->setPixmap(pix_PDF.scaled(90,90,Qt::KeepAspectRatio));
    QPixmap pix_EXCEL("C:/Users/msi/Documents/gestionclient/assests/EXCEL.png");
    ui->EXCEL->setPixmap(pix_EXCEL.scaled(90,90,Qt::KeepAspectRatio));
    QPixmap pix_creditcard("C:/Users/msi/Documents/gestionclient/assests/credit-card.png");
    ui->creditcard->setPixmap(pix_creditcard.scaled(90,90,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}
