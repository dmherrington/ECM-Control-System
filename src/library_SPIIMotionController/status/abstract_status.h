#ifndef SPII_ABSTRACT_STATUS_H
#define SPII_ABSTRACT_STATUS_H

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

    AbstractStatus(const AbstractStatus &copy);

    virtual ~AbstractStatus() = default;


    //!
    //! \brief setStatusType
    //! \param type
    //!
    void setStatusType(const StatusTypes &type);

    void setStatusValidity(const bool &valid);

    //!
    //! \brief getStatusType
    //! \return
    //!
    StatusTypes getStatusType() const;

    //!
    //! \brief setTime
    //! \param time
    //!
    void setTime(const common::EnvironmentTime &time);

    //!
    //! \brief getTime
    //! \return
    //!
    common::EnvironmentTime getTime() const;

    virtual bool isStatusValid() const;


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
        this->latestUpdate = rhs.latestUpdate;
        this->validStatus = rhs.validStatus;

        return *this;
    }

    bool operator == (const AbstractStatus &rhs) {
        if(this->statusType != rhs.statusType){
            return false;
        }
        if(this->validStatus != rhs.validStatus){
            return false;
        }
        return true;
    }

    bool operator != (const AbstractStatus &rhs) {
        return !(*this == rhs);
    }

protected:
    StatusTypes statusType;
    common::EnvironmentTime latestUpdate;
    bool validStatus = true;
};

#endif // SPII_ABSTRACT_STATUS_H
