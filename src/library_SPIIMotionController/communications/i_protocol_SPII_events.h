#ifndef I_PROTOCOL_SPII_EVENTS_H
#define I_PROTOCOL_SPII_EVENTS_H

#include <string>

#include "../status/status_components.h"

namespace Comms
{

//!
//! \brief Interface that it to be implemented by users of MavlinkComms to listen for any events it fired
//!
class IProtocolSPIIEvents
{
public:
    virtual ~IProtocolSPIIEvents() = default;

public:
    virtual void NewBufferState(const Status_BufferState &state) const = 0;
};


} //END Comms

#endif // I_PROTOCOL_SPII_EVENTS_H
