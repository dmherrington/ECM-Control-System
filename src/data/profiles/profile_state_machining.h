#ifndef PROFILE_STATE_MACHINING_H
#define PROFILE_STATE_MACHINING_H

#include "../motion_profile_state.h"

class ProfileState_Machining : public MotionProfile
{
public:
    enum class MACHININGProfileCodes
    {
        INCOMPLETE = 0,
        COMPLETE = 1,
        ABORTED = 2
    };

    //!
    //! \brief TOUCHOFFCodesToString
    //! \param code
    //! \return
    //!
    static std::string MACHININGCodesToString(const MACHININGProfileCodes &code) {
        switch (code) {
        case MACHININGProfileCodes::INCOMPLETE:
            return "Machining Routine Incomplete.";
        case MACHININGProfileCodes::COMPLETE:
            return "Machining Routine Finished.";
        case MACHININGProfileCodes::ABORTED:
            return "Machining Routine has been Aborted.";
        default:
            throw std::runtime_error("Unknown machining profile code seen");
        }
    }

public:
    ProfileState_Machining(const std::string &name, const std::string &tag);

    ProfileState_Machining(const ProfileState_Machining &copy);

    ProfileType getType() const override;

    void setCurrentCode(const MACHININGProfileCodes &code);

    MACHININGProfileCodes getCurrentCode() const;

private:
    MACHININGProfileCodes currentCode;
};

#endif // PROFILE_STATE_MACHINING_H
