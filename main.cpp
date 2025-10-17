#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test = c.createconnect(); // Try to connect


    if (!test) {
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              QObject::tr("Failed to connect to the database."));
        return -1; // Stop program if connection fails
    }

    MainWindow w;
    w.show();

    return a.exec();
}
