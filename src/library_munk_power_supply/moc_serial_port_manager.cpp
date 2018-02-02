/****************************************************************************
** Meta object code from reading C++ file 'serial_port_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "serial_port_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial_port_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPortManager_t {
    QByteArrayData data[12];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortManager_t qt_meta_stringdata_SerialPortManager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SerialPortManager"
QT_MOC_LITERAL(1, 18, 13), // "bytesReceived"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "data"
QT_MOC_LITERAL(4, 38, 10), // "writeBytes"
QT_MOC_LITERAL(5, 49, 9), // "writeData"
QT_MOC_LITERAL(6, 59, 18), // "handleBytesWritten"
QT_MOC_LITERAL(7, 78, 5), // "bytes"
QT_MOC_LITERAL(8, 84, 13), // "handleTimeout"
QT_MOC_LITERAL(9, 98, 11), // "handleError"
QT_MOC_LITERAL(10, 110, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(11, 139, 5) // "error"

    },
    "SerialPortManager\0bytesReceived\0\0data\0"
    "writeBytes\0writeData\0handleBytesWritten\0"
    "bytes\0handleTimeout\0handleError\0"
    "QSerialPort::SerialPortError\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x08 /* Private */,
       6,    1,   45,    2, 0x08 /* Private */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::LongLong,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void SerialPortManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortManager *_t = static_cast<SerialPortManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bytesReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->writeBytes((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->handleBytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->handleTimeout(); break;
        case 4: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SerialPortManager::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialPortManager::bytesReceived)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SerialPortManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialPortManager.data,
      qt_meta_data_SerialPortManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialPortManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortManager.stringdata0))
        return static_cast<void*>(const_cast< SerialPortManager*>(this));
    return QObject::qt_metacast(_clname);
}

int SerialPortManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SerialPortManager::bytesReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
