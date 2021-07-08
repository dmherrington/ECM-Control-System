#ifndef WESTINGHOUSE_VERSION_H
#define WESTINGHOUSE_VERSION_H

/* The major version, (1, if %LIBWESTINGHOUSE_VERSION is 1.2.3) */
#define LIBWESTINGHOUSE_VERSION_MAJOR (3)

/* The minor version (2, if %LIBWESTINGHOUSE_VERSION is 1.2.3) */
#define LIBWESTINGHOUSE_VERSION_MINOR (0)

/* The micro version (3, if %LIBWESTINGHOUSE_VERSION is 1.2.3) */
#define LIBWESTINGHOUSE_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define LIBWESTINGHOUSE_VERSION        3.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define LIBWESTINGHOUSE_VERSION_STRING "3.0.0"

/* Numerically encoded version, like 0x010203 */
#define LIBWESTINGHOUSE_VERSION_HEX ((LIBWESTINGHOUSE_VERSION_MAJOR << 24) |  \
                               (LIBWESTINGHOUSE_VERSION_MINOR << 16) |  \
                               (LIBWESTINGHOUSE_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define LIBWESTINGHOUSE_VERSION_CHECK(major,minor,micro)      \
    (LIBWESTINGHOUSE_VERSION_MAJOR > (major) ||               \
     (LIBWESTINGHOUSE_VERSION_MAJOR == (major) &&             \
      LIBWESTINGHOUSE_VERSION_MINOR > (minor)) ||             \
     (LIBWESTINGHOUSE_VERSION_MAJOR == (major) &&             \
      LIBWESTINGHOUSE_VERSION_MINOR == (minor) &&             \
      LIBWESTINGHOUSE_VERSION_MICRO >= (micro)))

#endif // WESTINGHOUSE_VERSION_H
