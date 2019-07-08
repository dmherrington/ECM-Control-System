#include "status_label_list.h"

Status_LabelList::Status_LabelList():
    AbstractStatus(StatusTypes::STATUS_LABELLIST)
{

}

Status_LabelList::Status_LabelList(const Status_LabelList &copy):
    AbstractStatus(StatusTypes::STATUS_LABELLIST)
{
    this->labelList = copy.labelList;
}

void Status_LabelList::setLabelList(const ProgramLabelList &list)
{
    this->labelList = list;
}

ProgramLabelList Status_LabelList::getLabelList() const
{
    return this->labelList;
}

