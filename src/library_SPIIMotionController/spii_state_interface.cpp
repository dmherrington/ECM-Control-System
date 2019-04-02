#include "spii_state_interface.h"

SPIIStateInterface::SPIIStateInterface(const std::vector<MotorAxis> &availableAxis):
    m_CB(nullptr)
{
    m_BufferManager = new BufferManager();

    m_MasterVariableValues = new BufferVariableValues();

    m_AxisStatus = new Status_Axis();

    m_MotorStatus = new Status_Motor();

    m_AxisPosition = new Status_Position();

}

SPIIStateInterface::~SPIIStateInterface()
{

}

Status_PerAxis* SPIIStateInterface::getAxisStatus(const MotorAxis &axis)
{

}

void SPIIStateInterface::setHomeInidcated(const bool &val)
{
    this->indicatedHome = val;
    if(m_CB)
        m_CB->cbi_SPIIHomeIndicated(this->indicatedHome);
}

bool SPIIStateInterface::isHomeInidcated() const
{
    return this->indicatedHome;
}


void SPIIStateInterface::setTouchoffIndicated(const bool &val)
{
    this->indicatedTouchoff = val;
    if(m_CB)
        m_CB->cbi_SPIITouchoffIndicated(this->indicatedTouchoff);
}

bool SPIIStateInterface::isTouchoffIndicated() const
{
    return this->indicatedTouchoff;
}


bool SPIIStateInterface::isMotorInMotion() const
{
    return m_MotorStatus->areAnyMotorsMoving();
}

bool SPIIStateInterface::isMotorEnabled() const
{       
    return m_MotorStatus->areAnyMotorsEnabled();
}

bool SPIIStateInterface::isEStopEngaged() const
{
    bool EStopEngaged = false;

    return EStopEngaged;
}


