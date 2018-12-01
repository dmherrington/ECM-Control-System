#ifndef ECM_COMMAND_PROFILE_COLLECTION_H
#define ECM_COMMAND_PROFILE_COLLECTION_H

#include <map>

#include "ecm_command_profile_configuration.h"

class ECMCommand_ProfileCollection
{
public:
    ECMCommand_ProfileCollection();

    ECMCommand_ProfileCollection(const ECMCommand_ProfileCollection &copy);

public:
    void insertProfile(const ECMCommand_ProfileConfiguration &profile);

    ECMCommand_ProfileConfiguration getProfile(const unsigned int &index);

private:
    std::map<unsigned int, ECMCommand_ProfileConfiguration> m_Collection;
};

#endif // ECM_COMMAND_PROFILE_COLLECTION_H
