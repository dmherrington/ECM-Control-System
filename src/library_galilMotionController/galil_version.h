#ifndef GALIL_VERSION_H
#define GALIL_VERSION_H

/* The major version, (1, if %LIBGALIL_VERSION is 1.2.3) */
#define LIBGALIL_VERSION_MAJOR (1)

/* The minor version (2, if %LIBGALIL_VERSION is 1.2.3) */
#define LIBGALIL_VERSION_MINOR (0)

/* The micro version (3, if %LIBGALIL_VERSION is 1.2.3) */
#define LIBGALIL_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define LIBGALIL_VERSION        1.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define LIBGALIL_VERSION_STRING "1.0.0"

/* Numerically encoded version, like 0x010203 */
#define LIBGALIL_VERSION_HEX ((LIBGALIL_VERSION_MAJOR << 24) |  \
                               (LIBGALIL_VERSION_MINOR << 16) |  \
                               (LIBGALIL_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define LIBGALIL_VERSION_CHECK(major,minor,micro)      \
    (LIBGALIL_VERSION_MAJOR > (major) ||               \
     (LIBGALIL_VERSION_MAJOR == (major) &&             \
      LIBGALIL_VERSION_MINOR > (minor)) ||             \
     (LIBGALIL_VERSION_MAJOR == (major) &&             \
      LIBGALIL_VERSION_MINOR == (minor) &&             \
      LIBGALIL_VERSION_MICRO >= (micro)))


#endif // GALIL_VERSION_H
