#include "status_variable_list.h"

Status_VariableList::Status_VariableList():
    AbstractStatus(StatusTypes::STATUS_VARIABLELIST)
{

}

Status_VariableList::Status_VariableList(const Status_VariableList &copy):
    AbstractStatus(StatusTypes::STATUS_VARIABLELIST)
{
    this->variableList = copy.variableList;
}

void Status_VariableList::setVariableList(const ProgramVariableList &list)
{
    this->variableList = list;
}

ProgramVariableList Status_VariableList::getVariableList() const
{
    return this->variableList;
}

