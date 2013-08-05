#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "var1.h"
#include "var2.h"
#include "help.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    var1* v1;
    var2* v2;
    help* h;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void show_help();
    void start_test();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
