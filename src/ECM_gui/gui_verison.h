#ifndef GUI_VERISON_H
#define GUI_VERISON_H

/* The major version, (1, if %APPGUI_VERSION is 1.2.3) */
#define APPGUI_VERSION_MAJOR (1)

/* The minor version (2, if %APPGUI_VERSION is 1.2.3) */
#define APPGUI_VERSION_MINOR (0)

/* The micro version (3, if %APPGUI_VERSION is 1.2.3) */
#define APPGUI_VERSION_MICRO (0)

/* The full version, like 1.2.3 */
#define APPGUI_VERSION        1.0.0

/* The full version, in string form (suited for string concatenation)
 */
#define APPGUI_VERSION_STRING "1.0.0"

/* Numerically encoded version, like 0x010203 */
#define APPGUI_VERSION_HEX ((APPGUI_VERSION_MAJOR << 24) |  \
                               (APPGUI_VERSION_MINOR << 16) |  \
                               (APPGUI_VERSION_MICRO << 8))

/* Evaluates to True if the version is greater than @major, @minor and @micro
 */
#define APPGUI_VERSION_CHECK(major,minor,micro)      \
    (APPGUI_VERSION_MAJOR > (major) ||               \
     (APPGUI_VERSION_MAJOR == (major) &&             \
      APPGUI_VERSION_MINOR > (minor)) ||             \
     (APPGUI_VERSION_MAJOR == (major) &&             \
      APPGUI_VERSION_MINOR == (minor) &&             \
      APPGUI_VERSION_MICRO >= (micro)))

#endif // GUI_VERISON_H
