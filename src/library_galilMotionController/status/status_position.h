#ifndef STATUS_POSITION_H
#define STATUS_POSITION_H

#include <map>

#include "common/class_forward.h"
#include "common/environment_time.h"
#include <axis_definitions.h>
#include "status/abstract_status.h"

ECM_CLASS_FORWARD(Status_Position);
class Status_Position : public AbstractStatus
{
public:
    Status_Position();

    Status_Position(const MotorAxis &axis, const Data::EnvironmentTime &time, const uint64_t &pos);

    Status_Position(const Status_Position &copy);

    void parseGalilString(const std::string &str);

    void setAxis(const MotorAxis &axis);
    void setPosition(const uint64_t &pos);
    void setTime(const Data::EnvironmentTime &time);

    MotorAxis getAxis() const;
    Data::EnvironmentTime getTime() const;
    uint64_t getPosition() const;

public:
    void operator = (const Status_Position &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->currentAxis = rhs.currentAxis;
        this->position = rhs.position;
        this->latestUpdate = rhs.latestUpdate;
    }

    bool operator == (const Status_Position &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
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
