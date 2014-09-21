#include "nameform.h"
#include "ui_nameform.h"

NameForm::NameForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NameForm)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(checkInput()));
}

NameForm::~NameForm()
{
    delete ui;
}

bool NameForm::checkInput()
{
    bank.setData(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());

    //debug plug
    this->close();

    return 0;
}
