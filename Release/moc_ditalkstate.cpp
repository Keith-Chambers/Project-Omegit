/****************************************************************************
** Meta object code from reading C++ file 'ditalkstate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Project-Omegit/ditalkstate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ditalkstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DitalkState_t {
    QByteArrayData data[6];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DitalkState_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DitalkState_t qt_meta_stringdata_DitalkState = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DitalkState"
QT_MOC_LITERAL(1, 12, 5), // "State"
QT_MOC_LITERAL(2, 18, 9), // "LoggedOut"
QT_MOC_LITERAL(3, 28, 8), // "LoggedIn"
QT_MOC_LITERAL(4, 37, 8), // "Chatting"
QT_MOC_LITERAL(5, 46, 4) // "Size"

    },
    "DitalkState\0State\0LoggedOut\0LoggedIn\0"
    "Chatting\0Size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DitalkState[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    4,   18,

 // enum data: key, value
       2, uint(DitalkState::LoggedOut),
       3, uint(DitalkState::LoggedIn),
       4, uint(DitalkState::Chatting),
       5, uint(DitalkState::Size),

       0        // eod
};

void DitalkState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject DitalkState::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DitalkState.data,
      qt_meta_data_DitalkState,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DitalkState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DitalkState::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DitalkState.stringdata0))
        return static_cast<void*>(const_cast< DitalkState*>(this));
    return QObject::qt_metacast(_clname);
}

int DitalkState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
