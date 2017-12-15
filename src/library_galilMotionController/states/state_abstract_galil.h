#ifndef STATE_ABSTRACT_GALIL_H
#define STATE_ABSTRACT_GALIL_H

#include <iostream>
#include "common/class_forward.h"

#include "settings/galil_settings.h"
#include "commands/abstract_command.h"

#include "states/state_types.h"
#include "states/hsm.h"

namespace ECM{
namespace Galil {

class AbstractStateGalil : public hsm::State
{
public:
    AbstractStateGalil() = default;

    AbstractStateGalil(const GalilSettings &settings);

    AbstractStateGalil(const AbstractStateGalil &copy);

    /**
      */
    virtual ~AbstractStateGalil() = default;

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
    virtual AbstractStateGalil* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractStateGalil** state) const = 0;

public:
    virtual void handleCommand(const AbstractCommand* command) = 0;

    virtual ECMState getCurrentState() const;

    virtual ECMState getDesiredState() const;

protected:
    GalilSettings mSettings;

    ECMState currentState;
    ECMState desiredState;
};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_ABSTRACT_GALIL_H
