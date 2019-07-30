#-------------------------------------------------
#
# Project created by QtCreator 2019-07-30T12:30:51
#
#-------------------------------------------------

QT       -= gui
QT += core
QT += serialport
QT += network

TARGET = library_plc
TEMPLATE = lib

DEFINES += LIBRARY_PLC_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        plc.cpp \
    communications/plc_data_framing.cpp \
    communications/plc_message.cpp \
    data_registers/abstract_register.cpp \
    plc_poll_machine.cpp \
    requests/abstract_request.cpp

HEADERS += \
        plc.h \
        library_plc_global.h \ 
    plc_version.h \
    communications/plc_data_framing.h \
    communications/plc_message.h \
    communications/plc_message_framing.h \
    data/type_read_write.h \
    data_registers/abstract_register.h \
    data_registers/available_registers.h \
    data_registers/register_components.h \
    data/type_plc_exception.h \
    plc_poll_machine.h \
    requests/abstract_request.h \
    requests/request_components.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

#Header file copy
INSTALL_PREFIX = $$(ECM_ROOT)/include/$$TARGET
INSTALL_HEADERS = $$HEADERS
include(../headerinstall.pri)

# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/library_plc.lib release/library_plc.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/library_plc.lib debug/library_plc.dll
INSTALLS += lib


INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/include

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
