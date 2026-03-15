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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Save;
    QAction *Show_history;
    QAction *Hide_history;
    QAction *About;
    QAction *Import;
    QAction *Export;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *displayPanel;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *actionClear;
    QPushButton *actionDel;
    QPushButton *actionPercent;
    QPushButton *actionDiv;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *num7;
    QPushButton *num8;
    QPushButton *num9;
    QPushButton *actionMul;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *num4;
    QPushButton *num5;
    QPushButton *num6;
    QPushButton *actionMinus;
    QHBoxLayout *horizontalLayout;
    QPushButton *num1;
    QPushButton *num2;
    QPushButton *num3;
    QPushButton *actionPlus;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *num0;
    QPushButton *comma;
    QPushButton *actionSign;
    QPushButton *actionCalc;
    QMenuBar *menuBar;
    QMenu *Menu;
    QMenu *History;
    QMenu *Info;
    QStatusBar *statusBar;
    QButtonGroup *actionGroup;
    QButtonGroup *numberGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(306, 328);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(306, 319));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #f5f5f5;\n"
"color: rgb(0, 0, 0);\n"
""));
        Save = new QAction(MainWindow);
        Save->setObjectName(QString::fromUtf8("Save"));
        Show_history = new QAction(MainWindow);
        Show_history->setObjectName(QString::fromUtf8("Show_history"));
        Hide_history = new QAction(MainWindow);
        Hide_history->setObjectName(QString::fromUtf8("Hide_history"));
        About = new QAction(MainWindow);
        About->setObjectName(QString::fromUtf8("About"));
        Import = new QAction(MainWindow);
        Import->setObjectName(QString::fromUtf8("Import"));
        Export = new QAction(MainWindow);
        Export->setObjectName(QString::fromUtf8("Export"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"min-width: 65;\n"
"min-height: 40;\n"
"max-width: 65;\n"
"max-height: 40;\n"
"}"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        displayPanel = new QLabel(centralWidget);
        displayPanel->setObjectName(QString::fromUtf8("displayPanel"));
        displayPanel->setMinimumSize(QSize(290, 40));
        displayPanel->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Open Sans"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setKerning(true);
        displayPanel->setFont(font);
        displayPanel->setLayoutDirection(Qt::LeftToRight);
        displayPanel->setStyleSheet(QString::fromUtf8("border: 1 solid #b8b8b8;\n"
"background-color: #fff;"));
        displayPanel->setScaledContents(true);
        displayPanel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        displayPanel->setWordWrap(true);
        displayPanel->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(displayPanel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        actionClear = new QPushButton(centralWidget);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionClear->setStyleSheet(QString::fromUtf8("background-color: #cb1a21;\n"
"color: #ffffff;"));

        horizontalLayout_5->addWidget(actionClear);

        actionDel = new QPushButton(centralWidget);
        actionDel->setObjectName(QString::fromUtf8("actionDel"));

        horizontalLayout_5->addWidget(actionDel);

        actionPercent = new QPushButton(centralWidget);
        actionPercent->setObjectName(QString::fromUtf8("actionPercent"));

        horizontalLayout_5->addWidget(actionPercent);

        actionDiv = new QPushButton(centralWidget);
        actionGroup = new QButtonGroup(MainWindow);
        actionGroup->setObjectName(QString::fromUtf8("actionGroup"));
        actionGroup->addButton(actionDiv);
        actionDiv->setObjectName(QString::fromUtf8("actionDiv"));

        horizontalLayout_5->addWidget(actionDiv);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        num7 = new QPushButton(centralWidget);
        numberGroup = new QButtonGroup(MainWindow);
        numberGroup->setObjectName(QString::fromUtf8("numberGroup"));
        numberGroup->addButton(num7);
        num7->setObjectName(QString::fromUtf8("num7"));

        horizontalLayout_3->addWidget(num7);

        num8 = new QPushButton(centralWidget);
        numberGroup->addButton(num8);
        num8->setObjectName(QString::fromUtf8("num8"));
        sizePolicy1.setHeightForWidth(num8->sizePolicy().hasHeightForWidth());
        num8->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(num8);

        num9 = new QPushButton(centralWidget);
        numberGroup->addButton(num9);
        num9->setObjectName(QString::fromUtf8("num9"));

        horizontalLayout_3->addWidget(num9);

        actionMul = new QPushButton(centralWidget);
        actionGroup->addButton(actionMul);
        actionMul->setObjectName(QString::fromUtf8("actionMul"));

        horizontalLayout_3->addWidget(actionMul);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        num4 = new QPushButton(centralWidget);
        numberGroup->addButton(num4);
        num4->setObjectName(QString::fromUtf8("num4"));

        horizontalLayout_2->addWidget(num4);

        num5 = new QPushButton(centralWidget);
        numberGroup->addButton(num5);
        num5->setObjectName(QString::fromUtf8("num5"));

        horizontalLayout_2->addWidget(num5);

        num6 = new QPushButton(centralWidget);
        numberGroup->addButton(num6);
        num6->setObjectName(QString::fromUtf8("num6"));

        horizontalLayout_2->addWidget(num6);

        actionMinus = new QPushButton(centralWidget);
        actionGroup->addButton(actionMinus);
        actionMinus->setObjectName(QString::fromUtf8("actionMinus"));

        horizontalLayout_2->addWidget(actionMinus);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        num1 = new QPushButton(centralWidget);
        numberGroup->addButton(num1);
        num1->setObjectName(QString::fromUtf8("num1"));
        sizePolicy1.setHeightForWidth(num1->sizePolicy().hasHeightForWidth());
        num1->setSizePolicy(sizePolicy1);
        num1->setMinimumSize(QSize(67, 42));
        num1->setMaximumSize(QSize(67, 42));

        horizontalLayout->addWidget(num1);

        num2 = new QPushButton(centralWidget);
        numberGroup->addButton(num2);
        num2->setObjectName(QString::fromUtf8("num2"));
        sizePolicy1.setHeightForWidth(num2->sizePolicy().hasHeightForWidth());
        num2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(num2);

        num3 = new QPushButton(centralWidget);
        numberGroup->addButton(num3);
        num3->setObjectName(QString::fromUtf8("num3"));
        sizePolicy1.setHeightForWidth(num3->sizePolicy().hasHeightForWidth());
        num3->setSizePolicy(sizePolicy1);
        num3->setMaximumSize(QSize(67, 42));

        horizontalLayout->addWidget(num3);

        actionPlus = new QPushButton(centralWidget);
        actionGroup->addButton(actionPlus);
        actionPlus->setObjectName(QString::fromUtf8("actionPlus"));

        horizontalLayout->addWidget(actionPlus);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 0, -1);
        num0 = new QPushButton(centralWidget);
        numberGroup->addButton(num0);
        num0->setObjectName(QString::fromUtf8("num0"));

        horizontalLayout_4->addWidget(num0);

        comma = new QPushButton(centralWidget);
        comma->setObjectName(QString::fromUtf8("comma"));

        horizontalLayout_4->addWidget(comma);

        actionSign = new QPushButton(centralWidget);
        actionSign->setObjectName(QString::fromUtf8("actionSign"));

        horizontalLayout_4->addWidget(actionSign);

        actionCalc = new QPushButton(centralWidget);
        actionCalc->setObjectName(QString::fromUtf8("actionCalc"));
        actionCalc->setStyleSheet(QString::fromUtf8("background-color: #3490cd;\n"
"color: #ffffff;"));

        horizontalLayout_4->addWidget(actionCalc);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 306, 23));
        Menu = new QMenu(menuBar);
        Menu->setObjectName(QString::fromUtf8("Menu"));
        History = new QMenu(menuBar);
        History->setObjectName(QString::fromUtf8("History"));
        Info = new QMenu(menuBar);
        Info->setObjectName(QString::fromUtf8("Info"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(Menu->menuAction());
        menuBar->addAction(History->menuAction());
        menuBar->addAction(Info->menuAction());
        Menu->addAction(Save);
        History->addAction(Show_history);
        History->addAction(Hide_history);
        History->addAction(Import);
        History->addAction(Export);
        Info->addAction(About);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        Show_history->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", nullptr));
        Hide_history->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\321\200\321\213\321\202\321\214", nullptr));
        About->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\270", nullptr));
        Import->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\320\277\320\276\321\200\321\202", nullptr));
        Export->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202", nullptr));
        displayPanel->setText(QString());
        actionClear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        actionDel->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        actionPercent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        actionDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        num7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        num8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        num9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        actionMul->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        num4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        num5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        num6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        actionMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        num1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        num2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        num3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        actionPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        num0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        comma->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        actionSign->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        actionCalc->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        Menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        History->setTitle(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217", nullptr));
        Info->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
