#ifndef MUNK_POWER_SUPPLY_H
#define MUNK_POWER_SUPPLY_H

#include <iostream>
#include <QDebug>
#include <QObject>

#include "library_munk_power_supply_global.h"

#include "communications/munk_comms_marshaler.h"
#include "communications/serial_configuration.h"

#include "data_registers/abstract_parameter.h"
#include "data_registers/segment_time_general.h"

#include "data_registers/segment_time_data_detailed.h"
#include "data_registers/segment_time_detailed.h"

#include "data_registers/segment_voltage_setpoint.h"
#include "data_registers/segment_current_setpoint.h"
#include "data_registers/parameter_memory_write.h"

#include "data/type_supply_output.h"

#include "data/type_current_voltage_prescale.h"

#include "data/type_fault_codes_general.h"

using namespace munk;

class LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT MunkPowerSupply : public QObject, comms::CommsEvents
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
    void generateAndTransmitMessage(const DataParameter::SegmentTimeDetailed &detailedSegmentData);

    //!
    //! \brief openSerialPort
    //!
    void openSerialPort(const QString &name);

    //!
    //! \brief closeSerialPort
    //!
    void closeSerialPort();

signals:

    void signal_ConnectionStatusUpdated(const bool &open_close);

    void signal_CommunicationError();

    void signal_CommunicationUpdate();

    void signal_SegmentSetAck();

    void signal_SegmentException();

    void signal_FaultCodeRecieved();

private:

    //!
    //! \brief generateMessages
    //! \param detailedSegmentData
    //!
    void generateMessages(const DataParameter::SegmentTimeDetailed &detailedSegmentData);

private:
    /////////////////////////////////////////////////////////
    /// Virtual Functions imposed from comms::CommsEvents
    /////////////////////////////////////////////////////////

    void ConnectionOpened() const override;

    void ConnectionClosed() const override;

    void CommunicationError(const std::string &type, const std::string &msg) const override;

    void CommunicationUpdate(const std::string &name, const std::string &msg) const override;

    void FaultCodeRegister1Received() override;

    void FaultCodeRegister2Received() override;

    void FaultCodeRegister3Received() override;

    void SegmentSetpointAcknowledged() override;

    void ExceptionResponseReceived() override;


private:
        DataParameter::SegmentTimeGeneral m_segmentTimeGeneral;

        DataParameter::SegmentCurrentSetpoint m_fwdISetpoint;
        DataParameter::SegmentCurrentSetpoint m_revISetpoint;

        DataParameter::SegmentVoltageSetpoint m_fwdVSetpoint;
        DataParameter::SegmentVoltageSetpoint m_revVSetpoint;

private:
    comms::MunkCommsMarshaler* commsMarshaler;
};

#endif // MUNK_POWER_SUPPLY_H
