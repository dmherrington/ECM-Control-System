#include "program_variable_value_list.h"

ProgramVariableValueList::ProgramVariableValueList()
{

}

ProgramVariableValueList::ProgramVariableValueList(const ProgramVariableValueList &copy)
{
    this->variableMap = copy.variableMap;
}


void ProgramVariableValueList::addVariable(const Status_VariableValue &var)
{
    this->variableMap[var.getVariableName()] = var;
}

void ProgramVariableValueList::removeVariable(const std::string &name)
{
    if(this->variableMap.count(name) > 0)
        this->variableMap.erase(name);
}

bool ProgramVariableValueList::updateVariable(const Status_VariableValue &var)
{
    if(this->variableMap.count(var.getVariableName()) > 0)
        return this->variableMap.at(var.getVariableName()).setVariableValue(var.getVariableValue());
    else
        this->variableMap[var.getVariableName()] = var;
    return true;
}

bool ProgramVariableValueList::getVariable(const std::string &name, Status_VariableValue &status)
{
    if(this->variableMap.count(name) > 0)
    {
        status = this->variableMap.at(name);
        return true;
    }
    return false;
}

bool ProgramVariableValueList::getVariableValue(const std::string &name, double &value)
{
    Status_VariableValue obj;
    if(this->getVariable(name,obj))
    {
        value = obj.getVariableValue();
    }
    return false;
}

void ProgramVariableValueList::clearVariableValueList()
{
    this->variableMap.clear();
}
