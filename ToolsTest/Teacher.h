#ifndef TEACHER_H
#define TEACHER_H
#include <QString>
#include "../SerializedTools/ISerializedModel.h"
#include "Student.h"

class Teacher :public IJsonModel
{
public:
    Teacher();

    Student * st;
    Student  st2;
    QString name;
    int age;

    // ISerializedModel interface
public:
    void RegistorTool();

    // IJsonModel interface
public:
    QString EncodeToJson();
    void DecodeFromJson(QString json);
};

#endif // TEACHER_H
