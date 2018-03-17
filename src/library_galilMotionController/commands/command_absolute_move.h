#ifndef COMMAND_ABSOLUTE_MOVE_H
#define COMMAND_ABSOLUTE_MOVE_H

#include <map>
#include <math.h>

#include "abstract_move_command.h"

/**
\* @file  command_absolute_move.h
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

ECM_CLASS_FORWARD(CommandAbsoluteMove);

class CommandAbsoluteMove : public AbstractMoveCommand
{
public:
    CommandAbsoluteMove();

    CommandAbsoluteMove(const MotorAxis &axis, const int &position);

    CommandAbsoluteMove(const CommandAbsoluteMove &copy);

    /**
      */
    virtual ~CommandAbsoluteMove() = default;

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
    void setAbsoluteDirection(const MotorAxis &axis, const Direction &direction);
    void setAbsolutePosition(const MotorAxis &axis, const int &position);

public:
    std::string getCommandString() const override;

private:
    std::map<MotorAxis, int> absoluteMove; /**< Value of the relative move */
};

//! \remark
//! PAm=n Arguements specified with a single axis mask and an assignment operator (=)
//! PA n ... Arguements specified with an implicit, comma-separated order
//! _PAm Operand holds the last value set by the command where m defines the axis
//!

//! \remark
//! The position is referenced to the absolute zero position, defined as position 0.
//! By default a new PA command may not be issued before the previous PA command has
//! finished executing. This operation may be changed by running in Position Tracking
//! Mode - See the PT command for more information.

#endif // COMMAND_ABSOLUTE_MOVE_H
