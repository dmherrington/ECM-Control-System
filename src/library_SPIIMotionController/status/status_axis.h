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
    bool isMotorMoving() const;

public:
    Status_PerAxis& operator = (const Status_PerAxis &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->currentAxis = rhs.currentAxis;
        this->moving = rhs.moving;
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
        if(this->moving != rhs.moving){
            return false;
        }
        return true;
    }

    bool operator != (const Status_PerAxis &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis = MotorAxis::Z;
    bool moving = false;
};


ECM_CLASS_FORWARD(Status_Motor);
class Status_Axis : public AbstractStatus
{
public:
    Status_Axis();

    Status_Axis(const Status_Axis &copy);

    ~Status_Axis();

    void updateAxisStatus(const Status_Axis &status);

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
