#ifndef NOTIFICATION_UPDATE_H
#define NOTIFICATION_UPDATE_H

#include <QMetaType>

#include "string"

#include "ecm_devices.h"
#include "environment_time.h"

namespace common {

class NotificationUpdate
{
public:
    enum class NotificationTypes
    {
        NOTIFICATION_GENERAL,
        NOTIFICATION_ALERT,
        NOTIFICATION_ERROR
    };

public:
    NotificationUpdate(const std::string &source = "", const ECMDevice &sourceType = ECMDevice::DEVICE_UNKNOWN, const NotificationTypes &status = NotificationTypes::NOTIFICATION_GENERAL, const std::string &msg = "")
    {
        common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,time);
        this->sourceName = source;
        this->sourceType = sourceType;
        this->type = status;
        this->message = msg;
    }

    NotificationUpdate(const NotificationUpdate &copy)
    {
        this->time = copy.time;
        this->sourceName = copy.sourceName;
        this->sourceType = copy.sourceType;
        this->type = copy.type;
        this->message = copy.message;
    }

    ~NotificationUpdate() = default;

public:
    void setSourceName(const std::string &source)
    {
        this->sourceName = source;
    }
    void setSourceType(const ECMDevice &type)
    {
        this->sourceType = type;
    }
    void setUpdateType(const NotificationTypes &status)
    {
        this->type = status;
    }
    void setPeripheralMessage(const std::string &msg)
    {
        this->message = msg;
    }

public:
    EnvironmentTime getNotificationTime() const
    {
        return this->time;
    }
    std::string getSourceName() const
    {
        return this->sourceName;
    }
    ECMDevice getSourceType() const
    {
        return this->sourceType;
    }
    NotificationTypes getUpdateType() const
    {
        return this->type;
    }
    std::string getPeripheralMessage() const
    {
        return this->message;
    }

public:
    NotificationUpdate& operator = (const NotificationUpdate &rhs)
    {
        this->time = rhs.time;
        this->sourceName = rhs.sourceName;
        this->sourceType = rhs.sourceType;
        this->type = rhs.type;
        this->message = rhs.message;
        return *this;
    }

private:
    EnvironmentTime time;
    std::string sourceName;
    ECMDevice sourceType;
    NotificationTypes type;
    std::string message;

};

} //end of namespace common

Q_DECLARE_METATYPE(common::NotificationUpdate)

#endif // NOTIFICATION_UPDATE_H
