#ifndef PROFILESTATE_HOMING_H
#define PROFILESTATE_HOMING_H

#include "../motion_profile_state.h"

class ProfileState_Homing : public MotionProfile
{
public:
    enum class HOMINGProfileCodes
    {
        INCOMPLETE = 0,
        COMPLETE = 1
    };

    //!
    //! \brief TOUCHOFFCodesToString
    //! \param code
    //! \return
    //!
    static std::string HOMINGCodesToString(const HOMINGProfileCodes &code) {
        switch (code) {
        case HOMINGProfileCodes::INCOMPLETE:
            return "Home Routine Incomplete.";
        case HOMINGProfileCodes::COMPLETE:
            return "Home Routine Finished.";
        default:
            throw std::runtime_error("Unknown homing profile code seen");
        }
    }

public:
    ProfileState_Homing(const std::string &name, const std::string &tag, const ProfileType &type = ProfileType::MOVE_TO_HOME);

    ProfileType getType() const override;

    void setCurrentCode(const HOMINGProfileCodes &code);

    HOMINGProfileCodes getCurrentCode() const;

private:
    ProfileType homingType;

    HOMINGProfileCodes currentCode;
};

#endif // PROFILESTATE_HOMING_H
