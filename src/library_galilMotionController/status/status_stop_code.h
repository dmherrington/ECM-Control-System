#ifndef STATUS_STOP_CODE_H
#define STATUS_STOP_CODE_H

#include <map>

#include "common/environment_time.h"
#include <axis_definitions.h>

class Status_StopCode
{
public:
    Status_StopCode();

    Status_StopCode(const MotorAxis &axis, const int &code);

    Status_StopCode(const MotorAxis &axis, const Data::EnvironmentTime &time, const int &code);

    Status_StopCode(const Status_StopCode &copy);

    void setAxis(const MotorAxis &axis);
    void setStopCode(const int &code);
    void setTime(const Data::EnvironmentTime &time);

    MotorAxis getAxis() const;
    Data::EnvironmentTime getTime() const;
    int getCode() const;

public:
    void operator = (const Status_StopCode &rhs)
    {
        this->currentAxis = rhs.currentAxis;
        this->stopCode = rhs.stopCode;
        this->latestUpdate = rhs.latestUpdate;
    }

    bool operator == (const Status_StopCode &rhs) {
        if(this->currentAxis != rhs.currentAxis){
            return false;
        }
        if(this->stopCode != rhs.stopCode){
            return false;
        }
        if(this->latestUpdate != rhs.latestUpdate){
            return false;
        }
        return true;
    }

    bool operator != (const Status_StopCode &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis;
    int stopCode = 0;
    Data::EnvironmentTime latestUpdate;
};

#endif // STATUS_STOP_CODE_H
