#include "sensor_state.h"

#include <stdio.h>
#include <sstream>
#include <QBuffer>
#include <stdexcept>

namespace data
{


//!
//! \brief Default constructor, allocates dynamic space
//!
SensorState::SensorState()
{
    Allocate();
}


//!
//! \brief Constructor specificying to allocate dynamic space or not
//!
//! If this object is to immediattly assigned to, it may be worthwile to not allocate space.
//! \param allocate true if we are to allocate space in the object
//!
SensorState::SensorState(bool allocate)
{
    Allocate();
}


/*!
 * \brief Copy constructor
 * \param that Data to copy from
 */
SensorState::SensorState(const SensorState &that)
{
    this->sensorData = that.sensorData;
}


/*!
 * \brief Destructor
 *
 * Delete the sensor object if it is set.
 */
SensorState::~SensorState()
{
    if(m_allocated == false)
        return;

    //if there is one reference (itself) Deallocate the sensor because its about to dissapear anyway
    if(*ref_count == 1)
    {
        this->Deallocate();
    }
}


//!
//! \brief Assignment operator
//! \param that Object to assing from
//! \return reference to assigned object
//!
SensorState& SensorState::operator =(const SensorState &rhs)
{
    // if the object being replaced, it may need to be deallocated before replaced.
    if(m_allocated == true)
    {
        *ref_count = *ref_count - 1;
        if(*ref_count == 0)
            this->Deallocate();
    }

    m_allocated = rhs.m_allocated;
    validityTime = rhs.validityTime;
    ref_count = rhs.ref_count;

    if(m_allocated)
        *ref_count = *ref_count + 1;

    this->sensorData = rhs.sensorData;

    return *this;
}


//!
//! \brief Allocate space for dynamic structure to be held
//!
void SensorState::Allocate()
{
    if(m_allocated == true)
        return;

    validityTime = new common::EnvironmentTime();
    ref_count = new uint();

    *ref_count = 1;

    m_allocated = true;

    this->sensorData = NULL;
}


//!
//! \brief Construct a sensor to be present in this state
//! \param type Type of sensor to create
//! \param name Name of sensor creating
//! \exception std::runtime Thrown when Type does not match a value in SensorTypes.
//!
void SensorState::ConstructSensor(const SensorTypes &type, std::string name)
{    
    this->sensorData = std::shared_ptr<Sensor>(SensorCollection::ConstructSensor(type, name));
}


//!
//! \brief Get a pointer to the sensor data held by this state.
//! \return Pointer to data, Null if no data provided.
//!
std::shared_ptr<Sensor> SensorState::getSensorData() const
{
    return this->sensorData;
}


//!
//! \brief set sensor data held in this object
//! \param sensorData Data to set to
//!
void SensorState::setSensorData(const std::shared_ptr<Sensor> &sensorData)
{
    this->sensorData = sensorData;
}

//!
//! \brief Delete dynamic data held by this object
//!
void SensorState::Deallocate()
{
    delete validityTime;
    delete ref_count;

    m_allocated = false;
}

}
