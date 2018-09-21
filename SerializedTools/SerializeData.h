#ifndef SERIALIZEDATA_H
#define SERIALIZEDATA_H

#include "serializedtools_global.h"
#include "ISerializeType.h"
#include <QMap>

struct SerializeData
{
public:
    void* getOffset(void* data)
    {
        return (void*)((char*)data + offset);
    }
    QString key;
    int64_t offset;
    QSharedPointer<ISerializeType> type;
};

#endif // SERIALIZEDATA_H
