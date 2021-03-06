#include "command_jog.h"

CommandJog::CommandJog():
    AbstractMoveCommand(CommandType::JOG_MOVE, MotorAxis::ALL)
{

}
CommandJog::CommandJog(const MotorAxis &axis, const double &speed):
    AbstractMoveCommand(CommandType::JOG_MOVE, axis)
{
    this->setJogSpeed(axis,speed);
}

CommandJog::CommandJog(const MotorAxis &axis, const double &resolution, const double &speed):
    AbstractMoveCommand(CommandType::JOG_MOVE, axis)
{
    this->setJogResolution(resolution);
    this->setJogSpeed(axis,speed);
}

CommandJog::CommandJog(const double &resolution, const double &speed):
    AbstractMoveCommand(CommandType::JOG_MOVE, MotorAxis::ALL)
{
    this->setJogResolution(resolution);
    this->setJogSpeed(this->getMoveAxis(),speed);

}

CommandJog::CommandJog(const CommandJog &copy):
    AbstractMoveCommand(copy)
{
    this->jogResolution = copy.jogResolution;
    this->jogSpeed = copy.jogSpeed;
}

AbstractCommand* CommandJog::getClone() const
{
    return (new CommandJog(*this));
}

void CommandJog::getClone(AbstractCommand** state) const
{
    *state = new CommandJog(*this);
}

void CommandJog::setJogDirection(const MotorAxis &axis, const Direction &direction)
{
    setMoveDirection(axis,direction);
}

void CommandJog::setJogResolution(const double &resolution)
{

}

void CommandJog::setJogSpeed(const MotorAxis &axis, const double &speed)
{
    if(axis == MotorAxis::ALL)
    {
        jogSpeed[MotorAxis::X] = fabs(speed);
        jogSpeed[MotorAxis::Y] = fabs(speed);
        jogSpeed[MotorAxis::Z] = fabs(speed);
    }
    else
    {
        jogSpeed[axis] = fabs(speed);
    }

    if(speed <= 0.0)
        this->setMoveDirection(axis, Direction::DIRECTION_UP); //this direction has negative values
    else
        this->setMoveDirection(axis, Direction::DIRECION_DOWN); //this direction has positive values
}

std::string CommandJog::getCommandString() const
{
    std::string str = "";
    if(this->getMoveAxis() == MotorAxis::ALL)
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(" ");

        std::map<MotorAxis, double>::const_iterator it = jogSpeed.begin();
        while (it!= jogSpeed.end()) {
            str.append(std::to_string(it->second));
            if(++it != jogSpeed.end())
                str.append(",");
        }
    }
    else
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(AxisToString(moveAxis));
        str.append("=");
        if(moveDirection.at(moveAxis) == Direction::DIRECTION_UP)
            str.append("-");
        str.append(std::to_string((int)jogSpeed.at(moveAxis)*10));
    }

    return str;
}
