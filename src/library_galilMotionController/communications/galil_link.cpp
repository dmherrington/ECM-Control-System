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

//!
//! \brief GalilLink::GalilLink
//!
GalilLink::GalilLink()
{
    connected = false;
    std::cout << "Create GalilLink " <<std::endl;
}

//!
//! \brief GalilLink::~GalilLink
//!
GalilLink::~GalilLink()
{
    Disconnect();

}

//!
//! \brief GalilLink::Connect
//! \return
//!
bool GalilLink::Connect(void)
{
    if(connected)
    {
        //We already connected and it has been requested to connect again
        //We shall close the port before opening this new connection
        this->Disconnect();
    }

    common::comms::CommunicationUpdate update("Galil Link");
    std::string errorString = "";

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
    return this->connected;
}

//!
//! \brief GalilLink::Disconnect
//! \return
//!
bool GalilLink::Disconnect(void)
{
    if(connected)
    {
        GReturn rtnCode = GClose(galil);
        if(rtnCode == G_NO_ERROR)
        {
            this->connected = false;
            EmitEvent([](const ILinkEvents *ptr){ptr->ConnectionClosed();});

        }
    }
    return this->connected;
}

//!
//! \brief GalilLink::isConnected
//! \return
//!
bool GalilLink::isConnected() const
{
    return this->connected;
}

//!
//! \brief GalilLink::UploadProgram
//! \param programText
//! \return
//!
GReturn GalilLink::UploadProgram(const std::string &programText) const
{
    GReturn rtn = GProgramDownload(galil,programText.c_str(),0);
    return rtn;
}

//!
//! \brief GalilLink::DownloadProgram
//! \param programText
//! \return
//!
GReturn GalilLink::DownloadProgram(std::string &programText) const
{
    GReturn rtnCode = G_BAD_LOST_DATA;
    unsigned int bufferSize = 1000;
    int retries = 0;
    while ((rtnCode == G_BAD_LOST_DATA) && (retries < 10))
    {
        char* buf = new char[bufferSize]();
        rtnCode = GProgramUpload(galil,buf,bufferSize);
        if(rtnCode == G_NO_ERROR)
            programText = std::string(buf);
        else
        {
            retries++;
            bufferSize = bufferSize * (retries + 1);
        }
        delete[] buf;
    }
    return rtnCode;
}

//!
//! \brief GalilLink::WriteTellErrorCode
//! \param errorCode
//! \param description
//! \return
//!
GReturn GalilLink::WriteTellErrorCode(unsigned int &errorCode, std::string &description) const
{
    GSize read_bytes = 0; //bytes read in GCommand

    std::string newCommand = "TC 0";
    char* buf = new char[4]();
    GReturn rtn = GCommand(galil,newCommand.c_str(),buf,4,&read_bytes);
    errorCode = stoi(std::string(buf));
    delete buf;

    newCommand = "TC 1";
    buf = new char[100]();
    rtn = GCommand(galil,newCommand.c_str(),buf,100,&read_bytes);
    description = std::string(buf);
    QString returnString = QString::fromStdString(std::string(buf));
    returnString.remove(QRegExp("[:\\n\\r]"));
    description = returnString.toStdString();
    delete buf;

    return rtn;
}

//!
//! \brief GalilLink::WriteCommand
//! \param command
//! \return
//!
GReturn GalilLink::WriteCommand(const std::string &command) const
{
    GReturn rtn = GCmd(galil,command.c_str());
    return rtn;
}

//!
//! \brief GalilLink::WriteRequest
//! \param request
//! \return
//!
GReturn GalilLink::WriteRequest(AbstractRequestPtr request) const
{

    GReturn rtnCode = G_BAD_LOST_DATA;
    std::string commandString = request->getRequestString();

    int retries = 0;
    while ((rtnCode == G_BAD_LOST_DATA) && (retries < 10))
    {
        GSize read_bytes = 0; //bytes read in GCommand
        char buf[request->getAllocatedBufferSize()];
        rtnCode = GCommand(galil,commandString.c_str(),buf,sizeof(buf),&read_bytes);

        if(rtnCode == G_NO_ERROR)
        {
            request->setBuffer(std::string(buf));
            request->updateTime();
        }
        else
        {
            retries++;
            request->increaseBufferSize();
        }
        delete[] buf;
    }

    return rtnCode;
}

} //END MAVLINKComms
