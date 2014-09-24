#ifndef NAMEFORM_H
#define NAMEFORM_H

#include <QDialog>
#include <QMessageBox>
#include "sharebank.h"
#include "shareStruct.h"

namespace Ui {
class NameForm;
}

class NameForm : public QDialog
{
    Q_OBJECT

public:
    explicit NameForm(QWidget *parent = 0);
    ~NameForm();

private:
    Ui::NameForm *ui;

public slots:
    bool checkInput();

private:
    shareBank bank;
};

#endif // NAMEFORM_H
