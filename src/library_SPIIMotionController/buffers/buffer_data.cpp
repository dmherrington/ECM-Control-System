#include "buffer_data.h"

BufferData::BufferData(const unsigned int &bufferIndex, const bool &dBuffer)
{
    setBufferIndex(bufferIndex);
    setIsDBuffer(dBuffer);
}

void BufferData::writeToJSON(QJsonArray &bufferDataArray)
{
    QJsonObject segmentObject;

    segmentObject["bufferIndex"] = (int)this->getBufferIndex();
    segmentObject["dBuffer"] = this->isDBuffer();
    segmentObject["bufferName"] = QString::fromStdString(this->getBufferName());
    segmentObject["bufferText"] = QString::fromStdString(this->getProgramString());

    bufferDataArray.append(segmentObject);
}

void BufferData::readFromJSON(const QJsonObject &bufferDataObject)
{
    this->setBufferIndex(bufferDataObject["bufferIndex"].toInt());
    this->setIsDBuffer(bufferDataObject["dBuffer"].toBool());
    this->setBufferName(bufferDataObject["bufferName"].toString().toStdString());
    this->setProgramString(bufferDataObject["bufferText"].toString().toStdString());
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
