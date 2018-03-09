#ifndef SENSORAY_H
#define SENSORAY_H

#include <QDir>
#include <QObject>

#include "library_sensoray_global.h"

#include "communications/sensoray_tcp_configuration.h"
#include "communications/sensoray_comms_marshaler.h"

using namespace sensoray;

class LIBRARY_SENSORAYSHARED_EXPORT Sensoray : public QObject, public comms::CommsEvents
{
    Q_OBJECT

public:
    //!
    //! \brief Sensoray
    //! \param name
    //! \param parent
    //!
    explicit Sensoray(const std::string &name = "Rigol_Oscilloscope", QObject *parent = nullptr);

    ~Sensoray() = default;

public:
    //!
    //! \brief openConnection
    //! \param ipAddress
    //! \param portNumber
    //!
    void openConnection(const std::string &ipAddress, const int &portNumber);

    //!
    //! \brief closeConnection
    //!
    void closeConnection();

    //!
    //! \brief transmitSerialMessage
    //! \param data
    //!
    void transmitSerialMessage(const QByteArray &data);

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

signals:
    //!
    //! \brief ReceivedSerialMessage
    //! \param msg
    //!
    void ReceivedSerialMessage(const QByteArray &msg) const;

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
    sensoray::comms::CommsMarshaler* commsMarshaler; /**< Member variable handling the communications with the
actual Galil unit. This parent class will be subscribing to published events from the marshaller. This
should drive the event driven structure required to exceite the state machine.*/
};

#endif // SENSORAY_H
