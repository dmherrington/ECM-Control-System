#ifndef MOTION_PROFILE_H
#define MOTION_PROFILE_H

#include <stdexcept>

#include "string"
#include "memory"

#include "environment_time.h"

class MotionProfile
{
public:
    enum class ProfileType
    {
        SETUP,
        HOMING,
        TOUCHOFF,
        PROFILE
    };

public:
    //! Constructor
    /*!
     *  \param name Name of sensor
     */
    MotionProfile(const std::string &name, const std::string &tag);

    MotionProfile(const MotionProfile &copy);


    //! Destructor
    virtual ~MotionProfile() = default;


    //! Get the name of this sensor
    /*!
     *  \return Name of sensor
     */
    std::string getName() const
    {
        return this->profileName;
    }

    //! \brief getTag
    /*!
     *  \return Name of the tag used to run profile
     */
    std::string getTag() const
    {
        return this->profileTag;
    }


    //! Get the type of the concrete sensor
    /*!
     *  \return Type of sensor
     */
    virtual ProfileType getType() const = 0;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    MotionProfile& operator = (const MotionProfile &rhs)
    {
        this->profileName = rhs.profileName;
        this->profileTag = rhs.profileTag;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const MotionProfile &rhs)
    {
        if(this->profileName != rhs.profileName){
            return false;
        }
        if(this->profileTag != rhs.profileTag){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const MotionProfile &rhs) {
        return !(*this == rhs);
    }


protected:
    std::string profileName;
    std::string profileTag;
};


#endif // MOTION_PROFILE_STATE_H
