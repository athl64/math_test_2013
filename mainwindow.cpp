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
    qDebug()<<"randoom is "<<c;

    QFile file("log.txt");
    QTextStream stream(&file);
    QDateTime now = QDateTime::currentDateTime();
    file.open(QIODevice::Append | QIODevice::Text);
    stream<<"\n--------------------------------------start\nstart - "<<now.toString()<<"\nvariant - "<<c+1<<"\n";
    file.close();

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
