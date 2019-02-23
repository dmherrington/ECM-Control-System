#ifndef BUFFER_DATA_H
#define BUFFER_DATA_H

#include <string>

class BufferData
{
public:
    BufferData();

    ~BufferData();

public:
    unsigned int getBufferIndex() const;

private:
    unsigned int index;

    std::string bufferProfile;

};

#endif // BUFFER_DATA_H
