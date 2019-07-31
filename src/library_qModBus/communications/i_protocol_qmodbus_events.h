#ifndef I_PROTOCOL_QMODBUS_EVENTS_H
#define I_PROTOCOL_QMODBUS_EVENTS_H

/**
\* @file  i_protocol_sensoray_events.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is interact with the sensoray.
\*
\* @section DESCRIPTION
\*
\*
\*/

#include <string>
#include <memory>

#include "i_link.h"

#include "common/modbus_register.h"
#include "common/comms/communication_update.h"
#include "common/comms/communication_connection.h"

namespace comms_QModBus{

//!
//! \brief Interface that it to be implemented by users of rigol comms to listen for any events it fired
//!
class IProtocolQModBusEvents
{

public:
    virtual ~IProtocolQModBusEvents() = default;

public:
    //!
    //! \brief SerialPortStatusUpdate signal to be emitted when the explicit serial port of the sensoray
    //! has a change in status.
    //! \param update object containing information related to the status of the serial port
    //!
    virtual void ModbusPortStatusUpdate(const common::comms::CommunicationUpdate &update) const = 0;

    //!
    //! \brief FailedDataTransmission
    //! \param reg
    //!
    virtual void ModbusFailedDataTransmission(const common::comms::CommunicationUpdate &update, const ModbusRegister &reg) const = 0;

    //!
    //! \brief ResponseReceived signal to be emitted when information has been received by the serial port
    //! \param buffer byte array containing the received message at the port
    //!
    virtual void ModbusResponseReceived(const QByteArray &buffer) const = 0;
};


} //end of namespace comms_QModBus

#endif // I_PROTOCOL_QMODBUS_EVENTS_H
