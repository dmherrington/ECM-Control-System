#ifndef NUMBER_SYSTEMS_H
#define NUMBER_SYSTEMS_H

#include "stdlib.h"
#include <vector>
#include <string>

#include <stdexcept>

#include "data_global.h"

namespace data {
namespace observation {

//!
//! \brief Class describing number systems that are supported by objects in the ExpressionEngine namespace
//!
class NumberSystems
{
public:


    //! Datatypes that can be utilized
    enum StorableDimensions
    {
        SCALAR,
        NR_STORABLE_DIMENSIONS
    };


    //!
    //! \brief Number of elements (dimensions) in a specific number system
    //! \param dim Number system in question
    //! \return Number of dimensions
    //! \exception std::runtime_error Thrown if passed dimension is not part of StorableDimensions
    //!
    static size_t NumElements(const StorableDimensions dim)
    {
        switch(dim)
        {
        case SCALAR:
            return 1;
        default:
            throw new std::runtime_error("Unknown Unit");
        }
    }


    //!
    //! \brief Name of elements (dimensions) for a specific number system
    //!
    //! If the number system has 1 element (i.e. scalar) this method returns an empty vector
    //! \param dim Number system in question
    //! \return Name of elements
    //! \exception std::runtime_error Thrown if passed dimension is not part of StorableDimensions
    //!
    static std::vector<std::string> ElementNames(const StorableDimensions dim)
    {
        switch(dim)
        {
        case SCALAR:
            return std::vector<std::string>();
        default:
            throw new std::runtime_error("Unknown Unit");
        }
    }
};

} //end of namespace observation
} //end of namespace data

#endif // NUMBER_SYSTEMS_H
