#ifndef LIBRARY_QMODBUS_H
#define LIBRARY_QMODBUS_H

#include "library_qmodbus_global.h"

#include <QDir>
#include <QObject>

#include "../../tools/libmodbus/src/modbus.h"

#include "common/common.h"
#include "common/comms/abstract_communication.h"
#include "common/comms/serial_configuration.h"

#include "communications/qmodbus_comms_marshaler.h"

class LIBRARY_QMODBUSSHARED_EXPORT Library_QModBus : public QObject, public common::comms::ICommunication, public comms_QModBus::CommsEvents
{
    Q_OBJECT
    Q_INTERFACES(common::comms::ICommunication)
public:
    //!
    //! \brief Sensoray
    //! \param name
    //! \param parent
    //!
    explicit Library_QModBus(const std::string &name = "QModBus", QObject *parent = nullptr);

    ~Library_QModBus() = default;


public:
    ///////////////////////////////////////////////////////////////////////////
    /// Imposed virtual methods from common::comms::ICommunication
    /// Methods supporting the Connect/Disconnect from accompanying RS485 port
    ///////////////////////////////////////////////////////////////////////////

    bool isSerialDeviceReadyToConnect() const;
    void openSerialPortConnection(const common::comms::SerialConfiguration &config) const override;
    void closeSerialPortConnection() const override;
    void writeToSerialPort(const QByteArray &msg) const override;
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
    comms_QModBus::CommsMarshaler* commsMarshaler; /**< Member variable handling the communications with the
actual RS485 units. This parent class will be subscribing to published events from the marshaller. This
should drive the event driven structure required to exceite the state machine.*/

    std::string deviceName;
};


#endif // LIBRARY_QMODBUS_H
