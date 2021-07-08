#ifndef QMODBUS_VERSION_H
#define QMODBUS_VERSION_H

/* The major version, (1, if %LIBQMODBUS_VERSION is 1.2.3) */
#define LIBQMODBUS_VERSION_MAJOR (3)

/* The minor version (2, if %LIBQMODBUS_VERSION is 1.2.3) */
#define LIBQMODBUS_VERSION_MINOR (0)

/* The micro version (3, if %LIBQMODBUS_VERSION is 1.2.3) */
#define LIBQMODBUS_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define LIBQMODBUS_VERSION        3.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define LIBQMODBUS_VERSION_STRING "3.0.0"

/* Numerically encoded version, like 0x010203 */
#define LIBQMODBUS_VERSION_HEX ((LIBQMODBUS_VERSION_MAJOR << 24) |  \
                               (LIBQMODBUS_VERSION_MINOR << 16) |  \
                               (LIBQMODBUS_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define LIBQMODBUS_VERSION_CHECK(major,minor,micro)      \
    (LIBQMODBUS_VERSION_MAJOR > (major) ||               \
     (LIBQMODBUS_VERSION_MAJOR == (major) &&             \
      LIBQMODBUS_VERSION_MINOR > (minor)) ||             \
     (LIBQMODBUS_VERSION_MAJOR == (major) &&             \
      LIBQMODBUS_VERSION_MINOR == (minor) &&             \
      LIBQMODBUS_VERSION_MICRO >= (micro)))


#endif // QMODBUS_VERSION_H
