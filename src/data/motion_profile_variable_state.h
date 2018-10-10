#ifndef MOTION_PROFILE_STATE_VARIABLE_H
#define MOTION_PROFILE_STATE_VARIABLE_H

#include <QDataStream>
#include <QTextStream>

#include <stdexcept>

#include "string"
#include "memory"

#include "common/class_forward.h"
#include "common/environment_time.h"

namespace common_data {

ECM_CLASS_FORWARD(ProfileVariableState);

class ProfileVariableState
{
public:
    ProfileVariableState();

    ProfileVariableState(const std::string &name, const double &value, const std::string &unit = "unitless");

    ProfileVariableState(const ProfileVariableState &copy);

    void setVariableName(const std::string &name);
    void setVariableUnit(const std::string &unit);
    void setVariableValue(const double &value);

    std::string getVariableName() const;
    std::string getVariableUnit() const;
    double getVariableValue() const;

    std::string getLoggingString() const;

public:
    ProfileVariableState& operator = (const ProfileVariableState &rhs)
    {
        this->variableName = rhs.variableName;
        this->variableUnit = rhs.variableUnit;
        this->variableValue = rhs.variableValue;
        return *this;
    }

    bool operator == (const ProfileVariableState &rhs) {
        if(this->variableName != rhs.variableName){
            return false;
        }
        if(this->variableUnit != rhs.variableUnit){
            return false;
        }
        if(this->variableValue != rhs.variableValue){
            return false;
        }
        return true;
    }

    bool operator != (const ProfileVariableState &rhs) {
        return !(*this == rhs);
    }

private:
    std::string variableName;
    std::string variableUnit;
    double variableValue;
};


ECM_CLASS_FORWARD(MotionProfileVariableState);

class MotionProfileVariableState
{
public:

    //!
    //! \brief Default constructor, allocates dynamic space
    //!
    MotionProfileVariableState();

    /*!
     * \brief Copy constructor
     * \param that Data to copy from
     */
    MotionProfileVariableState(const MotionProfileVariableState& that);

    /*!
     * \brief Destructor
     *
     * Delete the sensor object if it is set.
     */
    ~MotionProfileVariableState();

    //!
    //! \brief Assignment operator
    //! \param that Object to assing from
    //! \return reference to assigned object
    //!
    MotionProfileVariableState& operator =(const MotionProfileVariableState &rhs);


    //!
    //! \brief Allocate space for dynamic structure to be held
    //!
    virtual void Allocate();

    //!
    //! \brief Get a pointer to the sensor data held by this state.
    //! \return Pointer to data, Null if no data provided.
    //!
    std::shared_ptr<ProfileVariableState> getProfileStateVariable() const;

    //!
    //! \brief set sensor data held in this object
    //! \param sensorData Data to set to
    //!
    void setProfileStateVariable(const std::shared_ptr<ProfileVariableState> &variableData);

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


    friend QTextStream& operator <<(QTextStream &outStream, const MotionProfileVariableState &data)
    {
        return outStream<<QString::fromStdString(data.getProfileStateVariable()->getLoggingString());
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
    std::shared_ptr<ProfileVariableState> profileVariableData;

    //! The time of the sensor measurment
    common::EnvironmentTime observationTime;
};

} //end of namespace common_data

Q_DECLARE_METATYPE(common_data::MotionProfileVariableState)

#endif // MOTION_PROFILE_STATE_VARIABLE_H
