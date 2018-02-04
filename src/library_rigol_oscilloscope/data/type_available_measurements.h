#ifndef TYPE_AVAILABLE_MEASUREMENTS_H
#define TYPE_AVAILABLE_MEASUREMENTS_H

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
    MEASURE_MARea
};

} //end of namespace data
} //end of namespace rigol
#endif // TYPE_AVAILABLE_MEASUREMENTS_H
