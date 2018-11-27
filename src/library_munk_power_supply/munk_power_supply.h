#ifndef MUNK_POWER_SUPPLY_H
#define MUNK_POWER_SUPPLY_H

#include <iostream>
#include <QTextStream>
#include <QDebug>
#include <QObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "library_munk_power_supply_global.h"
#include "common/comms/communication_update.h"
#include "common/comms/communication_connection.h"

#include "data/type_read_write.h"
#include "data/type_exception_message.h"
#include "data/type_current_voltage_prescale.h"
#include "data/type_fault_codes_general.h"
#include "data/type_supply_output.h"

#include "communications/munk_comms_marshaler.h"
#include "communications/serial_configuration.h"
#include "communications/comms_progress_handler.h"

#include "data/type_fault_status_registers.h"

#include "data_registers/abstract_parameter.h"
#include "data_registers/segment_time_general.h"

#include "data_registers/segment_time_data_detailed.h"
#include "data_registers/segment_time_detailed.h"

#include "data_registers/segment_voltage_setpoint.h"
#include "data_registers/segment_current_setpoint.h"
#include "data_registers/parameter_memory_write.h"

#include "data_registers/register_fault_reset.h"

#include "data_response/fault_register_state.h"


#include "data_registers/register_pulse_mode.h"

#include "munk_machine_state.h"
#include "munk_poll_status.h"

#include "device_interface_power_supply.h"
using namespace registers_Munk;
using namespace data_Munk;
using namespace comms_Munk;

class LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT MunkPowerSupply : public QObject, public DeviceInterface_PowerSupply, CommsEvents, MunkStatusCallback_Interface
{
    Q_OBJECT

public:
    //!
    //! \brief MunkPowerSupply
    //!
    MunkPowerSupply(const std::string &name = "Munk_PowerSupply");

    ~MunkPowerSupply();

    void resetFaultState();

    //!
    //! \brief generateAndTransmitMessage
    //! \param detailedSegmentData
    //!
    void generateAndTransmitMessage(const SegmentTimeDetailed &detailedSegmentData);

    //!
    //! \brief openSerialPort
    //!
    void openSerialPort(const std::string &name);

    //!
    //! \brief closeSerialPort
    //!
    void closeSerialPort();

    bool isConnected() const;

public:
    void writeRegisterPulseMode(const registers_Munk::Register_PulseMode &pulseMode);

public:
    void saveToFile(const QString &filePath);

private:
    void write(QJsonObject &json) const;

signals:

    void signal_MunkCommunicationUpdate(const common::comms::CommunicationUpdate &value) const;

    void signal_CommunicationError(const std::string &type, const std::string &msg) const;

    void signal_CommunicationUpdate(const std::string &name, const std::string &msg) const;

    void signal_FaultCodeRecieved() const;

    void signal_FaultStateCleared();

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

    void FaultCodeReceived(const data_Munk::FaultRegisterType &faultRegister, const unsigned int &code) override;

    void FaultStateCleared() override;

    void ForwardVoltageSetpointAcknowledged() override;

    void ReverseVoltageSetpointAcknowledged() override;

    void ForwardCurrentSetpointAcknowledged() override;

    void ReverseCurrentSetpointAcknowledged() override;

    void SegmentTimeAcknowledged() override;

    void SegmentCommitedToMemoryAcknowledged() override;

    void NewSegmentSequence(const registers_Munk::SegmentTimeDetailed &segmentData) override;

    void ExceptionResponseReceived(const MunkRWType &RWType, const std::string &meaning) const override;

    ///////////////////////////////////////////////////////////////
    /// Virtual Functions imposed from MunkStatusCallback_Interface
    ///////////////////////////////////////////////////////////////

    void cbi_MunkFaultStateRequest(const RegisterFaultState &request) const override;

public:
    std::string getLogOfOperationalSettings() const;

private:
    std::string deviceName;

    SegmentTimeGeneral m_segmentTimeGeneral;

    SegmentCurrentSetpoint m_fwdISetpoint;
    SegmentCurrentSetpoint m_revISetpoint;

    SegmentVoltageSetpoint m_fwdVSetpoint;
    SegmentVoltageSetpoint m_revVSetpoint;


public:
    Munk_MachineState* machineState;


private:
    MunkCommsMarshaler* commsMarshaler;
    MunkPollStatus* pollStatus;
    CommsProgressHandler commsProgress;

};

#endif // MUNK_POWER_SUPPLY_H
