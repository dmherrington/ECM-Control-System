#include "profile_state_homing.h"

ProfileState_Homing::ProfileState_Homing(const std::string &name, const std::string &tag):
    MotionProfile(name,tag)
{

}

MotionProfile::ProfileType ProfileState_Homing::getType() const
{
    return ProfileType::HOMING;
}

void ProfileState_Homing::setCurrentCode(const HOMINGProfileCodes &code)
{
    this->currentCode = code;
}

ProfileState_Homing::HOMINGProfileCodes ProfileState_Homing::getCurrentCode() const
{
    return this->currentCode;
}
