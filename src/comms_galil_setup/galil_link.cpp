#include "galil_link.h"

#include <functional>

#include <QCoreApplication>
#include <QTimer>

namespace Comms
{


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

GalilLink::GalilLink()
{
//    m_bytesRead = 0;
//    m_port     = NULL;
//    m_stop    = false;
//    m_reqReset = false;

    std::cout << "Create GalilLink " <<std::endl;
}

GalilLink::~GalilLink()
{
//    Disconnect();
//    if(m_port) delete m_port;
//    m_port = NULL;
}


void GalilLink::RequestReset()
{
//    m_stopMutex.lock();
//    m_reqReset = true;
//    m_stopMutex.unlock();
}

void GalilLink::WriteBytes(const char *bytes, int length) const
{
//    QByteArray data(bytes, length);
//    if(m_port && m_port->isOpen()) {
//        //_logOutputDataRate(data.size(), QDateTime::currentMSecsSinceEpoch());
//        m_port->write(data);
//    } else {
//        // Error occured
//        _emitLinkError("Could not send data - link " + getPortName() + " is disconnected!");
//    }
}

//!
//! \brief Determine the connection status
//! \return True if the connection is established, false otherwise
//!
bool GalilLink::isConnected() const
{
    bool isConnected = false;

//    if (m_port) {
//        isConnected = m_port->isOpen();
//    }

    return isConnected;
}



bool GalilLink::Connect(void)
{
//    Disconnect();

//    QSerialPort::SerialPortError    error;
//    QString                         errorString;

//    // Initialize the connection
//    if (!_hardwareConnect(error, errorString)) {
//        if (_config.isAutoConnect()) {
//            // Be careful with spitting out open error related to trying to open a busy port using autoconnect
//            if (error == QSerialPort::PermissionError) {
//                // Device already open, ignore and fail connect
//                return false;
//            }
//        }

//        _emitLinkError("Error connecting: Could not create port. " + errorString.toStdString());
//        return false;
//    }
    return true;
}

void GalilLink::Disconnect(void)
{
//    if (m_port) {
//        m_port->close();
//        delete m_port;
//        m_port = NULL;
//    }
}


void GalilLink::_readBytes(void)
{
//    qint64 byteCount = m_port->bytesAvailable();
//    if (byteCount) {
//        QByteArray buffer;
//        buffer.resize(byteCount);
//        m_port->read(buffer.data(), buffer.size());

//        std::vector<uint8_t> vec_buffer = std::vector<uint8_t>(buffer.begin(), buffer.end());

//        EmitEvent([this,&vec_buffer](const ILinkEvents *ptr){ptr->ReceiveData(this, vec_buffer);});
//    }
}

void GalilLink::PortEventLoop()
{
//    if(m_port->bytesAvailable())
//        this->_readBytes();



//    if(m_port->errorString() != "")
//    {
//        //linkError(m_port->error());
//    }
}

} //END MAVLINKComms
