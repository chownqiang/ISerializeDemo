#ifndef ISERIALIZED_H
#define ISERIALIZED_H

class AbsSerializeData;
#include "SerializeData.h"

#include <QString>

class ISerialized
{
public:
    virtual QString Serialization(const void* data, QSharedPointer<QList<SerializeData>> dataKeys)=0;
    virtual void Deserialization(const void* data, QSharedPointer<QList<SerializeData>> dataKeys, QString strData)=0;
};

#endif // ISERIALIZED_H
