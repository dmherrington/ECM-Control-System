#ifndef TYPE_SUPPLY_OUTPUT_H
#define TYPE_SUPPLY_OUTPUT_H

#include <string>
#include <stdexcept>
#include <vector>

namespace Data
{

//!
//! \brief The TypeSupplyOutput enum
//!
enum class TypeSupplyOutput{
    OUTPUT1 = 0, /**< */
    OUTPUT2 = 1, /**< */
    OUTPUT3 = 2, /**< */
    OUTPUT4 = 3, /**< */
    OUTPUT5 = 4, /**< */
    OUTPUT6 = 5, /**< */
    OUTPUT7 = 6, /**< */
    OUTPUT8 = 7 /**< */
};

//!
//! \brief ReadWriteTypeToString
//! \param type
//! \return
//!
inline std::string TypeSupplyOutputToString(const TypeSupplyOutput &type) {
    switch (type) {
    case TypeSupplyOutput::OUTPUT1:
        return "OUTPUT1";
    case TypeSupplyOutput::OUTPUT2:
        return "OUTPUT2";
    case TypeSupplyOutput::OUTPUT3:
        return "OUTPUT3";
    case TypeSupplyOutput::OUTPUT4:
        return "OUTPUT4";
    case TypeSupplyOutput::OUTPUT5:
        return "OUTPUT5";
    case TypeSupplyOutput::OUTPUT6:
        return "OUTPUT6";
    case TypeSupplyOutput::OUTPUT7:
        return "OUTPUT7";
    case TypeSupplyOutput::OUTPUT8:
        return "OUTPUT8";
    default:
        throw std::runtime_error("Unknown read or write type seen");
    }
}

//!
//! \brief ReadWriteTypeFromString
//! \param str
//! \return
//!
inline TypeSupplyOutput TypeSupplyOutputString(const std::string &str) {
    if(str == "OUTPUT1")
        return TypeSupplyOutput::OUTPUT1;
    if(str == "OUTPUT2")
        return TypeSupplyOutput::OUTPUT2;
    if(str == "OUTPUT3")
        return TypeSupplyOutput::OUTPUT3;
    if(str == "OUTPUT4")
        return TypeSupplyOutput::OUTPUT4;
    if(str == "OUTPUT5")
        return TypeSupplyOutput::OUTPUT5;
    if(str == "OUTPUT6")
        return TypeSupplyOutput::OUTPUT6;
    if(str == "OUTPUT7")
        return TypeSupplyOutput::OUTPUT7;
    if(str == "OUTPUT8")
        return TypeSupplyOutput::OUTPUT8;
    throw std::runtime_error("Unknown read or write type seen");
}

//!
//! \brief getListOfReadWriteType
//! \return
//!
inline std::vector<std::string> getListOfTypeSupplyOutput()
{
    std::vector<std::string> str;
    str.push_back(Data::TypeSupplyOutputToString(TypeSupplyOutput::OUTPUT1));
    str.push_back(Data::TypeSupplyOutputToString(TypeSupplyOutput::OUTPUT2));
    str.push_back(Data::TypeSupplyOutputToString(TypeSupplyOutput::OUTPUT3));
    str.push_back(Data::TypeSupplyOutputToString(TypeSupplyOutput::OUTPUT4));
    str.push_back(Data::TypeSupplyOutputToString(TypeSupplyOutput::OUTPUT5));
    str.push_back(Data::TypeSupplyOutputToString(TypeSupplyOutput::OUTPUT6));
    str.push_back(Data::TypeSupplyOutputToString(TypeSupplyOutput::OUTPUT7));
    str.push_back(Data::TypeSupplyOutputToString(TypeSupplyOutput::OUTPUT8));
    return str;
}

} //end of namespace Data

#endif // TYPE_SUPPLY_OUTPUT_H
