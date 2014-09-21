#ifndef SHAREBANK_H
#define SHAREBANK_H

#include <QString>
#include "shareStruct.h"

class shareBank
{
public:
    shareBank();
    ~shareBank();
    FIO getData();
    bool setData(QString name, QString surname, QString clas);

private:
    static FIO pupilData;
};

#endif // SHAREBANK_H
