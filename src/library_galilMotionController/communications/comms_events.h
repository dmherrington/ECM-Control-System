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

    virtual void NewStatusPosition(const Status_Position &status)
    {
        UNUSED(status);
    }
};

}

#endif // COMMS_EVENTS_H
