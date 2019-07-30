#ifndef PLC_ABSTRACT_REQUEST_H
#define PLC_ABSTRACT_REQUEST_H

#include <QStringList>

#include <stdio.h>
#include <string.h>

#include "common/class_forward.h"
#include "common/environment_time.h"
#include "common/tuple_ecm_data.h"

#include "../data_registers/abstract_register.h"

/**
\* @file  abstract_request.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*
\*
\*/


namespace PLC {

ECM_CLASS_FORWARD(AbstractRequest);

class AbstractRequest
{
public:
    AbstractRequest();


    AbstractRequest(const AbstractRequest &copy);

    virtual ~AbstractRequest() = default;

public:
    virtual void setTupleDescription(const common::TupleECMData &tuple);

    virtual common::TupleECMData getTupleDescription() const;

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

    /**
     * @brief getClone
     * @return
     */
    virtual AbstractRequest* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractRequest** state) const = 0;

public:
    common::EnvironmentTime getTime() const
    {
        return this->latestUpdate;
    }

    void updateTime()
    {
        this->latestUpdate.CurrentTime(common::Devices::SYSTEMCLOCK,this->latestUpdate);
    }

protected:
    common::TupleECMData descriptor;
    common::EnvironmentTime latestUpdate;

    registers_PLC::AbstractPLCRegisterPtr currentRegisterRequest;

};

} //end of namespace PLC

#endif // PLC_ABSTRACT_REQUEST_H
