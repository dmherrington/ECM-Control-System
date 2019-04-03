#include "command_relative_move.h"

CommandRelativeMove::CommandRelativeMove():
    AbstractMoveCommand(CommandType::RELATIVE_MOVE, MotorAxis::ALL)
{
    relativeMove[MotorAxis::X] = 0.0;
    relativeMove[MotorAxis::Y] = 0.0;
    relativeMove[MotorAxis::Z] = 0.0;
}

CommandRelativeMove::CommandRelativeMove(const MotorAxis &axis, const int &distance):
    AbstractMoveCommand(CommandType::RELATIVE_MOVE, MotorAxis::ALL)
{
    this->setRelativeDistance(axis, distance);
}

CommandRelativeMove::CommandRelativeMove(const CommandRelativeMove &copy):
    AbstractMoveCommand(copy)
{
    this->relativeMove = copy.relativeMove;
}

AbstractCommand* CommandRelativeMove::getClone() const
{
    return (new CommandRelativeMove(*this));
}

void CommandRelativeMove::getClone(AbstractCommand** state) const
{
    *state = new CommandRelativeMove(*this);
}

void CommandRelativeMove::setRelativeDirection(const MotorAxis &axis, const Direction &direction)
{
    setMoveDirection(axis,direction);
}

void CommandRelativeMove::setRelativeDistance(const MotorAxis &axis, const double &distance)
{
    if(axis == MotorAxis::ALL)
    {
        relativeMove[MotorAxis::X] = fabs(distance);
        relativeMove[MotorAxis::Y] = fabs(distance);
        relativeMove[MotorAxis::Z] = fabs(distance);
    }
    else
    {
        moveAxis = axis;
        relativeMove[axis] = fabs(distance);
    }

    if(distance <= 0.0)
        this->setMoveDirection(axis, Direction::DIRECTION_POSITIVE); //this direction has negative values
    else
        this->setMoveDirection(axis, Direction::DIRECTION_NEGATIVE); //this direction has positive values
}


std::map<MotorAxis, double> CommandRelativeMove::getDirectedRelativeMove() const
{
    std::map<MotorAxis, double> rtnMoveMap;
    std::map<MotorAxis, Direction> directionMap = getMoveDirection();
    for (std::map<MotorAxis, double>::const_iterator it=relativeMove.begin(); it!=relativeMove.end(); ++it)
    {
        if(directionMap.at(it->first) == Direction::DIRECTION_NEGATIVE)
            rtnMoveMap.insert(std::pair<MotorAxis, double>(it->first,-1.0 * it->second));
        else
            rtnMoveMap.insert(std::pair<MotorAxis, double>(it->first,it->second));
    }

    return rtnMoveMap;
}

double CommandRelativeMove::getRelativeDistance(const MotorAxis &axis) const
{
    int targetPosition = 0;
    if(axis == MotorAxis::ALL)
    {
        return 0;
    }
    else
    {
        if(this->moveDirection.at(axis) == Direction::DIRECTION_POSITIVE)
            targetPosition = this->relativeMove.at(axis) * -10;
        else
            targetPosition = this->relativeMove.at(axis) * 10;
    }
    return targetPosition;
}

std::string CommandRelativeMove::getCommandString() const
{
    std::string str = "";
    if(this->getMoveAxis() == MotorAxis::ALL)
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(" ");

        std::map<MotorAxis, double>::const_iterator it = relativeMove.begin();
        while (it!= relativeMove.end()) {
            str.append(std::to_string(it->second));
            if(++it != relativeMove.end())
                str.append(",");
        }
    }
    else
    {
        str.append(CommandToString(this->getCommandType()));
        str.append("");
        str.append(AxisToString(moveAxis));
        str.append("=");
        if(moveDirection.at(moveAxis) == Direction::DIRECTION_POSITIVE)
            str.append("-");
        str.append(std::to_string(relativeMove.at(moveAxis) * 10));
    }

    return str;
}
