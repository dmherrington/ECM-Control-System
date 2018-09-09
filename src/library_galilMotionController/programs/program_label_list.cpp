#include "program_label_list.h"

ProgramLabelList::ProgramLabelList()
{

}

ProgramLabelList::ProgramLabelList(const ProgramLabelList &copy)
{
    this->labelMap = copy.labelMap;
}

bool ProgramLabelList::doesLabelExist(const std::string &name) const
{
    if(this->labelMap.count(name) > 0)
        return true;
    return false;
}

void ProgramLabelList::addLabel(const std::string &name, const int &lineNumber)
{
    this->labelMap[name] = lineNumber;
}

void ProgramLabelList::removeLabel(const std::string &name)
{
    if(this->labelMap.count(name) > 0)
        this->labelMap.erase(name);
}

void ProgramLabelList::updateLabel(const std::string &name, const int &lineNumber)
{
    if(this->labelMap.count(name) > 0)
        this->labelMap.at(name) = lineNumber;
    else
        this->labelMap[name] = lineNumber;
}

bool ProgramLabelList::getLabelLine(const std::string &name, int &lineNumber) const
{
    if(this->labelMap.count(name) > 0)
    {
        lineNumber = this->labelMap.at(name);
        return true;
    }
    return false;
}

void ProgramLabelList::clearLabelList()
{
    labelMap.clear();
}

size_t ProgramLabelList::sizeOfLabelList() const
{
    return this->labelMap.size();
}

std::map<std::string,int> ProgramLabelList::getLabelMap() const
{
    return this->labelMap;
}
