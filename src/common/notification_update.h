#ifndef NOTIFICATION_UPDATE_H
#define NOTIFICATION_UPDATE_H


#include <QMetaType>

#include "string"

#include "../ecm_devices.h"

namespace common {
namespace comms {

class NotificationUpdate
{
public:
    enum class UpdateTypes
    {
        NOTIFICATION,
        ALERT,
        ERROR
    };

public:
    CommunicationUpdate(const std::string &source = "", const ECMDevice &sourceType = ECMDevice::DEVICE_UNKNOWN, const UpdateTypes &status = UpdateTypes::NOTIFICATION, const std::string &msg = "")
    {
        this->sourceName = source;
        this->sourceType = sourceType;
        this->type = status;
        this->message = msg;
    }

    CommunicationUpdate(const NotificationUpdate &copy)
    {
        this->sourceName = copy.sourceName;
        this->sourceType = copy.sourceType;
        this->type = copy.type;
        this->message = copy.message;
    }

    ~CommunicationUpdate() = default;

public:
    void setSourceName(const std::string &source)
    {
        this->sourceName = source;
    }
    void setSourceType(const ECMDevice &type)
    {
        this->sourceType = type;
    }
    void setUpdateType(const UpdateTypes &status)
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
    ECMDevice getSourceType() const
    {
        return this->sourceType;
    }
    UpdateTypes getUpdateType() const
    {
        return this->type;
    }
    std::string getPeripheralMessage() const
    {
        return this->message;
    }

public:
    CommunicationUpdate& operator = (const NotificationUpdate &rhs)
    {
        this->sourceName = rhs.sourceName;
        this->sourceType = rhs.sourceType;
        this->type = rhs.type;
        this->message = rhs.message;
        return *this;
    }

private:
    std::string sourceName;
    ECMDevice sourceType;
    UpdateTypes type;
    std::string message;

};

} //end of namespace comms
} //end of namespace common

Q_DECLARE_METATYPE(common::comms::NotificationUpdate)

#endif // NOTIFICATION_UPDATE_H
