#include "ecmcommand_profile_configuration.h"

ECMCommand_ProfileConfiguration::ECMCommand_ProfileConfiguration()
{

}

void ECMCommand_ProfileConfiguration::writeToJSON(QJsonObject &obj)
{
    obj["opIndex"] = (int)this->getOperationIndex();
    obj["opName"] = QString::fromStdString(this->getOperationName());
    obj["useOperation"] = this->shouldProfileExecute();
    m_GalilOperation.writeToJSON(obj);
    m_MunkPulseMode.writeToJSON(obj);
    m_MunkSegment.writeToJSON(obj);
    m_PumpParameters.writeToJSON(obj);
    m_Touchoff.writeToJSON(obj);
}

void ECMCommand_ProfileConfiguration::readFromJSON(const QJsonObject &obj)
{
    this->setOperationIndex(obj["opIndex"].toInt());
    this->setOperationName(obj["opName"].toString().toStdString());
    this->setProfileExecution(obj["useOperation"].toBool());
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

unsigned int ECMCommand_ProfileConfiguration::getOperationIndex() const
{
    return this->operationIndex;
}

std::string ECMCommand_ProfileConfiguration::getOperationName() const
{
    return this->operationName;
}

bool ECMCommand_ProfileConfiguration::shouldProfileExecute() const
{
    return this->execute;
}

void ECMCommand_ProfileConfiguration::setOperationIndex(const unsigned int &index)
{
    this->operationIndex = index;
}

void ECMCommand_ProfileConfiguration::setOperationName(const std::string &name)
{
    this->operationName = name;
}
void ECMCommand_ProfileConfiguration::setProfileExecution(const bool &varExecute)
{
    this->execute = varExecute;
}
