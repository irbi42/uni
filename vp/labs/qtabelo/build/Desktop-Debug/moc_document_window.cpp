/****************************************************************************
** Meta object code from reading C++ file 'document_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../document_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'document_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DocumentWindow_t {
    QByteArrayData data[19];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DocumentWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DocumentWindow_t qt_meta_stringdata_DocumentWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DocumentWindow"
QT_MOC_LITERAL(1, 15, 16), // "actionCloseOther"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "DocumentWindow*"
QT_MOC_LITERAL(4, 49, 6), // "window"
QT_MOC_LITERAL(5, 56, 14), // "actionCopyPath"
QT_MOC_LITERAL(6, 71, 18), // "actionCopyFilename"
QT_MOC_LITERAL(7, 90, 20), // "actionRenameFilename"
QT_MOC_LITERAL(8, 111, 25), // "setFilenameSequenceNumber"
QT_MOC_LITERAL(9, 137, 6), // "number"
QT_MOC_LITERAL(10, 144, 27), // "resetFilenameSequenceNumber"
QT_MOC_LITERAL(11, 172, 20), // "documentCountChanged"
QT_MOC_LITERAL(12, 193, 5), // "count"
QT_MOC_LITERAL(13, 199, 23), // "documentModifiedChanged"
QT_MOC_LITERAL(14, 223, 8), // "modified"
QT_MOC_LITERAL(15, 232, 18), // "documentUrlChanged"
QT_MOC_LITERAL(16, 251, 3), // "url"
QT_MOC_LITERAL(17, 255, 14), // "slotCloseOther"
QT_MOC_LITERAL(18, 270, 22) // "filenameSequenceNumber"

    },
    "DocumentWindow\0actionCloseOther\0\0"
    "DocumentWindow*\0window\0actionCopyPath\0"
    "actionCopyFilename\0actionRenameFilename\0"
    "setFilenameSequenceNumber\0number\0"
    "resetFilenameSequenceNumber\0"
    "documentCountChanged\0count\0"
    "documentModifiedChanged\0modified\0"
    "documentUrlChanged\0url\0slotCloseOther\0"
    "filenameSequenceNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DocumentWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       1,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   70,    2, 0x0a /* Public */,
      10,    0,   73,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      13,    1,   77,    2, 0x0a /* Public */,
      15,    1,   80,    2, 0x0a /* Public */,
      17,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::QUrl,   16,
    QMetaType::Void,

 // properties: name, type, flags
      18, QMetaType::Int, 0x00095107,

       0        // eod
};

void DocumentWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DocumentWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->actionCloseOther((*reinterpret_cast< DocumentWindow*(*)>(_a[1]))); break;
        case 1: _t->actionCopyPath(); break;
        case 2: _t->actionCopyFilename(); break;
        case 3: _t->actionRenameFilename(); break;
        case 4: _t->setFilenameSequenceNumber((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->resetFilenameSequenceNumber(); break;
        case 6: _t->documentCountChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 7: _t->documentModifiedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 8: _t->documentUrlChanged((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 9: _t->slotCloseOther(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DocumentWindow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DocumentWindow::*)(DocumentWindow * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentWindow::actionCloseOther)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DocumentWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentWindow::actionCopyPath)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DocumentWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentWindow::actionCopyFilename)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DocumentWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentWindow::actionRenameFilename)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DocumentWindow *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->filenameSequenceNumber(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DocumentWindow *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFilenameSequenceNumber(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
        DocumentWindow *_t = static_cast<DocumentWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resetFilenameSequenceNumber(); break;
        default: break;
        }
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DocumentWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMdiSubWindow::staticMetaObject>(),
    qt_meta_stringdata_DocumentWindow.data,
    qt_meta_data_DocumentWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DocumentWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DocumentWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DocumentWindow.stringdata0))
        return static_cast<void*>(this);
    return QMdiSubWindow::qt_metacast(_clname);
}

int DocumentWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMdiSubWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DocumentWindow::actionCloseOther(DocumentWindow * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DocumentWindow::actionCopyPath()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DocumentWindow::actionCopyFilename()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DocumentWindow::actionRenameFilename()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
