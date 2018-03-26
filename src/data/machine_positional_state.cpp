#include "machine_positional_state.h"

namespace common_data {

PositionalState::PositionalState()
{

}

PositionalState::PositionalState(const std::string &name, const double &value)
{
    this->variableName = name;
    this->variableValue = value;
}

PositionalState::PositionalState(const PositionalState &copy)
{
    this->variableName = copy.variableName;
    this->variableValue = copy.variableValue;
}

void PositionalState::setVariableName(const std::string &name)
{
    this->variableName = name;
}

void PositionalState::setVariableValue(const double &value)
{
    this->variableValue = value ;
}

std::string PositionalState::getVariableName() const
{
    return this->variableName;
}

double PositionalState::getVariableValue() const
{
    return variableValue;
}

std::string PositionalState::getLoggingString() const
{
    std::string rtnStr = variableName + "\t" + std::to_string(variableValue);
    return rtnStr;
}


MachinePositionalState::MachinePositionalState():
    m_allocated(false)
{
    Allocate();
}

MachinePositionalState::MachinePositionalState(const MachinePositionalState &copy)
{
    this->observationTime = copy.observationTime;
    this->ref_count = copy.ref_count;

    if(m_allocated)
        *ref_count = *ref_count + 1;

    this->profileVariableData = copy.profileVariableData;
}

/*!
 * \brief Destructor
 *
 * Delete the sensor object if it is set.
 */
MachinePositionalState::~MachinePositionalState()
{
    if(m_allocated == false)
        return;

    //if there is one reference (itself) Deallocate the sensor because its about to dissapear anyway
    if(*ref_count == 1)
    {
        this->Deallocate();
    }
}

//!
//! \brief Assignment operator
//! \param that Object to assing from
//! \return reference to assigned object
//!
MachinePositionalState& MachinePositionalState::operator =(const MachinePositionalState &rhs)
{
    // if the object being replaced, it may need to be deallocated before replaced.
    if(m_allocated == true)
    {
        *ref_count = *ref_count - 1;
        if(*ref_count == 0)
            this->Deallocate();
    }

    m_allocated = rhs.m_allocated;
    observationTime = rhs.observationTime;
    ref_count = rhs.ref_count;

    if(m_allocated)
        *ref_count = *ref_count + 1;

    this->profileVariableData = rhs.profileVariableData;

    return *this;
}

//!
//! \brief Get a pointer to the sensor data held by this state.
//! \return Pointer to data, Null if no data provided.
//!
std::shared_ptr<PositionalState> MachinePositionalState::getPositionalState() const
{
    return this->profileVariableData;
}

//!
//! \brief set sensor data held in this object
//! \param sensorData Data to set to
//!
void MachinePositionalState::setPositionalState(const std::shared_ptr<PositionalState> &positionalData)
{
    this->profileVariableData = positionalData;
}


//!
//! \brief SensorState::getObservationTime
//! \return
//!
common::EnvironmentTime MachinePositionalState::getObservationTime() const
{
    return this->observationTime;
}

//!
//! \brief SensorState::setObservationTime
//! \param time
//!
void MachinePositionalState::setObservationTime(const common::EnvironmentTime &time)
{
    this->observationTime = time;
}

//!
//! \brief Allocate space for dynamic structure to be held
//!
void MachinePositionalState::Allocate()
{
    if(m_allocated == true)
        return;

    observationTime = common::EnvironmentTime();
    ref_count = new uint();

    *ref_count = 1;

    m_allocated = true;

    this->profileVariableData = nullptr;
}

//!
//! \brief Delete dynamic data held by this object
//!
void MachinePositionalState::Deallocate()
{
    if(m_allocated)
    {
        delete ref_count;

        m_allocated = false;
    }
}

} //end of namespace common_data
