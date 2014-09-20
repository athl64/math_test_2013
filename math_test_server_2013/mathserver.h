#ifndef MATHSERVER_H
#define MATHSERVER_H

#include <QTcpServer>
#include "maththread.h"

class mathServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit mathServer(QObject *parent = 0);
    void startListen();

signals:

public slots:

protected:
    void incomingConnection(int descriptor);

};

#endif // MATHSERVER_H
