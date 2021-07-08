#include "spii_state_interface.h"

SPIIStateInterface::SPIIStateInterface(const std::vector<MotorAxis> &availableAxis):
    m_CB(nullptr)
{
    m_BufferManager = new SPII_CurrentProgram();

    m_MasterVariableValues = new BufferVariableValues();

    for(size_t index = 0; index < availableAxis.size(); index++)
    {
        MotorAxis currentAxis = availableAxis.at(index);
        Status_AxisState currentState(currentAxis);

        m_AxisState.insert(std::pair<MotorAxis, Status_AxisState>(currentAxis, currentState));
    }
}

SPIIStateInterface::~SPIIStateInterface()
{

}
std::vector<double> SPIIStateInterface::getAxisPositionVector() const
{
    std::vector<double> currentPositions;

    std::map<MotorAxis, Status_AxisState>::const_iterator it;

    for ( it = m_AxisState.begin(); it != m_AxisState.end(); it++ )
    {
        currentPositions.push_back(it->second.getAxisPosition());
    }

    return currentPositions;
}

bool SPIIStateInterface::getAxisPosition(const MotorAxis &axis, double &position) const
{
    std::map<MotorAxis, Status_AxisState>::const_iterator it;

    bool validRequest = false;

    it = m_AxisState.find(axis);
    if (it != m_AxisState.end())
    {
        validRequest = true;
        position = it->second.getAxisPosition();
    }

    return validRequest;
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

bool SPIIStateInterface::areAnyMotorsInMotion() const
{
    std::map<MotorAxis, Status_AxisState>::const_iterator it;

    for ( it = m_AxisState.begin(); it != m_AxisState.end(); it++ )
    {
        if((it->second.m_MotorStatus.get().isMotorMoving()) && (it->first != MotorAxis::Y))
            return true;
    }
    return false;
}

bool SPIIStateInterface::areAnyMotorsEnabled() const
{
    std::map<MotorAxis, Status_AxisState>::const_iterator it;

    for ( it = m_AxisState.begin(); it != m_AxisState.end(); it++ )
    {
        if(it->second.m_MotorStatus.get().isMotorEnabled())
            return true;
    }
    return false;
}

bool SPIIStateInterface::areAllMotorsEnabled() const
{
    std::map<MotorAxis, Status_AxisState>::const_iterator it;

    for ( it = m_AxisState.begin(); it != m_AxisState.end(); it++ )
    {
        if(!it->second.m_MotorStatus.get().isMotorEnabled())
            return false;
    }
    return true;
}

bool SPIIStateInterface::isEStopEngaged() const
{
    return m_SystemFaults.get().isHardwareEmergencyStop();
}


