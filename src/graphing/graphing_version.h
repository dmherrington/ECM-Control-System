#ifndef GRAPHING_VERSION_H
#define GRAPHING_VERSION_H

/* The major version, (1, if %LIBGRAPHING_VERSION is 1.2.3) */
#define LIBGRAPHING_VERSION_MAJOR (1)

/* The minor version (2, if %LIBGRAPHING_VERSION is 1.2.3) */
#define LIBGRAPHING_VERSION_MINOR (0)

/* The micro version (3, if %LIBGRAPHING_VERSION is 1.2.3) */
#define LIBGRAPHING_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define LIBGRAPHING_VERSION        1.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define LIBGRAPHING_VERSION_STRING "1.0.0"

/* Numerically encoded version, like 0x010203 */
#define LIBGRAPHING_VERSION_HEX ((LIBGRAPHING_VERSION_MAJOR << 24) |  \
                               (LIBGRAPHING_VERSION_MINOR << 16) |  \
                               (LIBGRAPHING_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define LIBGRAPHING_VERSION_CHECK(major,minor,micro)      \
    (LIBGRAPHING_VERSION_MAJOR > (major) ||               \
     (LIBGRAPHING_VERSION_MAJOR == (major) &&             \
      LIBGRAPHING_VERSION_MINOR > (minor)) ||             \
     (LIBGRAPHING_VERSION_MAJOR == (major) &&             \
      LIBGRAPHING_VERSION_MINOR == (minor) &&             \
      LIBGRAPHING_VERSION_MICRO >= (micro)))


#endif // GRAPHING_VERSION_H
