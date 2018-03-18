#ifndef PROFILE_HOMING_H
#define PROFILE_HOMING_H

#include "../motion_profile_state.h"

class Profile_Homing : public MotionProfile
{
public:
    Profile_Homing(const std::string &name, const std::string &tag);

    ProfileType getType() const override;

    void setCurrentCode(const HOMINGProfileCodes &code);

    HOMINGProfileCodes getCurrentCode() const;

private:
    HOMINGProfileCodes currentCode;
};

#endif // PROFILE_HOMING_H
