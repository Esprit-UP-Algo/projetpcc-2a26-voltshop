#include "smtp.h"
#include <QDebug>

Smtp::Smtp(const QString &user, const QString &password,
           const QString &host, int port)
    : user(user), password(password), step(0)
{
    socket = new QSslSocket(this);

    connect(socket, &QSslSocket::connected, this, &Smtp::onConnected);
    connect(socket, &QSslSocket::readyRead, this, &Smtp::readyRead);
    connect(socket, &QSslSocket::errorOccurred, this, &Smtp::onError);
    connect(socket, &QSslSocket::sslErrors, this, &Smtp::onSslErrors);

    qDebug() << "Connecting to SMTP server...";
    socket->connectToHostEncrypted(host, port);
}

void Smtp::sendMail(const QString &from, const QString &to,
                    const QString &subject, const QString &body)
{
    this->from = from;
    this->to = to;
    this->subject = subject;
    this->body = body;

    // Construire le message complet
    message = "From: " + from + "\r\n";
    message += "To: " + to + "\r\n";
    message += "Subject: " + subject + "\r\n";
    message += "MIME-Version: 1.0\r\n";
    message += "Content-Type: text/plain; charset=utf-8\r\n\r\n";
    message += body + "\r\n";

    // L'envoi commence dans onConnected()
}

void Smtp::onConnected()
{
    qDebug() << "Connected to SMTP server";
}

void Smtp::onError(QAbstractSocket::SocketError error)
{
    qDebug() << "SMTP Error:" << socket->errorString();
}

void Smtp::onSslErrors(const QList<QSslError> &errors)
{
    qDebug() << "SSL Errors:";
    for (const QSslError &error : errors) {
        qDebug() << " -" << error.errorString();
    }
    // Pour le développement, vous pouvez ignorer certaines erreurs SSL
    // socket->ignoreSslErrors();
}

void Smtp::readyRead()
{
    QString response = socket->readAll();
    qDebug() << "SMTP:" << response.trimmed();

    if (response.startsWith("220")) {
        // Serveur prêt
        socket->write("EHLO localhost\r\n");
    }
    else if (response.startsWith("250") && step == 0) {
        // Réponse EHLO
        socket->write("AUTH LOGIN\r\n");
        step = 1;
    }
    else if (response.startsWith("334") && step == 1) {
        // Demande username
        socket->write(user.toUtf8().toBase64() + "\r\n");
        step = 2;
    }
    else if (response.startsWith("334") && step == 2) {
        // Demande password
        socket->write(password.toUtf8().toBase64() + "\r\n");
        step = 3;
    }
    else if (response.startsWith("235") && step == 3) {
        // Authentification réussie
        socket->write("MAIL FROM: <" + from.toUtf8() + ">\r\n");
        step = 4;
    }
    else if (response.startsWith("250") && step == 4) {
        // MAIL FROM accepté
        socket->write("RCPT TO: <" + to.toUtf8() + ">\r\n");
        step = 5;
    }
    else if (response.startsWith("250") && step == 5) {
        // RCPT TO accepté
        socket->write("DATA\r\n");
        step = 6;
    }
    else if (response.startsWith("354") && step == 6) {
        // Prêt à recevoir data
        socket->write(message.toUtf8() + "\r\n.\r\n");
        step = 7;
    }
    else if (response.startsWith("250") && step == 7) {
        // Message accepté
        qDebug() << "Email sent successfully!";
        socket->write("QUIT\r\n");
        step = 8;
    }
    else if (response.startsWith("221") || step == 8) {
        // Déconnexion
        socket->disconnectFromHost();
        deleteLater(); // Nettoyer la mémoire
    }
    else if (response.startsWith("5") || response.startsWith("4")) {
        // Erreur SMTP
        qDebug() << "SMTP Error:" << response;
        socket->write("QUIT\r\n");
    }
}
