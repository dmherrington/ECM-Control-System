#ifndef PROFILE_TOUCHOFF_H
#define PROFILE_TOUCHOFF_H

#include "../motion_profile_state.h"

class Profile_Touchoff : public MotionProfile
{
public:
    Profile_Touchoff(const std::string &name, const std::string &tag);

    ProfileType getType() const override;

    void setCurrentCode(const TOUCHOFFProfileCodes &code);

    TOUCHOFFProfileCodes getCurrentCode() const;

private:
    TOUCHOFFProfileCodes currentCode;
};
#endif // PROFILE_TOUCHOFF_H
