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
    GReturn rtnCode = GOpen(galilAddress.c_str(),&galil);
    if(rtnCode == G_NO_ERROR)
    {
        this->connected = true;
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
        }
    }
    return this->connected;
}

bool GalilLink::isConnected() const
{
    return this->connected;
}


GReturn GalilLink::WriteTellErrorCode(char *errorDescription) const
{
    GSize read_bytes = 0; //bytes read in GCommand
    std::string newCommand = "TC 1";
    GReturn rtn = GCommand(galil,newCommand.c_str(),errorDescription,sizeof(errorDescription),&read_bytes);
    return rtn;
}

GReturn GalilLink::WriteCommand(AbstractCommand *command) const
{
    std::cout<<"We are trying to write a command here: "<<CommandToString(command->getCommandType())<<std::endl;

    std::string stringCommand = command->getCommandString();
    GReturn rtn = GCmd(galil,stringCommand.c_str());
    return rtn;
}

GReturn GalilLink::WriteRequest(AbstractRequest *request) const
{
    std::cout<<"We are trying to write a request here: "<<RequestToString(request->getRequestType())<<std::endl;

    char* buf = request->getBuffer(); //buffer to be allocated for the response
    GSize read_bytes = 0; //bytes read in GCommand

    std::string stringRequest = request->getRequestString();

    GReturn rtn = GCommand(galil,stringRequest.c_str(),buf,sizeof(buf),&read_bytes);
    return rtn;

//    switch (rtn) {
//    case G_NO_ERROR:
//    {
//        StatusGeneric status(request->getRequestType());
//        status.setReceivedBuffer(buf);
//        EmitEvent([&status](const ILinkEvents *ptr){ptr->StatusReceived(status);});
//        break;
//    }
//    case G_BAD_LOST_DATA:
//    {
//        break;
//    }
//    case G_BAD_RESPONSE_QUESTION_MARK:
//    {
//        handleBadRequestResponse(request->getRequestType());
//        break;
//    }
//    default:
//        break;
//    }
}



//void GalilLink::_readBytes(void)
//{
//    qint64 byteCount = m_port->bytesAvailable();
//    if (byteCount) {
//        QByteArray buffer;
//        buffer.resize(byteCount);
//        m_port->read(buffer.data(), buffer.size());

//        std::vector<uint8_t> vec_buffer = std::vector<uint8_t>(buffer.begin(), buffer.end());

//        EmitEvent([this,&vec_buffer](const ILinkEvents *ptr){ptr->ReceiveData(this, vec_buffer);});
//    }
//}

} //END MAVLINKComms