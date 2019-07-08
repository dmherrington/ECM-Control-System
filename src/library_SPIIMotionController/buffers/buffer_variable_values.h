#ifndef BUFFER_VARIABLE_VALUES_H
#define BUFFER_VARIABLE_VALUES_H

#include <map>

#include "common/class_forward.h"
#include "common/data_get_set_notifier.h"
#include "common/operation/operation_variable_list.h"

#include "../status/abstract_status.h"
#include "../status/status_variable_value.h"

ECM_CLASS_FORWARD(BufferVariableValues);

class BufferVariableValues {

public:
    BufferVariableValues();

    BufferVariableValues(const BufferVariableValues &copy);

    ~BufferVariableValues();

    void fromVariableList(const Operation_VariableList &list);

    void addVariable(const Status_VariableValue &var);

    bool addVariableNotifier(const std::string &name, void* obj, const std::function<void()> func);

    void removeVariable(const std::string &name);

    bool removeVariableNotifier(const std::string &name, void* obj);

    bool updateVariable(const Status_VariableValue &var);

    bool getVariable(const std::string &name, Status_VariableValue &status);

    bool getVariableValue(const std::string &name, double &value);

    void clearVariableValueList();

public:
    BufferVariableValues& operator = (const BufferVariableValues &rhs)
    {
        this->variableMap = rhs.variableMap;
        return *this;
    }

    bool operator == (const BufferVariableValues &rhs) {
        if(this->variableMap != rhs.variableMap){
            return false;
        }
        return true;
    }

    bool operator != (const BufferVariableValues &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<std::string, DataGetSetNotifier<Status_VariableValue>*> variableMap;

};

#endif // BUFFER_VARIABLE_VALUES_H
