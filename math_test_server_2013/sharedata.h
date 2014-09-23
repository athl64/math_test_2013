#ifndef SHAREDATA_H
#define SHAREDATA_H

#include <QString>
#include "shareStruct.h"
#include <QVector>

class shareData
{
public:
    shareData();
    int getLength_();
    QString getName(int pos);
    QString getSurname(int pos);
    QString getStarted(int pos);
    QString getFinished(int pos);
    QString getClas(int pos);
    QString getMark(int pos);
    void setName(int pos, QString name);
    void setSurname(int pos, QString surname);
    void setStarted(int pos, QString started);
    void setFinished(int pos, QString finished);
    void setClas(int pos, QString clas);
    void setMark(int pos, QString mark);

private:
    static QVector<ShareStruct> db;
};

#endif // SHAREDATA_H
