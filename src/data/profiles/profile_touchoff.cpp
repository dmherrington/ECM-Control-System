#include "profile_state_touchoff.h"

ProfileState_Touchoff::ProfileState_Touchoff(const std::string &name, const std::string &tag, const MotorAxis &axis):
    MotionProfile(name,tag)
{
    setCurrentAxis(axis);
}

ProfileState_Touchoff::ProfileState_Touchoff(const ProfileState_Touchoff &copy):
    MotionProfile(copy)
{
    this->currentCode = copy.currentCode;
    this->currentAxis = copy.currentAxis;
}

MotionProfile::ProfileType ProfileState_Touchoff::getType() const
{
    return ProfileType::TOUCHOFF;
}

void ProfileState_Touchoff::setCurrentCode(const TOUCHOFFProfileCodes &code)
{
    this->currentCode = code;
}

void ProfileState_Touchoff::setCurrentAxis(const MotorAxis &axis)
{
    currentAxis = axis;
}

ProfileState_Touchoff::TOUCHOFFProfileCodes ProfileState_Touchoff::getCurrentCode() const
{
    return this->currentCode;
}

MotorAxis ProfileState_Touchoff::getCurrentAxis() const
{
    return currentAxis;
}
