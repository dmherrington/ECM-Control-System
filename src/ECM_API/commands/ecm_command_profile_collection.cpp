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

void ECMCommand_ProfileCollection::insertProfile(const ECMCommand_ProfileConfiguration &profile)
{
    std::pair<std::map<unsigned int,ECMCommand_ProfileConfiguration>::iterator,bool> ret;
    ret = m_Collection.insert(std::pair<unsigned int, ECMCommand_ProfileConfiguration>(profile.getOperationIndex(),profile));

    if(ret.second == false)
    {
        //this means there was something already at that index
        m_Collection.at(profile.getOperationIndex()) = profile;
    }
}

ECMCommand_ProfileConfiguration ECMCommand_ProfileCollection::getLeadingProfile() const
{
    std::map<unsigned int,ECMCommand_ProfileConfiguration>::const_iterator it = m_Collection.begin();
    ECMCommand_ProfileConfiguration leadingProfile = it->second;
    return leadingProfile;
}

ECMCommand_ProfileConfiguration ECMCommand_ProfileCollection::getProfile(const unsigned int &index) const
{
    return this->m_Collection.at(index);
}

unsigned int ECMCommand_ProfileCollection::getCollectionSize() const
{
    return this->m_Collection.size();
}
