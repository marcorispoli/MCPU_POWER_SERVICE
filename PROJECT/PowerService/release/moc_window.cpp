/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SOURCE/WINDOW/window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_debugWindow_t {
    const uint offsetsAndSize[36];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_debugWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_debugWindow_t qt_meta_stringdata_debugWindow = {
    {
QT_MOC_LITERAL(0, 11), // "debugWindow"
QT_MOC_LITERAL(12, 18), // "onDebugClearButton"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 16), // "onLogClearButton"
QT_MOC_LITERAL(49, 16), // "onSoftPoffButton"
QT_MOC_LITERAL(66, 13), // "onAbortButton"
QT_MOC_LITERAL(80, 11), // "onArmButton"
QT_MOC_LITERAL(92, 18), // "onBootloaderButton"
QT_MOC_LITERAL(111, 10), // "assignData"
QT_MOC_LITERAL(122, 9), // "rxFromCan"
QT_MOC_LITERAL(132, 5), // "canId"
QT_MOC_LITERAL(138, 4), // "data"
QT_MOC_LITERAL(143, 7), // "txToCan"
QT_MOC_LITERAL(151, 10), // "timerEvent"
QT_MOC_LITERAL(162, 12), // "QTimerEvent*"
QT_MOC_LITERAL(175, 2), // "ev"
QT_MOC_LITERAL(178, 30), // "on_logEnableCheck_stateChanged"
QT_MOC_LITERAL(209, 4) // "arg1"

    },
    "debugWindow\0onDebugClearButton\0\0"
    "onLogClearButton\0onSoftPoffButton\0"
    "onAbortButton\0onArmButton\0onBootloaderButton\0"
    "assignData\0rxFromCan\0canId\0data\0txToCan\0"
    "timerEvent\0QTimerEvent*\0ev\0"
    "on_logEnableCheck_stateChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_debugWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x0a,    1 /* Public */,
       3,    0,   81,    2, 0x0a,    2 /* Public */,
       4,    0,   82,    2, 0x0a,    3 /* Public */,
       5,    0,   83,    2, 0x0a,    4 /* Public */,
       6,    0,   84,    2, 0x0a,    5 /* Public */,
       7,    0,   85,    2, 0x0a,    6 /* Public */,
       8,    0,   86,    2, 0x0a,    7 /* Public */,
       9,    2,   87,    2, 0x0a,    8 /* Public */,
      12,    2,   92,    2, 0x0a,   11 /* Public */,
      13,    1,   97,    2, 0x0a,   14 /* Public */,
      16,    1,  100,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,   10,   11,
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,   10,   11,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void debugWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<debugWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onDebugClearButton(); break;
        case 1: _t->onLogClearButton(); break;
        case 2: _t->onSoftPoffButton(); break;
        case 3: _t->onAbortButton(); break;
        case 4: _t->onArmButton(); break;
        case 5: _t->onBootloaderButton(); break;
        case 6: _t->assignData(); break;
        case 7: _t->rxFromCan((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 8: _t->txToCan((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 9: _t->timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 10: _t->on_logEnableCheck_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject debugWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_debugWindow.offsetsAndSize,
    qt_meta_data_debugWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_debugWindow_t
, QtPrivate::TypeAndForceComplete<debugWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTimerEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *debugWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *debugWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_debugWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int debugWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
