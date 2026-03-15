/****************************************************************************
** Meta object code from reading C++ file 'recent_document_list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../recent_document_list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recent_document_list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RecentDocumentList_t {
    QByteArrayData data[13];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecentDocumentList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecentDocumentList_t qt_meta_stringdata_RecentDocumentList = {
    {
QT_MOC_LITERAL(0, 0, 18), // "RecentDocumentList"
QT_MOC_LITERAL(1, 19, 11), // "listChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "documentSelected"
QT_MOC_LITERAL(4, 49, 3), // "url"
QT_MOC_LITERAL(5, 53, 10), // "setMaximum"
QT_MOC_LITERAL(6, 64, 3), // "max"
QT_MOC_LITERAL(7, 68, 10), // "setRestore"
QT_MOC_LITERAL(8, 79, 7), // "restore"
QT_MOC_LITERAL(9, 87, 5), // "clear"
QT_MOC_LITERAL(10, 93, 13), // "slotUrlAction"
QT_MOC_LITERAL(11, 107, 5), // "count"
QT_MOC_LITERAL(12, 113, 7) // "maximum"

    },
    "RecentDocumentList\0listChanged\0\0"
    "documentSelected\0url\0setMaximum\0max\0"
    "setRestore\0restore\0clear\0slotUrlAction\0"
    "count\0maximum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecentDocumentList[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       3,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,
       9,    0,   54,    2, 0x0a /* Public */,
      10,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      11, QMetaType::Int, 0x00095001,
      12, QMetaType::Int, 0x00095103,
       8, QMetaType::Bool, 0x00095103,

       0        // eod
};

void RecentDocumentList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RecentDocumentList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->listChanged(); break;
        case 1: _t->documentSelected((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 2: _t->setMaximum((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->setRestore((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 4: _t->clear(); break;
        case 5: _t->slotUrlAction(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RecentDocumentList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecentDocumentList::listChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RecentDocumentList::*)(const QUrl & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecentDocumentList::documentSelected)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<RecentDocumentList *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->maximum(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->restore(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<RecentDocumentList *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setMaximum(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setRestore(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject RecentDocumentList::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RecentDocumentList.data,
    qt_meta_data_RecentDocumentList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RecentDocumentList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecentDocumentList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RecentDocumentList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RecentDocumentList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
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
void RecentDocumentList::listChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RecentDocumentList::documentSelected(const QUrl & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
