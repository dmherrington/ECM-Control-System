#include "acquire_command_type.h"


namespace commands_Rigol{

AcquireCommand_Type::AcquireCommand_Type():
    AbstractAcquireCommand(data_Rigol::AcquireType::ACQUIRE_TYPE)
{

}

AcquireCommand_Type::AcquireCommand_Type(const AcquireCommand_Type &copy):
    AbstractAcquireCommand(copy)
{
    this->option = copy.option;
}

AbstractRigolCommand* AcquireCommand_Type::getClone() const
{
    return (new AcquireCommand_Type(*this));
}

void AcquireCommand_Type::getClone(AbstractRigolCommand** state) const
{
    *state = new AcquireCommand_Type(*this);
}

void AcquireCommand_Type::setAcquisitionMode(const data_Rigol::AcquireCommand_TypeMode &mode)
{
    this->option = mode;
}

data_Rigol::AcquireCommand_TypeMode AcquireCommand_Type::getAcquisitionMode() const
{
    return this->option;
}

std::string AcquireCommand_Type::getAcquireCommandString() const
{
    std::string str = "";
    str+=data_Rigol::AcquireTypeModeToString(this->option);
    return str;
}


} //end of namespace commands

