#ifndef QMODBUS_COMMS_MARSHALER_H
#define QMODBUS_COMMS_MARSHALER_H

#include "common/publisher.h"
#include "common/comms/serial_configuration.h"

#include <unordered_map>

#include "i_link.h"
#include "qmodbus_link.h"
#include "protocol_qmodbus.h"
#include "i_link_events.h"
#include "i_protocol_qmodbus_events.h"
#include "comms_events.h"

/**
\* @file  qmodbus_comms_marshaler.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is interact with the qmodbus object.
\*
\* @section DESCRIPTION
\*
\*
\*/

namespace comms_QModBus{

class CommsMarshaler : public Publisher<CommsEvents>, private ILinkEvents, private IProtocolQModBusEvents
{
public:

    CommsMarshaler();

    virtual ~CommsMarshaler();
    ///////////////////////////////////////////////////////////////////
    /// Methods supporting the Connect/Disconnect from of the QModBus Device
    /// and accompanying RS485 port
    ///////////////////////////////////////////////////////////////////

    //!
    //! \brief Connect to an already created link
    //! \param linkName Name of link to connect to
    //! \return True if connection successful, false otherwise
    //!
    bool ConnectToLink(const common::comms::SerialConfiguration &linkConfig);

    //!
    //! \brief DisconnetFromLink
    //! \return
    //!
    bool DisconnetFromLink();

    bool isLinkConnected() const;

    ///////////////////////////////////////////////////////////////////
    /// Methods supporting the Connect/Disconnect from of the QModBus Device
    /// and accompanying RS485 port
    ///////////////////////////////////////////////////////////////////

    //!
    //! \brief ConnectToSerialPort
    //! \param linkConfig
    //! \return
    //!
    void ConnectToSerialPort(const common::comms::SerialConfiguration &config);

    //!
    //! \brief DisconnetFromSerialPort
    //! \return
    //!
    void DisconnetFromSerialPort();


    void WriteToSerialPort(const QByteArray &data) const;

private:
    //////////////////////////////////////////////////////////////
    /// React to ILinkEvents
    //////////////////////////////////////////////////////////////

    void CommunicationUpdate(const common::comms::CommunicationUpdate &update) const override;

    //////////////////////////////////////////////////////////////
    /// Virtual methods imposed from IProtocolQModBusEvents
    //////////////////////////////////////////////////////////////
    void SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const override;

    void ResponseReceived(const QByteArray &buffer) const override;

private:
    std::shared_ptr<QModBusLink> link;
    std::shared_ptr<QModBusProtocol> protocol;
};

} //end of namespace comms_QModBus


#endif // QMODBUS_COMMS_MARSHALER_H
