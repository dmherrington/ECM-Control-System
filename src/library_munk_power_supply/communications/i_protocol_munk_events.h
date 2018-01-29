#ifndef I_PROTOCOL_MUNK_EVENTS_H
#define I_PROTOCOL_MUNK_EVENTS_H

#include <string>
#include <memory>

#include "i_link.h"

#include "data/type_read_write.h"
#include "data/type_segment_mode.h"

namespace munk {
namespace comms{

//!
//! \brief Interface that it to be implemented by users of munk comms to listen for any events it fired
//!
class IProtocolMunkEvents
{
public:

    virtual void FaultCodeRegister1Received(const ILink* link_ptr) const = 0;
    virtual void FaultCodeRegister2Received(const ILink* link_ptr) const = 0;
    virtual void FaultCodeRegister3Received(const ILink* link_ptr) const = 0;

    virtual void SegmentVoltageSetpointAcknowledged(const ILink* link_ptr, const Data::SegmentMode &mode, const int &numberRegisters) const = 0;
    virtual void SegmentCurrentSetpointAcknowledged(const ILink* link_ptr , const Data::SegmentMode &mode, const int &numberRegisters) const = 0;
    virtual void SegmentTimeSetpointAcknowledged(const ILink* link_ptr , const int &numberRegisters) const = 0;


    virtual void ExceptionResponseReceived(const ILink* link_ptr, const Data::ReadWriteType &type, const uint8_t &code) const = 0;
};


} //end of namespace comms
} //end of namespace munk

#endif // I_PROTOCOL_MUNK_EVENTS_H
