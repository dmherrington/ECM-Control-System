#ifndef MUNK_COMMS_MARSHALER_H
#define MUNK_COMMS_MARSHALER_H

#include "common/publisher.h"

#include <unordered_map>

#include "i_link.h"
#include "serial_configuration.h"

#include "munk_serial_link.h"
#include "protocol_munk.h"

#include "i_link_events.h"
#include "comms_events.h"

#include "data_registers/segment_time_general.h"
#include "data_registers/segment_voltage_setpoint.h"
#include "data_registers/segment_current_setpoint.h"
#include "data_registers/parameter_memory_write.h"

#include "data/type_exception_message.h"
#include "data_registers/register_fault_state.h"
#include "data_registers/register_fault_reset.h"

namespace comms_Munk{

class MunkCommsMarshaler : public Publisher<CommsEvents>, private ILinkEvents, private IProtocolMunkEvents
{
public:

    MunkCommsMarshaler();

    virtual ~MunkCommsMarshaler();
    //////////////////////////////////////////////////////////////
    /// Connect/Disconnect from Munk Methods
    //////////////////////////////////////////////////////////////

    //!
    //! \brief Connect to an already created link
    //! \param linkName Name of link to connect to
    //! \return True if connection successful, false otherwise
    //!
    bool ConnectToLink(const SerialConfiguration &linkConfig);
    bool DisconnetFromLink();

    bool isConnected() const;

    void sendCompleteMunkParameters(std::vector<registers_Munk::AbstractParameterPtr> parameters);

    ///////////////////////////////////////////////////////////////////
    /// Methods issuing voltage setpoints relevant to the munk program
    ///////////////////////////////////////////////////////////////////
    void sendForwardVoltageSetpoint(const registers_Munk::SegmentVoltageSetpoint &setpoint);

    void sendReverseVoltageSetpoint(const registers_Munk::SegmentVoltageSetpoint &setpoint);

    /////////////////////////////////////////////////////////////////////
    /// Methods issuing current setpoints relevant to the munk program
    /////////////////////////////////////////////////////////////////////

    void sendForwardCurrentSetpoint(const registers_Munk::SegmentCurrentSetpoint &setpoint);

    void sendReverseCurrentSetpoint(const registers_Munk::SegmentCurrentSetpoint &setpoint);

    /////////////////////////////////////////////////////////////////////
    /// Methods issuing general segment data to the munk program
    /////////////////////////////////////////////////////////////////////

    void sendSegmentTime(const registers_Munk::SegmentTimeGeneral &segment);

    void sendCommitToEEPROM();

    /////////////////////////////////////////////////////////////////////
    /// Methods issuing general fault & status requests
    /////////////////////////////////////////////////////////////////////

    void sendRegisterFaultStateRequest(const registers_Munk::RegisterFaultState &request);

    void sendRegisterFaultStateClear(const registers_Munk::Register_FaultReset &request);

private:
    //////////////////////////////////////////////////////////////
    /// React to Link Events
    //////////////////////////////////////////////////////////////

    void ConnectionOpened() const override;

    void ConnectionClosed() const override;

    void ReceiveData(const std::vector<uint8_t> &buffer) const override;

    void CommunicationError(const std::string &type, const std::string &msg) const override;

    void CommunicationUpdate(const std::string &name, const std::string &msg) const override;

    //////////////////////////////////////////////////////////////
    /// IProtocolMunkEvents
    //////////////////////////////////////////////////////////////

    void FaultCodeReceived(const ILink* link_ptr, const data_Munk::FaultRegisterType &faultRegister, const unsigned int &code) const override;

    void FaultStateCleared(const ILink* link_ptr) const override;

    void SegmentVoltageSetpointAcknowledged(const ILink* link_ptr, const data_Munk::SegmentMode &mode) const override;
    void SegmentCurrentSetpointAcknowledged(const ILink* link_ptr , const data_Munk::SegmentMode &mode) const override;
    void SegmentTimeSetpointAcknowledged(const ILink* link_ptr) const override;
    void SegmentCommittedToMemory(const ILink* link_ptr) const override;

    void ExceptionResponseReceived(const ILink* link_ptr, const data_Munk::MunkRWType &type, const uint8_t &code) const override;

private:
    std::shared_ptr<ILink> link;
    std::shared_ptr<MunkProtocol> protocol;
};

} //end of namespace comms_Munk


#endif // MUNK_COMMS_MARSHALER_H
