#include "serial_port_manager.h"

SerialPortManager::SerialPortManager(QObject *parent) :
    QObject(parent), m_CB(nullptr)
{
    serialPortHelper = new SerialPortHelper();
    connect(serialPortHelper, &SerialPortHelper::transmitByteArray, this, &SerialPortManager::writeBytes);

    m_serialPort = new QSerialPort();
    m_timer.setSingleShot(true); // this implies this timer only fires once

    connect(m_serialPort, &QSerialPort::bytesWritten, this, &SerialPortManager::handleBytesWritten);
    connect(m_serialPort, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &SerialPortManager::handleError);
    connect(&m_timer, &QTimer::timeout, this, &SerialPortManager::handleTimeout);

    //this connection alerts this class when data is available for reading
    connect(m_serialPort,&QIODevice::readyRead, this, &SerialPortManager::readBytes);
}

SerialPortManager::SerialPortManager(QSerialPort *serialPort, QObject *parent) :
    m_serialPort(serialPort), QObject(parent)
{
    m_timer.setSingleShot(true); // this implies this timer only fires once
    connect(m_serialPort, &QSerialPort::bytesWritten, this, &SerialPortManager::handleBytesWritten);
    connect(m_serialPort, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &SerialPortManager::handleError);
    connect(&m_timer, &QTimer::timeout, this, &SerialPortManager::handleTimeout);

    //this connection alerts this class when data is available for reading
    connect(m_serialPort,&QIODevice::readyRead, this, &SerialPortManager::readBytes);

}

void SerialPortManager::handleBytesWritten(qint64 bytes)
{
    UNUSED(bytes);
}

SerialPortManager::~SerialPortManager()
{
    serialPortHelper->stop();
    delete serialPortHelper;
    serialPortHelper = nullptr;

    this->closeSerialPort();
}

void SerialPortManager::handleTimeout()
{

}

void SerialPortManager::handleError(QSerialPort::SerialPortError error)
{
    UNUSED(error);
}

void SerialPortManager::configureSerialPort(const QString &name)
{
    if(m_serialPort->isOpen())
        this->closeSerialPort();

    m_serialPort->setPortName(name);
    m_serialPort->setBaudRate(QSerialPort::Baud19200);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
    m_serialPort->setStopBits(QSerialPort::OneStop);

}

void SerialPortManager::configureSerialPort(const QString &name, const QSerialPort::BaudRate &rate,
                                           const QSerialPort::Parity &parity, const QSerialPort::DataBits &data,
                                           const QSerialPort::FlowControl &flow, const QSerialPort::StopBits &stop)
{
    if(m_serialPort->isOpen())
        this->closeSerialPort();

    m_serialPort->setPortName(name);
    m_serialPort->setBaudRate(rate);
    m_serialPort->setParity(parity);
    m_serialPort->setDataBits(data);
    m_serialPort->setFlowControl(flow);
    m_serialPort->setStopBits(stop);
}

void SerialPortManager::openSerialPort()
{
    for (int openRetries = 0; openRetries < 4; openRetries++)
    {
        if(!m_serialPort->open(QIODevice::ReadWrite))
        {
            std::cout<<"The port failed to open, trying again"<<std::endl;
            //A sleep should occur before reattempting to open port
            QThread::msleep(500);
        }
        else{
            break;
        }
    }

    if(!m_serialPort->isOpen())
    {
        QSerialPort::SerialPortError error = m_serialPort->error();
        QString errorString = m_serialPort->errorString();
            m_CB->cbiSerialPortHelper_serialPortStatus(false,errorString.toStdString());

        m_serialPort->close();
        delete m_serialPort;
        m_serialPort = NULL;
    }else{
        std::cout<<"The serial port was successfully opened."<<std::endl;
        if(m_CB)
            m_CB->cbiSerialPortHelper_serialPortStatus(true, "");
    }
}

void SerialPortManager::closeSerialPort()
{
    if(m_serialPort)
    {
        if(m_serialPort->isOpen())
            m_serialPort->close();
        delete m_serialPort;
        m_serialPort = NULL;
    }
}

void SerialPortManager::writeParameters(const std::vector<DataParameter::AbstractParameter*> &write)
{
    serialPortHelper->transmitParameters(write);
//    serialPortHelper->transmitBytes(write[0]);
//    transmittedData = write[0];
//    writeBytes(write[0]);
//    transmitVector = write;
//    for(unsigned int i = 0; i < transmitVector.size(); i++)
//    {
//        writeBytes(transmitVector[i]);
//    }
}

void SerialPortManager::writeBytes(const QByteArray &writeData)
{
    m_writeData = writeData;

    if((m_serialPort) && (m_serialPort->isOpen()))
    {
            qint64 bytesWritten = m_serialPort->write(writeData);

            if(bytesWritten == -1)
            {

            }
            else if (bytesWritten != m_writeData.size())
            {

            }
    }
    else
    {
        //the port is not yet open or is not defined
    }
}

void SerialPortManager::readBytes()
{
    qint64 byteCount = m_serialPort->bytesAvailable();
    if(byteCount)
    {
        QByteArray buffer;
        buffer.resize(byteCount);
        m_serialPort->read(buffer.data(), buffer.size());
        serialPortHelper->receivedBytes(buffer);
    }
}
