#ifndef ISERIALIZED_H
#define ISERIALIZED_H


#include "ISerializedModel.h"
#include "SerializedData.h"

#include <QString>

class ISerialized
{
public:
    virtual QString Serialization(const void* data, QList<SerializedData>* dataKeys)=0;
    virtual void Deserialization(const void* data, QList<SerializedData>* dataKeys, QString strData)=0;

};

#endif // ISERIALIZED_H
