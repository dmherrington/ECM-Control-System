#include "spii_buffer_manager.h"

BufferManager::BufferManager()
{

}

void BufferManager::setDBufferIndex(const unsigned int &index)
{

}
unsigned int BufferManager::getDBufferIndex() const
{

}

void BufferManager::setMaxBufferSize(const unsigned int &numBuffers)
{

}
unsigned int BufferManager::getBufferSize() const
{

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
