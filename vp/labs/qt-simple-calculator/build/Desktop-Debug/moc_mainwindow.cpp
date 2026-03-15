/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[364];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "onSaveAction"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 13), // "onShowHistory"
QT_MOC_LITERAL(4, 39, 13), // "onHideHistory"
QT_MOC_LITERAL(5, 53, 14), // "onClearHistory"
QT_MOC_LITERAL(6, 68, 7), // "onAbout"
QT_MOC_LITERAL(7, 76, 20), // "onHistoryItemClicked"
QT_MOC_LITERAL(8, 97, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 114, 4), // "item"
QT_MOC_LITERAL(10, 119, 21), // "clearStatusBarMessage"
QT_MOC_LITERAL(11, 141, 17), // "updateHistoryList"
QT_MOC_LITERAL(12, 159, 8), // "onExport"
QT_MOC_LITERAL(13, 168, 8), // "onImport"
QT_MOC_LITERAL(14, 177, 19), // "numberGroup_clicked"
QT_MOC_LITERAL(15, 197, 16), // "QAbstractButton*"
QT_MOC_LITERAL(16, 214, 19), // "actionGroup_clicked"
QT_MOC_LITERAL(17, 234, 20), // "on_actionDel_clicked"
QT_MOC_LITERAL(18, 255, 21), // "on_actionCalc_clicked"
QT_MOC_LITERAL(19, 277, 16), // "on_comma_clicked"
QT_MOC_LITERAL(20, 294, 22), // "on_actionClear_clicked"
QT_MOC_LITERAL(21, 317, 24), // "on_actionPercent_clicked"
QT_MOC_LITERAL(22, 342, 21) // "on_actionSign_clicked"

    },
    "MainWindow\0onSaveAction\0\0onShowHistory\0"
    "onHideHistory\0onClearHistory\0onAbout\0"
    "onHistoryItemClicked\0QListWidgetItem*\0"
    "item\0clearStatusBarMessage\0updateHistoryList\0"
    "onExport\0onImport\0numberGroup_clicked\0"
    "QAbstractButton*\0actionGroup_clicked\0"
    "on_actionDel_clicked\0on_actionCalc_clicked\0"
    "on_comma_clicked\0on_actionClear_clicked\0"
    "on_actionPercent_clicked\0on_actionSign_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    1,  109,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    1,  116,    2, 0x08 /* Private */,
      16,    1,  119,    2, 0x08 /* Private */,
      17,    0,  122,    2, 0x08 /* Private */,
      18,    0,  123,    2, 0x08 /* Private */,
      19,    0,  124,    2, 0x08 /* Private */,
      20,    0,  125,    2, 0x08 /* Private */,
      21,    0,  126,    2, 0x08 /* Private */,
      22,    0,  127,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onSaveAction(); break;
        case 1: _t->onShowHistory(); break;
        case 2: _t->onHideHistory(); break;
        case 3: _t->onClearHistory(); break;
        case 4: _t->onAbout(); break;
        case 5: _t->onHistoryItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->clearStatusBarMessage(); break;
        case 7: _t->updateHistoryList(); break;
        case 8: _t->onExport(); break;
        case 9: _t->onImport(); break;
        case 10: _t->numberGroup_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 11: _t->actionGroup_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 12: _t->on_actionDel_clicked(); break;
        case 13: _t->on_actionCalc_clicked(); break;
        case 14: _t->on_comma_clicked(); break;
        case 15: _t->on_actionClear_clicked(); break;
        case 16: _t->on_actionPercent_clicked(); break;
        case 17: _t->on_actionSign_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
