/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[604];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 40), // "on_pushButton_ConnectSerialPo..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 42), // "on_pushButton_ConfigureSerial..."
QT_MOC_LITERAL(4, 96, 36), // "on_pushButton_GenerateValid_r..."
QT_MOC_LITERAL(5, 133, 38), // "on_pushButton_GenerateInvalid..."
QT_MOC_LITERAL(6, 172, 16), // "onNewCurrentData"
QT_MOC_LITERAL(7, 189, 37), // "DataParameter::SegmentCurrent..."
QT_MOC_LITERAL(8, 227, 18), // "currentSetpointREV"
QT_MOC_LITERAL(9, 246, 18), // "currentSetpointFWD"
QT_MOC_LITERAL(10, 265, 16), // "onNewVoltageData"
QT_MOC_LITERAL(11, 282, 37), // "DataParameter::SegmentVoltage..."
QT_MOC_LITERAL(12, 320, 18), // "voltageSetpointREV"
QT_MOC_LITERAL(13, 339, 18), // "voltageSetpointFWD"
QT_MOC_LITERAL(14, 358, 16), // "onNewGeneralData"
QT_MOC_LITERAL(15, 375, 33), // "DataParameter::SegmentTimeGen..."
QT_MOC_LITERAL(16, 409, 11), // "segmentTime"
QT_MOC_LITERAL(17, 421, 31), // "on_pushButton_SendRevI_released"
QT_MOC_LITERAL(18, 453, 29), // "on_pushButton_SendFI_released"
QT_MOC_LITERAL(19, 483, 29), // "on_pushButton_SendRV_released"
QT_MOC_LITERAL(20, 513, 29), // "on_pushButton_SendFV_released"
QT_MOC_LITERAL(21, 543, 31), // "on_pushButton_SendData_released"
QT_MOC_LITERAL(22, 575, 22), // "onChanged_voltageValue"
QT_MOC_LITERAL(23, 598, 5) // "value"

    },
    "MainWindow\0on_pushButton_ConnectSerialPort_released\0"
    "\0on_pushButton_ConfigureSerialPort_released\0"
    "on_pushButton_GenerateValid_released\0"
    "on_pushButton_GenerateInvalid_released\0"
    "onNewCurrentData\0DataParameter::SegmentCurrentSetpoint\0"
    "currentSetpointREV\0currentSetpointFWD\0"
    "onNewVoltageData\0DataParameter::SegmentVoltageSetpoint\0"
    "voltageSetpointREV\0voltageSetpointFWD\0"
    "onNewGeneralData\0DataParameter::SegmentTimeGeneral\0"
    "segmentTime\0on_pushButton_SendRevI_released\0"
    "on_pushButton_SendFI_released\0"
    "on_pushButton_SendRV_released\0"
    "on_pushButton_SendFV_released\0"
    "on_pushButton_SendData_released\0"
    "onChanged_voltageValue\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    2,   83,    2, 0x08 /* Private */,
      10,    2,   88,    2, 0x08 /* Private */,
      14,    1,   93,    2, 0x08 /* Private */,
      17,    0,   96,    2, 0x08 /* Private */,
      18,    0,   97,    2, 0x08 /* Private */,
      19,    0,   98,    2, 0x08 /* Private */,
      20,    0,   99,    2, 0x08 /* Private */,
      21,    0,  100,    2, 0x08 /* Private */,
      22,    1,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,   12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   23,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_ConnectSerialPort_released(); break;
        case 1: _t->on_pushButton_ConfigureSerialPort_released(); break;
        case 2: _t->on_pushButton_GenerateValid_released(); break;
        case 3: _t->on_pushButton_GenerateInvalid_released(); break;
        case 4: _t->onNewCurrentData((*reinterpret_cast< const DataParameter::SegmentCurrentSetpoint(*)>(_a[1])),(*reinterpret_cast< const DataParameter::SegmentCurrentSetpoint(*)>(_a[2]))); break;
        case 5: _t->onNewVoltageData((*reinterpret_cast< const DataParameter::SegmentVoltageSetpoint(*)>(_a[1])),(*reinterpret_cast< const DataParameter::SegmentVoltageSetpoint(*)>(_a[2]))); break;
        case 6: _t->onNewGeneralData((*reinterpret_cast< const DataParameter::SegmentTimeGeneral(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_SendRevI_released(); break;
        case 8: _t->on_pushButton_SendFI_released(); break;
        case 9: _t->on_pushButton_SendRV_released(); break;
        case 10: _t->on_pushButton_SendFV_released(); break;
        case 11: _t->on_pushButton_SendData_released(); break;
        case 12: _t->onChanged_voltageValue((*reinterpret_cast< const double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
