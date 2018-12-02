#include "ecm_command_profile_collection.h"

ECMCommand_ProfileCollection::ECMCommand_ProfileCollection()
{

}

ECMCommand_ProfileCollection::ECMCommand_ProfileCollection(const ECMCommand_ProfileCollection &copy)
{
    this->m_Collection = copy.m_Collection;
}

void ECMCommand_ProfileCollection::insertProfile(const ECMCommand_ProfileConfiguration &profile)
{
   m_Collection.push_back(profile);
}

ECMCommand_ProfileConfiguration ECMCommand_ProfileCollection::getProfile(const unsigned int &index) const
{
    return this->m_Collection.at(index);
}

unsigned int ECMCommand_ProfileCollection::getCollectionSize() const
{
    return this->m_Collection.size();
}
