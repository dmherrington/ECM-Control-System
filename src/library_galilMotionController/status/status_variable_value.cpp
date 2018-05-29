#include "status_variable_value.h"

Status_VariableValue::Status_VariableValue():
    AbstractStatus(StatusTypes::STATUS_VARIABLEVALUE)
{

}

Status_VariableValue::Status_VariableValue(const std::string &name, const double &value):
    AbstractStatus(StatusTypes::STATUS_VARIABLEVALUE)
{
    this->variableName = name;
    this->variableValue = value;
}

Status_VariableValue::Status_VariableValue(const Status_VariableValue &copy):
    AbstractStatus(StatusTypes::STATUS_VARIABLEVALUE)
{
    this->variableName = copy.variableName;
    this->variableValue = copy.variableValue;
}

void Status_VariableValue::setVariableName(const std::string &axis)
{
    this->variableName = axis;
}

bool Status_VariableValue::setVariableValue(const double &value)
{
    return this->variableValue = value ; //Ken this needs to be handled if the data has changed
}

std::string Status_VariableValue::getVariableName() const
{
    return this->variableName;
}

double Status_VariableValue::getVariableValue() const
{
    return variableValue;
}

common_data::MotionProfileVariableState Status_VariableValue::getVariableState() const
{
    common_data::MotionProfileVariableState newState;
    newState.setObservationTime(this->getTime());
    common_data::ProfileVariableStatePtr ptr = std::make_shared<common_data::ProfileVariableState>(variableName,variableValue);
    newState.setProfileStateVariable(ptr);
    return newState;
}
