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

void BufferManager::writeToJSON(QJsonObject &saveObject)
{
    QJsonArray MCDataArray;
    QJsonObject dataObject;

    QJsonArray bufferDataArray;

    dataObject["indexDBuffer"] = (int)this->getDBufferIndex();
    dataObject["maxBufferSize"] = (int)this->maxBufferSize;

    std::map<unsigned int, BufferData*>::iterator it;
    for (it = m_ProgramBuffers.begin(); it!=m_ProgramBuffers.end(); ++it)
    {
            BufferData* currentData = it->second;
            currentData->writeToJSON(bufferDataArray);
    }
    MCDataArray.append(dataObject);
    saveObject["MotionControlData"] = MCDataArray;
}

void BufferManager::readFromJSON(const QJsonObject &loadObject)
{
    clearExistingBufferMap();

    QJsonArray MCDataArray = loadObject["MotionControlData"].toArray();
    QJsonObject MCObject = MCDataArray[0].toObject();

    this->setDBufferIndex(MCObject["indexDBuffer"].toInt());
    this->setMaxBufferSize(MCObject["maxBufferSize"].toInt());

    QJsonArray bufferDataArray = MCObject["bufferDataArray"].toArray();

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
    std::map<unsigned int, BufferData*>::iterator it;
    it = m_ProgramBuffers.find(bufferIndex);
    if(it != m_ProgramBuffers.end())
    {
        BufferData* currentData = it->second;
        currentData->updateBufferData(data);
    }
}

bool BufferManager::getBufferData(const unsigned int &bufferIndex, BufferData &data) const
{
    std::map<unsigned int, BufferData*>::const_iterator it;
    it = m_ProgramBuffers.find(bufferIndex);
    if(it != m_ProgramBuffers.end())
    {
        data = *it->second;
        return true;
    }
    else
        return false;
}

void BufferManager::clearExistingBufferMap()
{
    std::map<unsigned int, BufferData*>::iterator it;
    for (it = m_ProgramBuffers.begin(); it != m_ProgramBuffers.end();)
    {
        delete it->second;
        m_ProgramBuffers.erase(it++);
    }
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

