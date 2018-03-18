#ifndef MOTION_PROFILE_STATE_H
#define MOTION_PROFILE_STATE_H

#include "string"
#include "memory"

#include "common/types_execution_profiles.h"

class MotionProfile{
public:
    //! Constructor
    /*!
     *  \param name Name of sensor
     */
    MotionProfile(const std::string &name, const std::string &tag);

    //! Destructor
    virtual ~MotionProfile();


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

private:
    std::string profileName;
    std::string profileTag;
};

class MotionProfileState
{
public:
    MotionProfileState(const ProfileType &type);

    //!
    //! \brief Construct a sensor to be present in this state
    //! \param type Type of sensor to create
    //! \param name Name of sensor creating
    //! \exception std::runtime Thrown when Type does not match a value in SensorTypes.
    //!
    void ConstructProfileState(const ProfileType &type, const std::string &name, const std::string &tag);

    //!
    //! \brief Get a pointer to the sensor data held by this state.
    //! \return Pointer to data, Null if no data provided.
    //!
    std::shared_ptr<MotionProfile> getProfileState() const;

    //!
    //! \brief set sensor data held in this object
    //! \param sensorData Data to set to
    //!
    void setProfileState(const std::shared_ptr<MotionProfile> &sensorData);

private:
    std::shared_ptr<MotionProfile> profileStateData;
};

#endif // MOTION_PROFILE_STATE_H
