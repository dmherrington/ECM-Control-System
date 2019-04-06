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

void BufferManager::writeToJSON(QJsonObject &bufferDataObject)
{
    QJsonArray bufferDataArray;

    bufferDataObject["indexDBuffer"] = (int)this->getDBufferIndex();
    bufferDataObject["maxBufferSize"] = (int)this->maxBufferSize;

    std::map<unsigned int, BufferData*>::iterator it;
    for (it = m_ProgramBuffers.begin(); it!=m_ProgramBuffers.end(); ++it)
    {
            BufferData* currentData = it->second;
            currentData->writeToJSON(bufferDataArray);
    }

    bufferDataObject["BufferDataArray"] = bufferDataArray;
}

void BufferManager::readFromJSON(const QJsonObject &bufferDataObject)
{
    clearExistingBufferMap();

    this->setDBufferIndex(bufferDataObject["indexDBuffer"].toInt());
    this->setMaxBufferSize(bufferDataObject["maxBufferSize"].toInt());

    QJsonArray bufferDataArray = bufferDataObject["BufferDataArray"].toArray();

    if(!bufferDataArray.isEmpty())
    {
        for (size_t index = 0; index < bufferDataArray.size(); index++) {
            m_ProgramBuffers.at(index)->readFromJSON(bufferDataArray.at(index).toObject());
        }
    }
}


void BufferManager::setDBufferIndex(const unsigned int &index)
{
    m_ProgramBuffers.at(index)->setIsDBuffer(true);
}

unsigned int BufferManager::getDBufferIndex() const
{
    return this->indexDBuffer;
}

void BufferManager::setMaxBufferSize(const unsigned int &numBuffers)
{
    clearExistingBufferMap();

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

bool BufferManager::getBufferData(const unsigned int &bufferIndex, BufferData &data)
{

}

void BufferManager::clearExistingBufferMap()
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

