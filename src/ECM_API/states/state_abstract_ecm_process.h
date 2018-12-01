#ifndef STATE_ABSTRACT_ECM_PROCESS_H
#define STATE_ABSTRACT_ECM_PROCESS_H

#include <iostream>
#include <thread>

#include "common/class_forward.h"
#include "common/hsm.h"

#include "../ecm_api.h"
#include "../commands/ecm_command_profile_collection.h"

#include "state_ecm_types.h"


namespace ECM{
namespace API {

ECM_CLASS_FORWARD(AbstractStateECMProcess);

class AbstractStateECMProcess : public hsm::StateWithOwner<ECM_API>
{

public:
    AbstractStateECMProcess() = default;

    AbstractStateECMProcess(const AbstractStateECMProcess &copy);

    /**
      */
    virtual ~AbstractStateECMProcess() = default;

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
    virtual AbstractStateECMProcess* getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(AbstractStateECMProcess** state) const = 0;

public:
    virtual void OnExit();

    virtual void OnEnter();

public:

    virtual void initializeFromCollection(const ECMCommand_ProfileCollection &collection);

    virtual void uploadConfiguration(const ECMCommand_ProfileConfiguration &config);

public:
    virtual ECMState getCurrentState() const;

    virtual ECMState getDesiredState() const;

protected:
    bool checkEStop() const;
    void clearCommand();

protected:
    ECMCommand_ProfileCollection m_ProfileCollection;

    ECMState currentState;
    ECMState desiredState;
};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ABSTRACT_ECM_PROCESS_H
