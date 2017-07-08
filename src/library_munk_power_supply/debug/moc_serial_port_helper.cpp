/****************************************************************************
** Meta object code from reading C++ file 'serial_port_helper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../serial_port_helper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial_port_helper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialPortHelper_t {
    QByteArrayData data[10];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortHelper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortHelper_t qt_meta_stringdata_SerialPortHelper = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SerialPortHelper"
QT_MOC_LITERAL(1, 17, 13), // "bytesReceived"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "data"
QT_MOC_LITERAL(4, 37, 18), // "handleBytesWritten"
QT_MOC_LITERAL(5, 56, 5), // "bytes"
QT_MOC_LITERAL(6, 62, 13), // "handleTimeout"
QT_MOC_LITERAL(7, 76, 11), // "handleError"
QT_MOC_LITERAL(8, 88, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(9, 117, 5) // "error"

    },
    "SerialPortHelper\0bytesReceived\0\0data\0"
    "handleBytesWritten\0bytes\0handleTimeout\0"
    "handleError\0QSerialPort::SerialPortError\0"
    "error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,
       6,    0,   40,    2, 0x08 /* Private */,
       7,    1,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void SerialPortHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortHelper *_t = static_cast<SerialPortHelper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->bytesReceived((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: _t->handleBytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->handleTimeout(); break;
        case 3: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef int (SerialPortHelper::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialPortHelper::bytesReceived)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SerialPortHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialPortHelper.data,
      qt_meta_data_SerialPortHelper,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SerialPortHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortHelper.stringdata0))
        return static_cast<void*>(const_cast< SerialPortHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int SerialPortHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
int SerialPortHelper::bytesReceived(const QByteArray & _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
