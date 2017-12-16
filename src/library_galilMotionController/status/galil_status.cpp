#include "galil_status.h"

GalilStatus::GalilStatus()
{

}

bool GalilStatus::isAxisinMotion()
{
    return axisMoving;
}

bool GalilStatus::isMotorRunning()
{
    return motorRunning;
}
