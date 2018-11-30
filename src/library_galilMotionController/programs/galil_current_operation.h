#ifndef GALIL_CURRENT_OPERATION_H
#define GALIL_CURRENT_OPERATION_H

#include "galil_current_program.h"

class GalilCurrentOperation : public GalilCurrentProgram
{
public:
    GalilCurrentOperation();

    GalilCurrentOperation(const GalilCurrentOperation &copy);

    ~GalilCurrentOperation() = default;

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
    friend QTextStream& operator <<(QTextStream &outStream, const GalilCurrentOperation &data)
    {
        return outStream<<QString::fromStdString(data.getLoggingString());
    }

    friend std::ostream& operator<< (std::ostream &stream, const GalilCurrentOperation &data)
    {
        return stream<<data.getLoggingString();
    }

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    GalilCurrentOperation& operator = (const GalilCurrentOperation &rhs)
    {
        GalilCurrentProgram::operator =(rhs);
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
    bool operator == (const GalilCurrentOperation &rhs)
    {
        if(!GalilCurrentProgram::operator ==(rhs)){
            return false;
        }
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
    bool operator != (const GalilCurrentOperation &rhs) {
        return !(*this == rhs);
    }

private:
    unsigned int operationIndex = 0;
    std::string operationName = "";
    std::string profileName = "";
};

#endif // GALIL_CURRENT_OPERATION_H
