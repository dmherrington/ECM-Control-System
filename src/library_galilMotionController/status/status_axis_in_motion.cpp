#include "status_axis_in_motion.h"

Status_AxisInMotion::Status_AxisInMotion():
    AbstractStatus(StatusTypes::STATUS_MOTOREN)
{
    this->currentAxis = MotorAxis::Z;
    this->isInMotion = false;
}

Status_AxisInMotion::Status_AxisInMotion(const Status_AxisInMotion &copy):
    AbstractStatus(copy)
{
    this->currentAxis = copy.currentAxis;
    this->isInMotion = copy.isInMotion;
}

void Status_AxisInMotion::parseGalilString(const std::string &str)
{

}

void Status_AxisInMotion::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

MotorAxis Status_AxisInMotion::getAxis() const
{
    return this->currentAxis;
}

void Status_AxisInMotion::setMotorMoving(const bool &motion)
{
    this->isInMotion = motion;
}

bool Status_AxisInMotion::isMotorMoving() const
{
    return this->isInMotion;
}
