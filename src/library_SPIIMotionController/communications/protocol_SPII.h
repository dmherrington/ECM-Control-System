#ifndef PROTOCOL_SPII_H
#define PROTOCOL_SPII_H

#include <memory>
#include <vector>
#include <functional>
#include <math.h>
#include <unordered_map>

#include "i_link.h"
#include "i_protocol_SPII_events.h"
#include "i_protocol.h"

namespace Comms
{

class SPIIProtocol : public IProtocol
{

public:
    SPIIProtocol();

public:
    void ReceiveData(ILink *link, const std::vector<uint8_t> &buffer) override;

private:

    void Emit(const std::function<void(const IProtocolSPIIEvents*)> func)
    {
        for(const IProtocolSPIIEvents* listener : m_Listners)
            func(listener);
    }

private:
    std::vector<const IProtocolSPIIEvents*> m_Listners;
};


} //end of namespace Comms

#endif // PROTOCOL_SPII_H
