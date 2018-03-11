#ifndef COMMUNICATION_CONNECTION_H
#define COMMUNICATION_CONNECTION_H

#include <QMetaType>

#include "string"

namespace common {
namespace comms {

class CommunicationConnection
{
public:
    CommunicationConnection(const std::string &source = "", const bool &connection = false)
    {
        this->sourceName = source;
        this->connected = connection;
    }

    CommunicationConnection(const CommunicationConnection &copy)
    {
        this->sourceName = copy.sourceName;
        this->connected = copy.connected;
    }

    ~CommunicationConnection() = default;

public:
    void setSourceName(const std::string &source)
    {
        this->sourceName = source;
    }
    void setConnection(const bool &connection)
    {
        this->connected = connection;
    }

public:
    std::string getSourceName() const
    {
        return this->sourceName;
    }
    bool isConnected() const
    {
        return this->connected;
    }

public:
    CommunicationConnection& operator = (const CommunicationConnection &rhs)
    {
        this->sourceName = rhs.sourceName;
        this->connected = rhs.connected;
        return *this;
    }

private:
    std::string sourceName;
    bool connected = false;
};

} //end of namespace comms
} //end of namespace common

Q_DECLARE_METATYPE(common::comms::CommunicationConnection)

#endif // COMMUNICATION_CONNECTION_H
