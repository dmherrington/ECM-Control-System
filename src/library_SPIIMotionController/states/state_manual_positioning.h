#ifndef STATE_MANUAL_POSITIONING_H
#define STATE_MANUAL_POSITIONING_H

#include <map>

#include "states/state_abstract_spii.h"

namespace ECM{
namespace SPII {

ECM_CLASS_FORWARD(State_ManualPositioning);

class State_MotionStop;
class State_EStop;
class State_Ready;

class State_ManualPositioning : public AbstractStateSPII
{
public:
    State_ManualPositioning();

    void OnExit() override;

public:
    AbstractStateSPII* getClone() const override;

    void getClone(AbstractStateSPII** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void handleCommand(const AbstractCommandPtr command) override;

    void Update() override;

    void OnEnter() override;

    void OnEnter(const AbstractCommandPtr command);

private:
    void populateMotionComplete();

    bool allMotionComplete() const;

    void setupSubscribers();


private:
    std::map<MotorAxis,double> targetPosition;
    std::map<MotorAxis,bool> motionComplete;

};

} //end of namespace SPII
} //end of namespace ECM

#endif // STATE_MANUAL_POSITIONING_H
