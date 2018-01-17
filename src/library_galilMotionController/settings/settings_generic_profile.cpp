#include "settings_generic_profile.h"

ProgramGenericProfile::ProgramGenericProfile()
{
    profileGain = new ProgramProfileGain();
}

ProgramGenericProfile::ProgramGenericProfile(const ProgramGenericProfile &copy)
{
    this->copyData(copy);
}

void ProgramGenericProfile::copyData(const ProgramGenericProfile &copy)
{
    this->profileName = copy.profileName;
    this->profileLabel = copy.profileLabel;
    this->profileGain = copy.profileGain;
    this->variableMap = copy.variableMap;
}

ProgramGenericProfile::~ProgramGenericProfile()
{
    //destructor of the SettingsGenericProfile class

    //first remove the SettingsProfileGain class
    delete profileGain;
    profileGain = nullptr;

    //next iterate through the variable list and destroy variables
}

void ProgramGenericProfile::read(const QJsonObject &json)
{
    this->setProfileName(json["ProfileName"].toString().toStdString());
    this->setProfileLabel(json["ProfileLabel"].toString().toStdString());
    this->profileGain->read(json);
    QJsonArray variableArray = json["Variables"].toArray();
    for(int i = 0; i < variableArray.size(); i++)
    {
        QJsonObject jsonObject = variableArray[i].toObject();
        ProgramProfileVariable variable;
        variable.read(jsonObject);
        this->variableMap[variable.getDisplayName()] = variable;
    }
}

void ProgramGenericProfile::write(QJsonObject &json) const
{
    //first, add the label name that shall be displayed when interacting with parameters from the profile
    json["ProfileName"] = QString::fromStdString(profileName);

    //second, add the label name that shall execute when selecting run profile
    json["ProfileLabel"] = QString::fromStdString(profileLabel);

    //third, write the gains needed by the galil when executing this profile
    profileGain->write(json);

    //next write all of the variables to the object
    QJsonArray variableDataArray;
    std::map<std::string,ProgramProfileVariable>::const_iterator it;
    for (it=variableMap.begin(); it!=variableMap.end(); ++it)
    {
        ProgramProfileVariable var = it->second;
        if((var.getDisplayName() == "") || (var.getVariableName() == ""))
            continue;

        var.write(variableDataArray);
    }
    json["Variables"] = variableDataArray;
}

std::string ProgramGenericProfile::getProfileName() const
{
    return this->profileName;
}

void ProgramGenericProfile::setProfileName(const std::string &name)
{
    this->profileName = name;
}

std::string ProgramGenericProfile::getProfileLabel() const
{
    return this->profileLabel;
}

void ProgramGenericProfile::setProfileLabel(const std::string &name)
{
    this->profileLabel = name;
}

void ProgramGenericProfile::setVariableMap(const std::map<std::string, ProgramProfileVariable> &data)
{
    this->variableMap.clear();
    this->variableMap = data;
}

std::map<std::string,ProgramProfileVariable> ProgramGenericProfile::getVariableMap() const
{
    return this->variableMap;
}
