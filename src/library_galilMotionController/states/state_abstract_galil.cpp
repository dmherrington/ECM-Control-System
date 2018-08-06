#include "state_abstract_galil.h"

namespace ECM{
namespace Galil {

AbstractStateGalil::AbstractStateGalil(const GalilSettings &settings):
    mSettings(settings)
{

}

AbstractStateGalil::AbstractStateGalil(const AbstractStateGalil &copy)
{
    this->currentState = copy.currentState;
    this->desiredState = copy.desiredState;
}

void AbstractStateGalil::OnExit()
{

}

GalilState AbstractStateGalil::getCurrentState() const
{
    return currentState;
}

GalilState AbstractStateGalil::getDesiredState() const
{
    return desiredState;
}

void AbstractStateGalil::clearCommand()
{
//Since the current command is now a smart pointer, we do not have to directly manage this
//    if(this->currentCommand)
//    {
//        delete currentCommand;
//        currentCommand = nullptr;
//    }
}

bool AbstractStateGalil::checkEStop() const
{
    //Check to see if the estop has been cleared
    return Owner().isEStopEngaged();
}

} //end of namespace Galil
} //end of namespace ECM
