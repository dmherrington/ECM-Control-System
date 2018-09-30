#ifndef TYPE_PULSE_MODE_H
#define TYPE_PULSE_MODE_H

#include <string>
#include <stdexcept>
#include <vector>


namespace data_Munk {

//!
//! \brief The TypePulseModes enum
//!
enum class TypePulseModes : uint8_t{
    SLAVE = 0, /**< */
    MASTER = 1, /**< */
    STAND_ALONE = 2, /**< */
    ECMIntern = 3, /**< */
    ECMExtern = 4 /**< */
};


} //end of namespace data_Munk

#endif // TYPE_PULSE_MODE_H
