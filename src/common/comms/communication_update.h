#ifndef COMMUNICATION_UPDATE_H
#define COMMUNICATION_UPDATE_H

#include <QMetaType>

#include "../ecm_devices.h"

#include "string"

namespace common {
namespace comms {

class CommunicationUpdate
{
public:
    enum class UpdateTypes
    {
        CONNECTED,
        DISCONNECTED,
        UPDATE,
        ALERT
    };

public:
    CommunicationUpdate(const std::string &source = "", const UpdateTypes &status = UpdateTypes::UPDATE, const std::string &msg = "")
    {
        this->sourceName = source;
        this->updateType = status;
        this->message = msg;
    }

    CommunicationUpdate(const CommunicationUpdate &copy)
    {
        this->sourceName = copy.sourceName;
        this->deviceType = copy.deviceType;
        this->updateType = copy.updateType;
        this->message = copy.message;
    }

    ~CommunicationUpdate() = default;

public:
    void setSourceName(const std::string &source)
    {
        this->sourceName = source;
    }

    void setDeviceType(const ECMDevice &device)
    {
        this->deviceType = device;
    }

    void setUpdateType(const UpdateTypes &status)
    {
        this->updateType = status;
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

    ECMDevice getDeviceType() const
    {
        return this->deviceType;
    }

    UpdateTypes getUpdateType() const
    {
        return this->updateType;
    }

    std::string getPeripheralMessage() const
    {
        return this->message;
    }

public:
    CommunicationUpdate& operator = (const CommunicationUpdate &rhs)
    {
        this->sourceName = rhs.sourceName;
        this->deviceType = rhs.deviceType;
        this->updateType = rhs.updateType;
        this->message = rhs.message;
        return *this;
    }

private:
    std::string sourceName;
    ECMDevice deviceType;
    UpdateTypes updateType;
    std::string message;

};

} //end of namespace comms
} //end of namespace common

Q_DECLARE_METATYPE(common::comms::CommunicationUpdate)
#endif // COMMUNICATION_UPDATE_H
