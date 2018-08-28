#ifndef ISERIALIZETYPEJSON_H
#define ISERIALIZETYPEJSON_H

#include "ISerializeType.h"
#include "AbsSerializeData.h"

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

class DefaultJsonSerialize_Char : public IJsonSerializeType
{
public:
    virtual QString GetId() {  return "DefaultJsonSerialize_Char";  }

    virtual QJsonValue SerializationJson(const SerializeData* data)
    {
        return *(char*)data->offset;
    }

    virtual void DeserializationJson(const SerializeData* data, QJsonValue* value)
    {
        *(char*)data->offset=value->toInt();
    }
};

class DefaultJsonSerialize_Short : public IJsonSerializeType
{
public:

    virtual QJsonValue SerializationJson(const SerializeData* data)
    {
        return *(short*)data->offset;
    }

    virtual void DeserializationJson(const SerializeData* data, QJsonValue* value)
    {
        *(short*)data->offset=value->toInt();
    }
};

class DefaultJsonSerialize_Int :public IJsonSerializeType
{
public:
    virtual QString GetId() {  return "DefaultJsonSerialize_Int";  }

    virtual QJsonValue SerializationJson(const SerializeData* data)
    {
        return *(int*)(data->offset);
    }

    virtual void DeserializationJson(const SerializeData* data, QJsonValue* value)
    {
        *(int*)data->offset=value->toInt();
    }
};

class DefaultJsonSerialize_Qlonglong : public IJsonSerializeType
{
public:
    virtual QString GetId() {  return "DefaultJsonSerialize_Qlonglong";  }

    virtual QJsonValue SerializationJson(const SerializeData* data)
    {
        return *(qlonglong*)data->offset;
    }

    virtual void DeserializationJson(const SerializeData* data, QJsonValue* value)
    {
        *(qlonglong*)data->offset=value->toVariant().toLongLong();
    }
};

class DefaultJsonSerialize_Float : public IJsonSerializeType
{
public:
    virtual QString GetId() {  return "DefaultJsonSerialize_Float";  }

    virtual QJsonValue SerializationJson(const SerializeData* data)
    {
        return *(float*)data->offset;
    }

    virtual void DeserializationJson(const SerializeData* data, QJsonValue* value)
    {
        *(float*)data->offset=value->toDouble();
    }
};

class DefaultJsonSerialize_Double : public IJsonSerializeType
{
public:
    virtual QString GetId() {  return "DefaultJsonSerialize_Double";  }

    virtual QJsonValue SerializationJson(const SerializeData* data)
    {
        return *(double*)data->offset;
    }

    virtual void DeserializationJson(const SerializeData* data, QJsonValue* value)
    {
        *(double*)data->offset=value->toDouble();
    }
};

class DefaultJsonSerialize_QString : public IJsonSerializeType
{
public:
    virtual QString GetId() {  return "DefaultJsonSerialize_QString";  }

    virtual QJsonValue SerializationJson(const SerializeData* data)
    {
        return *(QString*)data->offset;
    }

    virtual void DeserializationJson(const SerializeData* data, QJsonValue* value)
    {
        *(QString*)data->offset=value->toString();
    }
};

class DefaultJsonSerialize_AbsSerializeData : public IJsonSerializeType
{
public:
    virtual QString GetId() {  return "DefaultJsonSerialize_AbsSerializeData";  }

    virtual QJsonValue SerializationJson(const SerializeData* data)
    {
        return ((AbsSerializeData *)data->offset)->SerializeToString();
    }

    virtual void DeserializationJson(const SerializeData* data, QJsonValue* value)
    {
        ((AbsSerializeData *)data->offset)->DeserializeByString(value->toString());
    }
};

class DefaultJsonSerialize_PAbsSerializeData : public IJsonSerializeType
{
public:
    virtual QString GetId() {  return "DefaultJsonSerialize_PAbsSerializeData";  }

    virtual QJsonValue SerializationJson(const SerializeData* data)
    {
        return (*(AbsSerializeData **)data->offset)->SerializeToString();
    }

    virtual void DeserializationJson(const SerializeData* data, QJsonValue* value)
    {
        (*(AbsSerializeData **)data->offset)->DeserializeByString(value->toString());
    }
};


#endif // ISERIALIZETYPEJSON_H
