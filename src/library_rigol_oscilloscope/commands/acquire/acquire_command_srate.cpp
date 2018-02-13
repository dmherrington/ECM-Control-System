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
    this->sampleRate = copy.sampleRate;
}

AbstractRigolCommand* AcquireCommand_Srate::getClone() const
{
    return (new AcquireCommand_Srate(*this));
}

void AcquireCommand_Srate::getClone(AbstractRigolCommand** state) const
{
    *state = new AcquireCommand_Srate(*this);
}

std::string AcquireCommand_Srate::getCommandKey() const
{
    std::string str = "";
    str+=data::AcquireTypeToString(this->getAcquisitionType());
    str+=getSuffixCommand();
    return str;
}

} //end of namespace commands
} //end of namespace rigol
