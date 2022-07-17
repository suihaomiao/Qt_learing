#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSpinBox>
#include "qperson.h"
#include <qpushbutton.h>
#include <QMetaProperty>

#define cout qDebug()

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    boy = new QPerson("王小二");
    boy->setage(10);
    boy->setProperty("score", 90);
    boy->setProperty("sex", "boy");
    girl = new QPerson("翠花");
    girl->setProperty("age", 12);
    girl->setProperty("socre", 95);
    girl->setProperty("sex", "girl");

    ui->boySpinBox->setProperty("isBoy", true);
    ui->boySpinBox->setValue(10);
    ui->girlSpinBox->setProperty("isBoy", false);
    ui->girlSpinBox->setValue(12);

    connect(ui->boySpinBox, SIGNAL(valueChanged(int)), this, SLOT(ageIncrement(int)));
    connect(ui->girlSpinBox, SIGNAL(valueChanged(int)), this, SLOT(ageIncrement(int)));
    connect(ui->clearText, &QPushButton::clicked, ui->textEdit, &QTextEdit::clear);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ageIncrement(int age)
{
    qDebug() << "debug info";
    QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
    if (spinBox != nullptr && spinBox->property("isBoy").toBool()) {
        boy->setProperty("age", age);
        ui->textEdit->append(QString("%1's age = %2").arg(boy->name()).arg(boy->age()));
    } else {
        girl->setProperty("age", age);
        ui->textEdit->append(QString("%1's age = %2").arg(girl->name()).arg(girl->age()));
    }
}

void Widget::on_boyIncreAge_clicked()
{
    unsigned age = boy->age();
    age++;
    emit boy->ageChange(age);
    ui->boySpinBox->setValue(age);
}

void Widget::on_girlIncreAge_clicked()
{
    unsigned age = girl->age();
    age++;
    emit girl->ageChange(age);
    ui->girlSpinBox->setValue(age);
}

void Widget::on_showClassInfo_clicked()
{
    ui->textEdit->clear();
    ui->textEdit->append("=======输出Person信息=======\n");
    const auto boyMeta =boy->metaObject();
    ui->textEdit->append(QString("class name:%1\n").arg(boyMeta->className()));
//    ui->textEdit->append(QString("class info:%1").arg());
    for (int i = boyMeta->propertyOffset(); i < boyMeta->propertyCount(); ++i) {
        QMetaProperty property = boyMeta->property(i);
        QString propertyValue =boy->property(property.name()).toString();
        ui->textEdit->append(QString("%1 : %2").arg(property.name()).arg(propertyValue));
    }
}
