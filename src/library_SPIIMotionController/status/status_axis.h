#ifndef STATUS_AXIS_H
#define STATUS_AXIS_H

#include "ACSC.h"

#include "common/class_forward.h"
#include "common/axis_definitions.h"
#include "common/data_get_set_notifier.h"

#include "abstract_status.h"

namespace SPII{

ECM_CLASS_FORWARD(Status_PerAxis);
class Status_PerAxis : public AbstractStatus
{
public:
    Status_PerAxis();

    Status_PerAxis(const Status_PerAxis &copy);

    void setAxis(const MotorAxis &axis);
    MotorAxis getAxis() const;

    void setMotorMoving(const bool &moving);
    bool isAxisMoving() const;

    void updateAxisStatus(const int &value);

public:
    Status_PerAxis& operator = (const Status_PerAxis &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->currentAxis = rhs.currentAxis;
        this->axisLeading = rhs.axisLeading;
        this->axisDataCollection = rhs.axisDataCollection;
        this->axisPEG = rhs.axisPEG;
        this->axisMoving = rhs.axisMoving;
        this->axisAccelerating = rhs.axisAccelerating;
        this->axisSegmentedMotion = rhs.axisSegmentedMotion;
        this->axisVelLock = rhs.axisVelLock;
        this->axisPosLock = rhs.axisPosLock;
        return *this;
    }

    bool operator == (const Status_PerAxis &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->currentAxis != rhs.currentAxis){
            return false;
        }
        if(this->axisLeading != rhs.axisLeading){
            return false;
        }
        if(this->axisDataCollection != rhs.axisDataCollection){
            return false;
        }
        if(this->axisPEG != rhs.axisPEG){
            return false;
        }
        if(this->axisMoving != rhs.axisMoving){
            return false;
        }
        if(this->axisAccelerating != rhs.axisAccelerating){
            return false;
        }
        if(this->axisSegmentedMotion != rhs.axisSegmentedMotion){
            return false;
        }
        if(this->axisVelLock != rhs.axisVelLock){
            return false;
        }
        if(this->axisPosLock != rhs.axisPosLock){
            return false;
        }
        return true;
    }

    bool operator != (const Status_PerAxis &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis = MotorAxis::Z;
    bool axisLeading = false;
    bool axisDataCollection = false;
    bool axisPEG = false;
    bool axisMoving = false;
    bool axisAccelerating = false;
    bool axisSegmentedMotion = false;
    bool axisVelLock = false;
    bool axisPosLock = false;

};


ECM_CLASS_FORWARD(Status_Motor);
class Status_Axis : public AbstractStatus
{
public:
    Status_Axis();

    Status_Axis(const Status_Axis &copy);

    ~Status_Axis();

    bool updateAxisStatus(const std::vector<Status_PerAxis> &status);

    Status_Axis* getAxisStatus(const MotorAxis &axis);

public:
    Status_Axis& operator = (const Status_Axis &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->m_AxisStatus = rhs.m_AxisStatus;
        return *this;
    }

    bool operator == (const Status_Axis &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->m_AxisStatus != rhs.m_AxisStatus){
            return false;
        }
        return true;
    }

    bool operator != (const Status_Axis &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<MotorAxis, DataGetSetNotifier<Status_PerAxis>*> m_AxisStatus;
};


}//end of namespace SPII

#endif // STATUS_AXIS_H
