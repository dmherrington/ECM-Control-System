#ifndef STATUS_BUFFER_STATE_H
#define STATUS_BUFFER_STATE_H

#include <string>

#include "abstract_status.h"

class Status_BufferState : public AbstractStatus
{
public:
    enum class ENUM_BUFFERSTATE {
        CLEARED,
        CURRENT,
        COMPILED,
        ERROR_UPLOAD,
        ERROR_COMPILING,
        UNKNOWN
    };

public:
    Status_BufferState(const ENUM_BUFFERSTATE &value = ENUM_BUFFERSTATE::UNKNOWN);

    Status_BufferState(const Status_BufferState &copy);

    ~Status_BufferState() = default;

public:
    void setBufferState(const ENUM_BUFFERSTATE &value);\
    ENUM_BUFFERSTATE getBufferStatus()const;

    void setProgramString(const std::string &text);
    std::string getProgramString() const;

    void setBufferIndex(const unsigned int &index);
    unsigned int getBufferIndex() const;

    void setErrorString(const std::string &text);
    std::string getErrorString() const;

    void setErrorLine(const unsigned int &line);
    unsigned int getErrorLine() const;


public:
    Status_BufferState& operator = (const Status_BufferState &rhs)
    {
        AbstractStatus::operator =(rhs);
        this->state = rhs.state;
        this->programString = rhs.programString;
        this->bufferIndex = rhs.bufferIndex;
        this->errorString = rhs.programString;
        this->errorLine = rhs.errorLine;
        return *this;
    }

    bool operator == (const Status_BufferState &rhs) {
        if(!AbstractStatus::operator ==(rhs)){
            return false;
        }
        if(this->state != rhs.state){
            return false;
        }
        if(this->programString != rhs.programString){
            return false;
        }
        if(this->bufferIndex != rhs.bufferIndex){
            return false;
        }
        if(this->errorString != rhs.programString){
            return false;
        }
        if(this->errorLine != rhs.errorLine){
            return false;
        }
        return true;
    }

    bool operator != (const Status_BufferState &rhs) {
        return !(*this == rhs);
    }

private:
    ENUM_BUFFERSTATE state;

    std::string programString = "";
    unsigned int bufferIndex = 0;

    std::string errorString = "";
    unsigned int errorLine = 0;
};

#endif // STATUS_BUFFER_STATE_H
