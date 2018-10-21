#include "status_variable_value.h"

Status_VariableValue::Status_VariableValue():
    AbstractStatus(StatusTypes::STATUS_VARIABLEVALUE)
{

}

Status_VariableValue::Status_VariableValue(const double &value):
    AbstractStatus(StatusTypes::STATUS_VARIABLEVALUE)
{
    this->variableValue = value;
}

Status_VariableValue::Status_VariableValue(const Status_VariableValue &copy):
    AbstractStatus(StatusTypes::STATUS_VARIABLEVALUE)
{
    this->programName = copy.programName;
    this->profileName = copy.profileName;
    this->variableName = copy.variableName;
    this->variableValue = copy.variableValue;
}

void Status_VariableValue::setProgramName(const std::string &program)
{
    this->programName = program;
}
void Status_VariableValue::setProfileName(const std::string &profile)
{
    this->profileName = profile;
}
void Status_VariableValue::setVariableName(const std::string &variable)
{
    this->variableName = variable;
}
std::string Status_VariableValue::getProgramName() const
{
    return this->programName;
}
std::string Status_VariableValue::getProfileName() const
{
    return this->profileName;
}
std::string Status_VariableValue::getVariableName() const
{
    return this->variableName;
}


void Status_VariableValue::setVariableValue(const double &value)
{
    this->variableValue = value;
}

void Status_VariableValue::setVariableUnit(const std::string &unit)
{
    this->variableUnit = unit;
}


double Status_VariableValue::getVariableValue() const
{
    return variableValue;
}

std::string Status_VariableValue::getVariableUnit() const
{
    return this->variableUnit;
}

common_data::MotionProfileVariableState Status_VariableValue::getVariableState() const
{
    common_data::MotionProfileVariableState newState;
    newState.setObservationTime(this->getTime());
    common_data::ProfileVariableStatePtr ptr = std::make_shared<common_data::ProfileVariableState>(getVariableName(),variableValue,variableUnit);
    newState.setProfileStateVariable(ptr);
    return newState;
}
