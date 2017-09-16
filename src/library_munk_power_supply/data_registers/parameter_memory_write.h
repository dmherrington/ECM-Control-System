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
};

}
#endif // PARAMETER_MEMORY_WRITE_H
