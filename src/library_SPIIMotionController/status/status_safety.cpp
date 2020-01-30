#include "status_safety.h"

Status_AxisSafety::Status_AxisSafety():
    AbstractStatus(StatusTypes::STATUS_SAFETY_FAULTS_PER_AXIS)
{

}

Status_AxisSafety::Status_AxisSafety(const Status_AxisSafety &copy):
    AbstractStatus(copy)
{
    safetyValue = copy.safetyValue;
    currentAxis = copy.currentAxis;
    errorCode = copy.errorCode;
    errorString = copy.errorString;

}

void Status_AxisSafety::setAxis(const MotorAxis &axis)
{
    currentAxis = axis;
}

MotorAxis Status_AxisSafety::getAxis() const
{
    return this->currentAxis;
}

void Status_AxisSafety::setErrorCode(const unsigned int &code, const std::string &errorString)
{
    this->errorCode = code;
    this->errorString = errorString;
}

void Status_AxisSafety::getErrorDetails(unsigned int &code, std::string &errorString) const
{
    code = this->errorCode;
    errorString = this->errorString;
}

std::string Status_AxisSafety::getErrorString() const
{
    return this->errorString;
}

unsigned int Status_AxisSafety::getErrorCode() const
{
    return this->errorCode;
}

bool Status_AxisSafety::updateSafetyState(const unsigned int &value)
{
    if(this->safetyValue != value)
    {
        this->safetyValue = value;
        return true;
    }
    return false;
}

bool Status_AxisSafety::doesSafetyFaultExist() const
{
    if(safetyValue != 0)
        return true;
    return false;
}

bool Status_AxisSafety::isRightLimit() const
{
    return safetyValue & ACSC_SAFETY_RL;
}
bool Status_AxisSafety::isLeftLimit() const
{
    return safetyValue &ACSC_SAFETY_LL;
}
bool Status_AxisSafety::isRightLimit2() const
{
    return false; //this does not exist per the manual
    //return safetyValue & ACSC_SAFETY_SRL;
}
bool Status_AxisSafety::isLeftLimit2() const
{
    return false; //this does not exist per the manual
    //return safetyValue &ACSC_SAFETY_SLL;
}
bool Status_AxisSafety::isOverheated() const
{
    return safetyValue & ACSC_SAFETY_HOT;
}
bool Status_AxisSafety::isDriverAlarm() const
{
    return safetyValue & ACSC_SAFETY_DRIVE;
}
bool Status_AxisSafety::isHardwareEmergencyStop() const
{
    return safetyValue & ACSC_SAFETY_ES;
}


Status_Safety::Status_Safety():
    AbstractStatus(StatusTypes::STATUS_ALL_AXIS)
{

}

Status_Safety::Status_Safety(const Status_Safety &copy):
    AbstractStatus(copy)
{
    this->m_AxisSafety = copy.m_AxisSafety;
}

Status_Safety::~Status_Safety()
{

}

bool Status_Safety::updateAxisStatus(const std::vector<Status_AxisSafety> &status)
{
    bool axisChanged = false;
    for(size_t index = 0; index < status.size(); index++)
    {
        Status_AxisSafety currentStatus = status.at(index);

        std::map<MotorAxis, DataGetSetNotifier<Status_AxisSafety>*>::const_iterator iter = m_AxisSafety.find(currentStatus.getAxis());

        if(iter != m_AxisSafety.end()) //item is already in the map and therefore we just need to update it
        {
            if(m_AxisSafety.at(currentStatus.getAxis())->set(currentStatus))
            {
                if(!axisChanged)
                    axisChanged = true;
            }
        }
        else {
            DataGetSetNotifier<Status_AxisSafety>* newStatus = new DataGetSetNotifier<Status_AxisSafety>();
            newStatus->set(currentStatus);
            //insert it into the map
            m_AxisSafety.insert(std::pair<MotorAxis, DataGetSetNotifier<Status_AxisSafety>*>(currentStatus.getAxis(), newStatus));
            axisChanged = true;
        }
    }
    return axisChanged;
}

Status_AxisSafety* Status_Safety::getAxisStatus(const MotorAxis &axis)
{

}

