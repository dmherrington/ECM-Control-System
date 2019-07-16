#ifndef DATA_VERSION_H
#define DATA_VERSION_H

/* The major version, (1, if %LIBDATA_VERSION is 1.2.3) */
#define LIBDATA_VERSION_MAJOR (3)

/* The minor version (2, if %LIBDATA_VERSION is 1.2.3) */
#define LIBDATA_VERSION_MINOR (0)

/* The micro version (3, if %LIBDATA_VERSION is 1.2.3) */
#define LIBDATA_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define LIBDATA_VERSION        3.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define LIBDATA_VERSION_STRING "3.0.0"

/* Numerically encoded version, like 0x010203 */
#define LIBDATA_VERSION_HEX ((LIBDATA_VERSION_MAJOR << 24) |  \
                               (LIBDATA_VERSION_MINOR << 16) |  \
                               (LIBDATA_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define LIBDATA_VERSION_CHECK(major,minor,micro)      \
    (LIBDATA_VERSION_MAJOR > (major) ||               \
     (LIBDATA_VERSION_MAJOR == (major) &&             \
      LIBDATA_VERSION_MINOR > (minor)) ||             \
     (LIBDATA_VERSION_MAJOR == (major) &&             \
      LIBDATA_VERSION_MINOR == (minor) &&             \
      LIBDATA_VERSION_MICRO >= (micro)))


#endif // DATA_VERSION_H
