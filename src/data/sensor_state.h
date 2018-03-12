#ifndef SENSORSTATE_H
#define SENSORSTATE_H

#include <QDataStream>

#include "data_global.h"

#include "sensor_collection.h"
#include "common/environment_time.h"

#include <memory>

namespace data
{

//! The state of a sensor
/*!
 * This object contains the dynamics, valid time, and data for a sensor.
 */
class Export SensorState
{
public:

    //!
    //! \brief Default constructor, allocates dynamic space
    //!
    SensorState();


    //!
    //! \brief Constructor specificying to allocate dynamic space or not
    //!
    //! If this object is to immediattly assigned to, it may be worthwile to not allocate space.
    //! \param allocate true if we are to allocate space in the object
    //!
    SensorState(bool allocate);


    /*!
     * \brief Copy constructor
     * \param that Data to copy from
     */
    SensorState(const SensorState& that);


    /*!
     * \brief Destructor
     *
     * Delete the sensor object if it is set.
     */
    ~SensorState();


    //!
    //! \brief Assignment operator
    //! \param that Object to assing from
    //! \return reference to assigned object
    //!
    SensorState& operator =(const SensorState &rhs);


    //!
    //! \brief Allocate space for dynamic structure to be held
    //!
    virtual void Allocate();


    //!
    //! \brief Construct a sensor to be present in this state
    //! \param type Type of sensor to create
    //! \param name Name of sensor creating
    //! \exception std::runtime Thrown when Type does not match a value in SensorTypes.
    //!
    void ConstructSensor(const SensorTypes &type, std::string name);


    //!
    //! \brief Get a pointer to the sensor data held by this state.
    //! \return Pointer to data, Null if no data provided.
    //!
    std::shared_ptr<Sensor> getSensorData() const;


    //!
    //! \brief set sensor data held in this object
    //! \param sensorData Data to set to
    //!
    void setSensorData(const std::shared_ptr<Sensor> &sensorData);

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
    std::shared_ptr<Sensor> sensorData;

public:
    //! The time of the state measurment
    common::EnvironmentTime *validityTime;
};

} //Data

Q_DECLARE_METATYPE(data::SensorState)

#endif // SENSOR_STATE_H