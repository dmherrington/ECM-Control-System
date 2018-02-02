#ifndef PARAMETER_MEMORY_WRITE_H
#define PARAMETER_MEMORY_WRITE_H

#include <string>
#include <vector>
#include <iostream>

#include "abstract_parameter.h"

namespace DataParameter{

//!
//! \brief The ParameterMemoryWrite class
//!
class ParameterMemoryWrite : public AbstractParameter
{
public:
    //!
    //! \brief ParameterMemoryWrite
    //!
    ParameterMemoryWrite();

    ParameterMemoryWrite(const ParameterMemoryWrite &copy);

public:
    //!
    //! \brief getParameterType
    //! \return
    //!
    virtual DataParameter::ParameterType getParameterType() const;

    //!
    //! \brief getByteArray
    //! \return
    //!
    virtual QByteArray getByteArray() const;

    //!
    //! \brief getDescription
    //! \return
    //!
    virtual std::string getDescription() const;

    AbstractParameter* getClone() const override
    {
        return (new ParameterMemoryWrite(*this));
    }

    void getClone(AbstractParameter** parameter) const override
    {
        *parameter = new ParameterMemoryWrite(*this);
    }

    //!
    //! \brief getExpectedResponse
    //! \return
    //!
    QByteArray getExpectedResponse() const override;


};

}
#endif // PARAMETER_MEMORY_WRITE_H
