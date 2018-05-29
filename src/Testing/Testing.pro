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

win32: LIBS += -L$$PWD/../../tools/sensoray/lib/ -ls24xx
INCLUDEPATH += $$PWD/../../tools/sensoray
DEPENDPATH += $$PWD/../../tools/sensoray

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../tools/sensoray/lib/ -ls24xx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../tools/sensoray/lib/ -ls24xx
else:unix:!macx: LIBS += -L$$OUT_PWD/../../tools/sensoray/lib/ -ls24xx

INCLUDEPATH += $$PWD/../../tools/sensoray/lib
DEPENDPATH += $$PWD/../../tools/sensoray/lib

unix:!macx|win32: LIBS += -L$$PWD/../../tools/sensoray/lib/ -ls24xx

INCLUDEPATH += $$PWD/../../tools/sensoray/include
DEPENDPATH += $$PWD/../../tools/sensoray/include


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_sensoray/release/ -llibrary_sensoray
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_sensoray/debug/ -llibrary_sensoray
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_sensoray/ -llibrary_sensoray

INCLUDEPATH += $$PWD/../library_sensoray
DEPENDPATH += $$PWD/../library_sensoray

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library_westinghouse510/release/ -llibrary_westinghouse510
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library_westinghouse510/debug/ -llibrary_westinghouse510
else:unix:!macx: LIBS += -L$$OUT_PWD/../library_westinghouse510/ -llibrary_westinghouse510

INCLUDEPATH += $$PWD/../library_westinghouse510
DEPENDPATH += $$PWD/../library_westinghouse510
