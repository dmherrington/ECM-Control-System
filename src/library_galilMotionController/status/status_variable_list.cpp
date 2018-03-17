#include "status_variable_list.h"

Status_VariableList::Status_VariableList():
    AbstractStatus(StatusTypes::STATUS_VARIABLELIST)
{

}

Status_VariableList::Status_VariableList(const Status_VariableList &copy):
    AbstractStatus(StatusTypes::STATUS_VARIABLELIST)
{
    this->variableMap = copy.variableMap;
}


void Status_VariableList::addVariable(const Status_VariableValue &var)
{
    this->variableMap[var.getVariableName()] = var;
}

void Status_VariableList::removeVariable(const std::string &name)
{
    if(this->variableMap.count(name) > 0)
        this->variableMap.erase(name);
}

bool Status_VariableList::updateVariable(const Status_VariableValue &var)
{
    if(this->variableMap.count(var.getVariableName()) > 0)
        return this->variableMap.at(var.getVariableName()).setVariableValue(var.getVariableValue());
    else
        this->variableMap[var.getVariableName()] = var;
    return true;
}

bool Status_VariableList::getVariable(const std::string &name, Status_VariableValue &status)
{
    if(this->variableMap.count(name) > 0)
    {
        status = this->variableMap.at(name);
        return true;
    }
    return false;
}

bool Status_VariableList::getVariableValue(const std::string &name, double &value)
{
    Status_VariableValue obj;
    if(this->getVariable(name,obj))
    {
        value = obj.getVariableValue();
    }
    return false;
}

