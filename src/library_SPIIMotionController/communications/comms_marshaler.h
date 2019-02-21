#ifndef COMMS_MARSHALER_SPII_H
#define COMMS_MARSHALER_SPII_H

#include "common/publisher.h"

#include <unordered_map>

#include "i_link.h"
#include "SPII_link.h"
#include "protocol_SPII.h"

#include "i_link_events.h"
#include "comms_events.h"

namespace Comms
{

class CommsMarshaler : public Publisher<CommsEvents>, private ILinkEvents, private IProtocolSPIIEvents
{
public:

    CommsMarshaler();

    void requestPosition();

    //////////////////////////////////////////////////////////////
    /// Connect/Disconnect from SPII Methods
    //////////////////////////////////////////////////////////////

    std::shared_ptr<HANDLE> ConnectToSimulation();
    HANDLE ConnectToSerialPort(const common::comms::SerialConfiguration &linkConfig);
    HANDLE ConnectToEthernetPort(const common::comms::TCPConfiguration &linkConfig);
    HANDLE ConnectToPCIPort(const ACSC_PCI_SLOT &linkConfig);


    void DisconnetLink();
    bool isDeviceConnected() const;


    //////////////////////////////////////////////////////////////
    /// Methods issuing SPII commands, requests, programs
    //////////////////////////////////////////////////////////////

    void sendCustomSPIICommands(const std::vector<std::string> &stringCommands);

    //!
    //! \brief Issue a message to a given link
    //!
    //! The type used in the shall be an underlying type which the protocol understands
    //! \param link Link to send message on
    //! \param message Message to send
    //!
    template <typename T>
    void SendSPIIMessage(const T& message);

private:
    //////////////////////////////////////////////////////////////
    /// Virtual methods imposed from ILinkEvents
    //////////////////////////////////////////////////////////////

    void ConnectionUpdate(const common::comms::CommunicationUpdate &update) const override;

    void ConnectionOpened() const override;

    void ConnectionClosed() const override;


private:
    std::shared_ptr<ILink> link;
    std::shared_ptr<SPIIProtocol> protocol;

};

}//END Comms

#endif // COMMS_MARSHALER_SPII_H
