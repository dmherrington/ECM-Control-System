#include "command_download_program.h"

CommandDownloadProgram::CommandDownloadProgram():
    AbstractCommand(CommandType::DOWNLOAD_PROGRAM)
{

}

CommandDownloadProgram::CommandDownloadProgram(const CommandDownloadProgram &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* CommandDownloadProgram::getClone() const
{
    return (new CommandDownloadProgram(*this));
}

void CommandDownloadProgram::getClone(AbstractCommand** state) const
{
    *state = new CommandDownloadProgram(*this);
}

std::string CommandDownloadProgram::getCommandString() const
{
    std::string str;
    return str;
}
