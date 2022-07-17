#include "widget.h"
#include "ui_widget.h"
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_getLocalTime_clicked()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    ui->localDate->setDate(currentTime.date());
    ui->localTime->setTime(currentTime.time());
    ui->timeAndDate->setDateTime(currentTime);
}
