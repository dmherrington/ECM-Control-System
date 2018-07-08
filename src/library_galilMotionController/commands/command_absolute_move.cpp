#include "command_absolute_move.h"

/**
\* @file  command_absolute_move.h
\*/

CommandAbsoluteMove::CommandAbsoluteMove():
    AbstractMoveCommand(CommandType::ABSOLUTE_MOVE, MotorAxis::ALL)
{
    absoluteMove[MotorAxis::X] = 0.0;
    absoluteMove[MotorAxis::Y] = 0.0;
    absoluteMove[MotorAxis::Z] = 0.0;
}

CommandAbsoluteMove::CommandAbsoluteMove(const MotorAxis &axis, const int &position):
    AbstractMoveCommand(CommandType::ABSOLUTE_MOVE, MotorAxis::ALL)
{
    this->setAbsolutePosition(axis, position);
}

CommandAbsoluteMove::CommandAbsoluteMove(const CommandAbsoluteMove &copy):
    AbstractMoveCommand(copy)
{
    this->absoluteMove = copy.absoluteMove;
}


AbstractCommand* CommandAbsoluteMove::getClone() const
{
    return (new CommandAbsoluteMove(*this));
}

void CommandAbsoluteMove::getClone(AbstractCommand** state) const
{
    *state = new CommandAbsoluteMove(*this);
}

void CommandAbsoluteMove::setAbsoluteDirection(const MotorAxis &axis, const Direction &direction)
{
    setMoveDirection(axis,direction);
}

void CommandAbsoluteMove::setAbsolutePosition(const MotorAxis &axis, const int &position)
{
    if(axis == MotorAxis::ALL)
    {
        absoluteMove[MotorAxis::X] = fabs(position);
        absoluteMove[MotorAxis::Y] = fabs(position);
        absoluteMove[MotorAxis::Z] = fabs(position);
    }
    else
    {
        absoluteMove[axis] = fabs(position);
    }

    if(position <= 0.0)
        this->setMoveDirection(axis, Direction::DIRECTION_UP); //this direction has negative values
    else
        this->setMoveDirection(axis, Direction::DIRECION_DOWN); //this direction has positive values
}

std::string CommandAbsoluteMove::getCommandString() const
{
    std::string str = "";
    if(this->getMoveAxis() == MotorAxis::ALL)
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(" ");

        std::map<MotorAxis, int>::const_iterator it = absoluteMove.begin();
        while (it!= absoluteMove.end()) {
            str.append(std::to_string(it->second));
            if(++it != absoluteMove.end())
                str.append(",");
        }
    }
    else
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(AxisToString(moveAxis));
        str.append("=");
        str.append(std::to_string(absoluteMove.at(moveAxis) * 10));
    }

    return str;
}
