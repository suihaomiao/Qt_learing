#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void StringChangeSignal();

signals:
    void StringChange(QString& str);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
