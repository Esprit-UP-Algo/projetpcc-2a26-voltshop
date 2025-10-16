#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    if (c.createconnect())
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"), c.lastError());
        return 1;
    }
}
