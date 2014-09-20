#ifndef THREADSOCK_H
#define THREADSOCK_H

#include <QThread>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>

class threadSock : public QThread
{
    Q_OBJECT
public:
    explicit threadSock(int sockDescr, QObject *parent = 0);
    void run();

signals:

public slots:
    void connected();
    void readyRead();
    void disconnected();

private:
    QTcpSocket *sock;
    int sockDescriptor;

};

#endif // THREADSOCK_H
