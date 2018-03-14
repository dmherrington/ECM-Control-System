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
    Request_TellVariable(const std::string &name);

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
    //!
    //! \brief setAxis
    //! \param axis
    //!
    void setVariableName(const std::string &axis);

    //!
    //! \brief getAxis
    //! \return
    //!
    std::string getVariableName() const;

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    std::string getRequestString() const override;

    std::vector<AbstractStatusPtr> getStatus() const override;

private:
    std::string variableName; /**< Value of the axis to be position requested */

};


#endif // REQUEST_TELL_VARIABLE_H
