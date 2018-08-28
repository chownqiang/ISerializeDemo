#include "CustomerJsonSerialize_QListPStudent.h"
#include "Student.h"
#include "QJsonArray"

QString CustomerJsonSerialize_QListPStudent::GetId()
{
    return "CustomerJsonSerialize_QListPStudent";
}

QJsonValue CustomerJsonSerialize_QListPStudent::SerializationJson(const SerializeData *data)
{
    QList<Student*> ts = *(QList<Student*>*)data->offset;
    QJsonArray arr;
    foreach (Student* temp, ts) {
        arr.push_back(temp->SerializeToString());
    }
    return arr;
}

void CustomerJsonSerialize_QListPStudent::DeserializationJson(const SerializeData *data, QJsonValue *value)
{
    QJsonArray arr = value->toArray();

    for(int i=0; i < arr.size(); i++ )
    {
        Student* s = new Student();
        s->DeserializeByString(arr.at(i).toString());
        (*(QList<Student*>*)data->offset).append(s);
    }
}
