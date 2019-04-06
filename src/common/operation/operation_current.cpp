#include "operation_current.h"

Operation_CurrentProgram::Operation_CurrentProgram()
{

}

Operation_CurrentProgram::Operation_CurrentProgram(const Operation_CurrentProgram &copy)
{

}

void Operation_CurrentProgram::writeToJSON(QJsonObject &saveObject)
{

}

void Operation_CurrentProgram::readFromJSON(const QJsonObject &openObject)
{

}

void Operation_CurrentProgram::setProgramLoaded(const bool &loaded, const std::string &path)
{

}

void Operation_CurrentProgram::setOperationIndex(const unsigned int &index)
{

}

void Operation_CurrentProgram::setOperationName(const std::string &name)
{

}

void Operation_CurrentProgram::setProfileName(const std::string &name)
{

}

bool Operation_CurrentProgram::wasProgramLoaded(std::string &path) const
{

}

unsigned int Operation_CurrentProgram::getOperationIndex() const
{

}

std::string Operation_CurrentProgram::getOperationName() const
{

}

std::string Operation_CurrentProgram::getProfileName() const
{

}
