#ifndef VAR2_H
#define VAR2_H

#include <QtWidgets/QDialog>
#include "help.h"

namespace Ui {
class var2;
}

class var2 : public QDialog
{
    Q_OBJECT
    help* h;
    
public:
    explicit var2(QWidget *parent = 0);
    ~var2();
    
public slots:
    void show_help();
    void check();
    void show_result();

private:
    Ui::var2 *ui;
};

#endif // VAR2_H
