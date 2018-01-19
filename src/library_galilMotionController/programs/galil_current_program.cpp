#include "galil_current_program.h"

GalilCurrentProgram::GalilCurrentProgram()
{

}

GalilCurrentProgram::GalilCurrentProgram(const GalilCurrentProgram &copy)
{
    this->program = copy.program;
    this->labels = copy.labels;
    this->variables = copy.labels;
}

void GalilCurrentProgram::setProgram(const std::string &programString)
{
    this->program = programString;
}

void GalilCurrentProgram::setLabels(const std::map<std::string, int> &labelMap)
{
    this->labels = labelMap;
}

void GalilCurrentProgram::setVariables(const std::map<std::string, int> &variableMap)
{
    this->variables = variableMap;
}

bool GalilCurrentProgram::doesLabelExist(const std::string &label) const
{
    if(this->labels.count(label) > 0)
        return true;
    return false;
}

bool GalilCurrentProgram::doesVariableExist(const std::string &variable) const
{
    if(this->variables.count(variable) > 0)
        return true;
    return false;
}

bool GalilCurrentProgram::getLabelLine(const std::string &label, int &line) const
{
    if(this->labels.count(label) == 0)
        return false;
    line = this->labels.at(label);
    return true;
}

bool GalilCurrentProgram::getVariableLine(const std::string &variable, int &line) const
{
    if(this->variables.count(variable) == 0)
        return false;
    line = this->variables.at(variable);
    return true;
}

std::map<std::string, int> GalilCurrentProgram::getLablMap() const
{
    return this->labels;
}

std::map<std::string, int> GalilCurrentProgram::getVariableMap() const
{
    return this->variables;
}

std::string GalilCurrentProgram::getProgram() const
{
    return this->program;
}
