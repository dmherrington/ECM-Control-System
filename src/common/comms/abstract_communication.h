#ifndef ICOMMUNICATION_H
#define ICOMMUNICATION_H

#include <QObject>

#include "common_global.h"

#include "serial_configuration.h"
#include "tcp_configuration.h"

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
    virtual void openEthernetPortConnection(const TCPConfiguration &config) const  = 0;
    virtual void closePortConnection() const = 0;
    virtual void writeModbusDataPort(const ModbusRegister &regMsg) const = 0;
    virtual void readModbusDataPort(const ModbusRegister &regMsg) const = 0;

    virtual bool isModbusPortOpen() const = 0;

signals:

    //!
    //! \brief signal_SerialPortReadyToConnect
    //!
    virtual void signal_PortReadyToConnect() const = 0;

    //!
    //! \brief signal_SerialPortNotReady
    //!
    virtual void signal_PortNotReady() const = 0;

    //!
    //! \brief signal_SerialPortUpdate
    //! \param update
    //!
    virtual void signal_PortUpdate(const CommunicationUpdate update) const = 0;

    //!
    //! \brief signal_PortFailedTransmission
    //! \param regMsg
    //!
    virtual void signal_PortFailedTransmission(const common::comms::CommunicationUpdate &update, const ModbusRegister &regMsg) const = 0;

    //!
    //! \brief signal_RXNewSerialData
    //! \param data
    //!
    virtual void signal_RXNewPortData(const QByteArray data) const = 0;
};

} //end of namespace comms
} //end of namespace common

Q_DECLARE_INTERFACE(common::comms::ICommunication,"ICommunication")

#endif // ICOMMUNICATION_H
