#include "arduino.h"
#include <QSerialPortInfo>
#include <QDebug>

ArduinoManager::ArduinoManager(QObject *parent)
    : QObject(parent),
    m_serial(new QSerialPort(this))
{
}

bool ArduinoManager::connectArduino(const QString &portName)
{
    m_serial->setPortName(portName);
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    if (!m_serial->open(QIODevice::ReadWrite)) {
        emit errorOccurred("Unable to open Arduino port: " + portName);
        return false;
    }

    connect(m_serial, &QSerialPort::readyRead,
            this, &ArduinoManager::onDataReceived);

    return true;
}

void ArduinoManager::sendToArduino(const QString &data)
{
    if (m_serial && m_serial->isWritable()) {
        m_serial->write(data.toUtf8() + "\n");
    }
}

void ArduinoManager::onDataReceived()
{
    m_buffer += m_serial->readAll();

    int index;
    while ((index = m_buffer.indexOf('\n')) != -1)
    {
        QByteArray line = m_buffer.left(index);
        m_buffer.remove(0, index + 1);

        QString lineStr = QString::fromUtf8(line).trimmed();
        if (lineStr.isEmpty())
            continue;

        // On ne traite que les lignes du type "IDE:12345678"
        if (lineStr.startsWith("IDE:")) {
            QString ide = lineStr.mid(4).trimmed();
            if (!ide.isEmpty()) {
                emit ideReceived(ide);
            }
        } else {
            // Debug éventuel, ignoré par MainWindow
            qDebug() << "[Arduino] Ignored line:" << lineStr;
        }
    }
}

void ArduinoManager::sendTransactionToLcd(const QString &amount, const QString &method)
{
    if (!m_serial || !m_serial->isWritable())
        return;

    QString line = amount + "," + method;
    m_serial->write(line.toUtf8() + "\n");
}
