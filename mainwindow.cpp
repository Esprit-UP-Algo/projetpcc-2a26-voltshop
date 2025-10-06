#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isEditMode(false)
    , currentEditRow(-1)
{
    ui->setupUi(this);
    QPixmap pix_logo("C:/Users/msi/Documents/gestionclient/assests/logo.jpeg");
    ui->logo->setPixmap(pix_logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->logo2->setPixmap(pix_logo.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap pix_stat("C:/Users/msi/Documents/gestionclient/assests/stat.png");
    ui->stat->setPixmap(pix_stat.scaled(700,700,Qt::KeepAspectRatio));
    QPixmap pix_PDF("C:/Users/msi/Documents/gestionclient/assests/PDF.png");
    ui->PDF->setPixmap(pix_PDF.scaled(90,90,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_quit_clicked()
{
    close();
}

// Helper function to populate form fields with table data
void MainWindow::populateFormFromTableRow(int row)
{
    // Get data from the table widget for the specified row
    QTableWidgetItem* cinItem = ui->tableWidget->item(row, 0);      // CIN column
    QTableWidgetItem* firstNameItem = ui->tableWidget->item(row, 1); // First Name column
    QTableWidgetItem* lastNameItem = ui->tableWidget->item(row, 2);  // Last Name column  
    QTableWidgetItem* emailItem = ui->tableWidget->item(row, 3);     // Email column
    QTableWidgetItem* addressItem = ui->tableWidget->item(row, 4);   // Address column
    QTableWidgetItem* phoneItem = ui->tableWidget->item(row, 5);     // Phone column
    
    // Populate the form fields with the table data (handle null items safely)
    ui->lineEdit->setText(cinItem ? cinItem->text() : "");          // CIN field
    ui->lineEdit_6->setText(firstNameItem ? firstNameItem->text() : ""); // First Name field
    ui->lineEdit_2->setText(lastNameItem ? lastNameItem->text() : "");   // Last Name field
    ui->lineEdit_3->setText(emailItem ? emailItem->text() : "");         // Email field
    ui->lineEdit_5->setText(addressItem ? addressItem->text() : "");     // Address field
    ui->lineEdit_4->setText(phoneItem ? phoneItem->text() : "");         // Phone number field
    
    // Set edit mode
    isEditMode = true;
    currentEditRow = row;
    
    // Change button text to indicate edit mode
    ui->pushButton->setText("Update Client");
    
    // Change the styling to indicate edit mode
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "font: 900 9pt \"Swis721 Blk BT\";"
        "background-color: #FF6B35;" // Orange color for edit mode
        "color: white;"
        "border-radius: 6px;"
        "padding: 6px 12px;"
        "}"
        "QPushButton:hover { background-color: #E55A2B; }"
        "QPushButton:pressed { background-color: #CC4125; }"
    );
}

// Edit button handlers for each row
void MainWindow::on_pushButton_10_clicked()
{
    populateFormFromTableRow(0); // First row (index 0)
}

void MainWindow::on_pushButton_14_clicked()
{
    populateFormFromTableRow(1); // Second row (index 1)
}

void MainWindow::on_pushButton_11_clicked()
{
    populateFormFromTableRow(2); // Third row (index 2)
}

void MainWindow::on_pushButton_13_clicked()
{
    populateFormFromTableRow(3); // Fourth row (index 3)
}

void MainWindow::on_pushButton_12_clicked()
{
    populateFormFromTableRow(4); // Fifth row (index 4)
}

void MainWindow::on_pushButton_15_clicked()
{
    populateFormFromTableRow(5); // Sixth row (index 5)
}

// Helper function to reset form back to add mode
void MainWindow::resetFormToAddMode()
{
    // Clear all form fields
    ui->lineEdit->clear();      // CIN field
    ui->lineEdit_6->clear();    // First Name field
    ui->lineEdit_2->clear();    // Last Name field
    ui->lineEdit_3->clear();    // Email field
    ui->lineEdit_4->clear();    // Phone field
    ui->lineEdit_5->clear();    // Address field
    
    // Reset edit mode flags
    isEditMode = false;
    currentEditRow = -1;
    
    // Reset button text and styling back to normal
    ui->pushButton->setText("Add Client");
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "font: 900 9pt \"Swis721 Blk BT\";"
        "background-color: #003271;"
        "color: white;"
        "border-radius: 6px;"
        "padding: 6px 12px;"
        "}"
        "QPushButton:hover { background-color: #004599; }"
        "QPushButton:pressed { background-color: #002050; }"
    );
}

// Cancel button handler
void MainWindow::on_pushButton_3_clicked()
{
    resetFormToAddMode(); // Reset form when cancel is pressed
}

