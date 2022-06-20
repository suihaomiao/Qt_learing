#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <qtextbrowser.h>
#include <qtextedit.h>
#include <QFileDialog>
#include <QFile>
#include <QByteArray>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->openFile, &QPushButton::clicked, this, &MainWindow::OpenFile);
    connect(ui->saveFile, &QPushButton::clicked, this, &MainWindow::SaveFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenFile()
{
    filePath = QFileDialog::getOpenFileName(this, tr("选择打开的文件"), ".", "text(*.txt) markdown(*.md)");
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "警告","打开文件失败");
        return;
    }
    QByteArray data = file.readAll();
    ui->textEdit->setText(data);
    ui->textBrowser->setText(data);
    file.close();
}

void MainWindow::SaveFile()
{
    QString data = ui->textEdit->toPlainText();
    QFile file(filePath);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QMessageBox::warning(this, "警告","打开文件失败");
        return;
    }
    file.write(data.toUtf8());
    file.close();
}

