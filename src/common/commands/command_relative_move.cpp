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

void CommandRelativeMove::addRelativeMoveDistance(const MotorAxis &axis, const double &distance)
{
    if(axis == MotorAxis::ALL)
    {

    }
    else
    {
        std::pair<std::map<MotorAxis,double>::iterator,bool> ret;
        ret = relativeMove.insert (std::pair<MotorAxis,double>(axis,distance));
        if (ret.second==false) {
            relativeMove[axis] = distance;
        }
    }
}


std::map<MotorAxis, double> CommandRelativeMove::getRelativeMoveDistance() const
{
    return relativeMove;
}

double CommandRelativeMove::getRelativeDistance(const MotorAxis &axis) const
{
    double targetPosition = 0;
    if(axis == MotorAxis::ALL)
    {
        return 0;
    }
    else
    {
        targetPosition = this->relativeMove.at(axis);
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
        if(moveDirection.at(moveAxis) == Direction::DIRECTION_INCREASE)
            str.append("-");
        str.append(std::to_string(relativeMove.at(moveAxis) * 10));
    }

    return str;
}
