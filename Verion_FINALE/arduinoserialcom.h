#ifndef ARDUINOSERIALCOM_H
#define ARDUINOSERIALCOM_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class ArduinoSerialCom : public QObject
{
    Q_OBJECT

public:
    explicit ArduinoSerialCom(QObject *parent = nullptr);
    ~ArduinoSerialCom();

    // Connect to Arduino
    bool connectToArduino(const QString &portName = "");

    // Disconnect from Arduino
    void disconnectFromArduino();

    // Send message to Arduino OLED
    bool sendMessage(const QString &message);

    // Check if connected
    bool isConnected() const;

    // Get available ports
    static QStringList getAvailablePorts();

signals:
    void connectionStatusChanged(bool connected);
    void errorOccurred(const QString &error);
    void dataReceived(const QString &data);

private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort;
    bool m_isConnected;
    QByteArray m_serialBuffer;  // Buffer for incomplete serial messages

    // Try to auto-detect Arduino port
    QString detectArduinoPort();
};

#endif // ARDUINOSERIALCOM_H
