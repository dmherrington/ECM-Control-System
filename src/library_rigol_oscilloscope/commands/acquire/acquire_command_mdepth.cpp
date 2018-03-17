#include "acquire_command_mdepth.h"


namespace commands_Rigol{

AcquireCommand_Mdepth::AcquireCommand_Mdepth():
    AbstractAcquireCommand(data_Rigol::AcquireType::ACQUIRE_MDEPTH)
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

void AcquireCommand_Mdepth::setSingleChannelDepth(const data_Rigol::DepthSingleChannel &depth)
{
    this->memDepth = data_Rigol::DepthSingleChannelToString(depth);
}

void AcquireCommand_Mdepth::setDualChannelDepth(const data_Rigol::DepthDualChannel &depth)
{
    this->memDepth = data_Rigol::DepthDualChannelToString(depth);
}

void AcquireCommand_Mdepth::setQuadratureChannelDepth(const data_Rigol::DepthQuadratureChannel &depth)
{
    this->memDepth = data_Rigol::DepthQuadratureChannelToString(depth);
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

