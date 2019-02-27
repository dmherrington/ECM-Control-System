#ifndef COMMS_MARSHALER_SPII_H
#define COMMS_MARSHALER_SPII_H

#include "common/publisher.h"

#include <unordered_map>

#include "i_link.h"
#include "SPII_link.h"
#include "protocol_SPII.h"

#include "i_link_events.h"
#include "comms_events.h"
#include "spii_settings.h"

namespace Comms
{

class CommsMarshaler : public Publisher<CommsEvents>, private ILinkEvents, private IProtocolSPIIEvents
{
public:

    CommsMarshaler();

public:
    bool commandMotionStop(const CommandStop &stop);

    bool commandMotorDisable(const CommandMotorDisable &disable);

    bool commandMotorEnable(const CommandMotorEnable &enable);

public:
    std::vector<Status_PerAxis> requestAxisState(const RequestAxisStatus* request);

    std::vector<Status_MotorPerAxis> requestMotorState(const RequestMotorStatus* request);

    std::vector<Status_PositionPerAxis> requestPosition(const RequestTellPosition* request);

    //////////////////////////////////////////////////////////////
    /// Connect/Disconnect from SPII Methods
    //////////////////////////////////////////////////////////////

    bool ConnectToSimulation(SPII_Settings &deviceSettings);
    SPII_Settings ConnectToSerialPort(const common::comms::SerialConfiguration &linkConfig);
    SPII_Settings ConnectToEthernetPort(const common::comms::TCPConfiguration &linkConfig);
    SPII_Settings ConnectToPCIPort(const ACSC_PCI_SLOT &linkConfig);


    void DisconnetLink();
    bool isDeviceConnected() const;


    //////////////////////////////////////////////////////////////
    /// Methods issuing SPII commands, requests, programs
    //////////////////////////////////////////////////////////////

    void sendCustomSPIICommands(const std::vector<std::string> &stringCommands);
    void sendAbstractSPIICommand(const AbstractCommandPtr command);
    void sendAbstractSPIIMotionCommand(const AbstractCommandPtr command);

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

    void NewBufferState(const Status_BufferState &state)const override;


private:
    std::shared_ptr<ILink> link;
    std::shared_ptr<SPIIProtocol> protocol;

};

}//END Comms

#endif // COMMS_MARSHALER_SPII_H
