#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mathserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    int insertRow(QString name, QString surname, QString clas, QString start);//return inserted row number
    void setRowData(int rowNum, QString mark, QString finish);//add data to exist row

};

#endif // MAINWINDOW_H
