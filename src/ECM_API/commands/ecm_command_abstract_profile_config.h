#ifndef ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H
#define ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H

#include <QJsonArray>
#include <QJsonObject>

#include "common/class_forward.h"
#include "common/profile_operation_type.h"

#include "ecm_command_execution_properties.h"

ECM_CLASS_FORWARD(ECMCommand_AbstractProfileConfig);

class ECMCommand_AbstractProfileConfig
{
public:
    ECMCommand_AbstractProfileConfig(const ProfileOpType &configType);

    ECMCommand_AbstractProfileConfig(const ECMCommand_AbstractProfileConfig &copy);

    virtual ~ECMCommand_AbstractProfileConfig()
    {

    }

    ProfileOpType getConfigType() const
    {
        return this->configType;
    }

public:
    /**
     *
     */
    template <class T>
    const T* as() const
    {
        //ensure that we are attempting to cast it to a type of configuration
        return static_cast<const T *>(this);
    }

    /**
     *
     */
    template <class T>
    T* as()
    {
        //ensure that we are attempting to cast it to a type of configuration
        return static_cast<T *>(this);
    }

public:
    virtual void writeToJSON(QJsonObject &obj);

    virtual void readFromJSON(const QJsonObject &obj);

public:
    unsigned int getOperationIndex() const;
    std::string getOperationName() const;
    bool shouldHomeBeIndicated() const;
    bool shouldProfileExecute() const;
    bool hasProfileCompleted() const;

    void setOperationIndex(const unsigned int &index);
    void setOperationName(const std::string &name);
    void setIndicateHomeAutomatically(const bool &homeExecute);
    void setProfileExecution(const bool &varExecute);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ECMCommand_AbstractProfileConfig& operator = (const ECMCommand_AbstractProfileConfig &rhs)
    {
        this->configType = rhs.configType;
        this->operationIndex = rhs.operationIndex;
        this->operationName = rhs.operationName;
        this->indicateHome = rhs.indicateHome;
        this->shouldExecute = rhs.shouldExecute;

        this->execProperties = rhs.execProperties;

        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ECMCommand_AbstractProfileConfig &rhs)
    {
        if(this->configType != rhs.configType){
            return false;
        }
        if(this->operationIndex != rhs.operationIndex){
            return false;
        }
        if(this->operationName != rhs.operationName){
            return false;
        }
        if(this->indicateHome != rhs.indicateHome){
            return false;
        }
        if(this->shouldExecute != rhs.shouldExecute){
            return false;
        }
        if(this->execProperties != rhs.execProperties)
        {
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ECMCommand_AbstractProfileConfig &rhs) {
        return !(*this == rhs);
    }



protected:
    ProfileOpType configType;
    unsigned int operationIndex = 0;
    std::string operationName = "";
    bool indicateHome = false;
    bool shouldExecute = false;

public:
    ECMCommand_ExecutionProperties execProperties;
};


#endif // ECM_COMMAND_ABSTRACT_PROFILE_CONFIG_H
