#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QDebug>

#define out qDebug()

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->selectAll, &QPushButton::clicked, ui->lineEdit, &QLineEdit::selectAll);
    connect(ui->cut, &QPushButton::clicked, ui->lineEdit, &QLineEdit::cut);
    connect(ui->copy, &QPushButton::clicked, ui->lineEdit, &QLineEdit::copy);
    connect(ui->paste, &QPushButton::clicked, ui->lineEdit, &QLineEdit::paste);
    connect(ui->undo, &QPushButton::clicked, ui->lineEdit, &QLineEdit::undo);
    connect(ui->redo, &QPushButton::clicked, ui->lineEdit, &QLineEdit::redo);
    connect(ui->cut, &QPushButton::clicked, ui->lineEdit, &QLineEdit::cut);
    connect(ui->clearAll, &QPushButton::clicked, ui->lineEdit, &QLineEdit::clear);

    // 按钮点击，改变内容
    connect(ui->setConnect, &QPushButton::clicked, this, &MainWindow::StringChangeSignal);
    connect(this, &MainWindow::StringChange, ui->lineEdit, &QLineEdit::setText);

    // 自动保持内容一致
//    connect(ui->textLineEdit, &QLineEdit::textEdited, this, &MainWindow::StringChangeSignal);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StringChangeSignal()
{
    QString str;
    str = ui->textLineEdit->text();
    emit StringChange(str);
    out << "输出信号，改变内容：" << str;
}
