#include "sharebank.h"

FIO shareBank::pupilData;

shareBank::shareBank()
{
    pupilData.name = "";
    pupilData.surname = "";
    pupilData.clas = "";

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
