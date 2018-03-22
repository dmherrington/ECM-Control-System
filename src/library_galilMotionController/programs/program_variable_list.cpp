#include "program_variable_list.h"

ProgramVariableList::ProgramVariableList()
{

}

ProgramVariableList::ProgramVariableList(const ProgramVariableList &copy):
{
    this->variableMap = copy.variableMap;
}

void ProgramVariableList::doesVariableExist(const std::string &name) const
{
    if(this->variableMap.count(name) > 0)
        return true;
    return false;
}

void ProgramVariableList::addVariable(const std::string &name, const int &lineNumber)
{
    this->variableMap[name] = lineNumber;
}

void ProgramVariableList::removeVariable(const std::string &name)
{
    if(this->variableMap.count(name) > 0)
        this->variableMap.erase(name);
}

void ProgramVariableList::updateVariable(const std::string &name, const int &lineNumber)
{
    if(this->variableMap.count(name) > 0)
        this->variableMap.at(name) = lineNumber;
    else
        this->variableMap[name] = lineNumber;
    return true;
}

bool ProgramVariableList::getVariableLine(const std::string &name, int &lineNumber)
{
    if(this->variableMap.count(name) > 0)
    {
        lineNumber = this->variableMap.at(name);
        return true;
    }
    return false;
}

void ProgramVariableList::clearVariableList()
{
    variableMap.clear();
}
