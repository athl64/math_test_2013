#include "maththread.h"

mathThread::mathThread(int descriptor, QObject *parent) :
    QThread(parent)
{
    this->sd = descriptor;

    rowPos = -1;
    guid = QUuid::createUuid();
    //qDebug() << "guid: " << guid.toString();
}

mathThread::~mathThread()
{

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

    //
    connect(this,SIGNAL(signalFirst(QString,QString,QString,QString,QString)),parent()->parent(),SLOT(insertRow(QString,QString,QString,QString,QString)));
    connect(this,SIGNAL(signalSecond(int,QString,QString)),parent()->parent(),SLOT(setRowData(int,QString,QString)));

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

    //
    bank.filter(received);
    if(bank.getName() != "" && bank.getSurname() != "" && bank.getClas() != "" && bank.getStarted() != "" && bank.getFinished() == "" && bank.getMark() == "")
    {
        emit signalFirst(bank.getName(),bank.getSurname(),bank.getClas(),bank.getStarted(),guid.toString());
    }
    else if(bank.getFinished() != "" && bank.getMark() != "")
    {
        rowPos = id.getIdByGuid(guid.toString());
        emit signalSecond(rowPos,bank.getMark(),bank.getFinished());
    }

    //sock->close();

    qDebug() << "received from client: " << received;
}

