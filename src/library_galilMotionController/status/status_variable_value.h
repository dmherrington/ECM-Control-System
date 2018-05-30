#ifndef STATUS_VARIABLE_VALUE_H
#define STATUS_VARIABLE_VALUE_H

#include "common/class_forward.h"
#include "common/tuple_profile_variable_string.h"

#include "data/motion_profile_variable_state.h"
#include "status/abstract_status.h"

ECM_CLASS_FORWARD(Status_VariableValue);

class Status_VariableValue : public AbstractStatus
{
public:
    Status_VariableValue();

    Status_VariableValue(const common::TupleECMData &description, const double &value);

    Status_VariableValue(const Status_VariableValue &copy);

    std::string getVariableName() const;

    bool setVariableValue(const double &value);

    double getVariableValue() const;

    common_data::MotionProfileVariableState getVariableState() const;
public:
    Status_VariableValue& operator = (const Status_VariableValue &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->variableValue = rhs.variableValue;
        return *this;
    }

    bool operator == (const Status_VariableValue &rhs) {
        if(!AbstractStatus::operator ==(rhs)){
            return false;
        }
        if(this->variableValue != rhs.variableValue){
            return false;
        }
        return true;
    }

    bool operator != (const Status_VariableValue &rhs) {
        return !(*this == rhs);
    }

private:
    double variableValue;
};

#endif // STATUS_VARIABLE_VALUE_H
