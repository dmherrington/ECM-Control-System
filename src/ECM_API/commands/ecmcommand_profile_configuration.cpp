#include "ecmcommand_profile_configuration.h"

ECMCommand_ProfileConfiguration::ECMCommand_ProfileConfiguration()
{

}

bool ECMCommand_ProfileConfiguration::shouldProfileExecute() const
{
    return this->execute;
}

void ECMCommand_ProfileConfiguration::setProfileExecution(const bool &varExecute)
{
    this->execute = varExecute;
}
