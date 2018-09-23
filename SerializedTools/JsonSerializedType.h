#ifndef JSONSERIALIZEDTYPE_H
#define JSONSERIALIZEDTYPE_H

#include "ISerializedType.h"
#include <QJsonValue>

class AbsJsonSerializedType : public ISerializedType
{
    // ISerializedType interface
public:
    QString GetTypename();
    // use it and free the value outside;
    void *Serialization(const void *model, SerializedData *data);
    void Deserialization(const void *model, SerializedData *data, const void *value);

    virtual QJsonValue SerializationJson(const void *model, SerializedData* data)=0;
    virtual void DeserializationJson(const void *model, SerializedData* data, QJsonValue* value)=0;

};

class JsonSerializedTypeChar : public AbsJsonSerializedType
{
    // ISerializedType interface
public:
    QString GetId();


    // AbsJsonSerializeType interface
public:
    QJsonValue SerializationJson(const void *model, SerializedData *data);
    void DeserializationJson(const void *model, SerializedData *data, QJsonValue *value);
};

class JsonSerializedTypeShort : public AbsJsonSerializedType
{


    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializedType interface
public:
    QJsonValue SerializationJson(const void *model, SerializedData *data);
    void DeserializationJson(const void *model, SerializedData *data, QJsonValue *value);
};

class JsonSerializedTypeInt : public AbsJsonSerializedType
{


    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializedType interface
public:
    QJsonValue SerializationJson(const void *model, SerializedData *data);
    void DeserializationJson(const void *model, SerializedData *data, QJsonValue *value);
};

class JsonSerializedTypeQlonglong : public AbsJsonSerializedType
{


    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializedType interface
public:
    QJsonValue SerializationJson(const void *model, SerializedData *data);
    void DeserializationJson(const void *model, SerializedData *data, QJsonValue *value);
};

#endif // JSONSERIALIZETYPE_H
