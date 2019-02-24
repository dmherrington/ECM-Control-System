#include "buffer_data.h"

BufferData::BufferData()
{

}

void BufferData::setBufferIndex(const unsigned int &bufferIndex)
{
    this->index = bufferIndex;
}


unsigned int BufferData::getBufferIndex() const
{
    return this->index;
}

