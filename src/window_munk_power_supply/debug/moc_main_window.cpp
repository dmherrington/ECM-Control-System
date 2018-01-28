/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../main_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[519];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "on_pushButton_released"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 31), // "widgetSegmentDisplay_dataUpdate"
QT_MOC_LITERAL(4, 67, 49), // "std::list<DataParameter::Segm..."
QT_MOC_LITERAL(5, 117, 7), // "newData"
QT_MOC_LITERAL(6, 125, 21), // "slot_SerialPortStatus"
QT_MOC_LITERAL(7, 147, 10), // "open_close"
QT_MOC_LITERAL(8, 158, 11), // "std::string"
QT_MOC_LITERAL(9, 170, 11), // "errorString"
QT_MOC_LITERAL(10, 182, 27), // "slot_ConnectionStatusUpdate"
QT_MOC_LITERAL(11, 210, 23), // "slot_CommunicationError"
QT_MOC_LITERAL(12, 234, 24), // "slot_CommunicationUpdate"
QT_MOC_LITERAL(13, 259, 18), // "slot_SegmentSetAck"
QT_MOC_LITERAL(14, 278, 21), // "slot_SegmentException"
QT_MOC_LITERAL(15, 300, 22), // "slot_FaultCodeRecieved"
QT_MOC_LITERAL(16, 323, 23), // "on_actionLoad_triggered"
QT_MOC_LITERAL(17, 347, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(18, 371, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(19, 398, 34), // "on_actionOpen_Connection_trig..."
QT_MOC_LITERAL(20, 433, 35), // "on_actionClose_Connection_tri..."
QT_MOC_LITERAL(21, 469, 35), // "on_actionTransmit_To_Munk_tri..."
QT_MOC_LITERAL(22, 505, 13) // "onGraphLegend"

    },
    "MainWindow\0on_pushButton_released\0\0"
    "widgetSegmentDisplay_dataUpdate\0"
    "std::list<DataParameter::SegmentTimeDataDetailed>\0"
    "newData\0slot_SerialPortStatus\0open_close\0"
    "std::string\0errorString\0"
    "slot_ConnectionStatusUpdate\0"
    "slot_CommunicationError\0"
    "slot_CommunicationUpdate\0slot_SegmentSetAck\0"
    "slot_SegmentException\0slot_FaultCodeRecieved\0"
    "on_actionLoad_triggered\0on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionOpen_Connection_triggered\0"
    "on_actionClose_Connection_triggered\0"
    "on_actionTransmit_To_Munk_triggered\0"
    "onGraphLegend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    1,   95,    2, 0x08 /* Private */,
       6,    2,   98,    2, 0x08 /* Private */,
      10,    1,  103,    2, 0x08 /* Private */,
      11,    0,  106,    2, 0x08 /* Private */,
      12,    0,  107,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,
      19,    0,  114,    2, 0x08 /* Private */,
      20,    0,  115,    2, 0x08 /* Private */,
      21,    0,  116,    2, 0x08 /* Private */,
      22,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 8,    7,    9,
    QMetaType::Void, QMetaType::Bool,    7,
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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_released(); break;
        case 1: _t->widgetSegmentDisplay_dataUpdate((*reinterpret_cast< const std::list<DataParameter::SegmentTimeDataDetailed>(*)>(_a[1]))); break;
        case 2: _t->slot_SerialPortStatus((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 3: _t->slot_ConnectionStatusUpdate((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 4: _t->slot_CommunicationError(); break;
        case 5: _t->slot_CommunicationUpdate(); break;
        case 6: _t->slot_SegmentSetAck(); break;
        case 7: _t->slot_SegmentException(); break;
        case 8: _t->slot_FaultCodeRecieved(); break;
        case 9: _t->on_actionLoad_triggered(); break;
        case 10: _t->on_actionSave_triggered(); break;
        case 11: _t->on_actionSave_As_triggered(); break;
        case 12: _t->on_actionOpen_Connection_triggered(); break;
        case 13: _t->on_actionClose_Connection_triggered(); break;
        case 14: _t->on_actionTransmit_To_Munk_triggered(); break;
        case 15: _t->onGraphLegend(); break;
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
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
