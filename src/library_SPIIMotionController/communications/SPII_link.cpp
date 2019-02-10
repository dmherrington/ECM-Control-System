#include "SPII_link.h"

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

//!
//! \brief GalilLink::GalilLink
//!
SPIILink::SPIILink()
{
    connected = false;
    std::cout << "Create GalilLink " <<std::endl;
}

//!
//! \brief GalilLink::~GalilLink
//!
SPIILink::~SPIILink()
{
    Disconnect();

}

//!
//! \brief GalilLink::Connect
//! \return
//!
void SPIILink::Connect(void)
{
    if(connected)
    {
        //We already connected and it has been requested to connect again
        //We shall close the port before opening this new connection
        this->Disconnect();
    }

    common::comms::CommunicationUpdate commsUpdate("SPII Link");

    switch (m_CommunicationSettings.type) {
    case COMMS_TYPE::ETHERNET:
    {
        m_SPII = acsc_OpenCommEthernetTCP(m_CommunicationSettings.ethernetPort.listenAddress(),m_CommunicationSettings.ethernetPort.listenPortNumber());
        if(m_SPII)
        break;
    }
    case COMMS_TYPE::PCI:
    {
        //m_SPII = acsc_OpenCommPCI();
        break;
    }
    case COMMS_TYPE::SERIAL:
    {
        //m_SPII = acsc_OpenCommSerial();
        break;
    }
    case COMMS_TYPE::SIMULATION:
    {
        m_SPII = acsc_OpenCommSimulator();
        break;
    }
    default:
        break;
    }

    if(m_SPII == ACSC_INVALID)
    {
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::ALERT);

        //there was a problem connecting
        int errorCode = acsc_GetLastError();
        acsc_GetErrorString(m_SPII,errorCode,)
        //get the string associated with the error code
        std::string errorString;
        commsUpdate.setPeripheralMessage(errorString);
    }
    else
    {
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
        commsUpdate.setPeripheralMessage("SPII Motor Controller Connected.");
    }

    EmitEvent([update](const ILinkEvents *ptr){ptr->ConnectionUpdate(update);});

}

//!
//! \brief GalilLink::Disconnect
//! \return
//!
void SPIILink::Disconnect(void)
{
    if(connected)
    {
        acsc_
        /*
        GReturn rtnCode = GClose(galil);
        if(rtnCode == G_NO_ERROR)
        {
            this->connected = false;
            EmitEvent([](const ILinkEvents *ptr){ptr->ConnectionClosed();});

            common::comms::CommunicationUpdate update("Galil Link");
            update.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED);
            update.setPeripheralMessage("Galil has been disconnected.");
            EmitEvent([update](const ILinkEvents *ptr){ptr->ConnectionUpdate(update);});

        }
        */
    }
}

//!
//! \brief GalilLink::isConnected
//! \return
//!
bool SPIILink::isConnected() const
{
    return this->connected;
}

} //END MAVLINKComms
