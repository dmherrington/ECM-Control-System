#ifndef EXECUTION_PROPERTIES_H
#define EXECUTION_PROPERTIES_H

#include "common_global.h"

#include "environment_time.h"

namespace common {
class COMMONSHARED_EXPORT ExecutionProperties
{
public:
    enum class ExecutionCondition
    {
        BEGINNING,
        EXECUTING,
        ENDING
    };
public:
    ExecutionProperties() = default;

    ExecutionProperties(const ExecutionProperties &copy)
    {
        this->time = copy.time;
        this->condition = copy.condition;
    }

    virtual ~ExecutionProperties() = default;

    void setTime(const EnvironmentTime &time)
    {
        this->time = time;
    }
    EnvironmentTime getTime() const
    {
        return this->time;
    }

    void setOperatingCondition(const ExecutionCondition &condition)
    {
        this->condition = condition;
    }

    ExecutionCondition getOperatingCondition() const
    {
        return this->condition;
    }

    void setMaxIndex(const unsigned int &index)
    {
        this->maxIndex = index;
    }

    unsigned int getMaxIndex() const
    {
        return this->maxIndex;
    }

    void setCurrentPosition(const int &position)
    {
        this->currentPosition = position;
    }

    int getCurrentPosition() const
    {
        return this->currentPosition;
    }
public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ExecutionProperties& operator = (const ExecutionProperties &rhs)
    {
        this->time = rhs.time;
        this->condition = rhs.condition;
        this->maxIndex = rhs.maxIndex;
        this->currentPosition = rhs.currentPosition;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ExecutionProperties &rhs)
    {
        if(this->time != rhs.time){
            return false;
        }
        if(this->condition != rhs.condition){
            return false;
        }
        if(this->maxIndex != rhs.maxIndex){
            return false;
        }
        if(this->currentPosition != rhs.currentPosition){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ExecutionProperties &rhs) {
        return !(*this == rhs);
    }

protected:
    EnvironmentTime time;
    ExecutionCondition condition = ExecutionCondition::BEGINNING;
    unsigned int maxIndex = 0;
    int currentPosition = 0;

};

class COMMONSHARED_EXPORT ExecuteOperationProperties : public ExecutionProperties
{
public:
    ExecuteOperationProperties():
        ExecutionProperties()
    {

    }

    ExecuteOperationProperties(const std::string &name, const unsigned int &currentIndex):
        ExecutionProperties()
    {
        this->setOperationName(name);
        this->setCurrentIndex(currentIndex);
    }

    ExecuteOperationProperties(const ExecuteOperationProperties &copy):
        ExecutionProperties(copy)
    {
        this->operationName = copy.operationName;
        this->currentIndex = copy.currentIndex;
        this->maxIndex = copy.maxIndex;
    }

    ~ExecuteOperationProperties() = default;

public:

    void setOperationName(const std::string &name)
    {
        this->operationName = name;
    }

    std::string getOperationName() const
    {
        return this->operationName;
    }

    void setCurrentIndex(const unsigned int &index)
    {
        this->currentIndex = index;
    }

    unsigned int getCurrentIndex() const
    {
        return this->currentIndex;
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ExecuteOperationProperties& operator = (const ExecuteOperationProperties &rhs)
    {
        ExecutionProperties::operator =(rhs);
        this->operationName = rhs.operationName;
        this->currentIndex = rhs.currentIndex;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ExecuteOperationProperties &rhs)
    {
        if(!ExecutionProperties::operator ==(rhs)){
            return false;
        }
        if(this->operationName != rhs.operationName){
            return false;
        }
        if(this->currentIndex != rhs.currentIndex){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ExecuteOperationProperties &rhs) {
        return !(*this == rhs);
    }

private:
    std::string operationName = "";
    unsigned int currentIndex = 0;
};

} //end of namespace common

#endif // EXECUTION_PROPERTIES_H
