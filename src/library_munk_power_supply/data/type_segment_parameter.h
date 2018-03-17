#ifndef TYPE_SEGMENT_PARAMETER_H
#define TYPE_SEGMENT_PARAMETER_H

#include <string>
#include <stdexcept>
#include <vector>


namespace data_Munk{

inline bool isOfTimeSegmentType(const int &value)
{
    if((value >= 4170) && (value <= 4186))
        return true;
    return false;
}

//!
//! \brief The SegmentParameter enum
//!
enum class SegmentParameter{
    SEGMENT1 = 4170, /**< */
    SEGMENT2 = 4171, /**< */
    SEGMENT3 = 4172, /**< */
    SEGMENT4 = 4173, /**< */
    SEGMENT5 = 4174, /**< */
    SEGMENT6 = 4175, /**< */
    SEGMENT7 = 4176, /**< */
    SEGMENT8 = 4178, /**< */
    SEGMENT9 = 4179, /**< */
    SEGMENT10 = 4180, /**< */
    SEGMENT11 = 4181, /**< */
    SEGMENT12 = 4182, /**< */
    SEGMENT13 = 4183, /**< */
    SEGMENT14 = 4184, /**< */
    SEGMENT15 = 4185, /**< */
    SEGMENT16 = 4186, /**< */
};


} //end of namespace data_Munk


#endif // TYPE_SEGMENT_PARAMETER_H
