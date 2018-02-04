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
    return "";
}


} //end of namespace data
} //end of namespace rigol

#endif // TYPE_AVAILABLE_MEASUREMENTS_H
