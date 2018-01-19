/****************************************************************************
** Meta object code from reading C++ file 'resources.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../resources.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resources.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Z__Resources_t {
    QByteArrayData data[12];
    char stringdata[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Z__Resources_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Z__Resources_t qt_meta_stringdata_Z__Resources = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 3),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 4),
QT_MOC_LITERAL(4, 23, 8),
QT_MOC_LITERAL(5, 32, 6),
QT_MOC_LITERAL(6, 39, 3),
QT_MOC_LITERAL(7, 43, 3),
QT_MOC_LITERAL(8, 47, 4),
QT_MOC_LITERAL(9, 52, 4),
QT_MOC_LITERAL(10, 57, 7),
QT_MOC_LITERAL(11, 65, 7)
    },
    "Z::Resources\0add\0\0name\0resource\0remove\0"
    "get\0def\0list\0_use\0acquire\0release"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Z__Resources[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x0a /* Public */,
       5,    1,   59,    2, 0x0a /* Public */,
       6,    2,   62,    2, 0x0a /* Public */,
       6,    1,   67,    2, 0x2a /* Public | MethodCloned */,
       8,    1,   70,    2, 0x0a /* Public */,
       8,    0,   73,    2, 0x2a /* Public | MethodCloned */,
      10,    1,   74,    2, 0x0a /* Public */,
      11,    1,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QObjectStar,    3,    4,
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::QObjectStar,    3,    7,
    QMetaType::QObjectStar, QMetaType::QString,    3,
    QMetaType::QStringList, QMetaType::Bool,    9,
    QMetaType::QStringList,
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QString,    3,

       0        // eod
};

void Z::Resources::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Resources *_t = static_cast<Resources *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->add((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->remove((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { QObject* _r = _t->get((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 3: { QObject* _r = _t->get((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 4: { QStringList _r = _t->list((*reinterpret_cast< const bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 5: { QStringList _r = _t->list();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->acquire((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->release((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Z::Resources::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Z__Resources.data,
      qt_meta_data_Z__Resources,  qt_static_metacall, 0, 0}
};


const QMetaObject *Z::Resources::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Z::Resources::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Z__Resources.stringdata))
        return static_cast<void*>(const_cast< Resources*>(this));
    return QObject::qt_metacast(_clname);
}

int Z::Resources::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
