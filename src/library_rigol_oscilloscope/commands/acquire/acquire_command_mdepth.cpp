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
    this->memDepth = copy.memDepth;
}

AbstractRigolCommand* AcquireCommand_Mdepth::getClone() const
{
    return (new AcquireCommand_Mdepth(*this));
}

void AcquireCommand_Mdepth::getClone(AbstractRigolCommand** state) const
{
    *state = new AcquireCommand_Mdepth(*this);
}

void AcquireCommand_Mdepth::setSingleChannelDepth(const data::DepthSingleChannel &depth)
{
    this->memDepth = data::DepthSingleChannelToString(depth);
}

void AcquireCommand_Mdepth::setDualChannelDepth(const data::DepthDualChannel &depth)
{
    this->memDepth = data::DepthDualChannelToString(depth);
}

void AcquireCommand_Mdepth::setQuadratureChannelDepth(const data::DepthQuadratureChannel &depth)
{
    this->memDepth = data::DepthQuadratureChannelToString(depth);
}

std::string AcquireCommand_Mdepth::getChannelDepth() const
{
    return this->memDepth;
}

std::string AcquireCommand_Mdepth::getAcquireCommandString() const
{
    std::string str = "";
    str+=memDepth;
    return str;
}

} //end of namespace commands
} //end of namespace rigol
