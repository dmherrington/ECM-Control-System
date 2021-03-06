#ifndef I_LINK_EVENTS_GALIL_H
#define I_LINK_EVENTS_GALIL_H

#include "common/comms/communication_update.h"

#include "status/status_components.h"

namespace Comms
{

class ILinkEvents
{
public:

    virtual void ConnectionUpdate(const common::comms::CommunicationUpdate &update) const = 0;

    virtual void ConnectionOpened() const = 0;

    virtual void ConnectionClosed() const = 0;

    virtual void StatusReceived(const AbstractStatus &status) const = 0;

    virtual void BadRequestResponse(const AbstractStatus &status) const = 0;

    virtual void BadCommandResponse(const AbstractStatus &status) const = 0;
};

} //end of namespace Comms

#endif // I_LINK_EVENTS_GALIL_H
