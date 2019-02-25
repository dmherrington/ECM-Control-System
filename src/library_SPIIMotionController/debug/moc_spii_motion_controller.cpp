/****************************************************************************
** Meta object code from reading C++ file 'spii_motion_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../spii_motion_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spii_motion_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SPIIMotionController_t {
    QByteArrayData data[5];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SPIIMotionController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SPIIMotionController_t qt_meta_stringdata_SPIIMotionController = {
    {
QT_MOC_LITERAL(0, 0, 20), // "SPIIMotionController"
QT_MOC_LITERAL(1, 21, 28), // "signal_MCCommunicationUpdate"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(4, 86, 10) // "connection"

    },
    "SPIIMotionController\0signal_MCCommunicationUpdate\0"
    "\0common::comms::CommunicationUpdate\0"
    "connection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SPIIMotionController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void SPIIMotionController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SPIIMotionController *_t = static_cast<SPIIMotionController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_MCCommunicationUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::comms::CommunicationUpdate >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SPIIMotionController::*)(const common::comms::CommunicationUpdate & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCCommunicationUpdate)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SPIIMotionController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SPIIMotionController.data,
      qt_meta_data_SPIIMotionController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SPIIMotionController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SPIIMotionController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SPIIMotionController.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "SPIIDeviceInterface_MotionControl"))
        return static_cast< SPIIDeviceInterface_MotionControl*>(this);
    return QObject::qt_metacast(_clname);
}

int SPIIMotionController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void SPIIMotionController::signal_MCCommunicationUpdate(const common::comms::CommunicationUpdate & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
