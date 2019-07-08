#include "command_upload_operational_variables.h"

Command_UploadOperationalVariables::Command_UploadOperationalVariables():
    AbstractCommand(CommandType::UPLOAD_OPERATIONAL_VARIABLES)
{

}

Command_UploadOperationalVariables::Command_UploadOperationalVariables(const Command_UploadOperationalVariables &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* Command_UploadOperationalVariables::getClone() const
{
    return (new Command_UploadOperationalVariables(*this));
}

void Command_UploadOperationalVariables::getClone(AbstractCommand** state) const
{
    *state = new Command_UploadOperationalVariables(*this);
}

void Command_UploadOperationalVariables::setOperationalVariables(const Operation_VariableList &variableList)
{
    m_VariableList = variableList;
}

Operation_VariableList Command_UploadOperationalVariables::getOperationalVariables() const
{
    return m_VariableList;
}
