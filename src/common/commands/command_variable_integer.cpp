#include "command_variable_integer.h"

Command_VariableInteger::Command_VariableInteger(const std::string &name, const int &value):
    AbstractCommand(CommandType::SET_VARIABLE_INTEGER)
{
    this->variableName = name;
    this->variableValue = value;
}

Command_VariableInteger::Command_VariableInteger(const Command_VariableInteger &copy):
    AbstractCommand(copy)
{
    this->variableName = copy.variableName;
    this->variableValue = copy.variableValue;
}

AbstractCommand* Command_VariableInteger::getClone() const
{
    return (new Command_VariableInteger(*this));
}

void Command_VariableInteger::getClone(AbstractCommand** state) const
{
    *state = new Command_VariableInteger(*this);
}

void Command_VariableInteger::setVariableName(const std::string &name)
{
    this->variableName = name;
}

void Command_VariableInteger::setVariableValue(const int &value)
{
    this->variableValue = value;
}

std::string Command_VariableInteger::getVariableName() const
{
    return this->variableName;
}

int Command_VariableInteger::getVariableValue() const
{
    return this->variableValue;
}

std::string Command_VariableInteger::getCommandString() const
{
    std::string str;
    str += variableName;
    str +="=";
    str +=std::to_string(variableValue);
    return str;
}
