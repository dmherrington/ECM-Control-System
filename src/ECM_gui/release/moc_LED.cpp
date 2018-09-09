/****************************************************************************
** Meta object code from reading C++ file 'LED.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LED.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LED.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LED_t {
    QByteArrayData data[25];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LED_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LED_t qt_meta_stringdata_LED = {
    {
QT_MOC_LITERAL(0, 0, 3), // "LED"
QT_MOC_LITERAL(1, 4, 17), // "toggleStateSignal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 18), // "setFlashingeSignal"
QT_MOC_LITERAL(4, 42, 8), // "flashing"
QT_MOC_LITERAL(5, 51, 18), // "stateChangedSignal"
QT_MOC_LITERAL(6, 70, 5), // "state"
QT_MOC_LITERAL(7, 76, 8), // "setState"
QT_MOC_LITERAL(8, 85, 11), // "toggleState"
QT_MOC_LITERAL(9, 97, 11), // "setFlashing"
QT_MOC_LITERAL(10, 109, 12), // "setFlashRate"
QT_MOC_LITERAL(11, 122, 4), // "rate"
QT_MOC_LITERAL(12, 127, 13), // "startFlashing"
QT_MOC_LITERAL(13, 141, 12), // "stopFlashing"
QT_MOC_LITERAL(14, 154, 14), // "setAlphaForOff"
QT_MOC_LITERAL(15, 169, 5), // "value"
QT_MOC_LITERAL(16, 175, 8), // "setColor"
QT_MOC_LITERAL(17, 184, 5), // "color"
QT_MOC_LITERAL(18, 190, 10), // "setVisible"
QT_MOC_LITERAL(19, 201, 7), // "visible"
QT_MOC_LITERAL(20, 209, 8), // "diameter"
QT_MOC_LITERAL(21, 218, 9), // "alignment"
QT_MOC_LITERAL(22, 228, 13), // "Qt::Alignment"
QT_MOC_LITERAL(23, 242, 9), // "flashRate"
QT_MOC_LITERAL(24, 252, 11) // "alphaForOff"

    },
    "LED\0toggleStateSignal\0\0setFlashingeSignal\0"
    "flashing\0stateChangedSignal\0state\0"
    "setState\0toggleState\0setFlashing\0"
    "setFlashRate\0rate\0startFlashing\0"
    "stopFlashing\0setAlphaForOff\0value\0"
    "setColor\0color\0setVisible\0visible\0"
    "diameter\0alignment\0Qt::Alignment\0"
    "flashRate\0alphaForOff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LED[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       7,  102, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,
       5,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   81,    2, 0x0a /* Public */,
       8,    0,   84,    2, 0x0a /* Public */,
       9,    1,   85,    2, 0x0a /* Public */,
      10,    1,   88,    2, 0x0a /* Public */,
      12,    0,   91,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      14,    1,   93,    2, 0x0a /* Public */,
      16,    1,   96,    2, 0x0a /* Public */,
      18,    1,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::QColor,   17,
    QMetaType::Void, QMetaType::Bool,   19,

 // properties: name, type, flags
      20, QMetaType::Double, 0x00095103,
      17, QMetaType::QColor, 0x00095103,
      21, 0x80000000 | 22, 0x0009510b,
       6, QMetaType::Bool, 0x00095103,
       4, QMetaType::Bool, 0x00095103,
      23, QMetaType::Int, 0x00095103,
      24, QMetaType::Int, 0x00095103,

       0        // eod
};

void LED::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LED *_t = static_cast<LED *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toggleStateSignal(); break;
        case 1: _t->setFlashingeSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->stateChangedSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->toggleState(); break;
        case 5: _t->setFlashing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setFlashRate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->startFlashing(); break;
        case 8: _t->stopFlashing(); break;
        case 9: _t->setAlphaForOff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 11: _t->setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LED::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LED::toggleStateSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LED::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LED::setFlashingeSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LED::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LED::stateChangedSignal)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        LED *_t = static_cast<LED *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->diameter(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->color(); break;
        case 2: *reinterpret_cast< Qt::Alignment*>(_v) = _t->alignment(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->state(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isFlashing(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->flashRate(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->alphaForOff(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        LED *_t = static_cast<LED *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDiameter(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setAlignment(*reinterpret_cast< Qt::Alignment*>(_v)); break;
        case 3: _t->setState(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setFlashing(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setFlashRate(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setAlphaForOff(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject LED::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LED.data,
      qt_meta_data_LED,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LED::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LED::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LED.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LED::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void LED::toggleStateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LED::setFlashingeSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LED::stateChangedSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_ScriptLed_t {
    QByteArrayData data[21];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptLed_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptLed_t qt_meta_stringdata_ScriptLed = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ScriptLed"
QT_MOC_LITERAL(1, 10, 18), // "stateChangedSignal"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "state"
QT_MOC_LITERAL(4, 36, 17), // "toggleStateSignal"
QT_MOC_LITERAL(5, 54, 18), // "setFlashingeSignal"
QT_MOC_LITERAL(6, 73, 8), // "flashing"
QT_MOC_LITERAL(7, 82, 14), // "setStateSignal"
QT_MOC_LITERAL(8, 97, 14), // "setColorSignal"
QT_MOC_LITERAL(9, 112, 5), // "color"
QT_MOC_LITERAL(10, 118, 18), // "setFlashRateSignal"
QT_MOC_LITERAL(11, 137, 4), // "rate"
QT_MOC_LITERAL(12, 142, 11), // "toggleState"
QT_MOC_LITERAL(13, 154, 11), // "setFlashing"
QT_MOC_LITERAL(14, 166, 8), // "setState"
QT_MOC_LITERAL(15, 175, 11), // "setColorRgb"
QT_MOC_LITERAL(16, 187, 3), // "red"
QT_MOC_LITERAL(17, 191, 5), // "green"
QT_MOC_LITERAL(18, 197, 4), // "blue"
QT_MOC_LITERAL(19, 202, 12), // "setFlashRate"
QT_MOC_LITERAL(20, 215, 20) // "publicScriptElements"

    },
    "ScriptLed\0stateChangedSignal\0\0state\0"
    "toggleStateSignal\0setFlashingeSignal\0"
    "flashing\0setStateSignal\0setColorSignal\0"
    "color\0setFlashRateSignal\0rate\0toggleState\0"
    "setFlashing\0setState\0setColorRgb\0red\0"
    "green\0blue\0setFlashRate\0publicScriptElements"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptLed[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       1,  102, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    0,   72,    2, 0x06 /* Public */,
       5,    1,   73,    2, 0x06 /* Public */,
       7,    1,   76,    2, 0x06 /* Public */,
       8,    1,   79,    2, 0x06 /* Public */,
      10,    1,   82,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      12,    0,   85,    2, 0x02 /* Public */,
      13,    1,   86,    2, 0x02 /* Public */,
      14,    1,   89,    2, 0x02 /* Public */,
      15,    3,   92,    2, 0x02 /* Public */,
      19,    1,   99,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QColor,    9,
    QMetaType::Void, QMetaType::Int,   11,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   16,   17,   18,
    QMetaType::Void, QMetaType::Int,   11,

 // properties: name, type, flags
      20, QMetaType::QString, 0x00095001,

       0        // eod
};

void ScriptLed::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptLed *_t = static_cast<ScriptLed *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChangedSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->toggleStateSignal(); break;
        case 2: _t->setFlashingeSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setStateSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setColorSignal((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 5: _t->setFlashRateSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->toggleState(); break;
        case 7: _t->setFlashing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setColorRgb((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        case 10: _t->setFlashRate((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScriptLed::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptLed::stateChangedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScriptLed::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptLed::toggleStateSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ScriptLed::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptLed::setFlashingeSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ScriptLed::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptLed::setStateSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ScriptLed::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptLed::setColorSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ScriptLed::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptLed::setFlashRateSignal)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ScriptLed *_t = static_cast<ScriptLed *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getPublicScriptElements(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ScriptLed::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ScriptLed.data,
      qt_meta_data_ScriptLed,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ScriptLed::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptLed::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptLed.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScriptLed::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ScriptLed::stateChangedSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScriptLed::toggleStateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ScriptLed::setFlashingeSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ScriptLed::setStateSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ScriptLed::setColorSignal(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ScriptLed::setFlashRateSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
