#ifndef PROGRAM_GENERIC_H
#define PROGRAM_GENERIC_H

#include <string.h>
#include <map>

#include "programs/program_generic_profile.h"

class ProgramGeneric
{
public:
    ProgramGeneric();

    ProgramGeneric(const ProgramGeneric &copy);

    void addProfile(const ProgramGenericProfile &profile);

    bool getProfileFromName(const std::string &profileName, ProgramGenericProfile &profile) const;

    bool getProfileLabel(const std::string &profileName, std::string &profileLabel) const;

    std::string buildProgram() const;

private:
    std::map<std::string, ProgramGenericProfile> profileMap;

};

#endif // PROGRAM_GENERIC_H
