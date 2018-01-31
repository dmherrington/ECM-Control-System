#include "munk_serial_link.h"

#include <functional>

#include <QCoreApplication>
#include <QTimer>

namespace munk {
namespace comms{

//!
//! \brief This class defines a thread such that a QObject can run in peace.
//!
class AppThread : public QThread
{
public:
    AppThread(const size_t interval, std::function<void()> func)
    {
        if(QCoreApplication::instance() == NULL)
        {
            int argc = 0;
            char * argv[] = {(char *)"sharedlib.app"};
            pApp = new QCoreApplication(argc, argv);
        }

        m_Interval = interval;
        m_Func = func;
    }

    virtual void run()
    {
        QTimer *timer = new QTimer(0);
        timer->moveToThread(this);
        pApp->connect(timer, &QTimer::timeout, m_Func);
        timer->start(m_Interval);

        exec();
    }

private:

    QCoreApplication *pApp;

    std::function<void()> m_Func;
    size_t m_Interval;
};

MunkSerialLink::MunkSerialLink()
{
    connected = false;
    m_bytesRead = 0;
    m_port     = NULL;
    m_stopp    = false;
    m_reqReset = false;
}


MunkSerialLink::~MunkSerialLink()
{
    Disconnect();
    if(m_port) delete m_port;
    m_port = NULL;
}

void MunkSerialLink::_emitLinkError(const std::string& errorMsg) const
{
    std::string msg = "Error on link " + getPortName() + ". " + errorMsg;
    EmitEvent([&](const ILinkEvents *ptr){ptr->CommunicationError("Link Error", msg);});
}

void MunkSerialLink::RequestReset()
{
    m_stoppMutex.lock();
    m_reqReset = true;
    m_stoppMutex.unlock();
}

void MunkSerialLink::setSerialConfiguration(const SerialConfiguration &config)
{
    if(isConnected())
        Disconnect();
    _config = config;
    _config.setDynamic();

    std::cout << "Create SerialLink " << config.portName() << config.baud() << config.flowControl()
             << config.parity() << config.dataBits() << config.stopBits() << std::endl;
    std::cout <<  "portName: " << config.portName() << std::endl;
}

bool MunkSerialLink::Connect(void)
{
    Disconnect();

    QSerialPort::SerialPortError    error;
    QString                         errorString;

    // Initialize the connection
    if (!_hardwareConnect(error, errorString)) {
        if (_config.isAutoConnect()) {
            // Be careful with spitting out open error related to trying to open a busy port using autoconnect
            if (error == QSerialPort::PermissionError) {
                // Device already open, ignore and fail connect
                return false;
            }
        }

        _emitLinkError("Error connecting: Could not create port. " + errorString.toStdString());
        return false;
    }
    return true;
}

bool MunkSerialLink::Disconnect(void)
{
    if (m_port) {
        m_ListenThread->quit();
        m_port->close();
        delete m_port;
        m_port = nullptr;
        EmitEvent([](const ILinkEvents *ptr){ptr->ConnectionClosed();});
    }
    return isConnected();
}

bool MunkSerialLink::isConnected() const
{
    bool isConnected = false;

    if (m_port) {
        isConnected = m_port->isOpen();
    }

    return isConnected;
}

bool MunkSerialLink::_hardwareConnect(QSerialPort::SerialPortError& error, QString& errorString)
{
    if (m_port) {
        std::cout << "SerialLink:" << QString::number((long)this, 16).toStdString() << "closing port" << std::endl;
        m_port->close();
        std::this_thread::sleep_for(std::chrono::microseconds(50000));
        delete m_port;
        m_port = NULL;
    }

    std::cout << "MunkSerialLink: hardwareConnect to " << _config.portName() << std::endl;

    //m_port = new QSerialPort(QString::fromStdString(_config.portName()).trimmed(),0);
    std::cout << "Configuring port" << std::endl;
    m_port = new QSerialPort();
    m_port->setPortName(QString::fromStdString(_config.portName()).trimmed());
    m_port->setBaudRate     (_config.baud());
    m_port->setDataBits     (static_cast<QSerialPort::DataBits>     (_config.dataBits()));
    m_port->setFlowControl  (static_cast<QSerialPort::FlowControl>  (_config.flowControl()));
    m_port->setStopBits     (static_cast<QSerialPort::StopBits>     (_config.stopBits()));
    m_port->setParity       (static_cast<QSerialPort::Parity>       (_config.parity()));

    for (int openRetries = 0; openRetries < 4; openRetries++) {
        if (!m_port->open(QIODevice::ReadWrite)) {
            //std::cout << "Port open failed, retrying" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        } else {
            break;
        }
    }

    if (!m_port->isOpen() ) {
        std::cout<<"The open failed."<<std::endl;
        //std::cerr << "open failed" << m_port->errorString().toStdString() << m_port->error() << getName() << _config.isAutoConnect() << std::endl;
        error = m_port->error();
        errorString = m_port->errorString();
        EmitEvent([&](const ILinkEvents *ptr){ptr->CommunicationUpdate(getPortName(), "Error opening port: " + errorString.toStdString());});
        m_port->close();
        delete m_port;
        m_port = NULL;
        return false; // couldn't open serial port
    }

    //EmitEvent([this](const ILinkEvents *ptr){ptr->CommunicationUpdate(getPortName(), "Opened port!");});
    EmitEvent([this](const ILinkEvents *ptr){ptr->ConnectionOpened();});

    std::cout << "Connection SeriaLink: " << "with settings " << _config.portName() << " "
             << _config.baud() << " " << _config.dataBits() << " " << _config.parity() << " " << _config.stopBits() << std::endl;

    m_ListenThread = new AppThread(10, [&](){
        this->PortEventLoop();
    });
    m_port->moveToThread(m_ListenThread);
    m_ListenThread->start();

    return true; // successful connection
}

void MunkSerialLink::_readBytes(void)
{
    qint64 byteCount = m_port->bytesAvailable();
    if (byteCount) {
        QByteArray buffer;
        buffer.resize(byteCount);
        m_port->read(buffer.data(), buffer.size());

        std::vector<uint8_t> vec_buffer = std::vector<uint8_t>(buffer.begin(), buffer.end());

        EmitEvent([this,&vec_buffer](const ILinkEvents *ptr){ptr->ReceiveData(vec_buffer);});
    }
}

void MunkSerialLink::WriteBytes(const QByteArray &data) const
{
    if(m_port && m_port->isOpen()) {
        m_port->write(data);
        if(m_port->waitForBytesWritten(30000))
        {
            std::cout<<"The port has timed out."<<std::endl;
        }
    } else {
        // Error occured
        _emitLinkError("Could not send data to link. Most likely port is disconnected");
    }
}

void MunkSerialLink::linkError(QSerialPort::SerialPortError error)
{
    switch (error) {
    case QSerialPort::NoError:
        break;
    case QSerialPort::ResourceError:
        EmitEvent([this](const ILinkEvents *ptr){ptr->ConnectionClosed();});
        break;
    default:
        break;
    }
}

void MunkSerialLink::PortEventLoop()
{
    if(m_port->bytesAvailable())
        this->_readBytes();

    if(m_port->errorString() != "")
    {
        linkError(m_port->error());
    }
}

std::string MunkSerialLink::getPortName() const
{
    return _config.portName();
}


} //end of namespace comms
} //end of namespace munk
