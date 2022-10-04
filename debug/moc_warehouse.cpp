/****************************************************************************
** Meta object code from reading C++ file 'warehouse.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../warehouse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'warehouse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Warehouse_t {
    QByteArrayData data[16];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Warehouse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Warehouse_t qt_meta_stringdata_Warehouse = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Warehouse"
QT_MOC_LITERAL(1, 10, 15), // "ChecklistDetial"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 39, 5), // "index"
QT_MOC_LITERAL(5, 45, 18), // "removeComFromDepot"
QT_MOC_LITERAL(6, 64, 7), // "searchN"
QT_MOC_LITERAL(7, 72, 7), // "searchC"
QT_MOC_LITERAL(8, 80, 4), // "back"
QT_MOC_LITERAL(9, 85, 6), // "addNew"
QT_MOC_LITERAL(10, 92, 13), // "addNewToTable"
QT_MOC_LITERAL(11, 106, 7), // "rfidadd"
QT_MOC_LITERAL(12, 114, 9), // "rfidaddto"
QT_MOC_LITERAL(13, 124, 6), // "cancel"
QT_MOC_LITERAL(14, 131, 6), // "clears"
QT_MOC_LITERAL(15, 138, 4) // "quit"

    },
    "Warehouse\0ChecklistDetial\0\0QModelIndex\0"
    "index\0removeComFromDepot\0searchN\0"
    "searchC\0back\0addNew\0addNewToTable\0"
    "rfidadd\0rfidaddto\0cancel\0clears\0quit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Warehouse[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Warehouse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Warehouse *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ChecklistDetial((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->removeComFromDepot(); break;
        case 2: _t->searchN(); break;
        case 3: _t->searchC(); break;
        case 4: _t->back(); break;
        case 5: _t->addNew(); break;
        case 6: _t->addNewToTable(); break;
        case 7: _t->rfidadd(); break;
        case 8: _t->rfidaddto(); break;
        case 9: _t->cancel(); break;
        case 10: _t->clears(); break;
        case 11: _t->quit(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Warehouse::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Warehouse.data,
    qt_meta_data_Warehouse,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Warehouse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Warehouse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Warehouse.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Warehouse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
