#include "settings_generic_profile.h"

SettingsGenericProfile::SettingsGenericProfile()
{
    profileGain = new SettingsProfileGain();
}

SettingsGenericProfile::~SettingsGenericProfile()
{
    //destructor of the SettingsGenericProfile class

    //first remove the SettingsProfileGain class
    delete profileGain;
    profileGain = nullptr;

    //next iterate through the variable list and destroy variables
}

void SettingsGenericProfile::read(const QJsonObject &json)
{

}

void SettingsGenericProfile::write(QJsonObject &json) const
{
    profileGain->write(json);
}

std::string SettingsGenericProfile::getProfileName() const
{
    return this->profileName;
}

void SettingsGenericProfile::setProfileName(const std::string &name)
{
    this->profileName = name;
}
