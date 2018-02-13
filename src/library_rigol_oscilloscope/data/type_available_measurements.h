#ifndef TYPE_AVAILABLE_MEASUREMENTS_H
#define TYPE_AVAILABLE_MEASUREMENTS_H

#include <string>
#include <stdexcept>

namespace rigol{
namespace data {

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
inline std::string MeasurementTypeToString(const MeasurementTypes &type) {
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


} //end of namespace data
} //end of namespace rigol

#endif // TYPE_AVAILABLE_MEASUREMENTS_H
