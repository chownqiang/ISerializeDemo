#ifndef SERIALIZEDDATA_H
#define SERIALIZEDDATA_H

#include "serializedtools_global.h"
#include "ISerializedType.h"
#include <QMap>

struct SerializedData
{
public:
    void* getOffset(const void* data);
    QString key;
    int64_t offset;
    QString typeId;
};



#endif // SERIALIZEDDATA_H
