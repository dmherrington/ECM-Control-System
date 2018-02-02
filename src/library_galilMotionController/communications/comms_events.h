#ifndef COMMS_EVENTS_H
#define COMMS_EVENTS_H

#include <string>
#include "common/common.h"

#include "status/status_components.h"

namespace Comms
{

class CommsEvents
{
public:

    /////////////////////////////////////////////////////////
    /// Link Events
    /////////////////////////////////////////////////////////

    virtual void LinkConnected() const
    {

    }

    virtual void LinkDisconnected() const
    {

    }

    virtual void StatusMessage(const std::string &msg)
    {
        UNUSED(msg);
    }

    virtual void NewStatusInputs(const StatusInputs &status)
    {
        UNUSED(status);
    }

    virtual void NewStatusPosition(const Status_Position &status)
    {
        UNUSED(status);
    }

    virtual void NewStatusMotorEnabled(const Status_MotorEnabled &status)
    {
        UNUSED(status);
    }

    virtual void NewStatusMotorInMotion(const Status_AxisInMotion &status)
    {
        UNUSED(status);
    }

    virtual void NewStatusMotorStopCode(const Status_StopCode &status)
    {
        UNUSED(status);
    }

};

}

#endif // COMMS_EVENTS_H
