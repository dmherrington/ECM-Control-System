#include "buffer_data.h"

BufferData::BufferData(const unsigned int &bufferIndex, const bool &dBuffer)
{
    setBufferIndex(bufferIndex);
    setIsDBuffer(dBuffer);
}

void BufferData::setBufferIndex(const unsigned int &bufferIndex)
{
    this->index = bufferIndex;
}


void BufferData::updateLineCount(const unsigned int &count)
{

}

void BufferData::setBufferCurrent(const bool &current)
{

}

void BufferData::setBufferCompiled(const bool &compiled)
{

}

void BufferData::setIsDBuffer(const bool &value)
{
    this->dBuffer = value;
}

bool BufferData::isBufferCurrent() const
{

}

bool BufferData::isBufferCompiled() const
{

}

bool BufferData::isDBuffer() const
{
    return this->dBuffer;
}

unsigned int BufferData::getBufferIndex() const
{
    return this->index;
}

