#ifndef STATE_ABSTRACT_SPII_H
#define STATE_ABSTRACT_SPII_H

#include <iostream>
#include <thread>

#include "common/hsm.h"
#include "common/class_forward.h"
#include "common/commands/command_components.h"

#include "state_types.h"
#include "../spii_state_interface.h"
#include "../requests/request_components.h"

namespace ECM {
namespace SPII {

class AbstractStateSPII : public hsm::StateWithOwner<SPIIStateInterface>
{
public:
    AbstractStateSPII():
        currentCommand(nullptr)
    {

    }

    AbstractStateSPII(const AbstractStateSPII &copy);

    /**
      */
    virtual ~AbstractStateSPII() = default;

    virtual void OnExit();
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
    virtual AbstractStateSPII* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractStateSPII** state) const = 0;

public:
    virtual void handleCommand(const AbstractCommandPtr command) = 0;

    virtual SPIIState getCurrentState() const;

    virtual SPIIState getDesiredState() const;

protected:
    bool checkEStop() const;

    void clearCommand();
protected:
    AbstractCommandPtr currentCommand;

    SPIIState currentState;
    SPIIState desiredState;
};

} //end of namespace SPII
} //end of namespace ECM

#endif // STATE_ABSTRACT_SPII_H
