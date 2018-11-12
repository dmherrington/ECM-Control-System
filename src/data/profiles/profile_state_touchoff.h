#ifndef PROFILESTATE_TOUCHOFF_H
#define PROFILESTATE_TOUCHOFF_H

#include "../motion_profile_state.h"

class ProfileState_Touchoff : public MotionProfile
{
public:
    enum class TOUCHOFFProfileCodes
    {
        SEARCHING = 0,
        FINISHED = 1,
        ERROR_POSITIONAL = 2,
        ERROR_INCONSISTENT = 3,
        ERROR_TOUCHING = 4,
        ABORTED = 5,
        CLEARED = 6
    };

    //!
    //! \brief TOUCHOFFCodesToString
    //! \param code
    //! \return
    //!
    static std::string TOUCHOFFCodesToString(const TOUCHOFFProfileCodes &code) {
        switch (code) {
        case TOUCHOFFProfileCodes::SEARCHING:
            return "Touchoff Searching.";
        case TOUCHOFFProfileCodes::FINISHED:
            return "Touchoff Finished.";
        case TOUCHOFFProfileCodes::ERROR_POSITIONAL:
            return "Touchoff Error: Positional Error Limit Exceeded";
        case TOUCHOFFProfileCodes::ERROR_INCONSISTENT:
            return "Touchoff Error: Inconsistent values.";
        case TOUCHOFFProfileCodes::ERROR_TOUCHING:
            return "Touchoff Error: Already touching.";
        case TOUCHOFFProfileCodes::ABORTED:
            return "Touchoff Error: Operation aborted.";
        default:
            throw std::runtime_error("Unknown touchoff profile code seen");
        }
    }

public:
    ProfileState_Touchoff(const std::string &name, const std::string &tag);

    ProfileState_Touchoff(const ProfileState_Touchoff &copy);

    ProfileType getType() const override;

    void setCurrentCode(const TOUCHOFFProfileCodes &code);

    TOUCHOFFProfileCodes getCurrentCode() const;

private:
    TOUCHOFFProfileCodes currentCode = TOUCHOFFProfileCodes::SEARCHING;
};
#endif // PROFILESTATE_TOUCHOFF_H
