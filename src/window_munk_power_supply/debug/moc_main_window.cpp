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
    QByteArrayData data[32];
    char stringdata0[630];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "slot_ConnectionStatusUpdate"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 10), // "open_close"
QT_MOC_LITERAL(4, 51, 23), // "slot_CommunicationError"
QT_MOC_LITERAL(5, 75, 11), // "std::string"
QT_MOC_LITERAL(6, 87, 4), // "type"
QT_MOC_LITERAL(7, 92, 3), // "msg"
QT_MOC_LITERAL(8, 96, 24), // "slot_CommunicationUpdate"
QT_MOC_LITERAL(9, 121, 4), // "name"
QT_MOC_LITERAL(10, 126, 18), // "slot_SegmentSetAck"
QT_MOC_LITERAL(11, 145, 21), // "slot_SegmentException"
QT_MOC_LITERAL(12, 167, 2), // "RW"
QT_MOC_LITERAL(13, 170, 7), // "meaning"
QT_MOC_LITERAL(14, 178, 22), // "slot_FaultCodeRecieved"
QT_MOC_LITERAL(15, 201, 6), // "regNum"
QT_MOC_LITERAL(16, 208, 25), // "slot_WriteProgressUpdated"
QT_MOC_LITERAL(17, 234, 9), // "completed"
QT_MOC_LITERAL(18, 244, 8), // "required"
QT_MOC_LITERAL(19, 253, 31), // "widgetSegmentDisplay_dataUpdate"
QT_MOC_LITERAL(20, 285, 50), // "std::list<registers_Munk::Seg..."
QT_MOC_LITERAL(21, 336, 7), // "newData"
QT_MOC_LITERAL(22, 344, 33), // "on_pushButton_AddSegment_rele..."
QT_MOC_LITERAL(23, 378, 23), // "on_actionLoad_triggered"
QT_MOC_LITERAL(24, 402, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(25, 426, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(26, 453, 34), // "on_actionOpen_Connection_trig..."
QT_MOC_LITERAL(27, 488, 35), // "on_actionClose_Connection_tri..."
QT_MOC_LITERAL(28, 524, 35), // "on_actionTransmit_To_Munk_tri..."
QT_MOC_LITERAL(29, 560, 13), // "onGraphLegend"
QT_MOC_LITERAL(30, 574, 31), // "on_pushButton_transmit_released"
QT_MOC_LITERAL(31, 606, 23) // "on_actionExit_triggered"

    },
    "MainWindow\0slot_ConnectionStatusUpdate\0"
    "\0open_close\0slot_CommunicationError\0"
    "std::string\0type\0msg\0slot_CommunicationUpdate\0"
    "name\0slot_SegmentSetAck\0slot_SegmentException\0"
    "RW\0meaning\0slot_FaultCodeRecieved\0"
    "regNum\0slot_WriteProgressUpdated\0"
    "completed\0required\0widgetSegmentDisplay_dataUpdate\0"
    "std::list<registers_Munk::SegmentTimeDataDetailed>\0"
    "newData\0on_pushButton_AddSegment_released\0"
    "on_actionLoad_triggered\0on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionOpen_Connection_triggered\0"
    "on_actionClose_Connection_triggered\0"
    "on_actionTransmit_To_Munk_triggered\0"
    "onGraphLegend\0on_pushButton_transmit_released\0"
    "on_actionExit_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x08 /* Private */,
       4,    2,  107,    2, 0x08 /* Private */,
       8,    2,  112,    2, 0x08 /* Private */,
      10,    1,  117,    2, 0x08 /* Private */,
      11,    2,  120,    2, 0x08 /* Private */,
      14,    2,  125,    2, 0x08 /* Private */,
      16,    2,  130,    2, 0x08 /* Private */,
      19,    1,  135,    2, 0x08 /* Private */,
      22,    0,  138,    2, 0x08 /* Private */,
      23,    0,  139,    2, 0x08 /* Private */,
      24,    0,  140,    2, 0x08 /* Private */,
      25,    0,  141,    2, 0x08 /* Private */,
      26,    0,  142,    2, 0x08 /* Private */,
      27,    0,  143,    2, 0x08 /* Private */,
      28,    0,  144,    2, 0x08 /* Private */,
      29,    0,  145,    2, 0x08 /* Private */,
      30,    0,  146,    2, 0x08 /* Private */,
      31,    0,  147,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    9,    7,
    QMetaType::Void, 0x80000000 | 5,    7,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,   12,   13,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,   15,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
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
        case 0: _t->slot_ConnectionStatusUpdate((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->slot_CommunicationError((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 2: _t->slot_CommunicationUpdate((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 3: _t->slot_SegmentSetAck((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 4: _t->slot_SegmentException((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 5: _t->slot_FaultCodeRecieved((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 6: _t->slot_WriteProgressUpdated((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 7: _t->widgetSegmentDisplay_dataUpdate((*reinterpret_cast< const std::list<registers_Munk::SegmentTimeDataDetailed>(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_AddSegment_released(); break;
        case 9: _t->on_actionLoad_triggered(); break;
        case 10: _t->on_actionSave_triggered(); break;
        case 11: _t->on_actionSave_As_triggered(); break;
        case 12: _t->on_actionOpen_Connection_triggered(); break;
        case 13: _t->on_actionClose_Connection_triggered(); break;
        case 14: _t->on_actionTransmit_To_Munk_triggered(); break;
        case 15: _t->onGraphLegend(); break;
        case 16: _t->on_pushButton_transmit_released(); break;
        case 17: _t->on_actionExit_triggered(); break;
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
