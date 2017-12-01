#ifndef COMMAND_MOTOR_ENABLE_H
#define COMMAND_MOTOR_ENABLE_H

#include <stdexcept>

#include "abstract_command.h"
#include "axis_definitions.h"

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


class CommandMotorEnable : public AbstractCommand
{
public:
    //!
    //! \brief CommandMotorEnable
    //!
    CommandMotorEnable();

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
    virtual std::string getCommandString() const override;

private:
    MotorAxis enableAxis; /**< Value of the axis to be disabled */

};

//! \remark
//! SH mm Arguement is an axis mask

//! \remark
//! The SH command changes the coordinate system.
//! Therefore, all position commands given prior to SH, must be repeated. Otherwise, the controller produces incorrect motion.
//! This command can be useful when the position of a motor has been manually adjusted following a motor off (MO) command.
//! During a program download the servo will disable for a brief period (roughly 300ms). This can be prevented by first issuing an MO.

#endif // COMMAND_MOTOR_ENABLE_H
