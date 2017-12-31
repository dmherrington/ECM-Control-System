#include "settings_generic_profile.h"

SettingsGenericProfile::SettingsGenericProfile()
{

}

SettingsGenericProfile::~SettingsGenericProfile()
{
    //destructor of the SettingsGenericProfile class

    //first remove the SettingsProfileGain class
    delete profileGain;
    profileGain = nullptr;

    //next iterate through the variable list and destroy variables
}

std::string SettingsGenericProfile::getProfileName() const
{
    return this->profileName;
}

void SettingsGenericProfile::setProfileName(const std::string &name)
{
    this->profileName = name;
}
