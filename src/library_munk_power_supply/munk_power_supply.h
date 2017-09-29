#ifndef MUNK_POWER_SUPPLY_H
#define MUNK_POWER_SUPPLY_H

#include <iostream>
#include <QDebug>
#include <QObject>
#include <QtSerialPort/QSerialPort>

#include "library_munk_power_supply_global.h"

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

#include "serial_port_manager.h"

#include <QDebug>

class LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT MunkPowerSupply : public QObject, public SerialPortManager_Interface
{
    Q_OBJECT
private:
    struct structSetpoints
    {
        DataParameter::SegmentCurrentSetpoint iSet;
        DataParameter::SegmentVoltageSetpoint vSet;
    };

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
    void openSerialPort();

    //!
    //! \brief closeSerialPort
    //!
    void closeSerialPort();

    //!
    //! \brief openSerialPort
    //! \param name
    //!
    void configureSerialPort(const QString &name);

    //!
    //! \brief openSerialPort
    //! \param name
    //! \param rate
    //! \param bits
    //! \param parity
    //! \param stop
    //!
    void configureSerialPort(const QString &name, const QSerialPort::BaudRate &rate, const QSerialPort::DataBits &bits, const QSerialPort::Parity &parity, const QSerialPort::StopBits &stop);

public:
    //!
    //! \brief cbiSerialPortHelper_serialPortStatus
    //! \param open_close
    //! \param errorString
    //!
    void cbiSerialPortHelper_serialPortStatus(const bool &open_close, const std::string &errorString) override;

signals:

    //!
    //! \brief signal_SerialPortStatus
    //! \param open_close
    //! \param errorString
    //!
    void signal_SerialPortStatus(const bool &open_close, const std::string &errorString);

    //!
    //! \brief signal_NewCurrentSetpoint
    //! \param currentSetpoint
    //!
    void signal_NewCurrentSetpoint(const DataParameter::SegmentCurrentSetpoint &currentSetpointREV, const DataParameter::SegmentCurrentSetpoint &currentSetpointFWD);

    //!
    //! \brief signal_NewVoltageSetpoint
    //! \param voltageSetpoint
    //!
    void signal_NewVoltageSetpoint(const DataParameter::SegmentVoltageSetpoint &voltageSetpointREV, const DataParameter::SegmentVoltageSetpoint &voltageSetpointFWD);

    //!
    //! \brief signal_NewTimeSetpoint
    //! \param segmentTime
    //!
    void signal_NewTimeSetpoint(const DataParameter::SegmentTimeGeneral &segmentTime);

    void messageGenerationProgress(const Data::DataFaultCodes &code);
    void transmissionProgress();
    void munkSupplyError();
    void serialPortError();

private:

    //!
    //! \brief generateMessages
    //! \param detailedSegmentData
    //!
    void generateMessages(const DataParameter::SegmentTimeDetailed &detailedSegmentData);

private slots:
    void receivedMSG(const QByteArray &data);

private:
        DataParameter::SegmentTimeGeneral m_segmentTimeGeneral;

        DataParameter::SegmentCurrentSetpoint m_fwdISetpoint;
        DataParameter::SegmentCurrentSetpoint m_revISetpoint;

        DataParameter::SegmentVoltageSetpoint m_fwdVSetpoint;
        DataParameter::SegmentVoltageSetpoint m_revVSetpoint;
private:
    //!
    //! \brief serialPort
    //!
    SerialPortManager* portHelper;

    QByteArray buffer;

};

#endif // MUNK_POWER_SUPPLY_H
