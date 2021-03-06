#ifndef MATHTHREAD_H
#define MATHTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include "sharebank.h"
#include "shareid.h"
#include "QUuid"

class mathThread : public QThread
{
    Q_OBJECT
public:
    explicit mathThread(int descriptor, QObject *parent = 0);
    ~mathThread();
    void run();

signals:
    void sockError(QTcpSocket::SocketError);
    void signalFirst(QString,QString,QString,QString,QString);
    void signalSecond(int,QString,QString);

public slots:
    void connected();
    void disconnected();
    void readyRead();

private:
    QTcpSocket *sock;
    int sd;
    int rowPos;
    shareBank bank;
    shareId id;
    QUuid guid;
};

#endif // MATHTHREAD_H
