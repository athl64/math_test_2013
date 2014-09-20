#include "mathserver.h"

mathServer::mathServer(QObject *parent) :
    QTcpServer(parent)
{
}

void mathServer::startListen()
{
    if(!this->listen(QHostAddress::Any,4455))
    {
        qDebug() << "error: " << this->errorString();
    }
    else
    {
        qDebug() << "started listening";
    }
}

void mathServer::incomingConnection(int descriptor)
{
    qDebug() << "incoming";
    mathThread *client = new mathThread(descriptor, this);
    connect(client,SIGNAL(finished()),client,SLOT(deleteLater()));
    client->start();
}
