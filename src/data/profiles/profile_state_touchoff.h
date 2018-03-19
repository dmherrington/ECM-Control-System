#ifndef PROFILESTATE_TOUCHOFF_H
#define PROFILESTATE_TOUCHOFF_H

#include "../motion_profile_state.h"

class ProfileState_Touchoff : public MotionProfile
{
public:
    ProfileState_Touchoff(const std::string &name, const std::string &tag);

    ProfileType getType() const override;

    void setCurrentCode(const TOUCHOFFProfileCodes &code);

    TOUCHOFFProfileCodes getCurrentCode() const;

private:
    TOUCHOFFProfileCodes currentCode;
};
#endif // PROFILESTATE_TOUCHOFF_H
