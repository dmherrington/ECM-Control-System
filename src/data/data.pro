#-------------------------------------------------
#
# Project created by QtCreator 2018-03-09T13:50:10
#
#-------------------------------------------------

QT       -= gui
QT += core

TARGET = data
TEMPLATE = lib

DEFINES += DATA_LIBRARY

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
    sensor_collection.cpp \
    sensor_state.cpp \
    dimensions/time_dimension.cpp \
    dimensions/voltage_dimension.cpp \
    observation/observation_collection.cpp \
    observation/observation_scalar.cpp \
    sensors/sensor.cpp \
    sensors/sensor_voltage.cpp \
    measurement_state.cpp \
    motion_profile_state.cpp \
    profiles/profile_touchoff.cpp \
    profiles/profile_homing.cpp \
    sensors/sensor_marea.cpp \
    dimensions/marea_dimension.cpp \
    profiles/profile_state_machining.cpp \
    motion_profile_variable_state.cpp \
    machine_positional_state.cpp \
    dimensions/position_dimension.cpp

HEADERS += \
    data_global.h \
    sensor_collection.h \
    sensor_state.h \
    dimensions/dimension.h \
    dimensions/time_dimension.h \
    dimensions/voltage_dimension.h \
    observation/cartesian_data.h \
    observation/cartesian_evaluation_parameters.h \
    observation/I_observation.h \
    observation/I_plot_comparable.h \
    observation/I_time_data.h \
    observation/number_systems.h \
    observation/observation_collection.h \
    observation/observation_ID_reference.h \
    observation/observation_scalar.h \
    observation/time_data_reference.h \
    sensors/sensor.h \
    sensors/sensor_voltage.h \
    digital_state.h \
    motion_profile_state.h \
    profiles/profile_state_homing.h \
    profiles/profile_state_touchoff.h \
    sensors/sensor_marea.h \
    dimensions/marea_dimension.h \
    profiles/profile_state_machining.h \
    motion_profile_variable_state.h \
    machine_positional_state.h \
    dimensions/position_dimension.h

# Unix lib Install
unix:!symbian {
    target.path = $$(ECM_ROOT)/lib
    INSTALLS += target
}

# Windows lib install
lib.path    = $$(ECM_ROOT)/lib
win32:CONFIG(release, debug|release):       lib.files   += release/data.lib release/data.dll
else:win32:CONFIG(debug, debug|release):    lib.files   += debug/data.lib debug/data.dll
INSTALLS += lib

#Header file copy
headers_common_data.path    = $$(ECM_ROOT)/include/data
headers_common_data.files   += \
        data_global.h \
        measurement_state.h \
        sensor_collection.h \
        sensor_state.h
INSTALLS       += headers_common_data

#Header file copy
headers_data_dimensions.path    = $$(ECM_ROOT)/include/data/dimensions
headers_data_dimensions.files   += \
    dimensions/dimension.h \
    dimensions/time_dimension.h \
    dimensions/voltage_dimension.h
INSTALLS       += headers_data_dimensions

#Header file copy
headers_data_observations.path    = $$(ECM_ROOT)/include/data/observation
headers_data_observations.files   += \
    observation/cartesian_data.h \
    observation/cartesian_evaluation_parameters.h \
    observation/I_observation.h \
    observation/I_plot_comparable.h \
    observation/I_time_data.h \
    observation/number_systems.h \
    observation/observation_collection.h \
    observation/observation_ID_reference.h \
    observation/observation_scalar.h \
    observation/time_data_reference.h
INSTALLS       += headers_data_observations

#Header file copy
headers_data_sensors.path    = $$(ECM_ROOT)/include/data/sensors
headers_data_sensors.files   += \
    sensors/sensor.h \
    sensors/sensor_voltage.h
INSTALLS       += headers_data_sensors

INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$(ECM_ROOT)/include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix:!macx: LIBS += -L$$OUT_PWD/../common/ -lcommon
