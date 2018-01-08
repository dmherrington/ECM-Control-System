#ifndef GALIL_STATE_INTERFACE_H
#define GALIL_STATE_INTERFACE_H

#include <iostream>
#include <map>

#include "gclib.h"
#include "gclibo.h"

#include "axis_definitions.h"

#include "programs/program_interface.h"

#include "commands/command_components.h"
#include "requests/request_components.h"
#include "status/status_components.h"

#include "communications/comms_marshaler.h"


class GalilStateInterface
{
public:
    GalilStateInterface(const std::vector<MotorAxis> &availableAxis);

    ~GalilStateInterface();

public:
    GalilStatus* getAxisStatus(const MotorAxis &axis);
    StatusInputs* getStatusInputs() const;

public:
    void transmitMessage(const std::string &msg);

    void transmitCommand(const AbstractCommand* cmd);

    void transmitRequest(const AbstractRequest* req);

    bool isMotorInMotion() const;
    bool isMotorArmed() const;


public:
    void updatePosition(const std::vector<Status_Position> &data);

public:
    bool isConnected();
    bool isLatched();

public:
    void setConnected(const bool &val);
    void setLatched(const bool &val);

private:
    bool connected = false;
    bool latched = false;


public:
    Comms::CommsMarshaler* commsMarshaler; /**< Member variable handling the communications with the
actual Galil unit. This parent class will be subscribing to published events from the marshaller. This
should drive the event driven structure required to exceite the state machine.*/

private:

    StatusInputs* statusInputs; /**< Member variable containing the current state
inputs of the Galil Unit. Only specific inputs are relevant within the request. Relevant
inputs are established through the settings file.*/

    std::map<MotorAxis, GalilStatus*> mStatus; /**< Member variable containing the current status
of each individual axis of the galil. This information contains positioning, motion, arming. */

    ProgramInterface* galilProgram; /**< Member variable containing the current program, labels,
and variables actually aboard the galil. This can be used as a comparison for determining if the
current program matches what the user witnesses. Also, this can be used to restore the current state
of the program.*/

};

#endif // GALIL_STATE_INTERFACE_H
