#ifndef COMMUNICATION_UPDATE_H
#define COMMUNICATION_UPDATE_H
#include <QMetaType>

#include "string"

namespace common {
namespace comms {

class CommunicationUpdate
{
public:
    CommunicationUpdate(const std::string &source = "", const int &status = 0, const std::string &msg = "")
    {
        this->sourceName = source;
        this->type = status;
        this->message = msg;
    }

    CommunicationUpdate(const CommunicationUpdate &copy)
    {
        this->sourceName = copy.sourceName;
        this->type = copy.type;
        this->message = copy.message;
    }

    ~CommunicationUpdate() = default;

public:
    void setSourceName(const std::string &source)
    {
        this->sourceName = source;
    }
    void setUpdateType(const int &status)
    {
        this->type = status;
    }
    void setPeripheralMessage(const std::string &msg)
    {
        this->message = msg;
    }

public:
    std::string getSourceName() const
    {
        return this->sourceName;
    }
    int getUpdateType() const
    {
        return this->type;
    }
    std::string getPeripheralMessage() const
    {
        return this->message;
    }

public:
    CommunicationUpdate& operator = (const CommunicationUpdate &rhs)
    {
        this->sourceName = rhs.sourceName;
        this->type = rhs.type;
        this->message = rhs.message;
        return *this;
    }

private:
    std::string sourceName;
    int type;
    std::string message;
};

} //end of namespace comms
} //end of namespace common

Q_DECLARE_METATYPE(common::comms::CommunicationUpdate)
#endif // COMMUNICATION_UPDATE_H
