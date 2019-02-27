#include "status_buffer_state.h"

Status_BufferState::Status_BufferState(const ENUM_BUFFERSTATE &value):
    AbstractStatus(StatusTypes::STATUS_BUFFERSTATE)
{
    this->state = value;
}

Status_BufferState::Status_BufferState(const Status_BufferState &copy):
    AbstractStatus(copy)
{
    this->state = copy.state;
    this->programString = copy.programString;
    this->bufferIndex = copy.bufferIndex;
    this->errorString = copy.programString;
    this->errorLine = copy.errorLine;
}

void Status_BufferState::setBufferState(const ENUM_BUFFERSTATE &value)
{
    this->state = value;
}

Status_BufferState::ENUM_BUFFERSTATE Status_BufferState::getBufferStatus() const
{
    return this->state;
}

void Status_BufferState::setProgramString(const std::string &text)
{
    this->programString = text;
}

std::string Status_BufferState::getProgramString() const
{
    return this->programString;
}


void Status_BufferState::setBufferIndex(const unsigned int &index)
{
    this->bufferIndex = index;
}
unsigned int Status_BufferState::getBufferIndex() const
{
    return this->bufferIndex;
}


void Status_BufferState::setErrorString(const std::string &text)
{
    this->errorString = text;
}
std::string Status_BufferState::getErrorString() const
{
    return this->errorString;
}


void Status_BufferState::setErrorLine(const unsigned int &line)
{
    this->errorLine = line;
}
unsigned int Status_BufferState::getErrorLine() const
{
    return this->errorLine;
}
