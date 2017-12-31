#ifndef SETTINGS_PROFILE_VARIABLE_H
#define SETTINGS_PROFILE_VARIABLE_H

#include <QString>
#include <QJsonArray>
#include <QJsonObject>

#include <string>

class SettingsProfileVariable
{
public:
    SettingsProfileVariable();

    SettingsProfileVariable(const SettingsProfileVariable &copy);

    ~SettingsProfileVariable() = default;

public:
    void read(const QJsonObject &jsonObject);
    void write(QJsonArray &jsonArray) const;

public:
    std::string getDisplayName() const;
    std::string getVariableName() const;
    double getDefaultValue() const;
    double getMaxValue() const;
    double getMinValue() const;

    void setDisplayName(const std::string &name);
    void setVariableName(const std::string &name);
    void setDefaultValue(const double &value);
    void setMaxValue(const double &value);
    void setMinValue(const double &value);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    void operator = (const SettingsProfileVariable &rhs)
    {
        this->variableName = rhs.variableName;
        this->displayName = rhs.displayName;
        this->max = rhs.max;
        this->min = rhs.min;
        this->def = rhs.def;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const SettingsProfileVariable &rhs)
    {
        if(this->variableName != rhs.variableName){
            return false;
        }
        if(this->displayName != rhs.displayName){
            return false;
        }
        if(this->max != rhs.max){
            return false;
        }
        if(this->min != rhs.min){
            return false;
        }
        if(this->def != rhs.def){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const SettingsProfileVariable &rhs) {
        return !(*this == rhs);
    }

private:
    std::string variableName = "";
    std::string displayName = "";
    double max = 0.0;
    double min = 0.0;
    double def = 0.0;
};

#endif // SETTINGS_PROFILE_VARIABLE_H
