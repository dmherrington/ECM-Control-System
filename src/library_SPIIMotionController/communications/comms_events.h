#ifndef COMMS_EVENTS_SPII_H
#define COMMS_EVENTS_SPII_H

#include <string>
#include "common/common.h"

#include "common/comms/communication_update.h"

namespace Comms
{

class CommsEvents
{

public:
    CommsEvents() = default;
    virtual ~CommsEvents() = default;

public:

    /////////////////////////////////////////////////////////
    /// Link Events
    /////////////////////////////////////////////////////////

    virtual void LinkConnectionUpdate(const common::comms::CommunicationUpdate &update)
    {
        UNUSED(update);
    }

    virtual void CustomUserRequestReceived(const std::string &request, const std::string &response)
    {
        UNUSED(request);
        UNUSED(response);
    }

};

}

#endif // COMMS_EVENTS_SPII_H
