/****************************************************************************
** Meta object code from reading C++ file 'ditalkbackendcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Project-Omegit/ditalkbackendcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ditalkbackendcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DitalkBackendController_t {
    QByteArrayData data[18];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DitalkBackendController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DitalkBackendController_t qt_meta_stringdata_DitalkBackendController = {
    {
QT_MOC_LITERAL(0, 0, 23), // "DitalkBackendController"
QT_MOC_LITERAL(1, 24, 18), // "newIncomingMessage"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 8), // "pMessage"
QT_MOC_LITERAL(4, 53, 12), // "stateChanged"
QT_MOC_LITERAL(5, 66, 18), // "DitalkState::State"
QT_MOC_LITERAL(6, 85, 9), // "pNewState"
QT_MOC_LITERAL(7, 95, 15), // "usernameChanged"
QT_MOC_LITERAL(8, 111, 16), // "firstNameChanged"
QT_MOC_LITERAL(9, 128, 15), // "lastNameChanged"
QT_MOC_LITERAL(10, 144, 15), // "fullNameChanged"
QT_MOC_LITERAL(11, 160, 15), // "startChatFailed"
QT_MOC_LITERAL(12, 176, 9), // "onNewChat"
QT_MOC_LITERAL(13, 186, 18), // "onChatDisconnected"
QT_MOC_LITERAL(14, 205, 13), // "loginResponse"
QT_MOC_LITERAL(15, 219, 14), // "QNetworkReply*"
QT_MOC_LITERAL(16, 234, 5), // "reply"
QT_MOC_LITERAL(17, 240, 14) // "logoutResponse"

    },
    "DitalkBackendController\0newIncomingMessage\0"
    "\0pMessage\0stateChanged\0DitalkState::State\0"
    "pNewState\0usernameChanged\0firstNameChanged\0"
    "lastNameChanged\0fullNameChanged\0"
    "startChatFailed\0onNewChat\0onChatDisconnected\0"
    "loginResponse\0QNetworkReply*\0reply\0"
    "logoutResponse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DitalkBackendController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       7,    0,   75,    2, 0x06 /* Public */,
       8,    0,   76,    2, 0x06 /* Public */,
       9,    0,   77,    2, 0x06 /* Public */,
      10,    0,   78,    2, 0x06 /* Public */,
      11,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   80,    2, 0x0a /* Public */,
      13,    0,   81,    2, 0x0a /* Public */,
      14,    1,   82,    2, 0x0a /* Public */,
      17,    1,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void DitalkBackendController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DitalkBackendController *_t = static_cast<DitalkBackendController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newIncomingMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->stateChanged((*reinterpret_cast< DitalkState::State(*)>(_a[1]))); break;
        case 2: _t->usernameChanged(); break;
        case 3: _t->firstNameChanged(); break;
        case 4: _t->lastNameChanged(); break;
        case 5: _t->fullNameChanged(); break;
        case 6: _t->startChatFailed(); break;
        case 7: _t->onNewChat(); break;
        case 8: _t->onChatDisconnected(); break;
        case 9: _t->loginResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->logoutResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DitalkBackendController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DitalkBackendController::newIncomingMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DitalkBackendController::*_t)(DitalkState::State );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DitalkBackendController::stateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DitalkBackendController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DitalkBackendController::usernameChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DitalkBackendController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DitalkBackendController::firstNameChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DitalkBackendController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DitalkBackendController::lastNameChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (DitalkBackendController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DitalkBackendController::fullNameChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (DitalkBackendController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DitalkBackendController::startChatFailed)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject DitalkBackendController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DitalkBackendController.data,
      qt_meta_data_DitalkBackendController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DitalkBackendController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DitalkBackendController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DitalkBackendController.stringdata0))
        return static_cast<void*>(const_cast< DitalkBackendController*>(this));
    return QObject::qt_metacast(_clname);
}

int DitalkBackendController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void DitalkBackendController::newIncomingMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DitalkBackendController::stateChanged(DitalkState::State _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DitalkBackendController::usernameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void DitalkBackendController::firstNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void DitalkBackendController::lastNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void DitalkBackendController::fullNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void DitalkBackendController::startChatFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
