#include "ecm_command_profile_configuration.h"

ECMCommand_ProfileConfiguration::ECMCommand_ProfileConfiguration():
    ECMCommand_AbstractProfileConfig(ProfileOpType::OPERATION)
{

}

void ECMCommand_ProfileConfiguration::writeToJSON(QJsonObject &obj)
{
    ECMCommand_AbstractProfileConfig::writeToJSON(obj);

    m_GalilOperation.setOperationIndex(this->getOperationIndex());
    m_GalilOperation.setOperationName(this->getOperationName());
    m_GalilOperation.writeToJSON(obj);

    m_ConfigPowerSupply.writeToJSON(obj);

    m_PumpParameters.writeToJSON(obj);

    m_Touchoff.writeToJSON(obj);
}

void ECMCommand_ProfileConfiguration::readFromJSON(const QJsonObject &obj)
{
    ECMCommand_AbstractProfileConfig::readFromJSON(obj);

    m_GalilOperation.readFromJSON(obj);
    m_ConfigPowerSupply.readFromJSON(obj);
    m_PumpParameters.readFromJSON(obj);
    m_Touchoff.readFromJSON(obj);
}

ECMCommand_ProfileConfiguration::ECMCommand_ProfileConfiguration(const ECMCommand_ProfileConfiguration &copy):
    ECMCommand_AbstractProfileConfig(copy)
{
    this->operationIndex = copy.operationIndex;
    this->operationName = copy.operationName;
    this->indicateHome = copy.indicateHome;
    this->shouldExecute = copy.shouldExecute;
    this->execProperties = copy.execProperties;

    this->m_GalilOperation = copy.m_GalilOperation;
    this->m_ConfigPowerSupply = copy.m_ConfigPowerSupply;
    this->m_PumpParameters = copy.m_PumpParameters;
    this->m_Touchoff = copy.m_Touchoff;
}

std::string ECMCommand_ProfileConfiguration::getProfileName() const
{
    return this->m_GalilOperation.getProfileName();
}
