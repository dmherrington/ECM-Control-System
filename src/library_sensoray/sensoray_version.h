#ifndef SENSORAY_VERSION_H
#define SENSORAY_VERSION_H

/* The major version, (1, if %LIBSENSORAY_VERSION is 1.2.3) */
#define LIBSENSORAY_VERSION_MAJOR (3)

/* The minor version (2, if %LIBSENSORAY_VERSION is 1.2.3) */
#define LIBSENSORAY_VERSION_MINOR (0)

/* The micro version (3, if %LIBSENSORAY_VERSION is 1.2.3) */
#define LIBSENSORAY_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define LIBSENSORAY_VERSION        3.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define LIBSENSORAY_VERSION_STRING "3.0.0"

/* Numerically encoded version, like 0x010203 */
#define LIBSENSORAY_VERSION_HEX ((LIBSENSORAY_VERSION_MAJOR << 24) |  \
                               (LIBSENSORAY_VERSION_MINOR << 16) |  \
                               (LIBSENSORAY_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define LIBSENSORAY_VERSION_CHECK(major,minor,micro)      \
    (LIBSENSORAY_VERSION_MAJOR > (major) ||               \
     (LIBSENSORAY_VERSION_MAJOR == (major) &&             \
      LIBSENSORAY_VERSION_MINOR > (minor)) ||             \
     (LIBSENSORAY_VERSION_MAJOR == (major) &&             \
      LIBSENSORAY_VERSION_MINOR == (minor) &&             \
      LIBSENSORAY_VERSION_MICRO >= (micro)))

#endif // SENSORAY_VERSION_H
