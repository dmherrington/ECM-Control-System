#ifndef MOTION_PROFILE_STATE_H
#define MOTION_PROFILE_STATE_H

#include <stdexcept>

#include "string"
#include "memory"

#include "common/environment_time.h"

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

//! The state of a sensor
/*!
 * This object contains the dynamics, valid time, and data for a sensor.
 */
class MotionProfileState
{
public:

    //!
    //! \brief Default constructor, allocates dynamic space
    //!
    MotionProfileState();

    /*!
     * \brief Copy constructor
     * \param that Data to copy from
     */
    MotionProfileState(const MotionProfileState& that);

    /*!
     * \brief Destructor
     *
     * Delete the sensor object if it is set.
     */
    ~MotionProfileState();

    //!
    //! \brief Assignment operator
    //! \param that Object to assing from
    //! \return reference to assigned object
    //!
    MotionProfileState& operator =(const MotionProfileState &rhs);


    //!
    //! \brief Allocate space for dynamic structure to be held
    //!
    virtual void Allocate();

    //!
    //! \brief Get a pointer to the sensor data held by this state.
    //! \return Pointer to data, Null if no data provided.
    //!
    std::shared_ptr<MotionProfile> getProfileState() const;

    //!
    //! \brief set sensor data held in this object
    //! \param sensorData Data to set to
    //!
    void setProfileState(const std::shared_ptr<MotionProfile> &profileData);

protected:

    //!
    //! \brief Delete dynamic data held by this object
    //!
    virtual void Deallocate();

private:

    //! boolean indicating if space has been allocated
    bool m_allocated;

    //! Number of references
    uint *ref_count;

    //! The sensor data
    std::shared_ptr<MotionProfile> profileStateData;

public:
    //! The time of the state measurment
    common::EnvironmentTime *validityTime;
};

Q_DECLARE_METATYPE(MotionProfileState)

#endif // MOTION_PROFILE_STATE_H
