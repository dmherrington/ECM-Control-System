#ifndef GALIL_CURRENT_PROGRAM_H
#define GALIL_CURRENT_PROGRAM_H

#include <string>
#include <map>

#include "program_label_list.h"
#include "program_variable_list.h"

class GalilCurrentProgram
{
public:
    GalilCurrentProgram();

    GalilCurrentProgram(const GalilCurrentProgram &copy);

    ~GalilCurrentProgram() = default;

public:
    void setProgram(const std::string &programString);

    void setLabelList(const ProgramLabelList &list);

    void setVariableList(const ProgramVariableList &list);

public:
    bool doesLabelExist(const std::string &label) const;

    bool doesVariableExist(const std::string &variable) const;

    bool getLabelLine(const std::string &label, int &line) const;

    bool getVariableLine(const std::string &variable, int &line) const;

    std::map<std::string, int> getLablMap() const;

    std::map<std::string, int> getVariableMap() const;

    std::string getProgram() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    GalilCurrentProgram& operator = (const GalilCurrentProgram &rhs)
    {
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

private:
    std::string program;
    ProgramLabelList labelList;
    ProgramVariableList variableList;
};

#endif // GALIL_CURRENT_PROGRAM_H
