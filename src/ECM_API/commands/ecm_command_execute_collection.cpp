#include "ecm_command_execute_collection.h"

ECMCommand_ExecuteCollection::ECMCommand_ExecuteCollection():
    ECMCommand_ProfileCollection()
{
    this->collectionType = CollectionType::ECMCollection_Execute;
}

ECMCommand_ExecuteCollection::ECMCommand_ExecuteCollection(const ECMCommand_ExecuteCollection &copy):
    ECMCommand_ProfileCollection(copy)
{
    this->partNumber = copy.partNumber;
    this->serialNumber = copy.serialNumber;
    this->activeIndex = copy.activeIndex;
    this->indicateHome = copy.indicateHome;
    this->overwriteContents = copy.overwriteContents;
}

ECMCommand_ExecuteCollection::ECMCommand_ExecuteCollection(const ECMCommand_ProfileCollection &proCollection):
    ECMCommand_ProfileCollection(proCollection)
{
    this->activeIndex = this->getLeadingProfile().getOperationIndex();
}

void ECMCommand_ExecuteCollection::insertProfile(const ECMCommand_ProfileConfiguration &profile)
{
    ECMCommand_ProfileCollection::insertProfile(profile);

    std::map<unsigned int,ECMCommand_ProfileConfiguration>::iterator it = m_Collection.begin();
    for (; it!=m_Collection.end(); ++it)
    {
        ECMCommand_ProfileConfiguration currentConfig = it->second;
        if(currentConfig.shouldProfileExecute() && !currentConfig.hasProfileCompleted())
        {
            this->activeIndex = currentConfig.getOperationIndex();
            break;
        }
    }
}

ECMCommand_AbstractCollectionPtr ECMCommand_ExecuteCollection::getClone() const
{
    return std::make_shared<ECMCommand_ExecuteCollection>(*this);
}

void ECMCommand_ExecuteCollection::getClone(ECMCommand_AbstractCollectionPtr &collection) const
{
    collection = std::make_shared<ECMCommand_ExecuteCollection>(*this);
}

ECMCommand_ProfileConfiguration ECMCommand_ExecuteCollection::getActiveConfiguration() const
{
    return this->m_Collection.at(activeIndex);
}

void ECMCommand_ExecuteCollection::setPartNumber(const std::string &number)
{
    this->partNumber = number;
}

void ECMCommand_ExecuteCollection::setSerialNumber(const std::string &number)
{
    this->serialNumber = number;
}

bool ECMCommand_ExecuteCollection::setProfileCompleted(const unsigned int &index)
{
    /*
     * We are first going to assume that everything is complete in the collection
     * unless we find an index that can negate this logic and should be executed.
     */
    bool returnCollectionCompleted = true;

    this->m_Collection.at(index).setProfileCompletion(true);

    std::map<unsigned int, ECMCommand_ProfileConfiguration>::iterator it;

    it = m_Collection.find(index);

    for (; it!=m_Collection.end(); ++it)
    {
        ECMCommand_ProfileConfiguration currentConfig = it->second;
        if(currentConfig.shouldProfileExecute())
        {
            this->activeIndex = currentConfig.getOperationIndex();
            returnCollectionCompleted = false;
            break;
        }
    }
    return returnCollectionCompleted;
}

void ECMCommand_ExecuteCollection::setHomeShouldIndicate(const bool &indicate)
{
    this->indicateHome = indicate;

    std::map<unsigned int, ECMCommand_ProfileConfiguration>::iterator it = m_Collection.begin();
    for (; it!=m_Collection.end(); ++it)
    {
        ECMCommand_ProfileConfiguration currentConfig = it->second;
        currentConfig.setHomeNeedsToBeIndicated(indicate);
    }
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

bool ECMCommand_ExecuteCollection::shouldHomeBeIndicated() const
{
    return this->indicateHome;
}

bool ECMCommand_ExecuteCollection::shouldOverwriteLogs() const
{
    return this->overwriteContents;
}
