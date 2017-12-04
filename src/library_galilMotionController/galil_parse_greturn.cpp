#include "galil_parse_greturn.h"

ParseGReturn::ParseGReturn()
{

}

std::string ParseGReturn::getGReturnString(const GReturn &code)
{
    switch (code) {
    case G_NO_ERROR:
        return G_NO_ERROR_S;
        break;
    case G_GCLIB_ERROR:
        return G_GCLIB_ERROR_S;
        break;
    case G_GCLIB_UTILITY_ERROR:
        return G_GCLIB_UTILITY_ERROR_S;
        break;
    case G_GCLIB_UTILITY_IP_TAKEN:
        return G_GCLIB_UTILITY_IP_TAKEN_S;
        break;
    case G_GCLIB_NON_BLOCKING_READ_EMPTY:
        return G_GCLIB_NON_BLOCKING_READ_EMPTY_S;
        break;
    case G_TIMEOUT:
        return G_TIMEOUT_S;
        break;
    case G_OPEN_ERROR:
        return G_OPEN_ERROR_S;
        break;
    case G_READ_ERROR:
        return G_NO_ERROR_S;
        break;
    case G_WRITE_ERROR:
        return G_WRITE_ERROR_S;
        break;
    case G_INVALID_PREPROCESSOR_OPTIONS:
        return G_INVALID_PREPROCESSOR_OPTIONS_S;
        break;
    case G_COMMAND_CALLED_WITH_ILLEGAL_COMMAND:
        return G_COMMAND_CALLED_WITH_ILLEGAL_COMMAND_S;
        break;
    case G_DATA_RECORD_ERROR:
        return G_DATA_RECORD_ERROR_S;
        break;
    case G_UNSUPPORTED_FUNCTION:
        return G_UNSUPPORTED_FUNCTION_S;
        break;
    case G_FIRMWARE_LOAD_NOT_SUPPORTED:
        return G_FIRMWARE_LOAD_NOT_SUPPORTED_S;
        break;
    case G_ARRAY_NOT_DIMENSIONED:
        return G_ARRAY_NOT_DIMENSIONED_S;
        break;
    case G_ILLEGAL_DATA_IN_PROGRAM:
        return G_ILLEGAL_DATA_IN_PROGRAM_S;
        break;
    case G_UNABLE_TO_COMPRESS_PROGRAM_TO_FIT:
        return G_UNABLE_TO_COMPRESS_PROGRAM_TO_FIT_S;
        break;
    case G_BAD_RESPONSE_QUESTION_MARK:
        return G_BAD_RESPONSE_QUESTION_MARK_S;
        break;
    case G_BAD_VALUE_RANGE:
        return G_BAD_VALUE_RANGE_S;
        break;
    case G_BAD_FULL_MEMORY:
        return G_BAD_FULL_MEMORY_S;
        break;
    case G_BAD_LOST_DATA:
        return G_BAD_LOST_DATA_S;
        break;
    case G_BAD_FILE:
        return G_BAD_FILE_S;
        break;
    case G_BAD_ADDRESS:
        return G_BAD_ADDRESS_S;
        break;
    case G_GCAPS_OPEN_ERROR:
        return G_GCAPS_OPEN_ERROR_S;
        break;
    case G_GCAPS_SUBSCRIPTION_ERROR:
        return G_GCAPS_SUBSCRIPTION_ERROR_S;
        break;
    default:
        std::string rtn = "Unknown GReturn error seen: ";
        rtn += std::to_string(code);
        return rtn;
        break;
    }
}
