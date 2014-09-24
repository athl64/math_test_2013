#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cstdlib"
#include "ctime"
#include <QDebug>
#include <QDateTime>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(start_test()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(show_help()));

    show_NameForm();

    //init network part
    client = new QTcpSocket(this);

    connect(client,SIGNAL(connected()),this,SLOT(Connected()));
    connect(client,SIGNAL(readyRead()),this,SLOT(ReadyRead()));
    connect(client,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(err()));

    client->connectToHost("127.0.0.1",4455);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_help()
{
    h = new help(this);
    h->show();
}

void MainWindow::start_test()
{
    this->hide();
    int c = 0;
    srand(time(0));//important for random number
    c=rand() %7;
    variant = c;
    qDebug()<<"randoom is "<<c;

    QFile file("log.txt");
    QTextStream stream(&file);
    QDateTime now = QDateTime::currentDateTime();
    if(file.open(QIODevice::Append | QIODevice::Text))
    {
        stream<<"\n--------------------------------------start\nstart - "<<now.toString()<<"\nvariant - "<<c+1<<"\n";
        file.close();
    }
    else
    {
        qDebug() << "cant open/create file\n";
    }

    //try to send variant number
    QString tmpText("");
    tmpText.append("<variant>" + QString::number(c) + "</variant>\n");
    tmpText.append("<name>" + bank.getData().name + "</name>\n");
    tmpText.append("<surname>" + bank.getData().surname + "</surname>\n");
    tmpText.append("<clas>" + bank.getData().clas + "</clas>\n");
    tmpText.append("<started>" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss") + "</started>\n");
    SendToServer(tmpText);

    switch (c) {
        case 0: {v1 = new var1(this); v1->show(); return;}
        case 1: {v2 = new var2(this); v2->show(); return;}
        case 2: {v3 = new var3(this); v3->show(); return;}
        case 3: {v4 = new var4(this); v4->show(); return;}
        case 4: {v5 = new var5(this); v5->show(); return;}
        case 5: {v6 = new var6(this); v6->show(); return;}
        case 6: {v7 = new var7(this); v7->show(); return;}
    }

}

void MainWindow::show_NameForm()
{
    nameForm = new NameForm(this);
    nameForm->show();
}

void MainWindow::Connected()
{
    qDebug() << "connected\n";
    sockConnected = true;
    //client->write("hello from test prog");
}

void MainWindow::Disconnected()
{
    qDebug() << "disconnected\n";
    sockConnected = false;
}

void MainWindow::ReadyRead()
{
    qDebug() << "readyRead\n";
    QString receivedStr(client->readAll());
    //client->close();
}

void MainWindow::SendToServer(QString in)
{
    do
    {
        if(getSockState())
        {
            qDebug() << "send\n";
            QByteArray tmp;
            tmp.clear();
            tmp.append(in);
            client->write(tmp);
            client->flush();
            qDebug() << "sent array content: " << tmp;
        }
        else
        {
            qDebug() << "sleep\n";
            Sleep(3000);
        }
    }
    while(!getSockState());
}

void MainWindow::err()
{
    qDebug() << "error\n" << client->errorString();
}

bool MainWindow::getSockState()
{
    return sockConnected;
}

void MainWindow::transmitMark()
{
    SendToServer("<mark>" + QString::number(bank.getMark()) + "</mark>\n");
    SendToServer("<finished>" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss") + "</finished>\n");
}
