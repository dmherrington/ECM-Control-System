#include "command_upload_program.h"

CommandUploadProgram::CommandUploadProgram():
    AbstractCommand(CommandType::UPLOAD_PROGRAM)
{

}

CommandUploadProgram::CommandUploadProgram(const CommandUploadProgram &copy):
    AbstractCommand(copy)
{
    this->program = copy.program;
}

AbstractCommand* CommandUploadProgram::getClone() const
{
    return (new CommandUploadProgram(*this));
}

void CommandUploadProgram::getClone(AbstractCommand** state) const
{
    *state = new CommandUploadProgram(*this);
}

std::string CommandUploadProgram::getCommandString() const
{
    std::string str;
    return str;
}

void CommandUploadProgram::setCurrentScript(const std::string &text)
{
    this->program.setProgram(text);
}

void CommandUploadProgram::setCurrentProgram(const GalilCurrentProgram &desiredProgram)
{
    this->program = desiredProgram;
}

GalilCurrentProgram CommandUploadProgram::getCurrentProgram() const
{
    return this->program;
}
