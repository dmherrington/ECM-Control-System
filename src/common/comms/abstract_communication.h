#ifndef ICOMMUNICATION_H
#define ICOMMUNICATION_H

#include <QObject>

#include "common_global.h"

#include "serial_configuration.h"

#include "communication_connection.h"
#include "communication_update.h"

#include "../modbus_register.h"

namespace common{
namespace comms{

class COMMONSHARED_EXPORT ICommunication
{
public:
    //!
    //! \brief ICommunication default constructor of the abstract ICommunication class
    //!
    ICommunication() = default;

    //!
    //! \brief ~ICommunication default destructor of the abstract ICommunication class
    //!
    virtual ~ICommunication() = default;

public:
    virtual bool isSerialDeviceReadyToConnect() const = 0;
    virtual void openSerialPortConnection(const SerialConfiguration &config) const  = 0;
    virtual void closeSerialPortConnection() const = 0;
    virtual void writeToSerialPort(const ModbusRegister &regMsg) const = 0;
    virtual bool isSerialPortOpen() const = 0;

signals:
    //!
    //! \brief signal_SerialPortReadyToConnect
    //!
    virtual void signal_SerialPortReadyToConnect() const = 0;

    //!
    //! \brief signal_SerialPortNotReady
    //!
    virtual void signal_SerialPortNotReady() const = 0;

    //!
    //! \brief signal_SerialPortUpdate
    //! \param update
    //!
    virtual void signal_SerialPortUpdate(const CommunicationUpdate update) const = 0;

    //!
    //! \brief signal_RXNewSerialData
    //! \param data
    //!
    virtual void signal_RXNewSerialData(const QByteArray data) const = 0;
};

} //end of namespace comms
} //end of namespace common

Q_DECLARE_INTERFACE(common::comms::ICommunication,"ICommunication")

#endif // ICOMMUNICATION_H
