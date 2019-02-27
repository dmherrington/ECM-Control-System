#ifndef STATUS_POSITION_H
#define STATUS_POSITION_H

#include <map>

#include "ACSC.h"

#include "common/class_forward.h"
#include "common/axis_definitions.h"
#include "common/data_get_set_notifier.h"

#include "status/abstract_status.h"

ECM_CLASS_FORWARD(Status_PositionPerAxis);
class Status_PositionPerAxis : public AbstractStatus
{
public:
    Status_PositionPerAxis();

    Status_PositionPerAxis(const Status_PositionPerAxis &copy);

    void setAxis(const MotorAxis &axis);

    void setPosition(const double &pos);

    MotorAxis getAxis() const;

    int getPosition() const;

public:
    Status_PositionPerAxis& operator = (const Status_PositionPerAxis &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->currentAxis = rhs.currentAxis;
        this->position = rhs.position;
        return *this;
    }

    bool operator == (const Status_PositionPerAxis &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->currentAxis != rhs.currentAxis){
            return false;
        }
        if(this->position != rhs.position){
            return false;
        }
        return true;
    }

    bool operator != (const Status_PositionPerAxis &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis = MotorAxis::Z;
    int position = 0;

};

ECM_CLASS_FORWARD(Status_Position);
class Status_Position : public AbstractStatus
{
public:
    Status_Position();

    Status_Position(const Status_Position &copy);

    ~Status_Position();

    bool updatePositionStatus(const std::vector<Status_PositionPerAxis> &status);

    Status_PositionPerAxis* getAxisPosition(const MotorAxis &axis);

    DataGetSetNotifier<Status_PositionPerAxis>* getAxisPositionNotifier(const MotorAxis &axis);

public:
    Status_Position& operator = (const Status_Position &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->m_PositionStatus = rhs.m_PositionStatus;
        return *this;
    }

    bool operator == (const Status_Position &rhs) {
        if(!AbstractStatus::operator ==(rhs))
        {
            return false;
        }
        if(this->m_PositionStatus != rhs.m_PositionStatus){
            return false;
        }
        return true;
    }

    bool operator != (const Status_Position &rhs) {
        return !(*this == rhs);
    }

private:
    std::map<MotorAxis, DataGetSetNotifier<Status_PositionPerAxis>*> m_PositionStatus;
};

#endif // STATUS_POSITION_H
