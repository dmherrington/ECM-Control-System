#include "state_abstract_spii.h"

namespace ECM{
namespace SPII {

AbstractStateSPII::AbstractStateSPII(const AbstractStateSPII &copy)
{
    this->currentState = copy.currentState;
    this->desiredState = copy.desiredState;
}

void AbstractStateSPII::OnExit()
{

}

SPIIState AbstractStateSPII::getCurrentState() const
{
    return currentState;
}

SPIIState AbstractStateSPII::getDesiredState() const
{
    return desiredState;
}

void AbstractStateSPII::clearCommand()
{
//Since the current command is now a smart pointer, we do not have to directly manage this
//    if(this->currentCommand)
//    {
//        delete currentCommand;
//        currentCommand = nullptr;
//    }
}

bool AbstractStateSPII::checkEStop() const
{
    //Check to see if the estop has been cleared
    return Owner().isEStopEngaged();
}

} //end of namespace Galil
} //end of namespace ECM
