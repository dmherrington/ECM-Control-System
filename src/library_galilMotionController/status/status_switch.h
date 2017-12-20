#ifndef STATUS_SWITCH_H
#define STATUS_SWITCH_H

#include <map>

#include "common/environment_time.h"
#include <axis_definitions.h>

enum SwitchStatus{
    POSLAT = 0,
    HOME_SW = 1,
    RLIMIT = 2,
    FLIMIT = 3,
    RESERVED = 4,
    MOTOR_OFF = 5,
    POSITION_ERROR = 6,
    AXIS_IN_MOTION = 7
};

class Status_Switch
{
public:
    Status_Switch();

    Status_Switch(const MotorAxis &axis, const int &code);

    Status_Switch(const MotorAxis &axis, const Data::EnvironmentTime &time, const int &code);

    Status_Switch(const Status_Switch &copy);

    void setAxis(const MotorAxis &axis);
    void setSwitchCode(const int &code);
    void setTime(const Data::EnvironmentTime &time);

    MotorAxis getAxis() const;
    Data::EnvironmentTime getTime() const;
    int getCode() const;
    bool getSwitchStatus(const SwitchStatus &bit) const;

private:
    void initializeMap();
    void parseInt(const uint8_t &value);

public:
    void operator = (const Status_Switch &rhs)
    {
        this->currentAxis = rhs.currentAxis;
        this->originalCode = rhs.originalCode;
        this->mapStatus = rhs.mapStatus;
        this->latestUpdate = rhs.latestUpdate;
    }

    bool operator == (const Status_Switch &rhs) {
        if(this->currentAxis != rhs.currentAxis){
            return false;
        }
        if(this->originalCode != rhs.originalCode){
            return false;
        }
        if(this->mapStatus != rhs.mapStatus){
            return false;
        }
        if(this->latestUpdate != rhs.latestUpdate){
            return false;
        }
        return true;
    }

    bool operator != (const Status_Switch &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis;
    int originalCode;
    std::map<SwitchStatus,bool> mapStatus;
    Data::EnvironmentTime latestUpdate;
};

#endif // STATUS_SWITCH_H
