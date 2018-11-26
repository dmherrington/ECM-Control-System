#include "program_variable_list.h"

ProgramVariableList::ProgramVariableList()
{

}

ProgramVariableList::ProgramVariableList(const ProgramVariableList &copy)
{
    this->variableMap = copy.variableMap;
}

bool ProgramVariableList::doesVariableExist(const std::string &name) const
{
    if(this->variableMap.count(name) > 0)
        return true;
    return false;
}

void ProgramVariableList::addVariable(const std::string &name, const double &value)
{
    this->variableMap[name] = value;
}

void ProgramVariableList::removeVariable(const std::string &name)
{
    if(this->variableMap.count(name) > 0)
        this->variableMap.erase(name);
}

void ProgramVariableList::updateVariable(const std::string &name, const double &value)
{
    if(this->variableMap.count(name) > 0)
        this->variableMap.at(name) = value;
    else
        this->variableMap[name] = value;
}

bool ProgramVariableList::getVariableValue(const std::string &name, double &value) const
{
    if(this->variableMap.count(name) > 0)
    {
        value = this->variableMap.at(name);
        return true;
    }
    return false;
}

void ProgramVariableList::clearVariableList()
{
    variableMap.clear();
}

size_t ProgramVariableList::sizeOfVariableList() const
{
    return variableMap.size();
}

 std::map<std::string, double> ProgramVariableList::getVariableMap() const
 {
     return this->variableMap;
 }

 std::string ProgramVariableList::getLoggingString() const
 {
   std::string str;
   std::map<std::string,double>::const_iterator it = this->variableMap.begin();
   for(; it != this->variableMap.end(); ++it)
   {
        str += it->first + ":" + std::to_string(it->second) + "\n";
   }

   return str;
 }
