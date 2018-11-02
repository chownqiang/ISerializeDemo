#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "Teacher.h"

#include <QVector>



class ClassRoom :  IJsonModel
{
public:
    ClassRoom();

    Teacher *teacher;
    QVector<Student*> stus;



    // ISerializedModel interface
public:
    void RegistorTool();

    // IJsonModel interface
public:
    QString EncodeToJson();
    void DecodeFromJson(QString json);
};

#endif // CLASSROOM_H
