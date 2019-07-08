#include "command_compile_buffer.h"

CommandCompileBuffer::CommandCompileBuffer():
    AbstractCommand(CommandType::COMPILE_BUFFER)
{

}

CommandCompileBuffer::CommandCompileBuffer(const CommandCompileBuffer &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* CommandCompileBuffer::getClone() const
{
    return (new CommandCompileBuffer(*this));
}

void CommandCompileBuffer::getClone(AbstractCommand** state) const
{
    *state = new CommandCompileBuffer(*this);
}

void CommandCompileBuffer::addCompileBuffer(const unsigned int &bufferIndex)
{
    this->compileBuffers.push_back(bufferIndex);
    this->compileAll = false;
}
std::vector<unsigned int> CommandCompileBuffer::getCompileBuffers() const
{
    return this->compileBuffers;
}

bool CommandCompileBuffer::shouldCompileAllBuffers() const
{
    return this->compileAll;
}

std::string CommandCompileBuffer::getCommandString() const
{
    std::string str;
    return str;
}
