#ifndef COMMON_GLOBAL_H
#define COMMON_GLOBAL_H

#ifdef _MSC_VER
#  if defined(COMMON_LIBRARY)
#    define COMMONSHARED_EXPORT  __declspec(dllexport)
#  else
#    define COMMONSHARED_EXPORT  __declspec(dllimport)
#  endif
#else
#  define COMMONSHARED_EXPORT
#endif

#endif // COMMON_GLOBAL_H
