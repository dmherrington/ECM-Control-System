#ifndef ABSTRACT_RIGOL_STATUS_H
#define ABSTRACT_RIGOL_STATUS_H

#include <string.h>

#include "library_rigol_oscilloscope_global.h"

#include "common/class_forward.h"
#include "common/environment_time.h"

#include "data/type_available_commands.h"

namespace rigol {
namespace commands {

using namespace data;
ECM_CLASS_FORWARD(AbstractRigolStatus);

class AbstractRigolStatus
{
public:
    AbstractRigolStatus(const CommandTypes &type);

    AbstractRigolStatus(const AbstractRigolStatus &copy);

    void setCommandType(const CommandTypes &type);
    CommandTypes getCommandType() const;

    void setTime(const EnvironmentTime &time);
    EnvironmentTime getTime() const;

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
    AbstractRigolStatus& operator = (const AbstractRigolStatus &rhs)
    {
        this->commandType = rhs.commandType;
        //this->latestUpdate = rhs.latestUpdate;
        return *this;
    }

    bool operator == (const AbstractRigolStatus &rhs) {
        if(this->commandType != rhs.commandType){
            return false;
        }
        return true;
    }

    bool operator != (const AbstractRigolStatus &rhs) {
        return !(*this == rhs);
    }

private:
    CommandTypes commandType;
    EnvironmentTime latestUpdate;
};

} //end of namespace commands
} //end of namespace rigol

#endif // ABSTRACT_RIGOL_STATUS_H
