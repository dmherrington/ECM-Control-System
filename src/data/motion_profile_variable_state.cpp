#include "motion_profile_variable_state.h"

namespace common_data {

ProfileVariableState::ProfileVariableState()
{

}

ProfileVariableState::ProfileVariableState(const std::string &name, const double &value, const std::string &unit)
{
    this->variableName = name;
    this->variableUnit = unit;
    this->variableValue = value;
}

ProfileVariableState::ProfileVariableState(const ProfileVariableState &copy)
{
    this->variableName = copy.variableName;
    this->variableUnit = copy.variableUnit;
    this->variableValue = copy.variableValue;
}

void ProfileVariableState::setVariableName(const std::string &name)
{
    this->variableName = name;
}

void ProfileVariableState::setVariableUnit(const std::string &unit)
{
    this->variableUnit = unit;
}

void ProfileVariableState::setVariableValue(const double &value)
{
    this->variableValue = value ;
}

std::string ProfileVariableState::getVariableName() const
{
    return this->variableName;
}

std::string ProfileVariableState::getVariableUnit() const
{
    return this->variableUnit;
}


double ProfileVariableState::getVariableValue() const
{
    return variableValue;
}

std::string ProfileVariableState::getLoggingString() const
{
    std::string rtnStr = variableName + "\t" + std::to_string(variableValue) + "\t" + variableUnit;
    return rtnStr;
}


MotionProfileVariableState::MotionProfileVariableState():
    m_allocated(false)
{
    Allocate();
}

MotionProfileVariableState::MotionProfileVariableState(const MotionProfileVariableState &copy)
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
MotionProfileVariableState::~MotionProfileVariableState()
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
MotionProfileVariableState& MotionProfileVariableState::operator =(const MotionProfileVariableState &rhs)
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
std::shared_ptr<ProfileVariableState> MotionProfileVariableState::getProfileStateVariable() const
{
    return this->profileVariableData;
}

//!
//! \brief set sensor data held in this object
//! \param sensorData Data to set to
//!
void MotionProfileVariableState::setProfileStateVariable(const std::shared_ptr<ProfileVariableState> &variableData)
{
    this->profileVariableData = variableData;
}


//!
//! \brief SensorState::getObservationTime
//! \return
//!
common::EnvironmentTime MotionProfileVariableState::getObservationTime() const
{
    return this->observationTime;
}

//!
//! \brief SensorState::setObservationTime
//! \param time
//!
void MotionProfileVariableState::setObservationTime(const common::EnvironmentTime &time)
{
    this->observationTime = time;
}

//!
//! \brief Allocate space for dynamic structure to be held
//!
void MotionProfileVariableState::Allocate()
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
void MotionProfileVariableState::Deallocate()
{
    if(m_allocated)
    {
        delete ref_count;

        m_allocated = false;
    }
}

} //end of namespace common_data
