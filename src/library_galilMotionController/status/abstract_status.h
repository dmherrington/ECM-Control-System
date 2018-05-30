#ifndef GALIL_ABSTRACT_STATUS_H
#define GALIL_ABSTRACT_STATUS_H

#include <string.h>
#include "common/class_forward.h"
#include "common/environment_time.h"

#include "common/tuple_ecm_data.h"

#include "status/status_types.h"

ECM_CLASS_FORWARD(AbstractStatus);
class AbstractStatus
{
public:
    AbstractStatus(const StatusTypes &type);

    AbstractStatus(const StatusTypes &type, const common::TupleECMData &tuple);

    AbstractStatus(const AbstractStatus &copy);

    void setStatusType(const StatusTypes &type);
    StatusTypes getStatusType() const;

    void setTime(const common::EnvironmentTime &time);
    common::EnvironmentTime getTime() const;

    virtual void setTupleDescription(const common::TupleECMData &tuple);

    virtual common::TupleECMData getTupleDescription() const;

    template <class T>
    const T* getTupleDescriptionAs() const
    {
        return static_cast<const T*>(descriptor.getData());
    }

public:
    /**
     *
     */
    template <class T>
    const T *as() const
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<const T *>(this);
    }

    /**
     *
     */
    template <class T>
    T *as()
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<T *>(this);
    }
public:
    AbstractStatus& operator = (const AbstractStatus &rhs)
    {
        this->statusType = rhs.statusType;
        this->descriptor = rhs.descriptor;
        this->latestUpdate = rhs.latestUpdate;
        return *this;
    }

    bool operator == (const AbstractStatus &rhs) {
        if(this->statusType != rhs.statusType){
            return false;
        }
        if(this->descriptor != rhs.descriptor){
            return false;
        }
        return true;
    }

    bool operator != (const AbstractStatus &rhs) {
        return !(*this == rhs);
    }

protected:
    StatusTypes statusType;
    common::TupleECMData descriptor;
    common::EnvironmentTime latestUpdate;
};

#endif // GALIL_ABSTRACT_STATUS_H
