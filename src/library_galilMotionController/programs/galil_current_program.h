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

private:
    std::string program;
    ProgramLabelList labelList;
    ProgramVariableList variableList;
};

#endif // GALIL_CURRENT_PROGRAM_H
