#ifndef JSONSERIALIZED_H
#define JSONSERIALIZED_H

#include "ISerialized.h"
#include "SerializeData.h"
#include "serializedtools_global.h"

class JsonSerialized : public ISerialized
{
public:
    virtual QString Serialization(const void* data, QSharedPointer<QList<SerializeData>> dataKeys);
    virtual void Deserialization(const void* data, QSharedPointer<QList<SerializeData>> dataKeys, QString strData);

private:
    QJsonValue GetQJsonValue(const SerializeData* temp);
    void SetDataValue(const SerializeData* temp, QJsonValue value);
};

#endif // JSONSERIALIZED_H
