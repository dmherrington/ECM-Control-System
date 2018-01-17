#ifndef GALIL_CURRENT_PROGRAM_H
#define GALIL_CURRENT_PROGRAM_H

#include <string>
#include <map>

class GalilCurrentProgram
{
public:
    GalilCurrentProgram();

    GalilCurrentProgram(const GalilCurrentProgram &copy);

    ~GalilCurrentProgram() = default;

public:
    void setProgram(const std::string &programString);

    void setLabels(const std::map<std::string, int> &labelMap);

    void setVariables(const std::map<std::string, int> &variableMap);

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
    std::map<std::string, int> labels;
    std::map<std::string, int> variables;
};

#endif // GALIL_CURRENT_PROGRAM_H
