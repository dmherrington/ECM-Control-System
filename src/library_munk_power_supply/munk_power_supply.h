#ifndef MUNK_POWER_SUPPLY_H
#define MUNK_POWER_SUPPLY_H

#include <iostream>
#include <QDebug>
#include <QObject>

#include "library_munk_power_supply_global.h"

#include "data/type_read_write.h"
#include "data/type_exception_message.h"
#include "data/type_current_voltage_prescale.h"
#include "data/type_fault_codes_general.h"
#include "data/type_supply_output.h"

#include "communications/munk_comms_marshaler.h"
#include "communications/serial_configuration.h"
#include "communications/comms_progress_handler.h"

#include "data_registers/abstract_parameter.h"
#include "data_registers/segment_time_general.h"

#include "data_registers/segment_time_data_detailed.h"
#include "data_registers/segment_time_detailed.h"

#include "data_registers/segment_voltage_setpoint.h"
#include "data_registers/segment_current_setpoint.h"
#include "data_registers/parameter_memory_write.h"

#include "munk_poll_status.h"

using namespace registers_Munk;
using namespace data_Munk;
using namespace comms_Munk;

class LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT MunkPowerSupply :  public QObject, CommsEvents, MunkStatusCallback_Interface
{

Q_OBJECT

public:
    //!
    //! \brief MunkPowerSupply
    //!
    MunkPowerSupply();

    ~MunkPowerSupply();

    //!
    //! \brief generateAndTransmitMessage
    //! \param detailedSegmentData
    //!
    void generateAndTransmitMessage(const SegmentTimeDetailed &detailedSegmentData);

    //!
    //! \brief openSerialPort
    //!
    void openSerialPort(const QString &name);

    //!
    //! \brief closeSerialPort
    //!
    void closeSerialPort();

    bool isConnected() const;

signals:

    void signal_ConnectionStatusUpdated(const bool &open_close) const;

    void signal_CommunicationError(const std::string &type, const std::string &msg) const;

    void signal_CommunicationUpdate(const std::string &name, const std::string &msg) const;

    void signal_FaultCodeRecieved(const int &regNum, const std::string &msg) const;

    void signal_SegmentSetAck(const std::string &msg) const;

    void signal_SegmentException(const std::string &RW, const std::string &meaning) const;

    void signal_SegmentWriteProgress(const int &completed, const int &required);

private:

    //!
    //! \brief generateMessages
    //! \param detailedSegmentData
    //!
    void generateMessages(const SegmentTimeDetailed &detailedSegmentData);

private:
    /////////////////////////////////////////////////////////
    /// Virtual Functions imposed from comms::CommsEvents
    /////////////////////////////////////////////////////////

    void ConnectionOpened() const override;

    void ConnectionClosed() const override;

    void CommunicationError(const std::string &type, const std::string &msg) const override;

    void CommunicationUpdate(const std::string &name, const std::string &msg) const override;

    void FaultCodeRegister1Received(const std::string &msg) override;

    void FaultCodeRegister2Received(const std::string &msg) override;

    void FaultCodeRegister3Received(const std::string &msg) override;

    void ForwardVoltageSetpointAcknowledged(const int &numberOfRegisters) override;

    void ReverseVoltageSetpointAcknowledged(const int &numberOfRegisters) override;

    void ForwardCurrentSetpointAcknowledged(const int &numberOfRegisters) override;

    void ReverseCurrentSetpointAcknowledged(const int &numberOfRegisters) override;

    void SegmentTimeAcknowledged(const int &numberOfRegisters) override;

    void SegmentCommitedToMemoryAcknowledged() override;

    void ExceptionResponseReceived(const MunkRWType &RWType, const std::string &meaning) const override;

    ///////////////////////////////////////////////////////////////
    /// Virtual Functions imposed from MunkStatusCallback_Interface
    ///////////////////////////////////////////////////////////////

    void cbi_MunkFaultStateRequest(const RegisterFaultState &request) const override;

private:
        SegmentTimeGeneral m_segmentTimeGeneral;

        SegmentCurrentSetpoint m_fwdISetpoint;
        SegmentCurrentSetpoint m_revISetpoint;

        SegmentVoltageSetpoint m_fwdVSetpoint;
        SegmentVoltageSetpoint m_revVSetpoint;

private:
    MunkCommsMarshaler* commsMarshaler;
    MunkPollStatus* pollStatus;
    CommsProgressHandler commsProgress;

};

#endif // MUNK_POWER_SUPPLY_H
