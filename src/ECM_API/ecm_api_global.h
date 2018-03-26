#ifndef ECM_API_GLOBAL_H
#define ECM_API_GLOBAL_H

#ifdef _MSC_VER
#  if defined(ECM_API_LIBRARY)
#    define ECM_APISHARED_EXPORT __declspec(dllexport)
#  else
#    define ECM_APISHARED_EXPORT __declspec(dllexport)
#  endif
#else
#  define ECM_APISHARED_EXPORT
#endif

#endif // ECM_API_GLOBAL_H
