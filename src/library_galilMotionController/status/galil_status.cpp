#include "galil_status.h"

GalilStatus::GalilStatus()
{

}

bool GalilStatus::isAxisinMotion() const
{
    return axisMoving;
}

bool GalilStatus::isMotorRunning() const
{
    return motorRunning;
}

bool GalilStatus::isLatchSet() const
{
    return latchSet;
}
