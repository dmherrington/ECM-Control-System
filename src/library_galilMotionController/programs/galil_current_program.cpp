#include "galil_current_program.h"

GalilCurrentProgram::GalilCurrentProgram()
{

}

GalilCurrentProgram::GalilCurrentProgram(const GalilCurrentProgram &copy)
{
    this->program = copy.program;
    this->labelList = copy.labelList;
    this->variableList = copy.variableList;
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

//bool GalilCurrentProgram::getVariableLine(const std::string &variable, int &line) const
//{
//    if(this->variableList.doesVariableExist(variable))
//        return false;
//    this->variableList.getVariableLine(variable,line);
//    return true;
//}

std::map<std::string, int> GalilCurrentProgram::getLablMap() const
{
    return this->labelList.getLabelMap();
}

std::map<std::string, double> GalilCurrentProgram::getVariableMap() const
{
    return this->variableList.getVariableMap();
}

std::string GalilCurrentProgram::getProgram() const
{
    return this->program;
}

void GalilCurrentProgram::writeJSONData(QJsonObject &json) const
{
    json["Program"] = QString::fromStdString(this->program);
}
