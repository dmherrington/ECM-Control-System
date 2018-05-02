#ifndef MACHINE_POSITIONAL_STATE_H
#define MACHINE_POSITIONAL_STATE_H

#include <QDataStream>
#include <QTextStream>

#include <stdexcept>

#include "string"
#include "memory"

#include "dimensions/position_dimension.h"

#include "common/class_forward.h"
#include "common/environment_time.h"
#include "common/axis_definitions.h"

namespace common_data {

ECM_CLASS_FORWARD(PositionalState);

class PositionalState
{
public:
    PositionalState();

    PositionalState(const  MotorAxis &axis, const unsigned int &position);

    PositionalState(const PositionalState &copy);

    void setStateAxis(const MotorAxis &axis);
    void setAxisPosition(const unsigned int &position);

    MotorAxis getAxis() const;
    unsigned int getAxisPosition() const;

    std::string getLoggingString() const;

public:
    PositionalState& operator = (const PositionalState &rhs)
    {
        this->axis = rhs.axis;
        this->position = rhs.position;
        return *this;
    }

    bool operator == (const PositionalState &rhs) {
        if(this->axis != rhs.axis){
            return false;
        }
        if(this->position != rhs.position){
            return false;
        }
        return true;
    }

    bool operator != (const PositionalState &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis axis;
    unsigned int position;
};


ECM_CLASS_FORWARD(MachinePositionalState);

class MachinePositionalState
{
public:

    //!
    //! \brief Default constructor, allocates dynamic space
    //!
    MachinePositionalState();

    /*!
     * \brief Copy constructor
     * \param that Data to copy from
     */
    MachinePositionalState(const MachinePositionalState& that);

    /*!
     * \brief Destructor
     *
     * Delete the sensor object if it is set.
     */
    ~MachinePositionalState();

    //!
    //! \brief Assignment operator
    //! \param that Object to assing from
    //! \return reference to assigned object
    //!
    MachinePositionalState& operator =(const MachinePositionalState &rhs);


    //!
    //! \brief Allocate space for dynamic structure to be held
    //!
    virtual void Allocate();

    //!
    //! \brief Get a pointer to the sensor data held by this state.
    //! \return Pointer to data, Null if no data provided.
    //!
    std::shared_ptr<PositionalState> getPositionalState() const;

    //!
    //! \brief set sensor data held in this object
    //! \param sensorData Data to set to
    //!
    void setPositionalState(const std::shared_ptr<PositionalState> &positionalData);

    //!
    //! \brief getObservationTime
    //! \return
    //!
    common::EnvironmentTime getObservationTime() const;

    //!
    //! \brief setObservationTime
    //! \param time
    //!
    void setObservationTime(const common::EnvironmentTime &time);


    friend QTextStream& operator <<(QTextStream &outStream, const MachinePositionalState &data)
    {
        return outStream<<QString::fromStdString(data.getPositionalState()->getLoggingString());
    }

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
    std::shared_ptr<PositionalState> profileVariableData;

    //! The time of the sensor measurment
    common::EnvironmentTime observationTime;
};

} //end of namespace common_data

Q_DECLARE_METATYPE(common_data::MachinePositionalState)

#endif // MACHINE_POSITIONAL_STATE_H
