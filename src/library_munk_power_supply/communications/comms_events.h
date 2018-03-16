#ifndef MUNK_COMMS_EVENTS_H
#define MUNK_COMMS_EVENTS_H

#include <string>
#include "common/common.h"

#include "data/type_read_write.h"

#include "data/fault_codes_register_one.h"
#include "data/fault_codes_register_two.h"
#include "data/fault_codes_register_three.h"

namespace comms_Munk{

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

    virtual void FaultCodeRegister1Received(const std::string &msg)
    {
        UNUSED(msg);
    }

    virtual void FaultCodeRegister2Received(const std::string &msg)
    {
        UNUSED(msg);
    }

    virtual void FaultCodeRegister3Received(const std::string &msg)
    {
        UNUSED(msg);
    }

    virtual void ForwardVoltageSetpointAcknowledged(const int &numberOfRegisters)
    {
        UNUSED(numberOfRegisters);
    }

    virtual void ReverseVoltageSetpointAcknowledged(const int &numberOfRegisters)
    {
        UNUSED(numberOfRegisters);
    }

    virtual void ForwardCurrentSetpointAcknowledged(const int &numberOfRegisters)
    {
        UNUSED(numberOfRegisters);
    }

    virtual void ReverseCurrentSetpointAcknowledged(const int &numberOfRegisters)
    {
        UNUSED(numberOfRegisters);
    }

    virtual void SegmentTimeAcknowledged(const int &numberOfRegisters)
    {
        UNUSED(numberOfRegisters);
    }

    virtual void SegmentCommitedToMemoryAcknowledged()
    {

    }

    virtual void ExceptionResponseReceived(const data_Munk::ReadWriteType &RWType, const std::string &meaning) const
    {
        UNUSED(RWType);
        UNUSED(meaning);
    }

};

} //end of namespace comms_Munk


#endif // COMMS_EVENTS_MUNK_H
