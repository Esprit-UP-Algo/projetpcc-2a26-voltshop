#include "client_dao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QApplication>

bool client_dao::create(const Client& c) {
    QString errorMessage;
    if (!validateClient(c, errorMessage)) {
        QMessageBox::warning(nullptr, "Validation Failed", errorMessage);
        return false;
    }
    QSqlQuery q;
    q.prepare(R"(
        INSERT INTO TAB_CLIENT
        (CIN, FIRST_NAME, LAST_NAME, EMAIL, PHONE_NBR, ADRESS, AGE)
        VALUES (:cin, :fn, :ln, :em, :ph, :ad, :age)
    )");
    q.bindValue(":cin", c.CIN.trimmed());
    q.bindValue(":fn", c.FIRST_NAME.trimmed());
    q.bindValue(":ln", c.LAST_NAME.trimmed());
    q.bindValue(":em", c.EMAIL.trimmed());
    q.bindValue(":ph", c.PHONE_NBR.trimmed());
    q.bindValue(":ad", c.ADRESS.trimmed());
    q.bindValue(":age", c.AGE);
    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();
    if (ok) {
        db.commit();
        QMessageBox::information(nullptr, "✅ Success", "Client has been added successfully!");
    } else {
        db.rollback();
        QMessageBox::critical(nullptr, "❌ Error", QString("Error during insertion: %1").arg(q.lastError().text()));
    }
    return ok;
}

bool client_dao::update(const Client& c) {
    QString errorMessage;
    if (!validateClient(c, errorMessage)) {
        QMessageBox::warning(nullptr, "Validation Failed", errorMessage);
        return false;
    }
    if (!exists(c.CIN)) {
        QMessageBox::warning(nullptr, "Client Not Found", QString("No client with CIN '%1' exists.").arg(c.CIN));
        return false;
    }
    QSqlQuery q;
    q.prepare(R"(
        UPDATE TAB_CLIENT
        SET FIRST_NAME = :fn,
            LAST_NAME = :ln,
            EMAIL = :em,
            PHONE_NBR = :ph,
            ADRESS = :ad,
            AGE = :age
        WHERE CIN = :cin
    )");
    q.bindValue(":fn", c.FIRST_NAME.trimmed());
    q.bindValue(":ln", c.LAST_NAME.trimmed());
    q.bindValue(":em", c.EMAIL.trimmed());
    q.bindValue(":ph", c.PHONE_NBR.trimmed());
    q.bindValue(":ad", c.ADRESS.trimmed());
    q.bindValue(":age", c.AGE);
    q.bindValue(":cin", c.CIN.trimmed());
    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();
    if (ok) {
        db.commit();
        QMessageBox::information(nullptr, "✅ Success", "Client has been updated successfully!");
    } else {
        db.rollback();
        QMessageBox::critical(nullptr, "❌ Error", QString("Error during update: %1").arg(q.lastError().text()));
    }
    return ok;
}

bool client_dao::remove(const QString& cin) {
    if (cin.trimmed().isEmpty()) {
        QMessageBox::warning(nullptr, "Empty CIN", "Please enter a CIN to delete.");
        return false;
    }
    if (!exists(cin)) {
        QMessageBox::warning(nullptr, "❌ Client Not Found", QString("No client with CIN '%1' was found in the database.").arg(cin));
        return false;
    }
    QSqlQuery q;
    q.prepare("DELETE FROM TAB_CLIENT WHERE CIN=:cin");
    q.bindValue(":cin", cin.trimmed());
    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();
    if (ok) {
        db.commit();
        QMessageBox::information(nullptr, "✅ Success", QString("Client with CIN '%1' has been deleted successfully.").arg(cin));
    } else {
        db.rollback();
        QMessageBox::critical(nullptr, "❌ Error", QString("Error during deletion: %1").arg(q.lastError().text()));
    }
    return ok;
}

bool client_dao::exists(const QString& cin) {
    QSqlQuery q;
    q.prepare("SELECT 1 FROM TAB_CLIENT WHERE CIN=:cin");
    q.bindValue(":cin", cin.trimmed());
    return q.exec() && q.next();
}

QVector<Client> client_dao::fetchAll() {
    QVector<Client> out;
    QSqlQuery q(R"(
        SELECT CIN, FIRST_NAME, LAST_NAME, EMAIL, PHONE_NBR, ADRESS, AGE
        FROM TAB_CLIENT
        ORDER BY CIN
    )");
    while (q.next()) {
        Client c;
        c.CIN = q.value(0).toString();
        c.FIRST_NAME = q.value(1).toString();
        c.LAST_NAME = q.value(2).toString();
        c.EMAIL = q.value(3).toString();
        c.PHONE_NBR = q.value(4).toString();
        c.ADRESS = q.value(5).toString();
        c.AGE = q.value(6).toInt();
        qDebug() << "Client fetched:" << c.CIN << "Age:" << c.AGE;
        out.push_back(c);
    }
    return out;
}

bool client_dao::validateClient(const Client& c, QString& errorMessage) {
    // Validations pour tous les champs, y compris Age (adapté à ton besoin)
    if (c.CIN.trimmed().isEmpty()) { errorMessage = "❌ CIN is required."; return false; }
    QRegularExpression cinRx("^[0-9]{8}$");
    if (!cinRx.match(c.CIN.trimmed()).hasMatch()) { errorMessage = "❌ CIN must contain exactly 8 digits."; return false; }
    if (c.FIRST_NAME.trimmed().isEmpty()) { errorMessage = "❌ First name is required."; return false; }
    if (c.LAST_NAME.trimmed().isEmpty()) { errorMessage = "❌ Last name is required."; return false; }
    if (c.EMAIL.trimmed().isEmpty()) { errorMessage = "❌ Email is required."; return false; }
    if (c.PHONE_NBR.trimmed().isEmpty()) { errorMessage = "❌ Phone number is required."; return false; }
    if (c.ADRESS.trimmed().isEmpty()) { errorMessage = "❌ Address is required."; return false; }
    if (c.AGE <= 0) { errorMessage = "❌ Age is required and must be greater than 0."; return false; }
    if (c.AGE < 1 || c.AGE > 120) { errorMessage = "❌ Age must be between 1 and 120 years."; return false; }
    return true;
}
static QString logPath()
{
    return QApplication::applicationDirPath() + "/client_journal.log";
}

void client_dao::journalAdd(const QString &action, const Client &c)
{
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    QString message = QString("[%1] %2 — CIN: %3 | %4 %5")
                          .arg(timestamp, action, c.CIN, c.FIRST_NAME, c.LAST_NAME);

    // --- Write to file ---
    QFile f(logPath());
    if (f.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&f);
        out << message << "\n";
        f.close();
    }
}

void client_dao::journalLoad(QListWidget *list)
{
    if (!list) return;

    list->clear();

    QFile f(logPath());
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream in(&f);
    QStringList lines;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!line.isEmpty())
            lines.append(line);
    }
    f.close();

    // Show most recent first & max 50
    int start = qMax(0, lines.size() - 50);
    for (int i = lines.size() - 1; i >= start; --i)
        list->addItem(lines[i]);
}

void client_dao::journalClear()
{
    QFile f(logPath());
    if (f.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        f.close();
    }
}
