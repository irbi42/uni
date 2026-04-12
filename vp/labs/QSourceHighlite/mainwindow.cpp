/*
 * Copyright (c) 2019-2020 Waqar Ahmed -- <waqar.17a@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qsourcehighliterthemes.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QMessageBox>
#include <QPushButton>
#include <QLayout>
#include <QSplitter>
#include <QTimer>

using namespace QSourceHighlite;

QHash<QString, QSourceHighliter::Language> MainWindow::_langStringToEnum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentFile("")
    , isUnnamed(true)
{
    ui->setupUi(this);

    initLangsEnum();
    initLangsComboBox();
    initThemesComboBox();


    ui->plainTextEdit->document()->setModified(false);
    pyRunnerWidget = new QWidget();
    pyRunnerWidget->setMinimumWidth(400);
    runButton = new QPushButton("Выполнить", pyRunnerWidget);
    stopButton = new QPushButton("Остановить", pyRunnerWidget);
    QHBoxLayout *pyRunnerLayout = new QHBoxLayout();
    QVBoxLayout *pyRunnerButtonLayout = new QVBoxLayout();
    runnerOutput = new QPlainTextEdit();
    runnerOutput->setReadOnly(true);
    pyRunnerButtonLayout->addWidget(runButton);
    pyRunnerButtonLayout->addWidget(stopButton);
    pyRunnerLayout->addLayout(pyRunnerButtonLayout);
    pyRunnerLayout->addWidget(runnerOutput);

    pyRunnerWidget->setLayout(pyRunnerLayout);

    QSplitter *mainSplitter = new QSplitter();
    mainSplitter->addWidget(ui->centralwidget);
    ui->centralwidget->setMinimumWidth(500);
    mainSplitter->addWidget(pyRunnerWidget);

    setCentralWidget(mainSplitter);

    pyRunnerWidget->hide();


    //set highlighter
    QFont f = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    ui->plainTextEdit->setFont(f);
    highlighter = new QSourceHighliter(ui->plainTextEdit->document());

    connect(ui->langComboBox,
            static_cast<void (QComboBox::*) (const QString&)>(&QComboBox::currentTextChanged),
            this, &MainWindow::languageChanged);
    connect(ui->themeComboBox,
            static_cast<void (QComboBox::*) (int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::themeChanged);

    ui->langComboBox->setCurrentText("Asm");
    languageChanged("Asm");
    //    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::printDebug);

    connect(ui->saveTXT, &QAction::triggered, this, &MainWindow::on_SaveTXT_triggered);
    connect(ui->saveJSON, &QAction::triggered, this, &MainWindow::on_SaveJSON_triggered);
    connect(ui->openTXT, &QAction::triggered, this, &MainWindow::on_OpenTXT_triggered);
    connect(ui->openJSON, &QAction::triggered, this, &MainWindow::on_OpenJSON_triggered);
    connect(ui->Exit, &QAction::triggered, this, &MainWindow::onExit);
    connect(ui->search, &QAction::triggered, this, &MainWindow::onSearch);

    connect(ui->showRunner, &QAction::triggered, this, &MainWindow::onShowRunner);
    connect(ui->hideRunner, &QAction::triggered, this, &MainWindow::onHideRunner);
    connect(runButton, &QPushButton::clicked, this, &MainWindow::onRunScript);
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::onStopScript);

    highlighter->rehighlight();



    connect(&process, &QProcess::readyReadStandardOutput, this, [this]() {
        runnerOutput->appendPlainText(process.readAllStandardOutput());
    });

    connect(&process, &QProcess::readyReadStandardError, this, [this]() {
        runnerOutput->appendPlainText("[ERROR] " + process.readAllStandardError());
    });

    connect(&process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [this](int exitCode, QProcess::ExitStatus status) {
                if (status == QProcess::NormalExit && exitCode == 0) {
                    runnerOutput->appendPlainText("\nСкрипт завершен");
                } else if (status == QProcess::NormalExit && exitCode != 0) {
                    runnerOutput->appendPlainText(QString("\nКод возврата: %1").arg(exitCode));
                }
                if (QFile::exists("temp.py")) {
                    QFile::remove("temp.py");
                }
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (!ui->plainTextEdit->document()->isModified()) {
        event->accept();
        return;
    }
    QMessageBox exMsg;
    exMsg.setText("Остались несохраненные изменения. Вы уверены что хотите выйти?");
    QPushButton * saveTXT = exMsg.addButton("save as TXT", QMessageBox::AcceptRole);
    QPushButton * saveJSON = exMsg.addButton("save as JSON", QMessageBox::AcceptRole);
    exMsg.addButton(QMessageBox::Discard);
    exMsg.addButton(QMessageBox::Cancel);
    exMsg.setDefaultButton(QMessageBox::Cancel);

    int ret = exMsg.exec();

    switch (ret) {
    case QMessageBox::Discard:
        ui->statusbar->showMessage("Disgard");
        event->accept();
        break;
    case QMessageBox::Cancel:
        event->ignore();
        ui->statusbar->showMessage("Cancel", 3000);
        break;
    default:
        if (exMsg.clickedButton() == saveTXT) {
            on_SaveTXT_triggered();
        } else if (exMsg.clickedButton() == saveJSON) {
            on_SaveJSON_triggered();
        }
        event->accept();
        break;
    }
}

void MainWindow::onExit() {
    close();
}

void MainWindow::onShowRunner() {
    pyRunnerWidget->show();
}

void MainWindow::onHideRunner() {
    pyRunnerWidget->hide();
}

void MainWindow::onRunScript() {
    if (ui->langComboBox->currentText() != "Python") {
        QMessageBox::information(this, "Ошибка", "Функционал не доступен для выбранного языка");
        return;
    }

    if (process.state() == QProcess::Running) {
        QMessageBox::information(this, "Предупреждение", "Процесс уже запущен. Сначала остановите текущий.");
        return;
    }

    QString fileName;
    if (currentFile.isEmpty() || ui->plainTextEdit->document()->isModified()) {
        fileName = "temp.py";
    } else {
        fileName = currentFile;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->statusbar->showMessage("Ошибка: не удалось открыть файл для записи.", 3000);
        return;
    }
    QString text = ui->plainTextEdit->toPlainText();
    QTextStream out(&file);
    out << text;

    file.close();
    runnerOutput->clear();

    process.start("python3", QStringList() << fileName);

    if (!process.waitForStarted()) {
        QMessageBox::critical(this, "Ошибка", "Python не установлен или не найден в PATH");
        return;
    }

    QTimer::singleShot(3000, this, [this, fileName]() {
        if (process.state() == QProcess::Running) {
            process.kill();
            process.waitForFinished(1000);
            runnerOutput->appendPlainText("Превышено время выполнения (3 сек). Процесс остановлен.\n");
        }
        if (fileName == "temp.py" && QFile::exists(fileName)) {
            QFile::remove(fileName);
        }
    });
}

void MainWindow::onStopScript() {
    if(process.state() == QProcess::Running) {
        process.kill();
        runnerOutput->setPlainText(runnerOutput->toPlainText() + "Процесс остановлен.\n");
        ui->statusbar->showMessage("Процесс остановлен.", 3000);
    }
}


void MainWindow::onSearch() {
    SearchDialog dialog(this);
    connect(&dialog, &SearchDialog::findNext, this, &MainWindow::onFindNext);
    connect(&dialog, &SearchDialog::replaceText, this, &MainWindow::onReplaceText);
    connect(&dialog, &SearchDialog::replaceAll, this, &MainWindow::onReplaceAll);
    dialog.exec();
}

void MainWindow::onFindNext(const QString &text) {
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    QString content = ui->plainTextEdit->toPlainText();
    int pos = content.indexOf(text, cursor.position(), Qt::CaseSensitive);

    if (pos >= 0) {
        cursor.setPosition(pos);
        cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, text.length());
        ui->plainTextEdit->setTextCursor(cursor);
        ui->statusbar->showMessage("Найдено: " + text, 3000);
    } else {
        pos = content.indexOf(text, 0, Qt::CaseSensitive);
        if (pos >= 0) {
            cursor.setPosition(pos);
            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, text.length());
            ui->plainTextEdit->setTextCursor(cursor);
            ui->statusbar->showMessage("Поиск с начала. Найдено: " + text, 3000);
        } else {
            QMessageBox::information(this, "Поиск", "Совпадений не найдено");
            ui->statusbar->showMessage("Совпадений не найдено", 3000);
        }

    }

}

void MainWindow::onReplaceText(const QString &find, const QString &replace) {
    QTextCursor found = ui->plainTextEdit->textCursor();
    QString selected = found.selectedText();

    if (!selected.isEmpty() && selected == find) {
        found.insertText(replace);
        ui->plainTextEdit->setTextCursor(found);
    } else {
        onFindNext(find);
        found = ui->plainTextEdit->textCursor();
        selected = found.selectedText();
        if (!selected.isEmpty() && selected == find) {
            found.insertText(replace);
            ui->plainTextEdit->setTextCursor(found);
        }
    }

    highlighter->rehighlight();
}

void MainWindow::onReplaceAll(const QString &find, const QString &replace) {
    QString content = ui->plainTextEdit->toPlainText();
    QString newContent = content.replace(find, replace, Qt::CaseSensitive);
    ui->plainTextEdit->setPlainText(newContent);
    highlighter->rehighlight();
    QString message = (QString("Все вхождения '%1' замененны на '%2'").arg(find).arg(replace));
    ui->statusbar->showMessage(message);
}

void MainWindow::on_SaveTXT_triggered () {
    QString fileName = QFileDialog::getSaveFileName (this, "Сохранить TXT файл", "", "TXT файлы *.txt");
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->statusbar->showMessage("Ошибка: не удалось открыть файл для записи.", 3000);
        return;
    }
    QString text = ui->plainTextEdit->toPlainText();
    QTextStream out(&file);

    out << text;

    file.close();

    isUnnamed = false;
    currentFile = fileName;
    ui->statusbar->showMessage("Файл " + fileName + " сохранен", 3000);
}

void MainWindow::on_OpenTXT_triggered () {
    QString fileName = QFileDialog::getOpenFileName (this, "Сохранить TXT файл", "", "TXT файлы *.txt");
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->statusbar->showMessage("Ошибка: не удалось открыть файл для записи.", 3000);
        return;
    }
    ui->plainTextEdit->setPlainText(file.readAll());

    file.close();

    isUnnamed = false;
    currentFile = fileName;
    ui->statusbar->showMessage("Файл " + fileName + " открыт", 3000);
}


void MainWindow::on_SaveJSON_triggered () {
    QString fileName = QFileDialog::getSaveFileName (this, "Сохранить JSON файл", "", "JSON файлы *.json");
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->statusbar->showMessage("Ошибка: не удалось открыть файл для записи.", 3000);
        return;
    }
    QJsonObject root;
    root["language"] = ui->langComboBox->currentText();
    root["theme"] = ui->themeComboBox->currentData().toInt();
    root["text"] = ui->plainTextEdit->toPlainText();

    QJsonDocument doc(root);
    file.write(doc.toJson());

    file.close();

    isUnnamed = false;
    currentFile = fileName;
    ui->statusbar->showMessage("Файл " + fileName + " сохранен", 3000);
}

void MainWindow::on_OpenJSON_triggered () {
    QString fileName = QFileDialog::getOpenFileName (this, "Сохранить JSON файл", "", "JSON файлы *.json");
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->statusbar->showMessage("Ошибка: не удалось открыть файл.", 3000);
        return;
    }
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);
    file.close();
    if (error.error != QJsonParseError::NoError) {
        ui->statusbar->showMessage("Ошибка парсинга.", 3000);
        return;
    }

    QJsonObject obj = doc.object();
    QString lang = obj["language"].toString();
    int theme = obj["theme"].toInt();
    QString text = obj["text"].toString();

    ui->plainTextEdit->setPlainText(text);

    if (!lang.isEmpty()) {
        ui->langComboBox->setCurrentText(lang);
    }

    ui->themeComboBox->setCurrentIndex(theme);

    isUnnamed = false;
    currentFile = fileName;
    ui->statusbar->showMessage("Файл " + fileName + " сохранен", 3000);
}

void MainWindow::initLangsEnum()
{
    MainWindow::_langStringToEnum = QHash<QString, QSourceHighliter::Language> {
        { QLatin1String("Asm"), QSourceHighliter::CodeAsm },
        { QLatin1String("Bash"), QSourceHighliter::CodeBash },
        { QLatin1String("C"), QSourceHighliter::CodeC },
        { QLatin1String("C++"), QSourceHighliter::CodeCpp },
        { QLatin1String("CMake"), QSourceHighliter::CodeCMake },
        { QLatin1String("CSharp"), QSourceHighliter::CodeCSharp },
        { QLatin1String("Css"), QSourceHighliter::CodeCSS },
        { QLatin1String("Go"), QSourceHighliter::CodeGo },
        { QLatin1String("Html"), QSourceHighliter::CodeXML },
        { QLatin1String("Ini"), QSourceHighliter::CodeINI },
        { QLatin1String("Java"), QSourceHighliter::CodeJava },
        { QLatin1String("Javascript"), QSourceHighliter::CodeJava },
        { QLatin1String("Json"), QSourceHighliter::CodeJSON },
        { QLatin1String("Lua"), QSourceHighliter::CodeLua },
        { QLatin1String("Make"), QSourceHighliter::CodeMake },
        { QLatin1String("Php"), QSourceHighliter::CodePHP },
        { QLatin1String("Python"), QSourceHighliter::CodePython },
        { QLatin1String("Qml"), QSourceHighliter::CodeQML },
        { QLatin1String("Rhai"), QSourceHighliter::CodeRhai },
        { QLatin1String("Rust"), QSourceHighliter::CodeRust },
        { QLatin1String("Sql"), QSourceHighliter::CodeSQL },
        { QLatin1String("Typescript"), QSourceHighliter::CodeTypeScript },
        { QLatin1String("V"), QSourceHighliter::CodeV },
        { QLatin1String("Vex"), QSourceHighliter::CodeVex },
        { QLatin1String("Xml"), QSourceHighliter::CodeXML },
        { QLatin1String("Yaml"), QSourceHighliter::CodeYAML }
    };
}

void MainWindow::initThemesComboBox()
{
    ui->themeComboBox->addItem("Default", 0);
    ui->themeComboBox->addItem("Monokai", QSourceHighliter::Themes::Monokai);
    ui->themeComboBox->addItem("Dark Theme", QSourceHighliter::Themes::DarkTheme);
    ui->themeComboBox->addItem("Light Theme", QSourceHighliter::Themes::LightTheme);

    ui->themeComboBox->setCurrentIndex(0);
}

void MainWindow::initLangsComboBox() {
    ui->langComboBox->addItem("Asm");
    ui->langComboBox->addItem("Bash");
    ui->langComboBox->addItem("C");
    ui->langComboBox->addItem("C++");
    ui->langComboBox->addItem("CMake");
    ui->langComboBox->addItem("CSharp");
    ui->langComboBox->addItem("Css");
    ui->langComboBox->addItem("Go");
    ui->langComboBox->addItem("Html");
    ui->langComboBox->addItem("Ini");
    ui->langComboBox->addItem("Javascript");
    ui->langComboBox->addItem("Java");
    ui->langComboBox->addItem("Lua");
    ui->langComboBox->addItem("Make");
    ui->langComboBox->addItem("Php");
    ui->langComboBox->addItem("Python");
    ui->langComboBox->addItem("Qml");
    ui->langComboBox->addItem("Rust");
    ui->langComboBox->addItem("Sql");
    ui->langComboBox->addItem("Typescript");
    ui->langComboBox->addItem("V");
    ui->langComboBox->addItem("Vex");
    ui->langComboBox->addItem("Xml");
    ui->langComboBox->addItem("Yaml");
}

void MainWindow::themeChanged(int) {
    QSourceHighliter::Themes theme = (QSourceHighliter::Themes)ui->themeComboBox->currentData().toInt();
    highlighter->setTheme(theme);
    applyEditorBackground(theme);
}

void MainWindow::applyEditorBackground(QSourceHighlite::QSourceHighliter::Themes theme) {
    auto themeFormats = QSourceHighliterTheme::theme(theme);
    QTextCharFormat blockFormat = themeFormats.value(QSourceHighliter::CodeBlock);
    QColor bgColor = blockFormat.background().color();
    // if(!bgColor.isValid()) {
    //     bgColor = "#ffffff";
    // }
    QString styleSheet = QString("QPlainTextEdit {background-color: %1; }").arg(bgColor.name());
    ui->plainTextEdit->setStyleSheet(styleSheet);
    ui->statusbar->showMessage(styleSheet);

}

void MainWindow::languageChanged(const QString &lang) {
    highlighter->setCurrentLanguage(_langStringToEnum.value(lang));
    highlighter->rehighlight();
}
