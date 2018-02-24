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
    this->queryNumber = copy.queryNumber;
}

AbstractRigolCommand* AcquireCommand_Average::getClone() const
{
    return (new AcquireCommand_Average(*this));
}

void AcquireCommand_Average::getClone(AbstractRigolCommand** state) const
{
    *state = new AcquireCommand_Average(*this);
}

void AcquireCommand_Average::setSampleNumbers(const unsigned int &samples)
{
    /* The following checks that the sample number is a power of 2 before
     * making the assignment. Additionally, this check ensures that the
     * value is within the required range of the argument.
     */

    unsigned int powerOfTwo = 1;
    while (powerOfTwo < samples && powerOfTwo < 1024)
        powerOfTwo *= 2;

    this->queryNumber = powerOfTwo;
}

unsigned int AcquireCommand_Average::getSampleNumber() const
{
    return this->queryNumber;
}

std::string AcquireCommand_Average::getAcquireCommandString() const
{
    std::string str = "";
    str+=std::to_string(this->queryNumber);
    return str;
}

} //end of namespace commands
} //end of namespace rigol
