#ifndef SENSORAY_COMMS_MARSHALER_H
#define SENSORAY_COMMS_MARSHALER_H

#include "common/publisher.h"

#include <unordered_map>

#include "i_link.h"
#include "sensoray_tcp_configuration.h"
#include "sensoray_tcp_link.h"
#include "protocol_sensoray.h"
#include "i_link_events.h"
#include "i_protocol_sensoray_events.h"
#include "comms_events.h"

namespace sensoray {
namespace comms{

class CommsMarshaler : public Publisher<CommsEvents>, private ILinkEvents, private IProtocolSensorayEvents
{
public:

    CommsMarshaler();

    virtual ~CommsMarshaler();
    //////////////////////////////////////////////////////////////
    /// Connect/Disconnect from Sensoray Methods
    //////////////////////////////////////////////////////////////

    //!
    //! \brief Connect to an already created link
    //! \param linkName Name of link to connect to
    //! \return True if connection successful, false otherwise
    //!
    bool ConnectToLink(const SensorayTCPConfiguration &linkConfig);
    bool DisconnetFromLink();


    ///////////////////////////////////////////////////////////////////
    /// Methods issuing something to the sensoray
    ///////////////////////////////////////////////////////////////////
    void EmitByteArray(const QByteArray &data);

    void resetSensorayIO();

private:
    //////////////////////////////////////////////////////////////
    /// React to Link Events
    //////////////////////////////////////////////////////////////

    void ConnectionOpened() const override;

    void ConnectionClosed() const override;

    void ReceiveData(const std::vector<uint8_t> &buffer) const override;

    void CommunicationError(const std::string &type, const std::string &msg) const override;

    void CommunicationUpdate(const std::string &name, const std::string &msg) const override;

    //////////////////////////////////////////////////////////////
    /// Virtual methods imposed from IProtocolSensorayEvents
    //////////////////////////////////////////////////////////////
    void ResponseReceived(const ILink* link_ptr, const std::vector<uint8_t> &buffer) const override;

private:
    std::shared_ptr<ILink> link;
    std::shared_ptr<SensorayProtocol> protocol;

};

} //end of namespace comms
} //end of namespace sensoray

#endif // SENSORAY_COMMS_MARSHALER_H
