#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "var1.h"
#include "var2.h"
#include "var3.h"
#include "var4.h"
#include "var5.h"
#include "var6.h"
#include "var7.h"
#include "help.h"
#include "nameform.h"
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    var1* v1;
    var2* v2;
    var3* v3;
    var4* v4;
    var5* v5;
    var6* v6;
    var7* v7;
    help* h;
    NameForm* nameForm;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void show_help();
    void start_test();
    void show_NameForm();

    //network
public slots:
    void Connected();
    void ReadyRead();
    void SendToServer();
    void err();
    
private:
    QTcpSocket *client;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H