#ifndef COMMAND_MOTOR_DISABLE_H
#define COMMAND_MOTOR_DISABLE_H

#include <stdexcept>

#include "abstract_command.h"
#include "axis_definitions.h"

class CommandMotorDisable : public AbstractCommand
{
public:
    //!
    //! \brief CommandMotorDisable
    //!
    CommandMotorDisable();

public:
    //!
    //! \brief setDisableAxis
    //! \param axis
    //!
    void setDisableAxis(const MotorAxis &axis);

    //!
    //! \brief getDisableAxis
    //! \return
    //!
    MotorAxis getDisableAxis() const;

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    virtual std::string getCommandString() const override;

private:
    MotorAxis disableAxis; /**< Value of the axis to be disabled */
};

//! \remark
//! MO mm Arguement is an axis mask
//! _MOm contains 1.000 if the axis is in the motor off state or 0.000 if the axes is in the servo here state.

//! \remark
//! The controller will continue to monitor the motor position
//! See the TP command for more details
//! To turn the motor back on use the SH (Servo Here) command.
//! The MO command is useful for positioning the motors by hand.



#endif // COMMAND_MOTOR_DISABLE_H
