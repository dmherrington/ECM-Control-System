/****************************************************************************
** Meta object code from reading C++ file 'observation_scalar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../observation/observation_scalar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'observation_scalar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_common_data__observation__ObservationScalar_t {
    QByteArrayData data[1];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_common_data__observation__ObservationScalar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_common_data__observation__ObservationScalar_t qt_meta_stringdata_common_data__observation__ObservationScalar = {
    {
QT_MOC_LITERAL(0, 0, 43) // "common_data::observation::Obs..."

    },
    "common_data::observation::ObservationScalar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_common_data__observation__ObservationScalar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void common_data::observation::ObservationScalar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject common_data::observation::ObservationScalar::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_common_data__observation__ObservationScalar.data,
      qt_meta_data_common_data__observation__ObservationScalar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *common_data::observation::ObservationScalar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *common_data::observation::ObservationScalar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_common_data__observation__ObservationScalar.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IObservation"))
        return static_cast< IObservation*>(this);
    return QObject::qt_metacast(_clname);
}

int common_data::observation::ObservationScalar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
