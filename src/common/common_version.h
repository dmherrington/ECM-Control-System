#ifndef COMMON_VERSION_H
#define COMMON_VERSION_H

/* The major version, (1, if %LIBCOMMON_VERSION is 1.2.3) */
#define LIBCOMMON_VERSION_MAJOR (3)

/* The minor version (2, if %LIBCOMMON_VERSION is 1.2.3) */
#define LIBCOMMON_VERSION_MINOR (0)

/* The micro version (3, if %LIBCOMMON_VERSION is 1.2.3) */
#define LIBCOMMON_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define LIBCOMMON_VERSION        3.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define LIBCOMMON_VERSION_STRING "3.0.0"

/* Numerically encoded version, like 0x010203 */
#define LIBCOMMON_VERSION_HEX ((LIBCOMMON_VERSION_MAJOR << 24) |  \
                               (LIBCOMMON_VERSION_MINOR << 16) |  \
                               (LIBCOMMON_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define LIBCOMMON_VERSION_CHECK(major,minor,micro)      \
    (LIBCOMMON_VERSION_MAJOR > (major) ||               \
     (LIBCOMMON_VERSION_MAJOR == (major) &&             \
      LIBCOMMON_VERSION_MINOR > (minor)) ||             \
     (LIBCOMMON_VERSION_MAJOR == (major) &&             \
      LIBCOMMON_VERSION_MINOR == (minor) &&             \
      LIBCOMMON_VERSION_MICRO >= (micro)))


#endif // COMMON_VERSION_H
