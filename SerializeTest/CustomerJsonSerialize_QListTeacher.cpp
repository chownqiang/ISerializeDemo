#include "CustomerJsonSerialize_QListTeacher.h"
#include "QJsonArray"
#include "QJsonObject"
#include "Teacher.h"

QString CustomerJsonSerialize_QListTeacher::GetId()
{
    return "CustomerJsonSerialize_QListTeacher";
}

QJsonValue CustomerJsonSerialize_QListTeacher::SerializationJson(const SerializeData *data)
{
    QList<Teacher> ts = *(QList<Teacher>*)data->offset;
    QJsonArray arr;
    foreach (Teacher temp, ts) {
        arr.push_back(temp.SerializeToString());
    }
    return arr;
}

void CustomerJsonSerialize_QListTeacher::DeserializationJson(const SerializeData *data, QJsonValue *value)
{
    QJsonArray  arr = value->toArray();

    for(int i=0; i < arr.size(); i++ )
    {
        Teacher t;
        t.DeserializeByString(arr.at(i).toString());
        (*(QList<Teacher>*)data->offset).append(t);
    }
}
