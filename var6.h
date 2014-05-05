#ifndef VAR6_H
#define VAR6_H

#include <QtWidgets/QDialog>
#include "help.h"

namespace Ui {
class var6;
}

class var6 : public QDialog
{
    Q_OBJECT
    help* h;
    
public:
    explicit var6(QWidget *parent = 0);
    ~var6();
    
public slots:
    void show_help();
    void check();
    void show_result();

private:
    Ui::var6 *ui;
};

#endif // VAR6_H
