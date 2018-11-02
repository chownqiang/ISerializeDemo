#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include "ISerializedModel.h"

class Student : IJsonModel
{
public:
    Student();

    QString name;
    int age;

    // IJsonModel interface
public:
    void RegistorTool();
    QString EncodeToJson();
    void DecodeFromJson(QString json);
};

#endif // STUDENT_H
