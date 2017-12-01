#ifndef COMMAND_RELATIVE_MOVE_H
#define COMMAND_RELATIVE_MOVE_H

#include <map>
#include <math.h>

#include "abstract_move_command.h"

//!
//! \brief The CommandRelativeMove class
//!
//!

class CommandRelativeMove : public AbstractMoveCommand
{
public:
    CommandRelativeMove();

    CommandRelativeMove(const MotorAxis &axis, const int &distance);

public:
    void setRelativeDirection(const MotorAxis &axis, const Direction &direction);
    void setRelativeDistance(const MotorAxis &axis, const int &distance);

public:
    std::string getCommandString() const override;

private:
    std::map<MotorAxis, int> relativeMove; /**< Value of the relative move */
};

//! \remark
//! PRm=n Arguements specified with a single axis mask and an assignment operator (=)
//! PR n ... Arguements specified with an implicit, comma-separated order
//! _PRm Operand holds the last value set by the command where m defines the axis

//! \remark
//! The PR command sets the incremental distance and direction of the next move.
//! The move is referenced with respect to the current position.

#endif // COMMAND_RELATIVE_MOVE_H
