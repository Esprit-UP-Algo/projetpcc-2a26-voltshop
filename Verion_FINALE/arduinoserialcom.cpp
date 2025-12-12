#include "arduinoserialcom.h"
#include <QThread>

ArduinoSerialCom::ArduinoSerialCom(QObject *parent)
    : QObject(parent), m_serialPort(nullptr), m_isConnected(false)
{
    m_serialPort = new QSerialPort(this);

    bool connected1 = connect(m_serialPort, &QSerialPort::readyRead,
            this, &ArduinoSerialCom::handleReadyRead);
    bool connected2 = connect(m_serialPort, &QSerialPort::errorOccurred,
            this, &ArduinoSerialCom::handleError);
    
    qDebug() << "🔌 ArduinoSerialCom constructor:";
    qDebug() << "   readyRead signal connected:" << (connected1 ? "YES" : "NO");
    qDebug() << "   errorOccurred signal connected:" << (connected2 ? "YES" : "NO");
}

ArduinoSerialCom::~ArduinoSerialCom()
{
    disconnectFromArduino();
}

bool ArduinoSerialCom::connectToArduino(const QString &portName)
{
    if (m_isConnected) {
        disconnectFromArduino();
    }

    QString port = portName;
    if (port.isEmpty()) {
        port = detectArduinoPort();
        if (port.isEmpty()) {
            emit errorOccurred("No Arduino detected");
            return false;
        }
    }

    m_serialPort->setPortName(port);
    m_serialPort->setBaudRate(QSerialPort::Baud9600);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    qDebug() << "🔌 Attempting to connect to Arduino on port:" << port;
    qDebug() << "🔌 Opening port in ReadWrite mode...";
    
    if (m_serialPort->open(QIODevice::ReadWrite)) {
        m_isConnected = true;
        emit connectionStatusChanged(true);
        qDebug() << "✅ Connected to Arduino on port:" << port;
        qDebug() << "🔌 Serial port is now listening for data...";

        // Wait for Arduino to initialize (important!)
        QThread::msleep(2000);
        return true;
    } else {
        QString error = QString("Failed to open port %1: %2")
        .arg(port)
            .arg(m_serialPort->errorString());
        emit errorOccurred(error);
        qDebug() << "❌" << error;
        return false;
    }
}

void ArduinoSerialCom::disconnectFromArduino()
{
    if (m_serialPort && m_serialPort->isOpen()) {
        m_serialPort->close();
        m_isConnected = false;
        emit connectionStatusChanged(false);
        qDebug() << "Disconnected from Arduino";
    }
}

bool ArduinoSerialCom::sendMessage(const QString &message)
{
    if (!m_isConnected || !m_serialPort->isOpen()) {
        emit errorOccurred("Not connected to Arduino");
        return false;
    }

    // Limit message length to fit on OLED
    QString truncated = message.left(50);

    // Send message with newline
    QByteArray data = truncated.toUtf8() + "\n";
    qint64 bytesWritten = m_serialPort->write(data);

    if (bytesWritten == -1) {
        emit errorOccurred("Failed to write to serial port");
        return false;
    }

    m_serialPort->flush();
    qDebug() << "Sent to Arduino:" << truncated;
    return true;
}

bool ArduinoSerialCom::isConnected() const
{
    return m_isConnected;
}

QStringList ArduinoSerialCom::getAvailablePorts()
{
    QStringList ports;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        ports << info.portName();
    }
    return ports;
}

void ArduinoSerialCom::handleReadyRead()
{
    // Append new data to buffer
    m_serialBuffer.append(m_serialPort->readAll());
    
    qDebug() << "🔌 handleReadyRead called! Buffer size:" << m_serialBuffer.length() << "bytes";
    qDebug() << "🔌 Raw buffer hex:" << m_serialBuffer.toHex();
    
    // Process complete lines (lines ending with \n)
    int lineEndIndex;
    while ((lineEndIndex = m_serialBuffer.indexOf('\n')) != -1) {
        // Extract one complete line
        QByteArray lineData = m_serialBuffer.left(lineEndIndex);
        m_serialBuffer.remove(0, lineEndIndex + 1);  // Remove line from buffer
        
        // Convert to QString and trim
        QString message = QString::fromUtf8(lineData).trimmed();
        
        qDebug() << "🔌 Processing line from buffer, length:" << lineData.length() << "bytes";
        qDebug() << "🔌 Raw line hex:" << lineData.toHex();
        qDebug() << "🔌 Trimmed message:" << message;
        
        // Only emit if message is not empty
        if (!message.isEmpty()) {
            qDebug() << "✅ Emitting dataReceived signal with:" << message;
            emit dataReceived(message);
            qDebug() << "✅ Received from Arduino:" << message;
        } else {
            qDebug() << "⚠️ Message is empty after trimming, skipping";
        }
    }
    
    // Log any leftover data in buffer
    if (m_serialBuffer.length() > 0) {
        qDebug() << "🔌 Leftover in buffer:" << m_serialBuffer.length() << "bytes (waiting for newline)";
    }
}

void ArduinoSerialCom::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        disconnectFromArduino();
        emit errorOccurred("Arduino disconnected");
    }
}

QString ArduinoSerialCom::detectArduinoPort()
{
    const auto infos = QSerialPortInfo::availablePorts();

    qDebug() << "=== DETECTING ARDUINO PORT ===";
    qDebug() << "Total ports found:" << infos.size();

    for (const QSerialPortInfo &info : infos) {
        qDebug() << "Port:" << info.portName();
        qDebug() << "  Description:" << info.description();
        qDebug() << "  Manufacturer:" << info.manufacturer();
        qDebug() << "  Vendor ID:" << QString::number(info.vendorIdentifier(), 16);
        qDebug() << "  Product ID:" << QString::number(info.productIdentifier(), 16);

        // Arduino Uno/Mega VID:PID = 2341:0043 or 2341:0001
        // CH340 clones = 1a86:7523
        bool isArduino = false;

        // Check by VID/PID (most reliable)
        if ((info.vendorIdentifier() == 0x2341) ||  // Official Arduino
            (info.vendorIdentifier() == 0x1a86) ||  // CH340 chip
            (info.vendorIdentifier() == 0x0403)) {  // FTDI chip
            isArduino = true;
        }

        // Check by description/manufacturer
        if (info.manufacturer().contains("Arduino", Qt::CaseInsensitive) ||
            info.description().contains("Arduino", Qt::CaseInsensitive) ||
            info.description().contains("USB Serial", Qt::CaseInsensitive) ||
            info.description().contains("CH340", Qt::CaseInsensitive) ||
            info.description().contains("USB-SERIAL", Qt::CaseInsensitive)) {
            isArduino = true;
        }

        if (isArduino) {
            qDebug() << "✅ Arduino detected on port:" << info.portName();
            return info.portName();
        }
    }

    qDebug() << "⚠️ No Arduino-specific port found";

    // If no Arduino-specific port found, try first available COM port
#ifdef Q_OS_WIN
    for (const QSerialPortInfo &info : infos) {
        if (info.portName().startsWith("COM")) {
            return info.portName();
        }
    }
#endif
    return "";
}
