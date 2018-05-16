#ifndef PARAMETER_MEMORY_WRITE_H
#define PARAMETER_MEMORY_WRITE_H

#include <string>
#include <vector>
#include <iostream>

#include "abstract_parameter.h"


namespace registers_Munk{

ECM_CLASS_FORWARD(ParameterMemoryWrite);

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

} //end of namepsace registers_Munk


#endif // PARAMETER_MEMORY_WRITE_H
