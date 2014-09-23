#include "sharedata.h"

QVector<ShareStruct> shareData::db;

shareData::shareData()
{

}

QString shareData::getName(int pos)
{
    return db.at(pos).name;
}

QString shareData::getSurname(int pos)
{
    return db.at(pos).surname;
}

QString shareData::getStarted(int pos)
{
    return db.at(pos).started;
}

QString shareData::getFinished(int pos)
{
    return db.at(pos).finished;
}

QString shareData::getClas(int pos)
{
    return db.at(pos).clas;
}

QString shareData::getMark(int pos)
{
    return db.at(pos).mark;
}

int shareData::getLength_()
{
    return db.length();
}

void shareData::setName(int pos, QString name)
{
    db[pos].name = name;
}

void shareData::setSurname(int pos, QString surname)
{
    db[pos].surname = surname;
}

void shareData::setStarted(int pos, QString started)
{
    db[pos].started = started;
}

void shareData::setFinished(int pos, QString finished)
{
    db[pos].finished = finished;
}

void shareData::setClas(int pos, QString clas)
{
    db[pos].clas = clas;
}

void shareData::setMark(int pos, QString mark)
{
    db[pos].mark = mark;
}
