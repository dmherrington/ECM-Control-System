#include "galil_status.h"

GalilStatus::GalilStatus(const MotorAxis &axis):
    currentAxis(axis)
{
    this->axisMoving.set(false);
    this->motorRunning.set(false);
}

bool GalilStatus::isAxisinMotion() const
{
    return axisMoving.get();
}

bool GalilStatus::setMotorEnabled(const bool &isRunning)
{
    return motorRunning.set(isRunning);
}

bool GalilStatus::setMotorMoving(const bool &isMoving)
{
    return axisMoving.set(isMoving);
}

bool GalilStatus::isMotorEnabled() const
{
    return motorRunning.get();
}

Status_Position GalilStatus::getPosition() const
{
    return this->position.get();
}

void GalilStatus::setPosition(const Status_Position &pos)
{
    this->position.set(pos);
}
