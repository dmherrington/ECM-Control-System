#ifndef PROFILE_STATE_MACHINING_H
#define PROFILE_STATE_MACHINING_H

#include "common/common.h"
#include "common/class_forward.h"

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
            return "MACHINING OPERATION INCOMPLETE.";
        case MACHININGProfileCodes::COMPLETE:
            return "MACHINING OPERATION COMPLETED.";
        case MACHININGProfileCodes::ABORTED:
            return "MACHINING OPERATION ABORTED.";
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

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ProfileState_Machining& operator = (const ProfileState_Machining &rhs)
    {
        MotionProfile::operator =(rhs);
        this->currentCode = rhs.currentCode;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ProfileState_Machining &rhs)
    {
        if(!MotionProfile::operator ==(rhs)){
            return false;
        }
        if(this->currentCode != rhs.currentCode){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ProfileState_Machining &rhs) {
        return !(*this == rhs);
    }
private:
    MACHININGProfileCodes currentCode;
};

#endif // PROFILE_STATE_MACHINING_H
