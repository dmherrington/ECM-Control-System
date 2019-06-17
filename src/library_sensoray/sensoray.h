#ifndef SENSORAY_H
#define SENSORAY_H

#include <QDir>
#include <QObject>

#include "library_sensoray_global.h"

#include "common/common.h"
#include "common/modbus_register.h"
#include "common/comms/abstract_communication.h"

#include "communications/sensoray_tcp_configuration.h"
#include "communications/sensoray_serial_configuration.h"

#include "communications/sensoray_comms_marshaler.h"

class LIBRARY_SENSORAYSHARED_EXPORT Sensoray : public QObject, public common::comms::ICommunication, public comms_Sensoray::CommsEvents
{
    Q_OBJECT
    Q_INTERFACES(common::comms::ICommunication)
public:
    //!
    //! \brief Sensoray
    //! \param name
    //! \param parent
    //!
    explicit Sensoray(const std::string &name = "Sensoray", QObject *parent = nullptr);

    ~Sensoray() = default;

public:
    ///////////////////////////////////////////////////////////////////////////
    /// Methods supporting the Connect/Disconnect from Sensoray device
    ///////////////////////////////////////////////////////////////////////////

    //!
    //! \brief openConnection
    //! \param ipAddress
    //! \param portNumber
    //!
    void openConnection(const comms_Sensoray::SensorayTCPConfiguration &config);

    //!
    //! \brief closeConnection
    //!
    void closeConnection();



public:
    ///////////////////////////////////////////////////////////////////////////
    /// Imposed virtual methods from common::comms::ICommunication
    /// Methods supporting the Connect/Disconnect from accompanying RS485 port
    ///////////////////////////////////////////////////////////////////////////

    bool isSerialDeviceReadyToConnect() const;
    void openSerialPortConnection(const common::comms::SerialConfiguration &config) const override;
    void closeSerialPortConnection() const override;
    void writeToSerialPort(const ModbusRegister &regMsg) const override;
    bool isSerialPortOpen() const override;

public:
    //////////////////////////////////////////////////////////////
    /// Virtual methods allowed from comms::CommsEvents
    //////////////////////////////////////////////////////////////

    //!
    //! \brief ConnectionStatusUpdated
    //! \param update
    //!
    void ConnectionStatusUpdated(const common::comms::CommunicationUpdate &update) const override;

    //!
    //! \brief SerialPortStatusUpdate
    //! \param update
    //!
    void SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const override;

    //!
    //! \brief NewDataReceived
    //! \param buffer
    //!
    void NewDataReceived(const QByteArray &buffer) const override;

    //!
    //! \brief ReceivedUpdatedADC
    //! \param data
    //!
    void ReceivedUpdatedADC(const std::vector<S2426_ADC_SAMPLE> data) const override;


signals:
    void signal_SensorayCommunicationUpdate(const common::comms::CommunicationUpdate &update) const;

    ///////////////////////////////////////////////////////////////////////////
    /// Imposed virtual signals from common::comms::ICommunication
    ///////////////////////////////////////////////////////////////////////////
    void signal_SerialPortReadyToConnect() const override;

    void signal_SerialPortNotReady() const override;

    void signal_SerialPortUpdate(const common::comms::CommunicationUpdate update) const override;

    void signal_RXNewSerialData(const QByteArray data) const override;

private:
    //!
    //! \brief initializeSensoray
    //!
    void initializeSensoray() const;

private:
    comms_Sensoray::CommsMarshaler* commsMarshaler; /**< Member variable handling the communications with the
actual Galil unit. This parent class will be subscribing to published events from the marshaller. This
should drive the event driven structure required to exceite the state machine.*/

    std::string deviceName;
};

#endif // SENSORAY_H
