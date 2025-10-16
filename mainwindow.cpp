#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    const QString amountText = ui->lineEdit_2->text().trimmed();
    const QString method = ui->comboBox_2->currentText();
    const QDate date = ui->dateEdit->date();
    const QString status = ui->comboBox_3->currentText();

    bool amountOk = false;
    const double amount = amountText.toDouble(&amountOk);
    if (!amountOk || method.startsWith("Select") || status.startsWith("Select"))
    {
        QMessageBox::warning(this, tr("Validation"), tr("Please fill Amount, Method, Date and Status."));
        return;
    }

    QSqlQuery q;
    q.prepare("INSERT INTO TRANSACTIONS (TRANSACTION_ID, AMOUNT, PAY_METHOD, T_DATE, STATUS)\n"
             "VALUES (TRANSACTIONS_SEQ.NEXTVAL, :amount, :method, :date, :status)");
    q.bindValue(":amount", amount);
    q.bindValue(":method", method);
    q.bindValue(":date", date);
    q.bindValue(":status", status);
    if (!q.exec())
    {
        QMessageBox::critical(this, tr("DB Error"), q.lastError().text());
        return;
    }

    // Append to tableWidget
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem("Auto")); // Auto-generated ID
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(amount)));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(method));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(date.toString("yyyy-MM-dd")));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(status));

    QMessageBox::information(this, tr("Success"), tr("Payment added."));
    ui->lineEdit_2->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
}
