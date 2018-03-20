#include "program_generic.h"

ProgramGeneric::ProgramGeneric()
{

}

ProgramGeneric::ProgramGeneric(const ProgramGeneric &copy)
{
    this->profileMap = copy.profileMap;
    this->programString = copy.programString;
}

void ProgramGeneric::setProgramString(const std::string &text)
{
    this->programString = text;
}

std::string ProgramGeneric::getProgramString() const
{
    return this->programString;
}

void ProgramGeneric::addProfile(const ProgramGenericProfile &profile)
{
    std::string profileName = profile.getProfileName();

    std::pair<std::map<std::string, ProgramGenericProfile>::iterator,bool> ret;
    ret = profileMap.insert(std::pair<std::string, ProgramGenericProfile>(profileName,profile));

    if (ret.second==false) //this means that the item was already in there
    {
        ret.first->second = profile;
    }
}

bool ProgramGeneric::getProfileFromName(const std::string &profileName, ProgramGenericProfile &profile) const
{
    if(profileMap.count(profileName) > 0)
    {
        profile = profileMap.at(profileName);
        return true;
    }
    return false;
}

bool ProgramGeneric::getProfileLabel(const std::string &profileName, std::string &profileLabel) const
{
    if(profileMap.count(profileName) > 0)
    {
        profileLabel = profileMap.at(profileName).getProfileLabel();
        return true;
    }
    return false;
}

std::string ProgramGeneric::buildProgram() const
{
    std::string programString;

    std::map<std::string, ProgramGenericProfile>::iterator it; //establish an iterator to move through map
    for(it == profileMap.begin(); it != profileMap.end(); ++it)
    {
        ProgramGenericProfile profile = it->second;
        programString += profile.getProfileProgram();
        programString += "\r\n";
    }

    return programString;
}
