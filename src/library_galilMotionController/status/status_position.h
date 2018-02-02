#ifndef STATUS_POSITION_H
#define STATUS_POSITION_H

#include <map>

#include "common/class_forward.h"

#include <axis_definitions.h>
#include "status/abstract_status.h"

ECM_CLASS_FORWARD(Status_Position);
class Status_Position : public AbstractStatus
{
public:
    Status_Position();

    Status_Position(const Status_Position &copy);

    void parseGalilString(const std::string &str);

    void setAxis(const MotorAxis &axis);
    void setPosition(const uint64_t &pos);

    MotorAxis getAxis() const;
    uint64_t getPosition() const;

public:
    Status_Position& operator = (const Status_Position &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->currentAxis = rhs.currentAxis;
        this->position = rhs.position;
        return *this;
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
        return true;
    }

    bool operator != (const Status_Position &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis = MotorAxis::Z;
    uint64_t position = 0;

};

#endif // STATUS_POSITION_H
