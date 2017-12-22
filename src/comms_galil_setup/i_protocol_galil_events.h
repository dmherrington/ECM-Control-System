#ifndef I_PROTOCOL_GALIL_EVENTS_H
#define I_PROTOCOL_GALIL_EVENTS_H

#include <string>
#include <memory>

#include "i_link.h"

#include "i_protocol_events.h"


namespace Comms
{

//!
//! \brief Interface that it to be implemented by users of MavlinkComms to listen for any events it fired
//!
class IProtocolGalilEvents : public IProtocolEvents
{
public:

    //!
    //! \brief A Message has been received over Mavlink protocol
    //! \param linkName Link identifier which generated command
    //! \param message Message that has been received
    //!
    virtual void MessageReceived(const ILink* link_ptr, const mavlink_message_t &message) const = 0;

};


} //END Comms

#endif // I_PROTOCOL_GALIL_EVENTS_H
