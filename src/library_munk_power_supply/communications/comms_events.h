#ifndef MUNK_COMMS_EVENTS_H
#define MUNK_COMMS_EVENTS_H

#include <string>
#include "common/common.h"

#include "data/type_read_write.h"
#include "data/type_fault_status_registers.h"

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

    virtual void FaultCodeReceived(const data_Munk::FaultRegisterType &faultRegister, const unsigned int &code)
    {
        UNUSED(faultRegister);
        UNUSED(code);
    }

    virtual void FaultStateCleared()
    {

    }

    virtual void ForwardVoltageSetpointAcknowledged()
    {

    }

    virtual void ReverseVoltageSetpointAcknowledged()
    {

    }

    virtual void ForwardCurrentSetpointAcknowledged()
    {

    }

    virtual void ReverseCurrentSetpointAcknowledged()
    {

    }

    virtual void SegmentTimeAcknowledged()
    {

    }

    virtual void SegmentCommitedToMemoryAcknowledged()
    {

    }

    virtual void ExceptionResponseReceived(const data_Munk::MunkRWType &RWType, const std::string &meaning) const
    {
        UNUSED(RWType);
        UNUSED(meaning);
    }

};

} //end of namespace comms_Munk


#endif // COMMS_EVENTS_MUNK_H
