/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTXT;
    QAction *openTXT;
    QAction *openJSON;
    QAction *saveTXT;
    QAction *saveJSON;
    QAction *copy;
    QAction *paste;
    QAction *cut;
    QAction *clear;
    QAction *undo;
    QAction *redo;
    QAction *search;
    QAction *Exit;
    QAction *showRunner;
    QAction *hideRunner;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *langComboBox;
    QLabel *label_2;
    QComboBox *themeComboBox;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *Save_As;
    QMenu *Open_As;
    QMenu *Edit;
    QMenu *Run;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionTXT = new QAction(MainWindow);
        actionTXT->setObjectName(QString::fromUtf8("actionTXT"));
        openTXT = new QAction(MainWindow);
        openTXT->setObjectName(QString::fromUtf8("openTXT"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("text-x-generic");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        openTXT->setIcon(icon);
        openJSON = new QAction(MainWindow);
        openJSON->setObjectName(QString::fromUtf8("openJSON"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        openJSON->setIcon(icon1);
        saveTXT = new QAction(MainWindow);
        saveTXT->setObjectName(QString::fromUtf8("saveTXT"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        saveTXT->setIcon(icon2);
        saveJSON = new QAction(MainWindow);
        saveJSON->setObjectName(QString::fromUtf8("saveJSON"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("document-save-as");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        saveJSON->setIcon(icon3);
        copy = new QAction(MainWindow);
        copy->setObjectName(QString::fromUtf8("copy"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        copy->setIcon(icon4);
        paste = new QAction(MainWindow);
        paste->setObjectName(QString::fromUtf8("paste"));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("edit-paste");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        paste->setIcon(icon5);
        cut = new QAction(MainWindow);
        cut->setObjectName(QString::fromUtf8("cut"));
        QIcon icon6;
        iconThemeName = QString::fromUtf8("edit-cut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        cut->setIcon(icon6);
        clear = new QAction(MainWindow);
        clear->setObjectName(QString::fromUtf8("clear"));
        QIcon icon7;
        iconThemeName = QString::fromUtf8("edit-delete");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        clear->setIcon(icon7);
        undo = new QAction(MainWindow);
        undo->setObjectName(QString::fromUtf8("undo"));
        QIcon icon8;
        iconThemeName = QString::fromUtf8("edit-undo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        undo->setIcon(icon8);
        redo = new QAction(MainWindow);
        redo->setObjectName(QString::fromUtf8("redo"));
        QIcon icon9;
        iconThemeName = QString::fromUtf8("edit-redo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        redo->setIcon(icon9);
        search = new QAction(MainWindow);
        search->setObjectName(QString::fromUtf8("search"));
        QIcon icon10;
        iconThemeName = QString::fromUtf8("edit-find");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        search->setIcon(icon10);
        Exit = new QAction(MainWindow);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        QIcon icon11;
        iconThemeName = QString::fromUtf8("application-exit");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        Exit->setIcon(icon11);
        showRunner = new QAction(MainWindow);
        showRunner->setObjectName(QString::fromUtf8("showRunner"));
        hideRunner = new QAction(MainWindow);
        hideRunner->setObjectName(QString::fromUtf8("hideRunner"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 0));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        langComboBox = new QComboBox(groupBox);
        langComboBox->setObjectName(QString::fromUtf8("langComboBox"));

        formLayout->setWidget(1, QFormLayout::LabelRole, langComboBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        themeComboBox = new QComboBox(groupBox);
        themeComboBox->setObjectName(QString::fromUtf8("themeComboBox"));

        formLayout->setWidget(3, QFormLayout::LabelRole, themeComboBox);


        horizontalLayout->addWidget(groupBox);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Save_As = new QMenu(menu);
        Save_As->setObjectName(QString::fromUtf8("Save_As"));
        Save_As->setIcon(icon3);
        Open_As = new QMenu(menu);
        Open_As->setObjectName(QString::fromUtf8("Open_As"));
        QIcon icon12;
        iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon12 = QIcon::fromTheme(iconThemeName);
        } else {
            icon12.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        Open_As->setIcon(icon12);
        Edit = new QMenu(menubar);
        Edit->setObjectName(QString::fromUtf8("Edit"));
        Run = new QMenu(menubar);
        Run->setObjectName(QString::fromUtf8("Run"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMinimumSize(QSize(0, 24));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(Edit->menuAction());
        menubar->addAction(Run->menuAction());
        menu->addAction(Save_As->menuAction());
        menu->addAction(Open_As->menuAction());
        menu->addAction(Exit);
        Save_As->addAction(saveTXT);
        Save_As->addAction(saveJSON);
        Open_As->addAction(openTXT);
        Open_As->addAction(openJSON);
        Edit->addAction(copy);
        Edit->addAction(paste);
        Edit->addAction(cut);
        Edit->addAction(clear);
        Edit->addAction(undo);
        Edit->addAction(redo);
        Edit->addAction(search);
        Run->addAction(showRunner);
        Run->addAction(hideRunner);
        toolBar->addAction(openTXT);
        toolBar->addAction(openJSON);
        toolBar->addSeparator();
        toolBar->addAction(saveTXT);
        toolBar->addAction(saveJSON);
        toolBar->addSeparator();
        toolBar->addAction(search);
        toolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(copy, SIGNAL(triggered()), plainTextEdit, SLOT(copy()));
        QObject::connect(paste, SIGNAL(triggered()), plainTextEdit, SLOT(paste()));
        QObject::connect(cut, SIGNAL(triggered()), plainTextEdit, SLOT(cut()));
        QObject::connect(undo, SIGNAL(triggered()), plainTextEdit, SLOT(undo()));
        QObject::connect(redo, SIGNAL(triggered()), plainTextEdit, SLOT(redo()));
        QObject::connect(clear, SIGNAL(triggered()), plainTextEdit, SLOT(clear()));

        langComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionTXT->setText(QCoreApplication::translate("MainWindow", "TXT", nullptr));
        openTXT->setText(QCoreApplication::translate("MainWindow", "TXT", nullptr));
        openJSON->setText(QCoreApplication::translate("MainWindow", "JSON", nullptr));
        saveTXT->setText(QCoreApplication::translate("MainWindow", "TXT", nullptr));
        saveJSON->setText(QCoreApplication::translate("MainWindow", "JSON", nullptr));
        copy->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        paste->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr));
        cut->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\200\320\265\320\267\320\260\321\202\321\214", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        undo->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        redo->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\321\214", nullptr));
        search->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        Exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        showRunner->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", nullptr));
        hideRunner->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\321\200\321\213\321\202\321\214", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Language:", nullptr));
        langComboBox->setCurrentText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Theme", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        Save_As->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
        Open_As->setTitle(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\272\320\260\320\272...", nullptr));
        Edit->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", nullptr));
        Run->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\320\272", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
