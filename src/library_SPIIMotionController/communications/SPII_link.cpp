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
    std::cout << "Create SPIILink " <<std::endl;
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
bool SPIILink::Connect(HANDLE* link)
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
        char *cstr = new char[m_CommunicationSettings.ethernetPort.listenAddress().length() + 1];
        strcpy(cstr, m_CommunicationSettings.ethernetPort.listenAddress().c_str());

        HANDLE currentCommsHandle = acsc_OpenCommEthernetTCP(cstr,m_CommunicationSettings.ethernetPort.listenPortNumber());
        m_SPII = &currentCommsHandle;
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
        HANDLE currentCommsHandle = acsc_OpenCommSimulator();
        m_SPII = &currentCommsHandle;
        double referencePosition;
        int value = acsc_GetRPosition(*m_SPII,ACSC_AXIS_0,&referencePosition,ACSC_SYNCHRONOUS);
        if(value)
        {
            std::cout<<"The current reference position is: "<<referencePosition<<std::endl;
        }

        break;
    }
    default:
    {
        break;
    }
    }

    if(m_SPII == ACSC_INVALID)
    {
        this->connected = false;

        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::ALERT);
        int errorCode = acsc_GetLastError();

        int availableBufLength = 256;
        char errorBuf[availableBufLength];
        int receivedBufLength = 256;
        //unsigned int maxTries = 2, tryIndex =0;

        //get the string associated with the error code
        if(acsc_GetErrorString(m_SPII,errorCode,errorBuf,availableBufLength,&receivedBufLength))
        {
            if(receivedBufLength == availableBufLength)
            {
                //the buffer may have not been long enough
                //we shall wrap this in a loop later
            }
            else
            {
                std::string errorString(errorBuf);
                commsUpdate.setPeripheralMessage(errorString);
            }
        }
        EmitEvent([commsUpdate](const ILinkEvents *ptr){ptr->ConnectionUpdate(commsUpdate);});
    }
    else
    {
        link = m_SPII;
        this->connected = true;
    }
    return this->connected;
}

//!
//! \brief GalilLink::Disconnect
//! \return
//!
void SPIILink::Disconnect(void)
{
    if(connected)
    {
        switch (m_CommunicationSettings.type) {
        case COMMS_TYPE::SIMULATION:
        {
            if(acsc_CloseSimulator())
            {
                //The simulator had closed properly
                connected = false;
            }
            else {
                //There was a problem closing the simulator
            }
            break;
        }
        default:
        {
            if(acsc_CloseComm(this->m_SPII))
            {
                //The simulator had closed properly
                connected = false;
            }
            else {
                //There was a problem closing the simulator
            }
            break;
        }
        }
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

void SPIILink::requestPosition()
{
    double referencePosition;
    int value = acsc_GetRPosition(m_SPII,ACSC_AXIS_0,&referencePosition,ACSC_SYNCHRONOUS);
    if(value)
    {
        std::cout<<"The current reference position is: "<<referencePosition<<std::endl;
    }
}

} //END MAVLINKComms
