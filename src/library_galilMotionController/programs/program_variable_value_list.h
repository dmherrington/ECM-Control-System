#ifndef PROGRAM_VARIABLE_VALUE_LIST_H
#define PROGRAM_VARIABLE_VALUE_LIST_H

#include <map>

#include "common/class_forward.h"
#include "common/data_get_set_notifier.h"

#include "../status/abstract_status.h"
#include "../status/status_variable_value.h"

ECM_CLASS_FORWARD(ProgramVariableValueList);

class ProgramVariableValueList
{
public:
    ProgramVariableValueList();

    ProgramVariableValueList(const ProgramVariableValueList &copy);

    ~ProgramVariableValueList();

    void addVariable(const Status_VariableValue &var);

    bool addVariableNotifier(const std::string &name, void* obj, const std::function<void()> func);

    void removeVariable(const std::string &name);

    bool removeVariableNotifier(const std::string &name, void* obj);

    bool updateVariable(const Status_VariableValue &var);

    bool getVariable(const std::string &name, Status_VariableValue &status);

    bool getVariableValue(const std::string &name, double &value);

    void clearVariableValueList();

public:
    ProgramVariableValueList& operator = (const ProgramVariableValueList &rhs)
    {
        this->variableMap = rhs.variableMap;
        return *this;
    }

    bool operator == (const ProgramVariableValueList &rhs) {
//        if(this->variableMap != rhs.variableMap){
//            return false;
//        }
        return true;
    }

    bool operator != (const ProgramVariableValueList &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<std::string,DataGetSetNotifier<Status_VariableValue>*> variableMap;
};

#endif // PROGRAM_VARIABLE_VALUE_LIST_H
