#ifndef I_PROTOCOL_MUNK_H
#define I_PROTOCOL_MUNK_H

#include <memory>
#include <vector>

#include "munk_message.h"

namespace comms_Munk{

class ILink;

class IProtocol
{
public:
    //!
    //! \brief ReceiveData
    //! \param link
    //!
    virtual bool ReceiveData(const ILink *link, MunkMessage &returnMessage) = 0;

};


} //end of namespace comms_Munk


#endif // I_PROTOCOL_MUNK_H
