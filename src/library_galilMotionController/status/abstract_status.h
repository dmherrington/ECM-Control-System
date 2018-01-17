#ifndef ABSTRACT_STATUS_H
#define ABSTRACT_STATUS_H

#include <string.h>
#include "common/class_forward.h"
#include "requests/request_types.h"
#include "common/environment_time.h"

#include "gclib.h"

ECM_CLASS_FORWARD(AbstractStatus);
class AbstractStatus
{
public:
    AbstractStatus(const RequestTypes &type);

    AbstractStatus(const AbstractStatus &copy);

    void setRequestType(const RequestTypes &type);
    RequestTypes getRequestType() const;

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
        this->requestType = rhs.requestType;
        return *this;
    }

    bool operator == (const AbstractStatus &rhs) {
        if(this->requestType != rhs.requestType){
            return false;
        }
        return true;
    }

    bool operator != (const AbstractStatus &rhs) {
        return !(*this == rhs);
    }

private:
    RequestTypes requestType;
};

#endif // ABSTRACT_STATUS_H
