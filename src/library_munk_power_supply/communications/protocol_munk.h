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
#include "data_registers/register_fault_state.h"
#include "data_registers/type_definition.h"

#include "munk_data_framing.h"

#include "data/type_current_set.h"
#include "data/type_voltage_set.h"
#include "data/type_segment_parameter.h"
#include "data/type_fault_status_registers.h"

#include "data_registers/type_definition.h"


namespace comms_Munk{

class MunkProtocol : public IProtocol
{

public:
    MunkProtocol();

    void AddListner(const IProtocolMunkEvents* listener);

public:
    /////////////////////////////////////////////////////////////////////
    /// Methods issuing voltage setpoints relevant to the munk program
    /////////////////////////////////////////////////////////////////////

    void sendForwardVoltageSetpoint(const ILink *link, const registers_Munk::SegmentVoltageSetpoint &setpoint);

    void sendReverseVoltageSetpoint(const ILink *link, const registers_Munk::SegmentVoltageSetpoint &setpoint);

    /////////////////////////////////////////////////////////////////////
    /// Methods issuing current setpoints relevant to the munk program
    /////////////////////////////////////////////////////////////////////

    void sendForwardCurrentSetpoint(const ILink *link, const registers_Munk::SegmentCurrentSetpoint &setpoint);

    void sendReverseCurrentSetpoint(const ILink *link, const registers_Munk::SegmentCurrentSetpoint &setpoint);

    /////////////////////////////////////////////////////////////////////
    /// Methods issuing general segment data to the munk program
    /////////////////////////////////////////////////////////////////////

    void sendSegmentTime(const ILink *link, const registers_Munk::SegmentTimeGeneral &segment);

    void sendCommitToEEPROM(const ILink *link, const registers_Munk::ParameterMemoryWrite &command);

    /////////////////////////////////////////////////////////////////////
    /// Methods issuing general fault & status requests
    /////////////////////////////////////////////////////////////////////

    void sendFaultStateRequest(const ILink *link, const registers_Munk::RegisterFaultState &request);


public:

    //!
    //! \brief Read data incoming from some link
    //!
    //! This code is largely a copy from MAVLinkProtocol::receiveBytes in qgroundcontrol
    //! \param link Link which data was read from
    //! \param buffer data that was read.
    //!
    void ReceiveData(ILink *link, const std::vector<uint8_t> &buffer) override;

    void parseForException(const ILink *link, const MunkMessage &msg);

    void parseForReadMessage(const ILink *link, const MunkMessage &msg);

    void parseForFaultStateCode(const ILink *link, const registers_Munk::AbstractParameter *parameter, const MunkMessage &msg);

    void parseForAck(const ILink *link, const MunkMessage &msg);

private:

    void Emit(const std::function<void(const IProtocolMunkEvents*)> func)
    {
        for(const IProtocolMunkEvents* listener : m_Listners)
            func(listener);
    }

private:
    std::vector<const IProtocolMunkEvents*> m_Listners;

    MunkDataFraming dataParse;

    std::vector<registers_Munk::AbstractParameter*> readVector;
};


} //end of namespace comms_Munk


#endif // PROTOCOL_MUNK_H
