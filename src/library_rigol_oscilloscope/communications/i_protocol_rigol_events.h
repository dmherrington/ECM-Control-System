#ifndef I_PROTOCOL_RIGOL_EVENTS_H
#define I_PROTOCOL_RIGOL_EVENTS_H

#include <string>
#include <memory>

#include "i_link.h"

namespace comms_Rigol{

//!
//! \brief Interface that it to be implemented by users of rigol comms to listen for any events it fired
//!
class IProtocolRigolEvents
{
public:
    virtual void ResponseReceived(const ILink* link_ptr, const std::vector<uint8_t> &buffer) const = 0;

    virtual void NewMeaurementReceived(const ILink* link_ptr, const commands_Rigol::RigolMeasurementStatus &status) const = 0;
};


} //end of namespace comms


#endif // I_PROTOCOL_RIGOL_EVENTS_H
