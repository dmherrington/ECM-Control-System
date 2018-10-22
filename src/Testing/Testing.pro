message($$PWD)

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

# Copy Files
target.path = $$(ECM_ROOT)/bin
target.files += $$PWD/../../tools/sensoray/lib/s24xx.dll
INSTALLS += target

INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/include
INCLUDEPATH += $$(ECM_ROOT)/tools/galil/include/
INCLUDEPATH += $$(ECM_ROOT)/tools/sensoray/lib/
INCLUDEPATH += $$(ECM_ROOT)/tools/libmodbus
INCLUDEPATH += $$(ECM_ROOT)/tools/libmodbus/src

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_qModBus/release/ -llibrary_qModBus
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_qModBus/debug/ -llibrary_qModBus
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_qModBus/ -llibrary_qModBus

INCLUDEPATH += $$PWD/../library_qModBus
DEPENDPATH += $$PWD/../library_qModBus

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_munk_power_supply/release/ -llibrary_munk_power_supply
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_munk_power_supply/debug/ -llibrary_munk_power_supply
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_munk_power_supply/ -llibrary_munk_power_supply

INCLUDEPATH += $$PWD/../library_munk_power_supply
DEPENDPATH += $$PWD/../library_munk_power_supply
