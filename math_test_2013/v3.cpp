#include "v3.h"
#include "ui_v3.h"

v3::v3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::v3)
{
    ui->setupUi(this);
}

v3::~v3()
{
    delete ui;
}
