#include "command_controller_gain.h"

CommandControllerGain::CommandControllerGain(const MotorAxis &axis)
{
    this->axis = axis;
}

void CommandControllerGain::setGainValue(const gainTypes &type, const double value)
{
    switch (type) {
    case gainTypes::Proportional:
        this->gain.p = value;
        break;
    case gainTypes::Integral:
        this->gain.i = value;
        break;
    case gainTypes::Derivative:
        this->gain.d = value;
        break;
    default:
        break;
    }
}

double CommandControllerGain::getGainValue(const gainTypes &type) const
{
    switch (type) {
    case gainTypes::Proportional:
        return this->gain.p;
        break;
    case gainTypes::Integral:
        return this->gain.i;
        break;
    case gainTypes::Derivative:
        return this->gain.d;
        break;
    default:
        return 0.0;
        break;
    }
}

std::string CommandControllerGain::getCommandString(const gainTypes &type) const
{
    std::string rtn;
    switch (type) {
    case gainTypes::Proportional:
    {
        CommandProportionalGain gain(this->axis);
        gain.setGainValue(this->gain.p);
        rtn = gain.getCommandString();
        break;
    }
    case gainTypes::Integral:
    {
        CommandIntegralGain gain(this->axis);
        gain.setGainValue(this->gain.i);
        rtn = gain.getCommandString();
        break;
    }
    case gainTypes::Derivative:
    {
        CommandDerivativeGain gain(this->axis);
        gain.setGainValue(this->gain.d);
        rtn = gain.getCommandString();
        break;
    }
    default:
        break;
    }
}

////////////////////////////////////////////////////////////////////////////
/// CommandProportionalGain
////////////////////////////////////////////////////////////////////////////

CommandProportionalGain::CommandProportionalGain(const MotorAxis &axis):
    AbstractCommand(CommandType::SET_PGAIN)
{
    this->axis = axis;
}

CommandProportionalGain::CommandProportionalGain(const CommandProportionalGain &copy):
    AbstractCommand(copy)
{
    this->axis = copy.axis;
    this->gainValue = copy.gainValue;
}

AbstractCommand* CommandProportionalGain::getClone() const
{
    return (new CommandProportionalGain(*this));
}

void CommandProportionalGain::getClone(AbstractCommand** state) const
{
    *state = new CommandProportionalGain(*this);
}

void CommandProportionalGain::setGainValue(const double &value)
{
    this->gainValue = value;
}

double CommandProportionalGain::getGainValue() const
{
    return this->gainValue;
}

std::string CommandProportionalGain::getCommandString() const
{
    std::string str;
    if(axis == MotorAxis::ALL)
    {
        //for now we are going to throw an exception here as this should create a multi-message
        //or the mask should reflect all layers which I dont know how galil would handle yet
    }
    else
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(AxisToString(axis));
        str += "=" + std::to_string(gainValue);
    }
    return str;
}

////////////////////////////////////////////////////////////////////////////
/// CommandIntegralGain
////////////////////////////////////////////////////////////////////////////

CommandIntegralGain::CommandIntegralGain(const MotorAxis &axis):
    AbstractCommand(CommandType::SET_IGAIN)
{
    this->axis = axis;
}

CommandIntegralGain::CommandIntegralGain(const CommandIntegralGain &copy):
    AbstractCommand(copy)
{
    this->axis = copy.axis;
    this->gainValue = copy.gainValue;
}

AbstractCommand* CommandIntegralGain::getClone() const
{
    return (new CommandIntegralGain(*this));
}

void CommandIntegralGain::getClone(AbstractCommand** state) const
{
    *state = new CommandIntegralGain(*this);
}

void CommandIntegralGain::setGainValue(const double &value)
{
    this->gainValue = value;
}

double CommandIntegralGain::getGainValue() const
{
    return this->gainValue;
}

std::string CommandIntegralGain::getCommandString() const
{
    std::string str;
    if(axis == MotorAxis::ALL)
    {
        //for now we are going to throw an exception here as this should create a multi-message
        //or the mask should reflect all layers which I dont know how galil would handle yet
    }
    else
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(AxisToString(axis));
        str += "=" + std::to_string(gainValue);
    }
    return str;
}

////////////////////////////////////////////////////////////////////////////
/// CommandDerivativeGain
////////////////////////////////////////////////////////////////////////////

CommandDerivativeGain::CommandDerivativeGain(const MotorAxis &axis):
    AbstractCommand(CommandType::SET_DGAIN)
{
    this->axis = axis;
}

CommandDerivativeGain::CommandDerivativeGain(const CommandDerivativeGain &copy):
    AbstractCommand(copy)
{
    this->axis = copy.axis;
    this->gainValue = copy.gainValue;
}

AbstractCommand* CommandDerivativeGain::getClone() const
{
    return (new CommandDerivativeGain(*this));
}

void CommandDerivativeGain::getClone(AbstractCommand** state) const
{
    *state = new CommandDerivativeGain(*this);
}

void CommandDerivativeGain::setGainValue(const double &value)
{
    this->gainValue = value;
}

double CommandDerivativeGain::getGainValue() const
{
    return this->gainValue;
}

std::string CommandDerivativeGain::getCommandString() const
{
    std::string str;
    if(axis == MotorAxis::ALL)
    {
        //for now we are going to throw an exception here as this should create a multi-message
        //or the mask should reflect all layers which I dont know how galil would handle yet
    }
    else
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(AxisToString(axis));
        str += "=" + std::to_string(gainValue);
    }
    return str;
}
