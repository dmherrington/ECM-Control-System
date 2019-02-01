#ifndef COMMAND_MOTOR_ENABLE_H
#define COMMAND_MOTOR_ENABLE_H

#include <stdexcept>

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
    //! \brief setEnableAxis
    //! \param axis
    //!
    void setEnableAxis(const MotorAxis &axis);

    //!
    //! \brief getEnableAxis
    //! \return
    //!
    MotorAxis getEnableAxis();

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    std::string getCommandString() const override;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    CommandMotorEnable& operator = (const CommandMotorEnable &rhs)
    {
        AbstractCommand::operator =(rhs);
        this->enableAxis = rhs.enableAxis;
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
        if(this->enableAxis != rhs.enableAxis){
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
    std::vector<MotorAxis> enableAxis; /**< Value of the axis to be enabled */

};

#endif // COMMAND_MOTOR_ENABLE_H
