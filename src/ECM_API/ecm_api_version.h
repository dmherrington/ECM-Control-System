#ifndef ECM_API_VERSION_H
#define ECM_API_VERSION_H

/* The major version, (1, if %ECMAPI_VERSION is 1.2.3) */
#define ECMAPI_VERSION_MAJOR (3)

/* The minor version (2, if %ECMAPI_VERSION is 1.2.3) */
#define ECMAPI_VERSION_MINOR (0)

/* The micro version (3, if %ECMAPI_VERSION is 1.2.3) */
#define ECMAPI_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define ECMAPI_VERSION        3.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define ECMAPI_VERSION_STRING "3.0.0"

/* Numerically encoded version, like 0x010203 */
#define ECMAPI_VERSION_HEX ((ECMAPI_VERSION_MAJOR << 24) |  \
                               (ECMAPI_VERSION_MINOR << 16) |  \
                               (ECMAPI_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define ECMAPI_VERSION_CHECK(major,minor,micro)      \
    (ECMAPI_VERSION_MAJOR > (major) ||               \
     (ECMAPI_VERSION_MAJOR == (major) &&             \
      ECMAPI_VERSION_MINOR > (minor)) ||             \
     (ECMAPI_VERSION_MAJOR == (major) &&             \
      ECMAPI_VERSION_MINOR == (minor) &&             \
      ECMAPI_VERSION_MICRO >= (micro)))


#endif // ECM_API_VERSION_H
