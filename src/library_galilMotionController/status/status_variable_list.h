#ifndef STATUS_VARIABLE_LIST_H
#define STATUS_VARIABLE_LIST_H

#include <map>

#include "common/class_forward.h"
#include "status/abstract_status.h"
#include "../programs/program_variable_list.h"

ECM_CLASS_FORWARD(Status_VariableList);

class Status_VariableList : public AbstractStatus
{
public:
    Status_VariableList();

    Status_VariableList(const Status_VariableList &copy);

    void setVariableList(const ProgramVariableList &list);

    ProgramVariableList getVariableList() const;

public:
    Status_VariableList& operator = (const Status_VariableList &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->variableList = rhs.variableList;
        return *this;
    }

    bool operator == (const Status_VariableList &rhs) {
        if(!AbstractStatus::operator ==(rhs)){
            return false;
        }
        if(this->variableList != rhs.variableList){
            return false;
        }
        return true;
    }

    bool operator != (const Status_VariableList &rhs) {
        return !(*this == rhs);
    }

private:
    ProgramVariableList variableList;
};

#endif // STATUS_VARIABLE_LIST_H
