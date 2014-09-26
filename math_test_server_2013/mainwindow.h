#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mathserver.h"
#include "shareid.h"

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

    shareId id;

public slots:
    int insertRow(QString name, QString surname, QString clas, QString start, QString guid);//return inserted row number
    void setRowData(int rowNum, QString mark, QString finish);//add data to exist row
    void testInsert();

};

#endif // MAINWINDOW_H
