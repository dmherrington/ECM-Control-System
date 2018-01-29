#ifndef STATUS_AXIS_IN_MOTION_H
#define STATUS_AXIS_IN_MOTION_H

#include <axis_definitions.h>
#include "status/abstract_status.h"
#include "common/class_forward.h"

ECM_CLASS_FORWARD(Status_AxisInMotion);
class Status_AxisInMotion : public AbstractStatus
{
public:
    Status_AxisInMotion();

    Status_AxisInMotion(const Status_AxisInMotion &copy);

    void parseGalilString(const std::string &str);

    void setAxis(const MotorAxis &axis);
    MotorAxis getAxis() const;

    void setMotorMoving(const bool &motion);
    bool isMotorMoving() const;

public:
    Status_AxisInMotion& operator = (const Status_AxisInMotion &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->currentAxis = rhs.currentAxis;
        this->isInMotion = rhs.isInMotion;
        return *this;
    }

    bool operator == (const Status_AxisInMotion &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->currentAxis != rhs.currentAxis){
            return false;
        }
        if(this->isInMotion != rhs.isInMotion){
            return false;
        }
        return true;
    }

    bool operator != (const Status_AxisInMotion &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis = MotorAxis::Z;
    bool isInMotion = 0;

};

#endif // STATUS_AXIS_IN_MOTION_H
