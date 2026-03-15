/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(399, 210);
        textBrowser = new QTextBrowser(Form);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 381, 191));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QDialog *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Dialog", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\220\320\233\320\254\320\232\320\243\320\233\320\257\320\242\320\236\320\240</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265:</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-lef"
                        "t:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\255\321\202\320\276 \320\277\321\200\320\276\321\201\321\202\320\276 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200, \320\275\320\270\321\207\320\265\320\263\320\276 \320\275\320\265\320\276\320\261\321\213\321\207\320\275\320\276\320\263\320\276...</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\244\321\203\320\275\320\272\321\206\320\270\320\270:</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\236\320\275 \320\274\320\276\320\266\320\265\321\202 \321\201\321\207\320\270\321\202\320\260\321\202\321\214 \321\207\320\270\321\201\320\273\320\260 \320\267\320\260 \321\202\320\265\320\261\321\217.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0p"
                        "x;\">\320\230\321\201\321\202\320\276\321\200\320\270\321\217:</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\241\320\276\321\205\321\200\320\260\320\275\321\217\320\265\321\202 \321\207\320\270\321\201\320\273\320\276 \320\262 \320\270\321\201\321\202\320\276\321\200\320\270\321\216, \321\207\321\202\320\276\320\261\321\213 \321\202\321\213 \320\275\320\265 \320\267\320\260\320\261\321\213\320\273.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\224\320\276\320\277\320\276\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\265 \320\267\320\260\320\264\320\260\320\275\320\270\320\265:</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\255\320\272\321\201\320\277\320\276\321\200\321\202\320\270\321\200\321\203"
                        "\320\265\321\202 \320\270\321\201\321\202\320\276\321\200\320\270\321\216 \320\262 \321\204\320\260\320\271\320\273 (\320\277\320\276\321\202\320\276\320\274\321\203 \321\207\321\202\320\276 \320\275\320\260\320\264\320\276).</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
