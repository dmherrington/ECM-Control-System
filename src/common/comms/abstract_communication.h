#ifndef ICOMMUNICATION_H
#define ICOMMUNICATION_H

#include <QObject>

#include "common_global.h"

#include "serial_configuration.h"

#include "communication_connection.h"
#include "communication_update.h"

namespace common{
namespace comms{

class COMMONSHARED_EXPORT ICommunication
{
public:
    ICommunication() = default;

    virtual ~ICommunication()
    {

    }
public:
    virtual bool isSerialDeviceReadyToConnect() const = 0;
    virtual void openSerialPortConnection(const SerialConfiguration &config) const  = 0;
    virtual void closeSerialPortConnection() const = 0;
    virtual void writeToSerialPort(const QByteArray &msg) const = 0;
    virtual bool isSerialPortOpen() const = 0;

signals:
    virtual void signal_SerialPortReadyToConnect() const = 0;
    virtual void signal_SerialPortConnection(const CommunicationConnection update) const = 0;
    virtual void signal_SerialPortUpdate(const CommunicationUpdate update) const = 0;
    virtual void signal_RXNewSerialData(const QByteArray data) const = 0;
};

} //end of namespace comms
} //end of namespace common

Q_DECLARE_INTERFACE(common::comms::ICommunication,"ICommunication")

#endif // ICOMMUNICATION_H
