#ifndef SHAREID_H
#define SHAREID_H

#include <QMap>
#include <QString>

class shareId
{
public:
    shareId();
    void insertVal(QString guid, int id);
    int getIdByGuid(QString guid);

public:
    static QMap<QString,int> bankID;
};

#endif // SHAREID_H
