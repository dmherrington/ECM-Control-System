#ifndef TCP_CONFIGURATION_H
#define TCP_CONFIGURATION_H

#include <QTcpSocket>
#include <string>

#include "library_rigol_oscilloscope_global.h"

#include "rigol_link_configuration.h"


namespace rigol{
namespace comms{

class TCPConfiguration : public LinkConfiguration
{
public:
    TCPConfiguration();
    TCPConfiguration(const std::string &listenAddress, const int &listenPort);
    TCPConfiguration(const std::string& listenAddress, const int &listenPort, const std::string& senderAddress, const int &senderPort);
    TCPConfiguration(TCPConfiguration* copy);

    // Destructor
    ~TCPConfiguration();

    int listenPortNumber() const { return _listenPortNumber; }
    const std::string listenAddress() const { return _listenAddress; }
    int senderPortNumber() const { return _senderPortNumber; }
    const std::string senderAddress() const { return _senderAddress; }

    void setListenPortNumber(int portNumber);
    void setListenAddress(std::string address);
    void setSenderPortNumber(int portNumber);
    void setSenderAddress(std::string address);

    /// From LinkConfiguration
    void        copyFrom        (LinkConfiguration* source);

private:
    int _listenPortNumber;
    std::string _listenAddress;
    int _senderPortNumber;
    std::string _senderAddress;

    QTcpSocket *m_socket;
};

} //end of namepsace comms
} //end of namespace rigol

#endif // TCP_CONFIGURATION_H
