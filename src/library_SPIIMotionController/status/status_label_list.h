#ifndef STATUS_LABEL_LIST_H
#define STATUS_LABEL_LIST_H

#include <map>

#include "common/class_forward.h"
#include "status/abstract_status.h"
#include "../programs/program_label_list.h"

ECM_CLASS_FORWARD(Status_LabelList);

class Status_LabelList : public AbstractStatus
{
public:
    Status_LabelList();

    Status_LabelList(const Status_LabelList &copy);

    void setLabelList(const ProgramLabelList &list);

    ProgramLabelList getLabelList() const;

public:
    Status_LabelList& operator = (const Status_LabelList &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->labelList = rhs.labelList;
        return *this;
    }

    bool operator == (const Status_LabelList &rhs) {
        if(!AbstractStatus::operator ==(rhs)){
            return false;
        }
        if(this->labelList != rhs.labelList){
            return false;
        }
        return true;
    }

    bool operator != (const Status_LabelList &rhs) {
        return !(*this == rhs);
    }

private:
    ProgramLabelList labelList;
};


#endif // STATUS_LABEL_LIST_H
