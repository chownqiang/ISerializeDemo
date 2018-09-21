#include "JsonSerialized.h"


QString JsonSerialized::Serialization(const void* data, QSharedPointer<QList<SerializeData>> dataKeys)
{
    QJsonObject json;
    foreach( SerializeData temp, *dataKeys)
    {
        if(temp.type->GetTypename() != "IJsonSerializeType")
        {
            qDebug() << __FILE__ << ":" <<__FUNCTION__ << ":invalid IJsonSerializeType : " << temp.type->GetTypename();
            throw QException();
        }
        QJsonValue * tempValue = (QJsonValue *)temp.type->Serialization(data, &temp);
        json.insert(temp.key, *tempValue);
        delete tempValue;
    }

    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray =document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);

    return strJson;
}

void JsonSerialized::Deserialization(const void* data, QSharedPointer<QList<SerializeData>> dataKeys, QString strData)
{
    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(strData.toUtf8(), &json_error));

    if(json_error.error != QJsonParseError::NoError)
    {
        qDebug() << "json error!";
        return;
    }

    QJsonObject rootObj = jsonDoc.object();

    //输出所有key，这一步是非必须的，放最后的话，你可能读不到任何key
    QStringList keys = rootObj.keys();

    foreach( SerializeData temp, *dataKeys)
    {
        //qDebug() << temp.key;
        if(rootObj.contains(temp.key))
        {
            if(temp.type->GetTypename() != "IJsonSerializeType")
            {
                qDebug() << __FILE__ << ":" <<__FUNCTION__ << ":invalid IJsonSerializeType : " << temp.type->GetTypename();
                throw QException();
            }

            QJsonValue jsonValue =  rootObj.value(temp.key);
            temp.type->Deserialization(data, &temp, &jsonValue);
        }
    }
}



//QString JsonSerialized::Serialization(AbsSerializeData* data)
//{
//    QList<SerializeData>* dataKeys =  data->GetKeys();
//    QJsonObject json;
//    foreach( SerializeData temp, *dataKeys)
//    {
//        // qDebug() << temp.key;
//        json.insert(temp.key, GetQJsonValue(&temp));
//    }

//    QJsonDocument document;
//    document.setObject(json);
//    QByteArray byteArray =document.toJson(QJsonDocument::Compact);
//    QString strJson(byteArray);

//    return strJson;
//}

//void JsonSerialized::Deserialization(AbsSerializeData* data, QString strData)
//{
//    QList<SerializeData>* dataKeys =  data->GetKeys();

//    QJsonParseError json_error;
//    QJsonDocument jsonDoc(QJsonDocument::fromJson(strData.toUtf8(), &json_error));

//    if(json_error.error != QJsonParseError::NoError)
//    {
//        // qDebug() << "json error!";
//        return;
//    }

//    QJsonObject rootObj = jsonDoc.object();

//    //输出所有key，这一步是非必须的，放最后的话，你可能读不到任何key
//    QStringList keys = rootObj.keys();

//        foreach( SerializeData temp, *dataKeys)
//        {
//            qDebug() << temp.key;
//            if(rootObj.contains(temp.key))
//            {
//                QJsonValue jsonValue =  rootObj.value(temp.key);
//                this->SetDataValue(&temp, jsonValue);
//            }
//        }
//}

//void JsonSerialized::SetDataValue(const SerializeData* temp, QJsonValue value)
//{
//    QJsonValue result ;
//    void * valuePointer = temp->offset ;

//    switch (temp->type) {
//    case SerializeDataType::char_type:
//        *(char*)valuePointer=value.toInt();
//        break;
//    case SerializeDataType::short_type:
//       *(short*)valuePointer=value.toInt();
//        break;
//    case SerializeDataType::int_type:
//        *(int*)valuePointer=value.toInt();
//        break;
//    case SerializeDataType::qlonglong_type:
//        *(qlonglong*)valuePointer=value.toVariant().toLongLong();
//        break;
//    case SerializeDataType::float_type:
//        *(float*)valuePointer = value.toString().toFloat();
//        break;
//    case SerializeDataType::double_type:
//         *(double*)valuePointer = value.toDouble();
//        break;
//    case SerializeDataType::QString_type:
//        *(QString*)valuePointer=value.toString();
//        break;
//        //case SerializeDataType::QByteArray_type:
//        // TODO QByteArray to json
//        // result = ((QByteArray)(*valuePointer)).toStdString();
//        break;
//    case SerializeDataType::AbsSerializeData_type:
//        ((AbsSerializeData *)valuePointer)->DeserializeByString(value.toString());
//        break;
//    case SerializeDataType::AbsSerializeData_ptype:
//        (*(AbsSerializeData **)valuePointer)->DeserializeByString(value.toString());
//        break;
//    default:
//        qDebug() << __FILE__ << ":" <<__FUNCTION__ << ":invalid SerializeDataType : " << temp->type;
//        throw QException();
//        break;
//    }
//}


//QJsonValue JsonSerialized::GetQJsonValue(const SerializeData* temp)
//{
//    QJsonValue result ;

//    void * valuePointer = temp->offset ;

//    switch (temp->type) {
//    case SerializeDataType::char_type:
//        result = *(char*)valuePointer;
//        break;
//    case SerializeDataType::short_type:
//        result = *(short*)valuePointer;
//        break;
//    case SerializeDataType::int_type:
//        result = *(int*)valuePointer;
//        break;
//    case SerializeDataType::qlonglong_type:
//        result = *(qlonglong*)valuePointer;
//        break;
//    case SerializeDataType::float_type:
//        result = *(float*)valuePointer;
//        break;
//    case SerializeDataType::double_type:
//        result = *(double*)valuePointer;
//        break;
//    case SerializeDataType::QString_type:
//        result = *(QString*)valuePointer;
//        break;
//        //case SerializeDataType::QByteArray_type:
//        // TODO QByteArray to json
//        // result = ((QByteArray)(*valuePointer)).toStdString();
//        break;
//    case SerializeDataType::AbsSerializeData_type:
//        result = ((AbsSerializeData *)valuePointer)->SerializeToString();
//        break;
//    case SerializeDataType::AbsSerializeData_ptype:
//        result = (*(AbsSerializeData **)valuePointer)->SerializeToString();
//        break;
//    default:
//        qDebug() << __FILE__ << ":" <<__FUNCTION__ << ":invalid SerializeDataType : " << temp->type;
//        throw QException();
//        break;
//    }

//    return result;
//}
