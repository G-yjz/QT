#ifndef RECVFILE_H
#define RECVFILE_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>

class RecvFile : public QThread
{
    Q_OBJECT
public:
    explicit RecvFile(QTcpSocket* tcp,QObject *parent = nullptr);

protected:
    void run() override;

private:
    QTcpSocket* m_tcp;

signals:
    void over();
};

#endif // RECVFILE_H
