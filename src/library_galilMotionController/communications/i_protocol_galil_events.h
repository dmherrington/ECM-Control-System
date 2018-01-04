#ifndef I_PROTOCOL_GALIL_EVENTS_H
#define I_PROTOCOL_GALIL_EVENTS_H

#include "status/status_components.h"

namespace Comms
{

//!
//! \brief Interface that it to be implemented by users of MavlinkComms to listen for any events it fired
//!
class IProtocolGalilEvents
{
public:
    //!
    //! \brief A Message has been received over Mavlink protocol
    //! \param linkName Link identifier which generated command
    //! \param message Message that has been received
    //!
    virtual void MessageReceived(const double &message) const = 0;

};


} //END Comms

#endif // I_PROTOCOL_GALIL_EVENTS_H
