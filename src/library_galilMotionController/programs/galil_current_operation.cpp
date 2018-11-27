#include "galil_current_operation.h"

GalilCurrentOperation::GalilCurrentOperation():
    GalilCurrentProgram()
{

}

GalilCurrentOperation::GalilCurrentOperation(const GalilCurrentOperation &copy):
    GalilCurrentProgram(copy)
{

}

void GalilCurrentOperation::setOperationName(const std::string &name)
{
    this->operationName = name;
}
void GalilCurrentOperation::setProfileName(const std::string &name)
{
    this->profileName = name;
}

std::string GalilCurrentOperation::getOperationName() const
{
    return this->operationName;
}
std::string GalilCurrentOperation::getProfileName() const
{
    return this->profileName;
}
