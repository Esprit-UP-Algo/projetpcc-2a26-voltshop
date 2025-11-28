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
<<<<<<< HEAD
    Transaction(int id, QString amount, QString pay_method, QDate date_trans, QString status, int idcom, int refId = 0);
=======
    Transaction(int id, QString amount, QString pay_method, QDate date_trans, QString status, int refId = 0);
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94

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
<<<<<<< HEAD
    int idcom = 0;
=======
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94
    int refId = 0; // value to insert into the TAB_TRANS."ID" column
};

#endif // TRANSACTION_H
