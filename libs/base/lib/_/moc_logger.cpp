/****************************************************************************
** Meta object code from reading C++ file 'logger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../logger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Z__Logger_t {
    QByteArrayData data[12];
    char stringdata[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Z__Logger_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Z__Logger_t qt_meta_stringdata_Z__Logger = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 7),
QT_MOC_LITERAL(2, 18, 11),
QT_MOC_LITERAL(3, 30, 0),
QT_MOC_LITERAL(4, 31, 3),
QT_MOC_LITERAL(5, 35, 7),
QT_MOC_LITERAL(6, 43, 4),
QT_MOC_LITERAL(7, 48, 18),
QT_MOC_LITERAL(8, 67, 7),
QT_MOC_LITERAL(9, 75, 8),
QT_MOC_LITERAL(10, 84, 2),
QT_MOC_LITERAL(11, 87, 2)
    },
    "Z::Logger\0message\0const char*\0\0msg\0"
    "MsgType\0type\0QMessageLogContext\0context\0"
    "setLevel\0_s\0_f"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Z__Logger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   39,    3, 0x0a /* Public */,
       1,    2,   46,    3, 0x2a /* Public | MethodCloned */,
       1,    1,   51,    3, 0x2a /* Public | MethodCloned */,
       9,    2,   54,    3, 0x0a /* Public */,
       9,    1,   59,    3, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    0x80000000 | 2, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    0x80000000 | 2, QMetaType::QString, 0x80000000 | 5,    4,    6,
    0x80000000 | 2, QMetaType::QString,    4,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool,   10,   11,
    QMetaType::Bool, QMetaType::QString,   10,

       0        // eod
};

void Z::Logger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Logger *_t = static_cast<Logger *>(_o);
        switch (_id) {
        case 0: { const char* _r = _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const MsgType(*)>(_a[2])),(*reinterpret_cast< const QMessageLogContext(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< const char**>(_a[0]) = _r; }  break;
        case 1: { const char* _r = _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const MsgType(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< const char**>(_a[0]) = _r; }  break;
        case 2: { const char* _r = _t->message((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const char**>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->setLevel((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->setLevel((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Z::Logger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Z__Logger.data,
      qt_meta_data_Z__Logger,  qt_static_metacall, 0, 0}
};


const QMetaObject *Z::Logger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Z::Logger::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Z__Logger.stringdata))
        return static_cast<void*>(const_cast< Logger*>(this));
    return QObject::qt_metacast(_clname);
}

int Z::Logger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
