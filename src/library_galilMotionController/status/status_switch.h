#ifndef STATUS_SWITCH_H
#define STATUS_SWITCH_H

#include <map>

#include <axis_definitions.h>
#include "status/abstract_status.h"

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

class Status_Switch : public AbstractStatus
{
public:
    Status_Switch();

    Status_Switch(const MotorAxis &axis, const int &code);

    Status_Switch(const Status_Switch &copy);

    void setAxis(const MotorAxis &axis);
    void setSwitchCode(const int &code);

    MotorAxis getAxis() const;
    int getCode() const;
    bool getSwitchStatus(const SwitchStatus &bit) const;

private:
    void initializeMap();
    void parseInt(const uint8_t &value);

public:
    Status_Switch& operator = (const Status_Switch &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->currentAxis = rhs.currentAxis;
        this->originalCode = rhs.originalCode;
        this->mapStatus = rhs.mapStatus;
        return *this;
    }

    bool operator == (const Status_Switch &rhs) {
        if(!AbstractStatus::operator ==(rhs)){
            return false;
        }
        if(this->currentAxis != rhs.currentAxis){
            return false;
        }
        if(this->originalCode != rhs.originalCode){
            return false;
        }
        if(this->mapStatus != rhs.mapStatus){
            return false;
        }
        return true;
    }

    bool operator != (const Status_Switch &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis = MotorAxis::Z;
    int originalCode = 0;
    std::map<SwitchStatus,bool> mapStatus;
};

#endif // STATUS_SWITCH_H
