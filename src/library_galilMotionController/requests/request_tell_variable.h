#ifndef REQUEST_TELL_VARIABLE_H
#define REQUEST_TELL_VARIABLE_H

#include <string>
#include "common/class_forward.h"
#include "requests/abstract_request.h"
#include "status/status_variable_value.h"


ECM_CLASS_FORWARD(Request_TellVariable);

class Request_TellVariable : public AbstractRequest
{
public:
    Request_TellVariable(const std::string &humName, const std::string &varName);

    Request_TellVariable(const Request_TellVariable &copy);

public:
    /**
      */
    virtual ~Request_TellVariable() = default;

public:

    /**
     * @brief getClone
     * @return
     */
    AbstractRequest* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    void getClone(AbstractRequest** state) const override;

public:

    /*!
     * \brief setHumanName
     * \param name
     */
    void setHumanName(const std::string &name);

    /*!
     * \brief setVariableName
     * \param name
     */
    void setVariableName(const std::string &name);

    /*!
     * \brief getHumanName
     * \return
     */
    std::string getHumanName() const;

    /*!
     * \brief getVariableName
     * \return
     */
    std::string getVariableName() const;

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    std::string getRequestString() const override;

    std::vector<AbstractStatusPtr> getStatus() const override;

private:
    std::string humanName; /**< A human readable name that describes the variable requested */

    std::string variableName; /**< The variable name explicitly recognized within the galil motion profile */
};


#endif // REQUEST_TELL_VARIABLE_H
