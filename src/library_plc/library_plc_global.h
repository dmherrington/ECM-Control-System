#ifndef LIBRARY_PLC_GLOBAL_H
#define LIBRARY_PLC_GLOBAL_H

#include <QtCore/qglobal.h>
#include "plc_version.h"

#if defined(LIBRARY_PLC_LIBRARY)
#  define LIBRARY_PLCSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBRARY_PLCSHARED_EXPORT Q_DECL_IMPORT
#endif


#endif // LIBRARY_PLC_GLOBAL_H
