#ifndef PROGRAM_GENERIC_PROFILE_H
#define PROGRAM_GENERIC_PROFILE_H

#include <map>
#include <string>
#include <iostream>

#include <QJsonArray>
#include <QJsonObject>

#include "programs/program_profile_gain.h"
#include "programs/program_profile_variable.h"

class ProgramGenericProfile
{
public:
    ProgramGenericProfile();
    ProgramGenericProfile(const ProgramGenericProfile &copy);

    ~ProgramGenericProfile();

    std::string getProfileProgram() const;

public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    void copyData(const ProgramGenericProfile &copy);

public:
    void setProfileName(const std::string &name);
    std::string getProfileName() const;

    void setProfileLabel(const std::string &label);
    std::string getProfileLabel() const;

    void setProfileDescription(const std::string &description);
    std::string getProfileDescription() const;

    void setProfileCode(const std::string &code);
    std::string getProfileCode() const;

    void setVariableMap(const std::map<std::string,ProgramProfileVariable> &data);
    std::map<std::string,ProgramProfileVariable> getVariableMap() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ProgramGenericProfile& operator = (const ProgramGenericProfile &rhs)
    {
        this->profileName = rhs.profileName;
        this->profileLabel = rhs.profileLabel;
        this->profileEndTag = rhs.profileEndTag;
        this->profileDescriptor = rhs.profileDescriptor;
        this->profileCode = rhs.profileCode;
        this->profileGain = rhs.profileGain;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ProgramGenericProfile &rhs)
    {
        if(this->profileName != rhs.profileName){
            return false;
        }
        if(this->profileLabel != rhs.profileLabel){
            return false;
        }
        if(this->profileEndTag != rhs.profileEndTag){
            return false;
        }
        if(this->profileDescriptor != rhs.profileDescriptor){
            return false;
        }
        if(this->profileCode != rhs.profileCode){
            return false;
        }
        if(this->profileGain != rhs.profileGain){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ProgramGenericProfile &rhs) {
        return !(*this == rhs);
    }



private:
    std::string profileName = "Default";
    std::string profileLabel = "Default";
    std::string profileEndTag = "enDefault";
    std::string profileDescriptor = "Description";
    std::string profileCode = "";

public:
    ProgramProfileGain profileGain;

private:
    std::map<std::string,ProgramProfileVariable> variableMap;

};

#endif // PROGRAM_GENERIC_PROFILE_H
