#include "acquire_command_mdepth.h"

namespace rigol {
namespace commands{

AcquireCommand_Mdepth::AcquireCommand_Mdepth():
    AbstractAcquireCommand(data::AcquireType::ACQUIRE_MDEPTH)
{

}

AcquireCommand_Mdepth::AcquireCommand_Mdepth(const AcquireCommand_Mdepth &copy):
    AbstractAcquireCommand(copy)
{

}

AbstractAcquireCommand* AcquireCommand_Mdepth::getClone() const
{
    return (new AcquireCommand_Mdepth(*this));
}

void AcquireCommand_Mdepth::getClone(AbstractAcquireCommand** state) const
{
    *state = new AcquireCommand_Mdepth(*this);
}

} //end of namespace commands
} //end of namespace rigol
