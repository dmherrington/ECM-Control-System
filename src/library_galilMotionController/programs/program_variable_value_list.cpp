#include "program_variable_value_list.h"

ProgramVariableValueList::ProgramVariableValueList()
{

}

ProgramVariableValueList::~ProgramVariableValueList()
{
    this->clearVariableValueList();
}

ProgramVariableValueList::ProgramVariableValueList(const ProgramVariableValueList &copy)
{
    this->variableMap = copy.variableMap;
}

void ProgramVariableValueList::addVariable(const Status_VariableValue &var)
{

    DataGetSetNotifier<Status_VariableValue>* newVar = new DataGetSetNotifier<Status_VariableValue>();
    newVar->set(var);
    this->variableMap[var.getVariableName()] = newVar;
}

bool ProgramVariableValueList::addVariableNotifier(const std::string &name, void *obj, const std::function<void ()> func)
{
    if(this->variableMap.count(name) > 0)
    {
        this->variableMap.at(name)->AddNotifier(obj,func);
        return true;
    }
    return false;
}

void ProgramVariableValueList::removeVariable(const std::string &name)
{
    if(this->variableMap.count(name) > 0)
    {
        delete this->variableMap.at(name);
        this->variableMap.erase(name);
    }
}

bool ProgramVariableValueList::removeVariableNotifier(const std::string &name, void *obj)
{
    if(this->variableMap.count(name) > 0)
    {
        this->variableMap.at(name)->RemoveNotifier(obj);
        return true;
    }
    return false;
}

bool ProgramVariableValueList::updateVariable(const Status_VariableValue &var)
{
    if(this->variableMap.count(var.getVariableName()) > 0)
    {
        return this->variableMap.at(var.getVariableName())->set(var);
    }
    else
    {
        //The variable was not already apart of the program variable value list, and therefore not
        //being actively monitored. Therefore we are not going to add it in the event it was just
        //deleted.
        return false;
    }
}

bool ProgramVariableValueList::getVariable(const std::string &name, Status_VariableValue &status)
{
    if(this->variableMap.count(name) > 0)
    {
        status = this->variableMap.at(name)->get();
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
    for ( auto it = variableMap.begin(); it != variableMap.end(); ++it)
    {
        delete it->second;
        variableMap.erase(it);
    }
}
