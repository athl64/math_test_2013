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
    //debug plug
    this->close();

    return 0;
}
