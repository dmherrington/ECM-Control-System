#ifndef I_PROTOCOL_MUNK_H
#define I_PROTOCOL_MUNK_H

#include <memory>
#include <vector>


namespace comms_Munk{

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


} //end of namespace comms_Munk


#endif // I_PROTOCOL_MUNK_H
