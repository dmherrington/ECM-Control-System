#ifndef I_LINK_EVENTS_SPII_H
#define I_LINK_EVENTS_SPII_H

#include "ACSC.h"

#include "common/comms/communication_update.h"

namespace Comms
{

class ILinkEvents
{

public:
    ILinkEvents() = default;
    virtual ~ILinkEvents() = default;

public:

    virtual void ConnectionUpdate(const common::comms::CommunicationUpdate &update) const = 0;

    virtual void ConnectionOpened() const = 0;

    virtual void ConnectionClosed() const = 0;
};

} //end of namespace Comms

#endif // I_LINK_EVENTS_SPII_H
