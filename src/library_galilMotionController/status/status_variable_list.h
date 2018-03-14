#ifndef STATUS_VARIABLE_LIST_H
#define STATUS_VARIABLE_LIST_H

#include <map>

#include "common/class_forward.h"
#include "status/abstract_status.h"
#include "status/status_variable_value.h"

ECM_CLASS_FORWARD(Status_VariableList);

class Status_VariableList : public AbstractStatus
{
public:
    Status_VariableList();

    Status_VariableList(const Status_VariableList &copy);

    void addVariable(const Status_VariableValue &var);

    void removeVariable(const std::string &name);

    bool updateVariable(const Status_VariableValue &var);

    bool getVariable(const std::string &name, Status_VariableValue &status);

    bool getVariableValue(const std::string &name, double &value);

public:
    Status_VariableList& operator = (const Status_VariableList &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->variableMap = rhs.variableMap;
        return *this;
    }

    bool operator == (const Status_VariableList &rhs) {
        if(!AbstractStatus::operator ==(rhs)){
            return false;
        }
//        if(this->variableMap != rhs.variableMap){
//            return false;
//        }
        return true;
    }

    bool operator != (const Status_VariableList &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<std::string,Status_VariableValue> variableMap;
};

#endif // STATUS_VARIABLE_LIST_H
