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
    explicit Sensoray(const std::string &name = "Rigol_Oscilloscope", QObject *parent = nullptr);

    ~Sensoray() = default;

public:
    void openConnection(const std::string &ipAddress, const int &portNumber);
    void closeConnection();

public:
    //////////////////////////////////////////////////////////////
    /// Virtual methods allowed from comms::CommsEvents
    //////////////////////////////////////////////////////////////
    void ConnectionOpened() const override;
    void ConnectionClosed() const override;
    void NewDataReceived(const QByteArray &buffer) const override;

signals:
    void ReceivedSerialMessage(const QByteArray &msg);

private:
    void initializeSensoray() const;

private:
    sensoray::comms::CommsMarshaler* commsMarshaler; /**< Member variable handling the communications with the
actual Galil unit. This parent class will be subscribing to published events from the marshaller. This
should drive the event driven structure required to exceite the state machine.*/
};

#endif // SENSORAY_H
