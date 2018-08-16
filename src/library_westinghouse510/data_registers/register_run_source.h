#ifndef REGISTER_RUN_SOURCE_H
#define REGISTER_RUN_SOURCE_H

#include "abstract_register.h"

namespace registers_WestinghousePump{


class Register_RunSource : public AbstractWestinghouseRegister
{

public:
    enum class SourceSetting : uint8_t
    {
        SOURCE_KEYPAD = 0,
        SOURCE_EXTERNAL_TERMINAL = 1,
        SOURCE_RS485 = 2,
        SOURCE_PLC = 3
    };

public:
    Register_RunSource(const WestinhouseRegisterTypes &type, const SourceSetting &setting = SourceSetting::SOURCE_KEYPAD);

protected:
    SourceSetting source;
};


} //end of namespace registers_WestinghousePump
#endif // REGISTER_RUN_SOURCE_H
