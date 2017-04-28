/****************************************************************************
** Meta object code from reading C++ file 'chatmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Project-Omegit/chatmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatManager_t {
    QByteArrayData data[13];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatManager_t qt_meta_stringdata_ChatManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ChatManager"
QT_MOC_LITERAL(1, 12, 18), // "newIncomingMessage"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "pMessage"
QT_MOC_LITERAL(4, 41, 18), // "newChatEstablished"
QT_MOC_LITERAL(5, 60, 16), // "chatDisconnected"
QT_MOC_LITERAL(6, 77, 16), // "startChatTimeOut"
QT_MOC_LITERAL(7, 94, 18), // "newOutgoingMessage"
QT_MOC_LITERAL(8, 113, 17), // "startChatResponse"
QT_MOC_LITERAL(9, 131, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 146, 6), // "pReply"
QT_MOC_LITERAL(11, 153, 27), // "updateMessageThreadResponse"
QT_MOC_LITERAL(12, 181, 19) // "updateMessageThread"

    },
    "ChatManager\0newIncomingMessage\0\0"
    "pMessage\0newChatEstablished\0"
    "chatDisconnected\0startChatTimeOut\0"
    "newOutgoingMessage\0startChatResponse\0"
    "QNetworkReply*\0pReply\0updateMessageThreadResponse\0"
    "updateMessageThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,
       6,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   60,    2, 0x0a /* Public */,
       8,    1,   63,    2, 0x0a /* Public */,
      11,    1,   66,    2, 0x0a /* Public */,
      12,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void ChatManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatManager *_t = static_cast<ChatManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newIncomingMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->newChatEstablished(); break;
        case 2: _t->chatDisconnected(); break;
        case 3: _t->startChatTimeOut(); break;
        case 4: _t->newOutgoingMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->startChatResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->updateMessageThreadResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 7: _t->updateMessageThread(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 6:
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
            typedef void (ChatManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatManager::newIncomingMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ChatManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatManager::newChatEstablished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ChatManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatManager::chatDisconnected)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ChatManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatManager::startChatTimeOut)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ChatManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ChatManager.data,
      qt_meta_data_ChatManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChatManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChatManager.stringdata0))
        return static_cast<void*>(const_cast< ChatManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ChatManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ChatManager::newIncomingMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChatManager::newChatEstablished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ChatManager::chatDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ChatManager::startChatTimeOut()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
