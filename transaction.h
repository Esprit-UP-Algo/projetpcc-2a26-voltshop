/* Header for the Transaction class (instance-based API).
   Matches the member functions implemented in transaction.cpp.
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

class Transaction
{
public:
    Transaction();
    // refId maps to the table column `ID` (an extra NOT NULL field in TAB_TRANS)
    Transaction(int id, QString amount, QString pay_method, QDate date_trans, QString status, int refId = 0);

    bool ajouter();
    bool supprimer(int id);
    bool modifier();
    QSqlQueryModel* afficher();

private:
    int id = 0;
    QString amount;          // as in VARCHAR2(100 BYTE)
    QString pay_method;
    QDate date_trans;
    QString status;
    int refId = 0; // value to insert into the TAB_TRANS."ID" column
};

#endif // TRANSACTION_H
