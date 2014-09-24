#include "sharebank.h"

shareBank::shareBank()
{
    name = "";
    surname = "";
    clas = "";
    started = "";
    variant = "";
    finished = "";
    mark = "";
}

bool shareBank::setFirst(QString Iname, QString Isurname, QString Iclas, QString Istarted, QString Ivariant)
{
    name = Iname;
    surname = Isurname;
    clas = Iclas;
    started = Istarted;
    variant = Ivariant;

    return 0;
}

bool shareBank::setSecond(QString Ifinished, QString Imark)
{
    finished = Ifinished;
    mark = Imark;

    return 0;
}

QString shareBank::getName()
{
    return name;
}

QString shareBank::getSurname()
{
    return surname;
}

QString shareBank::getClas()
{
    return clas;
}

QString shareBank::getStarted()
{
    return started;
}

QString shareBank::getFinished()
{
    return finished;
}

QString shareBank::getMark()
{
    return mark;
}

QString shareBank::getVariant()
{
    return variant;
}

void shareBank::filter(QString input)
{
    int posFrom = 0;
    int posTo = 0;
    int l = 0;

    posFrom = input.indexOf("<name>");
    posTo = input.indexOf("</name>");
    posFrom += 6;
    l = posTo - posFrom;
    if(posFrom >= 0 && posTo >= 0) {
        name = input.mid(posFrom,l);
    }
    posFrom = posTo = l = 0;

    posFrom = input.indexOf("<surname>");
    posTo = input.indexOf("</surname>");
    posFrom += 9;
    l = posTo - posFrom;
    if(posFrom >= 0 && posTo >= 0) {
        surname = input.mid(posFrom,l);
    }
    posFrom = posTo = l = 0;

    posFrom = input.indexOf("<clas>");
    posTo = input.indexOf("</clas>");
    posFrom += 6;
    l = posTo - posFrom;
    if(posFrom >= 0 && posTo >= 0) {
        clas = input.mid(posFrom,l);
    }
    posFrom = posTo = l = 0;

    posFrom = input.indexOf("<started>");
    posTo = input.indexOf("</started>");
    posFrom += 9;
    l = posTo - posFrom;
    if(posFrom >= 0 && posTo >= 0) {
        started = input.mid(posFrom,l);
    }
    posFrom = posTo = l = 0;

    posFrom = input.indexOf("<finished>");
    posTo = input.indexOf("</finished>");
    posFrom += 10;
    l = posTo - posFrom;
    if(posFrom >= 0 && posTo >= 0) {
        finished = input.mid(posFrom,l);
    }
    posFrom = posTo = l = 0;

    posFrom = input.indexOf("<mark>");
    posTo = input.indexOf("</mark>");
    posFrom += 6;
    l = posTo - posFrom;
    if(posFrom >= 0 && posTo >= 0) {
        mark = input.mid(posFrom,l);
    }
    posFrom = posTo = l = 0;

    posFrom = input.indexOf("<variant>");
    posTo = input.indexOf("</variant>");
    posFrom += 9;
    l = posTo - posFrom;
    if(posFrom >= 0 && posTo >= 0) {
        variant = input.mid(posFrom,l);
    }
}
