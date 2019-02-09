#ifndef BUFFER_DATA_H
#define BUFFER_DATA_H

class BufferData
{
public:
    BufferData();

    ~BufferData();

public:
    unsigned int getBufferIndex() const;

private:
    unsigned int index;
};

#endif // BUFFER_DATA_H
