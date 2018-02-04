#include "acquire_command_type.h"

namespace rigol {
namespace commands{

AcquireCommand_Type::AcquireCommand_Type():
    AbstractAcquireCommand(data::AcquireType::ACQUIRE_TYPE)
{

}

AcquireCommand_Type::AcquireCommand_Type(const AcquireCommand_Type &copy):
    AbstractAcquireCommand(copy)
{

}

AbstractAcquireCommand* AcquireCommand_Type::getClone() const
{
    return (new AcquireCommand_Type(*this));
}

void AcquireCommand_Type::getClone(AbstractAcquireCommand** state) const
{
    *state = new AcquireCommand_Type(*this);
}

} //end of namespace commands
} //end of namespace rigol
