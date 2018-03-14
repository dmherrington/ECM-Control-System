#ifndef STATUS_VARIABLE_VALUE_H
#define STATUS_VARIABLE_VALUE_H

#include "common/class_forward.h"
#include "common/data_get_set_notifier.h"

#include "status/abstract_status.h"

ECM_CLASS_FORWARD(Status_VariableValue);

class Status_VariableValue : public AbstractStatus
{
public:
    Status_VariableValue();

    Status_VariableValue(const std::string &name, const double &value);

    Status_VariableValue(const Status_VariableValue &copy);

    void setVariableName(const std::string &name);
    bool setVariableValue(const double &value);

    std::string getVariableName() const;
    double getVariableValue() const;

public:
    Status_VariableValue& operator = (const Status_VariableValue &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->variableName = rhs.variableName;
        this->variableValue.set(rhs.variableValue.get());
        return *this;
    }

    bool operator == (const Status_VariableValue &rhs) {
        if(!AbstractStatus::operator ==(rhs)){
            return false;
        }
        if(this->variableName != rhs.variableName){
            return false;
        }
        if(this->variableValue.get() != rhs.variableValue.get()){
            return false;
        }
        return true;
    }

    bool operator != (const Status_VariableValue &rhs) {
        return !(*this == rhs);
    }

private:
    std::string variableName;
    DataGetSetNotifier<double> variableValue;
};

#endif // STATUS_VARIABLE_VALUE_H
