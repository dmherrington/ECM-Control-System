#include "galil_current_program.h"

GalilCurrentProgram::GalilCurrentProgram()
{

}

GalilCurrentProgram::GalilCurrentProgram(const GalilCurrentProgram &copy)
{
    this->programLoaded = copy.programLoaded;
    this->programPath = copy.programPath;

    this->program = copy.program;
    this->labelList = copy.labelList;
    this->variableList = copy.variableList;
}

void GalilCurrentProgram::writeToJSON(QJsonObject &saveObject)
{
    UNUSED(saveObject);
}

void GalilCurrentProgram::readFromJSON(const QJsonObject &openObject)
{
    UNUSED(openObject);
}

void GalilCurrentProgram::setProgram(const std::string &programString)
{
    this->program = programString;
}

void GalilCurrentProgram::setLabelList(const ProgramLabelList &list)
{
    this->labelList = list;
}

void GalilCurrentProgram::setVariableList(const ProgramVariableList &list)
{
    this->variableList = list;
}

void GalilCurrentProgram::setProgramLoaded(const bool &loaded, const std::string &path)
{
    this->programLoaded = loaded;
    this->programPath = path;
}

void GalilCurrentProgram::updateVariableValue(const std::string &name, const double &value)
{
    this->variableList.updateVariable(name,value);
}

bool GalilCurrentProgram::doesLabelExist(const std::string &label) const
{
    return labelList.doesLabelExist(label);
}

bool GalilCurrentProgram::doesVariableExist(const std::string &variable) const
{
    return variableList.doesVariableExist(variable);
}

bool GalilCurrentProgram::getLabelLine(const std::string &label, int &line) const
{
    if(this->labelList.doesLabelExist(label))
        return false;
    this->labelList.getLabelLine(label,line);
    return true;
}

bool GalilCurrentProgram::wasProgramLoaded(std::string &path) const
{
    path = this->programPath;
    return this->programLoaded;
}

std::map<std::string, int> GalilCurrentProgram::getLablMap() const
{
    return this->labelList.getLabelMap();
}

std::map<std::string, double> GalilCurrentProgram::getVariableMap() const
{
    return this->variableList.getVariableMap();
}

ProgramLabelList GalilCurrentProgram::getLabelList() const
{
    return this->labelList;
}

ProgramVariableList GalilCurrentProgram::getVariableList() const
{
    return this->variableList;
}

std::string GalilCurrentProgram::getProgram() const
{
    return this->program;
}

std::string GalilCurrentProgram::getLoggingString() const
{
    std::string str;
    return this->getProgram();
}
