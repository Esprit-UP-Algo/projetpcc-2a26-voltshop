#include "EmployeeWindow.h"
#include "ui_EmployeeWindow.h"
#include <QPushButton>

EmployeeWindow::EmployeeWindow(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::EmployeeWindow)
{
    ui->setupUi(this);

    // Si tu ajoutes un bouton Retour dans employeewindow.ui (objectName: btnBackEmp)
    if (auto back = findChild<QPushButton*>("btnBackEmp")) {
        connect(back, &QPushButton::clicked, this, &EmployeeWindow::backRequested);
    }
}

EmployeeWindow::~EmployeeWindow()
{
    delete ui;
}
