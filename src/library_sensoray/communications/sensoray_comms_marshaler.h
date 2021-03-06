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

/**
\* @file  sensoray_comms_marshaler.h
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

    bool isLinkConnected() const;

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

    void readSensoaryADC();

private:
    //////////////////////////////////////////////////////////////
    /// React to ILinkEvents
    //////////////////////////////////////////////////////////////

    void CommunicationUpdate(const common::comms::CommunicationUpdate &update) const override;

    //////////////////////////////////////////////////////////////
    /// Virtual methods imposed from IProtocolSensorayEvents
    //////////////////////////////////////////////////////////////

    //!
    //! \brief SerialPortStatusUpdate
    //! \param update
    //!
    void SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const override;

    //!
    //! \brief ResponseReceived
    //! \param buffer
    //!
    void ResponseReceived(const QByteArray &buffer) const override;

    //!
    //! \brief UpdateFromADC
    //! \param data
    //!
    void UpdateFromADC(const std::vector<S2426_ADC_SAMPLE> data) const override;

private:
    SensoraySession* m_Session;
    std::shared_ptr<SensorayLink> link;
    std::shared_ptr<SensorayProtocol> protocol;
};

} //end of namespace comms


#endif // SENSORAY_COMMS_MARSHALER_H
