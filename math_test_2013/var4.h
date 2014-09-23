#ifndef VAR4_H
#define VAR4_H

#include <QtWidgets/QDialog>
#include "help.h"
#include "sharebank.h"

namespace Ui {
class var4;
}

class var4 : public QDialog
{
    Q_OBJECT
    help* h;
    
public:
    explicit var4(QWidget *parent = 0);
    ~var4();
    
public slots:
    void show_help();
    void check();
    void show_result();

private:
    Ui::var4 *ui;

signals:
    void markIsReady();

private:
    shareBank bank;
};

#endif // VAR4_H
