#include "ecmcommand_profile_configuration.h"

ECMCommand_ProfileConfiguration::ECMCommand_ProfileConfiguration()
{

}

ECMCommand_ProfileConfiguration::ECMCommand_ProfileConfiguration(const ECMCommand_ProfileConfiguration &copy)
{
    this->execute = copy.execute;
    this->m_GalilOperation = copy.m_GalilOperation;
    this->m_MunkPulseMode = copy.m_MunkPulseMode;
    this->m_MunkSegment = copy.m_MunkSegment;
    this->m_PumpParameters = copy.m_PumpParameters;
    this->m_Touchoff = copy.m_Touchoff;
}

bool ECMCommand_ProfileConfiguration::shouldProfileExecute() const
{
    return this->execute;
}

void ECMCommand_ProfileConfiguration::setProfileExecution(const bool &varExecute)
{
    this->execute = varExecute;
}
