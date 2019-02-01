#ifndef STATUS_AXIS_IN_MOTION_H
#define STATUS_AXIS_IN_MOTION_H

#include "ACSC.h"

#include <common/axis_definitions.h>
#include "status/abstract_status.h"
#include "common/class_forward.h"

namespace SPII{

ECM_CLASS_FORWARD(Status_PerAxis);
class Status_PerAxis : public AbstractStatus
{
public:
    Status_PerAxis();

    Status_PerAxis(const Status_PerAxis &copy);

    void setAxis(const MotorAxis &axis);
    MotorAxis getAxis() const;

    void setMotorMoving(const bool &moving);
    bool isMotorMoving() const;

public:
    Status_PerAxis& operator = (const Status_PerAxis &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->currentAxis = rhs.currentAxis;
        this->moving = rhs.moving;
        return *this;
    }

    bool operator == (const Status_PerAxis &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->currentAxis != rhs.currentAxis){
            return false;
        }
        if(this->moving != rhs.moving){
            return false;
        }
        return true;
    }

    bool operator != (const Status_PerAxis &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis = MotorAxis::Z;
    bool moving = false;
};



}//end of namespace SPII

#endif // STATUS_AXIS_IN_MOTION_H
