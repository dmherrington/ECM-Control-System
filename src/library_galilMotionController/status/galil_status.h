#ifndef GALIL_STATUS_H
#define GALIL_STATUS_H

#include <string>
#include <map>
#include <vector>

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

    std::vector<std::string> currentLabels;
    std::vector<std::string> currentVariables;
};

#endif // GALIL_STATUS_H
