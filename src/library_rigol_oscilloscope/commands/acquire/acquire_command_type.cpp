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

void AcquireCommand_Type::setAcquisitionMode(const data::AcquireCommand_TypeMode &mode)
{
    this->option = mode;
}

data::AcquireCommand_TypeMode AcquireCommand_Type::getAcquisitionMode() const
{
    return this->option;
}

std::string AcquireCommand_Type::getCommandKey() const
{
    std::string str = "";
    str+=data::AcquireTypeToString(this->getAcquisitionType());
    if(this->isReadorWrite() == data::ReadWriteType::WRITE)
    {
        str+=" ";
        str+=data::AcquireTypeModeToString(this->option);
    }
    str+=getSuffixCommand();
    return str;
}


} //end of namespace commands
} //end of namespace rigol
