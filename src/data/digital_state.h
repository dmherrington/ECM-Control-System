#ifndef DIGITAL_STATE_H
#define DIGITAL_STATE_H
#include <QDataStream>
#include <memory>

#include "data_global.h"

#include "sensor_collection.h"
#include "common/environment_time.h"

namespace data
{

class DigitalState
{
public:

    //!
    //! \brief Default constructor, allocates dynamic space
    //!
    DigitalState();


    //!
    //! \brief Constructor specificying to allocate dynamic space or not
    //!
    //! If this object is to immediattly assigned to, it may be worthwile to not allocate space.
    //! \param allocate true if we are to allocate space in the object
    //!
    DigitalState(bool allocate);


    /*!
     * \brief Copy constructor
     * \param that Data to copy from
     */
    DigitalState(const DigitalState& that);


    /*!
     * \brief Destructor
     *
     * Delete the sensor object if it is set.
     */
    ~DigitalState();


    //!
    //! \brief Assignment operator
    //! \param that Object to assing from
    //! \return reference to assigned object
    //!
    DigitalState& operator =(const DigitalState &rhs);


    //!
    //! \brief Allocate space for dynamic structure to be held
    //!
    virtual void Allocate();

    //!
    //! \brief Get a pointer to the sensor data held by this state.
    //! \return Pointer to data, Null if no data provided.
    //!
    std::shared_ptr<Sensor> getDigitalIO() const;


    //!
    //! \brief set sensor data held in this object
    //! \param sensorData Data to set to
    //!
    void setDigitalIO(const bool &IOState);

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
    bool state;

public:
    //! The time of the state measurment
    common::EnvironmentTime *validityTime;
};

} //end of namespace data

Q_DECLARE_METATYPE(data::DigitalState)

#endif // DIGITAL_STATE_H
