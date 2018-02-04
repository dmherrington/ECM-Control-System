#include "acquire_command_srate.h"

namespace rigol {
namespace commands{

AcquireCommand_Srate::AcquireCommand_Srate():
    AbstractAcquireCommand(data::AcquireType::ACQUIRE_SRAT)
{

}

AcquireCommand_Srate::AcquireCommand_Srate(const AcquireCommand_Srate &copy):
    AbstractAcquireCommand(copy)
{

}

AbstractAcquireCommand* AcquireCommand_Srate::getClone() const
{
    return (new AcquireCommand_Srate(*this));
}

void AcquireCommand_Srate::getClone(AbstractAcquireCommand** state) const
{
    *state = new AcquireCommand_Srate(*this);
}

} //end of namespace commands
} //end of namespace rigol
