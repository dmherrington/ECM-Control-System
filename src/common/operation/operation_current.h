#ifndef OPERATION_CURRENT_H
#define OPERATION_CURRENT_H

#include <QTextStream>
#include <QJsonObject>

class Operation_CurrentProgram
{
public:
    Operation_CurrentProgram();

    Operation_CurrentProgram(const Operation_CurrentProgram &copy);

    ~Operation_CurrentProgram() = default;

public:
    void writeToJSON(QJsonObject &saveObject);

    void readFromJSON(const QJsonObject &openObject);

public:
    void setProgramLoaded(const bool &loaded, const std::string &path);

    void setOperationIndex(const unsigned int &index);
    void setOperationName(const std::string &name);
    void setProfileName(const std::string &name);

public:

    bool wasProgramLoaded(std::string &path) const;
    unsigned int getOperationIndex() const;
    std::string getOperationName() const;
    std::string getProfileName() const;

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
    Operation_CurrentProgram& operator = (const Operation_CurrentProgram &rhs)
    {
        this->programLoaded = rhs.programLoaded;
        this->programPath = rhs.programPath;

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
    bool operator == (const Operation_CurrentProgram &rhs)
    {
        if(this->programLoaded != rhs.programLoaded){
            return false;
        }
        if(this->programPath != rhs.programPath){
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
    bool operator != (const Operation_CurrentProgram &rhs) {
        return !(*this == rhs);
    }

protected:
    bool programLoaded = false;
    std::string programPath = "";

    unsigned int operationIndex = 0;
    std::string operationName = "";
    std::string profileName = "";
};

#endif // OPERATION_CURRENT_H
