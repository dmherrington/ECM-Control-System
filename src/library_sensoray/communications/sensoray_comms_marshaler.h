#ifndef SENSORAY_COMMS_MARSHALER_H
#define SENSORAY_COMMS_MARSHALER_H

#include "common/publisher.h"
#include "common/comms/serial_configuration.h"

#include <unordered_map>

#include "i_link.h"
#include "sensoray_tcp_configuration.h"
#include "sensoray_link.h"
#include "protocol_sensoray.h"
#include "i_link_events.h"
#include "i_protocol_sensoray_events.h"
#include "comms_events.h"



namespace comms_Sensoray{

class CommsMarshaler : public Publisher<CommsEvents>, private ILinkEvents, private IProtocolSensorayEvents
{
public:

    CommsMarshaler();

    virtual ~CommsMarshaler();
    ///////////////////////////////////////////////////////////////////
    /// Methods supporting the Connect/Disconnect from Sensoray Device
    ///////////////////////////////////////////////////////////////////

    //!
    //! \brief Connect to an already created link
    //! \param linkName Name of link to connect to
    //! \return True if connection successful, false otherwise
    //!
    bool ConnectToLink(const SensorayTCPConfiguration &linkConfig);

    //!
    //! \brief DisconnetFromLink
    //! \return
    //!
    bool DisconnetFromLink();

    ///////////////////////////////////////////////////////////////////
    /// Methods supporting the Connect/Disconnect from of the Sensory Device
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

    ///////////////////////////////////////////////////////////////////
    /// Methods issuing something to the sensoray
    ///////////////////////////////////////////////////////////////////
    void resetSensorayIO();

private:
    //////////////////////////////////////////////////////////////
    /// React to Link Events
    //////////////////////////////////////////////////////////////

    void ConnectionOpened() const override;

    void ConnectionClosed() const override;

    void CommunicationError(const std::string &type, const std::string &msg) const override;

    void CommunicationUpdate(const std::string &name, const std::string &msg) const override;

    //////////////////////////////////////////////////////////////
    /// Virtual methods imposed from IProtocolSensorayEvents
    //////////////////////////////////////////////////////////////
    void ResponseReceived(const QByteArray &buffer) const override;
    void SerialPortConnectionUpdate(const common::comms::CommunicationConnection &connection) const override;
    void SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const override;

private:
    SensoraySession* m_Session;
    std::shared_ptr<SensorayLink> link;
    std::shared_ptr<SensorayProtocol> protocol;

};

} //end of namespace comms


#endif // SENSORAY_COMMS_MARSHALER_H
