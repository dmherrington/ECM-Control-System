#ifndef TYPE_CURRENT_FACTOR_H
#define TYPE_CURRENT_FACTOR_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

//!
//! \brief The CurrentFactorType enum
//!
enum class CurrentFactorType{
    AMPS = 0, /**< */
    A_DM2 = 1 /**< */
};

//!
//! \brief CurrentFactorToString
//! \param type
//! \return
//!
inline std::string CurrentFactorToString(const CurrentFactorType &type) {
    switch (type) {
    case CurrentFactorType::AMPS:
        return "Read";
    case CurrentFactorType::A_DM2:
        return "Write";
    default:
        throw std::runtime_error("Unknown current type seen");
    }
}

//!
//! \brief CurrentFactorFromString
//! \param str
//! \return
//!
inline CurrentFactorType CurrentFactorFromString(const std::string &str) {
    if(str == "Read")
        return CurrentFactorType::AMPS;
    if(str == "Write")
        return CurrentFactorType::A_DM2;
    throw std::runtime_error("Unknown current type seen");
}

//!
//! \brief getListOfCurrentFactor
//! \return
//!
inline std::vector<std::string> getListOfCurrentFactor()
{
    std::vector<std::string> str;
    str.push_back(Data::CurrentFactorToString(CurrentFactorType::AMPS));
    str.push_back(Data::CurrentFactorToString(CurrentFactorType::A_DM2));
    return str;
}

} //end of namespace Data

#endif // TYPE_CURRENT_FACTOR_H
