#ifndef VAR3_H
#define VAR3_H

#include <QtWidgets/QDialog>
#include "help.h"
#include "sharebank.h"

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

signals:
    void markIsReady();

private:
    shareBank bank;
};

#endif // VAR3_H
