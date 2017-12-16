#ifndef GALIL_INTERFACE_H
#define GALIL_INTERFACE_H

#include "commands/command_components.h"
#include "status/galil_status.h"

class GalilInterface
{
public:
    GalilInterface();

    void transmitMessage(const std::string &msg);

    void transmitMessage(const AbstractCommand* cmd);

public:
    GalilStatus status;
};

#endif // GALIL_INTERFACE_H
