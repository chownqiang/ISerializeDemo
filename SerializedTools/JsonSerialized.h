#ifndef JSONSERIALIZED_H
#define JSONSERIALIZED_H

#include "ISerialized.h"
#include "SerializedData.h"
#include "serializedtools_global.h"

class JsonSerialized : public ISerialized
{
public:
    virtual QString Serialization(const void* data, QList<SerializedData>* dataKeys);
    virtual void Deserialization(const void* data, QList<SerializedData>* dataKeys, QString strData);

};



#endif // JSONSERIALIZED_H
