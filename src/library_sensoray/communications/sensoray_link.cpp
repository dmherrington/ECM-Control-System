#include "sensoray_link.h"
#include <time.h>
#include <windows.h>
#include <conio.h>
namespace sensoray{
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


SensorayLink::SensorayLink()
{
    m_Session = new SensoraySession();
}

SensorayLink::~SensorayLink()
{
    DisconnectFromDevice();
    if(m_Session) delete m_Session;
    m_Session = nullptr;
}

void SensorayLink::RequestReset()
{

}

void SensorayLink::setTCPConfiguration(const SensorayTCPConfiguration &config)
{
    if(isConnected())
        DisconnectFromDevice();
    _config = config;

    std::cout << "Create SensorayTCPLink " << _config.getDeviceAddress() <<":"<< config.getTelnetPort() << std::endl;
}


bool SensorayLink::ConnectToDevice(void)
{
    DisconnectFromDevice();

    // Initialize the connection
    if (!_hardwareConnect()) {
        return false;
    }
    return true;
}

bool SensorayLink::DisconnectFromDevice(void)
{
    S24XXERR errorCode = S24XXERR::ERR_NONE;
    if(m_Session->isDeviceConnected())
    {
        if(m_Session->isSerialPortConnected())
        {
            s2426_ComportClose(&m_Session->handle,&errorCode);
            m_Session->setSerialPortConnected(false);
        }
        s24xx_SessionClose(m_Session->handle);
        m_Session->setDeviceConnected(false);
        s24xx_ApiClose();
        m_Session->setAPIOpen(false);
    }
    return true;
}

/// Performs the actual hardware port connection.
///     @param[out] error if failed
///     @param[out] error string if failed
/// @return success/fail
bool SensorayLink::_hardwareConnect()
{
    S24XXERR errorCode = S24XXERR::ERR_NONE;

    if(!s24xx_ApiOpen())
    {
        _emitLinkError("Error: Failed to open api interface.");
        return false;
    }

    m_Session->setAPIOpen(true);

    // Create session object and open the telnet session.
    if(!s24xx_SessionOpen( &(m_Session->handle), &errorCode, _config.getModelType(), _config.getDeviceAddress().c_str(), _config.getTelnetPort(), 10000))
    {
        _emitLinkError("Error: Failed to open session interface.");
        return false;
    }
    m_Session->setDeviceConnected(true);

    m_ListenThread = new AppThread(10, [&](){
        //this->PortEventLoop();
    });

    m_Session->moveToThread(m_ListenThread);
    m_ListenThread->start();


    EmitEvent([this](const ILinkEvents *ptr){ptr->CommunicationUpdate(getDeviceAddress(), "Opened port!");});
    EmitEvent([this](const ILinkEvents *ptr){ptr->ConnectionOpened();});

    return true; // successful connection
}


//!
//! \brief Determine the connection status
//! \return True if the connection is established, false otherwise
//!
bool SensorayLink::isConnected() const
{
    return m_Session->isDeviceConnected();
}

void SensorayLink::updateCurrentSession(SensoraySession* session)
{
    this->m_Session = session;
}

void SensorayLink::_emitLinkError(const std::string& errorMsg) const
{
    std::string msg = "Error on link " + getDeviceAddress() + ":" + std::to_string(getTelnetPortNumber()) + " - " + errorMsg;
    EmitEvent([&](const ILinkEvents *ptr){ptr->CommunicationError("Link Error", msg);});
}

LinkConfiguration SensorayLink::getLinkConfiguration()
{
    return _config;
}

std::string SensorayLink::getDeviceAddress() const
{
    return _config.getDeviceAddress();
}

int SensorayLink::getTelnetPortNumber() const
{
    return _config.getTelnetPort();
}

} //end of namepsace comms
} //end of namespace sensoray
