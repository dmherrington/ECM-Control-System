#ifndef TYPE_MEASURE_COMMANDS_H
#define TYPE_MEASURE_COMMANDS_H

#include <string>
#include <stdexcept>
#include <vector>


namespace data_Rigol{

enum class MeasurementCommands
{
    MEASURE_ITEM
};

//!
//! \brief SegmentModeToString
//! \param type
//! \return
//!
inline std::string MeasurementCommandToString(const MeasurementCommands &type) {
    switch (type) {
    case MeasurementCommands::MEASURE_ITEM:
        return "ITEM";
    default:
        throw std::runtime_error("Unknown measurement type seen");
    }
}

//!
//! \brief SegmentModeFromString
//! \param str
//! \return
//!
inline MeasurementCommands MeasurementTypeFromString(const std::string &str) {
    if(str == "ITEM")
        return MeasurementCommands::MEASURE_ITEM;
    throw std::runtime_error("Unknown measurement type string seen");
}

//!
//! \brief getListOfSegmentMode
//! \return
//!
inline std::vector<std::string> getListOfMeasurementTypes()
{
    std::vector<std::string> str;
    str.push_back(MeasurementCommandToString(MeasurementCommands::MEASURE_ITEM));
    return str;
}

} //end of namespace data_Rigol


#endif // TYPE_MEASURE_COMMANDS_H
