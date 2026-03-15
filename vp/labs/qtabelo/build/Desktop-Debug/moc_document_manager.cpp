/****************************************************************************
** Meta object code from reading C++ file 'document_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../document_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'document_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DocumentManager_t {
    QByteArrayData data[25];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DocumentManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DocumentManager_t qt_meta_stringdata_DocumentManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DocumentManager"
QT_MOC_LITERAL(1, 16, 17), // "tabVisibleChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 7), // "visible"
QT_MOC_LITERAL(4, 43, 18), // "tabPositionChanged"
QT_MOC_LITERAL(5, 62, 23), // "QTabWidget::TabPosition"
QT_MOC_LITERAL(6, 86, 8), // "position"
QT_MOC_LITERAL(7, 95, 18), // "tabAutoHideChanged"
QT_MOC_LITERAL(8, 114, 8), // "autoHide"
QT_MOC_LITERAL(9, 123, 13), // "setTabVisible"
QT_MOC_LITERAL(10, 137, 15), // "resetTabVisible"
QT_MOC_LITERAL(11, 153, 14), // "initTabVisible"
QT_MOC_LITERAL(12, 168, 14), // "setTabPosition"
QT_MOC_LITERAL(13, 183, 16), // "resetTabPosition"
QT_MOC_LITERAL(14, 200, 15), // "initTabPosition"
QT_MOC_LITERAL(15, 216, 14), // "setTabAutoHide"
QT_MOC_LITERAL(16, 231, 16), // "resetTabAutoHide"
QT_MOC_LITERAL(17, 248, 15), // "initTabAutoHide"
QT_MOC_LITERAL(18, 264, 22), // "closeSelectedSubWindow"
QT_MOC_LITERAL(19, 287, 14), // "QMdiSubWindow*"
QT_MOC_LITERAL(20, 302, 9), // "subWindow"
QT_MOC_LITERAL(21, 312, 20), // "closeOtherSubWindows"
QT_MOC_LITERAL(22, 333, 10), // "tabVisible"
QT_MOC_LITERAL(23, 344, 11), // "tabPosition"
QT_MOC_LITERAL(24, 356, 11) // "tabAutoHide"

    },
    "DocumentManager\0tabVisibleChanged\0\0"
    "visible\0tabPositionChanged\0"
    "QTabWidget::TabPosition\0position\0"
    "tabAutoHideChanged\0autoHide\0setTabVisible\0"
    "resetTabVisible\0initTabVisible\0"
    "setTabPosition\0resetTabPosition\0"
    "initTabPosition\0setTabAutoHide\0"
    "resetTabAutoHide\0initTabAutoHide\0"
    "closeSelectedSubWindow\0QMdiSubWindow*\0"
    "subWindow\0closeOtherSubWindows\0"
    "tabVisible\0tabPosition\0tabAutoHide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DocumentManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       3,  114, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       7,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   93,    2, 0x0a /* Public */,
      10,    0,   96,    2, 0x0a /* Public */,
      11,    0,   97,    2, 0x0a /* Public */,
      12,    1,   98,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    1,  103,    2, 0x0a /* Public */,
      16,    0,  106,    2, 0x0a /* Public */,
      17,    0,  107,    2, 0x0a /* Public */,
      18,    1,  108,    2, 0x0a /* Public */,
      21,    1,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   20,

 // properties: name, type, flags
      22, QMetaType::Bool, 0x00495107,
      23, 0x80000000 | 5, 0x0049510f,
      24, QMetaType::Bool, 0x00495107,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void DocumentManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DocumentManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tabVisibleChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->tabPositionChanged((*reinterpret_cast< const QTabWidget::TabPosition(*)>(_a[1]))); break;
        case 2: _t->tabAutoHideChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 3: _t->setTabVisible((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 4: _t->resetTabVisible(); break;
        case 5: _t->initTabVisible(); break;
        case 6: _t->setTabPosition((*reinterpret_cast< const QTabWidget::TabPosition(*)>(_a[1]))); break;
        case 7: _t->resetTabPosition(); break;
        case 8: _t->initTabPosition(); break;
        case 9: _t->setTabAutoHide((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 10: _t->resetTabAutoHide(); break;
        case 11: _t->initTabAutoHide(); break;
        case 12: _t->closeSelectedSubWindow((*reinterpret_cast< QMdiSubWindow*(*)>(_a[1]))); break;
        case 13: _t->closeOtherSubWindows((*reinterpret_cast< QMdiSubWindow*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DocumentManager::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentManager::tabVisibleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DocumentManager::*)(const QTabWidget::TabPosition );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentManager::tabPositionChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DocumentManager::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentManager::tabAutoHideChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DocumentManager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isTabVisible(); break;
        case 1: *reinterpret_cast< QTabWidget::TabPosition*>(_v) = _t->tabPosition(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isTabAutoHide(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DocumentManager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTabVisible(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setTabPosition(*reinterpret_cast< QTabWidget::TabPosition*>(_v)); break;
        case 2: _t->setTabAutoHide(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
        DocumentManager *_t = static_cast<DocumentManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resetTabVisible(); break;
        case 1: _t->resetTabPosition(); break;
        case 2: _t->resetTabAutoHide(); break;
        default: break;
        }
    }
#endif // QT_NO_PROPERTIES
}

static const QMetaObject::SuperData qt_meta_extradata_DocumentManager[] = {
    QMetaObject::SuperData::link<QTabWidget::staticMetaObject>(),
    nullptr
};

QT_INIT_METAOBJECT const QMetaObject DocumentManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QMdiArea::staticMetaObject>(),
    qt_meta_stringdata_DocumentManager.data,
    qt_meta_data_DocumentManager,
    qt_static_metacall,
    qt_meta_extradata_DocumentManager,
    nullptr
} };


const QMetaObject *DocumentManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DocumentManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DocumentManager.stringdata0))
        return static_cast<void*>(this);
    return QMdiArea::qt_metacast(_clname);
}

int DocumentManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMdiArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DocumentManager::tabVisibleChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DocumentManager::tabPositionChanged(const QTabWidget::TabPosition _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DocumentManager::tabAutoHideChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
