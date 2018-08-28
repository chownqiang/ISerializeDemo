#ifndef STUDENT_H
#define STUDENT_H

#include "../SerializeLibSrc/AbsSerializeData.h"

class Student : public AbsSerializeData
{
public:



    // AbsSerializeData interface
protected:
    virtual void InitSerializeKeys();
    QString ToJson();
    void JsonToValue(QString jsonValue);
    //field
public:
    QString name;
    int age;
    float score;
    QString classroom;
};

#endif // STUDENT_H
