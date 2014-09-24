#ifndef SHAREBANK_H
#define SHAREBANK_H

#include <QString>
#include <QDebug>

class shareBank
{
public:
    shareBank();
    bool setFirst(QString Iname, QString Isurname, QString Iclas, QString Istarted, QString Ivariant);
    bool setSecond(QString Ifinished, QString Imark);
    QString getName();
    QString getSurname();
    QString getClas();
    QString getStarted();
    QString getFinished();
    QString getMark();
    QString getVariant();

    void filter(QString input);

private:
    QString name;
    QString surname;
    QString clas;
    QString started;
    QString finished;
    QString mark;
    QString variant;
};

#endif // SHAREBANK_H
