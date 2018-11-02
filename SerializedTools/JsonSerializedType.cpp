#include "JsonSerializedType.h"
#include "SerializedData.h"
#include "ISerializedModel.h"
#include "QList"

#include <QJsonArray>

//AbsJsonSerializeType
QString AbsJsonSerializedType::GetTypename()
{
    return "JsonSerializeType";
}

void *AbsJsonSerializedType::Serialization(const void* model, SerializedData* data)
{
    return new QJsonValue(this->SerializationJson(model, data));
}

void AbsJsonSerializedType::Deserialization(const void* model, SerializedData* data, const void* value)
{
    this->DeserializationJson(model, data, (QJsonValue*)value);
}


// JsonSerializedTypeChar
QString JsonSerializedTypeChar::GetId()
{
    return "JsonSerializedTypeChar";
}

QJsonValue JsonSerializedTypeChar::SerializationJson(const void* model, SerializedData* data)
{
    return *(char*)(data->getOffset(model));
}

void JsonSerializedTypeChar::DeserializationJson(const void* model, SerializedData* data, const QJsonValue* value)
{
    *(char*)(data->getOffset(model))=value->toInt();
}

//JsonSerializedTypeShort
QString JsonSerializedTypeShort::GetId()
{
    return "JsonSerializedTypeShort";
}

QJsonValue JsonSerializedTypeShort::SerializationJson(const void* model, SerializedData* data)
{
    return *(short*)(data->getOffset(model));
}

void JsonSerializedTypeShort::DeserializationJson(const void* model, SerializedData* data, const QJsonValue* value)
{
    *(short*)(data->getOffset(model))=value->toInt();
}

//JsonSerializedTypeInt
QString JsonSerializedTypeInt::GetId()
{
    return "JsonSerializedTypeInt";
}

QJsonValue JsonSerializedTypeInt::SerializationJson(const void* model, SerializedData* data)
{
    return *(int*)(data->getOffset(model));
}

void JsonSerializedTypeInt::DeserializationJson(const void* model, SerializedData* data, const QJsonValue* value)
{
    *(int*)(data->getOffset(model))=value->toInt();
}


//JsonSerializedTypeQlonglong
QString JsonSerializedTypeQlonglong::GetId()
{
    return "JsonSerializedTypeQlonglong";
}

QJsonValue JsonSerializedTypeQlonglong::SerializationJson(const void* model, SerializedData* data)
{
    return *(qlonglong*)(data->getOffset(model));
}

void JsonSerializedTypeQlonglong::DeserializationJson(const void* model, SerializedData* data, const QJsonValue* value)
{
    *(qlonglong*)(data->getOffset(model))=value->toVariant().toLongLong();
}


//JsonSerializedTypeFloat
QString JsonSerializedTypeFloat::GetId()
{
    return "JsonSerializedTypeFloat";
}

QJsonValue JsonSerializedTypeFloat::SerializationJson(const void* model, SerializedData* data)
{
    return *(double*)(data->getOffset(model));

}

void JsonSerializedTypeFloat::DeserializationJson(const void* model, SerializedData* data, const QJsonValue* value)
{
    *(double*)(data->getOffset(model))=value->toDouble();
}



//JsonSerializedTypeDouble
QString JsonSerializedTypeDouble::GetId()
{
    return "JsonSerializedTypeDouble";
}

QJsonValue JsonSerializedTypeDouble::SerializationJson(const void* model, SerializedData* data)
{
    return *(double*)(data->getOffset(model));
}

void JsonSerializedTypeDouble::DeserializationJson(const void* model, SerializedData* data, const QJsonValue* value)
{
    *(double*)(data->getOffset(model))=value->toDouble();
}

//JsonSerializedTypeQString
QString JsonSerializedTypeQString::GetId()
{
    return "JsonSerializedTypeQString";
}

QJsonValue JsonSerializedTypeQString::SerializationJson(const void* model, SerializedData* data)
{
     return *(QString*)(data->getOffset(model));
}

void JsonSerializedTypeQString::DeserializationJson(const void* model, SerializedData* data, const QJsonValue* value)
{
    *(QString*)(data->getOffset(model))=value->toString();
}

//JsonSerializedTypeIJsonModel
QString JsonSerializedTypeIJsonModel::GetId()
{
    return "JsonSerializedTypeIJsonModel";
}

QJsonValue JsonSerializedTypeIJsonModel::SerializationJson(const void* model, SerializedData* data)
{
    return ((IJsonModel *)(data->getOffset(model)))->EncodeToJson();
}

void JsonSerializedTypeIJsonModel::DeserializationJson(const void* model, SerializedData* data, const QJsonValue* value)
{
    ((IJsonModel *)(data->getOffset(model)))->DecodeFromJson(value->toString());
}



//JsonSerializedTypePIJsonModel
QString JsonSerializedTypePIJsonModel::GetId()
{
    return "JsonSerializedTypePIJsonModel";
}

QJsonValue JsonSerializedTypePIJsonModel::SerializationJson(const void* model, SerializedData* data)
{
    if((*(IJsonModel **)(data->getOffset(model))) == nullptr)
        return QJsonValue();

    return (*(IJsonModel **)(data->getOffset(model)))->EncodeToJson();
}

void JsonSerializedTypePIJsonModel::DeserializationJson(const void* model, SerializedData* data, const QJsonValue* value)
{
    if(value->isNull())
        return;

    (*(IJsonModel **)(data->getOffset(model)))->DecodeFromJson(value->toString());
}



JsonSerializedTypeQVector_int::JsonSerializedTypeQVector_int(QString id)
{
    this->id = id;
}

QString JsonSerializedTypeQVector_int::GetId()
{
    return this->id;
}

QJsonValue JsonSerializedTypeQVector_int::SerializationJson(const void *model, SerializedData *data)
{

    QVector<int>* ts = (QVector<int>*)data->getOffset(model);
    QJsonArray arr;
    foreach (int temp, *ts)
    {
        arr.push_back(temp);
    }
    return arr;
}

void JsonSerializedTypeQVector_int::DeserializationJson(const void *model, SerializedData *data, const QJsonValue *value)
{
    QJsonArray  arr = value->toArray();

    for(int i=0; i < arr.size(); i++ )
    {
        int t = arr.at(i).toInt();
        (*(QVector<int>*)data->getOffset(model)).append(t);
    }
}
