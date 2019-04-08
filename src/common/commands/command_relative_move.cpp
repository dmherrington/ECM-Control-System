#include "command_relative_move.h"

CommandRelativeMove::CommandRelativeMove():
    AbstractMoveCommand(CommandType::RELATIVE_MOVE, MotorAxis::ALL)
{

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

void CommandRelativeMove::addRelativeMoveDistance(const MotorAxis &axis, const double &distance, const Direction &direction)
{
    if(axis == MotorAxis::ALL)
    {

    }
    else
    {
        std::pair<std::map<MotorAxis,double>::iterator,bool> ret;
        ret = relativeMove.insert (std::pair<MotorAxis,double>(axis,fabs(distance)));
        if (ret.second==false) {
            relativeMove[axis] = fabs(distance);
        }
        this->setMoveDirection(axis, direction);
    }
}


std::map<MotorAxis, double> CommandRelativeMove::getRelativeMoveDistance() const
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
