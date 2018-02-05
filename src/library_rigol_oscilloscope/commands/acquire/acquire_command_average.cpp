#include "acquire_command_average.h"

namespace rigol {
namespace commands{

AcquireCommand_Average::AcquireCommand_Average():
    AbstractAcquireCommand(data::AcquireType::ACQUIRE_AVERAGE)
{

}

AcquireCommand_Average::AcquireCommand_Average(const AcquireCommand_Average &copy):
    AbstractAcquireCommand(copy)
{

}

AbstractRigolCommand* AcquireCommand_Average::getClone() const
{
    return (new AcquireCommand_Average(*this));
}

void AcquireCommand_Average::getClone(AbstractRigolCommand** state) const
{
    *state = new AcquireCommand_Average(*this);
}

} //end of namespace commands
} //end of namespace rigol
