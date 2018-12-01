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
   std::pair<std::map<unsigned int,ECMCommand_ProfileConfiguration>::iterator,bool> ret;
   ret = m_Collection.insert(std::pair<unsigned int, ECMCommand_ProfileConfiguration>(profile.getOperationIndex(),profile));

   if(ret.second == false)
   {
       //this means there was something already at that index
       m_Collection.at(profile.getOperationIndex()) = profile;
   }
}

ECMCommand_ProfileConfiguration ECMCommand_ProfileCollection::getProfile(const unsigned int &index) const
{
    return this->m_Collection.at(index);
}

unsigned int ECMCommand_ProfileCollection::getCollectionSize() const
{
    return this->m_Collection.size();
}
