#include "sharebank.h"

FIO shareBank::pupilData;
int shareBank::mark;

shareBank::shareBank()
{
    pupilData.name = "";
    pupilData.surname = "";
    pupilData.clas = "";

    mark = 0;

}

shareBank::~shareBank()
{

}

FIO shareBank::getData()
{
    return pupilData;
}

bool shareBank::setData(QString name, QString surname, QString clas)
{
    pupilData.name = name;
    pupilData.surname = surname;
    pupilData.clas = clas;

    return 0;
}

int shareBank::getMark()
{
    return mark;
}

bool shareBank::setMark(int markIn)
{
    mark = markIn;

    return 0;
}
