#include "settings_profile_variable.h"

SettingsProfileVariable::SettingsProfileVariable()
{

}

SettingsProfileVariable::SettingsProfileVariable(const SettingsProfileVariable &copy)
{
    this->displayName = copy.displayName;
    this->variableName = copy.variableName;
    this->max = copy.max;
    this->min = copy.min;
    this->def = copy.def;
}

void SettingsProfileVariable::read(const QJsonObject &jsonObject)
{
    this->setDisplayName(jsonObject["DisplayName"].toString().toStdString());
    this->setVariableName(jsonObject["VariableName"].toString().toStdString());
    this->setMaxValue(jsonObject["MaxValue"].toDouble());
    this->setMinValue(jsonObject["MinValue"].toDouble());
    this->setDefaultValue(jsonObject["DefaultValue"].toDouble());
}

void SettingsProfileVariable::write(QJsonArray &jsonArray) const
{
    QJsonObject variableDataObject;
    variableDataObject["DisplayName"] = QString::fromStdString(displayName);
    variableDataObject["VariableName"] = QString::fromStdString(variableName);
    variableDataObject["MaxValue"] = max;
    variableDataObject["MinValue"] = min;
    variableDataObject["DefaultValue"] = def;
    jsonArray.append(variableDataObject);
}

std::string SettingsProfileVariable::getDisplayName() const
{
    return this->displayName;
}

std::string SettingsProfileVariable::getVariableName() const
{
    return this->variableName;
}

double SettingsProfileVariable::getCurrentValue() const
{
    return this->cur;
}

double SettingsProfileVariable::getDefaultValue() const
{
    return this->def;
}

double SettingsProfileVariable::getMaxValue() const
{
    return this->max;
}

double SettingsProfileVariable::getMinValue() const
{
    return this->min;
}

void SettingsProfileVariable::setDisplayName(const std::string &name)
{
    this->displayName = name;
}

void SettingsProfileVariable::setVariableName(const std::string &name)
{
    this->variableName = name;
}

void SettingsProfileVariable::setCurrentValue(const double &value)
{
    this->cur = value;
}

void SettingsProfileVariable::setDefaultValue(const double &value)
{
    this->def = value;
}

void SettingsProfileVariable::setMaxValue(const double &value)
{
    this->max = value;
}

void SettingsProfileVariable::setMinValue(const double &value)
{
    this->min = value;
}
