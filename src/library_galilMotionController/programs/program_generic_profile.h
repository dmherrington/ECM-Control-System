#ifndef PROGRAM_GENERIC_PROFILE_H
#define PROGRAM_GENERIC_PROFILE_H

#include <map>
#include <string>
#include <iostream>

#include <QJsonArray>
#include <QJsonObject>

#include "settings/settings_profile_variable.h"
#include "settings/settings_profile_gain.h"

class ProgramGenericProfile
{
public:
    ProgramGenericProfile();
    ProgramGenericProfile(const ProgramGenericProfile &copy);

    ~ProgramGenericProfile();

public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    void copyData(const ProgramGenericProfile &copy);

public:
    void setProfileName(const std::string &name);
    std::string getProfileName() const;

    void setProfileLabel(const std::string &label);
    std::string getProfileLabel() const;

    void setVariableMap(const std::map<std::string,SettingsProfileVariable> &data);
    std::map<std::string,SettingsProfileVariable> getVariableMap() const;

public:
    SettingsProfileGain* profileGain;

private:
    std::string profileName = "Default";
    std::string profileLabel = "Default";

    std::map<std::string,SettingsProfileVariable> variableMap;

};

#endif // PROGRAM_GENERIC_PROFILE_H
