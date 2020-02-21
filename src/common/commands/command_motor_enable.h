#ifndef COMMAND_MOTOR_ENABLE_H
#define COMMAND_MOTOR_ENABLE_H

#include <stdexcept>
#include <map>

#include "../class_forward.h"

#include "abstract_command.h"
#include "../axis_definitions.h"

/**
\* @file  command_motor_enable.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*
\*
\*/

ECM_CLASS_FORWARD(CommandMotorEnable);

class CommandMotorEnable : public AbstractCommand
{
public:
    enum EnableValue{
        NO_CHANGE,
        CHANGE
    };

public:
    //!
    //! \brief CommandMotorEnable
    //!
    CommandMotorEnable();

    CommandMotorEnable(const CommandMotorEnable &copy);

    /**
      */
    virtual ~CommandMotorEnable() = default;

public:

    /**
     * @brief getClone
     * @return
     */
    AbstractCommand* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    void getClone(AbstractCommand** state) const override;

public:
    //!
    //! \brief addAxis
    //! \param axis
    //!
    void addAxis(const MotorAxis &axis);

    //!
    //! \brief addAxis
    //! \param axes
    //!
    void addAxes(const std::vector<MotorAxis> &axes);


    //!
    //! \brief getEnableAxis
    //! \return
    //!
    std::map<MotorAxis,CommandMotorEnable::EnableValue> getEnableAction() const;


public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    CommandMotorEnable& operator = (const CommandMotorEnable &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->m_AxisValue = rhs.m_AxisValue;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const CommandMotorEnable &rhs)
    {
        if(!AbstractCommand::operator ==(rhs)){
            return false;
        }
        if(this->m_AxisValue != rhs.m_AxisValue){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const CommandMotorEnable &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<MotorAxis,EnableValue> m_AxisValue; /**< Value of the axis to begin motion */

};

#endif // COMMAND_MOTOR_ENABLE_H
