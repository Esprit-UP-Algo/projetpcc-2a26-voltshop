#include "gcommandewindow.h"
#include "ui_gcommandewindow.h"
#include <QPushButton>

GcommandeWindow::GcommandeWindow(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::GcommandeWindow)
{
    ui->setupUi(this);

    // Si tu as un bouton retour dans gcommandewindow.ui, nomme-le "btnBackGcom"
    if (auto back = findChild<QPushButton*>("btnBackGcom")) {
        connect(back, &QPushButton::clicked, this, &GcommandeWindow::backRequested);
    }
}

GcommandeWindow::~GcommandeWindow()
{
    delete ui;
}
