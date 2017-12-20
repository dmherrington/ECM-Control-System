#include "program_interface.h"

ProgramInterface::ProgramInterface()
{

}

ProgramInterface::ProgramInterface(const ProgramInterface &copy)
{
    this->program = copy.program;
    this->labels = copy.labels;
    this->variables = copy.labels;
}

void ProgramInterface::setProgram(const std::string &programString)
{
    this->program = programString;
}

void ProgramInterface::setLabels(const std::map<std::string, int> &labelMap)
{
    this->labels = labelMap;
}

void ProgramInterface::setVariables(const std::map<std::string, int> &variableMap)
{
    this->variables = variableMap;
}

bool ProgramInterface::doesLabelExist(const std::string &label) const
{
    if(this->labels.count(label) > 0)
        return true;
    return false;
}

bool ProgramInterface::doesVariableExist(const std::string &variable) const
{
    if(this->variables.count(variable) > 0)
        return true;
    return false;
}

bool ProgramInterface::getLabelLine(const std::string &label, int &line) const
{
    if(this->labels.count(label) == 0)
        return false;
    line = this->labels.at(label);
    return true;
}

bool ProgramInterface::getVariableLine(const std::string &variable, int &line) const
{
    if(this->variables.count(variable) == 0)
        return false;
    line = this->variables.at(variable);
    return true;
}

std::string ProgramInterface::getProgram() const
{
    return this->program;
}
