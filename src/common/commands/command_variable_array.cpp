#include "command_variable_array.h"

Command_VariableArray::Command_VariableArray(const std::string &name, const std::vector<double> &value):
    AbstractCommand(CommandType::SET_VARIABLE)
{
    this->variableName = name;
    this->variableValue = value;
}

Command_VariableArray::Command_VariableArray(const Command_VariableArray &copy):
    AbstractCommand(copy)
{
    this->variableName = copy.variableName;
    this->variableValue = copy.variableValue;
}

AbstractCommand* Command_VariableArray::getClone() const
{
    return (new Command_VariableArray(*this));
}

void Command_VariableArray::getClone(AbstractCommand** state) const
{
    *state = new Command_VariableArray(*this);
}

void Command_VariableArray::setVariableName(const std::string &name)
{
    this->variableName = name;
}

void Command_VariableArray::setVariableValue(const std::vector<double> &value)
{
    this->variableValue = value;
}

std::string Command_VariableArray::getVariableName() const
{
    return this->variableName;
}

std::vector<double> Command_VariableArray::getVariableValue() const
{
    return this->variableValue;
}

std::string Command_VariableArray::getCommandString() const
{
    std::string str;
    return str;
}
