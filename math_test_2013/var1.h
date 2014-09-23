#ifndef VAR1_H
#define VAR1_H

#include <QtWidgets/QDialog>
#include "help.h"
#include "sharebank.h"

namespace Ui {
class var1;
}

class var1 : public QDialog
{
    Q_OBJECT
    help* h;
    
public:
    explicit var1(QWidget *parent = 0);
    ~var1();

public slots:
    void show_help();
    void check();
    void show_result();
    
private:
    Ui::var1 *ui;

signals:
    void markIsReady();

private:
    shareBank bank;
};

#endif // VAR1_H
