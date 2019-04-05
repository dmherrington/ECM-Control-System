#include "spii_buffer_manager.h"

BufferManager::BufferManager()
{

}

BufferManager::BufferManager(const BufferManager &copy)
{
    this->indexDBuffer = copy.indexDBuffer;
    this->maxBufferSize = copy.maxBufferSize;
    this->m_ProgramBuffers = copy.m_ProgramBuffers;
}

void BufferManager::setDBufferIndex(const unsigned int &index)
{
    m_ProgramBuffers.at(index)->setIsDBuffer(true);
}

unsigned int BufferManager::getDBufferIndex() const
{

}

void BufferManager::setMaxBufferSize(const unsigned int &numBuffers)
{
    m_ProgramBuffers.clear();

    for(size_t index = 0; index < numBuffers; index++)
    {
        BufferData* newData = new BufferData(index);
        m_ProgramBuffers.insert(std::pair<unsigned int, BufferData*>(index,newData));
    }
}
unsigned int BufferManager::getBufferSize() const
{
    return m_ProgramBuffers.size();
}

void BufferManager::updateBufferData(const unsigned int &bufferIndex, const BufferData &data)
{

}
void BufferManager::getBufferData(const unsigned int &bufferIndex, BufferData &data)
{

}

void BufferManager::statusBufferUpdate(const Status_BufferState &state)
{
    unsigned int bufferIndex = state.getBufferIndex();
    BufferData* currentData = m_ProgramBuffers.at(bufferIndex);

    switch (state.getBufferStatus()) {
    case Status_BufferState::ENUM_BUFFERSTATE::CLEARED:
    {
        currentData->markBufferAsCleared();
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::COMPILED:
    {
        currentData->setBufferCompiled(true);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::CURRENT:
    {
        currentData->setProgramString(state.getProgramString());
        currentData->setBufferCurrent(true);
        currentData->setBufferCompiled(false);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::ERROR_COMPILING:
    {
        currentData->setBufferCompiled(false);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::ERROR_UPLOAD:
    {

        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::UNKNOWN:
    {

        break;
    }
    default:
        break;
    }
}

