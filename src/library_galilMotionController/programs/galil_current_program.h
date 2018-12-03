#ifndef GALIL_CURRENT_PROGRAM_H
#define GALIL_CURRENT_PROGRAM_H

#include <QJsonObject>
#include <QTextStream>

#include <string>
#include <map>

#include "common/common.h"

#include "program_label_list.h"
#include "program_variable_list.h"

class GalilCurrentProgram
{
public:
    GalilCurrentProgram();

    GalilCurrentProgram(const GalilCurrentProgram &copy);

    ~GalilCurrentProgram() = default;

public:
    void writeToJSON(QJsonObject &saveObject);

    void readFromJSON(const QJsonObject &openObject);

public:

    void fromProgram(const GalilCurrentProgram &copy);

    void setProgram(const std::string &programString);

    void setLabelList(const ProgramLabelList &list);

    void setVariableList(const ProgramVariableList &list);

    void setProgramLoaded(const bool &loaded, const std::string &path);

    void updateVariableValue(const std::string &name, const double &value);


public:
    bool doesLabelExist(const std::string &label) const;

    bool doesVariableExist(const std::string &variable) const;

    bool getLabelLine(const std::string &label, int &line) const;

    bool wasProgramLoaded(std::string &path) const;

    std::map<std::string, int> getLablMap() const;

    std::map<std::string, double> getVariableMap() const;

    ProgramLabelList getLabelList() const;

    ProgramVariableList getVariableList() const;

    std::string getProgram() const;

    std::string getLoggingString() const;

public:
    friend QTextStream& operator <<(QTextStream &outStream, const GalilCurrentProgram &data)
    {
        return outStream<<QString::fromStdString(data.getLoggingString());
    }

    friend std::ostream& operator<< (std::ostream &stream, const GalilCurrentProgram &data)
    {
        return stream<<data.getLoggingString();
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    GalilCurrentProgram& operator = (const GalilCurrentProgram &rhs)
    {
        this->programLoaded = rhs.programLoaded;
        this->programPath = rhs.programPath;

        this->program = rhs.program;
        this->labelList = rhs.labelList;
        this->variableList = rhs.variableList;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const GalilCurrentProgram &rhs)
    {
        if(this->programLoaded != rhs.programLoaded){
            return false;
        }
        if(this->programPath != rhs.programPath){
            return false;
        }

        if(this->program != rhs.program){
            return false;
        }
        if(this->labelList != rhs.labelList){
            return false;
        }
        if(this->variableList != rhs.variableList){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const GalilCurrentProgram &rhs) {
        return !(*this == rhs);
    }

protected:
    bool programLoaded = false;
    std::string programPath = "";

protected:
    std::string program;
    ProgramLabelList labelList;
    ProgramVariableList variableList;
};

#endif // GALIL_CURRENT_PROGRAM_H
