#-------------------------------------------------
#
# Project created by QtCreator 2017-05-30T07:36:57
#
#-------------------------------------------------

QT       -= gui

TARGET = library_munk_power_supply
TEMPLATE = lib

DEFINES += LIBRARY_MUNK_POWER_SUPPLY_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += munk_power_supply.cpp \
    data_registers/abstract_parameter.cpp \
    data_registers/segment_time_general.cpp \
    data_registers/segment_time_detailed.cpp \
    data_registers/segment_time_data_general.cpp \
    data_registers/segment_time_data_detailed.cpp \
    data/register_data_object.cpp \
    data_registers/segment_voltage_setpoint.cpp \
    data_registers/segment_current_setpoint.cpp \
    data_registers/parameter_memory_write.cpp \
    data_response/fault_register_one.cpp \
    data_response/fault_register_three.cpp \
    data_response/fault_register_two.cpp \
    data_response/valid_response.cpp \
    data_response/exception_response.cpp

HEADERS += munk_power_supply.h\
        library_munk_power_supply_global.h \
    data/type_read_write.h \
    data/type_segment_level.h \
    data/type_segment_mode.h \
    data/type_prescalar_power.h \
    data_registers/type_definition.h \
    data_registers/abstract_parameter.h \
    data_registers/segment_time_general.h \
    data_registers/segment_time_detailed.h \
    data/type_segment_parameter.h \
    data/type_current_set.h \
    data/type_voltage_set.h \
    data_registers/segment_time_data_general.h \
    data_registers/segment_time_data_detailed.h \
    data/register_data_object.h \
    data_registers/segment_voltage_setpoint.h \
    data_registers/segment_current_setpoint.h \
    data/type_current_voltage_prescale.h \
    data/type_current_factor.h \
    data/fault_codes_register_one.h \
    data/fault_codes_register_two.h \
    data/fault_codes_register_three.h \
    data_registers/parameter_memory_write.h \
    data_response/fault_register_one.h \
    data_response/fault_register_three.h \
    data_response/fault_register_two.h \
    data_response/valid_response.h \
    data_response/exception_response.h \
    data/type_response_exception.h

# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/library_munk_power_supply.lib release/library_munk_power_supply.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/library_munk_power_supply.lib debug/library_munk_power_supply.dll
INSTALLS += lib

#Header file copy
headers.path    = $$(ECM_ROOT)/include/library_munk_power_supply
headers.files   += \
    munk_power_supply.h\
    library_munk_power_supply_global.h
INSTALLS       += headers

#Header file copy
headers_data.path    = $$(ECM_ROOT)/include/library_munk_power_supply/data
headers_data.files   += \
    data/type_prescalar_power.h \
    data/type_read_write.h \
    data/type_segment_level.h \
    data/type_segment_mode.h
INSTALLS       += headers_data

#Header file copy
headers_data_registers.path    = $$(ECM_ROOT)/include/library_munk_power_supply/data_registers
headers_data_registers.files   += \
    data_registers/abstract_parameter.h \
    data_registers/segment_time_data.h \
    data_registers/segment_time_detailed.h \
    data_registers/segment_time_general.h \
    data_registers/type_definition.h
INSTALLS       += headers_data_registers

INCLUDEPATH += $$PWD/../

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon
