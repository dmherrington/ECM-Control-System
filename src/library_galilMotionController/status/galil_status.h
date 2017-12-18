#ifndef GALIL_STATUS_H
#define GALIL_STATUS_H

#include <string>
#include <map>
#include <vector>

#include <axis_definitions.h>

class GalilStatus
{
public:
    GalilStatus();

public:
    bool isMotorRunning() const;

    bool isAxisinMotion() const;

    bool isLatchSet() const;

private:
    bool motorRunning = false;
    bool axisMoving = false;
    bool latchSet = false;

    std::map<MotorAxis,double> currentPosition;
    std::vector<std::string> currentLabels;
    std::vector<std::string> currentVariables;
};

#endif // GALIL_STATUS_H
