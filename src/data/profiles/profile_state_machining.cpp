#include "profile_state_machining.h"

ProfileState_Machining::ProfileState_Machining(const std::string &name, const std::string &tag):
    MotionProfile(name,tag)
{

}

ProfileState_Machining::ProfileState_Machining(const ProfileState_Machining &copy):
    MotionProfile(copy)
{
    this->currentCode = copy.currentCode;
}

MotionProfile::ProfileType ProfileState_Machining::getType() const
{
    return ProfileType::PROFILE;
}

void ProfileState_Machining::setCurrentCode(const MACHININGProfileCodes &code)
{
    this->currentCode = code;
}

ProfileState_Machining::MACHININGProfileCodes ProfileState_Machining::getCurrentCode() const
{
    return this->currentCode;
}
