#ifndef STATE_TEST_H
#define STATE_TEST_H

#include "common/class_forward.h"
#include "common/hsm.h"

#include "../ecm_api.h"

#include "state_abstract_ecm_process.h"

namespace ECM{
namespace API {

ECM_CLASS_FORWARD(state_test);

class state_test : public AbstractStateECMProcess
{
public:
    state_test();

public:
    AbstractStateECMProcess* getClone() const override;

    void getClone(AbstractStateECMProcess** state) const override;

public:
    void OnExit() override;

    void OnEnter() override;

public:
    hsm::Transition GetTransition() override;

public:
    void Update() override;

};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_TEST_H
