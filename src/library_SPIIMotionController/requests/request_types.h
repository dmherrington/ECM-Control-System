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
    CUSTOM_STRING = 0,
    LIST_LABELS = 1,
    LIST_VARIABLES = 2,
    STOP_CODE = 3,
    TELL_INPUTS = 4,
    TELL_POSITION = 5,
    TELL_SWITCHES = 6,
    TELL_VARIABLE = 7,
    TELL_MOTOR = 8,
    TELL_AXIS = 9
};

//!
//! \brief RequestToString
//! \param type
//! \return
//!
inline std::string RequestToString(const RequestTypes &type) {
    switch (type) {
    case RequestTypes::LIST_LABELS:
        return "LL";
    case RequestTypes::LIST_VARIABLES:
        return "LV";
    case RequestTypes::STOP_CODE:
        return "SC";
    case RequestTypes::TELL_INPUTS:
        return "TI";
    case RequestTypes::TELL_POSITION:
        return "TP";
    case RequestTypes::TELL_SWITCHES:
        return "TS";
    default:
        throw std::runtime_error("Unknown RequestTypes seen in RequestToString");
    }
}

//!
//! \brief RequestFromString
//! \param str
//! \return
//!
inline RequestTypes RequestFromString(const std::string &str) {
    if(str == "LL")
        return RequestTypes::LIST_LABELS;
    if(str == "LV")
        return RequestTypes::LIST_VARIABLES;
    if(str == "SC")
        return RequestTypes::STOP_CODE;
    if(str == "TI")
        return RequestTypes::TELL_INPUTS;
    if(str == "TP")
        return RequestTypes::TELL_POSITION;
    if(str == "TS")
        return RequestTypes::TELL_SWITCHES;

    throw std::runtime_error("Unknown request type seen");
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
