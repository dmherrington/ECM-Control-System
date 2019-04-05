#ifndef SPII_BUFFER_MANAGER_H
#define SPII_BUFFER_MANAGER_H

#include <map>

#include "common/class_forward.h"

#include "../status/status_buffer_state.h"

#include "buffer_data.h"

#include "common/operation/operation_label_list.h"
#include "common/operation/operation_variable_list.h"

class BufferManager
{
public:
    BufferManager();

    BufferManager(const BufferManager &copy);

    ~BufferManager() = default;

public:
    void setDBufferIndex(const unsigned int &index);
    unsigned int getDBufferIndex() const;

    void setMaxBufferSize(const unsigned int &numBuffers);
    unsigned int getBufferSize() const;

    void updateBufferData(const unsigned int &bufferIndex, const BufferData &data);
    void getBufferData(const unsigned int &bufferIndex, BufferData &data);

    void statusBufferUpdate(const Status_BufferState &state);

protected:
    unsigned int indexDBuffer;
    unsigned int maxBufferSize;

protected:
    std::map<unsigned int, BufferData*> m_ProgramBuffers;


};

#endif // SPII_BUFFER_MANAGER_H
