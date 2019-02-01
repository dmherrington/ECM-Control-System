#include "status_motor.h"

namespace SPII {

Status_MotorPerAxis::Status_MotorPerAxis():
    AbstractStatus(StatusTypes::STATUS_MOTOR)
{

}

Status_MotorPerAxis::Status_MotorPerAxis(const Status_MotorPerAxis &copy):
    AbstractStatus (copy)
{

}

void Status_MotorPerAxis::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

MotorAxis Status_MotorPerAxis::getAxis() const
{
    return this->currentAxis;
}

void Status_MotorPerAxis::updateMotorAxisStatus(const unsigned int &value)
{
    if(value & ACSC_MST_ENABLE)
        this->isEnabled = true;
    else
        this->isEnabled = false;

    if(value & ACSC_MST_INPOS)
        this->hasReachedTarget = true;
    else
        this->hasReachedTarget = false;

    if(value & ACSC_MST_MOVE)
        this->isMoving = true;
    else
        this->isMoving = false;

    if(value & ACSC_MST_ACC)
        this->isAccelerating = true;
    else
        this->isAccelerating = false;

}

bool Status_MotorPerAxis::isMotorEnabled() const
{
    return this->isEnabled;
}
bool Status_MotorPerAxis::hasMotorReachedTarget() const
{
    return this->hasReachedTarget;
}
bool Status_MotorPerAxis::isMotorMoving() const
{
    return this->isMoving;
}
bool Status_MotorPerAxis::isMotorAccelerating() const
{
    return this->isAccelerating;
}

void Status_Motor::updateAxisStatus(const Status_MotorPerAxis &status)
{
    m_MotorStatus.insert(std::pair<MotorAxis,Status_MotorPerAxis>(status.getAxis(),status));
}

Status_MotorPerAxis* Status_Motor::getAxisStatus(const MotorAxis &axis)
{

}

} //end of namespace SPII
