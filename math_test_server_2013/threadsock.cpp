#include "threadsock.h"

threadSock::threadSock(int sockDescr, QObject *parent) :
    QThread(parent)
{
    sockDescriptor = sockDescr;
}

void threadSock::connected()
{
    qDebug() << "connected\n";
}

void threadSock::readyRead()
{
    QString received = "";
    QByteArray sent("received");

    received = sock->readAll();
    sock->write(sent);

    qDebug() << "received:\n" << received << "\n";

    sock->close();
}

void threadSock::disconnected()
{
    qDebug() << "disconnected\n";
    exit();
}

void threadSock::run()
{
    sock = new QTcpSocket();
    if(!sock->setSocketDescriptor(sockDescriptor))
    {
        qDebug() << "error: " << sock->errorString();
        return;
    }
    else
    {
        qDebug() << "started thread\n";
    }

    connect(sock,SIGNAL(connected()),this,SLOT(connected()));
    connect(sock,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(sock,SIGNAL(disconnected()),this,SLOT(disconnected()));

    exec();
}
