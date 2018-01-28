#ifndef PROTOCOL_MUNK_H
#define PROTOCOL_MUNK_H

#include <memory>
#include <vector>
#include <functional>
#include <math.h>
#include <unordered_map>

#include "i_link.h"
#include "i_protocol_munk_events.h"
#include "i_protocol.h"

#include "data_registers/segment_time_general.h"
#include "data_registers/segment_voltage_setpoint.h"
#include "data_registers/segment_current_setpoint.h"
#include "data_registers/parameter_memory_write.h"


namespace munk {
namespace comms{

class MunkProtocol : public IProtocol
{

public:
    MunkProtocol();

    void AddListner(const IProtocolMunkEvents* listener);

public:
    /////////////////////////////////////////////////////////////////////
    /// Methods issuing voltage setpoints relevant to the munk program
    /////////////////////////////////////////////////////////////////////

    void sendForwardVoltageSetpoint(const ILink *link, const DataParameter::SegmentVoltageSetpoint &setpoint);

    void sendReverseVoltageSetpoint(const ILink *link, const DataParameter::SegmentVoltageSetpoint &setpoint);

    /////////////////////////////////////////////////////////////////////
    /// Methods issuing current setpoints relevant to the munk program
    /////////////////////////////////////////////////////////////////////

    void sendForwardCurrentSetpoint(const ILink *link, const DataParameter::SegmentCurrentSetpoint &setpoint);

    void sendReverseCurrentSetpoint(const ILink *link, const DataParameter::SegmentCurrentSetpoint &setpoint);

    /////////////////////////////////////////////////////////////////////
    /// Methods issuing general segment data to the munk program
    /////////////////////////////////////////////////////////////////////

    void sendSegmentTime(const ILink *link, const DataParameter::SegmentTimeGeneral &segment);

    void sendCommitToEEPROM(const ILink *link, const DataParameter::ParameterMemoryWrite &command);

public:

    //!
    //! \brief Read data incoming from some link
    //!
    //! This code is largely a copy from MAVLinkProtocol::receiveBytes in qgroundcontrol
    //! \param link Link which data was read from
    //! \param buffer data that was read.
    //!
    void ReceiveData(ILink *link, const std::vector<uint8_t> &buffer) override;

private:

    void Emit(const std::function<void(const IProtocolMunkEvents*)> func)
    {
        for(const IProtocolMunkEvents* listener : m_Listners)
            func(listener);
    }

private:
    std::vector<const IProtocolMunkEvents*> m_Listners;
};


} //end of namespace comms
} //end of namespace munk

#endif // PROTOCOL_MUNK_H
