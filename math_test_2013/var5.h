#ifndef VAR5_H
#define VAR5_H

#include <QtWidgets/QDialog>
#include "help.h"

namespace Ui {
class var5;
}

class var5 : public QDialog
{
    Q_OBJECT
    help* h;
    
public:
    explicit var5(QWidget *parent = 0);
    ~var5();
    
public slots:
    void show_help();
    void check();
    void show_result();

private:
    Ui::var5 *ui;
};

#endif // VAR5_H
