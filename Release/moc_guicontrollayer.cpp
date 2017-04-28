/****************************************************************************
** Meta object code from reading C++ file 'guicontrollayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Project-Omegit/guicontrollayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guicontrollayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GuiControlLayer_t {
    QByteArrayData data[20];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GuiControlLayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GuiControlLayer_t qt_meta_stringdata_GuiControlLayer = {
    {
QT_MOC_LITERAL(0, 0, 15), // "GuiControlLayer"
QT_MOC_LITERAL(1, 16, 15), // "loggedInChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "appHeightChanged"
QT_MOC_LITERAL(4, 50, 15), // "appWidthChanged"
QT_MOC_LITERAL(5, 66, 15), // "chattingChanged"
QT_MOC_LITERAL(6, 82, 13), // "relayLoggedIn"
QT_MOC_LITERAL(7, 96, 11), // "pIsLoggedIn"
QT_MOC_LITERAL(8, 108, 27), // "changeApplicationDimensions"
QT_MOC_LITERAL(9, 136, 12), // "registerUser"
QT_MOC_LITERAL(10, 149, 9), // "pUsername"
QT_MOC_LITERAL(11, 159, 9), // "pPassword"
QT_MOC_LITERAL(12, 169, 12), // "pEmailPrefix"
QT_MOC_LITERAL(13, 182, 12), // "pEmailSuffix"
QT_MOC_LITERAL(14, 195, 9), // "loginUser"
QT_MOC_LITERAL(15, 205, 9), // "startChat"
QT_MOC_LITERAL(16, 215, 8), // "loggedIn"
QT_MOC_LITERAL(17, 224, 9), // "appHeight"
QT_MOC_LITERAL(18, 234, 8), // "appWidth"
QT_MOC_LITERAL(19, 243, 8) // "chatting"

    },
    "GuiControlLayer\0loggedInChanged\0\0"
    "appHeightChanged\0appWidthChanged\0"
    "chattingChanged\0relayLoggedIn\0pIsLoggedIn\0"
    "changeApplicationDimensions\0registerUser\0"
    "pUsername\0pPassword\0pEmailPrefix\0"
    "pEmailSuffix\0loginUser\0startChat\0"
    "loggedIn\0appHeight\0appWidth\0chatting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GuiControlLayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       4,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    0,   62,    2, 0x06 /* Public */,
       4,    0,   63,    2, 0x06 /* Public */,
       5,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   65,    2, 0x08 /* Private */,
       8,    1,   68,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       9,    4,   71,    2, 0x02 /* Public */,
      14,    2,   80,    2, 0x02 /* Public */,
      15,    0,   85,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,   13,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void,

 // properties: name, type, flags
      16, QMetaType::Bool, 0x00495103,
      17, QMetaType::Int, 0x00495103,
      18, QMetaType::Int, 0x00495103,
      19, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void GuiControlLayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GuiControlLayer *_t = static_cast<GuiControlLayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loggedInChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->appHeightChanged(); break;
        case 2: _t->appWidthChanged(); break;
        case 3: _t->chattingChanged(); break;
        case 4: _t->relayLoggedIn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->changeApplicationDimensions((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: { bool _r = _t->registerUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->loginUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->startChat(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GuiControlLayer::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiControlLayer::loggedInChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GuiControlLayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiControlLayer::appHeightChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GuiControlLayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiControlLayer::appWidthChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GuiControlLayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiControlLayer::chattingChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        GuiControlLayer *_t = static_cast<GuiControlLayer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isLoggedIn(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getAppHeight(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getAppWidth(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isChatting(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        GuiControlLayer *_t = static_cast<GuiControlLayer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLoggedIn(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setAppHeight(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setAppWidth(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setChatting(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject GuiControlLayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GuiControlLayer.data,
      qt_meta_data_GuiControlLayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GuiControlLayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GuiControlLayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GuiControlLayer.stringdata0))
        return static_cast<void*>(const_cast< GuiControlLayer*>(this));
    return QObject::qt_metacast(_clname);
}

int GuiControlLayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void GuiControlLayer::loggedInChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GuiControlLayer::appHeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void GuiControlLayer::appWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void GuiControlLayer::chattingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
