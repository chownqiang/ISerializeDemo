#include "Student.h"
#include "../SerializeLibSrc/ISerializeTypeJson.h"

void Student::InitSerializeKeys()
{
    this->SetKeyData("name",&this->name, QSharedPointer<ISerializeType>(new DefaultJsonSerialize_QString()));
    this->SetKeyData("age",&this->age,  QSharedPointer<ISerializeType>(new DefaultJsonSerialize_Int()));
    this->SetKeyData("classroom",&this->classroom, QSharedPointer<ISerializeType>(new DefaultJsonSerialize_QString()));
    this->SetKeyData("score",&this->score, QSharedPointer<ISerializeType>(new DefaultJsonSerialize_Float()));
}

QString Student::ToJson()
{
    QJsonObject json;
    json.insert("name", this->name);
    json.insert("age", this->age);
    json.insert("classroom", this->classroom);
    json.insert("score", this->score);
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray =document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);

    return strJson;
}

void Student::JsonToValue(QString strData)
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

    QJsonValue jname =  rootObj.value("name");
    QJsonValue jage =  rootObj.value("age");
    QJsonValue jclassroom =  rootObj.value("classroom");
    QJsonValue jscore =  rootObj.value("score");

    this->name = jname.toString();
    this->age = jage.toInt();
    this->classroom = jclassroom.toString();
    this->score = jscore.toDouble();
}



















