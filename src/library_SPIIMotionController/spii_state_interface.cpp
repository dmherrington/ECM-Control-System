#include "spii_state_interface.h"

SPIIStateInterface::SPIIStateInterface(const std::vector<MotorAxis> &availableAxes):
    m_CB(nullptr)
{
    m_BufferManager = new SPII_CurrentProgram();

    m_MasterVariableValues = new BufferVariableValues();

    m_AvailableAxes = availableAxes;

    for(size_t index = 0; index < availableAxes.size(); index++)
    {
        MotorAxis currentAxis = availableAxes.at(index);
        Status_AxisState currentState(currentAxis);

        m_AxisState.insert(std::pair<MotorAxis, Status_AxisState>(currentAxis, currentState));
    }
}

SPIIStateInterface::~SPIIStateInterface()
{

}
void SPIIStateInterface::updateAxisSettings(const AxisSettings &axisSettings)
{
    //first update the axis settings object member object
    m_AxisSettings = axisSettings;

    //update the available axes object contained within this class to manage the states stored
    m_AxisSettings.updateAvilableAxes(m_AxisSettings.getAvailableAxes());
}

void SPIIStateInterface::updateAvailableAxes(const std::vector<MotorAxis> &availableAxes)
{
    m_AvailableAxes = availableAxes;

    std::map<MotorAxis,Status_AxisState>::iterator it;

    //add items that are not present in the current vector
    for(size_t index = 0; index < availableAxes.size(); index++)
    {
       MotorAxis currentAxis = availableAxes.at(index);
       it = m_AxisState.find(currentAxis);
       if(it == m_AxisState.end()) //if the iterator is at the end, we need to add it to the map
       {
           Status_AxisState currentState(currentAxis);
           m_AxisState.insert(std::pair<MotorAxis, Status_AxisState>(currentAxis, currentState));
       }
    }

    //clear out the axis state if it is not present within the axis vector
    for ( it = m_AxisState.begin(); it != m_AxisState.end(); it++ )
    {
        //see if the current axis is contained within the vector
        for(size_t index = 0; index < availableAxes.size(); index++)
        {
            MotorAxis currentAxis = availableAxes.at(index);
            if(currentAxis == it->first)
                continue;
        }
        //if we made it to this point it is not in the vector and therefore we should remove
        m_AxisState.erase(it);
    }


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


