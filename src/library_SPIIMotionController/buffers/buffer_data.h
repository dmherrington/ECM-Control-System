#ifndef BUFFER_DATA_H
#define BUFFER_DATA_H

#include <string>

#include "buffer_variable_values.h"

class BufferData
{
public:
    BufferData(const unsigned int &bufferIndex = 0, const bool &dBuffer = false);

    ~BufferData();

public:
    void setBufferIndex(const unsigned int &bufferIndex);

    void updateLineCount(const unsigned int &count);

    void setBufferCurrent(const bool &current);

    void setBufferCompiled(const bool &compiled);

    void setIsDBuffer(const bool &value);

public:
    bool isBufferCurrent() const;

    bool isBufferCompiled() const;

    bool isDBuffer() const;

public:
    unsigned int getBufferIndex() const;

public:
    BufferVariableValues m_BufferVariables;

private:
    unsigned int index = 0;

    bool dBuffer = false;

    unsigned int lineCount = 0;

    std::string bufferProfile = "";

    bool isCurrent = false;

    bool isCompiled = false;
};

#endif // BUFFER_DATA_H
