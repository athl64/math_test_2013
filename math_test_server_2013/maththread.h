#ifndef MATHTHREAD_H
#define MATHTHREAD_H

#include <QThread>
#include <QTcpSocket>

class mathThread : public QThread
{
    Q_OBJECT
public:
    explicit mathThread(int descriptor, QObject *parent = 0);
    void run();

signals:
    void sockError(QTcpSocket::SocketError);

public slots:
    void connected();
    void disconnected();
    void readyRead();

private:
    QTcpSocket *sock;
    int sd;
};

#endif // MATHTHREAD_H
