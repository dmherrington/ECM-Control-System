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
    connected = false;
    std::cout << "Create GalilLink " <<std::endl;
}

GalilLink::~GalilLink()
{
    Disconnect();

}

bool GalilLink::Connect(void)
{
    if(connected)
    {
        //We already connected and it has been requested to connect again
        //We shall close the port before opening this new connection
        this->Disconnect();
    }

    //We should attempt connecting to the Galil unit at the prescribed address
    GReturn rtnCode = GOpen(address.c_str(),&galil);
    if(rtnCode == G_NO_ERROR)
    {
        this->connected = true;
        EmitEvent([](const ILinkEvents *ptr){ptr->ConnectionOpened();});
    }

    return this->connected;
}

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

bool GalilLink::isConnected() const
{
    return this->connected;
}

GReturn GalilLink::UploadProgram(const std::string &programText) const
{
    GReturn rtn = GProgramDownload(galil,programText.c_str(),0);
    return rtn;
}

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
    delete buf;

    return rtn;
}

GReturn GalilLink::WriteCommand(const std::string &command) const
{
    GReturn rtn = GCmd(galil,command.c_str());
    return rtn;
}

GReturn GalilLink::WriteRequest(AbstractRequestPtr request) const
{
    GSize read_bytes = 0; //bytes read in GCommand
    char buf[request->getAllocatedBufferSize()];

    //char* buf = request->getBuffer(); //buffer to be allocated for the response
    std::string commandString = request->getRequestString();

    GReturn rtn = GCommand(galil,commandString.c_str(),buf,sizeof(buf),&read_bytes);
    request->setBuffer(std::string(buf));
    request->updateTime();
    return rtn;
}

} //END MAVLINKComms
