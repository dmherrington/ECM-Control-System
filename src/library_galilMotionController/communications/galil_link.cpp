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
    Disconnect();

}

void GalilLink::handleBadCommandResponse(const CommandType &type) const
{
    GReturn rtn = G_BAD_RESPONSE_QUESTION_MARK;
    GSize read_bytes = 0; //bytes read in GCommand
    int attempts = 0;
    char error[100];
    while ((rtn == G_NO_ERROR) && (attempts < 5)) {
        std::string newCommand = "TC 1";
        rtn = GCommand(galil,newCommand.c_str(),error,sizeof(error),&read_bytes);
        attempts++;
    }

    if(rtn == G_NO_ERROR)
    {
//        StatusGeneric status(type);
//        status.setReceivedBuffer(error);
//        EmitEvent([](const ILinkEvents *ptr){ptr->BadCommandResponse(status);});
    }
    else{
        //std::cout<"GalilLink handleBadStatusResponse has seen an unknown rtn type when requesting the error"<<std::endl;
    }
}

void GalilLink::handleBadRequestResponse(const RequestTypes &type) const
{
    GReturn rtn = G_BAD_RESPONSE_QUESTION_MARK;
    GSize read_bytes = 0; //bytes read in GCommand
    int attempts = 0;
    char error[100];
    while ((rtn == G_NO_ERROR) && (attempts < 5)) {
        std::string newCommand = "TC 1";
        rtn = GCommand(galil,newCommand.c_str(),error,sizeof(error),&read_bytes);
        attempts++;
    }

    if(rtn == G_NO_ERROR)
    {
        StatusGeneric status(type);
        status.setReceivedBuffer(error);
        EmitEvent([&status](const ILinkEvents *ptr){ptr->BadRequestResponse(status);});
    }
    else{
        //std::cout<"GalilLink handleBadStatusResponse has seen an unknown rtn type when requesting the error"<<std::endl;
    }
}

void GalilLink::WriteCommand(AbstractCommand *command) const
{
    std::cout<<"We are trying to write a command here: "<<CommandToString(command->getCommandType())<<std::endl;

    std::string stringCommand = command->getCommandString();
    GReturn rtn = GCmd(galil,stringCommand.c_str());

    switch (rtn) {
    case G_NO_ERROR:
    {

        break;
    }
    case G_BAD_LOST_DATA:
    {
        break;
    }
    case G_BAD_RESPONSE_QUESTION_MARK:
    {
        handleBadCommandResponse(command->getCommandType());
        break;
    }
    default:
        break;
    }
}

void GalilLink::WriteRequest(AbstractRequest *request) const
{
    std::cout<<"We are trying to write a request here: "<<RequestToString(request->getRequestType())<<std::endl;

    char* buf; //buffer to be allocated for the response
    GSize read_bytes = 0; //bytes read in GCommand

    std::string stringRequest = request->getRequestString();

    request->getBuffer(buf);
    GReturn rtn = GCommand(galil,stringRequest.c_str(),buf,sizeof(buf),&read_bytes);

    switch (rtn) {
    case G_NO_ERROR:
    {
        StatusGeneric status(request->getRequestType());
        status.setReceivedBuffer(buf);
        EmitEvent([&status](const ILinkEvents *ptr){ptr->StatusReceived(status);});
        break;
    }
    case G_BAD_LOST_DATA:
    {
        break;
    }
    case G_BAD_RESPONSE_QUESTION_MARK:
    {
        handleBadRequestResponse(request->getRequestType());
        break;
    }
    default:
        break;
    }
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
    //We should attempt connecting to the Galil unit at the prescribed address
    GReturn rtnCode = GOpen(galilAddress.c_str(),&galil);

    switch (rtnCode) {
    case G_NO_ERROR:
        EmitEvent([](const ILinkEvents *ptr){ptr->ConnectionOpened();});
        break;
    case G_BAD_ADDRESS:
        break;
    case G_GCLIB_ERROR:
        break;
    case G_OPEN_ERROR:
        break;
    default:
        break;
    }

}

void GalilLink::Disconnect(void)
{
    GReturn rtnCode = GClose(galil);

    switch (rtnCode) {
    case G_NO_ERROR:
        EmitEvent([](const ILinkEvents *ptr){ptr->ConnectionClosed();});
        break;
    case G_GCLIB_ERROR:
        break;
    default:
        break;
    }

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
