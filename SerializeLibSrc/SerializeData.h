#ifndef SERIALIZEDATA_H
#define SERIALIZEDATA_H

#include "Serializelib_Global.h"
#include "ISerializeType.h"
#include <QMap>

struct SerializeData
{
public:
    QString key;
    void* offset;
    QSharedPointer<ISerializeType> type;
};


#endif // SERIALIZEDATATYPE_H
