#include "digital_state.h"

namespace data
{


//!
//! \brief Default constructor, allocates dynamic space
//!
DigitalState::DigitalState():
    m_allocated(false)
{
    Allocate();
}


//!
//! \brief Constructor specificying to allocate dynamic space or not
//!
//! If this object is to immediattly assigned to, it may be worthwile to not allocate space.
//! \param allocate true if we are to allocate space in the object
//!
DigitalState::DigitalState(bool allocate)
{
    Allocate();
}


/*!
 * \brief Copy constructor
 * \param that Data to copy from
 */
DigitalState::DigitalState(const DigitalState &that)
{
    this->state = that.state;
    this->validityTime = that.validityTime;
    this->ref_count = that.ref_count;

    if(m_allocated)
        *ref_count = *ref_count + 1;
}


/*!
 * \brief Destructor
 *
 * Delete the sensor object if it is set.
 */
DigitalState::~DigitalState()
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
DigitalState& DigitalState::operator =(const DigitalState &rhs)
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

    this->state = rhs.state;

    return *this;
}


//!
//! \brief Allocate space for dynamic structure to be held
//!
void DigitalState::Allocate()
{
    if(m_allocated == true)
        return;

    validityTime = new common::EnvironmentTime();
    ref_count = new uint();

    *ref_count = 1;

    m_allocated = true;

    this->state = false;
}

//!
//! \brief Get a pointer to the sensor data held by this state.
//! \return Pointer to data, Null if no data provided.
//!
std::shared_ptr<Sensor> DigitalState::getDigitalIO() const
{
    return this->state;
}


//!
//! \brief set sensor data held in this object
//! \param sensorData Data to set to
//!
void DigitalState::setDigitalIO(const bool &IOState)
{
    this->state = IOState;
}

//!
//! \brief Delete dynamic data held by this object
//!
void DigitalState::Deallocate()
{
    if(m_allocated)
    {
        delete validityTime;
        delete ref_count;

        m_allocated = false;
    }
}

} //end of namespace data
