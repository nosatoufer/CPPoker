/****************************************************************************
** Meta object code from reading C++ file 'pokerclientgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../view/pokerclientgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pokerclientgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PokerClientGui_t {
    QByteArrayData data[13];
    char stringdata[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PokerClientGui_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PokerClientGui_t qt_meta_stringdata_PokerClientGui = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 11),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 13),
QT_MOC_LITERAL(4, 42, 16),
QT_MOC_LITERAL(5, 59, 15),
QT_MOC_LITERAL(6, 75, 11),
QT_MOC_LITERAL(7, 87, 10),
QT_MOC_LITERAL(8, 98, 15),
QT_MOC_LITERAL(9, 114, 9),
QT_MOC_LITERAL(10, 124, 8),
QT_MOC_LITERAL(11, 133, 8),
QT_MOC_LITERAL(12, 142, 9)
    },
    "PokerClientGui\0slotQuitter\0\0slotConnexion\0"
    "slotNouveauSalon\0slotDeconnexion\0"
    "slotApropos\0slotRegles\0slotCombinaison\0"
    "slotCheck\0slotFold\0slotCall\0slotRaise\0"
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
       1,    0,   69,    2, 0x08,
       3,    0,   70,    2, 0x08,
       4,    0,   71,    2, 0x08,
       5,    0,   72,    2, 0x08,
       6,    0,   73,    2, 0x08,
       7,    0,   74,    2, 0x08,
       8,    0,   75,    2, 0x08,
       9,    0,   76,    2, 0x08,
      10,    0,   77,    2, 0x08,
      11,    0,   78,    2, 0x08,
      12,    0,   79,    2, 0x08,

 // slots: parameters
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

void PokerClientGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PokerClientGui *_t = static_cast<PokerClientGui *>(_o);
        switch (_id) {
        case 0: _t->slotQuitter(); break;
        case 1: _t->slotConnexion(); break;
        case 2: _t->slotNouveauSalon(); break;
        case 3: _t->slotDeconnexion(); break;
        case 4: _t->slotApropos(); break;
        case 5: _t->slotRegles(); break;
        case 6: _t->slotCombinaison(); break;
        case 7: _t->slotCheck(); break;
        case 8: _t->slotFold(); break;
        case 9: _t->slotCall(); break;
        case 10: _t->slotRaise(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PokerClientGui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PokerClientGui.data,
      qt_meta_data_PokerClientGui,  qt_static_metacall, 0, 0}
};


const QMetaObject *PokerClientGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PokerClientGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PokerClientGui.stringdata))
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
