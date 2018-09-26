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
    void* Serialization(const void* model, SerializedData* data);
    void Deserialization(const void* model, SerializedData* data,const void* value);

    virtual QJsonValue SerializationJson(void *model)=0;
    virtual void DeserializationJson(void *model, QJsonValue* value)=0;

};

class JsonSerializedTypeChar : public AbsJsonSerializedType
{
    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializeType interface
public:
    QJsonValue SerializationJson(void *model);
    void DeserializationJson(void *model, QJsonValue *value);
};

class JsonSerializedTypeShort : public AbsJsonSerializedType
{
    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializedType interface
public:
    QJsonValue SerializationJson(void *model);
    void DeserializationJson(void *model, QJsonValue *value);
};

class JsonSerializedTypeInt : public AbsJsonSerializedType
{
    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializedType interface
public:
    QJsonValue SerializationJson(void *model);
    void DeserializationJson(void *model, QJsonValue *value);
};

class JsonSerializedTypeQlonglong : public AbsJsonSerializedType
{
    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializedType interface
public:
    QJsonValue SerializationJson(void *model);
    void DeserializationJson(void *model, QJsonValue *value);
};

class JsonSerializedTypeFloat : public AbsJsonSerializedType
{


    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializedType interface
public:
    QJsonValue SerializationJson(void *model);
    void DeserializationJson(void *model, QJsonValue *value);
};

class JsonSerializedTypeDouble : public AbsJsonSerializedType
{
    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializedType interface
public:
    QJsonValue SerializationJson(void *model);
    void DeserializationJson(void *model, QJsonValue *value);
};

class JsonSerializedTypeQString : public AbsJsonSerializedType
{
    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializedType interface
public:
    QJsonValue SerializationJson(void *model);
    void DeserializationJson(void *model, QJsonValue *value);
};

class JsonSerializedTypeIJsonModel : public AbsJsonSerializedType
{


    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializedType interface
public:
    QJsonValue SerializationJson(void *model);
    void DeserializationJson(void *model, QJsonValue *value);
};

class JsonSerializedTypePIJsonModel : public AbsJsonSerializedType
{

    // ISerializedType interface
public:
    QString GetId();

    // AbsJsonSerializedType interface
public:
    QJsonValue SerializationJson(void *model);
    void DeserializationJson(void *model, QJsonValue *value);
};



#endif // JSONSERIALIZETYPE_H
















