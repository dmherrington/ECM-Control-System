#include "command_absolute_move.h"

/**
\* @file  command_absolute_move.h
\*/

CommandAbsoluteMove::CommandAbsoluteMove():
    AbstractMoveCommand(CommandType::ABSOLUTE_MOVE, MotorAxis::ALL)
{

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

void CommandAbsoluteMove::addAbsoluteMovePosition(const MotorAxis &axis, const double &position, const Direction &direction)
{
    if(axis == MotorAxis::ALL)
    {

    }
    else
    {
        std::pair<std::map<MotorAxis,double>::iterator,bool> ret;
        ret = absoluteMove.insert (std::pair<MotorAxis,double>(axis,position));
        if (ret.second==false) {
            absoluteMove[axis] = fabs(position);
            this->setMoveDirection(axis, direction);
        }
     }
}

std::map<MotorAxis, double> CommandAbsoluteMove::getAbsoluteMovePosition() const
{
    std::map<MotorAxis, double> rtnMoveMap;
    std::map<MotorAxis, Direction> directionMap = getMoveDirection();
    for (std::map<MotorAxis, double>::const_iterator it=absoluteMove.begin(); it!=absoluteMove.end(); ++it)
    {
        if(directionMap.at(it->first) == Direction::DIRECTION_NEGATIVE)
            rtnMoveMap.insert(std::pair<MotorAxis, double>(it->first,-1.0 * it->second));
        else
            rtnMoveMap.insert(std::pair<MotorAxis, double>(it->first,it->second));
    }

    return rtnMoveMap;
}

std::string CommandAbsoluteMove::getCommandString() const
{
    std::string str = "";
    if(this->getMoveAxis() == MotorAxis::ALL)
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(" ");

        std::map<MotorAxis, double>::const_iterator it = absoluteMove.begin();
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
