/****************************************************************************
** Meta object code from reading C++ file 'teachingmanagerinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../teachingmanagerinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teachingmanagerinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TeachingManagerInterface_t {
    QByteArrayData data[9];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TeachingManagerInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TeachingManagerInterface_t qt_meta_stringdata_TeachingManagerInterface = {
    {
QT_MOC_LITERAL(0, 0, 24), // "TeachingManagerInterface"
QT_MOC_LITERAL(1, 25, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 72, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(5, 96, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(6, 120, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(7, 144, 24), // "on_pushButton_13_clicked"
QT_MOC_LITERAL(8, 169, 23) // "on_pushButton_6_clicked"

    },
    "TeachingManagerInterface\0on_pushButton_clicked\0"
    "\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_5_clicked\0"
    "on_pushButton_13_clicked\0"
    "on_pushButton_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TeachingManagerInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TeachingManagerInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TeachingManagerInterface *_t = static_cast<TeachingManagerInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: _t->on_pushButton_5_clicked(); break;
        case 5: _t->on_pushButton_13_clicked(); break;
        case 6: _t->on_pushButton_6_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TeachingManagerInterface::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TeachingManagerInterface.data,
      qt_meta_data_TeachingManagerInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TeachingManagerInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TeachingManagerInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TeachingManagerInterface.stringdata0))
        return static_cast<void*>(const_cast< TeachingManagerInterface*>(this));
    return QDialog::qt_metacast(_clname);
}

int TeachingManagerInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
