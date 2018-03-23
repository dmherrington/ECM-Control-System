#ifndef ABSTRACT_RIGOL_STATUS_H
#define ABSTRACT_RIGOL_STATUS_H

#include <string.h>

#include "library_rigol_oscilloscope_global.h"

#include "common/class_forward.h"
#include "common/environment_time.h"

#include "data/type_available_commands.h"


namespace commands_Rigol {

using namespace data_Rigol;
ECM_CLASS_FORWARD(AbstractRigolStatus);

class AbstractRigolStatus
{
public:
    AbstractRigolStatus(const std::string &name, const CommandTypes &type);

    AbstractRigolStatus(const AbstractRigolStatus &copy);

    void setDeviceName(const std::string &name);
    std::string getDeviceName() const;

    void setCommandType(const CommandTypes &type);
    CommandTypes getCommandType() const;

    void updateMeasurementTime();
    common::EnvironmentTime getMeasurementTime() const;

    void updateReceivedTime();
    common::EnvironmentTime getRequestTime() const;
    common::EnvironmentTime getReceivedTime() const;


public:
    /**
     *
     */
    template <class T>
    const T *as() const
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<const T *>(this);
    }

    /**
     *
     */
    template <class T>
    T *as()
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<T *>(this);
    }
public:
    AbstractRigolStatus& operator = (const AbstractRigolStatus &rhs)
    {
        this->deviceName = rhs.deviceName;
        this->commandType = rhs.commandType;
        this->measurementTime = rhs.measurementTime;
        this->requestTime = rhs.requestTime;
        this->receivedTime = rhs.receivedTime;
        return *this;
    }

    bool operator == (const AbstractRigolStatus &rhs) {
        if(this->deviceName != rhs.deviceName){
            return false;
        }
        if(this->commandType != rhs.commandType){
            return false;
        }
        return true;
    }

    bool operator != (const AbstractRigolStatus &rhs) {
        return !(*this == rhs);
    }

private:
    std::string deviceName = "Rigol";
    CommandTypes commandType;
    common::EnvironmentTime measurementTime;
    common::EnvironmentTime requestTime;
    common::EnvironmentTime receivedTime;
};

} //end of namespace commands


#endif // ABSTRACT_RIGOL_STATUS_H
