#ifndef STATUS_MOTOR_ENABLED_H
#define STATUS_MOTOR_ENABLED_H

#include <map>

#include "ACSC.h"

#include "common/class_forward.h"
#include "common/axis_definitions.h"
#include "common/data_get_set_notifier.h"

#include "status/abstract_status.h"

namespace SPII {

ECM_CLASS_FORWARD(Status_MotorPerAxis);
class Status_MotorPerAxis : public AbstractStatus
{
public:
    Status_MotorPerAxis();

    Status_MotorPerAxis(const Status_MotorPerAxis &copy);

    void setAxis(const MotorAxis &axis);
    MotorAxis getAxis() const;

    void updateMotorAxisStatus(const unsigned int &value);

    bool isMotorEnabled() const;
    bool hasMotorReachedTarget() const;
    bool isMotorMoving() const;
    bool isMotorAccelerating() const;


public:
    Status_MotorPerAxis& operator = (const Status_MotorPerAxis &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->currentAxis = rhs.currentAxis;
        this->isEnabled = rhs.isEnabled;
        this->hasReachedTarget = rhs.hasReachedTarget;
        this->isMoving = rhs.isMoving;
        this->isAccelerating = rhs.isAccelerating;
        return *this;
    }

    bool operator == (const Status_MotorPerAxis &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->currentAxis != rhs.currentAxis){
            return false;
        }
        if(this->isEnabled != rhs.isEnabled){
            return false;
        }
        if(this->hasReachedTarget != rhs.hasReachedTarget){
            return false;
        }
        if(this->isMoving != rhs.isMoving){
            return false;
        }
        if(this->isAccelerating != rhs.isAccelerating){
            return false;
        }
        return true;
    }

    bool operator != (const Status_MotorPerAxis &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis = MotorAxis::Z;
    bool isEnabled = false;
    bool hasReachedTarget = false;
    bool isMoving = false;
    bool isAccelerating = false;

};

ECM_CLASS_FORWARD(Status_Motor);
class Status_Motor : public AbstractStatus
{
public:
    Status_Motor() = default;

    void updateAxisStatus(const Status_MotorPerAxis &status);

    Status_MotorPerAxis* getAxisStatus(const MotorAxis &axis);

public:
    Status_Motor& operator = (const Status_Motor &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->m_MotorStatus = rhs.m_MotorStatus;
        return *this;
    }

    bool operator == (const Status_Motor &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->m_MotorStatus != rhs.m_MotorStatus){
            return false;
        }
        return true;
    }

    bool operator != (const Status_Motor &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<MotorAxis, DataGetSetNotifier<Status_MotorPerAxis>> m_MotorStatus;
};

}//end of namespace SPII

#endif // STATUS_MOTOR_ENABLED_H

