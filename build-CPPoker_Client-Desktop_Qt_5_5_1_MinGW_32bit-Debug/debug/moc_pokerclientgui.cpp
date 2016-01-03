/****************************************************************************
** Meta object code from reading C++ file 'pokerclientgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CPPoker-Client/view/pokerclientgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pokerclientgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PokerClientGui_t {
    QByteArrayData data[14];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PokerClientGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PokerClientGui_t qt_meta_stringdata_PokerClientGui = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PokerClientGui"
QT_MOC_LITERAL(1, 15, 3), // "bet"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "value"
QT_MOC_LITERAL(4, 26, 4), // "fold"
QT_MOC_LITERAL(5, 31, 5), // "allIn"
QT_MOC_LITERAL(6, 37, 11), // "slotQuitter"
QT_MOC_LITERAL(7, 49, 13), // "slotConnexion"
QT_MOC_LITERAL(8, 63, 16), // "slotNouveauSalon"
QT_MOC_LITERAL(9, 80, 15), // "slotDeconnexion"
QT_MOC_LITERAL(10, 96, 11), // "slotApropos"
QT_MOC_LITERAL(11, 108, 10), // "slotRegles"
QT_MOC_LITERAL(12, 119, 15), // "slotCombinaison"
QT_MOC_LITERAL(13, 135, 13) // "slotStartGame"

    },
    "PokerClientGui\0bet\0\0value\0fold\0allIn\0"
    "slotQuitter\0slotConnexion\0slotNouveauSalon\0"
    "slotDeconnexion\0slotApropos\0slotRegles\0"
    "slotCombinaison\0slotStartGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PokerClientGui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       4,    0,   72,    2, 0x0a /* Public */,
       5,    0,   73,    2, 0x0a /* Public */,
       6,    0,   74,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
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

void PokerClientGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PokerClientGui *_t = static_cast<PokerClientGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->fold(); break;
        case 2: _t->allIn(); break;
        case 3: _t->slotQuitter(); break;
        case 4: _t->slotConnexion(); break;
        case 5: _t->slotNouveauSalon(); break;
        case 6: _t->slotDeconnexion(); break;
        case 7: _t->slotApropos(); break;
        case 8: _t->slotRegles(); break;
        case 9: _t->slotCombinaison(); break;
        case 10: _t->slotStartGame(); break;
        default: ;
        }
    }
}

const QMetaObject PokerClientGui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PokerClientGui.data,
      qt_meta_data_PokerClientGui,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PokerClientGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PokerClientGui::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PokerClientGui.stringdata0))
        return static_cast<void*>(const_cast< PokerClientGui*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PokerClientGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE
