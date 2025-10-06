#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix_logo(":/images/logo.jpg");
    ui->logo->setPixmap(pix_logo.scaled(100,100,Qt::KeepAspectRatio));

    QPixmap pix_stat(":/images/stat.png");
    ui->stat->setPixmap(pix_stat.scaled(700,700,Qt::KeepAspectRatio));

    QPixmap pix_pdf(":/images/pdf.jpg");
    ui->pdf->setPixmap(pix_pdf.scaled(700,700,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}
