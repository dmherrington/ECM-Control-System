#include "ecm_command_profile_configuration.h"

ECMCommand_ProfileConfiguration::ECMCommand_ProfileConfiguration():
    ECMCommand_AbstractProfileConfig(ConfigType::OPERATION)
{

}

void ECMCommand_ProfileConfiguration::writeToJSON(QJsonObject &obj)
{
    obj["opIndex"] = (int)this->getOperationIndex();
    obj["opName"] = QString::fromStdString(this->getOperationName());
    obj["useOperation"] = this->shouldProfileExecute();

    m_GalilOperation.setOperationIndex(this->getOperationIndex());
    m_GalilOperation.setOperationName(this->getOperationName());
    m_GalilOperation.writeToJSON(obj);

    m_ConfigPowerSupply.writeToJSON(obj);

    m_PumpParameters.writeToJSON(obj);

    m_Touchoff.writeToJSON(obj);
}

void ECMCommand_ProfileConfiguration::readFromJSON(const QJsonObject &obj)
{
    this->setOperationIndex(obj["opIndex"].toInt());
    this->setOperationName(obj["opName"].toString().toStdString());
    this->setProfileExecution(obj["useOperation"].toBool());
    m_GalilOperation.readFromJSON(obj);
    m_ConfigPowerSupply.readFromJSON(obj);
    m_PumpParameters.readFromJSON(obj);
    m_Touchoff.readFromJSON(obj);
}

ECMCommand_ProfileConfiguration::ECMCommand_ProfileConfiguration(const ECMCommand_ProfileConfiguration &copy)
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

unsigned int ECMCommand_ProfileConfiguration::getOperationIndex() const
{
    return this->operationIndex;
}

std::string ECMCommand_ProfileConfiguration::getOperationName() const
{
    return this->operationName;
}

std::string ECMCommand_ProfileConfiguration::getProfileName() const
{
    return this->m_GalilOperation.getProfileName();
}

bool ECMCommand_ProfileConfiguration::shouldHomeBeIndicated() const
{
    return this->indicateHome;
}

bool ECMCommand_ProfileConfiguration::shouldProfileExecute() const
{
    return this->shouldExecute;
}

bool ECMCommand_ProfileConfiguration::hasProfileCompleted() const
{
    return this->execProperties.hasProfileBeenCompleted();
}

void ECMCommand_ProfileConfiguration::setOperationIndex(const unsigned int &index)
{
    this->operationIndex = index;
}

void ECMCommand_ProfileConfiguration::setOperationName(const std::string &name)
{
    this->operationName = name;
}

void ECMCommand_ProfileConfiguration::setIndicateHomeAutomatically(const bool &homeExecute)
{
    this->indicateHome = homeExecute;
}

void ECMCommand_ProfileConfiguration::setProfileExecution(const bool &varExecute)
{
    this->shouldExecute = varExecute;
}
