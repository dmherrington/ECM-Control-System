#ifndef REQUEST_TYPES_H
#define REQUEST_TYPES_H

#include <vector>
#include <string>
#include <stdexcept>

/**
\* @file  request_types.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*
\*
\*/

enum class RequestTypes{
    LIST_LABELS = 0,
    LIST_VARIABLES = 1,
    STOP_CODE = 2,
    TELL_POSITION = 3,
    TELL_SWITCHES = 4
};

//!
//! \brief RequestToString
//! \param type
//! \return
//!
inline std::string RequestToString(const RequestTypes &type) {
    switch (type) {
    case RequestTypes::LIST_LABELS:
        return "MO";
    case RequestTypes::LIST_VARIABLES:
        return "SH";
    case RequestTypes::STOP_CODE:
        return "JG";
    case RequestTypes::TELL_POSITION:
        return "PR";
    case RequestTypes::TELL_SWITCHES:
        return "PA";
    default:
        throw std::runtime_error("Unknown command type seen");
    }
}

//!
//! \brief RequestFromString
//! \param str
//! \return
//!
inline RequestTypes RequestFromString(const std::string &str) {
    if(str == "MO")
        return RequestTypes::LIST_LABELS;
    if(str == "SH")
        return RequestTypes::LIST_VARIABLES;
    if(str == "JG")
        return RequestTypes::STOP_CODE;
    if(str == "PR")
        return RequestTypes::TELL_POSITION;
    if(str == "PA")
        return RequestTypes::TELL_SWITCHES;

    throw std::runtime_error("Unknown command type seen");
}

//!
//! \brief getListOfCurrentRequestTypes
//! \return
//!
inline std::vector<std::string> getListOfCurrentRequestTypes()
{
    std::vector<std::string> str;

    return str;
}

#endif // REQUEST_TYPES_H
