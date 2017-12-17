#ifndef GALIL_INTERFACE_H
#define GALIL_INTERFACE_H

#include <iostream>
#include <map>

#include "axis_definitions.h"

#include "commands/command_components.h"
#include "status/galil_status.h"

class GalilInterface
{
public:
    GalilInterface();

    ~GalilInterface();

public:
    GalilStatus* getAxisStatus(const MotorAxis &axis);

public:
    void transmitMessage(const std::string &msg);

    void transmitMessage(const AbstractCommand* cmd);

private:
    std::map<MotorAxis, GalilStatus*> mStatus;
};

#endif // GALIL_INTERFACE_H
