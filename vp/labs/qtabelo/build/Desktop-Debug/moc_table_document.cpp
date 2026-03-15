/****************************************************************************
** Meta object code from reading C++ file 'table_document.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../table_document.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'table_document.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TableDocument_t {
    QByteArrayData data[31];
    char stringdata0[446];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TableDocument_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TableDocument_t qt_meta_stringdata_TableDocument = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TableDocument"
QT_MOC_LITERAL(1, 14, 20), // "tabBarVisibleChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "visible"
QT_MOC_LITERAL(4, 44, 21), // "tabBarPositionChanged"
QT_MOC_LITERAL(5, 66, 23), // "QTabWidget::TabPosition"
QT_MOC_LITERAL(6, 90, 8), // "position"
QT_MOC_LITERAL(7, 99, 21), // "tabBarAutoHideChanged"
QT_MOC_LITERAL(8, 121, 7), // "enabled"
QT_MOC_LITERAL(9, 129, 14), // "contentChanged"
QT_MOC_LITERAL(10, 144, 8), // "modified"
QT_MOC_LITERAL(11, 153, 16), // "setTabBarVisible"
QT_MOC_LITERAL(12, 170, 18), // "resetTabBarVisible"
QT_MOC_LITERAL(13, 189, 17), // "initTabBarVisible"
QT_MOC_LITERAL(14, 207, 17), // "setTabBarPosition"
QT_MOC_LITERAL(15, 225, 19), // "resetTabBarPosition"
QT_MOC_LITERAL(16, 245, 18), // "initTabBarPosition"
QT_MOC_LITERAL(17, 264, 17), // "setTabBarAutoHide"
QT_MOC_LITERAL(18, 282, 19), // "resetTabBarAutoHide"
QT_MOC_LITERAL(19, 302, 18), // "initTabBarAutoHide"
QT_MOC_LITERAL(20, 321, 20), // "showTableContextMenu"
QT_MOC_LITERAL(21, 342, 13), // "QTableWidget*"
QT_MOC_LITERAL(22, 356, 5), // "table"
QT_MOC_LITERAL(23, 362, 3), // "pos"
QT_MOC_LITERAL(24, 366, 10), // "slotAddTab"
QT_MOC_LITERAL(25, 377, 5), // "count"
QT_MOC_LITERAL(26, 383, 12), // "slotCloseTab"
QT_MOC_LITERAL(27, 396, 5), // "index"
QT_MOC_LITERAL(28, 402, 13), // "tabBarVisible"
QT_MOC_LITERAL(29, 416, 14), // "tabBarPosition"
QT_MOC_LITERAL(30, 431, 14) // "tabBarAutoHide"

    },
    "TableDocument\0tabBarVisibleChanged\0\0"
    "visible\0tabBarPositionChanged\0"
    "QTabWidget::TabPosition\0position\0"
    "tabBarAutoHideChanged\0enabled\0"
    "contentChanged\0modified\0setTabBarVisible\0"
    "resetTabBarVisible\0initTabBarVisible\0"
    "setTabBarPosition\0resetTabBarPosition\0"
    "initTabBarPosition\0setTabBarAutoHide\0"
    "resetTabBarAutoHide\0initTabBarAutoHide\0"
    "showTableContextMenu\0QTableWidget*\0"
    "table\0pos\0slotAddTab\0count\0slotCloseTab\0"
    "index\0tabBarVisible\0tabBarPosition\0"
    "tabBarAutoHide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TableDocument[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       3,  132, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       7,    1,  100,    2, 0x06 /* Public */,
       9,    1,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  106,    2, 0x0a /* Public */,
      12,    0,  109,    2, 0x0a /* Public */,
      13,    0,  110,    2, 0x0a /* Public */,
      14,    1,  111,    2, 0x0a /* Public */,
      15,    0,  114,    2, 0x0a /* Public */,
      16,    0,  115,    2, 0x0a /* Public */,
      17,    1,  116,    2, 0x0a /* Public */,
      18,    0,  119,    2, 0x0a /* Public */,
      19,    0,  120,    2, 0x0a /* Public */,
      20,    2,  121,    2, 0x0a /* Public */,
      24,    1,  126,    2, 0x09 /* Protected */,
      26,    1,  129,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,   10,

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
    QMetaType::Void, 0x80000000 | 21, QMetaType::QPoint,   22,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   27,

 // properties: name, type, flags
      28, QMetaType::Bool, 0x00495107,
      29, 0x80000000 | 5, 0x0049510f,
      30, QMetaType::Bool, 0x00495107,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void TableDocument::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TableDocument *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tabBarVisibleChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->tabBarPositionChanged((*reinterpret_cast< const QTabWidget::TabPosition(*)>(_a[1]))); break;
        case 2: _t->tabBarAutoHideChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 3: _t->contentChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setTabBarVisible((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 5: _t->resetTabBarVisible(); break;
        case 6: _t->initTabBarVisible(); break;
        case 7: _t->setTabBarPosition((*reinterpret_cast< const QTabWidget::TabPosition(*)>(_a[1]))); break;
        case 8: _t->resetTabBarPosition(); break;
        case 9: _t->initTabBarPosition(); break;
        case 10: _t->setTabBarAutoHide((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 11: _t->resetTabBarAutoHide(); break;
        case 12: _t->initTabBarAutoHide(); break;
        case 13: _t->showTableContextMenu((*reinterpret_cast< QTableWidget*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 14: _t->slotAddTab((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 15: _t->slotCloseTab((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TableDocument::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableDocument::tabBarVisibleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TableDocument::*)(const QTabWidget::TabPosition );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableDocument::tabBarPositionChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TableDocument::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableDocument::tabBarAutoHideChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TableDocument::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableDocument::contentChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TableDocument *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isTabBarVisible(); break;
        case 1: *reinterpret_cast< QTabWidget::TabPosition*>(_v) = _t->tabBarPosition(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isTabBarAutoHide(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TableDocument *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTabBarVisible(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setTabBarPosition(*reinterpret_cast< QTabWidget::TabPosition*>(_v)); break;
        case 2: _t->setTabBarAutoHide(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
        TableDocument *_t = static_cast<TableDocument *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resetTabBarVisible(); break;
        case 1: _t->resetTabBarPosition(); break;
        case 2: _t->resetTabBarAutoHide(); break;
        default: break;
        }
    }
#endif // QT_NO_PROPERTIES
}

static const QMetaObject::SuperData qt_meta_extradata_TableDocument[] = {
    QMetaObject::SuperData::link<QTabWidget::staticMetaObject>(),
    nullptr
};

QT_INIT_METAOBJECT const QMetaObject TableDocument::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TableDocument.data,
    qt_meta_data_TableDocument,
    qt_static_metacall,
    qt_meta_extradata_TableDocument,
    nullptr
} };


const QMetaObject *TableDocument::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableDocument::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TableDocument.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TableDocument::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
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
void TableDocument::tabBarVisibleChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TableDocument::tabBarPositionChanged(const QTabWidget::TabPosition _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TableDocument::tabBarAutoHideChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TableDocument::contentChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
