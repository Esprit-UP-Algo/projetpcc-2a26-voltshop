#ifndef ARDUINOMANAGER_H
#define ARDUINOMANAGER_H

#include <QObject>
#include <QSerialPort>

class ArduinoManager : public QObject
{
    Q_OBJECT
public:
    explicit ArduinoManager(QObject *parent = nullptr);

    bool connectArduino(const QString &portName);
    void sendToArduino(const QString &data);
    void sendTransactionToLcd(const QString &amount, const QString &method);

signals:
    void errorOccurred(const QString &message);
    // Émis quand on reçoit "IDE:XXXXXXXX" de l'Arduino
    void ideReceived(const QString &ide);

private slots:
    void onDataReceived();

private:
    QSerialPort *m_serial;
    QByteArray   m_buffer;
};

#endif // ARDUINOMANAGER_H
