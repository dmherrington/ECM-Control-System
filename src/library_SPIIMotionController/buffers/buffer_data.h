#ifndef BUFFER_DATA_H
#define BUFFER_DATA_H

#include <string>

#include "buffer_variable_values.h"

class BufferData
{
public:
    BufferData(const unsigned int &bufferIndex = 0, const bool &dBuffer = false);

    ~BufferData();

public:

    std::string setBufferName(const std::string &value);
    std::string getBufferName() const;

    void setProgramString(const std::string &program);
    std::string getProgramString() const;

    void setBufferIndex(const unsigned int &bufferIndex);

    void updateLineCount(const unsigned int &count);

    void setBufferCurrent(const bool &current);

    void setBufferCompiled(const bool &compiled);

    void setIsDBuffer(const bool &value);

    void markBufferAsCleared();

public:
    bool isBufferCurrent() const;

    bool isBufferCompiled() const;

    bool isDBuffer() const;

public:
    unsigned int getBufferIndex() const;

public:
    BufferData& operator = (const BufferData &rhs)
    {
        this->m_BufferVariables = rhs.m_BufferVariables;
        this->bufferIndex = rhs.bufferIndex;
        this->bufferName = rhs.bufferName;
        this->lockBufferName = rhs.lockBufferName;
        this->dBuffer = rhs.dBuffer;
        this->lineCount = rhs.lineCount;
        this->bufferProfile = rhs.bufferProfile;
        this->isCurrent = rhs.isCurrent;
        this->isCompiled = rhs.isCompiled;
        this->programText = rhs.programText;
        return *this;
    }

    bool operator == (const BufferData &rhs) {
        if(this->m_BufferVariables != rhs.m_BufferVariables){
            return false;
        }
        if(this->bufferIndex != rhs.bufferIndex){
            return false;
        }
        if(this->bufferName != rhs.bufferName){
            return false;
        }
        if(this->lockBufferName != rhs.lockBufferName){
            return false;
        }
        if(this->dBuffer != rhs.dBuffer){
            return false;
        }
        if(this->lineCount != rhs.lineCount){
            return false;
        }
        if(this->bufferProfile != rhs.bufferProfile){
            return false;
        }
        if(this->isCurrent != rhs.isCurrent){
            return false;
        }
        if(this->isCompiled != rhs.isCompiled){
            return false;
        }
        if(this->programText != rhs.programText){
            return false;
        }
        return true;
    }

    bool operator != (const BufferData &rhs) {
        return !(*this == rhs);
    }

public:
    BufferVariableValues m_BufferVariables;

private:
    unsigned int bufferIndex = 0;

    std::string bufferName = "";
    bool lockBufferName = false;

    bool dBuffer = false;

    unsigned int lineCount = 0;

    std::string bufferProfile = "";

    bool isCurrent = false;

    bool isCompiled = false;

    std::string programText = "";
};

#endif // BUFFER_DATA_H
