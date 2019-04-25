#include "buffer_data.h"

BufferData::BufferData(const unsigned int &bufferIndex, const bool &dBuffer)
{
    setBufferIndex(bufferIndex);
    setIsDBuffer(dBuffer);
    setBufferName("Buffer #" + std::to_string(bufferIndex));
}

BufferData::BufferData(const BufferData &copy)
{
    this->updateBufferData(copy);
}

bool BufferData::doesBufferAccuratelyReflect(const BufferData &data)
{
    if(this->bufferIndex != data.bufferIndex){
        return false;
    }
    if(this->programText != data.programText){
        return false;
    }
    return true;
}

void BufferData::updateBufferData(const BufferData &data)
{
    this->m_BufferVariables = data.m_BufferVariables;
    this->bufferIndex = data.bufferIndex;
    this->bufferName = data.bufferName;
    this->lockBufferName = data.lockBufferName;
    this->dBuffer = data.dBuffer;
    this->lineCount = data.lineCount;
    this->bufferProfile = data.bufferProfile;
    this->isCurrent = data.isCurrent;
    this->isCompiled = data.isCompiled;
    this->programText = data.programText;
}

void BufferData::writeToText(QString &stringObject)
{
    if(programText.empty())
        return;

    if(dBuffer)
        stringObject += "#A \r\n";
    else
        stringObject += "#" + QString::number(bufferIndex) + "\r\n";

    stringObject += QString::fromStdString(programText);
}

void BufferData::writeToJSON(QJsonObject &jsonObject)
{
    jsonObject["bufferIndex"] = (int)this->getBufferIndex();
    jsonObject["dBuffer"] = this->isDBuffer();

    jsonObject["bufferName"] = QString::fromStdString(this->getBufferName());
    jsonObject["programText"] = QString::fromStdString(this->getProgramString());
}

void BufferData::readFromJSON(const QJsonObject &bufferDataObject)
{
    this->setBufferIndex(bufferDataObject["bufferIndex"].toInt());
    this->setIsDBuffer(bufferDataObject["dBuffer"].toBool());

    this->setBufferName(bufferDataObject["bufferName"].toString().toStdString());
    this->setProgramString(bufferDataObject["programText"].toString().toStdString());
}

std::string BufferData::setBufferName(const std::string &value)
{
    std::string currentBufferName = "";
    if(isDBuffer())
    {
        lockBufferName = true;
        bufferName = "DBuffer";
    }
    else
    {
        if(!lockBufferName)
        {
            bufferName = value;
        }
    }

    return this->bufferName;
}

std::string BufferData::getBufferName() const
{
    return this->bufferName;
}

void BufferData::setProgramString(const std::string &program)
{
    this->programText = program;
}

std::string BufferData::getProgramString() const
{
    return this->programText;
}

void BufferData::setBufferIndex(const unsigned int &bufferIndex)
{
    this->bufferIndex = bufferIndex;
}


void BufferData::updateLineCount(const unsigned int &count)
{
    this->lineCount = count;
}

void BufferData::setBufferCurrent(const bool &current)
{
    this->isCurrent = current;
}

void BufferData::setBufferCompiled(const bool &compiled)
{
    this->isCompiled = compiled;
}

void BufferData::setIsDBuffer(const bool &value)
{
    this->dBuffer = value;
}

bool BufferData::isBufferCurrent() const
{
    return this->isCurrent;
}

bool BufferData::isBufferCompiled() const
{
    return this->isCompiled;
}

bool BufferData::isDBuffer() const
{
    return this->dBuffer;
}

unsigned int BufferData::getBufferIndex() const
{
    return this->bufferIndex;
}

void BufferData::markBufferAsCleared()
{
    setProgramString("");
    setBufferCurrent(true);
    setBufferCompiled(true);
}
