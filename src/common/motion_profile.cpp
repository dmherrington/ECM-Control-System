#include "motion_profile.h"

MotionProfile::MotionProfile(const std::string &name, const std::string &tag):
    profileName(name), profileTag(tag)
{

}

MotionProfile::MotionProfile(const MotionProfile &copy)
{
    this->profileName = copy.profileName;
    this->profileTag = copy.profileTag;
}
