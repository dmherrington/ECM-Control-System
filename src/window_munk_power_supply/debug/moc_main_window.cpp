/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../main_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[289];
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
QT_MOC_LITERAL(6, 125, 6), // "onOpen"
QT_MOC_LITERAL(7, 132, 6), // "onSave"
QT_MOC_LITERAL(8, 139, 8), // "onSaveAs"
QT_MOC_LITERAL(9, 148, 6), // "onExit"
QT_MOC_LITERAL(10, 155, 13), // "onGraphLegend"
QT_MOC_LITERAL(11, 169, 31), // "on_pushButton_transmit_released"
QT_MOC_LITERAL(12, 201, 21), // "slot_SerialPortStatus"
QT_MOC_LITERAL(13, 223, 10), // "open_close"
QT_MOC_LITERAL(14, 234, 11), // "std::string"
QT_MOC_LITERAL(15, 246, 11), // "errorString"
QT_MOC_LITERAL(16, 258, 30) // "on_pushButton_connect_released"

    },
    "MainWindow\0on_pushButton_released\0\0"
    "widgetSegmentDisplay_dataUpdate\0"
    "std::list<DataParameter::SegmentTimeDataDetailed>\0"
    "newData\0onOpen\0onSave\0onSaveAs\0onExit\0"
    "onGraphLegend\0on_pushButton_transmit_released\0"
    "slot_SerialPortStatus\0open_close\0"
    "std::string\0errorString\0"
    "on_pushButton_connect_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    1,   65,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    2,   74,    2, 0x08 /* Private */,
      16,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 14,   13,   15,
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
        case 2: _t->onOpen(); break;
        case 3: _t->onSave(); break;
        case 4: _t->onSaveAs(); break;
        case 5: _t->onExit(); break;
        case 6: _t->onGraphLegend(); break;
        case 7: _t->on_pushButton_transmit_released(); break;
        case 8: _t->slot_SerialPortStatus((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 9: _t->on_pushButton_connect_released(); break;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
