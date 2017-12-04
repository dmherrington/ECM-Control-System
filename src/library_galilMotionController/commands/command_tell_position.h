#ifndef COMMAND_TELL_POSITION_H
#define COMMAND_TELL_POSITION_H

#include <string>

#include "commands/abstract_command.h"
#include "axis_definitions.h"

class CommandTellPosition : public AbstractCommand
{
public:
    CommandTellPosition(const MotorAxis &axis = MotorAxis::Z);

public:
    //!
    //! \brief setAxis
    //! \param axis
    //!
    void setAxis(const MotorAxis &axis);

    //!
    //! \brief getAxis
    //! \return
    //!
    MotorAxis getAxis() const;

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    virtual std::string getCommandString() const override;

private:
    MotorAxis tellAxis; /**< Value of the axis to be position requested */

};

#endif // COMMAND_TELL_POSITION_H
