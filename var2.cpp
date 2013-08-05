#include "var2.h"
#include "ui_var2.h"

var2::var2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::var2)
{
    ui->setupUi(this);
}

var2::~var2()
{
    delete ui;
}
