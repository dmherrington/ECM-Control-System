#include "motion_profile_state.h"

MotionProfile::MotionProfile(const std::string &name, const std::string &tag):
    profileName(name), profileTag(tag)
{

}

MotionProfile::MotionProfile(const MotionProfile &copy)
{
    this->profileName = copy.profileName;
    this->profileTag = copy.profileTag;
}

MotionProfileState::MotionProfileState():
    m_allocated(false)
{
    Allocate();
}

MotionProfileState::MotionProfileState(const MotionProfileState &copy)
{
    this->validityTime = copy.validityTime;
    this->ref_count = copy.ref_count;

    if(m_allocated)
        *ref_count = *ref_count + 1;

    this->profileStateData = copy.profileStateData;
}

/*!
 * \brief Destructor
 *
 * Delete the sensor object if it is set.
 */
MotionProfileState::~MotionProfileState()
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
MotionProfileState& MotionProfileState::operator =(const MotionProfileState &rhs)
{
    // if the object being replaced, it may need to be deallocated before replaced.
    if(m_allocated == true)
    {
        *ref_count = *ref_count - 1;
        if(*ref_count == 0)
            this->Deallocate();
    }

    m_allocated = rhs.m_allocated;
    validityTime = rhs.validityTime;
    ref_count = rhs.ref_count;

    if(m_allocated)
        *ref_count = *ref_count + 1;

    this->profileStateData = rhs.profileStateData;

    return *this;
}

//!
//! \brief Get a pointer to the sensor data held by this state.
//! \return Pointer to data, Null if no data provided.
//!
std::shared_ptr<MotionProfile> MotionProfileState::getProfileState() const
{
    return this->profileStateData;
}

//!
//! \brief set sensor data held in this object
//! \param sensorData Data to set to
//!
void MotionProfileState::setProfileState(const std::shared_ptr<MotionProfile> &profileData)
{
    this->profileStateData = profileData;
}


//!
//! \brief Allocate space for dynamic structure to be held
//!
void MotionProfileState::Allocate()
{
    if(m_allocated == true)
        return;

    validityTime = new common::EnvironmentTime();
    ref_count = new uint();

    *ref_count = 1;

    m_allocated = true;

    this->profileStateData = nullptr;
}

//!
//! \brief Delete dynamic data held by this object
//!
void MotionProfileState::Deallocate()
{
    if(m_allocated)
    {
        delete validityTime;
        delete ref_count;

        m_allocated = false;
    }
}
