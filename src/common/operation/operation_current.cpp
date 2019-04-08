#include "operation_current.h"

Operation_CurrentProgram::Operation_CurrentProgram()
{

}

Operation_CurrentProgram::Operation_CurrentProgram(const Operation_CurrentProgram &copy)
{
    this->currentOpType = copy.currentOpType;

    this->programLoaded = copy.programLoaded;
    this->programPath = copy.programPath;

    this->operationIndex = copy.operationIndex;
    this->operationName = copy.operationName;
    this->profileName = copy.profileName;
}

void Operation_CurrentProgram::writeToJSON(QJsonObject &saveObject)
{
    saveObject["opType"] = static_cast<int>(this->getOperationType());

    saveObject["opIndex"] = static_cast<int>(this->getOperationIndex());
    saveObject["opName"] = QString::fromStdString(this->getOperationName());
    saveObject["profileName"] = QString::fromStdString(this->getProfileName());
}

void Operation_CurrentProgram::readFromJSON(const QJsonObject &openObject)
{
    this->setOperationType(static_cast<ProfileOpType>(openObject["opType"].toInt()));

    this->setOperationIndex(openObject["opIndex"].toInt());
    this->setOperationName(openObject["opName"].toString().toStdString());
    this->setProfileName(openObject["profileName"].toString().toStdString());
}

void Operation_CurrentProgram::setOperationType(const ProfileOpType &opType)
{
    this->currentOpType = opType;
}

void Operation_CurrentProgram::setProgramLoaded(const bool &loaded, const std::string &path)
{
    programLoaded = loaded;
    programPath = path;
}

void Operation_CurrentProgram::setOperationIndex(const unsigned int &index)
{
    this->operationIndex = index;
}

void Operation_CurrentProgram::setOperationName(const std::string &name)
{
    this->operationName = name;
}

void Operation_CurrentProgram::setProfileName(const std::string &name)
{
    this->profileName = name;
}

ProfileOpType Operation_CurrentProgram::getOperationType() const
{
    return this->currentOpType;
}
bool Operation_CurrentProgram::wasProgramLoaded(std::string &path) const
{
    path = this->programPath;
    return this->programLoaded;
}

unsigned int Operation_CurrentProgram::getOperationIndex() const
{
    return operationIndex;
}

std::string Operation_CurrentProgram::getOperationName() const
{
    return operationName;
}

std::string Operation_CurrentProgram::getProfileName() const
{
    return profileName;
}
