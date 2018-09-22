#ifndef IJSONSERIALIZETYPE_H
#define IJSONSERIALIZETYPE_H

#include "ISerializeType.h"
#include <QJsonValue>
#include <QDebug>

class IJsonSerializeType : public ISerializeType
{
public:
    virtual QString GetTypename()
    {
        return "IJsonSerializeType";
    }
    ~IJsonSerializeType()
    {
        qDebug()<< "free :" ;
    }

    // use it and free the value outside;
    virtual void* Serialization(const SerializeData* data)
    {
        return new QJsonValue(this->SerializationJson(data));
    }

    virtual void Deserialization(const SerializeData* data,const void* value)
    {
        this->DeserializationJson(data, (QJsonValue*)value);
    }

    virtual QJsonValue SerializationJson(const SerializeData* data)=0;
    virtual void DeserializationJson(const SerializeData* data, QJsonValue* value)=0;
};

#endif // IJSONSERIALIZETYPE_H


