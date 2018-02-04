#ifndef PROTOCOL_MUNK_H
#define PROTOCOL_MUNK_H

#include <memory>
#include <vector>
#include <functional>
#include <math.h>
#include <unordered_map>
#include "iostream"

#include "i_link.h"
#include "i_protocol_rigol_events.h"
#include "i_protocol.h"

#include "common/common.h"

namespace rigol {
namespace comms{

class RigolProtocol : public IProtocol
{

public:
    RigolProtocol();

    void AddListner(const IProtocolRigolEvents* listener);

public:

public:

    //!
    //! \brief Read data incoming from some link
    //!
    //! This code is largely a copy from MAVLinkProtocol::receiveBytes in qgroundcontrol
    //! \param link Link which data was read from
    //! \param buffer data that was read.
    //!
    void ReceiveData(ILink *link, const std::vector<uint8_t> &buffer) override;

private:

    void Emit(const std::function<void(const IProtocolRigolEvents*)> func)
    {
        for(const IProtocolRigolEvents* listener : m_Listners)
            func(listener);
    }

private:
    std::vector<const IProtocolRigolEvents*> m_Listners;

};


} //end of namespace comms
} //end of namespace munk

#endif // PROTOCOL_MUNK_H
