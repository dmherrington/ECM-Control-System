#ifndef PLC_VERSION_H
#define PLC_VERSION_H

/* The major version, (1, if %LIBPLC_VERSION is 1.2.3) */
#define LIBPLC_VERSION_MAJOR (1)

/* The minor version (2, if %LIBPLC_VERSION is 1.2.3) */
#define LIBPLC_VERSION_MINOR (0)

/* The micro version (3, if %LIBPLC_VERSION is 1.2.3) */
#define LIBPLC_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define LIBPLC_VERSION        1.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define LIBPLC_VERSION_STRING "1.0.0"

/* Numerically encoded version, like 0x010203 */
#define LIBPLC_VERSION_HEX ((LIBPLC_VERSION_MAJOR << 24) |  \
                               (LIBPLC_VERSION_MINOR << 16) |  \
                               (LIBPLC_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define LIBPLC_VERSION_CHECK(major,minor,micro)      \
    (LIBPLC_VERSION_MAJOR > (major) ||               \
     (LIBPLC_VERSION_MAJOR == (major) &&             \
      LIBPLC_VERSION_MINOR > (minor)) ||             \
     (LIBPLC_VERSION_MAJOR == (major) &&             \
      LIBPLC_VERSION_MINOR == (minor) &&             \
      LIBPLC_VERSION_MICRO >= (micro)))

#endif // PLC_VERSION_H
