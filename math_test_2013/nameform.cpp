#include "nameform.h"
#include "ui_nameform.h"

NameForm::NameForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NameForm)
{
    ui->setupUi(this);

    ui->lineEdit->setMaxLength(20);
    ui->lineEdit_2->setMaxLength(20);
    ui->lineEdit_3->setMaxLength(5);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(checkInput()));
}

NameForm::~NameForm()
{
    delete ui;
}

bool NameForm::checkInput()
{
    if(ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "" && ui->lineEdit_3->text() != "")
    {
        bank.setData(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
        this->close();
    }
    else
    {
        QMessageBox info;
        info.setWindowTitle("Увага!");
        info.setText("Перевірте щоб всі поля були заповнені правильно!");
        info.exec();
    }

    //debug plug
    //this->close();

    return 0;
}
