#include "JsonSerializedType.h"
#include "SerializedData.h"
#include "ISerializedModel.h"

//AbsJsonSerializeType
QString AbsJsonSerializedType::GetTypename()
{
    return "JsonSerializeType";
}

void *AbsJsonSerializedType::Serialization(const void* model, SerializedData* data)
{
    return new QJsonValue(this->SerializationJson(data->getOffset(model)));
}

void AbsJsonSerializedType::Deserialization(const void* model, SerializedData* data, const void* value)
{
    this->DeserializationJson(data->getOffset(model), (QJsonValue*)value);
}


// JsonSerializedTypeChar
QString JsonSerializedTypeChar::GetId()
{
    return "JsonSerializedTypeChar";
}

QJsonValue JsonSerializedTypeChar::SerializationJson(void *model)
{
    return *(char*)model;
}

void JsonSerializedTypeChar::DeserializationJson(void *model, QJsonValue *value)
{
    *(char*)model=value->toInt();
}

//JsonSerializedTypeShort
QString JsonSerializedTypeShort::GetId()
{
    return "JsonSerializedTypeShort";
}

QJsonValue JsonSerializedTypeShort::SerializationJson(void *model)
{
    return *(short*)model;
}

void JsonSerializedTypeShort::DeserializationJson(void *model, QJsonValue *value)
{
    *(short*)model=value->toInt();
}

//JsonSerializedTypeInt
QString JsonSerializedTypeInt::GetId()
{
    return "JsonSerializedTypeInt";
}

QJsonValue JsonSerializedTypeInt::SerializationJson(void *model)
{
    return *(int*)model;
}

void JsonSerializedTypeInt::DeserializationJson(void *model, QJsonValue *value)
{
    *(int*)model=value->toInt();
}


//JsonSerializedTypeQlonglong
QString JsonSerializedTypeQlonglong::GetId()
{
    return "JsonSerializedTypeQlonglong";
}

QJsonValue JsonSerializedTypeQlonglong::SerializationJson(void *model)
{
    return *(qlonglong*)model;
}

void JsonSerializedTypeQlonglong::DeserializationJson(void *model, QJsonValue *value)
{
    *(qlonglong*)model=value->toVariant().toLongLong();
}


//JsonSerializedTypeFloat
QString JsonSerializedTypeFloat::GetId()
{
    return "JsonSerializedTypeFloat";
}

QJsonValue JsonSerializedTypeFloat::SerializationJson(void *model)
{
    return *(double*)model;

}

void JsonSerializedTypeFloat::DeserializationJson(void *model, QJsonValue *value)
{
    *(double*)model=value->toDouble();
}



//JsonSerializedTypeDouble
QString JsonSerializedTypeDouble::GetId()
{
    return "JsonSerializedTypeDouble";
}

QJsonValue JsonSerializedTypeDouble::SerializationJson(void *model)
{
    return *(double*)model;
}

void JsonSerializedTypeDouble::DeserializationJson(void *model, QJsonValue *value)
{
    *(double*)model=value->toDouble();
}

//JsonSerializedTypeQString
QString JsonSerializedTypeQString::GetId()
{
    return "JsonSerializedTypeQString";
}

QJsonValue JsonSerializedTypeQString::SerializationJson(void *model)
{
     return *(QString*)model;
}

void JsonSerializedTypeQString::DeserializationJson(void *model, QJsonValue *value)
{
    *(QString*)model=value->toString();
}

//JsonSerializedTypeIJsonModel
QString JsonSerializedTypeIJsonModel::GetId()
{
    return "JsonSerializedTypeIJsonModel";
}

QJsonValue JsonSerializedTypeIJsonModel::SerializationJson(void *model)
{
    return ((IJsonModel *)model)->EncodeToJson();
}

void JsonSerializedTypeIJsonModel::DeserializationJson(void *model, QJsonValue *value)
{
    ((IJsonModel *)model)->DecodeFromJson(value->toString());
}



//JsonSerializedTypePIJsonModel
QString JsonSerializedTypePIJsonModel::GetId()
{
    return "JsonSerializedTypePIJsonModel";
}

QJsonValue JsonSerializedTypePIJsonModel::SerializationJson(void *model)
{
    if((*(IJsonModel **)model) == nullptr)
        return QJsonValue();

    return (*(IJsonModel **)model)->EncodeToJson();
}

void JsonSerializedTypePIJsonModel::DeserializationJson(void *model, QJsonValue *value)
{
    if(value->isNull())
        return;

    (*(IJsonModel **)model)->DecodeFromJson(value->toString());
}
