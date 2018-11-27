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
    void setOperationName(const std::string &name);
    void setProfileName(const std::string &name);

public:
    std::string getOperationName() const;
    std::string getProfileName() const;

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
    std::string operationName;
    std::string profileName;
};

#endif // GALIL_CURRENT_OPERATION_H
