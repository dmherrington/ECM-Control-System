#include "command_variable.h"

Command_Variable::Command_Variable(const std::string &name, const double &value):
    AbstractCommand(CommandType::SET_VARIABLE)
{
    this->variableName = name;
    this->variableValue = value;
}

Command_Variable::Command_Variable(const Command_Variable &copy):
    AbstractCommand(copy)
{
    this->variableName = copy.variableName;
    this->variableValue = copy.variableValue;
}

AbstractCommand* Command_Variable::getClone() const
{
    return (new Command_Variable(*this));
}

void Command_Variable::getClone(AbstractCommand** state) const
{
    *state = new Command_Variable(*this);
}

void Command_Variable::setVariableName(const std::string &name)
{
    this->variableName = name;
}

void Command_Variable::setVariableValue(const double &value)
{
    this->variableValue = value;
}

std::string Command_Variable::getVariableName() const
{
    return this->variableName;
}

double Command_Variable::getVariableValue() const
{
    return this->variableValue;
}

std::string Command_Variable::getCommandString() const
{
    std::string str;
    str += variableName;
    str +="=";
    str +=std::to_string(variableValue);
    return str;
}
