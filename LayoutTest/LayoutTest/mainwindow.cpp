#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>

#define out qDebug()

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 代码管理布局

//    // 创建垂水平布局器， 账号和密码
//    QHBoxLayout *account = new QHBoxLayout();
//    account->addWidget(ui->accountLable);
//    account->addWidget(ui->account);

//    QHBoxLayout *passwd = new QHBoxLayout();
//    passwd->addWidget(ui->passwdLable);
//    passwd->addWidget(ui->password);

//    // 创建一个垂直布局器，账号和密码
//    QVBoxLayout *qhbox1 = new QVBoxLayout();
//    // 将登陆和注册按钮放在该布局器中
//    qhbox1->addLayout(account);
//    qhbox1->addLayout(passwd);

//    // 创建水平布局器，包含登陆和注册
//    QVBoxLayout *button = new QVBoxLayout();
//    button->addWidget(ui->logIn);
//    button->addWidget(ui->registers);

//    out << "debug";
//    QGridLayout *grid = new QGridLayout(this->centralWidget());
//    grid->addWidget(ui->welcome,0 ,0 );
//    grid->addLayout(qhbox1, 1, 0);
//    grid->addLayout(button, 2, 0);

//    setLayout(grid);
    ui->centralWidget->setLayout(ui->gridLayout);
    ui->password->setEchoMode(QLineEdit::Password);
    ui->passwdCheck->setCheckState(Qt::Unchecked);
    connect(ui->passwdCheck, &QCheckBox::stateChanged, this, &MainWindow::ChangePasswdStatus);
    connect(ui->logIn, &QPushButton::clicked, this, &MainWindow::Login);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangePasswdStatus(int state)
{
//    out << state;
    bool echoMode = state == Qt::Unchecked ? false : true;
    if (!echoMode) {
        ui->password->setEchoMode(QLineEdit::Password);
    } else {
        ui->password->setEchoMode(QLineEdit::Normal);
    }
}

void MainWindow::Login()
{
    QString account = ui->account->text();
    QString passwd = ui->password->text();

    // 认证过程
    if (account == "shm" && passwd == "123456") {
        out << "登陆成功";
        QMessageBox::information(this, "登陆成功", "欢迎使用", QMessageBox::Open | QMessageBox::Yes, QMessageBox::Yes);
    } else {
        QMessageBox::warning(this, "账号密码不匹配", "兄弟，开guest吧");
    }
}


