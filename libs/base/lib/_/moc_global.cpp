/****************************************************************************
** Meta object code from reading C++ file 'global.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../global.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'global.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Z__Global_t {
    QByteArrayData data[8];
    char stringdata[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Z__Global_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Z__Global_t qt_meta_stringdata_Z__Global = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 4),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 3),
QT_MOC_LITERAL(4, 20, 3),
QT_MOC_LITERAL(5, 24, 5),
QT_MOC_LITERAL(6, 30, 3),
QT_MOC_LITERAL(7, 34, 12)
    },
    "Z::Global\0save\0\0set\0key\0value\0get\0"
    "defaultValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Z__Global[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    2,   35,    2, 0x0a /* Public */,
       6,    2,   40,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    4,    5,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QVariant,    4,    7,
    QMetaType::QVariant, QMetaType::QString,    4,

       0        // eod
};

void Z::Global::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Global *_t = static_cast<Global *>(_o);
        switch (_id) {
        case 0: _t->save(); break;
        case 1: _t->set((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->get((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 3: { QVariant _r = _t->get((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Z::Global::staticMetaObject = {
    { &QSettings::staticMetaObject, qt_meta_stringdata_Z__Global.data,
      qt_meta_data_Z__Global,  qt_static_metacall, 0, 0}
};


const QMetaObject *Z::Global::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Z::Global::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Z__Global.stringdata))
        return static_cast<void*>(const_cast< Global*>(this));
    return QSettings::qt_metacast(_clname);
}

int Z::Global::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSettings::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
