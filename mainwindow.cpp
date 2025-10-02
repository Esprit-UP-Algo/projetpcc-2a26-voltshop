#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , clientWindow(nullptr)
{
    ui->setupUi(this);
    
    // Load VoltShop logo in main window
    QPixmap pix_logo(":/images/ressource/logo.jpeg");
    if (!pix_logo.isNull()) {
        ui->logo_main->setPixmap(pix_logo.scaled(100,80,Qt::KeepAspectRatio));
    }
    
    // Connect the person icon button (pushButton_2) to open client module
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::openClientModule);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (clientWindow) {
        delete clientWindow;
    }
}

void MainWindow::openClientModule()
{
    if (!clientWindow) {
        clientWindow = new ClientWindow();
    }
    clientWindow->show();
    clientWindow->raise();
    clientWindow->activateWindow();
}
