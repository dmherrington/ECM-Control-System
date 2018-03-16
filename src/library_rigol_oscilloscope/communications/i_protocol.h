#ifndef RIGOL_I_PROTOCOL_H
#define RIGOL_I_PROTOCOL_H

#include <memory>
#include <vector>

namespace comms_Rigol{

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


#endif // RIGOL_I_PROTOCOL_H
