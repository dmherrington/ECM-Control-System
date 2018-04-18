QT -= gui
QT += core serialport
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

unix {
DEFINES += OSTYPE_LINUX
}
win32 {
DEFINES += OSTYPE_WINDOWS
}

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
    clock_testing.h \
    main.h


INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/include
INCLUDEPATH += $$(ECM_ROOT)/tools/galil/include/
INCLUDEPATH += $$(ECM_ROOT)/tools/sensoray/lib/


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon

INCLUDEPATH += $$PWD/../common
DEPENDPATH += $$PWD/../common

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../data/release/ -ldata
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../data/debug/ -ldata
else:unix:!macx: LIBS += -L$$OUT_PWD/../data/ -ldata

INCLUDEPATH += $$PWD/../data
DEPENDPATH += $$PWD/../data

#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../graphing/release/ -lgraphing
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../graphing/debug/ -lgraphing
#else:unix:!macx: LIBS += -L$$OUT_PWD/../graphing/ -lgraphing

#INCLUDEPATH += $$PWD/../graphing
#DEPENDPATH += $$PWD/../graphing

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_munk_power_supply/release/ -llibrary_munk_power_supply
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_munk_power_supply/debug/ -llibrary_munk_power_supply
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_munk_power_supply/ -llibrary_munk_power_supply

INCLUDEPATH += $$PWD/../library_munk_power_supply
DEPENDPATH += $$PWD/../library_munk_power_supply

#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/release/ -llibrary_rigol_oscilloscope
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/debug/ -llibrary_rigol_oscilloscope
#else:unix:!macx: LIBS += -L$$OUT_PWD/../library_rigol_oscilloscope/ -llibrary_rigol_oscilloscope

#INCLUDEPATH += $$PWD/../library_rigol_oscilloscope
#DEPENDPATH += $$PWD/../library_rigol_oscilloscope

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_westinghouse510/release/ -llibrary_westinghouse510
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_westinghouse510/debug/ -llibrary_westinghouse510
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_westinghouse510/ -llibrary_westinghouse510

INCLUDEPATH += $$PWD/../library_westinghouse510
DEPENDPATH += $$PWD/../library_westinghouse510



#unix:!macx|win32: LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclib
#unix:!macx|win32: LIBS += -L$$PWD/../../tools/galil/lib/dynamic/x86/ -lgclibo

#INCLUDEPATH += $$PWD/../../tools/galil/lib/dynamic/x86
#DEPENDPATH += $$PWD/../../tools/galil/lib/dynamic/x86

#win32: LIBS += -L$(ECM_ROOT)/tools/galil/dll/x86/ -lgclib -lgclibo
#else:unix: LIBS += -L$(ECM_ROOT)/tools/galil/dll/x86/ -lgclib -lgclibo

#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_galilMotionController/release/ -llibrary_galilMotionController
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_galilMotionController/debug/ -llibrary_galilMotionController
#else:unix:!macx: LIBS += -L$$OUT_PWD/../library_galilMotionController/ -llibrary_galilMotionController

#INCLUDEPATH += $$PWD/../library_galilMotionController
#DEPENDPATH += $$PWD/../library_galilMotionController



win32: LIBS += -L$$PWD/../../tools/sensoray/lib/ -ls24xx

INCLUDEPATH += $$PWD/../../tools/sensoray
DEPENDPATH += $$PWD/../../tools/sensoray


unix:!macx: LIBS += -L$$PWD/../../tools/sensoray/lib/linux/x64/ -l24xx

INCLUDEPATH += $$PWD/../../tools/sensoray/lib/linux/x64
DEPENDPATH += $$PWD/../../tools/sensoray/lib/linux/x64

unix:!macx: PRE_TARGETDEPS += $$PWD/../../tools/sensoray/lib/linux/x64/lib24xx.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_sensoray/release/ -llibrary_sensoray
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_sensoray/debug/ -llibrary_sensoray
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_sensoray/ -llibrary_sensoray

INCLUDEPATH += $$PWD/../library_sensoray
DEPENDPATH += $$PWD/../library_sensoray

#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ECM_API/release/ -lECM_API
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ECM_API/debug/ -lECM_API
#else:unix:!macx: LIBS += -L$$OUT_PWD/../ECM_API/ -lECM_API

#INCLUDEPATH += $$PWD/../ECM_API
#DEPENDPATH += $$PWD/../ECM_API
