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
    //!
    virtual void ReceiveData(const ILink *link) = 0;

};


} //end of namespace comms_Munk


#endif // I_PROTOCOL_MUNK_H
