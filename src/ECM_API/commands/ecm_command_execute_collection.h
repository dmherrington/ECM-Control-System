#ifndef ECM_COMMAND_EXECUTE_COLLECTION_H
#define ECM_COMMAND_EXECUTE_COLLECTION_H

#include "ecm_command_profile_collection.h"

class ECMCommand_ExecuteCollection : public ECMCommand_ProfileCollection
{
public:
    ECMCommand_ExecuteCollection();

public:
    void setPartNumber(const std::string &number);
    void setSerialNumber(const std::string &number);
    void setCurrentProfileCompleted();
    void setOverwriteLogs(const bool &overwrite);

public:
    std::string getPartNumber() const;
    std::string getSerialNumber() const;
    unsigned int getActiveIndex() const;
    bool shouldOverwriteLogs() const;

private:
    std::string partNumber = "";
    std::string serialNumber = "";
    unsigned int activeIndex = 0;
    bool overwriteContents = true;
};

#endif // ECM_COMMAND_EXECUTE_COLLECTION_H
