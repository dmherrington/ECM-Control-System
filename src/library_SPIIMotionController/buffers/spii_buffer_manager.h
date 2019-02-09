#ifndef SPII_BUFFER_MANAGER_H
#define SPII_BUFFER_MANAGER_H

#include <map>

#include "common/class_forward.h"

#include "buffer_data.h"

class BufferManager
{
public:
    BufferManager();

    ~BufferManager() = default;

private:
    unsigned int indexDBuffer;
    unsigned int maxBufferSize;

private:
    std::map<unsigned int, BufferData> m_ProgramBuffers;
};

#endif // SPII_BUFFER_MANAGER_H
