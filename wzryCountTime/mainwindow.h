#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loopBtn_clicked();

private:
    Ui::MainWindow *ui;
    //创建定时器对象
    QTimer* timer=new QTimer(this);

};
#endif // MAINWINDOW_H
