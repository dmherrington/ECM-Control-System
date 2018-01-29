#ifndef COMMS_EVENTS_H
#define COMMS_EVENTS_H

#include <string>
#include "common/common.h"

#include "data/type_read_write.h"

namespace munk {
namespace comms{

class CommsEvents
{
public:

    /////////////////////////////////////////////////////////
    /// Link Events
    /////////////////////////////////////////////////////////

    virtual void ConnectionOpened() const
    {

    }

    virtual void ConnectionClosed() const
    {

    }

    virtual void CommunicationError(const std::string &type, const std::string &msg) const
    {
        UNUSED(type);
        UNUSED(msg);
    }

    virtual void CommunicationUpdate(const std::string &name, const std::string &msg) const
    {
        UNUSED(name);
        UNUSED(msg);
    }



    /////////////////////////////////////////////////////////
    /// Munk Protocol Events
    /////////////////////////////////////////////////////////

    virtual void FaultCodeRegister1Received()
    {

    }

    virtual void FaultCodeRegister2Received()
    {

    }

    virtual void FaultCodeRegister3Received()
    {

    }

    virtual void ForwardVoltageSetpointAcknowledged(const int &numberOfRegisters) const
    {
        UNUSED(numberOfRegisters);
    }

    virtual void ReverseVoltageSetpointAcknowledged(const int &numberOfRegisters) const
    {
        UNUSED(numberOfRegisters);
    }

    virtual void ForwardCurrentSetpointAcknowledged(const int &numberOfRegisters) const
    {
        UNUSED(numberOfRegisters);
    }

    virtual void ReverseCurrentSetpointAcknowledged(const int &numberOfRegisters) const
    {
        UNUSED(numberOfRegisters);
    }

    virtual void SegmentTimeAcknowledged(const int &numberOfRegisters) const
    {
        UNUSED(numberOfRegisters);
    }

    virtual void ExceptionResponseReceived(const Data::ReadWriteType &RWType, const std::string &meaning) const
    {
        UNUSED(RWType);
        UNUSED(meaning);
    }

};

} //end of namespace comms
} //end of namespace munk

#endif // COMMS_EVENTS_H
