#ifndef V3_H
#define V3_H

#include <QDialog>

namespace Ui {
class v3;
}

class v3 : public QDialog
{
    Q_OBJECT
    
public:
    explicit v3(QWidget *parent = 0);
    ~v3();
    
private:
    Ui::v3 *ui;
};

#endif // V3_H
