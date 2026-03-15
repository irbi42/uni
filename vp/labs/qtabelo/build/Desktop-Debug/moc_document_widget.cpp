/****************************************************************************
** Meta object code from reading C++ file 'document_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../document_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'document_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DocumentWidget_t {
    QByteArrayData data[15];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DocumentWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DocumentWidget_t qt_meta_stringdata_DocumentWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DocumentWidget"
QT_MOC_LITERAL(1, 15, 15), // "modifiedChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "modified"
QT_MOC_LITERAL(4, 41, 10), // "urlChanged"
QT_MOC_LITERAL(5, 52, 3), // "url"
QT_MOC_LITERAL(6, 56, 11), // "setModified"
QT_MOC_LITERAL(7, 68, 13), // "resetModified"
QT_MOC_LITERAL(8, 82, 6), // "setUrl"
QT_MOC_LITERAL(9, 89, 8), // "resetUrl"
QT_MOC_LITERAL(10, 98, 20), // "documentCountChanged"
QT_MOC_LITERAL(11, 119, 5), // "count"
QT_MOC_LITERAL(12, 125, 19), // "copyPathToClipboard"
QT_MOC_LITERAL(13, 145, 23), // "copyFilenameToClipboard"
QT_MOC_LITERAL(14, 169, 14) // "renameFilename"

    },
    "DocumentWidget\0modifiedChanged\0\0"
    "modified\0urlChanged\0url\0setModified\0"
    "resetModified\0setUrl\0resetUrl\0"
    "documentCountChanged\0count\0"
    "copyPathToClipboard\0copyFilenameToClipboard\0"
    "renameFilename"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DocumentWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       2,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   70,    2, 0x0a /* Public */,
       7,    0,   73,    2, 0x0a /* Public */,
       8,    1,   74,    2, 0x0a /* Public */,
       9,    0,   77,    2, 0x0a /* Public */,
      10,    1,   78,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,
      13,    0,   82,    2, 0x0a /* Public */,
      14,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QUrl,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00495107,
       5, QMetaType::QUrl, 0x00495107,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void DocumentWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DocumentWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->modifiedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->urlChanged((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 2: _t->setModified((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 3: _t->resetModified(); break;
        case 4: _t->setUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 5: _t->resetUrl(); break;
        case 6: _t->documentCountChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 7: _t->copyPathToClipboard(); break;
        case 8: _t->copyFilenameToClipboard(); break;
        case 9: _t->renameFilename(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DocumentWidget::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentWidget::modifiedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DocumentWidget::*)(const QUrl & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentWidget::urlChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DocumentWidget *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isModified(); break;
        case 1: *reinterpret_cast< QUrl*>(_v) = _t->url(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DocumentWidget *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setModified(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setUrl(*reinterpret_cast< QUrl*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
        DocumentWidget *_t = static_cast<DocumentWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resetModified(); break;
        case 1: _t->resetUrl(); break;
        default: break;
        }
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DocumentWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<TableDocument::staticMetaObject>(),
    qt_meta_stringdata_DocumentWidget.data,
    qt_meta_data_DocumentWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DocumentWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DocumentWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DocumentWidget.stringdata0))
        return static_cast<void*>(this);
    return TableDocument::qt_metacast(_clname);
}

int DocumentWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TableDocument::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DocumentWidget::modifiedChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DocumentWidget::urlChanged(const QUrl & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
