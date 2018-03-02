#include "sensoray_tcp_link.h"
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


SensorayTCPLink::SensorayTCPLink()
{
    m_Session = new SensoraySession();
}

SensorayTCPLink::~SensorayTCPLink()
{
    Disconnect();
    if(m_Session) delete m_Session;
    m_Session = nullptr;
}

void SensorayTCPLink::RequestReset()
{

}

void SensorayTCPLink::resetSensorayIO()
{
    S24XXERR errorCode = S24XXERR::ERR_NONE;
    s24xx_ResetIo(m_Session->handle,&errorCode);

    S2426_ADC_SAMPLE samp[8];
    int	iters;
    S24XXERR err = ERR_NONE;
    u8	dioChan;
    u32	EncoderCounts;			// Snapshot of encoder counts and acquisition time.
    u32	EncoderTimestamp;
    u8	dinDebounced;			// Snapshot of debounced dins.

    // Set session timeout to 5 seconds. Don't reset i/o upon timeout.
//	s24xx_SetTimeout( sess, &err, 5, UNITS_SECONDS, ACTION_NONE );

    // Set encoder mode.
    s2426_WriteEncoderMode( m_Session->handle, &errorCode, QUADRATURE_X4, ENC_PRELOAD_DISABLE );

    // Activate pwm mode for dout channels 12-15, using arbitrary timing values.
    for ( dioChan = 12; dioChan < 16; dioChan++ )
    {
        s2426_SetDoutMode( m_Session->handle, &errorCode, dioChan, DOUT2426_MODE_PWM );
        s2426_WritePwm( m_Session->handle, &errorCode, dioChan, (u16)( ( 23 * ( dioChan + 1 ) ) & 255 ), (u16)( ( 39 * ( dioChan + 1 ) ) & 511 ) );
    }

    // Execute the i/o processing loop a few times, approximately ten times per second.
    for (iters = 0; iters < 10000; iters++)
    {
        // Read encoder counts.
        s2426_ReadEncoderCounts(m_Session->handle, &errorCode, &EncoderCounts, &EncoderTimestamp );

        // Write counts to digital outputs.
        s2426_WriteDout( m_Session->handle, &errorCode, (u16)iters );

        // Read a/d converter.
        s2426_ReadAdc( m_Session->handle, &errorCode, samp, TRUE );

        // Write counts to dac.
        s2426_WriteAout( m_Session->handle, &errorCode, (s16)iters, TRUE );

        // Read debounced digital inputs.
        s2426_ReadDin( m_Session->handle, &errorCode, &dinDebounced, NULL );

        // Abort if error detected.
        if ( errorCode != ERR_NONE )
        {
            printf( "Error: %s\n", s24xx_ErrorText( err ) );
            break;
        }

        // Wait one "tick" time. In a realtime application this should use an ipc mechanism with realtime behavior.
        Sleep(1);
    }
}

void SensorayTCPLink::setTCPConfiguration(const SensorayTCPConfiguration &config)
{
    if(isConnected())
        Disconnect();
    _config = config;

    std::cout << "Create SensorayTCPLink " << _config.getDeviceAddress() <<":"<< config.getTelnetPort() << std::endl;
}


bool SensorayTCPLink::Connect(void)
{
    Disconnect();

    // Initialize the connection
    if (!_hardwareConnect()) {
        return false;
    }
    return true;
}

bool SensorayTCPLink::Disconnect(void)
{
    S24XXERR errorCode = S24XXERR::ERR_NONE;
    if(m_Session->isDeviceConnected())
    {
        if(m_Session->isCommPortOpened())
        {
            s2426_ComportClose(&m_Session->handle,&errorCode);
        }
        s24xx_SessionClose(m_Session->handle);
    }
    return true;
}


/// Performs the actual hardware port connection.
///     @param[out] error if failed
///     @param[out] error string if failed
/// @return success/fail
bool SensorayTCPLink::_hardwareConnect()
{
    HSESSION session;
    S24XXERR errorCode = S24XXERR::ERR_NONE;

    if(!s24xx_ApiOpen())
    {
        _emitLinkError("Error: Failed to open api interface.");
        return false;
    }

    // Create session object and open the telnet session.
    if(!s24xx_SessionOpen( &(m_Session->handle), &errorCode, _config.getModelType(), _config.getDeviceAddress().c_str(), _config.getTelnetPort(), 10000))
    {
        _emitLinkError("Error: Failed to open session interface.");
        return false;
    }
    u8	dioChan;
    for ( dioChan = 12; dioChan < 16; dioChan++ )
    {
        s2426_SetDoutMode( m_Session->handle, &errorCode, dioChan, DOUT2426_MODE_PWM );
        s2426_WritePwm( m_Session->handle, &errorCode, dioChan, (u16)( ( 23 * ( dioChan + 1 ) ) & 255 ), (u16)( ( 39 * ( dioChan + 1 ) ) & 511 ) );
    }

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
bool SensorayTCPLink::isConnected() const
{
    return false;
}


void SensorayTCPLink::_emitLinkError(const std::string& errorMsg) const
{
    std::string msg = "Error on link " + getDeviceAddress() + ":" + std::to_string(getTelnetPortNumber()) + " - " + errorMsg;
    EmitEvent([&](const ILinkEvents *ptr){ptr->CommunicationError("Link Error", msg);});
}

LinkConfiguration SensorayTCPLink::getLinkConfiguration()
{
    return _config;
}

std::string SensorayTCPLink::getDeviceAddress() const
{
    return _config.getDeviceAddress();
}

int SensorayTCPLink::getTelnetPortNumber() const
{
    return _config.getTelnetPort();
}

} //end of namepsace comms
} //end of namespace sensoray
