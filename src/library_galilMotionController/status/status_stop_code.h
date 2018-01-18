#ifndef STATUS_STOP_CODE_H
#define STATUS_STOP_CODE_H

#include <map>

#include <axis_definitions.h>
#include "status/abstract_status.h"


class Status_StopCode : public AbstractStatus
{
public:
    Status_StopCode();

    Status_StopCode(const MotorAxis &axis, const int &code);

    Status_StopCode(const Status_StopCode &copy);

    void setAxis(const MotorAxis &axis);
    void setStopCode(const int &code);

    MotorAxis getAxis() const;
    int getCode() const;

public:
    void operator = (const Status_StopCode &rhs)
    {
        this->currentAxis = rhs.currentAxis;
        this->stopCode = rhs.stopCode;
    }

    bool operator == (const Status_StopCode &rhs) {

        if(this->currentAxis != rhs.currentAxis){
            return false;
        }
        if(this->stopCode != rhs.stopCode){
            return false;
        }
        return true;
    }

    bool operator != (const Status_StopCode &rhs) {
        return !(*this == rhs);
    }

private:
    MotorAxis currentAxis;
    int stopCode = 0;
};

#endif // STATUS_STOP_CODE_H
