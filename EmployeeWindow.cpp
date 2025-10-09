#include "employeewindow.h"
#include "ui_employeewindow.h"
#include <QPixmap>
#include <QPushButton>

EmployeeWindow::EmployeeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EmployeeWindow)
{
    ui->setupUi(this);
    
    // Load images using resource system
    QPixmap pix_logo(":/images/ressource/logo.jpeg");
    if (!pix_logo.isNull()) {
        ui->logo->setPixmap(pix_logo.scaled(100,100,Qt::KeepAspectRatio));
        ui->logo2->setPixmap(pix_logo.scaled(100,100,Qt::KeepAspectRatio));
    }
    
    // Connect quit button to emit back signal
    connect(ui->quit, &QPushButton::clicked, this, &EmployeeWindow::backRequested);
    
    // Note: You'll need to add stat.png and PDF.png to your resources
    // QPixmap pix_stat(":/images/ressource/stat.png");
    // ui->stat->setPixmap(pix_stat.scaled(700,700,Qt::KeepAspectRatio));
    // QPixmap pix_PDF(":/images/ressource/PDF.png");
    // ui->PDF->setPixmap(pix_PDF.scaled(90,90,Qt::KeepAspectRatio));
}

EmployeeWindow::~EmployeeWindow()
{
    delete ui;
}

void EmployeeWindow::on_quit_clicked()
{
    // Signal will be emitted by the connection above
}