#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initTableSize();

    mathServer *server = new mathServer(this);
    server->startListen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::insertRow(QString name, QString surname, QString clas, QString start, QString guid)
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    int currentRow = ui->tableWidget->rowCount();
    currentRow--;

    ui->tableWidget->setItem(currentRow,0,new QTableWidgetItem(name + " " + surname));
    ui->tableWidget->setItem(currentRow,1,new QTableWidgetItem(clas));
    ui->tableWidget->setItem(currentRow,2,new QTableWidgetItem(start));
    ui->tableWidget->setItem(currentRow,4,new QTableWidgetItem("Тестування"));
    id.insertVal(guid,currentRow);

    return currentRow;
}

void MainWindow::setRowData(int rowNum, QString mark, QString finish)
{
    ui->tableWidget->setItem(rowNum,5,new QTableWidgetItem(mark));
    ui->tableWidget->setItem(rowNum,3,new QTableWidgetItem(finish));
    ui->tableWidget->setItem(rowNum,4,new QTableWidgetItem("Завершено"));
}

void MainWindow::testInsert()
{
    insertRow("maxim2","galich1","12-h","now1","guid shorter then need");
}

void MainWindow::initTableSize()
{
    ui->tableWidget->horizontalHeader()->resizeSection(0,300);
    ui->tableWidget->horizontalHeader()->resizeSection(2,140);
    ui->tableWidget->horizontalHeader()->resizeSection(3,140);
}
