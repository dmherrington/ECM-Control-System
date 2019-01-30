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

    /*
    common::comms::CommunicationUpdate update("Galil Link");
    std::string errorString = "";
    address
    //We should attempt connecting to the Galil unit at the prescribed address
    GReturn rtnCode = GOpen(address.c_str(),&galil);
    if(rtnCode == G_NO_ERROR)
    {
        this->connected = true;
        EmitEvent([](const ILinkEvents *ptr){ptr->ConnectionOpened();});
        update.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
        errorString = "Galil has been connected.";
    }
    else{
        unsigned int bufferSize = 100;
        char* buf = new char[bufferSize]();
        GError(rtnCode,buf,bufferSize);
        std::string bufString(buf);
        delete[] buf;
        errorString = "Error connecting to galil: " + bufString;
        update.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::ALERT);
    }

    update.setPeripheralMessage(errorString);
    EmitEvent([update](const ILinkEvents *ptr){ptr->ConnectionUpdate(update);});
    */
}

//!
//! \brief GalilLink::Disconnect
//! \return
//!
void SPIILink::Disconnect(void)
{
    if(connected)
    {
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
