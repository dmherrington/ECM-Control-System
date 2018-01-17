#ifndef I_LINK_EVENTS_H
#define I_LINK_EVENTS_H

#include "status/status_components.h"

namespace Comms
{

class ILinkEvents
{
public:
    virtual void ConnectionOpened() const = 0;

    virtual void ConnectionClosed() const = 0;

    virtual void StatusReceived(const AbstractStatus &status) const = 0;

    virtual void BadRequestResponse(const AbstractStatus &status) const = 0;

    virtual void BadCommandResponse(const AbstractStatus &status) const = 0;
};

} //END Comms

#endif // I_LINK_EVENTS_H
