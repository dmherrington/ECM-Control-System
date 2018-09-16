#ifndef ERROR_UPDATE_H
#define ERROR_UPDATE_H

#include <QMetaType>

#include "../ecm_devices.h"

#include "string"

namespace common {

class ErrorUpdate
{
public:
    enum class UpdateTypes
    {
        WARNING,
        ALERT,
        CRITICAL
    };

public:
    ErrorUpdate(const std::string &source = "", const ECMDevice &device = ECMDevice::DEVICE_UNKNOWN,
                const UpdateTypes &status = UpdateTypes::WARNING, const std::string &msg = "")
    {
        this->sourceName = source;
        this->deviceType = device;
        this->updateType = status;
        this->message = msg;
    }

    ErrorUpdate(const ErrorUpdate &copy)
    {
        this->sourceName = copy.sourceName;
        this->deviceType = copy.deviceType;
        this->updateType = copy.updateType;
        this->message = copy.message;
    }

    ~ErrorUpdate() = default;

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
    CommunicationUpdate& operator = (const ErrorUpdate &rhs)
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

} //end of namespace common

Q_DECLARE_METATYPE(common::ErrorUpdate)

#endif // ERROR_UPDATE_H
