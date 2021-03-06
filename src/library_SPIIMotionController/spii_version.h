#ifndef SPII_VERSION_H
#define SPII_VERSION_H

/* The major version, (1, if %LIBSPII_VERSION is 1.2.3) */
#define LIBSPII_VERSION_MAJOR (1)

/* The minor version (2, if %LIBSPII_VERSION is 1.2.3) */
#define LIBSPII_VERSION_MINOR (0)

/* The micro version (3, if %LIBSPII_VERSION is 1.2.3) */
#define LIBSPII_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define LIBSPII_VERSION        1.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define LIBSPII_VERSION_STRING "1.0.0"

/* Numerically encoded version, like 0x010203 */
#define LIBSPII_VERSION_HEX ((LIBSPII_VERSION_MAJOR << 24) |  \
                               (LIBSPII_VERSION_MINOR << 16) |  \
                               (LIBSPII_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define LIBSPII_VERSION_CHECK(major,minor,micro)      \
    (LIBSPII_VERSION_MAJOR > (major) ||               \
     (LIBSPII_VERSION_MAJOR == (major) &&             \
      LIBSPII_VERSION_MINOR > (minor)) ||             \
     (LIBSPII_VERSION_MAJOR == (major) &&             \
      LIBSPII_VERSION_MINOR == (minor) &&             \
      LIBSPII_VERSION_MICRO >= (micro)))


#endif // SPII_VERSION_H
