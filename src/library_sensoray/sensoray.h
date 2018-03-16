#ifndef SENSORAY_H
#define SENSORAY_H

#include <QDir>
#include <QObject>

#include "library_sensoray_global.h"

#include "common/common.h"
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
    /// Methods supporting the Connect/Disconnect from accompanying RS485 port
    ///////////////////////////////////////////////////////////////////////////

    void openSerialPortConnection(const common::comms::SerialConfiguration &config) const override;
    void closeSerialPortConnection() const override;
    void writeToSerialPort(const QByteArray &msg) const override;
    bool isSerialPortOpen() const override;

public:
    //////////////////////////////////////////////////////////////
    /// Virtual methods allowed from comms::CommsEvents
    //////////////////////////////////////////////////////////////

    //!
    //! \brief ConnectionOpened
    //!
    void ConnectionOpened() const override;

    //!
    //! \brief ConnectionClosed
    //!
    void ConnectionClosed() const override;

    //!
    //! \brief CommunicationError
    //! \param type
    //! \param msg
    //!
    void CommunicationError(const std::string &type, const std::string &msg) const override;

    //!
    //! \brief CommunicationUpdate
    //! \param name
    //! \param msg
    //!
    void CommunicationUpdate(const std::string &name, const std::string &msg) const override;

    //!
    //! \brief NewDataReceived
    //! \param buffer
    //!
    void NewDataReceived(const QByteArray &buffer) const override;

    void SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const override;

    void SerialPortConnection(const common::comms::CommunicationConnection &connection) const override;

signals:
    void signal_SerialPortConnection(const common::comms::CommunicationConnection update) const override;

    void signal_SerialPortUpdate(const common::comms::CommunicationUpdate update) const override;

    void signal_RXNewSerialData(const QByteArray data) override;

    //!
    //! \brief ConnectionStatus
    //!
    void ConnectionStatus() const;

private:
    //!
    //! \brief initializeSensoray
    //!
    void initializeSensoray() const;

private:
    comms_Sensoray::CommsMarshaler* commsMarshaler; /**< Member variable handling the communications with the
actual Galil unit. This parent class will be subscribing to published events from the marshaller. This
should drive the event driven structure required to exceite the state machine.*/
};

#endif // SENSORAY_H
