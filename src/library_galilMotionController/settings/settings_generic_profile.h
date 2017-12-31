#ifndef SETTINGS_GENERIC_PROFILE_H
#define SETTINGS_GENERIC_PROFILE_H

#include <map>
#include <string>

#include <QJsonArray>
#include <QJsonObject>

#include "settings/settings_profile_variable.h"
#include "settings/settings_profile_gain.h"

class SettingsGenericProfile
{
public:
    SettingsGenericProfile();
    ~SettingsGenericProfile();

public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

public:
    void setProfileName(const std::string &name);
    std::string getProfileName() const;

public:
    SettingsProfileGain* profileGain;

private:
    std::string profileName = "Default";
    std::map<std::string,SettingsProfileVariable> variableMap;

};

#endif // SETTINGS_GENERIC_PROFILE_H
