#include "maththread.h"

mathThread::mathThread(int descriptor, QObject *parent) :
    QThread(parent)
{
    this->sd = descriptor;
}

void mathThread::run()
{
    sock = new QTcpSocket();
    if(!sock->setSocketDescriptor(this->sd))
    {
        qDebug() << "error while starting thread: " << sock->errorString();
        emit sockError(sock->error());
        return;
    }

    connect(sock,SIGNAL(connected()),this,SLOT(connected()),Qt::DirectConnection);
    connect(sock,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
    connect(sock,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);

    exec();
}

void mathThread::connected()
{
    qDebug() << "connected\n";
}

void mathThread::disconnected()
{
    qDebug() << "disconnected";
    sock->deleteLater();
    exit(0);
}

void mathThread::readyRead()
{
    QString received = "";
    QByteArray sent("received on server");

    received = sock->readAll();
    sock->write(sent);

    sock->close();

    qDebug() << "received from client: " << received;
}

