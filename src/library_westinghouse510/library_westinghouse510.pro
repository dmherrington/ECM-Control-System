#-------------------------------------------------
#
# Project created by QtCreator 2018-03-09T10:47:27
#
#-------------------------------------------------

QT       -= gui
QT += core
QT += serialport
QT += network

TARGET = library_westinghouse510
TEMPLATE = lib

DEFINES += LIBRARY_WESTINGHOUSE510_LIBRARY

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
        westinghouse_510.cpp \
    data_registers/abstract_register.cpp \
    data_registers/register_operation_signal.cpp \
    data_registers/register_flow_rate.cpp \
    westinghouse_510_state.cpp \
    communications/westinghouse_510_data_framing.cpp \
    communications/westinghouse_message.cpp \
    data_registers/register_run_source.cpp

HEADERS += \
    library_westinghouse510_global.h \
    westinghouse_510.h \
    westinghouse_510_state.h \
    data_registers/abstract_register.h \
    data_registers/available_registers.h \
    data_registers/register_flow_rate.h \
    data_registers/register_components.h \
    data_registers/register_operation_signal.h \
    communications/westinghouse_510_data_framing.h \
    communications/westinghouse_510_message_framing.h \
    communications/westinghouse_message.h \
    data/westinghouse_exception_message.h \
    data/type_read_write.h \
    data_registers/register_run_source.h \
    westinghouse_version.h \
    device_interface_pump.h \
    command_pump_properties.h

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
win32:CONFIG(release, debug|release):       lib.files   += release/library_westinghouse510.lib release/library_westinghouse510.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/library_westinghouse510.lib debug/library_westinghouse510.dll
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
