#ifndef PROTOCOL_SPII_H
#define PROTOCOL_SPII_H

#include <memory>
#include <vector>
#include <functional>
#include <math.h>
#include <unordered_map>

#include "ACSC.h"

#include "i_link.h"
#include "i_protocol_SPII_events.h"
#include "i_protocol.h"

#include "../requests/request_components.h"
#include "../status/status_components.h"

#include "common/axis_definitions.h"

#include "i_link.h"

namespace Comms
{

class SPIIProtocol : public IProtocol
{

public:
    SPIIProtocol();

    void updateCommsHandle(std::shared_ptr<HANDLE> commsLink);

    bool requestPosition(const int &axisRequest, double &value);

    bool requestAxisStatus(const int &axisRequest, int &value);

    bool requestMotorStatus(const int &axisRequest, int &value);

public:
    void ReceiveData(ILink *link, const std::vector<uint8_t> &buffer) override;

private:

    void Emit(const std::function<void(const IProtocolSPIIEvents*)> func)
    {
        for(const IProtocolSPIIEvents* listener : m_Listners)
            func(listener);
    }

private:
    std::shared_ptr<HANDLE> m_SPII; /**< Member variable containing a pointer to the SPII interface */

private:
    std::vector<const IProtocolSPIIEvents*> m_Listners;
};


} //end of namespace Comms

#endif // PROTOCOL_SPII_H
