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
    virtual void writeToJSON(QJsonObject &saveObject);

    virtual void readFromJSON(const QJsonObject &loadObject);

public:
    void setDBufferIndex(const unsigned int &index);
    unsigned int getDBufferIndex() const;

    void setMaxBufferSize(const unsigned int &numBuffers);
    unsigned int getBufferSize() const;

    void updateBufferData(const unsigned int &bufferIndex, const BufferData &data);
    bool getBufferData(const unsigned int &bufferIndex, BufferData &data) const;

    std::map<unsigned int, BufferData> getBufferData() const;

    void statusBufferUpdate(const Status_BufferState &state);

private:
    void clearExistingBufferMap();

public:
    BufferManager& operator = (const BufferManager &rhs)
    {
        this->indexDBuffer = rhs.indexDBuffer;
        this->maxBufferSize = rhs.maxBufferSize;
        this->m_ProgramBuffers = rhs.m_ProgramBuffers;
        return *this;
    }

    bool operator == (const BufferManager &rhs) {
        if(this->indexDBuffer != rhs.indexDBuffer){
            return false;
        }
        if(this->maxBufferSize != rhs.maxBufferSize){
            return false;
        }
        if(this->m_ProgramBuffers != rhs.m_ProgramBuffers){
            return false;
        }
        return true;
    }

    bool operator != (const BufferManager &rhs) {
        return !(*this == rhs);
    }

protected:
    unsigned int indexDBuffer;
    unsigned int maxBufferSize;

protected:
    std::map<unsigned int, BufferData*> m_ProgramBuffers;


};

#endif // SPII_BUFFER_MANAGER_H
