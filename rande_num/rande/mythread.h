#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QVector>

class Generate : public QThread
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);
    void recvNum(int num);

protected:
    void run() override;

signals:
    void sendArray(QVector<int> num);

private:
    int m_num;

};

class BubbleSort : public QThread
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    void recvArray(QVector<int> list);

protected:
    void run() override;

signals:
    void finish(QVector<int> num);

private:
    QVector<int> m_list;

};

class Insertion : public QThread
{
    Q_OBJECT
public:
    explicit Insertion(QObject *parent = nullptr);
    void recvArray(QVector<int> list);

protected:
    void run() override;

signals:
    void finish(QVector<int> num);

private:
    QVector<int> m_list;
    void insertionSort(QVector<int> &arr, int n);

};

#endif // MYTHREAD_H
