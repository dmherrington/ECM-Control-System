#ifndef STATE_ABSTRACT_GALIL_H
#define STATE_ABSTRACT_GALIL_H

#include <iostream>
#include <thread>

#include "common/class_forward.h"
#include "common/hsm.h"

#include "library_galilMotionController/settings/galil_settings.h"
#include "library_galilMotionController/commands/command_components.h"

#include "library_galilMotionController/states/state_types.h"
#include "library_galilMotionController/galil_state_interface.h"

namespace ECM{
namespace Galil {

class AbstractStateGalil : public hsm::StateWithOwner<GalilStateInterface>
{
public:
    AbstractStateGalil():
        currentCommand(nullptr)
    {

    }

    AbstractStateGalil(const GalilSettings &settings);

    AbstractStateGalil(const AbstractStateGalil &copy);

    /**
      */
    virtual ~AbstractStateGalil() = default;

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
    virtual AbstractStateGalil* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractStateGalil** state) const = 0;

public:
    virtual void handleCommand(const AbstractCommandPtr command) = 0;

    virtual GalilState getCurrentState() const;

    virtual GalilState getDesiredState() const;

protected:
    bool checkEStop() const;
    void clearCommand();
protected:
    GalilSettings mSettings;
    AbstractCommandPtr currentCommand;

    GalilState currentState;
    GalilState desiredState;
};

} //end of namespace Galil
} //end of namespace ECM

#endif // STATE_ABSTRACT_GALIL_H
