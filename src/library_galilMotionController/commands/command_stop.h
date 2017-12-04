#ifndef COMMAND_STOP_H
#define COMMAND_STOP_H

#include <string>

#include "commands/abstract_command.h"
#include "axis_definitions.h"

class CommandStop : public AbstractCommand
{
public:
    CommandStop(const MotorAxis &axis = MotorAxis::Z);

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
    MotorAxis stopAxis; /**< Value of the axis to be stop requested */

};

#endif // COMMAND_STOP_H
