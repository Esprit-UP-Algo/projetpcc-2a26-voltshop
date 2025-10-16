#include "connection.h"
#include <QSqlDatabase>
    #include <QSqlError>
#include <QSqlQuery>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
// DSN-less connection: avoids IM002 by specifying driver + service directly
db.setDatabaseName("Driver={Oracle in XE};Dbq=//localhost:1521/XE;Uid=fathi;Pwd=esprit18;");

if (db.open())
test=true;
else
lastError_ = db.lastError().text();

if (test)
{
    QSqlQuery q;
    // Create sequence if it doesn't exist
    q.exec("CREATE SEQUENCE TRANSACTIONS_SEQ START WITH 1 INCREMENT BY 1 NOCACHE");
}

    return  test;
}
