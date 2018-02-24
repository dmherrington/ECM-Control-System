#ifndef I_PROTOCOL_H
#define I_PROTOCOL_H

#include <memory>
#include <vector>

namespace rigol {
namespace comms{

class ILink;

class IProtocol
{
public:
    //!
    //! \brief ReceiveData
    //! \param link
    //! \param buffer
    //!
    virtual void ReceiveData(ILink *link, const std::vector<uint8_t> &buffer) = 0;
};


} //end of namespace comms
} //end of namespace rigol

#endif // I_PROTOCOL_H
