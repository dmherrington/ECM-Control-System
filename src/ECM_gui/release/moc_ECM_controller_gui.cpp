/****************************************************************************
** Meta object code from reading C++ file 'ECM_controller_gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ECM_controller_gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ECM_controller_gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ECMControllerGUI_t {
    QByteArrayData data[80];
    char stringdata0[2063];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ECMControllerGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ECMControllerGUI_t qt_meta_stringdata_ECMControllerGUI = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ECMControllerGUI"
QT_MOC_LITERAL(1, 17, 20), // "CreateSensorDisplays"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 25), // "common::TupleSensorString"
QT_MOC_LITERAL(4, 65, 6), // "sensor"
QT_MOC_LITERAL(5, 72, 24), // "common_data::SensorTypes"
QT_MOC_LITERAL(6, 97, 4), // "type"
QT_MOC_LITERAL(7, 102, 26), // "MarshalCreateSensorDisplay"
QT_MOC_LITERAL(8, 129, 28), // "slot_NewlyAvailableRigolData"
QT_MOC_LITERAL(9, 158, 3), // "val"
QT_MOC_LITERAL(10, 162, 17), // "slot_AddPlottable"
QT_MOC_LITERAL(11, 180, 20), // "common::TupleECMData"
QT_MOC_LITERAL(12, 201, 4), // "data"
QT_MOC_LITERAL(13, 206, 4), // "plot"
QT_MOC_LITERAL(14, 211, 20), // "slot_RemovePlottable"
QT_MOC_LITERAL(15, 232, 27), // "slot_DisplayActionTriggered"
QT_MOC_LITERAL(16, 260, 30), // "slot_UpdatedMotionProfileState"
QT_MOC_LITERAL(17, 291, 18), // "MotionProfileState"
QT_MOC_LITERAL(18, 310, 5), // "state"
QT_MOC_LITERAL(19, 316, 27), // "slot_NewProfileVariableData"
QT_MOC_LITERAL(20, 344, 34), // "common::TupleProfileVariableS..."
QT_MOC_LITERAL(21, 379, 8), // "variable"
QT_MOC_LITERAL(22, 388, 39), // "common_data::MotionProfileVar..."
QT_MOC_LITERAL(23, 428, 18), // "slot_NewSensorData"
QT_MOC_LITERAL(24, 447, 24), // "common_data::SensorState"
QT_MOC_LITERAL(25, 472, 22), // "slot_NewPositionalData"
QT_MOC_LITERAL(26, 495, 29), // "common::TuplePositionalString"
QT_MOC_LITERAL(27, 525, 5), // "tuple"
QT_MOC_LITERAL(28, 531, 35), // "common_data::MachinePositiona..."
QT_MOC_LITERAL(29, 567, 21), // "slot_MCNewMotionState"
QT_MOC_LITERAL(30, 589, 11), // "std::string"
QT_MOC_LITERAL(31, 601, 22), // "slot_MCNewDigitalInput"
QT_MOC_LITERAL(32, 624, 12), // "StatusInputs"
QT_MOC_LITERAL(33, 637, 6), // "status"
QT_MOC_LITERAL(34, 644, 23), // "slot_MCNewProgramLabels"
QT_MOC_LITERAL(35, 668, 16), // "ProgramLabelList"
QT_MOC_LITERAL(36, 685, 6), // "labels"
QT_MOC_LITERAL(37, 692, 29), // "slot_MCNEWProgramVariableList"
QT_MOC_LITERAL(38, 722, 19), // "ProgramVariableList"
QT_MOC_LITERAL(39, 742, 9), // "variables"
QT_MOC_LITERAL(40, 752, 24), // "slot_UpdateHomeIndicated"
QT_MOC_LITERAL(41, 777, 5), // "value"
QT_MOC_LITERAL(42, 783, 34), // "on_pushButton_MotorEnable_rel..."
QT_MOC_LITERAL(43, 818, 35), // "on_pushButton_MotorDisable_re..."
QT_MOC_LITERAL(44, 854, 32), // "on_pushButton_ResetHome_released"
QT_MOC_LITERAL(45, 887, 31), // "on_pushButton_MoveHome_released"
QT_MOC_LITERAL(46, 919, 40), // "on_pushButton_EstablishToucho..."
QT_MOC_LITERAL(47, 960, 33), // "on_pushButton_IncreaseJog_pre..."
QT_MOC_LITERAL(48, 994, 34), // "on_pushButton_IncreaseJog_rel..."
QT_MOC_LITERAL(49, 1029, 33), // "on_pushButton_DecreaseJog_pre..."
QT_MOC_LITERAL(50, 1063, 34), // "on_pushButton_DecreaseJog_rel..."
QT_MOC_LITERAL(51, 1098, 43), // "on_pushButton_IncreaseRelativ..."
QT_MOC_LITERAL(52, 1142, 43), // "on_pushButton_DecreaseRelativ..."
QT_MOC_LITERAL(53, 1186, 41), // "on_doubleSpinBox_CutDepth_edi..."
QT_MOC_LITERAL(54, 1228, 48), // "on_doubleSpinBox_RetractDista..."
QT_MOC_LITERAL(55, 1277, 41), // "on_doubleSpinBox_StepSize_edi..."
QT_MOC_LITERAL(56, 1319, 39), // "on_spinBox_RetractSpeed_editi..."
QT_MOC_LITERAL(57, 1359, 38), // "on_spinBox_PlungeSpeed_editin..."
QT_MOC_LITERAL(58, 1398, 41), // "on_doubleSpinBox_CutSpeed_edi..."
QT_MOC_LITERAL(59, 1440, 40), // "on_spinBox_RetractPeriod_edit..."
QT_MOC_LITERAL(60, 1481, 32), // "on_spinBox_Pause_editingFinished"
QT_MOC_LITERAL(61, 1514, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(62, 1539, 28), // "slot_ChangedWindowVisibility"
QT_MOC_LITERAL(63, 1568, 38), // "GeneralDialogWindow::DialogWi..."
QT_MOC_LITERAL(64, 1607, 10), // "visibility"
QT_MOC_LITERAL(65, 1618, 30), // "on_actionConnections_triggered"
QT_MOC_LITERAL(66, 1649, 7), // "checked"
QT_MOC_LITERAL(67, 1657, 23), // "on_actionPump_triggered"
QT_MOC_LITERAL(68, 1681, 31), // "on_actionPower_Supply_triggered"
QT_MOC_LITERAL(69, 1713, 31), // "on_actionOscilliscope_triggered"
QT_MOC_LITERAL(70, 1745, 27), // "on_actionTouchoff_triggered"
QT_MOC_LITERAL(71, 1773, 33), // "on_actionMotion_Profile_trigg..."
QT_MOC_LITERAL(72, 1807, 41), // "on_actionCustom_Motion_Comman..."
QT_MOC_LITERAL(73, 1849, 38), // "on_actionOpen_Sensors_Window_..."
QT_MOC_LITERAL(74, 1888, 33), // "on_actionClear_All_Data_trigg..."
QT_MOC_LITERAL(75, 1922, 41), // "on_pushButton_RunExplicitProf..."
QT_MOC_LITERAL(76, 1964, 42), // "on_pushButton_RunAutomatedPro..."
QT_MOC_LITERAL(77, 2007, 27), // "on_pushButton_Stop_released"
QT_MOC_LITERAL(78, 2035, 22), // "slot_LockMotionButtons"
QT_MOC_LITERAL(79, 2058, 4) // "lock"

    },
    "ECMControllerGUI\0CreateSensorDisplays\0"
    "\0common::TupleSensorString\0sensor\0"
    "common_data::SensorTypes\0type\0"
    "MarshalCreateSensorDisplay\0"
    "slot_NewlyAvailableRigolData\0val\0"
    "slot_AddPlottable\0common::TupleECMData\0"
    "data\0plot\0slot_RemovePlottable\0"
    "slot_DisplayActionTriggered\0"
    "slot_UpdatedMotionProfileState\0"
    "MotionProfileState\0state\0"
    "slot_NewProfileVariableData\0"
    "common::TupleProfileVariableString\0"
    "variable\0common_data::MotionProfileVariableState\0"
    "slot_NewSensorData\0common_data::SensorState\0"
    "slot_NewPositionalData\0"
    "common::TuplePositionalString\0tuple\0"
    "common_data::MachinePositionalState\0"
    "slot_MCNewMotionState\0std::string\0"
    "slot_MCNewDigitalInput\0StatusInputs\0"
    "status\0slot_MCNewProgramLabels\0"
    "ProgramLabelList\0labels\0"
    "slot_MCNEWProgramVariableList\0"
    "ProgramVariableList\0variables\0"
    "slot_UpdateHomeIndicated\0value\0"
    "on_pushButton_MotorEnable_released\0"
    "on_pushButton_MotorDisable_released\0"
    "on_pushButton_ResetHome_released\0"
    "on_pushButton_MoveHome_released\0"
    "on_pushButton_EstablishTouchoff_released\0"
    "on_pushButton_IncreaseJog_pressed\0"
    "on_pushButton_IncreaseJog_released\0"
    "on_pushButton_DecreaseJog_pressed\0"
    "on_pushButton_DecreaseJog_released\0"
    "on_pushButton_IncreaseRelativeMove_released\0"
    "on_pushButton_DecreaseRelativeMove_released\0"
    "on_doubleSpinBox_CutDepth_editingFinished\0"
    "on_doubleSpinBox_RetractDistance_editingFinished\0"
    "on_doubleSpinBox_StepSize_editingFinished\0"
    "on_spinBox_RetractSpeed_editingFinished\0"
    "on_spinBox_PlungeSpeed_editingFinished\0"
    "on_doubleSpinBox_CutSpeed_editingFinished\0"
    "on_spinBox_RetractPeriod_editingFinished\0"
    "on_spinBox_Pause_editingFinished\0"
    "on_actionClose_triggered\0"
    "slot_ChangedWindowVisibility\0"
    "GeneralDialogWindow::DialogWindowTypes\0"
    "visibility\0on_actionConnections_triggered\0"
    "checked\0on_actionPump_triggered\0"
    "on_actionPower_Supply_triggered\0"
    "on_actionOscilliscope_triggered\0"
    "on_actionTouchoff_triggered\0"
    "on_actionMotion_Profile_triggered\0"
    "on_actionCustom_Motion_Commands_triggered\0"
    "on_actionOpen_Sensors_Window_triggered\0"
    "on_actionClear_All_Data_triggered\0"
    "on_pushButton_RunExplicitProfile_released\0"
    "on_pushButton_RunAutomatedProfile_released\0"
    "on_pushButton_Stop_released\0"
    "slot_LockMotionButtons\0lock"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ECMControllerGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,  264,    2, 0x08 /* Private */,
       7,    2,  269,    2, 0x08 /* Private */,
       8,    2,  274,    2, 0x08 /* Private */,
      10,    2,  279,    2, 0x08 /* Private */,
      10,    1,  284,    2, 0x28 /* Private | MethodCloned */,
      14,    1,  287,    2, 0x08 /* Private */,
      15,    0,  290,    2, 0x08 /* Private */,
      16,    1,  291,    2, 0x08 /* Private */,
      19,    2,  294,    2, 0x08 /* Private */,
      23,    2,  299,    2, 0x08 /* Private */,
      25,    2,  304,    2, 0x08 /* Private */,
      29,    1,  309,    2, 0x08 /* Private */,
      31,    1,  312,    2, 0x08 /* Private */,
      34,    1,  315,    2, 0x08 /* Private */,
      37,    1,  318,    2, 0x08 /* Private */,
      40,    1,  321,    2, 0x08 /* Private */,
      42,    0,  324,    2, 0x08 /* Private */,
      43,    0,  325,    2, 0x08 /* Private */,
      44,    0,  326,    2, 0x08 /* Private */,
      45,    0,  327,    2, 0x08 /* Private */,
      46,    0,  328,    2, 0x08 /* Private */,
      47,    0,  329,    2, 0x08 /* Private */,
      48,    0,  330,    2, 0x08 /* Private */,
      49,    0,  331,    2, 0x08 /* Private */,
      50,    0,  332,    2, 0x08 /* Private */,
      51,    0,  333,    2, 0x08 /* Private */,
      52,    0,  334,    2, 0x08 /* Private */,
      53,    0,  335,    2, 0x08 /* Private */,
      54,    0,  336,    2, 0x08 /* Private */,
      55,    0,  337,    2, 0x08 /* Private */,
      56,    0,  338,    2, 0x08 /* Private */,
      57,    0,  339,    2, 0x08 /* Private */,
      58,    0,  340,    2, 0x08 /* Private */,
      59,    0,  341,    2, 0x08 /* Private */,
      60,    0,  342,    2, 0x08 /* Private */,
      61,    0,  343,    2, 0x08 /* Private */,
      62,    2,  344,    2, 0x08 /* Private */,
      65,    1,  349,    2, 0x08 /* Private */,
      67,    1,  352,    2, 0x08 /* Private */,
      68,    1,  355,    2, 0x08 /* Private */,
      69,    1,  358,    2, 0x08 /* Private */,
      70,    1,  361,    2, 0x08 /* Private */,
      71,    1,  364,    2, 0x08 /* Private */,
      72,    1,  367,    2, 0x08 /* Private */,
      73,    1,  370,    2, 0x08 /* Private */,
      74,    0,  373,    2, 0x08 /* Private */,
      75,    0,  374,    2, 0x08 /* Private */,
      76,    0,  375,    2, 0x08 /* Private */,
      77,    0,  376,    2, 0x08 /* Private */,
      78,    1,  377,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Bool,   12,   13,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 22,   21,   18,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 24,    4,   18,
    QMetaType::Void, 0x80000000 | 26, 0x80000000 | 28,   27,   18,
    QMetaType::Void, 0x80000000 | 30,   18,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void, QMetaType::Bool,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 63, QMetaType::Bool,    6,   64,
    QMetaType::Void, QMetaType::Bool,   66,
    QMetaType::Void, QMetaType::Bool,   66,
    QMetaType::Void, QMetaType::Bool,   66,
    QMetaType::Void, QMetaType::Bool,   66,
    QMetaType::Void, QMetaType::Bool,   66,
    QMetaType::Void, QMetaType::Bool,   66,
    QMetaType::Void, QMetaType::Bool,   66,
    QMetaType::Void, QMetaType::Bool,   66,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   79,

       0        // eod
};

void ECMControllerGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ECMControllerGUI *_t = static_cast<ECMControllerGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateSensorDisplays((*reinterpret_cast< const common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< const common_data::SensorTypes(*)>(_a[2]))); break;
        case 1: _t->MarshalCreateSensorDisplay((*reinterpret_cast< const common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< const common_data::SensorTypes(*)>(_a[2]))); break;
        case 2: _t->slot_NewlyAvailableRigolData((*reinterpret_cast< const common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 3: _t->slot_AddPlottable((*reinterpret_cast< const common::TupleECMData(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 4: _t->slot_AddPlottable((*reinterpret_cast< const common::TupleECMData(*)>(_a[1]))); break;
        case 5: _t->slot_RemovePlottable((*reinterpret_cast< const common::TupleECMData(*)>(_a[1]))); break;
        case 6: _t->slot_DisplayActionTriggered(); break;
        case 7: _t->slot_UpdatedMotionProfileState((*reinterpret_cast< const MotionProfileState(*)>(_a[1]))); break;
        case 8: _t->slot_NewProfileVariableData((*reinterpret_cast< const common::TupleProfileVariableString(*)>(_a[1])),(*reinterpret_cast< const common_data::MotionProfileVariableState(*)>(_a[2]))); break;
        case 9: _t->slot_NewSensorData((*reinterpret_cast< const common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< const common_data::SensorState(*)>(_a[2]))); break;
        case 10: _t->slot_NewPositionalData((*reinterpret_cast< const common::TuplePositionalString(*)>(_a[1])),(*reinterpret_cast< const common_data::MachinePositionalState(*)>(_a[2]))); break;
        case 11: _t->slot_MCNewMotionState((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 12: _t->slot_MCNewDigitalInput((*reinterpret_cast< const StatusInputs(*)>(_a[1]))); break;
        case 13: _t->slot_MCNewProgramLabels((*reinterpret_cast< const ProgramLabelList(*)>(_a[1]))); break;
        case 14: _t->slot_MCNEWProgramVariableList((*reinterpret_cast< const ProgramVariableList(*)>(_a[1]))); break;
        case 15: _t->slot_UpdateHomeIndicated((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 16: _t->on_pushButton_MotorEnable_released(); break;
        case 17: _t->on_pushButton_MotorDisable_released(); break;
        case 18: _t->on_pushButton_ResetHome_released(); break;
        case 19: _t->on_pushButton_MoveHome_released(); break;
        case 20: _t->on_pushButton_EstablishTouchoff_released(); break;
        case 21: _t->on_pushButton_IncreaseJog_pressed(); break;
        case 22: _t->on_pushButton_IncreaseJog_released(); break;
        case 23: _t->on_pushButton_DecreaseJog_pressed(); break;
        case 24: _t->on_pushButton_DecreaseJog_released(); break;
        case 25: _t->on_pushButton_IncreaseRelativeMove_released(); break;
        case 26: _t->on_pushButton_DecreaseRelativeMove_released(); break;
        case 27: _t->on_doubleSpinBox_CutDepth_editingFinished(); break;
        case 28: _t->on_doubleSpinBox_RetractDistance_editingFinished(); break;
        case 29: _t->on_doubleSpinBox_StepSize_editingFinished(); break;
        case 30: _t->on_spinBox_RetractSpeed_editingFinished(); break;
        case 31: _t->on_spinBox_PlungeSpeed_editingFinished(); break;
        case 32: _t->on_doubleSpinBox_CutSpeed_editingFinished(); break;
        case 33: _t->on_spinBox_RetractPeriod_editingFinished(); break;
        case 34: _t->on_spinBox_Pause_editingFinished(); break;
        case 35: _t->on_actionClose_triggered(); break;
        case 36: _t->slot_ChangedWindowVisibility((*reinterpret_cast< const GeneralDialogWindow::DialogWindowTypes(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 37: _t->on_actionConnections_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->on_actionPump_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->on_actionPower_Supply_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->on_actionOscilliscope_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->on_actionTouchoff_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->on_actionMotion_Profile_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->on_actionCustom_Motion_Commands_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->on_actionOpen_Sensors_Window_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->on_actionClear_All_Data_triggered(); break;
        case 46: _t->on_pushButton_RunExplicitProfile_released(); break;
        case 47: _t->on_pushButton_RunAutomatedProfile_released(); break;
        case 48: _t->on_pushButton_Stop_released(); break;
        case 49: _t->slot_LockMotionButtons((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleSensorString >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleSensorString >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleSensorString >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleECMData >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleECMData >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleECMData >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MotionProfileState >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleProfileVariableString >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common_data::MotionProfileVariableState >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleSensorString >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common_data::SensorState >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TuplePositionalString >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common_data::MachinePositionalState >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ECMControllerGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ECMControllerGUI.data,
      qt_meta_data_ECMControllerGUI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ECMControllerGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ECMControllerGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ECMControllerGUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ECMControllerGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
