#ifndef RIGOL_I_LINK_EVENTS_H
#define RIGOL_I_LINK_EVENTS_H

#include <cstdlib>
#include <vector>
#include <string>

#include "common/comms/communication_update.h"

#include "commands/measure/rigol_measurement_status.h"

namespace comms_Rigol{

class ILink;

class ILinkEvents
{
public:


    virtual void ConnectionUpdate(const common::comms::CommunicationUpdate &update) const = 0;

    virtual void ConnectionOpened() const = 0;

    virtual void ConnectionClosed() const = 0;

    virtual void ReceiveData(const std::vector<uint8_t> &buffer) const = 0;

    virtual void CommunicationError(const std::string &type, const std::string &msg) const = 0;

    virtual void CommunicationUpdate(const std::string &name, const std::string &msg) const = 0;
};

} //end of namespace comms


#endif // RIGOL_I_LINK_EVENTS_H
