/****************************************************************************
** Meta object code from reading C++ file 'ECM_controller_gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ECM_controller_gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ECM_controller_gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ECMControllerGUI_t {
    QByteArrayData data[8];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ECMControllerGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ECMControllerGUI_t qt_meta_stringdata_ECMControllerGUI = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ECMControllerGUI"
QT_MOC_LITERAL(1, 17, 18), // "slot_NewSensorData"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 25), // "common::TupleSensorString"
QT_MOC_LITERAL(4, 63, 6), // "sensor"
QT_MOC_LITERAL(5, 70, 17), // "data::SensorState"
QT_MOC_LITERAL(6, 88, 5), // "state"
QT_MOC_LITERAL(7, 94, 34) // "on_pushButton_MotorEnable_rel..."

    },
    "ECMControllerGUI\0slot_NewSensorData\0"
    "\0common::TupleSensorString\0sensor\0"
    "data::SensorState\0state\0"
    "on_pushButton_MotorEnable_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ECMControllerGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x08 /* Private */,
       7,    0,   29,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

       0        // eod
};

void ECMControllerGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ECMControllerGUI *_t = static_cast<ECMControllerGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_NewSensorData((*reinterpret_cast< const common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< const data::SensorState(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_MotorEnable_released(); break;
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
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< data::SensorState >(); break;
            }
            break;
        }
    }
}

const QMetaObject ECMControllerGUI::staticMetaObject = {
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
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
