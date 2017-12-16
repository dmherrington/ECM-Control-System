#ifndef GALIL_STATUS_H
#define GALIL_STATUS_H

#include <map>

class GalilStatus
{
public:
    GalilStatus();

public:
    bool isMotorRunning();

    bool isAxisinMotion();

private:
    bool motorRunning = false;
    bool axisMoving = false;
};

#endif // GALIL_STATUS_H
