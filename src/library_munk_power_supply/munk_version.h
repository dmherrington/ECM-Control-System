#ifndef MUNK_VERSION_H
#define MUNK_VERSION_H

/* The major version, (1, if %LIBMUNK_VERSION is 1.2.3) */
#define LIBMUNK_VERSION_MAJOR (3)

/* The minor version (2, if %LIBMUNK_VERSION is 1.2.3) */
#define LIBMUNK_VERSION_MINOR (0)

/* The micro version (3, if %LIBMUNK_VERSION is 1.2.3) */
#define LIBMUNK_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define LIBMUNK_VERSION        3.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define LIBMUNK_VERSION_STRING "3.0.0"

/* Numerically encoded version, like 0x010203 */
#define LIBMUNK_VERSION_HEX ((LIBMUNK_VERSION_MAJOR << 24) |  \
                               (LIBMUNK_VERSION_MINOR << 16) |  \
                               (LIBMUNK_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define LIBMUNK_VERSION_CHECK(major,minor,micro)      \
    (LIBMUNK_VERSION_MAJOR > (major) ||               \
     (LIBMUNK_VERSION_MAJOR == (major) &&             \
      LIBMUNK_VERSION_MINOR > (minor)) ||             \
     (LIBMUNK_VERSION_MAJOR == (major) &&             \
      LIBMUNK_VERSION_MINOR == (minor) &&             \
      LIBMUNK_VERSION_MICRO >= (micro)))


#endif // MUNK_VERSION_H
