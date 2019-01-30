#ifndef I_PROTOCOL_SPII_H
#define I_PROTOCOL_SPII_H

#include <memory>
#include <vector>

namespace Comms
{

class ILink;

class IProtocol
{
public:
    IProtocol() = default;
    virtual ~IProtocol() = default;

public:
    virtual void ReceiveData(ILink *link, const std::vector<uint8_t> &buffer) = 0;

};


} //end of namespace Comms

#endif // I_PROTOCOL_SPII_H
