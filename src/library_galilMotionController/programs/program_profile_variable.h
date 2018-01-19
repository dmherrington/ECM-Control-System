#ifndef PROGRAM_PROFILE_VARIABLE_H
#define PROGRAM_PROFILE_VARIABLE_H

#include <QString>
#include <QJsonArray>
#include <QJsonObject>

#include <string>

class ProgramProfileVariable
{
public:
    ProgramProfileVariable();

    ProgramProfileVariable(const ProgramProfileVariable &copy);

    ~ProgramProfileVariable() = default;

public:
    void read(const QJsonObject &jsonObject);
    void write(QJsonArray &jsonArray) const;

public:
    //!
    //! \brief getDisplayName
    //! \return
    //!
    std::string getDisplayName() const;

    //!
    //! \brief getVariableName
    //! \return
    //!
    std::string getVariableName() const;

    //!
    //! \brief getCurrentValue
    //! \return
    //!
    double getCurrentValue() const;

    //!
    //! \brief getDefaultValue
    //! \return
    //!
    double getDefaultValue() const;

    //!
    //! \brief getMaxValue
    //! \return
    //!
    double getMaxValue() const;

    //!
    //! \brief getMinValue
    //! \return
    //!
    double getMinValue() const;

    //!
    //! \brief setDisplayName
    //! \param name
    //!
    void setDisplayName(const std::string &name);

    //!
    //! \brief setVariableName
    //! \param name
    //!
    void setVariableName(const std::string &name);

    //!
    //! \brief setCurrentValue
    //! \param value
    //!
    void setCurrentValue(const double &value);

    //!
    //! \brief setDefaultValue
    //! \param value
    //!
    void setDefaultValue(const double &value);

    //!
    //! \brief setMaxValue
    //! \param value
    //!
    void setMaxValue(const double &value);

    //!
    //! \brief setMinValue
    //! \param value
    //!
    void setMinValue(const double &value);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ProgramProfileVariable& operator = (const ProgramProfileVariable &rhs)
    {
        this->variableName = rhs.variableName;
        this->displayName = rhs.displayName;
        this->max = rhs.max;
        this->min = rhs.min;
        this->def = rhs.def;
        this->cur = rhs.cur;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ProgramProfileVariable &rhs)
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
        if(this->cur != rhs.cur){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ProgramProfileVariable &rhs) {
        return !(*this == rhs);
    }

private:
    std::string variableName = "";
    std::string displayName = "";
    double max = 0.0;
    double min = 0.0;
    double def = 0.0;
    double cur = 0.0;
};

#endif // PROGRAM_PROFILE_VARIABLE_H
