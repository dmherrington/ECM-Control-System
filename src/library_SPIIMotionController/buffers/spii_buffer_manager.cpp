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

    dataObject["indexDBuffer"] = (int)this->getDBufferIndex();
    dataObject["maxBufferSize"] = (int)this->maxBufferSize;
    QJsonArray MCBufferArray;

    std::map<unsigned int, BufferData*>::iterator it;
    for (it = m_ProgramBuffers.begin(); it!=m_ProgramBuffers.end(); ++it)
    {
        QJsonObject bufferObject;
        BufferData* currentData = it->second;
        currentData->writeToJSON(bufferObject);
        MCBufferArray.append(bufferObject);
    }
    dataObject["bufferDataArray"] = MCBufferArray;

    MCDataArray.append(dataObject);
    saveObject["MotionControlData"] = MCDataArray;
}

void BufferManager::readFromJSON(const QJsonObject &loadObject)
{
    clearExistingBufferMap();

    QJsonArray MCDataArray = loadObject["MotionControlData"].toArray();
    QJsonObject MCObject = MCDataArray[0].toObject();

    this->setMaxBufferSize(MCObject["maxBufferSize"].toInt());
    if(MCObject["indexDBuffer"].toInt() > maxBufferSize - 1)
    {
        this->setDBufferIndex(maxBufferSize - 1);
    }
    else
        this->setDBufferIndex(MCObject["indexDBuffer"].toInt());

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

    maxBufferSize = numBuffers;
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

std::map<unsigned int, BufferData> BufferManager::getBufferData() const
{
    std::map<unsigned int, BufferData> rtnData;
    std::map<unsigned int, BufferData*>::const_iterator it = m_ProgramBuffers.cbegin();

    for(;it!=m_ProgramBuffers.cend();++it)
    {
        rtnData.insert(std::pair<unsigned int, BufferData>(it->first,*it->second));
    }
    return rtnData;
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
        currentData->setBufferCurrent(true);
        currentData->setBufferCompiled(false);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::COMPILED:
    {
        currentData->setProgramString(state.getProgramString());
        currentData->setBufferCurrent(true);
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

