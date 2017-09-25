#ifndef MUNK_POWER_SUPPLY_H
#define MUNK_POWER_SUPPLY_H

#include <iostream>
#include <QDebug>
#include <QObject>
#include <QtSerialPort/QSerialPort>

#include "library_munk_power_supply_global.h"

#include "data_registers/segment_time_general.h"

#include "data_registers/segment_time_data_detailed.h"
#include "data_registers/segment_time_detailed.h"

#include "data_registers/segment_voltage_setpoint.h"
#include "data_registers/segment_current_setpoint.h"

#include "data/type_supply_output.h"

#include "data/type_current_voltage_prescale.h"

#include "data/type_fault_codes_general.h"

#include "serial_port_helper.h"

class LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT MunkPowerSupply : public QObject
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

    void transmitMessage(const QByteArray &data);

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

signals:

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
    //!
    //! \brief serialPort
    //!
    SerialPortHelper* portHelper;

};

#endif // MUNK_POWER_SUPPLY_H
