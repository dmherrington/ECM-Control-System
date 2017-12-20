#ifndef STATUS_POSITION_H
#define STATUS_POSITION_H

#include <map>

#include "common/environment_time.h"
#include <axis_definitions.h>

class Status_Position
{
public:
    Status_Position();

    Status_Position(const MotorAxis &axis, const Data::EnvironmentTime &time, const uint64_t &pos);

    Status_Position(const Status_Position &copy);

    void setPosition(const uint64_t &pos);
    void setTime(const Data::EnvironmentTime &time);

    MotorAxis getAxis() const;
    Data::EnvironmentTime getTime() const;
    uint64_t getPosition() const;

public:
    void operator = (const Status_Position &rhs)
    {
        this->currentAxis = rhs.currentAxis;
        this->position = rhs.position;
        this->latestUpdate = rhs.latestUpdate;
    }

    bool operator == (const Status_Position &rhs) {
        if(this->currentAxis != rhs.currentAxis){
            return false;
        }
        if(this->position != rhs.position){
            return false;
        }
        if(this->latestUpdate != rhs.latestUpdate){
            return false;
        }
        return true;
    }

    bool operator != (const Status_Position &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis;
    uint64_t position = 0;
    Data::EnvironmentTime latestUpdate;

};

#endif // STATUS_POSITION_H
