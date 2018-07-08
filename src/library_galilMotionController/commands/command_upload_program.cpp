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

void CommandUploadProgram::setProgram(const ProgramGeneric &desiredProgram)
{
    this->program = desiredProgram;
}

ProgramGeneric CommandUploadProgram::getProgram() const
{
    return this->program;
}
