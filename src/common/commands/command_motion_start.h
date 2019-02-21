#ifndef COMMAND_MOTION_START_H
#define COMMAND_MOTION_START_H

#include <string>
#include <map>

#include "../class_forward.h"
#include "../axis_definitions.h"

#include "abstract_command.h"

/**
\* @file  command_jog.h
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

ECM_CLASS_FORWARD(CommandMotionStart);

class CommandMotionStart : public AbstractCommand
{

public:
    enum MotionValue{
        NO_CHANGE,
        CHANGE
    };

public:
    CommandMotionStart(const MotorAxis &axis = MotorAxis::Z);

    CommandMotionStart(const CommandMotionStart &copy);

    /**
      */
    ~CommandMotionStart() override = default;

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
    //! \brief setAxis
    //! \param axis
    //!
    void addAxis(const MotorAxis &axis);

    //!
    //! \brief getAxis
    //! \return
    //!
    std::map<MotorAxis,CommandMotionStart::MotionValue> getAxis() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    CommandMotionStart& operator = (const CommandMotionStart &rhs)
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
    bool operator == (const CommandMotionStart &rhs)
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
    bool operator != (const CommandMotionStart &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<MotorAxis,MotionValue> m_AxisValue; /**< Value of the axis to begin motion */

};

#endif // COMMAND_MOTION_START_H
