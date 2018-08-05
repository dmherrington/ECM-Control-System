#include "profile_state_touchoff.h"

ProfileState_Touchoff::ProfileState_Touchoff(const std::string &name, const std::string &tag):
    MotionProfile(name,tag)
{

}

ProfileState_Touchoff::ProfileState_Touchoff(const ProfileState_Touchoff &copy):
    MotionProfile(copy)
{
    this->currentCode = copy.currentCode;
}

MotionProfile::ProfileType ProfileState_Touchoff::getType() const
{
    return ProfileType::TOUCHOFF;
}

void ProfileState_Touchoff::setCurrentCode(const TOUCHOFFProfileCodes &code)
{
    this->currentCode = code;
}

ProfileState_Touchoff::TOUCHOFFProfileCodes ProfileState_Touchoff::getCurrentCode() const
{
    return this->currentCode;
}
