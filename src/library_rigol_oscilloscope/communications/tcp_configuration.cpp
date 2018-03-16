#include "tcp_configuration.h"

namespace comms_Rigol {

TCPConfiguration::TCPConfiguration()
{
    _listenAddress       = "127.0.0.1";
    _listenPortNumber    = 5555;
}
TCPConfiguration::TCPConfiguration(const std::string& listenAddress, const int &listenPort)
{
    _listenAddress       = listenAddress;
    _listenPortNumber    = listenPort;
}

TCPConfiguration::~TCPConfiguration()
{

}

TCPConfiguration::TCPConfiguration(const std::string& listenAddress, const int &listenPort, const std::string& senderAddress, const int &senderPort)
{
    _listenAddress       = listenAddress;
    _listenPortNumber    = listenPort;
    _senderAddress       = senderAddress;
    _senderPortNumber    = senderPort;
}

TCPConfiguration::TCPConfiguration(TCPConfiguration* copy)
{
    _listenAddress       = copy->listenAddress();
    _listenPortNumber    = copy->listenPortNumber();
    _senderAddress       = copy->senderAddress();
    _senderPortNumber    = copy->senderPortNumber();
}

void TCPConfiguration::copyFrom(LinkConfiguration* source)
{
    LinkConfiguration::copyFrom(source);
    TCPConfiguration* ssource = dynamic_cast<TCPConfiguration*>(source);
    Q_ASSERT(ssource != NULL);
    _listenAddress               = ssource->listenAddress();
    _listenPortNumber            = ssource->listenPortNumber();
    _senderAddress               = ssource->senderAddress();
    _senderPortNumber            = ssource->senderPortNumber();
}

void TCPConfiguration::setListenAddress(std::string address)
{
    _listenAddress = address;
}

void TCPConfiguration::setListenPortNumber(int portNumber)
{
    _listenPortNumber = portNumber;
}

void TCPConfiguration::setSenderAddress(std::string address)
{
    _senderAddress = address;
}

void TCPConfiguration::setSenderPortNumber(int portNumber)
{
    _senderPortNumber = portNumber;
}

} //end of namepsace comms_Rigol

