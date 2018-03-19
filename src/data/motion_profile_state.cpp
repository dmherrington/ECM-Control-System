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

MotionProfileState::MotionProfileState()
{

}

void MotionProfileState::ConstructProfileState(const ProfileType &type, const std::string &name, const std::string &tag)
{

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
