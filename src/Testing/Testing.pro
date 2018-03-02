QT -= gui
QT += core serialport
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    state2.cpp \
    state1.cpp \
    clock_testing.cpp

HEADERS += \
    hsm.h \
    state2.h \
    state1.h \
    clock_testing.h



INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/tools/galil/include/
INCLUDEPATH += $$(ECM_ROOT)/tools/sensoray/lib/
INCLUDEPATH += $$(ECM_ROOT)/include



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/release/ -llibrary_rigol_oscilloscope
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/debug/ -llibrary_rigol_oscilloscope
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/ -llibrary_rigol_oscilloscope

INCLUDEPATH += $$PWD/../library_rigol_oscilloscope
DEPENDPATH += $$PWD/../library_rigol_oscilloscope

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library_rigol_oscilloscope/release/liblibrary_rigol_oscilloscope.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library_rigol_oscilloscope/debug/liblibrary_rigol_oscilloscope.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library_rigol_oscilloscope/release/library_rigol_oscilloscope.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library_rigol_oscilloscope/debug/library_rigol_oscilloscope.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../library_rigol_oscilloscope/liblibrary_rigol_oscilloscope.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon

INCLUDEPATH += $$PWD/../common
DEPENDPATH += $$PWD/../common

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/release/libcommon.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/debug/libcommon.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/release/common.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/debug/common.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../common/libcommon.a

unix:!macx|win32: LIBS += -L$$PWD/../../tools/sensoray/lib/ -ls24xx

INCLUDEPATH += $$PWD/../../tools/sensoray
DEPENDPATH += $$PWD/../../tools/sensoray

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_sensoray/release/ -llibrary_sensoray
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_sensoray/debug/ -llibrary_sensoray
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_sensoray/ -llibrary_sensoray

INCLUDEPATH += $$PWD/../library_sensoray
DEPENDPATH += $$PWD/../library_sensoray
