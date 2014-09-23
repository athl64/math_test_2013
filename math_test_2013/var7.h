#ifndef VAR7_H
#define VAR7_H

#include <QtWidgets/QDialog>
#include "help.h"
#include "sharebank.h"

namespace Ui {
class var7;
}

class var7 : public QDialog
{
    Q_OBJECT
    help* h;
    
public:
    explicit var7(QWidget *parent = 0);
    ~var7();
    
public slots:
    void show_help();
    void check();
    void show_result();

private:
    Ui::var7 *ui;

signals:
    void markIsReady();

private:
    shareBank bank;
};

#endif // VAR7_H
