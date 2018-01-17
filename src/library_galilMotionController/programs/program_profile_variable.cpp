#include "program_profile_variable.h"

ProgramProfileVariable::ProgramProfileVariable()
{

}

ProgramProfileVariable::ProgramProfileVariable(const ProgramProfileVariable &copy)
{
    this->displayName = copy.displayName;
    this->variableName = copy.variableName;
    this->max = copy.max;
    this->min = copy.min;
    this->def = copy.def;
}

void ProgramProfileVariable::read(const QJsonObject &jsonObject)
{
    this->setDisplayName(jsonObject["DisplayName"].toString().toStdString());
    this->setVariableName(jsonObject["VariableName"].toString().toStdString());
    this->setMaxValue(jsonObject["MaxValue"].toDouble());
    this->setMinValue(jsonObject["MinValue"].toDouble());
    this->setDefaultValue(jsonObject["DefaultValue"].toDouble());
}

void ProgramProfileVariable::write(QJsonArray &jsonArray) const
{
    QJsonObject variableDataObject;
    variableDataObject["DisplayName"] = QString::fromStdString(displayName);
    variableDataObject["VariableName"] = QString::fromStdString(variableName);
    variableDataObject["MaxValue"] = max;
    variableDataObject["MinValue"] = min;
    variableDataObject["DefaultValue"] = def;
    jsonArray.append(variableDataObject);
}

std::string ProgramProfileVariable::getDisplayName() const
{
    return this->displayName;
}

std::string ProgramProfileVariable::getVariableName() const
{
    return this->variableName;
}

double ProgramProfileVariable::getCurrentValue() const
{
    return this->cur;
}

double ProgramProfileVariable::getDefaultValue() const
{
    return this->def;
}

double ProgramProfileVariable::getMaxValue() const
{
    return this->max;
}

double ProgramProfileVariable::getMinValue() const
{
    return this->min;
}

void ProgramProfileVariable::setDisplayName(const std::string &name)
{
    this->displayName = name;
}

void ProgramProfileVariable::setVariableName(const std::string &name)
{
    this->variableName = name;
}

void ProgramProfileVariable::setCurrentValue(const double &value)
{
    this->cur = value;
}

void ProgramProfileVariable::setDefaultValue(const double &value)
{
    this->def = value;
}

void ProgramProfileVariable::setMaxValue(const double &value)
{
    this->max = value;
}

void ProgramProfileVariable::setMinValue(const double &value)
{
    this->min = value;
}
