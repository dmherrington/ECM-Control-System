#ifndef OPERATION_CURRENT_H
#define OPERATION_CURRENT_H

#include <QTextStream>
#include <QJsonObject>

class Operation_Current
{
public:
    Operation_Current();

    Operation_Current(const Operation_Current &copy);

    ~Operation_Current() = default;

public:
    void writeToJSON(QJsonObject &saveObject);

    void readFromJSON(const QJsonObject &openObject);

public:
    void setOperationIndex(const unsigned int &index);
    void setOperationName(const std::string &name);
    void setProfileName(const std::string &name);

public:
    unsigned int getOperationIndex() const;
    std::string getOperationName() const;
    std::string getProfileName() const;

public:

public:
//    friend QTextStream& operator <<(QTextStream &outStream, const GalilCurrentOperation &data)
//    {
//        return outStream<<QString::fromStdString(data.getLoggingString());
//    }

//    friend std::ostream& operator<< (std::ostream &stream, const GalilCurrentOperation &data)
//    {
//        return stream<<data.getLoggingString();
//    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Operation_Current& operator = (const Operation_Current &rhs)
    {
        //GalilCurrentProgram::operator =(rhs);
        this->operationIndex = rhs.operationIndex;
        this->operationName = rhs.operationName;
        this->profileName = rhs.profileName;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Operation_Current &rhs)
    {
//        if(!GalilCurrentProgram::operator ==(rhs)){
//            return false;
//        }
        if(this->operationIndex != rhs.operationIndex){
            return false;
        }
        if(this->operationName != rhs.operationName){
            return false;
        }
        if(this->profileName != rhs.profileName){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const Operation_Current &rhs) {
        return !(*this == rhs);
    }

private:
    unsigned int operationIndex = 0;
    std::string operationName = "";
    std::string profileName = "";
};

#endif // OPERATION_CURRENT_H
