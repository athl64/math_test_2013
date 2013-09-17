#ifndef VAR3_H
#define VAR3_H

#include <QDialog>
#include "help.h"

namespace Ui {
class var3;
}

class var3 : public QDialog
{
    Q_OBJECT
    help* h;
    
public:
    explicit var3(QWidget *parent = 0);
    ~var3();

public slots:
    void show_help();
    void check();
    void show_result();
    
private:
    Ui::var3 *ui;
};

#endif // VAR3_H
