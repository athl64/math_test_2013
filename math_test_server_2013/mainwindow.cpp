#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mathServer *server = new mathServer;
    server->startListen();

    insertRow("maxim","galich","12-j","now");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::insertRow(QString name, QString surname, QString clas, QString start)
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    int currentRow = ui->tableWidget->rowCount();
    currentRow--;

    ui->tableWidget->setItem(currentRow,0,new QTableWidgetItem(name + " " + surname));
    ui->tableWidget->setItem(currentRow,1,new QTableWidgetItem(clas));
    ui->tableWidget->setItem(currentRow,2,new QTableWidgetItem(start));
    ui->tableWidget->setItem(currentRow,4,new QTableWidgetItem("Тестування"));

    return currentRow;
}

void MainWindow::setRowData(int rowNum, QString mark, QString finish)
{
    ui->tableWidget->setItem(rowNum,5,new QTableWidgetItem(mark));
    ui->tableWidget->setItem(rowNum,3,new QTableWidgetItem(finish));
    ui->tableWidget->setItem(rowNum,4,new QTableWidgetItem("Завершено"));
}
