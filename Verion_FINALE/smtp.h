#ifndef SMTP_H
#define SMTP_H

#include <QtNetwork/QSslSocket>
#include <QObject>

class Smtp : public QObject
{
    Q_OBJECT

public:
    Smtp(const QString &user, const QString &password,
         const QString &host, int port = 465);

    void sendMail(const QString &from,
                  const QString &to,
                  const QString &subject,
                  const QString &body);

private slots:
    void readyRead();
    void onConnected();
    void onError(QAbstractSocket::SocketError error);
    void onSslErrors(const QList<QSslError> &errors);

private:
    QSslSocket *socket;
    QString user;
    QString password;
    QString message;
    QString from;
    QString to;
    QString subject;
    QString body;
    int step;
};

#endif // SMTP_H
