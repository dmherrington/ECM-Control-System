#ifndef RIGOL_COMMS_MARSHALER_H
#define RIGOL_COMMS_MARSHALER_H

#include "common/publisher.h"

#include <unordered_map>

#include "i_link.h"
#include "tcp_configuration.h"
#include "rigol_tcp_link.h"
#include "protocol_rigol.h"

#include "i_link_events.h"
#include "comms_events.h"

#include "commands/acquire/acquire_components.h"

#include "commands/measure/measure_command_item.h"

namespace comms_Rigol{

class RigolCommsMarshaler : public Publisher<CommsEvents>, private ILinkEvents, private IProtocolRigolEvents
{
public:

    RigolCommsMarshaler();

    virtual ~RigolCommsMarshaler();
    //////////////////////////////////////////////////////////////
    /// Connect/Disconnect from Rigol Methods
    //////////////////////////////////////////////////////////////

    //!
    //! \brief Connect to an already created link
    //! \param linkName Name of link to connect to
    //! \return True if connection successful, false otherwise
    //!
    bool ConnectToLink(const TCPConfiguration &linkConfig);
    bool DisconnetFromLink();
    bool isDeviceConnected() const;

    void sendAbstractAcquireCommand(const commands_Rigol::AbstractAcquireCommandPtr command);

    void sendSetMeasurementCommand(const commands_Rigol::MeasureCommand_Item &command);

    void sendMeasurementRequest(const commands_Rigol::MeasureCommand_Item &command);


    ///////////////////////////////////////////////////////////////////
    /// Methods issuing something to rigol
    ///////////////////////////////////////////////////////////////////
    void EmitByteArray(const QByteArray &data_Rigol);


private:
    //////////////////////////////////////////////////////////////
    /// React to Link Events
    //////////////////////////////////////////////////////////////

    void ConnectionUpdate(const common::comms::CommunicationUpdate &update) const override;

    void ConnectionOpened() const override;

    void ConnectionClosed() const override;

    void ReceiveData(const std::vector<uint8_t> &buffer) const override;

    void CommunicationError(const std::string &type, const std::string &msg) const override;

    void CommunicationUpdate(const std::string &name, const std::string &msg) const override;

    //////////////////////////////////////////////////////////////
    /// Virtual methods imposed from IProtocolRigolEvents
    //////////////////////////////////////////////////////////////
    void ResponseReceived(const ILink* link_ptr, const std::vector<uint8_t> &buffer) const override;
    void NewMeaurementReceived(const ILink* link_ptr, const commands_Rigol::RigolMeasurementStatus &status) const override;

private:
    std::shared_ptr<ILink> link;
    std::shared_ptr<RigolProtocol> protocol;

};

} //end of namespace comms


#endif // RIGOL_COMMS_MARSHALER_H
