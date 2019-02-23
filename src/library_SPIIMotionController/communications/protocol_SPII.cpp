#include "protocol_SPII.h"

#include <iostream>

#include <algorithm>


namespace Comms
{

SPIIProtocol::SPIIProtocol()
{

}

void SPIIProtocol::updateCommsHandle(std::shared_ptr<HANDLE> commsLink)
{
    m_SPII = commsLink;
}

bool SPIIProtocol::requestPosition(const int &axisRequest, double &value)
{
    bool rtnValidity = acsc_GetRPosition(m_SPII.get(),axisRequest,&value,ACSC_SYNCHRONOUS);
    return rtnValidity;
}

bool SPIIProtocol::requestAxisStatus(const int &axisRequest, int &value)
{
    bool rtnValidity = acsc_GetAxisState(m_SPII.get(),axisRequest,&value,ACSC_SYNCHRONOUS);
    return rtnValidity;
}

bool SPIIProtocol::requestMotorStatus(const int &axisRequest, int &value)
{
    bool rtnValidity = acsc_GetMotorState(m_SPII.get(),axisRequest,&value,ACSC_SYNCHRONOUS);
    return rtnValidity;
}

void SPIIProtocol::ReceiveData(ILink *link, const std::vector<uint8_t> &buffer)
{
    UNUSED(link);
    UNUSED(buffer);
}


} //END Comms
