#include "rigol_tcp_link.h"

namespace rigol{
namespace comms {

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


RigolTCPLink::RigolTCPLink()
{
    m_socket    = NULL;
    m_bytesRead = 0;
    m_stopp    = false;
    m_reqReset = false;
}

RigolTCPLink::~RigolTCPLink()
{
    Disconnect();
    if(m_socket) delete m_socket;
    m_socket = NULL;
}

void RigolTCPLink::RequestReset()
{
    m_stoppMutex.lock();
    m_reqReset = true;
    m_stoppMutex.unlock();
}

void RigolTCPLink::setTCPConfiguration(const TCPConfiguration &config)
{
    if(isConnected())
        Disconnect();
    _config = config;

    std::cout << "Create RigolTCPLink " << _config.listenAddress() << config.listenPortNumber() << std::endl;
}


bool RigolTCPLink::Connect(void)
{
    Disconnect();

    QTcpSocket::SocketError error;
    QString errorString;

    // Initialize the connection
    if (!_hardwareConnect(error, errorString)) {
        if (_config.isAutoConnect()) {
            // Be careful with spitting out open error related to trying to open a busy port using autoconnect
            if (error == QTcpSocket::AddressInUseError) {
                // Device already open, ignore and fail connect
                return false;
            }
        }

        _emitLinkError("Error connecting: Could not create port. " + errorString.toStdString());
        return false;
    }
    return true;
}

bool RigolTCPLink::Disconnect(void)
{
    if (m_socket) {
        m_socket->close();
        delete m_socket;
        m_socket = NULL;
    }
    return true;
}


/// Performs the actual hardware port connection.
///     @param[out] error if failed
///     @param[out] error string if failed
/// @return success/fail
bool RigolTCPLink::_hardwareConnect(QAbstractSocket::SocketError &error, QString& errorString)
{
    if (m_socket) {
        std::cout << "UdpLink:" << QString::number((long)this, 16).toStdString() << "closing port" << std::endl;
        m_socket->close();
        std::this_thread::sleep_for(std::chrono::microseconds(50000));
        delete m_socket;
        m_socket = NULL;
    }

    std::cout << "UdpLink: hardwareConnect to " << _config.listenAddress() << ":" << _config.listenPortNumber() << std::endl;

    m_socket = new QTcpSocket();
    m_socket->bind(QHostAddress(QString::fromStdString((_config.listenAddress()))), _config.listenPortNumber());
    m_socket->connectToHost(QHostAddress(QString::fromStdString((_config.listenAddress()))), _config.listenPortNumber());

    for (int openRetries = 0; openRetries < 4; openRetries++) {
        if (!m_socket->open(QIODevice::ReadWrite)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        } else {
            break;
        }
    }

    if (!m_socket->isOpen() ) {
        error = m_socket->error();
        errorString = m_socket->errorString();
        EmitEvent([&](const ILinkEvents *ptr){ptr->CommunicationUpdate(_config.listenAddress(), "Error opening port: " + errorString.toStdString());});
        m_socket->close();
        delete m_socket;
        m_socket = NULL;
        return false; // couldn't open udp port
    }


    // TODO: Figure out the alternative to this:
    EmitEvent([this](const ILinkEvents *ptr){ptr->CommunicationUpdate(getListenAddress(), "Opened port!");});
    EmitEvent([this](const ILinkEvents *ptr){ptr->ConnectionOpened();});

    std::cout << "Connection UdpLink: " << "with settings " << _config.listenAddress() << ":" << _config.listenPortNumber() << std::endl;


    m_ListenThread = new AppThread(10, [&](){
        //this->PortEventLoop();
    });
    m_socket->moveToThread(m_ListenThread);
    m_ListenThread->start();

    return true; // successful connection
}


void RigolTCPLink::WriteBytes(const QByteArray &data) const
{
    if(m_socket && m_socket->isOpen()) {
        m_socket->write(data);
    } else {
        // Error occured
        _emitLinkError("Could not send data - link " + getSenderAddress() + ":" + std::to_string(getSenderPortNumber()) + " is disconnected!");
    }
}

std::vector<uint8_t> RigolTCPLink::WriteBytesRequest(const QByteArray &data) const
{
    std::vector<uint8_t> buffer;

    if(m_socket && m_socket->isOpen()) {
        m_socket->write(data);
        if (m_socket->waitForBytesWritten()) {
            // read response
            if (m_socket->waitForReadyRead()) {
                buffer = this->ProcessResponse();
            }
        }
    } else {
        // Error occured
        _emitLinkError("Could not send data - link " + getSenderAddress() + ":" + std::to_string(getSenderPortNumber()) + " is disconnected!");
    }
    return buffer;
}

std::vector<uint8_t> RigolTCPLink::ProcessResponse() const
{
    std::vector<uint8_t> vec_buffer;

    if(m_socket && m_socket->isOpen()) {
        if(m_socket->bytesAvailable())
        {
            qint64 byteCount = m_socket->bytesAvailable();
            if (byteCount) {
                QByteArray buffer;
                buffer.resize(byteCount);
                m_socket->read(buffer.data(), buffer.size());
                vec_buffer = std::vector<uint8_t>(buffer.begin(), buffer.end());
            }
        } else {
            // Error occured
            _emitLinkError("Could not send data - link " + getSenderAddress() + ":" + std::to_string(getSenderPortNumber()) + " is disconnected!");
        }
    }
    return vec_buffer;
}


//!
//! \brief Determine the connection status
//! \return True if the connection is established, false otherwise
//!
bool RigolTCPLink::isConnected() const
{
    bool isConnected = false;

    if (m_socket) {
        isConnected = m_socket->isOpen();
    }

    return isConnected;
}


void RigolTCPLink::_emitLinkError(const std::string& errorMsg) const
{
    std::string msg = "Error on link " + getListenAddress() + ":" + std::to_string(getListenPortNumber()) + " - " + errorMsg;
    EmitEvent([&](const ILinkEvents *ptr){ptr->CommunicationError("Link Error", msg);});
}

LinkConfiguration RigolTCPLink::getLinkConfiguration()
{
    return _config;
}

std::string RigolTCPLink::getListenAddress() const
{
    return _config.listenAddress();
}

int RigolTCPLink::getListenPortNumber() const
{
    return _config.listenPortNumber();
}

std::string RigolTCPLink::getSenderAddress() const
{
    return _config.senderAddress();
}

int RigolTCPLink::getSenderPortNumber() const
{
    return _config.senderPortNumber();
}

//void RigolTCPLink::processPendingDatagrams(void) const
//{
//    qint64 byteCount = m_socket->bytesAvailable();
//    if (byteCount) {
//        QByteArray buffer;
//        buffer.resize(byteCount);
//        m_socket->read(buffer.data(), buffer.size());
//        std::vector<uint8_t> vec_buffer = std::vector<uint8_t>(buffer.begin(), buffer.end());
//        EmitEvent([this,&vec_buffer](const ILinkEvents *ptr){ptr->ReceiveData(vec_buffer);});
//    }
//}

void RigolTCPLink::linkError(QTcpSocket::SocketError error)
{
    // TODO: Handle link errors:
    switch (error) {
    case QTcpSocket::AddressInUseError:
        EmitEvent([this](const ILinkEvents *ptr){ptr->ConnectionClosed();});
        break;
    default:
        break;
    }
}

} //end of namepsace comms
} //end of namespace rigol
