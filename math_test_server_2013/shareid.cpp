#include "shareid.h"

QMap<QString,int> shareId::bankID;

shareId::shareId()
{
}

void shareId::insertVal(QString guid, int id)
{
    bankID.insert(guid,id);
}

int shareId::getIdByGuid(QString guid)
{
    int res = -1;
    res = bankID.value(guid);

    return res;
}
