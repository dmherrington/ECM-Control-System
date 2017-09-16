#include "serial_port_helper.h"

SerialPortHelper::SerialPortHelper(QObject *parent) :
    QObject(parent)
{
    m_serialPort = new QSerialPort();
    m_timer.setSingleShot(true); // this implies this timer only fires once
    connect(m_serialPort, &QSerialPort::bytesWritten, this, &SerialPortHelper::handleBytesWritten);
    connect(m_serialPort, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &SerialPortHelper::handleError);
    connect(&m_timer, &QTimer::timeout, this, &SerialPortHelper::handleTimeout);

    //this connection alerts this class when data is available for reading
    connect(m_serialPort,&QIODevice::readyRead, this, &SerialPortHelper::readBytes);
}

SerialPortHelper::SerialPortHelper(QSerialPort *serialPort, QObject *parent) :
    m_serialPort(serialPort), QObject(parent)
{
    m_timer.setSingleShot(true); // this implies this timer only fires once
    connect(m_serialPort, &QSerialPort::bytesWritten, this, &SerialPortHelper::handleBytesWritten);
    connect(m_serialPort, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &SerialPortHelper::handleError);
    connect(&m_timer, &QTimer::timeout, this, &SerialPortHelper::handleTimeout);

    //this connection alerts this class when data is available for reading
    connect(m_serialPort,&QIODevice::readyRead, this, &SerialPortHelper::readBytes);

}

void SerialPortHelper::handleBytesWritten(qint64 bytes)
{
    UNUSED(bytes);
}

SerialPortHelper::~SerialPortHelper()
{
    this->closeSerialPort();
}

void SerialPortHelper::handleTimeout()
{

}

void SerialPortHelper::handleError(QSerialPort::SerialPortError error)
{
    UNUSED(error);
}

void SerialPortHelper::configureSerialPort(const QString &name)
{
    if(m_serialPort->isOpen())
        this->closeSerialPort();

    m_serialPort->setPortName(name);
    m_serialPort->setBaudRate(QSerialPort::Baud9600);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
    m_serialPort->setStopBits(QSerialPort::OneStop);

}

void SerialPortHelper::configureSerialPort(const QString &name, const QSerialPort::BaudRate &rate,
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

void SerialPortHelper::openSerialPort()
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
        //qDebug() << "open failed" << _port->errorString() << _port->error() << getName() << qgcApp()->toolbox()->linkManager()->isAutoconnectLink(this);
        QSerialPort::SerialPortError error = m_serialPort->error();
        QString errorString = m_serialPort->errorString();
        UNUSED(error);
        UNUSED(errorString);
        //emit communicationUpdate(getName(),"Error opening port: " + _port->errorString());
        m_serialPort->close();
        delete m_serialPort;
        m_serialPort = NULL;
    }else{
        std::cout<<"The serial port was successfully opened."<<std::endl;
    }
}

void SerialPortHelper::closeSerialPort()
{
    if(m_serialPort)
    {
        if(m_serialPort->isOpen())
            m_serialPort->close();
        delete m_serialPort;
        m_serialPort = NULL;
    }
}

void SerialPortHelper::writeBytes(const QByteArray &writeData)
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

void SerialPortHelper::readBytes()
{
    qint64 byteCount = m_serialPort->bytesAvailable();
    if(byteCount)
    {
        QByteArray buffer;
        buffer.resize(byteCount);
        m_serialPort->read(buffer.data(), buffer.size());
        std::cout<<"I have seen some data"<<std::endl;
        emit bytesReceived(buffer);
    }
}
