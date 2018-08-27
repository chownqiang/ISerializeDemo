#ifndef TEACHER_H
#define TEACHER_H

#include "../SerializeLibSrc/AbsSerializeData.h"

class Teacher : public AbsSerializeData
{
public:


    // AbsSerializeData interface
protected:
    virtual void InitSerializeKeys();

//field
public:
    QString name;
    int age;
    qlonglong salary;
};

#endif // TEACHER_H
