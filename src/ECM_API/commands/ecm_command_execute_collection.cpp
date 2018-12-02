#include "ecm_command_execute_collection.h"

ECMCommand_ExecuteCollection::ECMCommand_ExecuteCollection():
    ECMCommand_ProfileCollection()
{

}

void ECMCommand_ExecuteCollection::setPartNumber(const std::string &number)
{
    this->partNumber = number;
}

void ECMCommand_ExecuteCollection::setSerialNumber(const std::string &number)
{
    this->serialNumber = number;
}

void ECMCommand_ExecuteCollection::setCurrentProfileCompleted()
{
    this->m_Collection.at(this->getActiveIndex()).setProfileCompletion(true);
}

void ECMCommand_ExecuteCollection::setOverwriteLogs(const bool &overwrite)
{
    this->overwriteContents = overwrite;
}

std::string ECMCommand_ExecuteCollection::getPartNumber() const
{
    return this->partNumber;
}

std::string ECMCommand_ExecuteCollection::getSerialNumber() const
{
    return this->serialNumber;
}

unsigned int ECMCommand_ExecuteCollection::getActiveIndex() const
{
    return this->activeIndex;
}

bool ECMCommand_ExecuteCollection::shouldOverwriteLogs() const
{
    return this->overwriteContents;
}
