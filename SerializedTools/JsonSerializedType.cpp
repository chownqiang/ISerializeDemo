#include "JsonSerializedType.h"
#include "SerializedData.h"

//AbsJsonSerializeType
QString AbsJsonSerializedType::GetTypename()
{
    return "JsonSerializeType";
}

void *AbsJsonSerializedType::Serialization(const void *model, SerializedData *data)
{
    return new QJsonValue(this->SerializationJson(model, data));
}

void AbsJsonSerializedType::Deserialization(const void *model, SerializedData *data, const void *value)
{
    this->DeserializationJson(model, data, (QJsonValue*)value);
}


// JsonSerializedTypeChar
QString JsonSerializedTypeChar::GetId()
{
    return "JsonSerializedTypeChar";
}

QJsonValue JsonSerializedTypeChar::SerializationJson(const void *model, SerializedData *data)
{
    return *(char*)(data->getOffset(model));
}

void JsonSerializedTypeChar::DeserializationJson(const void *model, SerializedData *data, QJsonValue *value)
{
    *(char*)(data->getOffset(model))=value->toInt();
}

//JsonSerializedTypeShort
QString JsonSerializedTypeShort::GetId()
{
    return "JsonSerializedTypeShort";
}

QJsonValue JsonSerializedTypeShort::SerializationJson(const void *model, SerializedData *data)
{
    return *(short*)(data->getOffset(model));
}

void JsonSerializedTypeShort::DeserializationJson(const void *model, SerializedData *data, QJsonValue *value)
{
    *(short*)(data->getOffset(model))=value->toInt();
}

//JsonSerializedTypeInt
QString JsonSerializedTypeInt::GetId()
{
    return "JsonSerializedTypeInt";
}

QJsonValue JsonSerializedTypeInt::SerializationJson(const void *model, SerializedData *data)
{
    return *(int*)(data->getOffset(model));
}

void JsonSerializedTypeInt::DeserializationJson(const void *model, SerializedData *data, QJsonValue *value)
{
    *(int*)(data->getOffset(model))=value->toInt();
}


//JsonSerializedTypeQlonglong
QString JsonSerializedTypeQlonglong::GetId()
{
    return "JsonSerializedTypeQlonglong";
}

QJsonValue JsonSerializedTypeQlonglong::SerializationJson(const void *model, SerializedData *data)
{
    return *(qlonglong*)(data->getOffset(model));
}

void JsonSerializedTypeQlonglong::DeserializationJson(const void *model, SerializedData *data, QJsonValue *value)
{
    *(qlonglong*)(data->getOffset(model))=value->toVariant().toLongLong();
}


