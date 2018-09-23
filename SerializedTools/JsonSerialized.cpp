#include "JsonSerialized.h"


QString JsonSerialized::Serialization(const void* data, QList<SerializedData>* dataKeys)
{
    QJsonObject json;
    foreach( SerializedData temp, *dataKeys)
    {
        if(temp.type->GetTypename() != "JsonSerializeType")
        {
            qDebug() << __FILE__ << ":" <<__FUNCTION__ << ":invalid JsonSerializeType : " << temp.type->GetTypename();
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

void JsonSerialized::Deserialization(const void* data, QList<SerializedData>* dataKeys, QString strData)
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

    foreach( SerializedData temp, *dataKeys)
    {
        //qDebug() << temp.key;
        if(rootObj.contains(temp.key))
        {
            if(temp.type->GetTypename() != "JsonSerializeType")
            {
                qDebug() << __FILE__ << ":" <<__FUNCTION__ << ":invalid JsonSerializeType : " << temp.type->GetTypename();
                throw QException();
            }

            QJsonValue jsonValue =  rootObj.value(temp.key);
            temp.type->Deserialization(data, &temp, &jsonValue);
        }
    }
}

