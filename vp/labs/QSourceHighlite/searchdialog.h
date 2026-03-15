#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    SearchDialog(QWidget *parent = nullptr);

private:
    QLineEdit *findLineEdit;
    QLineEdit *replaceLineEdit;

    QPushButton *findButton;
    QPushButton *replaceButton;
    QPushButton *replaceAllButton;
    QLabel *findLineLabel;
    QLabel *replaceLineLabel;


private slots:
    void on_findButton_clicked ();
    void on_replaceButton_clicked ();
    void on_replaceAllButton_clicked ();

signals:
    void findNext (const QString &text);
    void replaceText (const QString &find, const QString &replace);
    void replaceAll (const QString &find, const QString &replace);


};


#endif // SEARCHDIALOG_H
