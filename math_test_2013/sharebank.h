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
    int getMark();
    bool setMark(int markIn);

private:
    static FIO pupilData;
    static int mark;
};

#endif // SHAREBANK_H
