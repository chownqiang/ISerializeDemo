#include "JsonSerialized.h"
#include "JsonSerializedType.h"



JsonSerialized* JsonSerialized::Instance()
{
    JsonSerialized* model  = nullptr;
    if(model)
        return model;

    model = new JsonSerialized();
    return model;
}

QString JsonSerialized::Serialization(const void* data, QList<SerializedData>* dataKeys)
{
    // TODO: !IJsonModel ,error
    QJsonObject json;
    foreach( SerializedData temp, *dataKeys)
    {
        ISerializedType* currType = this->serializedType[temp.typeId];
        if(!currType)
        {
            qDebug() << __FILE__ << ":" <<__FUNCTION__ << ":invalid JsonSerializeType : " << temp.typeId;
            throw QException();
        }

        if(currType->GetTypename() != "JsonSerializeType")
        {
            qDebug() << __FILE__ << ":" <<__FUNCTION__ << ":invalid JsonSerializeType : " << currType->GetTypename();
            throw QException();
        }
        QJsonValue * tempValue = (QJsonValue *)currType->Serialization(data, &temp);
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
    // TODO: !IJsonModel ,error

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
            ISerializedType* currType = this->serializedType[temp.typeId];
            if(!currType)
            {
                qDebug() << __FILE__ << ":" <<__FUNCTION__ << ":invalid JsonSerializeType : " << temp.typeId;
                throw QException();
            }

            if(currType->GetTypename() != "JsonSerializeType")
            {
                qDebug() << __FILE__ << ":" <<__FUNCTION__ << ":invalid JsonSerializeType : " << currType->GetTypename();
                throw QException();
            }

            QJsonValue jsonValue =  rootObj.value(temp.key);

            currType->Deserialization(data, &temp, &jsonValue);
        }
    }
}

JsonSerialized::JsonSerialized()
{
    //registor JsonSerializedType
    {
        ISerializedType * jchar = new JsonSerializedTypeChar();
        this->serializedType.insert(jchar->GetId(),jchar);

        ISerializedType * jshort = new JsonSerializedTypeShort();
        this->serializedType.insert(jshort->GetId(),jshort);

        ISerializedType * jint = new JsonSerializedTypeInt();
        this->serializedType.insert(jint->GetId(),jint);

        ISerializedType * jll = new JsonSerializedTypeQlonglong();
        this->serializedType.insert(jll->GetId(),jll);

        ISerializedType * jfloat = new JsonSerializedTypeFloat();
        this->serializedType.insert(jfloat->GetId(),jfloat);

        ISerializedType * jdouble = new JsonSerializedTypeDouble();
        this->serializedType.insert(jdouble->GetId(),jdouble);

        ISerializedType * jqstring = new JsonSerializedTypeQString();
        this->serializedType.insert(jqstring->GetId(),jqstring);

        ISerializedType * jmodel = new JsonSerializedTypeIJsonModel();
        this->serializedType.insert(jmodel->GetId(),jmodel);

        ISerializedType * jPmodel = new JsonSerializedTypePIJsonModel();
        this->serializedType.insert(jPmodel->GetId(),jPmodel);

    }
}

