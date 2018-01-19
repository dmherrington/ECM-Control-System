#ifndef I_PROTOCOL_H
#define I_PROTOCOL_H

#include <memory>
#include <vector>

namespace Comms
{

class ILink;

class IProtocol
{
public:
    virtual void ReceiveData(ILink *link, const std::vector<uint8_t> &buffer) = 0;

};


} //END MAVLINKComms

#endif // I_PROTOCOL_H
