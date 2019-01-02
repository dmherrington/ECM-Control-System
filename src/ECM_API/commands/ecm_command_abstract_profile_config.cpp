#include "ecm_command_abstract_profile_config.h"

ECMCommand_AbstractProfileConfig::ECMCommand_AbstractProfileConfig(const ProfileOpType &configType)
{
    this->configType = configType;
}

ECMCommand_AbstractProfileConfig::ECMCommand_AbstractProfileConfig(const ECMCommand_AbstractProfileConfig &copy)
{
    this->configType = copy.configType;
    this->operationIndex = copy.operationIndex;
    this->operationName = copy.operationName;
    this->indicateHome = copy.indicateHome;
    this->shouldExecute = copy.shouldExecute;

    this->execProperties = copy.execProperties;
}

void ECMCommand_AbstractProfileConfig::writeToJSON(QJsonObject &obj)
{
    obj["opType"] = static_cast<int>(this->getConfigType());
    obj["opIndex"] = static_cast<int>(this->getOperationIndex());
    obj["opName"] = QString::fromStdString(this->getOperationName());
    obj["useOperation"] = this->shouldProfileExecute();
}

void ECMCommand_AbstractProfileConfig::readFromJSON(const QJsonObject &obj)
{
    this->setOperationIndex(obj["opIndex"].toInt());
    this->setOperationName(obj["opName"].toString().toStdString());
    this->setProfileExecution(obj["useOperation"].toBool());
}


unsigned int ECMCommand_AbstractProfileConfig::getOperationIndex() const
{
    return this->operationIndex;
}

std::string ECMCommand_AbstractProfileConfig::getOperationName() const
{
    return this->operationName;
}

bool ECMCommand_AbstractProfileConfig::shouldHomeBeIndicated() const
{
    return this->indicateHome;
}

bool ECMCommand_AbstractProfileConfig::shouldProfileExecute() const
{
    return this->shouldExecute;
}

bool ECMCommand_AbstractProfileConfig::hasProfileCompleted() const
{
    return this->execProperties.hasProfileBeenCompleted();
}

void ECMCommand_AbstractProfileConfig::setOperationIndex(const unsigned int &index)
{
    this->operationIndex = index;
}

void ECMCommand_AbstractProfileConfig::setOperationName(const std::string &name)
{
    this->operationName = name;
}

void ECMCommand_AbstractProfileConfig::setIndicateHomeAutomatically(const bool &homeExecute)
{
    this->indicateHome = homeExecute;
}

void ECMCommand_AbstractProfileConfig::setProfileExecution(const bool &varExecute)
{
    this->shouldExecute = varExecute;
}

