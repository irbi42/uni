#include "searchdialog.h"
#include "qaction.h"


SearchDialog::SearchDialog(QWidget *parent)
    : QDialog(parent)
{
    findButton = new QPushButton("Найти далее", this);
    replaceButton = new QPushButton("Заменить", this);
    replaceAllButton = new QPushButton("Заменить все", this);
    findLineLabel = new QLabel("Найти:", this);
    replaceLineLabel = new QLabel("Заменить:", this);

    findLineEdit = new QLineEdit(this);
    replaceLineEdit = new QLineEdit(this);

    QHBoxLayout *findLayout = new QHBoxLayout;
    findLayout->addWidget(findLineLabel);
    findLayout->addWidget(findLineEdit);
    QHBoxLayout *replaceLayout = new QHBoxLayout;
    replaceLayout->addWidget(replaceLineLabel);
    replaceLayout->addWidget(replaceLineEdit);
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(findButton);
    buttonsLayout->addWidget(replaceButton);
    buttonsLayout->addWidget(replaceAllButton);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(findLayout);
    mainLayout->addLayout(replaceLayout);
    mainLayout->addLayout(buttonsLayout);




    connect(findButton, SIGNAL(clicked()), this, SLOT(on_findButton_clicked()));
    connect(replaceButton, SIGNAL(clicked()), this, SLOT(on_replaceButton_clicked()));
    connect(replaceAllButton, SIGNAL(clicked()), this, SLOT(on_replaceAllButton_clicked()));

}

void SearchDialog::on_findButton_clicked () {
    emit findNext(findLineEdit->text());
}

void SearchDialog::on_replaceButton_clicked () {
    emit replaceText(findLineEdit->text(), replaceLineEdit->text());
}

void SearchDialog::on_replaceAllButton_clicked (){
    emit replaceAll(findLineEdit->text(), replaceLineEdit->text());
}
