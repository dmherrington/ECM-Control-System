QT += widgets

TEMPLATE = lib
TARGET = qtwaitingspinner

SOURCES += \
    waitingspinnerwidget.cpp
    
HEADERS += \
    waitingspinnerwidget.h

#Header file copy
headers.path    = $$(ECM_ROOT)/include/qtwaitingspinner
headers.files   += $$HEADERS
INSTALLS       += headers

# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/qtwaitingspinner.lib release/qtwaitingspinner.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/qtwaitingspinner.lib debug/qtwaitingspinner.dll
INSTALLS += lib
