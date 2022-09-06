#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include<QLCDNumber>
#include<QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("王者荣耀兵线计时");
    setWindowIcon(QIcon(":/66.jpg"));
    //setFixedSize(200,300);设置窗口固定大小

    int sec = 0, min = 0;
    int showSec = 10;
    int showMin = 0;
    QString ShowMsg=QString("下一波兵线时间：%1:%2").arg(showMin).arg(showSec);
    QString LcdMsg=QString("%1.%2").arg(showMin).arg(showSec);
    connect(timer,&QTimer::timeout,this,[=]()mutable{
        ui->curTime->setTextFormat(Qt::RichText);
        ui->curTime->setText(ShowMsg);
        ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        ui->lcdNumber->display(LcdMsg);
        if (++sec == 60) {
            sec = 0;
            min++;
        }
        if (sec == showSec && min == showMin) {
            showSec += 33;//每33秒出兵线
            if (showSec >= 60) {
                showSec -= 60;
                showMin += 1;
            }
            ShowMsg=QString("下一波兵线时间：%1:%2").arg(showMin).arg(showSec);
            LcdMsg=QString("%1.%2").arg(showMin).arg(showSec);
            ui->curTime->setText(ShowMsg);
            ui->lcdNumber->display(LcdMsg);
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loopBtn_clicked()
{
    //启动定时器
    if(timer->isActive())
    {
        timer->stop();//关闭定时器
        ui->loopBtn->setText("开始计时");
    }
    else
    {
        ui->loopBtn->setText("停止计时");
        timer->start(1000);//1000ms==1s
    }

}
