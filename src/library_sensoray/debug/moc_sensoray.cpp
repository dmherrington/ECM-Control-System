/****************************************************************************
** Meta object code from reading C++ file 'sensoray.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sensoray.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sensoray.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Sensoray_t {
    QByteArrayData data[5];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sensoray_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sensoray_t qt_meta_stringdata_Sensoray = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Sensoray"
QT_MOC_LITERAL(1, 9, 21), // "ReceivedSerialMessage"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "msg"
QT_MOC_LITERAL(4, 36, 16) // "ConnectionStatus"

    },
    "Sensoray\0ReceivedSerialMessage\0\0msg\0"
    "ConnectionStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sensoray[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    0,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,

       0        // eod
};

void Sensoray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sensoray *_t = static_cast<Sensoray *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReceivedSerialMessage((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->ConnectionStatus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Sensoray::*_t)(const QByteArray & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::ReceivedSerialMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Sensoray::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::ConnectionStatus)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Sensoray::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Sensoray.data,
      qt_meta_data_Sensoray,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Sensoray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sensoray::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sensoray.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "comms::CommsEvents"))
        return static_cast< comms::CommsEvents*>(this);
    return QObject::qt_metacast(_clname);
}

int Sensoray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Sensoray::ReceivedSerialMessage(const QByteArray & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Sensoray::ConnectionStatus()const
{
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
