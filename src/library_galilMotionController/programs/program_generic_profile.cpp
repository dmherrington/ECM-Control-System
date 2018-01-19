#include "program_generic_profile.h"

ProgramGenericProfile::ProgramGenericProfile()
{

}

ProgramGenericProfile::ProgramGenericProfile(const ProgramGenericProfile &copy)
{
    this->copyData(copy);
}

std::string ProgramGenericProfile::getProfileProgram() const
{
    std::string programString;
    programString += "'**************************************\r\n";
    programString += "#" + this->profileLabel + "\r\n";
    programString += "'**************************************\r\n";
    programString += this->profileCode + "\r\n";
    programString += this->profileEndTag + "\r\n";
    return programString;
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
    //destructor of the ProgramGenericProfile class
    //iterate through the variable list and destroy variables
}

void ProgramGenericProfile::read(const QJsonObject &json)
{
    this->setProfileName(json["ProfileName"].toString().toStdString());
    this->setProfileLabel(json["ProfileLabel"].toString().toStdString());
    this->setProfileDescription(json["ProfileDescriptor"].toString().toStdString());
    this->setProfileCode(json["ProfileCode"].toString().toStdString());

    this->profileGain.read(json);
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

    //third, add the description associated with the profile
    json["ProfileDescriptor"] = QString::fromStdString(profileDescriptor);

    //fourth, add the the actual profile code as related to the specific profile
    json["ProfileCode"] = QString::fromStdString(profileCode);

    //third, write the gains needed by the galil when executing this profile
    profileGain.write(json);

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

void ProgramGenericProfile::setProfileLabel(const std::string &label)
{
    this->profileLabel = label;
    this->profileEndTag = "e" + label;
}

std::string ProgramGenericProfile::getProfileDescription() const
{
    return this->profileDescriptor;
}

void ProgramGenericProfile::setProfileDescription(const std::string &description)
{
    this->profileDescriptor = description;
}

std::string ProgramGenericProfile::getProfileCode() const
{
    return this->profileCode;
}

void ProgramGenericProfile::setProfileCode(const std::string &code)
{
    this->profileCode = code;
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
