#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qperson.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void ageIncrement(int age);
private slots:
    void on_boyIncreAge_clicked();

    void on_girlIncreAge_clicked();

    void on_showClassInfo_clicked();

private:
    Ui::Widget *ui;
    QPerson *boy;
    QPerson *girl;
};

#endif // WIDGET_H
