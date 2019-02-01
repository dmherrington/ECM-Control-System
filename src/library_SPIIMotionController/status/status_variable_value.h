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

    Status_VariableValue(const double &value);

    Status_VariableValue(const Status_VariableValue &copy);

    void setProgramName(const std::string &program);
    void setProfileName(const std::string &profile);
    void setVariableName(const std::string &variable);

    std::string getProgramName() const;
    std::string getProfileName() const;
    std::string getVariableName() const;

    void setVariableValue(const double &value);
    void setVariableUnit(const std::string &unit);

    double getVariableValue() const;
    std::string getVariableUnit() const;

    common_data::MotionProfileVariableState getVariableState() const;
public:
    Status_VariableValue& operator = (const Status_VariableValue &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->programName = rhs.programName;
        this->profileName = rhs.profileName;
        this->variableName = rhs.variableName;
        this->variableValue = rhs.variableValue;
        this->variableUnit = rhs.variableUnit;
        return *this;
    }

    bool operator == (const Status_VariableValue &rhs) {
        if(!AbstractStatus::operator ==(rhs)){
            return false;
        }
        if(this->programName != rhs.programName){
            return false;
        }
        if(this->profileName != rhs.profileName){
            return false;
        }
        if(this->variableName != rhs.variableName){
            return false;
        }
        if(this->variableValue != rhs.variableValue){
            return false;
        }
        if(this->variableUnit != rhs.variableUnit){
            return false;
        }
        return true;
    }

    bool operator != (const Status_VariableValue &rhs) {
        return !(*this == rhs);
    }

private:
    std::string programName = "";
    std::string profileName = "";
    std::string variableName = "";

    double variableValue = 0.0;
    std::string variableUnit = "unitless";
};

#endif // STATUS_VARIABLE_VALUE_H
