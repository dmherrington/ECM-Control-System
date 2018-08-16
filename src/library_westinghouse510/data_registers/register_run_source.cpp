#include "register_run_source.h"

namespace registers_WestinghousePump {

Register_RunSource::Register_RunSource(const WestinhouseRegisterTypes &type, const SourceSetting &setting):
    AbstractWestinghouseRegister(RegisterTypeToInt(type))
{

}

} //end of namespace registers_WestinghousePump
