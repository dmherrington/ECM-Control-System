#include "status_variable_value.h"

Status_VariableValue::Status_VariableValue():
    AbstractStatus(StatusTypes::STATUS_VARIABLEVALUE)
{

}

Status_VariableValue::Status_VariableValue(const common::TupleECMData &description, const double &value):
    AbstractStatus(StatusTypes::STATUS_VARIABLEVALUE)
{
    this->descriptor = description;
    this->variableValue = value;
}

Status_VariableValue::Status_VariableValue(const Status_VariableValue &copy):
    AbstractStatus(StatusTypes::STATUS_VARIABLEVALUE)
{
    this->variableValue = copy.variableValue;
}

std::string Status_VariableValue::getVariableName() const
{
    QString variableName = static_cast<common::TupleProfileVariableString*>(this->descriptor.getData())->variableName;
    return variableName.toStdString();
}

bool Status_VariableValue::setVariableValue(const double &value)
{
    return this->variableValue = value ; //Ken this needs to be handled if the data has changed
}

double Status_VariableValue::getVariableValue() const
{
    return variableValue;
}

common_data::MotionProfileVariableState Status_VariableValue::getVariableState() const
{
    common_data::MotionProfileVariableState newState;
    newState.setObservationTime(this->getTime());
    common_data::ProfileVariableStatePtr ptr = std::make_shared<common_data::ProfileVariableState>(getVariableName(),variableValue);
    newState.setProfileStateVariable(ptr);
    return newState;
}
