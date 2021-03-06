#ifndef RIGOL_VERSION_H
#define RIGOL_VERSION_H

/* The major version, (1, if %LIBRIGOL_VERSION is 1.2.3) */
#define LIBRIGOL_VERSION_MAJOR (1)

/* The minor version (2, if %LIBRIGOL_VERSION is 1.2.3) */
#define LIBRIGOL_VERSION_MINOR (0)

/* The micro version (3, if %LIBRIGOL_VERSION is 1.2.3) */
#define LIBRIGOL_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define LIBRIGOL_VERSION        1.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define LIBRIGOL_VERSION_STRING "1.0.0"

/* Numerically encoded version, like 0x010203 */
#define LIBRIGOL_VERSION_HEX ((LIBRIGOL_VERSION_MAJOR << 24) |  \
                               (LIBRIGOL_VERSION_MINOR << 16) |  \
                               (LIBRIGOL_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define LIBRIGOL_VERSION_CHECK(major,minor,micro)      \
    (LIBRIGOL_VERSION_MAJOR > (major) ||               \
     (LIBRIGOL_VERSION_MAJOR == (major) &&             \
      LIBRIGOL_VERSION_MINOR > (minor)) ||             \
     (LIBRIGOL_VERSION_MAJOR == (major) &&             \
      LIBRIGOL_VERSION_MINOR == (minor) &&             \
      LIBRIGOL_VERSION_MICRO >= (micro)))


#endif // RIGOL_VERSION_H
