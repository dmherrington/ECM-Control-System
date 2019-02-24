#include "operation_variable_list.h"

Operation_VariableList::Operation_VariableList()
{

}

Operation_VariableList::Operation_VariableList(const Operation_VariableList &copy)
{
    this->variableMap = copy.variableMap;
}

void Operation_VariableList::writeToJSON(QJsonObject &saveObject)
{
    QJsonArray MCVariableArray;

    std::map<std::string,double>::iterator it = variableMap.begin();

    QJsonObject varObject;

    for(;it!=variableMap.end();++it)
    {
        std::string variableKey = it->first;
        varObject[QString::fromStdString(variableKey)] = it->second;
    }

    MCVariableArray.append(varObject);

    saveObject["variableData"] = MCVariableArray;
}

void Operation_VariableList::readFromJSON(const QJsonObject &openObject)
{
    QJsonArray MCVariableArray = openObject["variableData"].toArray();
    QJsonObject variableObject = MCVariableArray[0].toObject();

    for (int variableIndex = 0; variableIndex < variableObject.size(); ++variableIndex) {
        QString variableKey = variableObject.keys().at(variableIndex);
        double variableValue = variableObject.value(variableKey).toDouble();
        addVariable(variableKey.toStdString(),variableValue);
    }
}

bool Operation_VariableList::doesVariableExist(const std::string &name) const
{
    if(this->variableMap.count(name) > 0)
        return true;
    return false;
}

void Operation_VariableList::addVariable(const std::string &name, const double &value)
{
    this->variableMap[name] = value;
}

void Operation_VariableList::removeVariable(const std::string &name)
{
    if(this->variableMap.count(name) > 0)
        this->variableMap.erase(name);
}

void Operation_VariableList::updateVariable(const std::string &name, const double &value)
{
    if(this->variableMap.count(name) > 0)
        this->variableMap.at(name) = value;
    else
        this->variableMap[name] = value;
}

bool Operation_VariableList::getVariableValue(const std::string &name, double &value) const
{
    if(this->variableMap.count(name) > 0)
    {
        value = this->variableMap.at(name);
        return true;
    }
    return false;
}

void Operation_VariableList::clearVariableList()
{
    variableMap.clear();
}

size_t Operation_VariableList::sizeOfVariableList() const
{
    return variableMap.size();
}

 std::map<std::string, double> Operation_VariableList::getVariableMap() const
 {
     return this->variableMap;
 }

 std::string Operation_VariableList::getLoggingString() const
 {
   std::string str;
   std::map<std::string,double>::const_iterator it = this->variableMap.begin();
   for(; it != this->variableMap.end(); ++it)
   {
        str += it->first + ":" + std::to_string(it->second) + "\n";
   }

   return str;
 }
