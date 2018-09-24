#ifndef ISERIALIZED_H
#define ISERIALIZED_H


#include "ISerializedModel.h"
#include "SerializedData.h"

#include <QString>

class ISerialized
{
public:
    virtual QString Serialization(const ISerializedModel* data, QList<SerializedData>* dataKeys)=0;
    virtual void Deserialization(const ISerializedModel* data, QList<SerializedData>* dataKeys, QString strData)=0;
};

#endif // ISERIALIZED_H
