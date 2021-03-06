#ifndef I_PROTOCOL_SENSORARY_EVENTS_H
#define I_PROTOCOL_SENSORARY_EVENTS_H

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

#include "s24xx.h"

#include "i_link.h"

#include "common/comms/communication_update.h"
#include "common/comms/communication_connection.h"

namespace comms_Sensoray{

//!
//! \brief Interface that it to be implemented by users of rigol comms to listen for any events it fired
//!
class IProtocolSensorayEvents
{
public:
    //!
    //! \brief SerialPortStatusUpdate signal to be emitted when the explicit serial port of the sensoray
    //! has a change in status.
    //! \param update object containing information related to the status of the serial port
    //!
    virtual void SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const = 0;

    //!
    //! \brief ResponseReceived signal to be emitted when information has been received by the serial port
    //! \param buffer byte array containing the received message at the port
    //!
    virtual void ResponseReceived(const QByteArray &buffer) const = 0;

    //!
    //! \brief UpdateFromADC
    //! \param data
    //!
    virtual void UpdateFromADC(const std::vector<S2426_ADC_SAMPLE> data) const = 0;

};


} //end of namespace comms

#endif // I_PROTOCOL_SENSORARY_EVENTS_H
