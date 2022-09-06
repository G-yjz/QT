#include "mythread.h"
#include<QElapsedTimer>
#include<QDebug>
#include<algorithm>
using namespace std;

Generate::Generate(QObject *parent) : QThread(parent)
{

}

void Generate::recvNum(int num){
    m_num=num;
}

void Generate::run(){
    qDebug()<<"线程地址："<<QThread::currentThread();
    QVector<int> list;
    QElapsedTimer time;
    time.start();
    for(int i=0;i<m_num;++i){
        list.push_back(qrand()%100000);
    }
    int miLsec=time.elapsed();
    qDebug()<<"生成"<<m_num<<"用时："<<miLsec<<"毫秒";
    emit sendArray(list);
}


BubbleSort::BubbleSort(QObject *parent):QThread(parent)
{

}

void BubbleSort::recvArray(QVector<int> list)
{
    m_list=list;
}

void BubbleSort::run()
{
    qDebug()<<"冒泡线程地址："<<QThread::currentThread();
    QElapsedTimer time;
    time.start();
    int i, j,temp;
    for (i = 0; i < m_list.size(); i++)
        for (j = 0; j < m_list.size() - 1 - i; j++)
            if (m_list[j] > m_list[j + 1]){
                temp=m_list[j];
                m_list[j]=m_list[j+1];
                m_list[j+1]=temp;
            }
    int miLsec=time.elapsed();
    qDebug()<<"冒泡用时"<<miLsec<<"毫秒";
    emit finish(m_list);
}

Insertion::Insertion(QObject *parent):QThread(parent)
{

}

void Insertion::recvArray(QVector<int> list)
{
    m_list=list;
}

void Insertion::run()
{
    qDebug()<<"插入排序线程地址："<<QThread::currentThread();
    QElapsedTimer time;
    time.start();
    insertionSort(m_list,m_list.size());
    int miLsec=time.elapsed();
    qDebug()<<"插入排序用时"<<miLsec<<"毫秒";
    emit finish(m_list);
}



void Insertion::insertionSort(QVector<int> &arr, int n) {
    for (int i = 1; i < n; i++) {
        //寻找元素arr[i]合适的插入位置
        int e = arr[i];
        int j;//j保存元素e应该插入的位置
        for (j = i; j > 0 && arr[j-1] > e; j--) {
            arr[j]=arr[j-1];
        }
        arr[j] = e;
    }
}




