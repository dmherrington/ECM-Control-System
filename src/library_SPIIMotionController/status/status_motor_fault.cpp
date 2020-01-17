#include "status_motor_fault.h"

Status_MotorAxisFault::Status_MotorAxisFault():
    AbstractStatus(StatusTypes::STATUS_MOTOR_FAULTS_PER_AXIS)
{

}

Status_MotorAxisFault::Status_MotorAxisFault(const Status_MotorAxisFault &copy):
    AbstractStatus(copy)
{
    currentAxis = copy.currentAxis;
    faultValue = copy.faultValue;
    errorString = copy.errorString;
}

void Status_MotorAxisFault::assembleFaultString()
{
    errorString = "";
    if(isHardwareEmergencyStop())
        errorString+="|Hardware ESTOP";
    if(isRightLimit())
        errorString+="|Right Limit";
    if(isLeftLimit())
        errorString+="|Left Limit";
    if(isNetworkError())
        errorString+="|Network Error";
    if(isOverheated())
        errorString+="|Overheated";
    if(isSWRightLimit())
        errorString+="|SW Right Limit";
    if(isSWLeftLimit())
        errorString+="|SW Left Limit";
    if(isPrimaryEncoderConnected())
        errorString+="|Primary Encoder Connection";
    if(isSecondaryEncoderConnected())
        errorString+="|Secondary Encoder Connection";
    if(isDriverAlarm())
        errorString+="|Driver Alarm";
    if(isPrimaryEncoderError())
        errorString+="|Primary Encoder Error";
    if(isSecondaryEncoderError())
        errorString+="|Secondary Encoder Error";
    if(isPositionError())
        errorString+="|Position Error";
    if(isCriticalPositionError())
        errorString+="|Critical Position Error";
    if(isVelocityLimit())
        errorString+="|Velocity Limit";
    if(isAccelerationLimit())
        errorString+="|Acceleration Limit";
    if(isCurrentLimit())
        errorString+="|Current Limit";
    if(isServoProcessorAlarm())
        errorString+="|Servo Processor Failure";
}

void Status_MotorAxisFault::setAxis(const MotorAxis &axis)
{
    currentAxis = axis;
}

MotorAxis Status_MotorAxisFault::getAxis() const
{
    return this->currentAxis;
}

bool Status_MotorAxisFault::updateMotorFaultState(const unsigned int &value)
{
    if(this->faultValue != value)
    {
        this->faultValue = value;
        assembleFaultString();
        return true;
    }
    return false;
}

bool Status_MotorAxisFault::doesMotorFaultExist() const
{
    if(faultValue != 0)
        return true;
    return false;
}

bool Status_MotorAxisFault::isHardwareEmergencyStop() const
{
    return faultValue & ACSC_SAFETY_ES;
}
bool Status_MotorAxisFault::isRightLimit() const
{
    return faultValue & ACSC_SAFETY_RL;
}
bool Status_MotorAxisFault::isLeftLimit() const
{
    return faultValue &ACSC_SAFETY_LL;
}
bool Status_MotorAxisFault::isNetworkError() const
{
    return faultValue & ACSC_SAFETY_NETWORK;
}
bool Status_MotorAxisFault::isOverheated() const
{
    return faultValue & ACSC_SAFETY_HOT;
}
bool Status_MotorAxisFault::isSWRightLimit() const
{
    return faultValue & ACSC_SAFETY_SRL;
}
bool Status_MotorAxisFault::isSWLeftLimit() const
{
    return faultValue & ACSC_SAFETY_SLL;
}
bool Status_MotorAxisFault::isPrimaryEncoderConnected() const
{
    return faultValue & ACSC_SAFETY_ENCNC;
}
bool Status_MotorAxisFault::isSecondaryEncoderConnected() const
{
    return faultValue & ACSC_SAFETY_ENC2NC;
}
bool Status_MotorAxisFault::isDriverAlarm() const
{
    return faultValue & ACSC_SAFETY_DRIVE;
}
bool Status_MotorAxisFault::isPrimaryEncoderError() const
{
    return faultValue & ACSC_SAFETY_ENC;
}
bool Status_MotorAxisFault::isSecondaryEncoderError() const
{
    return faultValue & ACSC_SAFETY_ENC2;
}
bool Status_MotorAxisFault::isPositionError() const
{
    return faultValue & ACSC_SAFETY_PE;
}
bool Status_MotorAxisFault::isCriticalPositionError() const
{
    return faultValue & ACSC_SAFETY_CPE;
}
bool Status_MotorAxisFault::isVelocityLimit() const
{
    return faultValue & ACSC_SAFETY_VL;
}
bool Status_MotorAxisFault::isAccelerationLimit() const
{
    return faultValue & ACSC_SAFETY_AL;
}
bool Status_MotorAxisFault::isCurrentLimit() const
{
    return faultValue & ACSC_SAFETY_CL;
}
bool Status_MotorAxisFault::isServoProcessorAlarm() const
{
    return faultValue & ACSC_SAFETY_SP;
}

void Status_MotorAxisFault::getErrorDetails(unsigned int &code, std::string &errorString) const
{
    code = this->faultValue;
    errorString = this->errorString;
}

std::string Status_MotorAxisFault::getErrorString() const
{
    return this->errorString;
}

unsigned int Status_MotorAxisFault::getErrorCode() const
{
    return this->faultValue;
}


Status_MotorFault::Status_MotorFault():
    AbstractStatus(StatusTypes::STATUS_ALL_AXIS)
{

}

Status_MotorFault::Status_MotorFault(const Status_MotorFault &copy):
    AbstractStatus(copy)
{
    this->m_MotorAxisFault = copy.m_MotorAxisFault;
}

Status_MotorFault::~Status_MotorFault()
{

}

bool Status_MotorFault::updateMotorAxisStatus(const std::vector<Status_MotorAxisFault> &status)
{
    bool axisChanged = false;
    for(size_t index = 0; index < status.size(); index++)
    {
        Status_MotorAxisFault currentStatus = status.at(index);

        std::map<MotorAxis, DataGetSetNotifier<Status_MotorAxisFault>*>::const_iterator iter = m_MotorAxisFault.find(currentStatus.getAxis());

        if(iter != m_MotorAxisFault.end()) //item is already in the map and therefore we just need to update it
        {
            if(m_MotorAxisFault.at(currentStatus.getAxis())->set(currentStatus))
            {
                if(!axisChanged)
                    axisChanged = true;
            }
        }
        else {
            DataGetSetNotifier<Status_MotorAxisFault>* newStatus = new DataGetSetNotifier<Status_MotorAxisFault>();
            newStatus->set(currentStatus);
            //insert it into the map
            m_MotorAxisFault.insert(std::pair<MotorAxis, DataGetSetNotifier<Status_MotorAxisFault>*>(currentStatus.getAxis(), newStatus));
            axisChanged = true;
        }
    }
    return axisChanged;
}

Status_MotorAxisFault* Status_MotorFault::getMotorAxisStatus(const MotorAxis &axis)
{

}
