#ifndef VAR2_H
#define VAR2_H

#include <QDialog>

namespace Ui {
class var2;
}

class var2 : public QDialog
{
    Q_OBJECT
    
public:
    explicit var2(QWidget *parent = 0);
    ~var2();
    
private:
    Ui::var2 *ui;
};

#endif // VAR2_H
