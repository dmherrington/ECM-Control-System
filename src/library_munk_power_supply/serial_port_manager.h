#ifndef SERIAL_PORT_MANAGER_H
#define SERIAL_PORT_MANAGER_H

#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QThread>
#include <QTextStream>
#include <QTimer>
#include <QByteArray>
#include <QObject>

#include <iostream>

#include "common/common.h"

#include "serial_port_helper.h"

class SerialPortManager_Interface
{
public:
    virtual void cbiSerialPortHelper_serialPortStatus(const bool &open_close, const std::string &errorString) = 0;
};

class SerialPortManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortManager(QObject *parent = nullptr);

    explicit SerialPortManager(QSerialPort *serialPort, QObject *parent = NULL);

    ~SerialPortManager();

    void configureSerialPort(const QString &name);

    void configureSerialPort(const QString &name, const QSerialPort::BaudRate &rate,
                                               const QSerialPort::Parity &parity, const QSerialPort::DataBits &data,
                                               const QSerialPort::FlowControl &flow, const QSerialPort::StopBits &stop);

    void writeParameters(const std::vector<DataParameter::AbstractParameter*> &write);

    void readBytes();

    void changeSerialParameters();

    void closeSerialPort();

    void openSerialPort();

signals:
    bytesReceived(const QByteArray &data);

private slots:
    void writeBytes(const QByteArray &writeData);
    void handleBytesWritten(qint64 bytes);
    void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

public:
    void connectCallback(SerialPortManager_Interface *cb)
    {
        m_CB = cb;
    }
private:
    SerialPortManager_Interface *m_CB;
    SerialPortHelper* serialPortHelper;

private:
    QSerialPort *m_serialPort;
    QByteArray m_writeData;
    QByteArray m_readData;
    QTimer m_timer;

    QByteArray transmittedData;
    std::vector<QByteArray> transmitVector;
};

#endif // SERIAL_PORT_HELPER_H
