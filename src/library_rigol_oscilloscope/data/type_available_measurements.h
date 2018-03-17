#ifndef TYPE_AVAILABLE_MEASUREMENTS_H
#define TYPE_AVAILABLE_MEASUREMENTS_H

#include <string>
#include <stdexcept>
#include <vector>

namespace data_Rigol {

enum class MeasurementTypes
{
    MEASURE_VMAX,
    MEASURE_VMIN,
    MEASURE_VPP,
    MEASURE_VTOP,
    MEASURE_VBASE,
    MESAURE_VAMP,
    MEASURE_VAVG,
    MEASURE_VRMS,
    MEASURE_OVERSHOOT,
    MEASURE_PRESHOOT,
    MEASURE_MAREA,
    MEASURE_MPAREA,
    MEASURE_PERIOD,
    MEASURE_FREQUENCY,
    MEASURE_RTIME,
    MEASURE_FTIME,
    MEASURE_PWIDTH,
    MEASURE_NWIDTH,
    MEASURE_PDUTY,
    MEASURE_NDUTY,
    MEASURE_RDELAY,
    MEASURE_FDELAY,
    MEASURE_RPHASE,
    MEASURE_FPHASE
};

//!
//! \brief SegmentModeToString
//! \param type
//! \return
//!
inline std::string MeasurementTypeEnumToString(const MeasurementTypes &type) {
    switch (type) {
    case MeasurementTypes::MEASURE_VMAX:
        return "VMAX";
        break;
    case MeasurementTypes::MEASURE_VMIN:
        return "VMIN";
        break;
    case MeasurementTypes::MEASURE_VPP:
        return "VPP";
        break;
    case MeasurementTypes::MEASURE_VTOP:
        return "VTOP";
        break;
    case MeasurementTypes::MEASURE_VBASE:
        return "VBASe";
        break;
    case MeasurementTypes::MESAURE_VAMP:
        return "VAMP";
        break;
    case MeasurementTypes::MEASURE_VAVG:
        return "VAVG";
        break;
    case MeasurementTypes::MEASURE_VRMS:
        return "VRMS";
        break;
    case MeasurementTypes::MEASURE_OVERSHOOT:
        return "OVERshoot";
        break;
    case MeasurementTypes::MEASURE_PRESHOOT:
        return "PREShoot";
        break;
    case MeasurementTypes::MEASURE_MAREA:
        return "MARea";
        break;
    case MeasurementTypes::MEASURE_MPAREA:
        return "MPARea";
        break;
    case MeasurementTypes::MEASURE_PERIOD:
        return "PERiod";
        break;
    case MeasurementTypes::MEASURE_FREQUENCY:
        return "FREQuency";
        break;
    case MeasurementTypes::MEASURE_RTIME:
        return "RTIMe";
        break;
    case MeasurementTypes::MEASURE_FTIME:
        return "FTIMe";
        break;
    case MeasurementTypes::MEASURE_PWIDTH:
        return "PWIDth";
        break;
    case MeasurementTypes::MEASURE_NWIDTH:
        return "NWIDth";
        break;
    case MeasurementTypes::MEASURE_PDUTY:
        return "PDUTy";
        break;
    case MeasurementTypes::MEASURE_NDUTY:
        return "NDUTy";
        break;
    case MeasurementTypes::MEASURE_RDELAY:
        return "RDELay";
        break;
    case MeasurementTypes::MEASURE_FDELAY:
        return "FDELay";
        break;
    case MeasurementTypes::MEASURE_RPHASE:
        return "RPHase";
        break;
    case MeasurementTypes::MEASURE_FPHASE:
        return "FPHase";
        break;
    default:
        throw std::runtime_error("Unknown measurement type seen");
        break;
    }
    return "";
}

inline MeasurementTypes AvailableMeasurementTypeStringToEnum(const std::string str) {
    if(str == "VMAX")
        return MeasurementTypes::MEASURE_VMAX;
    if(str == "VMIN")
        return MeasurementTypes::MEASURE_VMIN;
    if(str == "VPP")
        return MeasurementTypes::MEASURE_VPP;
    if(str == "VTOP")
        return MeasurementTypes::MEASURE_VTOP;
    if(str == "VBASe")
        return MeasurementTypes::MEASURE_VBASE;
    if(str == "VAMP")
        return MeasurementTypes::MESAURE_VAMP;
    if(str == "VAVG")
        return MeasurementTypes::MEASURE_VAVG;
    if(str == "VRMS")
        return MeasurementTypes::MEASURE_VRMS;
    if(str == "OVERshoot")
        return MeasurementTypes::MEASURE_OVERSHOOT;
    if(str == "PREShoot")
        return MeasurementTypes::MEASURE_PRESHOOT;
    if(str == "MARea")
        return MeasurementTypes::MEASURE_MAREA;
    if(str == "MPARea")
        return MeasurementTypes::MEASURE_MPAREA;
    if(str == "PERiod")
        return MeasurementTypes::MEASURE_PERIOD;
    if(str == "FREQuency")
        return MeasurementTypes::MEASURE_FREQUENCY;
    if(str == "RTIMe")
        return MeasurementTypes::MEASURE_RTIME;
    if(str == "FTIMe")
        return MeasurementTypes::MEASURE_FTIME;
    if(str == "PWIDth")
        return MeasurementTypes::MEASURE_PWIDTH;
    if(str == "NWIDth")
        return MeasurementTypes::MEASURE_NWIDTH;
    if(str == "PDUTy")
        return MeasurementTypes::MEASURE_PDUTY;
    if(str == "NDUTy")
        return MeasurementTypes::MEASURE_NDUTY;
    if(str == "RDELay")
        return MeasurementTypes::MEASURE_RDELAY;
    if(str == "FDELay")
        return MeasurementTypes::MEASURE_FDELAY;
    if(str == "RPHase")
        return MeasurementTypes::MEASURE_RPHASE;
    if(str == "FPHase")
        return MeasurementTypes::MEASURE_FPHASE;
    throw std::runtime_error("Unknown measurement type string seen");
}

inline std::vector<std::string> getListOfAvailableMeasurements()
{
    std::vector<std::string> str;
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_VMAX));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_VMIN));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_VPP));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_VTOP));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_VBASE));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MESAURE_VAMP));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_VAVG));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_VRMS));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_OVERSHOOT));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_PRESHOOT));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_MAREA));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_MPAREA));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_PERIOD));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_FREQUENCY));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_RTIME));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_FTIME));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_PWIDTH));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_NWIDTH));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_PDUTY));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_NDUTY));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_RDELAY));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_FDELAY));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_RPHASE));
    str.push_back(MeasurementTypeEnumToString(MeasurementTypes::MEASURE_FPHASE));
    return str;
}

} //end of namespace data_Rigol


#endif // TYPE_AVAILABLE_MEASUREMENTS_H
