#include "ecm_command_profile_collection.h"

ECMCommand_ProfileCollection::ECMCommand_ProfileCollection():
    ECMCommand_AbstractCollection()
{
    this->collectionType = CollectionType::ECMCollection_Profile;
}

ECMCommand_ProfileCollection::ECMCommand_ProfileCollection(const ECMCommand_ProfileCollection &copy):
    ECMCommand_AbstractCollection(copy)
{
    this->m_Collection = copy.m_Collection;
}


ECMCommand_AbstractCollectionPtr ECMCommand_ProfileCollection::getClone() const
{
    return std::make_shared<ECMCommand_ProfileCollection>(*this);
}

void ECMCommand_ProfileCollection::getClone(ECMCommand_AbstractCollectionPtr &collection) const
{
    collection = std::make_shared<ECMCommand_ProfileCollection>(*this);
}

void ECMCommand_ProfileCollection::insertProfile(const ECMCommand_ProfileConfiguration *profile)
{
    std::pair<std::map<unsigned int,ECMCommand_AbstractProfileConfig*>::iterator,bool> ret;
    ret = m_Collection.insert(std::pair<unsigned int, ECMCommand_AbstractProfileConfig*>(profile.getOperationIndex(),profile));

    if(ret.second == false)
    {
        //this means there was something already at that index
        m_Collection.at(profile.getOperationIndex()) = profile;
    }
}

ECMCommand_AbstractProfileConfig* ECMCommand_ProfileCollection::getLeadingProfile() const
{
    std::map<unsigned int,ECMCommand_AbstractProfileConfig*>::const_iterator it = m_Collection.begin();
    ECMCommand_AbstractProfileConfig* leadingProfile = it->second;
    return leadingProfile;
}

ECMCommand_AbstractProfileConfig *ECMCommand_ProfileCollection::getProfile(const unsigned int &index) const
{
    return this->m_Collection.at(index);
}

std::map<unsigned int, ECMCommand_AbstractProfileConfig*> ECMCommand_ProfileCollection::getCollection() const
{
    return this->m_Collection;
}

unsigned int ECMCommand_ProfileCollection::getActiveCollectionSize() const
{
    unsigned int count = 0;
    std::map<unsigned int, ECMCommand_AbstractProfileConfig*>::const_iterator it = m_Collection.begin();
    for(; it != m_Collection.end(); ++it)
    {
        if(it->second->shouldProfileExecute())
            count++;
    }

    return count;
}

unsigned int ECMCommand_ProfileCollection::getCollectionSize() const
{
    return this->m_Collection.size();
}

void ECMCommand_ProfileCollection::setAssociatedMotionScript(const std::string &script)
{
    std::map<unsigned int, ECMCommand_AbstractProfileConfig>::iterator it = m_Collection.begin();
    for(; it != m_Collection.end(); ++it)
    {
        ECMCommand_ProfileConfiguration currentConfig = it->second;
        currentConfig.m_GalilOperation.setProgram(script);
    }
}
