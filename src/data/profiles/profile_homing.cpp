#include "profile_homing.h"

Profile_Homing::Profile_Homing(const std::string &name, const std::string &tag):
    MotionProfile(name,tag)
{

}

ProfileType Profile_Homing::getType() const
{
    return ProfileType::HOMING;
}

void Profile_Homing::setCurrentCode(const HOMINGProfileCodes &code)
{
    this->currentCode = code;
}

HOMINGProfileCodes Profile_Homing::getCurrentCode() const
{
    return this->currentCode;
}
