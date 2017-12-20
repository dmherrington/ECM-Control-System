#ifndef PROGRAM_INTERFACE_H
#define PROGRAM_INTERFACE_H

#include <string>

#include <map>

class ProgramInterface
{
public:
    ProgramInterface();

    ProgramInterface(const ProgramInterface &copy);

    ~ProgramInterface() = default;

public:
    void setProgram(const std::string &programString);

    void setLabels(const std::map<std::string, int> &labelMap);

    void setVariables(const std::map<std::string, int> &variableMap);

public:
    bool doesLabelExist(const std::string &label) const;

    bool doesVariableExist(const std::string &variable) const;

    bool getLabelLine(const std::string &label, int &line) const;

    bool getVariableLine(const std::string &variable, int &line) const;

    std::string getProgram() const;

private:
    std::string program;
    std::map<std::string, int> labels;
    std::map<std::string, int> variables;
};

#endif // PROGRAM_INTERFACE_H
