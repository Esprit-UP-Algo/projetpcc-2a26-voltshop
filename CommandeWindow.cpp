#include "CommandeWindow.h"
#include "ui_CommandeWindow.h"
#include <QPushButton>

CommandeWindow::CommandeWindow(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::CommandeWindow)
{
    ui->setupUi(this);

    // bouton retour optionnel nommé "btnBackCommande"
    if (auto back = findChild<QPushButton*>("btnBackCommande")) {
        connect(back, &QPushButton::clicked, this, &CommandeWindow::backRequested);
    }
    QPixmap orderPix(":/images/ressource/stat2.png");
    if (!orderPix.isNull()) {
        ui->orderlabel->setPixmap(orderPix.scaled(ui->orderlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

CommandeWindow::~CommandeWindow()
{
    delete ui;
}
