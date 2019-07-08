#ifndef MOTION_PROFILE_STATE_H
#define MOTION_PROFILE_STATE_H

#include <stdexcept>

#include "string"
#include "memory"

#include "common/environment_time.h"
#include "common/motion_profile.h"

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
    virtual ~MotionProfileState();

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
