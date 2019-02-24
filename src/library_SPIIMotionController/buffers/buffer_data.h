#ifndef BUFFER_DATA_H
#define BUFFER_DATA_H

#include <string>

#include "buffer_variable_values.h"

class BufferData
{
public:
    BufferData();

    ~BufferData();

public:
    void setBufferIndex(const unsigned int &bufferIndex);

public:
    unsigned int getBufferIndex() const;

public:
    BufferVariableValues m_BufferVariables;

private:
    unsigned int index;

    std::string bufferProfile;

};

#endif // BUFFER_DATA_H
