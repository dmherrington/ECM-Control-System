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

std::vector<SPII::Status_PositionPerAxis> SPIIProtocol::requestPosition(const MotorAxis &axis)
{
    std::vector<SPII::Status_PositionPerAxis> rtnStatus;

    switch (axis) {
        case MotorAxis::ALL:
    {

        break;
    }
    case MotorAxis::X:
    case MotorAxis::Y:
    case MotorAxis::Z:
    {
        double referencePosition;
        if(acsc_GetRPosition(m_SPII.get(),ACSC_AXIS_0,&referencePosition,ACSC_SYNCHRONOUS))
        {
            SPII::Status_PositionPerAxis newPosition;
            newPosition.setAxis(axis);
            newPosition.setPosition(referencePosition);
            rtnStatus.push_back(newPosition);
        }
        break;
    }

    }

    return rtnStatus;
}

std::vector<SPII::Status_PerAxis> SPIIProtocol::requestAxisStatus(const MotorAxis &axis)
{

}

std::vector<SPII::Status_MotorPerAxis> SPIIProtocol::requestMotorStatus(const MotorAxis &axis)
{

}

void SPIIProtocol::ReceiveData(ILink *link, const std::vector<uint8_t> &buffer)
{

}


} //END Comms
