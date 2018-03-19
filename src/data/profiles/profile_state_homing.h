#ifndef PROFILESTATE_HOMING_H
#define PROFILESTATE_HOMING_H

#include "../motion_profile_state.h"

class ProfileState_Homing : public MotionProfile
{
public:
    ProfileState_Homing(const std::string &name, const std::string &tag);

    ProfileType getType() const override;

    void setCurrentCode(const HOMINGProfileCodes &code);

    HOMINGProfileCodes getCurrentCode() const;

private:
    HOMINGProfileCodes currentCode;
};

#endif // PROFILESTATE_HOMING_H
