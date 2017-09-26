#ifndef SERIAL_PORT_HELPER_H
#define SERIAL_PORT_HELPER_H

#include <QtSerialPort/QSerialPort>

#include <QThread>
#include <QTextStream>
#include <QTimer>
#include <QByteArray>
#include <QObject>

#include <iostream>

#include "common/common.h"

#include "munk_tx_rx.h"

class SerialPortHelper : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortHelper(QObject *parent = nullptr);

    explicit SerialPortHelper(QSerialPort *serialPort, QObject *parent = NULL);

    ~SerialPortHelper();

    void configureSerialPort(const QString &name);

    void configureSerialPort(const QString &name, const QSerialPort::BaudRate &rate,
                                               const QSerialPort::Parity &parity, const QSerialPort::DataBits &data,
                                               const QSerialPort::FlowControl &flow, const QSerialPort::StopBits &stop);

    void writeByteVector(const std::vector<QByteArray> &write);

    void writeBytes(const QByteArray &writeData);

    void readBytes();

    void changeSerialParameters();

    void closeSerialPort();

    void openSerialPort();

signals:
    bytesReceived(const QByteArray &data);

private slots:
    void handleBytesWritten(qint64 bytes);
    void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort;
    QByteArray m_writeData;
    QByteArray m_readData;
    QTimer m_timer;
    MunkTXRX m_parseHelper;

    std::vector<QByteArray> transmitVector;
};

#endif // SERIAL_PORT_HELPER_H
